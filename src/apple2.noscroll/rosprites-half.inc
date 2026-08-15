;-----------------------------------------------------------------------------
; rosprites-half.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2026
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "RODATA"

;-----------------------------------------------------------------------------
; Willy, at 3.5 colour pixels per tile column and placed at
; the even dot alignment. 16 rows x 3 bytes; the third byte is always
; empty here and is kept only so both alignments share a 48-byte
; stride. Stored white with bit 7 clear, so ORA and EOR leave the
; palette bit of whatever is underneath alone

willyHalf:
sprite00Half:
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $4C, $01, $00                             ; X--XX--------X------- = --XX--XX-------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $30, $00, $00                             ; -XX------------------ = ----XX---------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $3F, $00, $00                             ; -XXXXXX-------------- = XXXXXX---------------
.byte $73, $01, $00                             ; XXX--XX------X------- = XX--XXXX-------------
.byte $73, $01, $00                             ; XXX--XX------X------- = XX--XXXX-------------
.byte $4F, $01, $00                             ; X--XXXX------X------- = XXXX--XX-------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $4C, $01, $00                             ; X--XX--------X------- = --XX--XX-------------

sprite01Half:
.byte $00, $06, $00                             ; -----------XX-------- = --------XX-----------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $30, $06, $00                             ; -XX--------XX-------- = ----XX--XX-----------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $40, $01, $00                             ; X------------X------- = ------XX-------------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $4C, $01, $00                             ; X--XX--------X------- = --XX--XX-------------
.byte $4C, $07, $00                             ; X--XX------XXX------- = --XX--XXXX-----------
.byte $4C, $07, $00                             ; X--XX------XXX------- = --XX--XXXX-----------
.byte $7C, $07, $00                             ; XXXXX------XXX------- = --XXXXXXXX-----------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $30, $00, $00                             ; -XX------------------ = ----XX---------------
.byte $30, $00, $00                             ; -XX------------------ = ----XX---------------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------

sprite02Half:
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $40, $19, $00                             ; X--------XX--X------- = ------XX--XX---------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $00, $06, $00                             ; -----------XX-------- = --------XX-----------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $70, $07, $00                             ; XXX--------XXX------- = ----XXXXXX-----------
.byte $30, $1E, $00                             ; -XX------XXXX-------- = ----XX--XXXX---------
.byte $30, $1E, $00                             ; -XX------XXXX-------- = ----XX--XXXX---------
.byte $70, $19, $00                             ; XXX------XX--X------- = ----XXXX--XX---------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $30, $06, $00                             ; -XX--------XX-------- = ----XX--XX-----------
.byte $70, $19, $00                             ; XXX------XX--X------- = ----XXXX--XX---------

sprite03Half:
.byte $00, $78, $00                             ; -------XXXX---------- = ----------XXXX-------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $00, $66, $00                             ; -------XX--XX-------- = --------XX--XX-------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $00, $18, $00                             ; ---------XX---------- = ----------XX---------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $40, $1F, $00                             ; X--------XXXXX------- = ------XXXXXX---------
.byte $40, $7F, $00                             ; X------XXXXXXX------- = ------XXXXXXXX-------
.byte $40, $67, $00                             ; X------XX--XXX------- = ------XXXX--XX-------
.byte $40, $19, $00                             ; X--------XX--X------- = ------XX--XX---------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $40, $61, $00                             ; X------XX----X------- = ------XX----XX-------
.byte $40, $67, $00                             ; X------XX--XXX------- = ------XXXX--XX-------

sprite04Half:
.byte $0F, $00, $00                             ; ---XXXX-------------- = XXXX-----------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $33, $00, $00                             ; -XX--XX-------------- = XX--XX---------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $0C, $00, $00                             ; ---XX---------------- = --XX-----------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $7C, $01, $00                             ; XXXXX--------X------- = --XXXXXX-------------
.byte $7F, $01, $00                             ; XXXXXXX------X------- = XXXXXXXX-------------
.byte $73, $01, $00                             ; XXX--XX------X------- = XX--XXXX-------------
.byte $4C, $01, $00                             ; X--XX--------X------- = --XX--XX-------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $43, $01, $00                             ; X----XX------X------- = XX----XX-------------
.byte $73, $01, $00                             ; XXX--XX------X------- = XX--XXXX-------------

sprite05Half:
.byte $3C, $00, $00                             ; -XXXX---------------- = --XXXX---------------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $4C, $01, $00                             ; X--XX--------X------- = --XX--XX-------------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $30, $00, $00                             ; -XX------------------ = ----XX---------------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $70, $07, $00                             ; XXX--------XXX------- = ----XXXXXX-----------
.byte $3C, $06, $00                             ; -XXXX------XX-------- = --XXXX--XX-----------
.byte $3C, $06, $00                             ; -XXXX------XX-------- = --XXXX--XX-----------
.byte $4C, $07, $00                             ; X--XX------XXX------- = --XX--XXXX-----------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $70, $01, $00                             ; XXX----------X------- = ----XXXX-------------
.byte $30, $06, $00                             ; -XX--------XX-------- = ----XX--XX-----------
.byte $4C, $07, $00                             ; X--XX------XXX------- = --XX--XXXX-----------

sprite06Half:
.byte $30, $00, $00                             ; -XX------------------ = ----XX---------------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $30, $06, $00                             ; -XX--------XX-------- = ----XX--XX-----------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $40, $01, $00                             ; X------------X------- = ------XX-------------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $40, $19, $00                             ; X--------XX--X------- = ------XX--XX---------
.byte $70, $19, $00                             ; XXX------XX--X------- = ----XXXX--XX---------
.byte $70, $19, $00                             ; XXX------XX--X------- = ----XXXX--XX---------
.byte $70, $1F, $00                             ; XXX------XXXXX------- = ----XXXXXXXX---------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $00, $06, $00                             ; -----------XX-------- = --------XX-----------
.byte $00, $06, $00                             ; -----------XX-------- = --------XX-----------
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------

sprite07Half:
.byte $40, $07, $00                             ; X----------XXX------- = ------XXXX-----------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $40, $19, $00                             ; X--------XX--X------- = ------XX--XX---------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $00, $06, $00                             ; -----------XX-------- = --------XX-----------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $00, $7E, $00                             ; -------XXXXXX-------- = --------XXXXXX-------
.byte $40, $67, $00                             ; X------XX--XXX------- = ------XXXX--XX-------
.byte $40, $67, $00                             ; X------XX--XXX------- = ------XXXX--XX-------
.byte $40, $79, $00                             ; X------XXXX--X------- = ------XX--XXXX-------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $00, $1E, $00                             ; ---------XXXX-------- = --------XXXX---------
.byte $40, $19, $00                             ; X--------XX--X------- = ------XX--XX---------

