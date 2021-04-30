;-----------------------------------------------------------------------------
; rotext.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "RODATA"

roTextLevel:
.BYTE "         CENTRAL CAVERN         "
.BYTE "          THE COLD ROOM         "
.BYTE "          THE MENAGERIE         "
.BYTE "   ABANDONED URANIUM WORKINGS   "
.BYTE "         EUGENE+S LAIR          "
.BYTE "       PROCESSING PLANT         "
.BYTE "            THE VAT             "
.BYTE "MINER WILLY MEETS THE KONG BEAST"
.BYTE "        WACKY AMOEBATRONS       "
.BYTE "       THE ENDORIAN FOREST      "
.BYTE "ATTACK OF THE MUTANT TELEPHONES "
.BYTE " RETURN OF THE ALIEN KONG BEAST "
.BYTE "          ORE REFINERY          "
.BYTE "       SKYLAB LANDING BAY       "
.BYTE "            THE BANK            "
.BYTE "      THE SIXTEENTH CAVERN      "
.BYTE "         THE WAREHOUSE          "
.BYTE "      AMOEBATRONS+ REVENGE      "
.BYTE "     SOLAR POWER GENERATOR      "
.BYTE "        THE FINAL BARRIER       "
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
.BYTE "APPLE II  VERSION BY"
roTextStefan:
.BYTE "STEFAN WESSELS, 2020"
roTextIntro:
.BYTE ".  .  .  .  .  .  . MANIC MINER . . [ BUG-BYTE LTD.  1983 . . BY "
.BYTE "MATTHEW SMITH . . . Q, O * W, P = LEFT * RIGHT . . SPACE = JUMP . . M = MUSIC "
.BYTE "ON/OFF . . S = IN GAME SOUND ON/OFF . . B = MONOCHROME/COLOR . . "
.BYTE "C = LEVEL SCROLL MODE . . ESC = QUIT . . . GUIDE MINER WILLY THROUGH 20 LETHAL "
.BYTE "CAVERNS .  .  .  .  .  .  ", 0
roTextMono:
.byte " MONO"
roTextColor:
.byte "COLOR"
roTextCheatCode:
.byte "6031769"
