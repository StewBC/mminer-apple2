;-----------------------------------------------------------------------------
; rotext.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "RODATA"

roTextLevel:
.byte "         Central Cavern         "
.byte "          The Cold Room         "
.byte "          The Menagerie         "
.byte "   Abandoned Uranium Workings   "
.byte "         Eugene's Lair          "
.byte "       Processing Plant         "
.byte "            The Vat             "
.byte "Miner Willy meets the Kong Beast"
.byte "        Wacky Amoebatrons       "
.byte "       The Endorian Forest      "
.byte "Attack of the Mutant Telephones "
.byte " Return of the Alien Kong Beast "
.byte "          Ore Refinery          "
.byte "       Skylab Landing Bay       "
.byte "            The Bank            "
.byte "      The Sixteenth Cavern      "
.byte "         The Warehouse          "
.byte "      Amoebatrons' Revenge      "
.byte "     Solar Power Generator      "
.byte "        The Final Barrier       "
roTextAir:
.byte "AIR  "
roTextScore:
.byte "SCORE"
roTextHighScore:
.byte "HIGH"
roTextGame:
.byte "GAME"
roTextOver:
.byte "OVER"
roTextPressEnter:
.byte "PRESS ENTER TO START"
roTextEnter := (roTextPressEnter + 6)
roTextAppleIIVersion:
.byte "Apple II  version by"
roTextStefan:
.byte "Stefan Wessels, 2020"
roTextIntro:
.byte ".  .  .  .  .  .  . MANIC MINER . . ", $7f, " BUG-BYTE ltd.  1983 . . By "
.byte "Matthew Smith . . . Q, O & W, P = Left & Right . . Space = Jump . . M = Music "
.byte "On/Off . . S = In Game Sound On/Off . . B = Monochrome/Color . . "
.byte "C = Level scroll mode . . ESC = Quit . . . Guide Miner Willy through 20 lethal "
.byte "caverns .  .  .  .  .  .  ", 0
roTextMono:
.byte " MONO"
roTextColor:
.byte "COLOR"
roTextCheatCode:
.byte "6031769"
