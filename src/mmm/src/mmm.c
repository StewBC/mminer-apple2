#include <stdio.h>
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "6502.h"
#include "mminer.h"

// Apple II sim related
#define CPU_FREQUENCY       1022727               // 1 MHz (cycles/sec) NTSC = 14.31818 MHz / 14, PAL = 14.25 MHz / 14
#define TARGET_FPS          (1000000 / 60)        // (cycles/sec) / (updates/sec) = cycles/update

MACHINE m;                                        // The container for the CPU, RAM, etc
uint8_t RAM_MAIN[RAM_SIZE];                       // The 64K RAM
uint8_t RAM_IO[RAM_SIZE];                         // 64K of IO port "mask" (0 = is not a port)

#define MLI         0xBF00                        // The Machine Language Interface (MM only calls it to quit)
#define KBD         0xC000                        // Port where the Apple II reads what keys are down
#define KBDSTRB     0xC010                        // Port where the Apple II acknowledges a key press (clears it)
#define SPEAKER     0xC030                        // Port that toggles the speaker
#define LOWSCR      0xC054                        // Port that draw Hires from $2000
#define HISCR       0xC055                        // Port that draws Hires from $4000

// The start of a line of pixels (192 rows) in HGR memory.
// (Add to active Hires page ie $2000 or $4000)
uint16_t row_start[] = {
    0x0000,0x0400,0x0800,0x0C00,0x1000,0x1400,0x1800,0x1C00,
    0x0080,0x0480,0x0880,0x0C80,0x1080,0x1480,0x1880,0x1C80,
    0x0100,0x0500,0x0900,0x0D00,0x1100,0x1500,0x1900,0x1D00,
    0x0180,0x0580,0x0980,0x0D80,0x1180,0x1580,0x1980,0x1D80,
    0x0200,0x0600,0x0A00,0x0E00,0x1200,0x1600,0x1A00,0x1E00,
    0x0280,0x0680,0x0A80,0x0E80,0x1280,0x1680,0x1A80,0x1E80,
    0x0300,0x0700,0x0B00,0x0F00,0x1300,0x1700,0x1B00,0x1F00,
    0x0380,0x0780,0x0B80,0x0F80,0x1380,0x1780,0x1B80,0x1F80,
    0x0028,0x0428,0x0828,0x0C28,0x1028,0x1428,0x1828,0x1C28,
    0x00A8,0x04A8,0x08A8,0x0CA8,0x10A8,0x14A8,0x18A8,0x1CA8,
    0x0128,0x0528,0x0928,0x0D28,0x1128,0x1528,0x1928,0x1D28,
    0x01A8,0x05A8,0x09A8,0x0DA8,0x11A8,0x15A8,0x19A8,0x1DA8,
    0x0228,0x0628,0x0A28,0x0E28,0x1228,0x1628,0x1A28,0x1E28,
    0x02A8,0x06A8,0x0AA8,0x0EA8,0x12A8,0x16A8,0x1AA8,0x1EA8,
    0x0328,0x0728,0x0B28,0x0F28,0x1328,0x1728,0x1B28,0x1F28,
    0x03A8,0x07A8,0x0BA8,0x0FA8,0x13A8,0x17A8,0x1BA8,0x1FA8,
    0x0050,0x0450,0x0850,0x0C50,0x1050,0x1450,0x1850,0x1C50,
    0x00D0,0x04D0,0x08D0,0x0CD0,0x10D0,0x14D0,0x18D0,0x1CD0,
    0x0150,0x0550,0x0950,0x0D50,0x1150,0x1550,0x1950,0x1D50,
    0x01D0,0x05D0,0x09D0,0x0DD0,0x11D0,0x15D0,0x19D0,0x1DD0,
    0x0250,0x0650,0x0A50,0x0E50,0x1250,0x1650,0x1A50,0x1E50,
    0x02D0,0x06D0,0x0AD0,0x0ED0,0x12D0,0x16D0,0x1AD0,0x1ED0,
    0x0350,0x0750,0x0B50,0x0F50,0x1350,0x1750,0x1B50,0x1F50,
    0x03D0,0x07D0,0x0BD0,0x0FD0,0x13D0,0x17D0,0x1BD0,0x1FD0
};

