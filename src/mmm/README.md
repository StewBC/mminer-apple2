# The Manic Miner Machine  
The Manic Minder Machine is a very, very small Apple II emulator that I built specifically to run the version of Manic Miner that I made, for the Apple II, on my Windows PC.  Yesterday, after I finished my harte_6502 6502 cycle-accurate CPU emulator, I thought about doing a Commodore 64 emulator, but then realized that Manic Miner loads into RAM all in one go (well, the loader loads it), and I don't use any ROM routines.  
  
Manic Miner uses only the 2 hires banks (at $2000 and $4000), the Keyboard ($C000), Keyboard Strobe ($c010) and the speaker ($C030).  So building an emulator should be very easy.  Well, it was.  
  
My speaker code is beyond terrible, but I'll maybe figure that out later.  Turn audio off with M or S (Music & Sound).  ESC will quit.  O & P for left and right and SPACE to jump.  
  
# The Files  
| File | Description
| --- | ---
| 6502.c | The 6502 Machine
| mminer.c | The 6502 Manic Miner compiled code
| mmm.c | The Apple II emulator (all 403 lines of it ;)
  
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
On my M3 Mac Mini, the harte_6502 test run in 11s and on my windows PC in 35s.  But the emulator runs great on Windows, and can run a little faster than the 1.023 MHz that the Apple II runs at.  But the emulator runs pretty slow on my M3 Mac Mini.  I did not look to see if the issue is related to SDL_GetPerformanceFrequency or something else.  
  
# The Future  
I will probably not do too much with this.  I'll see about fixing the audio.  
  
Feel free to contact me at swessels@email.com if you have thoughts or suggestions.  
  
Thank you  
Stefan Wessels  
9 September 2024 - Initial Revision