;-----------------------------------------------------------------------------
; The same eight frames one dot to the right, for when Willy stands
; on an odd screen byte. Without this his white art pairs straddle
; two screen colour pixels and he renders as orange/blue fringe
; instead of white
willyHalfOdd:
sprite00HalfOdd:
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $18, $03, $00                             ; --XX--------XX------- = ---XX--XX------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $60, $00, $00                             ; XX------------------- = -----XX--------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $7E, $00, $00                             ; XXXXXX--------------- = -XXXXXX--------------
.byte $66, $03, $00                             ; XX--XX------XX------- = -XX--XXXX------------
.byte $66, $03, $00                             ; XX--XX------XX------- = -XX--XXXX------------
.byte $1E, $03, $00                             ; --XXXX------XX------- = -XXXX--XX------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $18, $03, $00                             ; --XX--------XX------- = ---XX--XX------------

sprite01HalfOdd:
.byte $00, $0C, $00                             ; ----------XX--------- = ---------XX----------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $60, $0C, $00                             ; XX--------XX--------- = -----XX--XX----------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $00, $03, $00                             ; ------------XX------- = -------XX------------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $18, $03, $00                             ; --XX--------XX------- = ---XX--XX------------
.byte $18, $0F, $00                             ; --XX------XXXX------- = ---XX--XXXX----------
.byte $18, $0F, $00                             ; --XX------XXXX------- = ---XX--XXXX----------
.byte $78, $0F, $00                             ; XXXX------XXXX------- = ---XXXXXXXX----------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $60, $00, $00                             ; XX------------------- = -----XX--------------
.byte $60, $00, $00                             ; XX------------------- = -----XX--------------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------

sprite02HalfOdd:
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $00, $33, $00                             ; --------XX--XX------- = -------XX--XX--------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $00, $0C, $00                             ; ----------XX--------- = ---------XX----------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $60, $0F, $00                             ; XX--------XXXX------- = -----XXXXXX----------
.byte $60, $3C, $00                             ; XX------XXXX--------- = -----XX--XXXX--------
.byte $60, $3C, $00                             ; XX------XXXX--------- = -----XX--XXXX--------
.byte $60, $33, $00                             ; XX------XX--XX------- = -----XXXX--XX--------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $60, $0C, $00                             ; XX--------XX--------- = -----XX--XX----------
.byte $60, $33, $00                             ; XX------XX--XX------- = -----XXXX--XX--------

sprite03HalfOdd:
.byte $00, $70, $01                             ; -------XXX----------X = -----------XXXX------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $4C, $01                             ; -------X--XX--------X = ---------XX--XX------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $30, $00                             ; --------XX----------- = -----------XX--------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $3F, $00                             ; --------XXXXXX------- = -------XXXXXX--------
.byte $00, $7F, $01                             ; -------XXXXXXX------X = -------XXXXXXXX------
.byte $00, $4F, $01                             ; -------X--XXXX------X = -------XXXX--XX------
.byte $00, $33, $00                             ; --------XX--XX------- = -------XX--XX--------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $43, $01                             ; -------X----XX------X = -------XX----XX------
.byte $00, $4F, $01                             ; -------X--XXXX------X = -------XXXX--XX------

sprite04HalfOdd:
.byte $1E, $00, $00                             ; --XXXX--------------- = -XXXX----------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $66, $00, $00                             ; XX--XX--------------- = -XX--XX--------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $18, $00, $00                             ; --XX----------------- = ---XX----------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $78, $03, $00                             ; XXXX--------XX------- = ---XXXXXX------------
.byte $7E, $03, $00                             ; XXXXXX------XX------- = -XXXXXXXX------------
.byte $66, $03, $00                             ; XX--XX------XX------- = -XX--XXXX------------
.byte $18, $03, $00                             ; --XX--------XX------- = ---XX--XX------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $06, $03, $00                             ; ----XX------XX------- = -XX----XX------------
.byte $66, $03, $00                             ; XX--XX------XX------- = -XX--XXXX------------

sprite05HalfOdd:
.byte $78, $00, $00                             ; XXXX----------------- = ---XXXX--------------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $18, $03, $00                             ; --XX--------XX------- = ---XX--XX------------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $60, $00, $00                             ; XX------------------- = -----XX--------------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $60, $0F, $00                             ; XX--------XXXX------- = -----XXXXXX----------
.byte $78, $0C, $00                             ; XXXX------XX--------- = ---XXXX--XX----------
.byte $78, $0C, $00                             ; XXXX------XX--------- = ---XXXX--XX----------
.byte $18, $0F, $00                             ; --XX------XXXX------- = ---XX--XXXX----------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $60, $03, $00                             ; XX----------XX------- = -----XXXX------------
.byte $60, $0C, $00                             ; XX--------XX--------- = -----XX--XX----------
.byte $18, $0F, $00                             ; --XX------XXXX------- = ---XX--XXXX----------

sprite06HalfOdd:
.byte $60, $00, $00                             ; XX------------------- = -----XX--------------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $60, $0C, $00                             ; XX--------XX--------- = -----XX--XX----------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $00, $03, $00                             ; ------------XX------- = -------XX------------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $00, $33, $00                             ; --------XX--XX------- = -------XX--XX--------
.byte $60, $33, $00                             ; XX------XX--XX------- = -----XXXX--XX--------
.byte $60, $33, $00                             ; XX------XX--XX------- = -----XXXX--XX--------
.byte $60, $3F, $00                             ; XX------XXXXXX------- = -----XXXXXXXX--------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $00, $0C, $00                             ; ----------XX--------- = ---------XX----------
.byte $00, $0C, $00                             ; ----------XX--------- = ---------XX----------
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------

sprite07HalfOdd:
.byte $00, $0F, $00                             ; ----------XXXX------- = -------XXXX----------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $33, $00                             ; --------XX--XX------- = -------XX--XX--------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $0C, $00                             ; ----------XX--------- = ---------XX----------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $7C, $01                             ; -------XXXXX--------X = ---------XXXXXX------
.byte $00, $4F, $01                             ; -------X--XXXX------X = -------XXXX--XX------
.byte $00, $4F, $01                             ; -------X--XXXX------X = -------XXXX--XX------
.byte $00, $73, $01                             ; -------XXX--XX------X = -------XX--XXXX------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $3C, $00                             ; --------XXXX--------- = ---------XXXX--------
.byte $00, $33, $00                             ; --------XX--XX------- = -------XX--XX--------

;-----------------------------------------------------------------------------
; All other sprites, 1bpp, one byte per row. Each byte still expands
; through binDouble into 2 screen bytes = 14 dots = 7 colour pixels,
; Left comment column is the stored byte, right is what it expands to.

spritesHalf:
sprite08Half:
.byte $E5                                       ; XXX--X-X = --XXXXXX--XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $22                                       ; --X---X- = --XX----XX----
.byte $A1                                       ; X-X----X = --XX--XX------

sprite09Half:
.byte $CB                                       ; XX--X-XX = ----XXXXXX--XX
.byte $6E                                       ; -XX-XXX- = --XXXX--XXXXXX
.byte $4E                                       ; -X--XXX- = ----XX--XXXXXX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $D3                                       ; XX-X--XX = XX--XXXXXX----
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite0AHalf:
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $8D                                       ; X---XX-X = ------XX--XXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $A7                                       ; X-X--XXX = --XX--XXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $AF                                       ; X-X-XXXX = --XX--XXXXXXXX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--