// RGB values
struct mRGB {
    uint8_t c[3];
};
typedef struct mRGB mRGB;

// The Apple II color palette as RGB values
mRGB palette[8] = {
    {0X00, 0X00, 0X00},                           // Black
    {0X46, 0XC4, 0X45},                           // Green
    {0XDD, 0X6D, 0XEA},                           // Violet
    {0XFF, 0XFF, 0XFF},                           // White
    {0X00, 0X00, 0X00},                           // Black
    {0XE2, 0X84, 0X3A},                           // Orange
    {0X30, 0XA7, 0XEB},                           // Blue
    {0XFF, 0XFF, 0XFF},                           // White
};

// Global variables to emulate speaker clicks
#define SAMPLE_RATE 44100
enum {
    SAMPLE_PREVIOUS,
    OUTPUT_PREVIOUS,
    SAMPLE_CURRENT,
    NUM_SAMPLES,
};
struct A2SPEAKER {
    float   speaker_state;
    float   sample_rate;
    float   samples[NUM_SAMPLES];
};
typedef struct A2SPEAKER A2SPEAKER;
// Speaker should be part of MACHINE but I don't want to modify 6502.?
A2SPEAKER speaker;

// Global handles for SDL rendering
SDL_Window      *window;
SDL_Renderer    *renderer;
SDL_Surface     *surface;
SDL_Texture     *texture;
int             screen_updated = TARGET_FPS;      // Counter - at TARGET_FPS forces screen update
int             active_page = 0x4000;             // 0x2000 or 0x4000 - active hires memory page

// Present the selected HiRes screen (page)
void show_screen(uint16_t page) {
    int x, y;
    uint32_t *pixels = (uint32_t *)surface->pixels;

    // Loop through each row
    for (y = 0; y < 192; y++) {
        // Get the pointer to the start of the row in the SDL surface
        uint32_t *p = &pixels[y * surface->w];
        // An index to "walk" the pixels in the surface
        int px = 0;
        // Get the address where this row starts in HGR memory
        int address = page + row_start[y];

        // Loop through every 2 bytes (40 iterations for each 280-pixel row - 140 color pixels)
        for (int x = 0; x < 40; x += 2) {
            // Combine two bytes into a 16-bit value for ease of extracting pixels
            uint16_t col = (RAM_MAIN[address + x + 1] << 8) | RAM_MAIN[address + x];

            // Extract the phase bits
            int ph1 = (col & 0b0000000010000000) >> 5;
            int ph2 = (col & 0b1000000000000000) >> 13;

            // Extract pixels and offset for phase bits
            int p1 = ph1 + ((col & 0b0000000000000001) << 1  | (col & 0b0000000000000010) >> 1 );
            int p2 = ph1 + ((col & 0b0000000000000100) >> 1  | (col & 0b0000000000001000) >> 3 );
            int p3 = ph1 + ((col & 0b0000000000010000) >> 3  | (col & 0b0000000000100000) >> 5 );
            int p4 = ph1 + ((col & 0b0000000001000000) >> 5  | (col & 0b0000000100000000) >> 8 );
            int p5 = ph2 + ((col & 0b0000001000000000) >> 8  | (col & 0b0000010000000000) >> 10);
            int p6 = ph2 + ((col & 0b0000100000000000) >> 10 | (col & 0b0001000000000000) >> 12);
            int p7 = ph2 + ((col & 0b0010000000000000) >> 12 | (col & 0b0100000000000000) >> 14);

            // Set the pixel value from the palette
            p[px++] = SDL_MapRGB(surface->format, palette[p1].c[0], palette[p1].c[1], palette[p1].c[2]);
            p[px++] = SDL_MapRGB(surface->format, palette[p2].c[0], palette[p2].c[1], palette[p2].c[2]);
            p[px++] = SDL_MapRGB(surface->format, palette[p3].c[0], palette[p3].c[1], palette[p3].c[2]);
            p[px++] = SDL_MapRGB(surface->format, palette[p4].c[0], palette[p4].c[1], palette[p4].c[2]);
            p[px++] = SDL_MapRGB(surface->format, palette[p5].c[0], palette[p5].c[1], palette[p5].c[2]);
            p[px++] = SDL_MapRGB(surface->format, palette[p6].c[0], palette[p6].c[1], palette[p6].c[2]);
            p[px++] = SDL_MapRGB(surface->format, palette[p7].c[0], palette[p7].c[1], palette[p7].c[2]);
        }
    }

    // Rendering the texture
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Mark screen as updated now
    screen_updated = 0;
}

