# Manic Miner
 Remake of the ZX Spectrum game for the Apple II.

1. INTRODUCTION

This is a game I have always loved, from the moment I saw it in a computer shop
back in the 80's.  I once made an okay Commodore 64 version, in C, but this
version is a rewrite from the ground up for the Apple II, in 6502 assembly
language and I am very pleased with the outcome.

This is my first color program for the Apple II.  Another learning experience :)

2. CURRENT STATUS

The game is complete.

There's a pre-built Apple II disk of the project, mminer.dsk under the
releases tab.  This can be played directly in emulators.

There's also a video of the game here: https://youtu.be/OGxj_g1ImhM

3. DIFFERENCES FROM THE ORIGINAL

There are several differences that all have to do with Apple II hardware
limitations.

In the Apple II version, the title screen is not the high resolution picture
with the animated piano keyboard.  Instead it uses the ZX Spectrum loading
screen, which has the words Manic and Miner bounce up and down.  I do use the
hires screen for loading though, so it is just the opposite way ;)

The reason for not using the high resolution picture is due to a memory
limitation. If I did use some of the ROM memory for RAM, I could probably fix
this, but I didn't want to trash ProDOS and I didn't want to have to reboot the
Apple II when the program is quit.

The biggest differences have to do with the screen and keys.  

The ZX Spectrum has a 32 column, 8 pixel per column, color display (256 pixels).
The Apple II can only display 20 7-pixel color columns (140 pixels).  This means
I cannot fit the level on-screen at any given time.  The level does need to
scroll as you play through it.

I have settled on a 3 zone scrolling method.  As Willy enters a zone, the screen
will quickly scroll to the proper "camera position" for the zone Willy is in.
However, if you press the C key, the scrolling method toggles to one where the
game tries to keep Willy more or less in the middle of the screen - so as you
move around the center of the room, the game scrolls the screen all the time.
This method may be better suited to learning a room.

The scrolling method I use scrolls the game in "game columns" which means 2
bytes at a time.  This is a rather coarse scroll.  I did spend a lot of effort
on making run-time duplicates off all instanced data that allowed me to do a
1-byte scroll.  Sadly, this turned out to be even worse as the motion became
very jerky a lot more frequently.

