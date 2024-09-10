#pragma once

#define RAM_SIZE        (64*1024)
#define PAGE_SIZE       RAM_SIZE
#define NUM_PAGES       ((RAM_SIZE)/(PAGE_SIZE))

/* A memory region tracks a block of bytes, be that ROM, RAM or IO Port*/
struct MEMORY_REGION {
    uint32_t address;
    uint32_t length;
    uint8_t  *memory;
};

/* RAM_BANK is */
typedef struct MEMORY_REGION RAM_BANK;
struct RAM {
    RAM_BANK *ram_banks;
    uint16_t num_ram_banks;
};
typedef struct RAM RAM;

/* ROMS contain rom "chips" */
typedef struct MEMORY_REGION ROM;
struct ROMS {
    ROM *rom;
    uint16_t num_roms;
};
typedef struct ROMS ROMS;

/* PAGE points to a block of bytes, with a length of PAGE_SIZE (implied) */
struct PAGE {
    uint8_t *memory;
};
typedef struct PAGE PAGE;

/* PAGES is an array of PAGE structures.  These can be mapped (or not) into teh 6502 address space */
struct PAGES {
    PAGE *pages;
    uint16_t num_pages;
};
typedef struct PAGES PAGES;

/* The 6502 internals*/
struct CPU {
    uint16_t    pc;             // Program counter
    uint16_t    sp;             // Stack pointer
    uint8_t     A, X, Y;        // 8 bit registers
    union {
        struct {
            uint8_t     C: 1;   // carry
            uint8_t     Z: 1;   // zero
            uint8_t     I: 1;   // Interrupt Disable
            uint8_t     D: 1;   // BCD mode
            uint8_t     B: 1;   // Break
            uint8_t     E: 1;   // Extra (almost unused)
            uint8_t     V: 1;   // Overflow
            uint8_t     N: 1;   // Negative
        };
    uint8_t flags;
    };
    union {
        struct {
            uint8_t address_lo;
            uint8_t address_hi;
        } ;
        uint16_t address_16;    // For Emulation - Usually where bytes will be fetched
    };
    union {
        struct {
            uint8_t scratch_lo;
            uint8_t scratch_hi;
        } ;
        uint16_t scratch_16;    // For Emulation - Placeholder
    };
    struct {
        uint8_t page_fault: 1;  // During stages where a page-fault could happen, denotes fault
    };
    uint8_t instruction;        // Current instruction being executed
    int16_t instruction_cycle;  // Stage (value 0, instruction fetched, is cycle 1 of execution, -1 need instruction)
    uint64_t cycles;            // Total count of cycles the cpu has executed
} ;
typedef struct CPU CPU;

// Forward declarations
struct MACHINE;
typedef struct MACHINE MACHINE;

// Function pointer prototype that point at the steps, each individual cycle, of a 6502 instruction
typedef void (*opcode_steps)(MACHINE *m);

// Prototypes for callbacks when cpu accesses a port
typedef uint8_t (*IO_READ)(MACHINE *m, uint16_t address);
typedef void (*IO_WRITE)(MACHINE *m, uint16_t address, uint8_t value);

// The emulated machine (computer)
struct MACHINE
{
    CPU         cpu;            // 6502
    PAGES       read_pages;     // Up to 64K of memory currently visible to CPU when reading
    PAGES       write_pages;    // Up to 64K of memory currently visible to CPU when writing
    PAGES       io_pages;       // Up to 64K of bytes where 0 means this is RAM/ROM and 1 means it is a port
    IO_READ     io_read;        // The callback when reading from a port
    IO_WRITE    io_write;       // The callback when writing to a port
    RAM         ram;            // All RAM in the system (may be > 64K but up to 64K) mapped in throug pages
    ROMS        roms;           // All ROMS in the system, may be mapped into 64K, through read_pages
};
typedef struct MACHINE MACHINE;

// The 256 possible opcodes
extern  opcode_steps *opcodes[256];
// The UNDEFINED step (cycle) is for the unimplemented opcodes
extern  opcode_steps UNDEFINED[];

// Configure the ram, ROMS and memory setup (what is mapped in)
uint8_t ram_init(RAM *ram, uint16_t num_ram_banks);
void    ram_add(RAM *ram, uint8_t ram_bank_num, uint32_t address, uint32_t length, uint8_t *memory);
uint8_t roms_init(ROMS *roms, uint16_t num_roms);
void    rom_add(ROMS *roms, uint8_t rom_num, uint32_t address, uint32_t length, uint8_t *memory);
uint8_t pages_init(PAGES *pages, uint16_t num_pages);
void    pages_map(PAGES *pages, uint32_t start_page, uint32_t num_pages, uint8_t *memory);

// Exposed so that HARTE tests can be loaded and checked
uint8_t read_from_memory(MACHINE *m, uint16_t address);
void    write_to_memory(MACHINE *m, uint16_t address, uint8_t value);

// 1 time init
void    cpu_init(CPU *cpu);

// Step the machine a single CPU cycle
void    machine_step(MACHINE *m);