sprite0BHalf:
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $06                                       ; -----XX- = --------XXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $87                                       ; X----XXX = ------XXXXXX--

sprite0CHalf:
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------

sprite0DHalf:
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $B1                                       ; X-XX---X = XXXX--XX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $E5                                       ; XXX--X-X = --XXXXXX--XX--
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $F5                                       ; XXXX-X-X = XXXXXXXX--XX--
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------

sprite0EHalf:
.byte $D3                                       ; XX-X--XX = XX--XXXXXX----
.byte $76                                       ; -XXX-XX- = XXXXXX--XXXX--
.byte $72                                       ; -XXX--X- = XXXXXX--XX----
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $CB                                       ; XX--X-XX = ----XXXXXX--XX
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite0FHalf:
.byte $A7                                       ; X-X--XXX = --XX--XXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $85                                       ; X----X-X = ------XX--XX--

sprite10Half:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--

sprite11Half:
.byte $40                                       ; -X------ = ----XX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $B1                                       ; X-XX---X = XXXX--XX------
.byte $B1                                       ; X-XX---X = XXXX--XX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $40                                       ; -X------ = ----XX--------
.byte $E1                                       ; XXX----X = --XXXXXX------

sprite12Half:
.byte $81                                       ; X------X = ------XX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $62                                       ; -XX---X- = --XXXX--XX----
.byte $62                                       ; -XX---X- = --XXXX--XX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite13Half:
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $46                                       ; -X---XX- = ----XX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite14Half:
.byte $02                                       ; ------X- = --------XX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--

sprite15Half:
.byte $40                                       ; -X------ = ----XX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------

sprite16Half:
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $22                                       ; --X---X- = --XX----XX----
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $62                                       ; -XX---X- = --XXXX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite17Half:
.byte $81                                       ; X------X = ------XX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $46                                       ; -X---XX- = ----XX--XXXX--
.byte $46                                       ; -X---XX- = ----XX--XXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite18Half:
.byte $02                                       ; ------X- = --------XX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8D                                       ; X---XX-X = ------XX--XXXX
.byte $8D                                       ; X---XX-X = ------XX--XXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $02                                       ; ------X- = --------XX----
.byte $87                                       ; X----XXX = ------XXXXXX--

sprite19Half:
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $A7                                       ; X-X--XXX = --XX--XXXXXX--
.byte $76                                       ; -XXX-XX- = XXXXXX--XXXX--
.byte $D9                                       ; XX-XX--X = XX--XXXX----XX
.byte $58                                       ; -X-XX--- = XX--XX------XX
.byte $58                                       ; -X-XX--- = XX--XX------XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

sprite1AHalf:
.byte $81                                       ; X------X = ------XX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $81                                       ; X------X = ------XX------
.byte $83                                       ; X-----XX = ------XXXX----
.byte $02                                       ; ------X- = --------XX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $91                                       ; X--X---X = XX----XX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $60                                       ; -XX----- = --XXXX--------

sprite1BHalf:
.byte $02                                       ; ------X- = --------XX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $02                                       ; ------X- = --------XX----
.byte $06                                       ; -----XX- = --------XXXX--
.byte $04                                       ; -----X-- = ----------XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $62                                       ; -XX---X- = --XXXX--XX----
.byte $22                                       ; --X---X- = --XX----XX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $81                                       ; X------X = ------XX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $00                                       ; -------- = --------------

sprite1CHalf:
.byte $06                                       ; -----XX- = --------XXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $06                                       ; -----XX- = --------XXXX--
.byte $04                                       ; -----X-- = ----------XX--
.byte $0C                                       ; ----XX-- = ----------XXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $81                                       ; X------X = ------XX------
.byte $83                                       ; X-----XX = ------XXXX----
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite1DHalf:
.byte $04                                       ; -----X-- = ----------XX--
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $00                                       ; -------- = --------------

sprite1EHalf:
.byte $20                                       ; --X----- = --XX----------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $22                                       ; --X---X- = --XX----XX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $00                                       ; -------- = --------------

sprite1FHalf:
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $20                                       ; --X----- = --XX----------
.byte $30                                       ; --XX---- = XXXX----------
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $22                                       ; --X---X- = --XX----XX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $81                                       ; X------X = ------XX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite20Half:
.byte $40                                       ; -X------ = ----XX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $40                                       ; -X------ = ----XX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $20                                       ; --X----- = --XX----------
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $46                                       ; -X---XX- = ----XX--XXXX--
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $81                                       ; X------X = ------XX------
.byte $83                                       ; X-----XX = ------XXXX----
.byte $00                                       ; -------- = --------------

sprite21Half:
.byte $81                                       ; X------X = ------XX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $81                                       ; X------X = ------XX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $40                                       ; -X------ = ----XX--------
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $89                                       ; X---X--X = ------XX----XX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $06                                       ; -----XX- = --------XXXX--

sprite22Half:
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $81                                       ; X------X = ------XX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $D3                                       ; XX-X--XX = XX--XXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $62                                       ; -XX---X- = --XXXX--XX----

sprite23Half:
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $02                                       ; ------X- = --------XX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $A7                                       ; X-X--XXX = --XX--XXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $E5                                       ; XXX--X-X = --XXXXXX--XX--

sprite24Half:
.byte $06                                       ; -----XX- = --------XXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $8B                                       ; X---X-XX = ------XXXX--XX
.byte $8B                                       ; X---X-XX = ------XXXX--XX
.byte $8B                                       ; X---X-XX = ------XXXX--XX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $04                                       ; -----X-- = ----------XX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $97                                       ; X--X-XXX = XX----XXXXXX--
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $EB                                       ; XXX-X-XX = --XXXXXXXX--XX

sprite25Half:
.byte $06                                       ; -----XX- = --------XXXX--
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $8B                                       ; X---X-XX = ------XXXX--XX
.byte $8B                                       ; X---X-XX = ------XXXX--XX
.byte $8B                                       ; X---X-XX = ------XXXX--XX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $06                                       ; -----XX- = --------XXXX--
.byte $04                                       ; -----X-- = ----------XX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $2E                                       ; --X-XXX- = --XX----XXXXXX
.byte $AF                                       ; X-X-XXXX = --XX--XXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $CB                                       ; XX--X-XX = ----XXXXXX--XX

sprite26Half:
.byte $60                                       ; -XX----- = --XXXX--------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $D1                                       ; XX-X---X = XX--XXXX------
.byte $D1                                       ; XX-X---X = XX--XXXX------
.byte $D1                                       ; XX-X---X = XX--XXXX------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $20                                       ; --X----- = --XX----------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $74                                       ; -XXX-X-- = XXXXXX----XX--
.byte $F5                                       ; XXXX-X-X = XXXXXXXX--XX--
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $D3                                       ; XX-X--XX = XX--XXXXXX----