// Handle the Apple II ports used by Manic Miner
uint8_t io_read_callback(MACHINE *m, uint16_t address) {
    switch(address) {
        case KBDSTRB:
            RAM_MAIN[KBD] &= 0x7F;
        break;
        case SPEAKER:
            speaker.speaker_state = 1.0f - speaker.speaker_state;
            break;
        case LOWSCR:
            active_page = 0x2000;
            show_screen(0x2000);
            break;
        case HISCR:
            active_page = 0x4000;
            show_screen(0x4000);
            break;
    }
    return m->read_pages.pages[address / PAGE_SIZE].memory[address % PAGE_SIZE];
}

// Writing to these ports is the same as reading from them
void io_write_callback(MACHINE *m, uint16_t address, uint8_t value) {
    io_read_callback(m, address);
}

// Set MACHINE up as an Apple II
int AppleII_configure(MACHINE *m) {

    // Load the Manic Miner logo HGR and the game itself
    memcpy(&RAM_MAIN[0x4000], manic_miner, manic_miner_size);

    // RAM
    if(!ram_init(&m->ram, 1)) {
        return 0;
    }
    ram_add(&m->ram, 0, 0x0000, RAM_SIZE, RAM_MAIN);

    // PAGES
    if(!pages_init(&m->read_pages, RAM_SIZE / PAGE_SIZE)) {
        return 0;
    }
    if(!pages_init(&m->write_pages, RAM_SIZE / PAGE_SIZE)) {
        return 0;
    }
    if(!pages_init(&m->io_pages, RAM_SIZE / PAGE_SIZE)) {
        return 0;
    }

    // Map main write ram
    pages_map(&m->write_pages, m->ram.ram_banks[0].address / PAGE_SIZE, m->ram.ram_banks[0].length / PAGE_SIZE, m->ram.ram_banks[0].memory);

    // Map read ram (same as write ram in this case)
    pages_map(&m->read_pages , m->ram.ram_banks[0].address / PAGE_SIZE, m->ram.ram_banks[0].length / PAGE_SIZE, m->ram.ram_banks[0].memory);

    // Install the IO callbacks
    m->io_write = io_write_callback;
    m->io_read = io_read_callback;

    // Map IO area checks - start with no IO
    memset(RAM_IO, 0, RAM_SIZE);

    // Add the IO ports the game uses
    RAM_IO[KBDSTRB] = 1;
    RAM_IO[SPEAKER] = 1;
    RAM_IO[LOWSCR] = 1;                           // Page 1 in MM speak
    RAM_IO[HISCR] = 1;                            // Page 2 in MM speak
    pages_map(&m->io_pages, 0, RAM_SIZE / PAGE_SIZE, RAM_IO);

    cpu_init(&m->cpu);
    // The game code starts at $6000
    m->cpu.pc = 0x6000;
    // Override the JMP instruction there from a cold start
    m->cpu.instruction_cycle = -1;

    return 1;
}

