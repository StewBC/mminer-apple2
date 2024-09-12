# The Manic Miner Machine  
The Manic Minder Machine is a very, very small Apple II emulator that I built specifically to run, on a modern computer, the unmodified 6502 version of Manic Miner that I made for the Apple II.  
  
Manic Miner uses only the Keyboard ($C000), Keyboard Strobe ($C010), the speaker ($C030) and 2 hires banks (with toggles at $C054 and $C055).  So building an emulator should be very easy.  Well, it was.  
  
Turn audio off with M or S (Music & Sound).  ESC will quit.  O & P for left and right and SPACE to jump.  The original ZX Spectum cheat will also work.
  
# The Files  
| File | Description
| --- | ---
| 6502.c | The 6502 Machine
| mminer.c | The 6502 Manic Miner compiled code
| mmm.c | The Apple II emulator (around 400 lines :)
  
# Building the code  
The CMakeLists.txt file works for my installation.  This is my note at the top which sums up my feelings and frustrations.  
```
# This file is abysmal.  I can't stand working with these 3rd party libraries because, for me at
# least, nothing ever works as advertised.  If you know what you are doing and you want to build
# this, what's here can be a guide to get you going.  I built this on macOS (not this file) and
# WIN32.  After I modified it for macOS the WIN32 broke so I modified it for WIN32 and now the
# APPLE is broken. Probably an easy fix if you know what you are doing which I clearly don't when
# it comes to SDL
```
  
# The Speed  
The game runs equally well on my M3 Mac Mini as well as on my Windows PC.  I did not build for Linux.  
  
# The Future  
I will probably not do too much with this.
  
Feel free to contact me at swessels@email.com if you have thoughts or suggestions.  
  
Thank you  
Stefan Wessels  
9 September 2024 - Initial Revision