sprite27Half:
.byte $60                                       ; -XX----- = --XXXX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $D1                                       ; XX-X---X = XX--XXXX------
.byte $D1                                       ; XX-X---X = XX--XXXX------
.byte $D1                                       ; XX-X---X = XX--XXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $20                                       ; --X----- = --XX----------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E9                                       ; XXX-X--X = --XXXXXX----XX
.byte $FB                                       ; XXXXX-XX = XXXXXXXXXX--XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $D7                                       ; XX-X-XXX = XX--XXXXXXXX--

sprite28Half:
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $40                                       ; -X------ = ----XX--------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E5                                       ; XXX--X-X = --XXXXXX--XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $A7                                       ; X-X--XXX = --XX--XXXXXX--

sprite29Half:
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $81                                       ; X------X = ------XX------
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $CB                                       ; XX--X-XX = ----XXXXXX--XX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $46                                       ; -X---XX- = ----XX--XXXX--

sprite2AHalf:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----

sprite2BHalf:
.byte $10                                       ; ---X---- = XX------------
.byte $10                                       ; ---X---- = XX------------
.byte $10                                       ; ---X---- = XX------------
.byte $10                                       ; ---X---- = XX------------
.byte $10                                       ; ---X---- = XX------------
.byte $10                                       ; ---X---- = XX------------
.byte $10                                       ; ---X---- = XX------------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------

sprite2CHalf:
.byte $20                                       ; --X----- = --XX----------
.byte $20                                       ; --X----- = --XX----------
.byte $20                                       ; --X----- = --XX----------
.byte $20                                       ; --X----- = --XX----------
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $22                                       ; --X---X- = --XX----XX----
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----

sprite2DHalf:
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $62                                       ; -XX---X- = --XXXX--XX----
.byte $62                                       ; -XX---X- = --XXXX--XX----
.byte $62                                       ; -XX---X- = --XXXX--XX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--

sprite2EHalf:
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $48                                       ; -X--X--- = ----XX------XX
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--

sprite2FHalf:
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $12                                       ; ---X--X- = XX------XX----
.byte $22                                       ; --X---X- = --XX----XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----

sprite30Half:
.byte $04                                       ; -----X-- = ----------XX--
.byte $04                                       ; -----X-- = ----------XX--
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--

sprite31Half:
.byte $0C                                       ; ----XX-- = ----------XXXX
.byte $0C                                       ; ----XX-- = ----------XXXX
.byte $0C                                       ; ----XX-- = ----------XXXX
.byte $0C                                       ; ----XX-- = ----------XXXX
.byte $4C                                       ; -X--XX-- = ----XX----XXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX

sprite32Half:
.byte $08                                       ; ----X--- = ------------XX
.byte $08                                       ; ----X--- = ------------XX
.byte $08                                       ; ----X--- = ------------XX
.byte $08                                       ; ----X--- = ------------XX
.byte $08                                       ; ----X--- = ------------XX
.byte $08                                       ; ----X--- = ------------XX
.byte $08                                       ; ----X--- = ------------XX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX

sprite33Half:
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $B7                                       ; X-XX-XXX = XXXX--XXXXXX--
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------

sprite34Half:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite35Half:
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite36Half:
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite37Half:
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite38Half:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $76                                       ; -XXX-XX- = XXXXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite39Half:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $6E                                       ; -XX-XXX- = --XXXX--XXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite3AHalf:
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $ED                                       ; XXX-XX-X = --XXXXXX--XXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--

sprite3BHalf:
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $40                                       ; -X------ = ----XX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $50                                       ; -X-X---- = XX--XX--------
.byte $91                                       ; X--X---X = XX----XX------
.byte $91                                       ; X--X---X = XX----XX------
.byte $00                                       ; -------- = --------------

sprite3CHalf:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $12                                       ; ---X--X- = XX------XX----

sprite3DHalf:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $81                                       ; X------X = ------XX------
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--

sprite3EHalf:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $06                                       ; -----XX- = --------XXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $20                                       ; --X----- = --XX----------

sprite3FHalf:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $22                                       ; --X---X- = --XX----XX----
.byte $04                                       ; -----X-- = ----------XX--

sprite40Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX

sprite41Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $02                                       ; ------X- = --------XX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $C9                                       ; XX--X--X = ----XXXX----XX

sprite42Half:
.byte $06                                       ; -----XX- = --------XXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $02                                       ; ------X- = --------XX----
.byte $06                                       ; -----XX- = --------XXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $0A                                       ; ----X-X- = --------XX--XX
.byte $89                                       ; X---X--X = ------XX----XX
.byte $89                                       ; X---X--X = ------XX----XX
.byte $00                                       ; -------- = --------------

sprite43Half:
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--

sprite44Half:
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--

sprite45Half:
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--

sprite46Half:
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite47Half:
.byte $40                                       ; -X------ = ----XX--------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $50                                       ; -X-X---- = XX--XX--------
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $40                                       ; -X------ = ----XX--------

sprite48Half:
.byte $81                                       ; X------X = ------XX------
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $81                                       ; X------X = ------XX------
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $26                                       ; --X--XX- = --XX----XXXX--
.byte $A7                                       ; X-X--XXX = --XX--XXXXXX--
.byte $E5                                       ; XXX--X-X = --XXXXXX--XX--
.byte $64                                       ; -XX--X-- = --XXXX----XX--
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $81                                       ; X------X = ------XX------

sprite49Half:
.byte $02                                       ; ------X- = --------XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $46                                       ; -X---XX- = ----XX--XXXX--
.byte $4A                                       ; -X--X-X- = ----XX--XX--XX
.byte $46                                       ; -X---XX- = ----XX--XXXX--
.byte $48                                       ; -X--X--- = ----XX------XX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $EB                                       ; XXX-X-XX = --XXXXXXXX--XX
.byte $AF                                       ; X-X-XXXX = --XX--XXXXXXXX
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----

sprite4AHalf:
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $4A                                       ; -X--X-X- = ----XX--XX--XX
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $4A                                       ; -X--X-X- = ----XX--XX--XX
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $48                                       ; -X--X--- = ----XX------XX
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $C9                                       ; XX--X--X = ----XXXX----XX
.byte $4A                                       ; -X--X-X- = ----XX--XX--XX
.byte $4A                                       ; -X--X-X- = ----XX--XX--XX
.byte $4A                                       ; -X--X-X- = ----XX--XX--XX
.byte $4A                                       ; -X--X-X- = ----XX--XX--XX
.byte $4C                                       ; -X--XX-- = ----XX----XXXX
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $02                                       ; ------X- = --------XX----

sprite4BHalf:
.byte $62                                       ; -XX---X- = --XXXX--XX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $BB                                       ; X-XXX-XX = XXXX--XXXX--XX
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $FB                                       ; XXXXX-XX = XXXXXXXXXX--XX
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $BB                                       ; X-XXX-XX = XXXX--XXXX--XX
.byte $E5                                       ; XXX--X-X = --XXXXXX--XX--
.byte $F5                                       ; XXXX-X-X = XXXXXXXX--XX--

sprite4CHalf:
.byte $00                                       ; -------- = --------------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $BF                                       ; X-XXXXXX = XXXX--XXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $E5                                       ; XXX--X-X = --XXXXXX--XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----