// Set up SDL graphics and Audio
int init_sdl() {
    // Initialize SDL with video and audio
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Create window
    window = SDL_CreateWindow("Manic Miner Machine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Create RGB surface
    surface = SDL_CreateRGBSurface(0, 140, 192, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    if(surface == NULL) {
        printf("Surface could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Create texture for pixel rendering
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture == NULL) {
        printf("Texture could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Now init the Audio
    SDL_AudioSpec wanted_spec;
    SDL_AudioSpec obtained_spec;

    // Set the desired audio format
    wanted_spec.freq = SAMPLE_RATE;
    wanted_spec.format = AUDIO_F32SYS;
    wanted_spec.channels = 2;                     // Stereo sound
    wanted_spec.samples = 4096;                   // Buffer size
    wanted_spec.callback = NULL;                  // No callback

    // Open the audio device
    if (SDL_OpenAudio(&wanted_spec, &obtained_spec) < 0) {
        printf("Couldn't open audio! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Set up the speaker now that the obtained freq is known
    memset(&speaker, 0, sizeof(speaker));
    memset(speaker.samples, 0, NUM_SAMPLES * sizeof(float));
    // The 1.5 is a fudge number to make sure the audio doesn't lag
    speaker.sample_rate = ((float)CPU_FREQUENCY / obtained_spec.freq) + 1.5f;

    return 1;
}

int main(int argc, char* argv[]) {
    int quit = 0;
    SDL_Event e;
    float sample_cycles;
    Uint64 start_time, end_time;
    Uint64 ticks_per_clock_cycle = SDL_GetPerformanceFrequency() / CPU_FREQUENCY; // Ticks per microsecond

    if(!init_sdl()) {
        SDL_Quit();
        return 1;
    }

    // Make this machine an Apple II and load Manic Miner into RAM
    AppleII_configure(&m);

    // Start the audio
    SDL_PauseAudio(0);

    // After init_sdl that sets up speaker.sample_rate
    sample_cycles = speaker.sample_rate;
    const float alpha = 0.98f;                    // High pass filter coefficient
    const float beta = 0.98f;                     // Low pass filter coefficient

    // Start running the sim loop
    while (!quit) {
        // Take note of the time to help sync to Apple II speed
        start_time = SDL_GetPerformanceCounter();

        // Process all SDL events
        while (SDL_PollEvent(&e) != 0) {
            // Set the last key pressed in the "port"
            if (e.type == SDL_KEYDOWN) {
                RAM_MAIN[KBD] = 0x80 | e.key.keysym.sym;
            }

            // If the user closes the window
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Step the sim one instruction
        int cycles = 0;
        do {
            // Step the sim one cycle
            machine_step(&m);
            cycles++;
            speaker.samples[SAMPLE_CURRENT] += speaker.speaker_state;
            if(--sample_cycles <= 0.0f) {
                float output_previous = speaker.samples[OUTPUT_PREVIOUS];
                float sample_previous = speaker.samples[SAMPLE_PREVIOUS];
                float sample_current = speaker.samples[SAMPLE_CURRENT];
                // Calculate a high pass and low pass filtered sample
                float high_pass_result = alpha * (output_previous + sample_current - sample_previous);
                float filter_result = beta * high_pass_result + (1 - beta) * output_previous;
                // Save the current sample of next time
                speaker.samples[SAMPLE_PREVIOUS] = sample_current;
                // And make the filtered sample prev and also use as left and right for SDL
                speaker.samples[OUTPUT_PREVIOUS] = filter_result;
                speaker.samples[SAMPLE_CURRENT] = filter_result;
                // Queue the stero samples
                SDL_QueueAudio(1, &speaker.samples[OUTPUT_PREVIOUS], 2 * sizeof(float));
                // Start a new sample
                speaker.samples[SAMPLE_CURRENT] = 0.0f;
                // Reset when the next samples will be queued
                sample_cycles += speaker.sample_rate;

            }
        } while(m.cpu.instruction_cycle != -1);

        // If a call was made to the MLI, it's to QUIT
        if(m.cpu.pc == MLI) {
            quit = 1;
        }

        // If the page hasn't been "switched", force an update of the current page
        if(++screen_updated >= TARGET_FPS) {
            show_screen(active_page);
        }

        // When the speaker is not being toggled, it needs to turn off
        end_time = SDL_GetPerformanceCounter();

        // Try to lock the SIM to the Apple II 1.023 MHz
        while ((end_time - start_time) < (ticks_per_clock_cycle * cycles)) {
            end_time = SDL_GetPerformanceCounter();
        }
    }

    // Cleanup
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_CloseAudio();
    IMG_Quit();
    SDL_Quit();
    return 0;
}