For the curious - if you want to draw a green line on the Apple II, starting at
column 0, for 7 pixels, you need to write the following 2 bytes (bit
representation): %00101010 %01010101.  However, if you want that green line
starting at column 1, you need to write the bytes in the other order, i.e.
%01010101 %00101010.  To get the speed I need, I have all data to be rendered
stored as instances that I can "blast" to the screen quickly. For a 1-byte
scroll, the whole screen needs to be rendered with the image bytes reversed, so
I needed more memory to make the reverse second set.  And then that didn't pay
off :(

About the keys - The ZX Spectrum version requires keys to be held down to move.
The Apple II doesn't have a concept of keys being held down.  You only know when
a key is pressed, not when it's released so you cannot tell what state a key is
in.  You can also only detect one key press at a time.

In order to make the game play with the key limitation, I use the keys as
toggles.  If you press P, Willy will start and keep walking, as though you are
keeping the key down.  Pressing P again will stop Willy, as though you had let
go of the P key.  My Apple IIe does have auto-repeat so actually holding down
the P key has an undesirable effect of stutter-walking.

I also made the game remember keys so that you can anticipate a key-press (like
you would steer early in Pac Man). This works very well but it can also cause
grief.  For example, if you press Jump while in a jump, but you land somewhere
unexpected, you will still jump because of the stored anticipated jump.  If, of
course, you are quick enough, just pressing the key again before it activates
would cancel the anticipation.

All in all, the key and scroll system makes the game fun and playable, I think,
as much as is possible given the limitations.

4. TECHNICAL DETAILS

The game is written in 6502 assembly language using the ca65 assembler.  The
game uses memory from $0800 to $B52C.

Below is a CPU cycle profile of 1 game frame in stage 1 after a couple of
seconds of being on the level.  The door isn't visible so this renders only the
one enemy and Willy, as well as the level tiles.  The auidoPlayNote includes an
artificial delay that's based on the number of tiles rendered.  If I didn't have
that, the really empty levels such as SkyLab would play the in-game music way
too fast.  However, this does mean that the game experience is smoother with the
music turned off, since there's no artificial delay.

Hex | Dec | Frame % | Item
--- | --- | --- | ---
19C3E | 105534 | 100% | Total Frame
18 | 24 | 0% | inputGet
E8 | 232 | 0% | willyMove
80 | 128 | 0% | gameAI
5EF3 | 24307 | 23% | screenClear
123 | 291 | 0% | tilesAnimateKeys
47 | 71 | 0% | tilesAnimateConveyor
6EB | 1771 | 2% | screenDrawSprites
C55 | 3157 | 3% | screenDrawWilly
C6FD | 50941 | 48% | screenDrawLevel
DDA | 3546 | 3% | uiUpdate
3A | 58 | 0% | screenDrawSprite (door)
26 | 38 | 0% | screenSwap
51BD | 20925 | 20% | audioPlayNote

As can be seen, clearing the area where the world will be drawn takes almost 24%
of the frame and drawing the level tiles takes about 50% of the frame!

5. KEYS

After the intro music on the title screen, the game has a scrolling ticker that
shows help and keys, but these are the keys:

* Q or O - Move Willy left
* W or P - Move Willy right
* Space  - Jump
* B      - Toggle Black and White / Color mode
* C      - Toggle scrolling mode
* M      - Turn the music on/off
* S      - Turn in-game audio on/off 
* ESC    - Quit level or in UI, return to ProDOS

The game also supports the cheat mode, as in the original.  In game, enter the
cheat code 6031769 and a boot will appear next to the lives at the bottom of the
screen.  Cheat mode is now enabled.  Press the 6 key to start the cheat.  Now
use the keys 12345 to enter the binary value for the level (0 through 19).  Key
one sets bit 0, so it's reversed.

Once the appropriate room has been selected, press 6 again to start playing that
level.  Note that the cheat cannot be turned off and also that the Game Win
Sequence (once you beat the last level) is disabled if you cheated.  To see
that, you really have to beat all levels!

Here's a "cheat sheet" for the binary to access a level.  If you enter a room
number greater than 20, the room is reset to room 0.

Cheat Key (binary 0-19 reverse) | 12345
--- | ---
Central Cavern | 00000
The Cold Room | 10000
The Menagerie | 01000
Abandoned Uranium Workings | 11000
Eugenes Lair | 00100
Processing Plant | 10100
The Vat | 01100
Miner Willy meets the Kong | 11100
Wacky Amoebatrons | 00010
The Endorian Forest | 10010
Attack of the Mutant Telephones | 01010
Return of the Alien Kong Beast | 11010
Ore Refinery | 00110
Skylab Landing Bay | 10110
The Bank | 01110
The Sixteenth Cavern | 11110
The Warehouse | 00001
Amoebatrons Revenge | 10001
Solar Power Generator | 01001
The Final Barrier | 11001

6. THE FILES

I tried to thoroughly comment all the code.

There are actually 2 programs in this.  The 1st is the game, and it's in
src/apple2.

File | Desc
--- | ---
audio.inc | Routines to make the speaker beep
defs.inc | Constants and definitions used throughout
game.inc | The in-game logic, AI etc.  The bulk of the "game"
input.inc | User controls for game and editor
level.inc | Decompress a level and place the keys
logo.hgr | 8Kb splash screen in HGR format
logo.inc | File that simply does an incbin on logo.hgr
mminer.asm | Where the game starts, initial setup, etc.
mminer.cfg | ca65 configuration file
roaudio.inc | Frequency and timing data for music and SFX
rofont.inc | A ZX Spectrum font
rolevels.inc | Level layout, tile usage, sprite positions, etc.
rosprites.inc | Sprite definitions
rosystem.inc | Helper tables (multiplication, color masks, etc.)
rotext.inc | All text used in the game
rotiles.inc | Background tile definitions
screen.inc | Code related to drawing tiles, sprites, etc.
sprite.inc | Code for making instances of sprites, coloring them, etc.
text.inc | In game text and print functions
ui.inc | User facing screens (title, scroller)
variables.inc | All variables (scores, instance buffers, positions, etc.)
Willy.inc | All logic relating to the movement of the main character, Willy

The second is the ProDos loader that will auto-load the game.  It's in the
src/apple2.loader folder.  It has these files (all provided to me by Oliver
Schmidt)

File | Desc
--- | ---
loader.cfg | ca65 configuration file
loader.s | file to load and start the game

7. BUILDING THE GAME

Making the game has a few steps.  Use make and the Makefile on all OSs, that
would be the easiest.  

Start by making the loader - this needs to be done once only.  
make TARGETS=apple2.loader

Next, make the game with:  
make

The next step is to make a bootable disk image.  For this, you will need 3rd
party software.  I use AppleCommander.  This software will put the loader and
game into the disk image. You will need to install Java to use AppleCommander.  

The apple2/template.dsk is a "blank ProDos floppy" that has the loader and the
game placed on it by AppleCommander.

To make the disc image, set an environment variable to point at apple commander
(see notes) and then use the command:  
make dsk

This will make a disc named mminer.dsk which can be loaded up in an emulator.

If you want to edit the code and get into some iterative development/testing,
you can edit the Makefile.  Look for, and change, apple2_EMUCMD.  It is
currently configured to work with AppleWin and the path to AppleWin is expected
to be in an environment variable called APPLEWIN_HOME.  Edit variables as
necessary.

If you use AppleWin and you have sed installed, you can also uncomment the
PREEMUCMD := sed... command which will copy the game symbols to the emulator for
use.  For that to really make sense, you should to do this make command once: 
make OPTIONS=mapfile,labelfile,listing,debugfile.  That will make a file called
Makefile.options that will be re-used, and will generate a label file with all 
the labels.

Once done, you can build and play the game with the command: make dsk test

NOTES:
1) Find AppleCommander here (I used Version 1.6.0):
https://github.com/AppleCommander/AppleCommander/releases  
2) Set the environment variable (or change the Makefile-dsk.md) to point at the
apple commander jar file.  Here's how it's done for different shell's:  
 Powershell:  
   $env:AC = "path to apple commander.jar"  
 cmd.exe   
   set AC="path to apple commander.jar"  
 bash (Unix or MacOS terminal):  
   export AC="path to apple commander.jar"  

8. CREDITS

* Matthew Smith and BUG-BYTE for creating and publishing the game in
  1983.  Matthew later re-released the game with minor tweaks under the 
  Software Projects banner.  This is not that version.
* A special call-out to Oliver Schmidt who provided me with invaluable
  advice and support.
* Bill Buckels for Bmb2HDR which I used to make the logo HGR from my
  GIMP exported BMP.
* Everyone involved in the Apple II projects (AppleWin | AppleCommander).
* Everyone involved in making the cc65 tools, it's very good.

9. CONTACT

Feel free to contact me at swessels@email.com if you have thoughts or
suggestions.

Thank you  
Stefan Wessels  
21 April 2020 - Initial Revision  