sprite4DHalf:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $00                                       ; -------- = --------------

sprite4EHalf:
.byte $00                                       ; -------- = --------------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $BF                                       ; X-XXXXXX = XXXX--XXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $E5                                       ; XXX--X-X = --XXXXXX--XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----

sprite4FHalf:
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $40                                       ; -X------ = ----XX--------
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----

sprite50Half:
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $81                                       ; X------X = ------XX------
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--

sprite51Half:
; The source pose sits half a destination pixel right of sprite50, which the
; 2:1 crunch cannot represent: it straddled every pair boundary and fattened
; the mast to two pixels and scrambled the legs.  Held at sprite50's position
; instead, so the walk reads 2,3,3,4 - a one-frame dwell rather than a shape
; change.  Copy sprite52's bytes here instead to dwell at the far end.
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $81                                       ; X------X = ------XX------
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--

sprite52Half:
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $02                                       ; ------X- = --------XX----
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX

sprite53Half:
.byte $30                                       ; --XX---- = XXXX----------
.byte $30                                       ; --XX---- = XXXX----------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------

sprite54Half:
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------

sprite55Half:
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $81                                       ; X------X = ------XX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--

sprite56Half:
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $4C                                       ; -X--XX-- = ----XX----XXXX
.byte $C5                                       ; XX---X-X = ----XXXX--XX--

sprite57Half:
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $32                                       ; --XX--X- = XXXX----XX----
.byte $A3                                       ; X-X---XX = --XX--XXXX----

sprite58Half:
.byte $06                                       ; -----XX- = --------XXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--

sprite59Half:
.byte $06                                       ; -----XX- = --------XXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $02                                       ; ------X- = --------XX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $83                                       ; X-----XX = ------XXXX----

sprite5AHalf:
.byte $0C                                       ; ----XX-- = ----------XXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $06                                       ; -----XX- = --------XXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $06                                       ; -----XX- = --------XXXX--
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX

sprite5BHalf:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--

sprite5CHalf:
.byte $60                                       ; -XX----- = --XXXX--------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $4E                                       ; -X--XXX- = ----XX--XXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--

sprite5DHalf:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--

sprite5EHalf:
.byte $06                                       ; -----XX- = --------XXXX--
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $72                                       ; -XXX--X- = XXXXXX--XX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--

sprite5FHalf:
.byte $40                                       ; -X------ = ----XX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $40                                       ; -X------ = ----XX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $50                                       ; -X-X---- = XX--XX--------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $12                                       ; ---X--X- = XX------XX----
.byte $E1                                       ; XXX----X = --XXXXXX------

sprite60Half:
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite61Half:
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $04                                       ; -----X-- = ----------XX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--

sprite62Half:
.byte $02                                       ; ------X- = --------XX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $4A                                       ; -X--X-X- = ----XX--XX--XX
.byte $4A                                       ; -X--X-X- = ----XX--XX--XX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $02                                       ; ------X- = --------XX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $4A                                       ; -X--X-X- = ----XX--XX--XX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $40                                       ; -X------ = ----XX--------
.byte $87                                       ; X----XXX = ------XXXXXX--

sprite63Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $42                                       ; -X----X- = ----XX--XX----

sprite64Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite65Half:
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite66Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite67Half:
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $40                                       ; -X------ = ----XX--------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $40                                       ; -X------ = ----XX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------

sprite68Half:
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $81                                       ; X------X = ------XX------
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite69Half:
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $EB                                       ; XXX-X-XX = --XXXXXXXX--XX
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite6AHalf:
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $02                                       ; ------X- = --------XX----
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $02                                       ; ------X- = --------XX----
.byte $02                                       ; ------X- = --------XX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite6BHalf:
.byte $81                                       ; X------X = ------XX------
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $24                                       ; --X--X-- = --XX------XX--

sprite6CHalf:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $81                                       ; X------X = ------XX------
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $62                                       ; -XX---X- = --XXXX--XX----
.byte $D7                                       ; XX-X-XXX = XX--XXXXXXXX--
.byte $6E                                       ; -XX-XXX- = --XXXX--XXXXXX

sprite6DHalf:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $0C                                       ; ----XX-- = ----------XXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $81                                       ; X------X = ------XX------
.byte $00                                       ; -------- = --------------
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $46                                       ; -X---XX- = ----XX--XXXX--
.byte $A9                                       ; X-X-X--X = --XX--XX----XX
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--

sprite6EHalf:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $02                                       ; ------X- = --------XX----
.byte $89                                       ; X---X--X = ------XX----XX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $8D                                       ; X---XX-X = ------XX--XXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $D5                                       ; XX-X-X-X = XX--XXXX--XX--
.byte $F9                                       ; XXXXX--X = XXXXXXXX----XX
.byte $B5                                       ; X-XX-X-X = XXXX--XX--XX--
.byte $28                                       ; --X-X--- = --XX--------XX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $95                                       ; X--X-X-X = XX----XX--XX--
.byte $E9                                       ; XXX-X--X = --XXXXXX----XX
.byte $A7                                       ; X-X--XXX = --XX--XXXXXX--

sprite6FHalf:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $0A                                       ; ----X-X- = --------XX--XX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $D1                                       ; XX-X---X = XX--XXXX------
.byte $E5                                       ; XXX--X-X = --XXXXXX--XX--
.byte $B1                                       ; X-XX---X = XXXX--XX------
.byte $28                                       ; --X-X--- = --XX--------XX
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $95                                       ; X--X-X-X = XX----XX--XX--

sprite70Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $81                                       ; X------X = ------XX------
.byte $00                                       ; -------- = --------------
.byte $02                                       ; ------X- = --------XX----
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $02                                       ; ------X- = --------XX----
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $A7                                       ; X-X--XXX = --XX--XXXXXX--
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----

sprite71Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $81                                       ; X------X = ------XX------
.byte $02                                       ; ------X- = --------XX----
.byte $20                                       ; --X----- = --XX----------
.byte $00                                       ; -------- = --------------
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite72Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $02                                       ; ------X- = --------XX----
.byte $40                                       ; -X------ = ----XX--------
.byte $81                                       ; X------X = ------XX------
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite73Half:
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $81                                       ; X------X = ------XX------
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

sprite74Half:
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $A7                                       ; X-X--XXX = --XX--XXXXXX--
.byte $A7                                       ; X-X--XXX = --XX--XXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $81                                       ; X------X = ------XX------
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FD                                       ; XXXXXX-X = XXXXXXXX--XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

sprite75Half:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $81                                       ; X------X = ------XX------
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $38                                       ; --XXX--- = XXXX--------XX
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $FB                                       ; XXXXX-XX = XXXXXXXXXX--XX
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $38                                       ; --XXX--- = XXXX--------XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

sprite76Half:
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $E5                                       ; XXX--X-X = --XXXXXX--XX--
.byte $E5                                       ; XXX--X-X = --XXXXXX--XX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $81                                       ; X------X = ------XX------
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $FB                                       ; XXXXX-XX = XXXXXXXXXX--XX
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $FB                                       ; XXXXX-XX = XXXXXXXXXX--XX
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $FB                                       ; XXXXX-XX = XXXXXXXXXX--XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

sprite77Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $93                                       ; X--X--XX = XX----XXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $93                                       ; X--X--XX = XX----XXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----

sprite78Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $26                                       ; --X--XX- = --XX----XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $26                                       ; --X--XX- = --XX----XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite79Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $2C                                       ; --X-XX-- = --XX------XXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $2A                                       ; --X-X-X- = --XX----XX--XX
.byte $EB                                       ; XXX-X-XX = --XXXXXXXX--XX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite7AHalf:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $4C                                       ; -X--XX-- = ----XX----XXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $4C                                       ; -X--XX-- = ----XX----XXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite7BHalf:
.byte $00                                       ; -------- = --------------
.byte $40                                       ; -X------ = ----XX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $D1                                       ; XX-X---X = XX--XXXX------
.byte $50                                       ; -X-X---- = XX--XX--------
.byte $12                                       ; ---X--X- = XX------XX----
.byte $12                                       ; ---X--X- = XX------XX----
.byte $91                                       ; X--X---X = XX----XX------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $A3                                       ; X-X---XX = --XX--XXXX----

sprite7CHalf:
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $20                                       ; --X----- = --XX----------
.byte $20                                       ; --X----- = --XX----------
.byte $20                                       ; --X----- = --XX----------
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $22                                       ; --X---X- = --XX----XX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $46                                       ; -X---XX- = ----XX--XXXX--

sprite7DHalf:
.byte $00                                       ; -------- = --------------
.byte $20                                       ; --X----- = --XX----------
.byte $30                                       ; --XX---- = XXXX----------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $B1                                       ; X-XX---X = XXXX--XX------
.byte $91                                       ; X--X---X = XX----XX------
.byte $8D                                       ; X---XX-X = ------XX--XXXX
.byte $4C                                       ; -X--XX-- = ----XX----XXXX
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $8B                                       ; X---X-XX = ------XXXX--XX

sprite7EHalf:
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $89                                       ; X---X--X = ------XX----XX
.byte $89                                       ; X---X--X = ------XX----XX
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $06                                       ; -----XX- = --------XXXX--
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $8D                                       ; X---XX-X = ------XX--XXXX

sprite7FHalf:
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $81                                       ; X------X = ------XX------
.byte $91                                       ; X--X---X = XX----XX------
.byte $91                                       ; X--X---X = XX----XX------
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $F1                                       ; XXXX---X = XXXXXXXX------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $B1                                       ; X-XX---X = XXXX--XX------

sprite80Half:
.byte $00                                       ; -------- = --------------
.byte $04                                       ; -----X-- = ----------XX--
.byte $0C                                       ; ----XX-- = ----------XXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $8D                                       ; X---XX-X = ------XX--XXXX
.byte $89                                       ; X---X--X = ------XX----XX
.byte $B1                                       ; X-XX---X = XXXX--XX------
.byte $32                                       ; --XX--X- = XXXX----XX----
.byte $22                                       ; --X---X- = --XX----XX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $D1                                       ; XX-X---X = XX--XXXX------

sprite81Half:
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $04                                       ; -----X-- = ----------XX--
.byte $04                                       ; -----X-- = ----------XX--
.byte $04                                       ; -----X-- = ----------XX--
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $E3                                       ; XXX---XX = --XXXXXXXX----
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $62                                       ; -XX---X- = --XXXX--XX----

sprite82Half:
.byte $00                                       ; -------- = --------------
.byte $02                                       ; ------X- = --------XX----
.byte $06                                       ; -----XX- = --------XXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $8F                                       ; X---XXXX = ------XXXXXXXX
.byte $8B                                       ; X---X-XX = ------XXXX--XX
.byte $0A                                       ; ----X-X- = --------XX--XX
.byte $48                                       ; -X--X--- = ----XX------XX
.byte $48                                       ; -X--X--- = ----XX------XX
.byte $89                                       ; X---X--X = ------XX----XX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C5                                       ; XX---X-X = ----XXXX--XX--

sprite83Half:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

sprite84Half:
.byte $00                                       ; -------- = --------------
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $6E                                       ; -XX-XXX- = --XXXX--XXXXXX
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $00                                       ; -------- = --------------
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $00                                       ; -------- = --------------

sprite85Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $6E                                       ; -XX-XXX- = --XXXX--XXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------

sprite86Half:
.byte $00                                       ; -------- = --------------
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $00                                       ; -------- = --------------

sprite87Half:
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $91                                       ; X--X---X = XX----XX------
.byte $91                                       ; X--X---X = XX----XX------
.byte $91                                       ; X--X---X = XX----XX------
.byte $91                                       ; X--X---X = XX----XX------
.byte $91                                       ; X--X---X = XX----XX------
.byte $91                                       ; X--X---X = XX----XX------
.byte $91                                       ; X--X---X = XX----XX------

sprite88Half:
.byte $00                                       ; -------- = --------------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $22                                       ; --X---X- = --XX----XX----
.byte $22                                       ; --X---X- = --XX----XX----
.byte $22                                       ; --X---X- = --XX----XX----
.byte $14                                       ; ---X-X-- = XX--------XX--
.byte $14                                       ; ---X-X-- = XX--------XX--
.byte $14                                       ; ---X-X-- = XX--------XX--
.byte $14                                       ; ---X-X-- = XX--------XX--
.byte $14                                       ; ---X-X-- = XX--------XX--
.byte $10                                       ; ---X---- = XX------------

sprite89Half:
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $00                                       ; -------- = --------------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX

sprite8AHalf:
.byte $00                                       ; -------- = --------------
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $4A                                       ; -X--X-X- = ----XX--XX--XX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $28                                       ; --X-X--- = --XX--------XX
.byte $28                                       ; --X-X--- = --XX--------XX
.byte $28                                       ; --X-X--- = --XX--------XX
.byte $28                                       ; --X-X--- = --XX--------XX
.byte $28                                       ; --X-X--- = --XX--------XX
.byte $08                                       ; ----X--- = ------------XX

sprite8BHalf:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $BB                                       ; X-XXX-XX = XXXX--XXXX--XX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $DD                                       ; XX-XXX-X = XX--XXXX--XXXX
.byte $5E                                       ; -X-XXXX- = XX--XX--XXXXXX
.byte $5E                                       ; -X-XXXX- = XX--XX--XXXXXX
.byte $C5                                       ; XX---X-X = ----XXXX--XX--
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $02                                       ; ------X- = --------XX----

sprite8CHalf:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $DD                                       ; XX-XXX-X = XX--XXXX--XXXX
.byte $DD                                       ; XX-XXX-X = XX--XXXX--XXXX
.byte $BB                                       ; X-XXX-XX = XXXX--XXXX--XX
.byte $BB                                       ; X-XXX-XX = XXXX--XXXX--XX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $DD                                       ; XX-XXX-X = XX--XXXX--XXXX
.byte $46                                       ; -X---XX- = ----XX--XXXX--
.byte $46                                       ; -X---XX- = ----XX--XXXX--
.byte $40                                       ; -X------ = ----XX--------

sprite8DHalf:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $DD                                       ; XX-XXX-X = XX--XXXX--XXXX
.byte $56                                       ; -X-X-XX- = XX--XX--XXXX--
.byte $56                                       ; -X-X-XX- = XX--XX--XXXX--
.byte $DD                                       ; XX-XXX-X = XX--XXXX--XXXX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $BB                                       ; X-XXX-XX = XXXX--XXXX--XX
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $46                                       ; -X---XX- = ----XX--XXXX--
.byte $02                                       ; ------X- = --------XX----

sprite8EHalf:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $DD                                       ; XX-XXX-X = XX--XXXX--XXXX
.byte $5E                                       ; -X-XXXX- = XX--XX--XXXXXX
.byte $5E                                       ; -X-XXXX- = XX--XX--XXXXXX
.byte $5E                                       ; -X-XXXX- = XX--XX--XXXXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $A3                                       ; X-X---XX = --XX--XXXX----
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $81                                       ; X------X = ------XX------

sprite8FHalf:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $FB                                       ; XXXXX-XX = XXXXXXXXXX--XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $9F                                       ; X--XXXXX = XX----XXXXXXXX
.byte $00                                       ; -------- = --------------
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite90Half:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $FB                                       ; XXXXX-XX = XXXXXXXXXX--XX
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $BF                                       ; X-XXXXXX = XXXX--XXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FD                                       ; XXXXXX-X = XXXXXXXX--XXXX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $9F                                       ; X--XXXXX = XX----XXXXXXXX
.byte $00                                       ; -------- = --------------
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite91Half:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $FB                                       ; XXXXX-XX = XXXXXXXXXX--XX
.byte $FB                                       ; XXXXX-XX = XXXXXXXXXX--XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $9B                                       ; X--XX-XX = XX----XXXX--XX
.byte $04                                       ; -----X-- = ----------XX--
.byte $20                                       ; --X----- = --XX----------
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite92Half:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $FB                                       ; XXXXX-XX = XXXXXXXXXX--XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FB                                       ; XXXXX-XX = XXXXXXXXXX--XX
.byte $7C                                       ; -XXXXX-- = XXXXXX----XXXX
.byte $3E                                       ; --XXXXX- = XXXX----XXXXXX
.byte $DF                                       ; XX-XXXXX = XX--XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $9F                                       ; X--XXXXX = XX----XXXXXXXX
.byte $00                                       ; -------- = --------------
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $64                                       ; -XX--X-- = --XXXX----XX--
.byte $C3                                       ; XX----XX = ----XXXXXX----

sprite93Half:
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $40                                       ; -X------ = ----XX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $60                                       ; -XX----- = --XXXX--------
.byte $70                                       ; -XXX---- = XXXXXX--------
.byte $D3                                       ; XX-X--XX = XX--XXXXXX----
.byte $D3                                       ; XX-X--XX = XX--XXXXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $D3                                       ; XX-X--XX = XX--XXXXXX----
.byte $72                                       ; -XXX--X- = XXXXXX--XX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $B1                                       ; X-XX---X = XXXX--XX------
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----

sprite94Half:
.byte $83                                       ; X-----XX = ------XXXX----
.byte $81                                       ; X------X = ------XX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $A7                                       ; X-X--XXX = --XX--XXXXXX--
.byte $A7                                       ; X-X--XXX = --XX--XXXXXX--
.byte $06                                       ; -----XX- = --------XXXX--
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $B7                                       ; X-XX-XXX = XXXX--XXXXXX--
.byte $F5                                       ; XXXX-X-X = XXXXXXXX--XX--
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $72                                       ; -XXX--X- = XXXXXX--XX----
.byte $B5                                       ; X-XX-X-X = XXXX--XX--XX--
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $85                                       ; X----X-X = ------XX--XX--

sprite95Half:
.byte $02                                       ; ------X- = --------XX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $81                                       ; X------X = ------XX------
.byte $C1                                       ; XX-----X = ----XXXX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $2E                                       ; --X-XXX- = --XX----XXXXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $0A                                       ; ----X-X- = --------XX--XX
.byte $BF                                       ; X-XXXXXX = XXXX--XXXXXXXX
.byte $B9                                       ; X-XXX--X = XXXX--XX----XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $72                                       ; -XXX--X- = XXXXXX--XX----
.byte $B5                                       ; X-XX-X-X = XXXX--XX--XX--
.byte $BF                                       ; X-XXXXXX = XXXX--XXXXXXXX
.byte $85                                       ; X----X-X = ------XX--XX--

sprite96Half:
.byte $06                                       ; -----XX- = --------XXXX--
.byte $02                                       ; ------X- = --------XX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $4E                                       ; -X--XXX- = ----XX--XXXXXX
.byte $4E                                       ; -X--XXX- = ----XX--XXXXXX
.byte $0C                                       ; ----XX-- = ----------XXXX
.byte $0E                                       ; ----XXX- = --------XXXXXX
.byte $6E                                       ; -XX-XXX- = --XXXX--XXXXXX
.byte $EB                                       ; XXX-X-XX = --XXXXXXXX--XX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $E5                                       ; XXX--X-X = --XXXXXX--XX--
.byte $6A                                       ; -XX-X-X- = --XXXX--XX--XX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $0A                                       ; ----X-X- = --------XX--XX

sprite97Half:
.byte $A1                                       ; X-X----X = --XX--XX------
.byte $40                                       ; -X------ = ----XX--------
.byte $E1                                       ; XXX----X = --XXXXXX------
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $52                                       ; -X-X--X- = XX--XX--XX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $F3                                       ; XXXX--XX = XXXXXXXXXX----
.byte $40                                       ; -X------ = ----XX--------
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----
.byte $B3                                       ; X-XX--XX = XXXX--XXXX----

sprite98Half:
.byte $81                                       ; X------X = ------XX------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $81                                       ; X------X = ------XX------
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--

sprite99Half:
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $83                                       ; X-----XX = ------XXXX----
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $C7                                       ; XX---XXX = ----XXXXXXXX--
.byte $83                                       ; X-----XX = ------XXXX----
.byte $44                                       ; -X---X-- = ----XX----XX--
.byte $EB                                       ; XXX-X-XX = --XXXXXXXX--XX
.byte $AF                                       ; X-X-XXXX = --XX--XXXXXXXX
.byte $44                                       ; -X---X-- = ----XX----XX--

sprite9AHalf:
.byte $87                                       ; X----XXX = ------XXXXXX--
.byte $85                                       ; X----X-X = ------XX--XX--
.byte $02                                       ; ------X- = --------XX----
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $4A                                       ; -X--X-X- = ----XX--XX--XX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $CF                                       ; XX--XXXX = ----XXXXXXXXXX
.byte $02                                       ; ------X- = --------XX----
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX
.byte $CD                                       ; XX--XX-X = ----XXXX--XXXX

sprite9BHalf:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

sprite9CHalf:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

sprite9DHalf:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

sprite9EHalf:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

sprite9FHalf:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteA0Half:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteA1Half:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteA2Half:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteA3Half:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteA4Half:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $FD                                       ; XXXXXX-X = XXXXXXXX--XXXX
.byte $FD                                       ; XXXXXX-X = XXXXXXXX--XXXX
.byte $F9                                       ; XXXXX--X = XXXXXXXX----XX
.byte $BD                                       ; X-XXXX-X = XXXX--XX--XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $BB                                       ; X-XXX-XX = XXXX--XXXX--XX
.byte $BF                                       ; X-XXXXXX = XXXX--XXXXXXXX
.byte $B9                                       ; X-XXX--X = XXXX--XX----XX
.byte $BF                                       ; X-XXXXXX = XXXX--XXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FD                                       ; XXXXXX-X = XXXXXXXX--XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteA5Half:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteA6Half:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteA7Half:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $A5                                       ; X-X--X-X = --XX--XX--XX--
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $42                                       ; -X----X- = ----XX--XX----
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $18                                       ; ---XX--- = XX----------XX

spriteA8Half:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteA9Half:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $58                                       ; -X-XX--- = XX--XX------XX
.byte $F9                                       ; XXXXX--X = XXXXXXXX----XX
.byte $7C                                       ; -XXXXX-- = XXXXXX----XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $78                                       ; -XXXX--- = XXXXXX------XX
.byte $F9                                       ; XXXXX--X = XXXXXXXX----XX
.byte $58                                       ; -X-XX--- = XX--XX------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteAAHalf:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteABHalf:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteACHalf:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteADHalf:
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $18                                       ; ---XX--- = XX----------XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX

spriteAEHalf:
.byte $00                                       ; -------- = --------------
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $24                                       ; --X--X-- = --XX------XX--
.byte $DB                                       ; XX-XX-XX = XX--XXXXXX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $3C                                       ; --XXXX-- = XXXX------XXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $66                                       ; -XX--XX- = --XXXX--XXXX--
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $5A                                       ; -X-XX-X- = XX--XX--XX--XX
.byte $7E                                       ; -XXXXXX- = XXXXXX--XXXXXX
.byte $00                                       ; -------- = --------------

spriteAFHalf:
.byte $C3                                       ; XX----XX = ----XXXXXX----
.byte $CB                                       ; XX--X-XX = ----XXXXXX--XX
.byte $E7                                       ; XXX--XXX = --XXXXXXXXXX--
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $EF                                       ; XXX-XXXX = --XXXXXXXXXXXX
.byte $F7                                       ; XXXX-XXX = XXXXXXXXXXXX--
.byte $EB                                       ; XXX-X-XX = --XXXXXXXX--XX
.byte $00                                       ; -------- = --------------
.byte $81                                       ; X------X = ------XX------
.byte $B7                                       ; X-XX-XXX = XXXX--XXXXXX--
.byte $F9                                       ; XXXXX--X = XXXXXXXX----XX
.byte $99                                       ; X--XX--X = XX----XX----XX
.byte $FF                                       ; XXXXXXXX = XXXXXXXXXXXXXX
.byte $B7                                       ; X-XX-XXX = XXXX--XXXXXX--
.byte $81                                       ; X------X = ------XX------

;-----------------------------------------------------------------------------
; Odd-alignment lookup. Moves every dot of a byte one place right
; (bit i -> bit i+1); halfShiftCarry is the dot that falls out of
; bit 6 and has to slot into bit 0 of the next byte. Bit 7 is the
; palette select, not a dot, so it is dropped but comes back when
; the colour mask is applied.
;
;   odd[0] = halfShiftDots [L]
;   odd[1] = halfShiftDots [R] | halfShiftCarry[L]
;   odd[2] = halfShiftCarry[R]
;
; A table rather than an asl. No bit shifting anywhere, not even
; at level-init time.

halfShiftDots:
.byte $00, $02, $04, $06, $08, $0A, $0C, $0E    ; $00
.byte $10, $12, $14, $16, $18, $1A, $1C, $1E    ; $08
.byte $20, $22, $24, $26, $28, $2A, $2C, $2E    ; $10
.byte $30, $32, $34, $36, $38, $3A, $3C, $3E    ; $18
.byte $40, $42, $44, $46, $48, $4A, $4C, $4E    ; $20
.byte $50, $52, $54, $56, $58, $5A, $5C, $5E    ; $28
.byte $60, $62, $64, $66, $68, $6A, $6C, $6E    ; $30
.byte $70, $72, $74, $76, $78, $7A, $7C, $7E    ; $38
.byte $00, $02, $04, $06, $08, $0A, $0C, $0E    ; $40
.byte $10, $12, $14, $16, $18, $1A, $1C, $1E    ; $48
.byte $20, $22, $24, $26, $28, $2A, $2C, $2E    ; $50
.byte $30, $32, $34, $36, $38, $3A, $3C, $3E    ; $58
.byte $40, $42, $44, $46, $48, $4A, $4C, $4E    ; $60
.byte $50, $52, $54, $56, $58, $5A, $5C, $5E    ; $68
.byte $60, $62, $64, $66, $68, $6A, $6C, $6E    ; $70
.byte $70, $72, $74, $76, $78, $7A, $7C, $7E    ; $78
.byte $00, $02, $04, $06, $08, $0A, $0C, $0E    ; $80
.byte $10, $12, $14, $16, $18, $1A, $1C, $1E    ; $88
.byte $20, $22, $24, $26, $28, $2A, $2C, $2E    ; $90
.byte $30, $32, $34, $36, $38, $3A, $3C, $3E    ; $98
.byte $40, $42, $44, $46, $48, $4A, $4C, $4E    ; $A0
.byte $50, $52, $54, $56, $58, $5A, $5C, $5E    ; $A8
.byte $60, $62, $64, $66, $68, $6A, $6C, $6E    ; $B0
.byte $70, $72, $74, $76, $78, $7A, $7C, $7E    ; $B8
.byte $00, $02, $04, $06, $08, $0A, $0C, $0E    ; $C0
.byte $10, $12, $14, $16, $18, $1A, $1C, $1E    ; $C8
.byte $20, $22, $24, $26, $28, $2A, $2C, $2E    ; $D0
.byte $30, $32, $34, $36, $38, $3A, $3C, $3E    ; $D8
.byte $40, $42, $44, $46, $48, $4A, $4C, $4E    ; $E0
.byte $50, $52, $54, $56, $58, $5A, $5C, $5E    ; $E8
.byte $60, $62, $64, $66, $68, $6A, $6C, $6E    ; $F0
.byte $70, $72, $74, $76, $78, $7A, $7C, $7E    ; $F8

halfShiftCarry:
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $00
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $08
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $10
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $18
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $20
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $28
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $30
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $38
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $40
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $48
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $50
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $58
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $60
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $68
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $70
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $78
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $80
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $88
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $90
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $98
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $A0
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $A8
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $B0
.byte $00, $00, $00, $00, $00, $00, $00, $00    ; $B8
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $C0
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $C8
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $D0
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $D8
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $E0
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $E8
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $F0
.byte $01, $01, $01, $01, $01, $01, $01, $01    ; $F8

