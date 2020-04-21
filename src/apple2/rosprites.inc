;-----------------------------------------------------------------------------
; rosprites.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "RODATA"

;-----------------------------------------------------------------------------
; The Willy sprites and the cheat-boot are stored in white, 2bpp since they are
; not re-instanced.  They are drawn from where they reside when loaded.
; To save memory, the other sprites are stored as 1 bpp.  The single bits
; get doubled in the instance, and the high bit is set in the bytes, before color
; is applied.  The method for bit doubling is not quite a double, but a lookup
; table is used.  The "bit" format the sprites are stored in works like this: Each
; byte is composed of 2 nibbles that will each become a 7 bit byte, and the msb
; will automatically be turned on. Assume the nibbles are: abcd efgh then the
; "decompression" will make 2 bytes that will have the format 1abbccdd 1eeffggh.
; a and h together form the "split" pixel, 1 is the msb that's turned on and
; bcdefg are doubled through the 16 byte lookup table named binDouble.
sprites:
sprite00:
.byte $00, $1E, $00, $00                        ; ---------XXXX--------------- = --------XXXX----------------
.byte $70, $1F, $00, $00                        ; XXX------XXXXX-------------- = ----XXXXXXXX----------------
.byte $7C, $07, $00, $00                        ; XXXXX------XXX-------------- = --XXXXXXXX------------------
.byte $30, $06, $00, $00                        ; -XX--------XX--------------- = ----XX--XX------------------
.byte $70, $1F, $00, $00                        ; XXX------XXXXX-------------- = ----XXXXXXXX----------------
.byte $70, $07, $00, $00                        ; XXX--------XXX-------------- = ----XXXXXX------------------
.byte $40, $01, $00, $00                        ; X------------X-------------- = ------XX--------------------
.byte $70, $07, $00, $00                        ; XXX--------XXX-------------- = ----XXXXXX------------------
.byte $7C, $1F, $00, $00                        ; XXXXX----XXXXX-------------- = --XXXXXXXXXX----------------
.byte $7C, $1F, $00, $00                        ; XXXXX----XXXXX-------------- = --XXXXXXXXXX----------------
.byte $3F, $7E, $00, $00                        ; -XXXXXXXXXXXX--------------- = XXXXXX--XXXXXX--------------
.byte $7F, $79, $00, $00                        ; XXXXXXXXXXX--X-------------- = XXXXXXXX--XXXX--------------
.byte $70, $07, $00, $00                        ; XXX--------XXX-------------- = ----XXXXXX------------------
.byte $3C, $1E, $00, $00                        ; -XXXX----XXXX--------------- = --XXXX--XXXX----------------
.byte $7C, $1F, $00, $00                        ; XXXXX----XXXXX-------------- = --XXXXXXXXXX----------------
.byte $3C, $7E, $00, $00                        ; -XXXX--XXXXXX--------------- = --XXXX--XXXXXX--------------

sprite01:
.byte $00, $60, $03, $00                        ; -------XX----------XX------- = ------------XXXX------------
.byte $00, $7E, $03, $00                        ; -------XXXXXX------XX------- = --------XXXXXXXX------------
.byte $40, $7F, $00, $00                        ; X------XXXXXXX-------------- = ------XXXXXXXX--------------
.byte $00, $66, $00, $00                        ; -------XX--XX--------------- = --------XX--XX--------------
.byte $00, $7E, $03, $00                        ; -------XXXXXX------XX------- = --------XXXXXXXX------------
.byte $00, $7E, $00, $00                        ; -------XXXXXX--------------- = --------XXXXXX--------------
.byte $00, $18, $00, $00                        ; ---------XX----------------- = ----------XX----------------
.byte $00, $7E, $00, $00                        ; -------XXXXXX--------------- = --------XXXXXX--------------
.byte $40, $67, $03, $00                        ; X------XX--XXX-----XX------- = ------XXXX--XXXX------------
.byte $40, $67, $03, $00                        ; X------XX--XXX-----XX------- = ------XXXX--XXXX------------
.byte $40, $67, $03, $00                        ; X------XX--XXX-----XX------- = ------XXXX--XXXX------------
.byte $40, $7F, $03, $00                        ; X------XXXXXXX-----XX------- = ------XXXXXXXXXX------------
.byte $00, $7E, $00, $00                        ; -------XXXXXX--------------- = --------XXXXXX--------------
.byte $00, $18, $00, $00                        ; ---------XX----------------- = ----------XX----------------
.byte $00, $18, $00, $00                        ; ---------XX----------------- = ----------XX----------------
.byte $00, $78, $00, $00                        ; -------XXXX----------------- = ----------XXXX--------------


sprite02:
.byte $00, $00, $3C, $00                        ; ---------------XXXX--------- = ----------------XXXX--------
.byte $00, $60, $3F, $00                        ; -------XX------XXXXXX------- = ------------XXXXXXXX--------
.byte $00, $78, $0F, $00                        ; -------XXXX------XXXX------- = ----------XXXXXXXX----------
.byte $00, $60, $0C, $00                        ; -------XX--------XX--------- = ------------XX--XX----------
.byte $00, $60, $3F, $00                        ; -------XX------XXXXXX------- = ------------XXXXXXXX--------
.byte $00, $60, $0F, $00                        ; -------XX--------XXXX------- = ------------XXXXXX----------
.byte $00, $00, $03, $00                        ; -------------------XX------- = --------------XX------------
.byte $00, $60, $0F, $00                        ; -------XX--------XXXX------- = ------------XXXXXX----------
.byte $00, $78, $3F, $00                        ; -------XXXX----XXXXXX------- = ----------XXXXXXXXXX--------
.byte $00, $78, $3F, $00                        ; -------XXXX----XXXXXX------- = ----------XXXXXXXXXX--------
.byte $00, $7E, $7C, $01                        ; -------XXXXXX-XXXXX--------X = --------XXXXXX--XXXXXX------
.byte $00, $7E, $73, $01                        ; -------XXXXXX-XXX--XX------X = --------XXXXXXXX--XXXX------
.byte $00, $60, $0F, $00                        ; -------XX--------XXXX------- = ------------XXXXXX----------
.byte $00, $78, $3C, $00                        ; -------XXXX----XXXX--------- = ----------XXXX--XXXX--------
.byte $00, $18, $3F, $00                        ; ---------XX----XXXXXX------- = ----------XX--XXXXXX--------
.byte $00, $78, $7C, $01                        ; -------XXXX---XXXXX--------X = ----------XXXX--XXXXXX------

sprite03:
.byte $00, $00, $40, $07                        ; --------------X----------XXX = --------------------XXXX----
.byte $00, $00, $7C, $07                        ; --------------XXXXX------XXX = ----------------XXXXXXXX----
.byte $00, $00, $7F, $01                        ; --------------XXXXXXX------X = --------------XXXXXXXX------
.byte $00, $00, $4C, $01                        ; --------------X--XX--------X = ----------------XX--XX------
.byte $00, $00, $7C, $07                        ; --------------XXXXX------XXX = ----------------XXXXXXXX----
.byte $00, $00, $7C, $01                        ; --------------XXXXX--------X = ----------------XXXXXX------
.byte $00, $00, $30, $00                        ; ---------------XX----------- = ------------------XX--------
.byte $00, $00, $7C, $01                        ; --------------XXXXX--------X = ----------------XXXXXX------
.byte $00, $00, $7F, $07                        ; --------------XXXXXXX----XXX = --------------XXXXXXXXXX----
.byte $00, $60, $7F, $1F                        ; -------XX-----XXXXXXX--XXXXX = ------------XXXXXXXXXXXXXX--
.byte $00, $78, $7F, $7F                        ; -------XXXX---XXXXXXXXXXXXXX = ----------XXXXXXXXXXXXXXXXXX
.byte $00, $78, $7C, $79                        ; -------XXXX---XXXXX--XXXX--X = ----------XXXX--XXXXXX--XXXX
.byte $00, $00, $7C, $07                        ; --------------XXXXX------XXX = ----------------XXXXXXXX----
.byte $00, $00, $4F, $67                        ; --------------X--XXXXXX--XXX = --------------XXXX--XXXX--XX
.byte $00, $60, $03, $7E                        ; -------XX----------XXXXXXXX- = ------------XXXX------XXXXXX
.byte $00, $60, $0F, $18                        ; -------XX--------XXXX--XX--- = ------------XXXXXX------XX--

sprite04:
.byte $70, $01, $00, $00                        ; XXX----------X-------------- = ----XXXX--------------------
.byte $70, $1F, $00, $00                        ; XXX------XXXXX-------------- = ----XXXXXXXX----------------
.byte $40, $7F, $00, $00                        ; X------XXXXXXX-------------- = ------XXXXXXXX--------------
.byte $40, $19, $00, $00                        ; X--------XX--X-------------- = ------XX--XX----------------
.byte $70, $1F, $00, $00                        ; XXX------XXXXX-------------- = ----XXXXXXXX----------------
.byte $40, $1F, $00, $00                        ; X--------XXXXX-------------- = ------XXXXXX----------------
.byte $00, $06, $00, $00                        ; -----------XX--------------- = --------XX------------------
.byte $40, $1F, $00, $00                        ; X--------XXXXX-------------- = ------XXXXXX----------------
.byte $70, $7F, $00, $00                        ; XXX----XXXXXXX-------------- = ----XXXXXXXXXX--------------
.byte $7C, $7F, $03, $00                        ; XXXXX--XXXXXXX-----XX------- = --XXXXXXXXXXXXXX------------
.byte $7F, $7F, $0F, $00                        ; XXXXXXXXXXXXXX---XXXX------- = XXXXXXXXXXXXXXXXXX----------
.byte $4F, $1F, $0F, $00                        ; X--XXXX--XXXXX---XXXX------- = XXXX--XXXXXX--XXXX----------
.byte $70, $1F, $00, $00                        ; XXX------XXXXX-------------- = ----XXXXXXXX----------------
.byte $73, $79, $00, $00                        ; XXX--XXXXXX--X-------------- = XX--XXXX--XXXX--------------
.byte $3F, $60, $03, $00                        ; -XXXXXXXX----------XX------- = XXXXXX------XXXX------------
.byte $0C, $78, $03, $00                        ; ---XX--XXXX--------XX------- = --XX------XXXXXX------------

sprite05:
.byte $00, $1E, $00, $00                        ; ---------XXXX--------------- = --------XXXX----------------
.byte $00, $7E, $03, $00                        ; -------XXXXXX------XX------- = --------XXXXXXXX------------
.byte $00, $78, $0F, $00                        ; -------XXXX------XXXX------- = ----------XXXXXXXX----------
.byte $00, $18, $03, $00                        ; ---------XX--------XX------- = ----------XX--XX------------
.byte $00, $7E, $03, $00                        ; -------XXXXXX------XX------- = --------XXXXXXXX------------
.byte $00, $78, $03, $00                        ; -------XXXX--------XX------- = ----------XXXXXX------------
.byte $00, $60, $00, $00                        ; -------XX------------------- = ------------XX--------------
.byte $00, $78, $03, $00                        ; -------XXXX--------XX------- = ----------XXXXXX------------
.byte $00, $7E, $0F, $00                        ; -------XXXXXX----XXXX------- = --------XXXXXXXXXX----------
.byte $00, $7E, $0F, $00                        ; -------XXXXXX----XXXX------- = --------XXXXXXXXXX----------
.byte $40, $1F, $3F, $00                        ; X--------XXXXX-XXXXXX------- = ------XXXXXX--XXXXXX--------
.byte $40, $67, $3F, $00                        ; X------XX--XXX-XXXXXX------- = ------XXXX--XXXXXXXX--------
.byte $00, $78, $03, $00                        ; -------XXXX--------XX------- = ----------XXXXXX------------
.byte $00, $1E, $0F, $00                        ; ---------XXXX----XXXX------- = --------XXXX--XXXX----------
.byte $00, $7E, $0C, $00                        ; -------XXXXXX----XX--------- = --------XXXXXX--XX----------
.byte $40, $1F, $0F, $00                        ; X--------XXXXX---XXXX------- = ------XXXXXX--XXXX----------

sprite06:
.byte $00, $60, $03, $00                        ; -------XX----------XX------- = ------------XXXX------------
.byte $00, $60, $3F, $00                        ; -------XX------XXXXXX------- = ------------XXXXXXXX--------
.byte $00, $00, $7F, $01                        ; --------------XXXXXXX------X = --------------XXXXXXXX------
.byte $00, $00, $33, $00                        ; ---------------XX--XX------- = --------------XX--XX--------
.byte $00, $60, $3F, $00                        ; -------XX------XXXXXX------- = ------------XXXXXXXX--------
.byte $00, $00, $3F, $00                        ; ---------------XXXXXX------- = --------------XXXXXX--------
.byte $00, $00, $0C, $00                        ; -----------------XX--------- = ----------------XX----------
.byte $00, $00, $3F, $00                        ; ---------------XXXXXX------- = --------------XXXXXX--------
.byte $00, $60, $7F, $01                        ; -------XX-----XXXXXXX------X = ------------XXXXXXXXXX------
.byte $00, $60, $73, $01                        ; -------XX-----XXX--XX------X = ------------XXXX--XXXX------
.byte $00, $60, $73, $01                        ; -------XX-----XXX--XX------X = ------------XXXX--XXXX------
.byte $00, $60, $73, $01                        ; -------XX-----XXX--XX------X = ------------XXXX--XXXX------
.byte $00, $00, $3F, $00                        ; ---------------XXXXXX------- = --------------XXXXXX--------
.byte $00, $00, $0C, $00                        ; -----------------XX--------- = ----------------XX----------
.byte $00, $00, $0C, $00                        ; -----------------XX--------- = ----------------XX----------
.byte $00, $00, $0F, $00                        ; -----------------XXXX------- = --------------XXXX----------

sprite07:
.byte $00, $00, $3C, $00                        ; ---------------XXXX--------- = ----------------XXXX--------
.byte $00, $00, $7C, $07                        ; --------------XXXXX------XXX = ----------------XXXXXXXX----
.byte $00, $00, $70, $1F                        ; --------------XXX------XXXXX = ------------------XXXXXXXX--
.byte $00, $00, $30, $06                        ; ---------------XX--------XX- = ------------------XX--XX----
.byte $00, $00, $7C, $07                        ; --------------XXXXX------XXX = ----------------XXXXXXXX----
.byte $00, $00, $70, $07                        ; --------------XXX--------XXX = ------------------XXXXXX----
.byte $00, $00, $40, $01                        ; --------------X------------X = --------------------XX------
.byte $00, $00, $70, $07                        ; --------------XXX--------XXX = ------------------XXXXXX----
.byte $00, $00, $7C, $1F                        ; --------------XXXXX----XXXXX = ----------------XXXXXXXXXX--
.byte $00, $00, $7C, $1F                        ; --------------XXXXX----XXXXX = ----------------XXXXXXXXXX--
.byte $00, $00, $3F, $7E                        ; ---------------XXXXXXXXXXXX- = --------------XXXXXX--XXXXXX
.byte $00, $00, $4F, $7F                        ; --------------X--XXXXXXXXXXX = --------------XXXX--XXXXXXXX
.byte $00, $00, $70, $07                        ; --------------XXX--------XXX = ------------------XXXXXX----
.byte $00, $00, $3C, $1E                        ; ---------------XXXX----XXXX- = ----------------XXXX--XXXX--
.byte $00, $00, $7C, $19                        ; --------------XXXXX----XX--X = ----------------XXXXXX--XX--
.byte $00, $00, $3F, $1E                        ; ---------------XXXXXX--XXXX- = --------------XXXXXX--XXXX--

sprite08:
.byte $8F, $91                                  ; X---XXXXX--X---X = ------XXXXXXXXXX----XX------
.byte $C3, $F1                                  ; XX----XXXXXX---X = ----XXXXXX----XXXXXXXX------
.byte $83, $F1                                  ; X-----XXXXXX---X = ------XXXX----XXXXXXXX------
.byte $0E, $91                                  ; ----XXX-X--X---X = --------XXXXXXXX----XX------
.byte $9F, $10                                  ; X--XXXXX---X---- = XX----XXXXXXXXXX------------
.byte $AF, $30                                  ; X-X-XXXX--XX---- = --XX--XXXXXXXXXXXX----------
.byte $FF, $70                                  ; XXXXXXXX-XXX---- = XXXXXXXXXXXXXXXXXXXX--------
.byte $AF, $00                                  ; X-X-XXXX-------- = --XX--XXXXXXXX--------------
.byte $9F, $70                                  ; X--XXXXX-XXX---- = XX----XXXXXXXXXXXXXX--------
.byte $8F, $30                                  ; X---XXXX--XX---- = ------XXXXXXXXXXXX----------
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------
.byte $DB, $B1                                  ; XX-XX-XXX-XX---X = XX--XXXXXX--XXXXXX--XX------
.byte $E1, $70                                  ; XXX----X-XXX---- = --XXXXXX------XXXXXX--------
.byte $40, $20                                  ; -X--------X----- = ----XX----------XX----------
.byte $81, $10                                  ; X------X---X---- = ------XX------XX------------

sprite09:
.byte $0E, $34                                  ; ----XXX---XX-X-- = --------XXXXXXXXXX------XX--
.byte $87, $E7                                  ; X----XXXXXX--XXX = ------XXXXXX----XXXXXXXXXX--
.byte $06, $E7                                  ; -----XX-XXX--XXX = --------XXXX----XXXXXXXXXX--
.byte $2C, $34                                  ; --X-XX----XX-X-- = --XX------XXXXXXXX------XX--
.byte $4E, $30                                  ; -X--XXX---XX---- = ----XX--XXXXXXXXXX----------
.byte $4E, $70                                  ; -X--XXX--XXX---- = ----XX--XXXXXXXXXXXX--------
.byte $EF, $F1                                  ; XXX-XXXXXXXX---X = --XXXXXXXXXXXXXXXXXXXX------
.byte $4E, $F1                                  ; -X--XXX-XXXX---X = ----XX--XXXXXXXXXXXXXX------
.byte $4E, $F1                                  ; -X--XXX-XXXX---X = ----XX--XXXXXXXXXXXXXX------
.byte $2E, $70                                  ; --X-XXX--XXX---- = --XX----XXXXXXXXXXXX--------
.byte $0C, $10                                  ; ----XX-----X---- = ----------XXXXXX------------
.byte $0C, $10                                  ; ----XX-----X---- = ----------XXXXXX------------
.byte $06, $30                                  ; -----XX---XX---- = --------XXXX--XXXX----------
.byte $06, $30                                  ; -----XX---XX---- = --------XXXX--XXXX----------
.byte $C3, $E1                                  ; XX----XXXXX----X = ----XXXXXX------XXXXXX------
.byte $06, $30                                  ; -----XX---XX---- = --------XXXX--XXXX----------

sprite0A:
.byte $08, $F9                                  ; ----X---XXXXX--X = ------------XXXXXXXXXX----XX
.byte $0C, $9F                                  ; ----XX--X--XXXXX = ----------XXXXXX----XXXXXXXX
.byte $08, $9F                                  ; ----X---X--XXXXX = ------------XXXX----XXXXXXXX
.byte $00, $F9                                  ; --------XXXXX--X = --------------XXXXXXXX----XX
.byte $89, $F1                                  ; X---X--XXXXX---X = ------XX----XXXXXXXXXX------
.byte $0A, $F3                                  ; ----X-X-XXXX--XX = --------XX--XXXXXXXXXXXX----
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $0A, $70                                  ; ----X-X--XXX---- = --------XX--XXXXXXXX--------
.byte $89, $F7                                  ; X---X--XXXXX-XXX = ------XX----XXXXXXXXXXXXXX--
.byte $08, $F3                                  ; ----X---XXXX--XX = ------------XXXXXXXXXXXX----
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------

sprite0B:
.byte $00, $FB                                  ; --------XXXXX-XX = --------------XXXXXXXXXX--XX
.byte $08, $3E                                  ; ----X-----XXXXX- = ------------XXXXXX----XXXXXX
.byte $00, $3E                                  ; ----------XXXXX- = --------------XXXX----XXXXXX
.byte $00, $EB                                  ; --------XXX-X-XX = ----------------XXXXXXXX--XX
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $00, $FF                                  ; --------XXXXXXXX = --------------XXXXXXXXXXXXXX
.byte $0E, $F3                                  ; ----XXX-XXXX--XX = --------XXXXXXXXXXXXXXXX----
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $00, $FF                                  ; --------XXXXXXXX = --------------XXXXXXXXXXXXXX
.byte $00, $E1                                  ; --------XXX----X = ----------------XXXXXX------
.byte $00, $E1                                  ; --------XXX----X = ----------------XXXXXX------
.byte $00, $B3                                  ; --------X-XX--XX = --------------XXXX--XXXX----
.byte $00, $B3                                  ; --------X-XX--XX = --------------XXXX--XXXX----
.byte $0C, $1E                                  ; ----XX-----XXXX- = ----------XXXXXX------XXXXXX
.byte $00, $B3                                  ; --------X-XX--XX = --------------XXXX--XXXX----

sprite0C:
.byte $DF, $00                                  ; XX-XXXXX-------- = XX--XXXXXXXXXX--------------
.byte $7C, $10                                  ; -XXXXX-----X---- = XXXXXX----XXXXXX------------
.byte $7C, $00                                  ; -XXXXX---------- = XXXXXX----XXXX--------------
.byte $D7, $00                                  ; XX-X-XXX-------- = XX--XXXXXXXX----------------
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $FF, $00                                  ; XXXXXXXX-------- = XXXXXXXXXXXXXX--------------
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $8F, $00                                  ; X---XXXX-------- = ------XXXXXXXX--------------
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $FF, $00                                  ; XXXXXXXX-------- = XXXXXXXXXXXXXX--------------
.byte $87, $00                                  ; X----XXX-------- = ------XXXXXX----------------
.byte $87, $00                                  ; X----XXX-------- = ------XXXXXX----------------
.byte $CD, $00                                  ; XX--XX-X-------- = ----XXXX--XXXX--------------
.byte $CD, $00                                  ; XX--XX-X-------- = ----XXXX--XXXX--------------
.byte $78, $30                                  ; -XXXX-----XX---- = XXXXXX------XXXXXX----------
.byte $CD, $00                                  ; XX--XX-X-------- = ----XXXX--XXXX--------------

sprite0D:
.byte $9F, $10                                  ; X--XXXXX---X---- = XX----XXXXXXXXXX------------
.byte $F9, $30                                  ; XXXXX--X--XX---- = XXXXXXXX----XXXXXX----------
.byte $F9, $10                                  ; XXXXX--X---X---- = XXXXXXXX----XXXX------------
.byte $9F, $00                                  ; X--XXXXX-------- = XX----XXXXXXXX--------------
.byte $8F, $91                                  ; X---XXXXX--X---X = ------XXXXXXXXXX----XX------
.byte $CF, $50                                  ; XX--XXXX-X-X---- = ----XXXXXXXXXXXX--XX--------
.byte $EF, $F1                                  ; XXX-XXXXXXXX---X = --XXXXXXXXXXXXXXXXXXXX------
.byte $0E, $50                                  ; ----XXX--X-X---- = --------XXXXXXXX--XX--------
.byte $EF, $91                                  ; XXX-XXXXX--X---X = --XXXXXXXXXXXXXX----XX------
.byte $CF, $10                                  ; XX--XXXX---X---- = ----XXXXXXXXXXXX------------
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------

sprite0E:
.byte $2C, $70                                  ; --X-XX---XXX---- = --XX------XXXXXXXXXX--------
.byte $E7, $E1                                  ; XXX--XXXXXX----X = --XXXXXXXXXX----XXXXXX------
.byte $E7, $60                                  ; XXX--XXX-XX----- = --XXXXXXXXXX----XXXX--------
.byte $2C, $34                                  ; --X-XX----XX-X-- = --XX------XXXXXXXX------XX--
.byte $0C, $72                                  ; ----XX---XXX--X- = ----------XXXXXXXXXX--XX----
.byte $0E, $72                                  ; ----XXX--XXX--X- = --------XXXXXXXXXXXX--XX----
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $8F, $72                                  ; X---XXXX-XXX--X- = ------XXXXXXXXXXXXXX--XX----
.byte $8F, $72                                  ; X---XXXX-XXX--X- = ------XXXXXXXXXXXXXX--XX----
.byte $0E, $74                                  ; ----XXX--XXX-X-- = --------XXXXXXXXXXXX----XX--
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $0C, $60                                  ; ----XX---XX----- = ----------XXXX--XXXX--------
.byte $0C, $60                                  ; ----XX---XX----- = ----------XXXX--XXXX--------
.byte $87, $C3                                  ; X----XXXXX----XX = ------XXXXXX------XXXXXX----
.byte $0C, $60                                  ; ----XX---XX----- = ----------XXXX--XXXX--------

sprite0F:
.byte $89, $F1                                  ; X---X--XXXXX---X = ------XX----XXXXXXXXXX------
.byte $8F, $C3                                  ; X---XXXXXX----XX = ------XXXXXXXX----XXXXXX----
.byte $8F, $C1                                  ; X---XXXXXX-----X = ------XXXXXXXX----XXXX------
.byte $89, $70                                  ; X---X--X-XXX---- = ------XX----XXXXXXXX--------
.byte $08, $F9                                  ; ----X---XXXXX--X = ------------XXXXXXXXXX----XX
.byte $0C, $F5                                  ; ----XX--XXXX-X-X = ----------XXXXXXXXXXXX--XX--
.byte $0E, $FF                                  ; ----XXX-XXXXXXXX = --------XXXXXXXXXXXXXXXXXXXX
.byte $00, $F5                                  ; --------XXXX-X-X = --------------XXXXXXXX--XX--
.byte $0E, $F9                                  ; ----XXX-XXXXX--X = --------XXXXXXXXXXXXXX----XX
.byte $0C, $F1                                  ; ----XX--XXXX---X = ----------XXXXXXXXXXXX------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $8D, $DB                                  ; X---XX-XXX-XX-XX = ------XX--XXXXXX--XXXXXX--XX
.byte $0E, $87                                  ; ----XXX-X----XXX = --------XXXXXX------XXXXXX--
.byte $04, $02                                  ; -----X--------X- = ----------XX----------XX----
.byte $08, $81                                  ; ----X---X------X = ------------XX------XX------

sprite10:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $E9, $97                                  ; XX-X--X--X-XXX = --XXXXXX----XXXX----XXXXXX--
.byte $1A, $58                                  ; --XX-X-X-XX--- = XX------XX--XXXX--XX------XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $2A, $54                                  ; -X-X-X-X-X-X-- = --XX----XX--XXXX--XX----XX--
.byte $89, $91                                  ; ---X--X--X---X = ------XX----XXXX----XX------
.byte $48, $12                                  ; X--X-----X--X- = ----XX------XXXX------XX----
.byte $4A, $52                                  ; X--X-X-X-X--X- = ----XX--XX--XXXX--XX--XX----
.byte $4A, $52                                  ; X--X-X-X-X--X- = ----XX--XX--XXXX--XX--XX----
.byte $4A, $52                                  ; X--X-X-X-X--X- = ----XX--XX--XXXX--XX--XX----
.byte $4A, $52                                  ; X--X-X-X-X--X- = ----XX--XX--XXXX--XX--XX----
.byte $4A, $52                                  ; X--X-X-X-X--X- = ----XX--XX--XXXX--XX--XX----
.byte $4A, $52                                  ; X--X-X-X-X--X- = ----XX--XX--XXXX--XX--XX----
.byte $4A, $52                                  ; X--X-X-X-X--X- = ----XX--XX--XXXX--XX--XX----
.byte $4A, $52                                  ; X--X-X-X-X--X- = ----XX--XX--XXXX--XX--XX----
.byte $4A, $52                                  ; X--X-X-X-X--X- = ----XX--XX--XXXX--XX--XX----

sprite11:
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $8F, $00                                  ; X---XXXX-------- = ------XXXXXXXX--------------
.byte $8B, $10                                  ; X---X-XX---X---- = ------XXXX--XXXX------------
.byte $8F, $60                                  ; X---XXXX-XX----- = ------XXXXXXXX--XXXX--------
.byte $C3, $10                                  ; XX----XX---X---- = ----XXXXXX----XX------------
.byte $C9, $00                                  ; XX--X--X-------- = ----XXXX----XX--------------
.byte $CB, $00                                  ; XX--X-XX-------- = ----XXXXXX--XX--------------
.byte $C7, $10                                  ; XX---XXX---X---- = ----XXXXXXXX--XX------------
.byte $66, $10                                  ; -XX--XX----X---- = --XXXX--XXXX--XX------------
.byte $62, $10                                  ; -XX---X----X---- = --XXXX--XX----XX------------
.byte $62, $10                                  ; -XX---X----X---- = --XXXX--XX----XX------------
.byte $60, $10                                  ; -XX--------X---- = --XXXX--------XX------------
.byte $E1, $10                                  ; XXX----X---X---- = --XXXXXX------XX------------
.byte $DF, $00                                  ; XX-XXXXX-------- = XX--XXXXXXXXXX--------------
.byte $02, $00                                  ; ------X--------- = --------XX------------------
.byte $8F, $00                                  ; X---XXXX-------- = ------XXXXXXXX--------------

sprite12:
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $0C, $60                                  ; ----XX---XX----- = ----------XXXX--XXXX--------
.byte $0C, $B3                                  ; ----XX--X-XX--XX = ----------XXXXXXXX--XXXX----
.byte $0E, $40                                  ; ----XXX--X------ = --------XXXXXX----XX--------
.byte $06, $20                                  ; -----XX---X----- = --------XXXX----XX----------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $06, $70                                  ; -----XX--XXX---- = --------XXXX--XXXXXX--------
.byte $8B, $50                                  ; X---X-XX-X-X---- = ------XXXX--XXXX--XX--------
.byte $8B, $50                                  ; X---X-XX-X-X---- = ------XXXX--XXXX--XX--------
.byte $8D, $40                                  ; X---XX-X-X------ = ------XX--XXXX----XX--------
.byte $83, $40                                  ; X-----XX-X------ = ------XXXX--------XX--------
.byte $87, $40                                  ; X----XXX-X------ = ------XXXXXX------XX--------
.byte $4E, $30                                  ; -X--XXX---XX---- = ----XX--XXXXXXXXXX----------
.byte $04, $50                                  ; -----X---X-X---- = ----------XX--XX--XX--------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------

sprite13:
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $08, $D1                                  ; ----X---XX-X---X = ------------XXXX--XXXX------
.byte $08, $76                                  ; ----X----XXX-XX- = ------------XXXXXXXX--XXXX--
.byte $0C, $91                                  ; ----XX--X--X---X = ----------XXXXXX----XX------
.byte $0C, $40                                  ; ----XX---X------ = ----------XXXX----XX--------
.byte $0C, $50                                  ; ----XX---X-X---- = ----------XXXXXX--XX--------
.byte $0C, $B1                                  ; ----XX--X-XX---X = ----------XXXXXXXX--XX------
.byte $06, $B1                                  ; -----XX-X-XX---X = --------XXXX--XXXX--XX------
.byte $06, $91                                  ; -----XX-X--X---X = --------XXXX--XX----XX------
.byte $06, $91                                  ; -----XX-X--X---X = --------XXXX--XX----XX------
.byte $06, $81                                  ; -----XX-X------X = --------XXXX--------XX------
.byte $0E, $81                                  ; ----XXX-X------X = --------XXXXXX------XX------
.byte $8D, $72                                  ; X---XX-X-XXX--X- = ------XX--XXXXXXXXXX--XX----
.byte $04, $A1                                  ; -----X--X-X----X = ----------XX----XX--XX------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------

sprite14:
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $00, $B3                                  ; --------X-XX--XX = --------------XXXX--XXXX----
.byte $00, $FD                                  ; --------XXXXXX-X = --------------XXXXXXXX--XXXX
.byte $08, $32                                  ; ----X-----XX--X- = ------------XXXXXX----XX----
.byte $08, $91                                  ; ----X---X--X---X = ------------XXXX----XX------
.byte $08, $B1                                  ; ----X---X-XX---X = ------------XXXXXX--XX------
.byte $08, $72                                  ; ----X----XXX--X- = ------------XXXXXXXX--XX----
.byte $0C, $62                                  ; ----XX---XX---X- = ----------XXXX--XXXX--XX----
.byte $0C, $42                                  ; ----XX---X----X- = ----------XXXX----XX--XX----
.byte $0C, $42                                  ; ----XX---X----X- = ----------XXXX----XX--XX----
.byte $0C, $02                                  ; ----XX--------X- = ----------XXXX--------XX----
.byte $0C, $12                                  ; ----XX-----X--X- = ----------XXXXXX------XX----
.byte $0A, $F1                                  ; ----X-X-XXXX---X = --------XX--XXXXXXXXXX------
.byte $00, $52                                  ; ---------X-X--X- = --------------XX--XX--XX----
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------

sprite15:
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $8F, $00                                  ; X---XXXX-------- = ------XXXXXXXX--------------
.byte $CD, $00                                  ; XX--XX-X-------- = ----XXXX--XXXX--------------
.byte $BF, $00                                  ; X-XXXXXX-------- = XXXX--XXXXXXXX--------------
.byte $4C, $10                                  ; -X--XX-----X---- = ----XX----XXXXXX------------
.byte $89, $10                                  ; X---X--X---X---- = ------XX----XXXX------------
.byte $8D, $10                                  ; X---XX-X---X---- = ------XX--XXXXXX------------
.byte $4E, $10                                  ; -X--XXX----X---- = ----XX--XXXXXXXX------------
.byte $46, $30                                  ; -X---XX---XX---- = ----XX--XXXX--XXXX----------
.byte $42, $30                                  ; -X----X---XX---- = ----XX--XX----XXXX----------
.byte $42, $30                                  ; -X----X---XX---- = ----XX--XX----XXXX----------
.byte $40, $30                                  ; -X--------XX---- = ----XX--------XXXX----------
.byte $48, $30                                  ; -X--X-----XX---- = ----XX------XXXXXX----------
.byte $8F, $50                                  ; X---XXXX-X-X---- = ------XXXXXXXXXX--XX--------
.byte $4A, $00                                  ; -X--X-X--------- = ----XX--XX--XX--------------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------

sprite16:
.byte $0C, $00                                  ; ----XX---------- = ----------XXXX--------------
.byte $0E, $10                                  ; ----XXX----X---- = --------XXXXXXXX------------
.byte $8B, $10                                  ; X---X-XX---X---- = ------XXXX--XXXX------------
.byte $6E, $10                                  ; -XX-XXX----X---- = --XXXX--XXXXXXXX------------
.byte $89, $30                                  ; X---X--X--XX---- = ------XX----XXXXXX----------
.byte $02, $30                                  ; ------X---XX---- = --------XX----XXXX----------
.byte $0A, $30                                  ; ----X-X---XX---- = --------XX--XXXXXX----------
.byte $8D, $30                                  ; X---XX-X--XX---- = ------XX--XXXXXXXX----------
.byte $8D, $60                                  ; X---XX-X-XX----- = ------XX--XXXX--XXXX--------
.byte $89, $60                                  ; X---X--X-XX----- = ------XX----XX--XXXX--------
.byte $89, $60                                  ; X---X--X-XX----- = ------XX----XX--XXXX--------
.byte $81, $60                                  ; X------X-XX----- = ------XX--------XXXX--------
.byte $81, $70                                  ; X------X-XXX---- = ------XX------XXXXXX--------
.byte $4E, $B1                                  ; -X--XXX-X-XX---X = ----XX--XXXXXXXXXX--XX------
.byte $85, $20                                  ; X----X-X--X----- = ------XX--XX----XX----------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------

sprite17:
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $06, $30                                  ; -----XX---XX---- = --------XXXX--XXXX----------
.byte $CD, $30                                  ; XX--XX-X--XX---- = ----XXXX--XXXXXXXX----------
.byte $02, $70                                  ; ------X--XXX---- = --------XX----XXXXXX--------
.byte $04, $60                                  ; -----X---XX----- = ----------XX----XXXX--------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $0E, $60                                  ; ----XXX--XX----- = --------XXXXXX--XXXX--------
.byte $0A, $D1                                  ; ----X-X-XX-X---X = --------XX--XXXX--XXXX------
.byte $0A, $D1                                  ; ----X-X-XX-X---X = --------XX--XXXX--XXXX------
.byte $02, $B1                                  ; ------X-X-XX---X = --------XX----XXXX--XX------
.byte $02, $C1                                  ; ------X-XX-----X = --------XX--------XXXX------
.byte $02, $E1                                  ; ------X-XXX----X = --------XX------XXXXXX------
.byte $0C, $72                                  ; ----XX---XXX--X- = ----------XXXXXXXXXX--XX----
.byte $0A, $20                                  ; ----X-X---X----- = --------XX--XX--XX----------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------

sprite18:
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $08, $D1                                  ; ----X---XX-X---X = ------------XXXX--XXXX------
.byte $06, $F1                                  ; -----XX-XXXX---X = --------XXXX--XXXXXXXX------
.byte $08, $C3                                  ; ----X---XX----XX = ------------XX----XXXXXX----
.byte $00, $93                                  ; --------X--X--XX = --------------XX----XXXX----
.byte $00, $D3                                  ; --------XX-X--XX = --------------XX--XXXXXX----
.byte $08, $E3                                  ; ----X---XXX---XX = ------------XX--XXXXXXXX----
.byte $08, $66                                  ; ----X----XX--XX- = ------------XX--XXXX--XXXX--
.byte $08, $46                                  ; ----X----X---XX- = ------------XX----XX--XXXX--
.byte $08, $46                                  ; ----X----X---XX- = ------------XX----XX--XXXX--
.byte $08, $06                                  ; ----X--------XX- = ------------XX--------XXXX--
.byte $08, $87                                  ; ----X---X----XXX = ------------XX------XXXXXX--
.byte $00, $FB                                  ; --------XXXXX-XX = --------------XXXXXXXXXX--XX
.byte $00, $40                                  ; ---------X------ = ------------------XX--------
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------

sprite19:
.byte $4A, $60                                  ; -X--X-X--XX----- = ----XX--XX--XX--XXXX--------
.byte $C5, $50                                  ; XX---X-X-X-X---- = ----XXXX--XX--XX--XX--------
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $8F, $00                                  ; X---XXXX-------- = ------XXXXXXXX--------------
.byte $89, $00                                  ; X---X--X-------- = ------XX----XX--------------
.byte $89, $00                                  ; X---X--X-------- = ------XX----XX--------------
.byte $89, $00                                  ; X---X--X-------- = ------XX----XX--------------
.byte $44, $10                                  ; -X---X-----X---- = ----XX----XX--XX------------
.byte $48, $E1                                  ; -X--X---XXX----X = ----XX------XX--XXXXXX------
.byte $A3, $22                                  ; X-X---XX--X---X- = --XX--XXXX------XX----XX----
.byte $24, $14                                  ; --X--X-----X-X-- = --XX------XX--XX--------XX--
.byte $24, $04                                  ; --X--X-------X-- = --XX------XX------------XX--
.byte $24, $04                                  ; --X--X-------X-- = --XX------XX------------XX--
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

sprite1A:
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $0C, $20                                  ; ----XX----X----- = ----------XXXX--XX----------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $DF, $60                                  ; XX-XXXXX-XX----- = XX--XXXXXXXXXX--XXXX--------
.byte $78, $30                                  ; -XXXX-----XX---- = XXXXXX------XXXXXX----------
.byte $20, $10                                  ; --X--------X---- = --XX----------XX------------
.byte $5A, $10                                  ; -X-XX-X----X---- = XX--XX--XX--XXXX------------
.byte $EF, $10                                  ; XXX-XXXX---X---- = --XXXXXXXXXXXXXX------------
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $02, $00                                  ; ------X--------- = --------XX------------------
.byte $02, $00                                  ; ------X--------- = --------XX------------------
.byte $02, $00                                  ; ------X--------- = --------XX------------------
.byte $85, $00                                  ; X----X-X-------- = ------XX--XX----------------

sprite1B:
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $B1                                  ; --------X-XX---X = --------------XXXX--XX------
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $C1                                  ; --------XX-----X = ------------------XXXX------
.byte $00, $83                                  ; --------X-----XX = --------------------XXXX----
.byte $4E, $B3                                  ; -X--XXX-X-XX--XX = ----XX--XXXXXXXXXX--XXXX----
.byte $C3, $E1                                  ; XX----XXXXX----X = ----XXXXXX------XXXXXX------
.byte $83, $60                                  ; X-----XX-XX----- = ------XXXX------XXXX--------
.byte $C1, $60                                  ; XX-----X-XX----- = ----XXXX--------XXXX--------
.byte $85, $70                                  ; X----X-X-XXX---- = ------XX--XX--XXXXXX--------
.byte $0A, $20                                  ; ----X-X---X----- = --------XX--XX--XX----------
.byte $85, $10                                  ; X----X-X---X---- = ------XX--XX--XX------------
.byte $08, $00                                  ; ----X----------- = ------------XX--------------
.byte $04, $10                                  ; -----X-----X---- = ----------XX--XX------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite1C:
.byte $00, $C1                                  ; --------XX-----X = ------------------XXXX------
.byte $00, $62                                  ; ---------XX---X- = ----------------XXXX--XX----
.byte $00, $E7                                  ; --------XXX--XXX = ----------------XXXXXXXXXX--
.byte $00, $C1                                  ; --------XX-----X = ------------------XXXX------
.byte $00, $83                                  ; --------X-----XX = --------------------XXXX----
.byte $00, $06                                  ; -------------XX- = ----------------------XXXX--
.byte $8D, $76                                  ; X---XX-X-XXX-XX- = ------XX--XXXXXXXXXX--XXXX--
.byte $87, $C3                                  ; X----XXXXX----XX = ------XXXXXX------XXXXXX----
.byte $02, $81                                  ; ------X-X------X = --------XX----------XX------
.byte $85, $D1                                  ; X----X-XXX-X---X = ------XX--XX--XX--XXXX------
.byte $0E, $F1                                  ; ----XXX-XXXX---X = --------XXXXXXXXXXXXXX------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $00, $10                                  ; -----------X---- = --------------XX------------
.byte $08, $20                                  ; ----X-----X----- = ------------XX--XX----------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite1D:
.byte $00, $83                                  ; --------X-----XX = --------------------XXXX----
.byte $00, $C5                                  ; --------XX---X-X = ------------------XXXX--XX--
.byte $00, $CF                                  ; --------XX--XXXX = ------------------XXXXXXXXXX
.byte $08, $A3                                  ; ----X---X-X---XX = ------------XX--XX--XXXX----
.byte $04, $56                                  ; -----X---X-X-XX- = ----------XX--XX--XX--XXXX--
.byte $08, $AD                                  ; ----X---X-X-XX-X = ------------XX--XX--XX--XXXX
.byte $06, $DD                                  ; -----XX-XX-XXX-X = --------XXXX--XX--XXXX--XXXX
.byte $0E, $06                                  ; ----XXX------XX- = --------XXXXXX--------XXXX--
.byte $04, $83                                  ; -----X--X-----XX = ----------XX--------XXXX----
.byte $0E, $F3                                  ; ----XXX-XXXX--XX = --------XXXXXXXXXXXXXXXX----
.byte $0C, $F3                                  ; ----XX--XXXX--XX = ----------XXXXXXXXXXXXXX----
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $00, $20                                  ; ----------X----- = ----------------XX----------
.byte $00, $20                                  ; ----------X----- = ----------------XX----------
.byte $00, $50                                  ; ---------X-X---- = --------------XX--XX--------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite1E:
.byte $C1, $00                                  ; XX-----X-------- = ----XXXX--------------------
.byte $A3, $00                                  ; X-X---XX-------- = --XX--XXXX------------------
.byte $F3, $00                                  ; XXXX--XX-------- = XXXXXXXXXX------------------
.byte $C5, $10                                  ; XX---X-X---X---- = ----XXXX--XX--XX------------
.byte $6A, $20                                  ; -XX-X-X---X----- = --XXXX--XX--XX--XX----------
.byte $B5, $10                                  ; X-XX-X-X---X---- = XXXX--XX--XX--XX------------
.byte $BB, $60                                  ; X-XXX-XX-XX----- = XXXX--XXXX--XX--XXXX--------
.byte $60, $70                                  ; -XX------XXX---- = --XXXX--------XXXXXX--------
.byte $C1, $20                                  ; XX-----X--X----- = ----XXXX--------XX----------
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $CF, $30                                  ; XX--XXXX--XX---- = ----XXXXXXXXXXXXXX----------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------
.byte $04, $00                                  ; -----X---------- = ----------XX----------------
.byte $04, $00                                  ; -----X---------- = ----------XX----------------
.byte $0A, $00                                  ; ----X-X--------- = --------XX--XX--------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite1F:
.byte $83, $00                                  ; X-----XX-------- = ------XXXX------------------
.byte $46, $00                                  ; -X---XX--------- = ----XX--XXXX----------------
.byte $E7, $00                                  ; XXX--XXX-------- = --XXXXXXXXXX----------------
.byte $83, $00                                  ; X-----XX-------- = ------XXXX------------------
.byte $C1, $00                                  ; XX-----X-------- = ----XXXX--------------------
.byte $60, $00                                  ; -XX------------- = --XXXX----------------------
.byte $6E, $B1                                  ; -XX-XXX-X-XX---X = --XXXX--XXXXXXXXXX--XX------
.byte $C3, $E1                                  ; XX----XXXXX----X = ----XXXXXX------XXXXXX------
.byte $81, $40                                  ; X------X-X------ = ------XX----------XX--------
.byte $8B, $A1                                  ; X---X-XXX-X----X = ------XXXX--XX--XX--XX------
.byte $8F, $70                                  ; X---XXXX-XXX---- = ------XXXXXXXXXXXXXX--------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $08, $00                                  ; ----X----------- = ------------XX--------------
.byte $04, $10                                  ; -----X-----X---- = ----------XX--XX------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite20:
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $8D, $00                                  ; X---XX-X-------- = ------XX--XXXX--------------
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $83, $00                                  ; X-----XX-------- = ------XXXX------------------
.byte $C1, $00                                  ; XX-----X-------- = ----XXXX--------------------
.byte $CD, $72                                  ; XX--XX-X-XXX--X- = ----XXXX--XXXXXXXXXX--XX----
.byte $87, $C3                                  ; X----XXXXX----XX = ------XXXXXX------XXXXXX----
.byte $06, $C1                                  ; -----XX-XX-----X = --------XXXX------XXXX------
.byte $06, $83                                  ; -----XX-X-----XX = --------XXXX--------XXXX----
.byte $0E, $A1                                  ; ----XXX-X-X----X = --------XXXXXX--XX--XX------
.byte $04, $50                                  ; -----X---X-X---- = ----------XX--XX--XX--------
.byte $08, $A1                                  ; ----X---X-X----X = ------------XX--XX--XX------
.byte $00, $10                                  ; -----------X---- = --------------XX------------
.byte $08, $20                                  ; ----X-----X----- = ------------XX--XX----------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite21:
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $04, $30                                  ; -----X----XX---- = ----------XX--XXXX----------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $0C, $00                                  ; ----XX---------- = ----------XXXX--------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $FB                                  ; -----XX-XXXXX-XX = --------XXXX--XXXXXXXXXX--XX
.byte $0C, $1E                                  ; ----XX-----XXXX- = ----------XXXXXX------XXXXXX
.byte $08, $04                                  ; ----X--------X-- = ------------XX----------XX--
.byte $08, $5A                                  ; ----X----X-XX-X- = ------------XXXX--XX--XX--XX
.byte $08, $F7                                  ; ----X---XXXX-XXX = ------------XXXXXXXXXXXXXX--
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $00, $40                                  ; ---------X------ = ------------------XX--------
.byte $00, $40                                  ; ---------X------ = ------------------XX--------
.byte $00, $40                                  ; ---------X------ = ------------------XX--------
.byte $00, $A1                                  ; --------X-X----X = ----------------XX--XX------

sprite22:
.byte $0C, $10                                  ; ----XX-----X---- = ----------XXXXXX------------
.byte $0A, $30                                  ; ----X-X---XX---- = --------XX--XXXXXX----------
.byte $89, $70                                  ; X---X--X-XXX---- = ------XX----XXXXXXXX--------
.byte $89, $70                                  ; X---X--X-XXX---- = ------XX----XXXXXXXX--------
.byte $89, $70                                  ; X---X--X-XXX---- = ------XX----XXXXXXXX--------
.byte $0A, $30                                  ; ----X-X---XX---- = --------XX--XXXXXX----------
.byte $0C, $10                                  ; ----XX-----X---- = ----------XXXXXX------------
.byte $00, $10                                  ; -----------X---- = --------------XX------------
.byte $0C, $10                                  ; ----XX-----X---- = ----------XXXXXX------------
.byte $04, $10                                  ; -----X-----X---- = ----------XX--XX------------
.byte $0C, $10                                  ; ----XX-----X---- = ----------XXXXXX------------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $2E, $30                                  ; --X-XXX---XX---- = --XX----XXXXXXXXXX----------
.byte $AF, $70                                  ; X-X-XXXX-XXX---- = --XX--XXXXXXXXXXXXXX--------
.byte $FF, $60                                  ; XXXXXXXX-XX----- = XXXXXXXXXXXXXX--XXXX--------
.byte $C7, $40                                  ; XX---XXX-X------ = ----XXXXXXXX------XX--------

sprite23:
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $08, $E1                                  ; ----X---XXX----X = ------------XX--XXXXXX------
.byte $04, $72                                  ; -----X---XXX--X- = ----------XX--XXXXXX--XX----
.byte $04, $72                                  ; -----X---XXX--X- = ----------XX--XXXXXX--XX----
.byte $04, $72                                  ; -----X---XXX--X- = ----------XX--XXXXXX--XX----
.byte $08, $E1                                  ; ----X---XXX----X = ------------XX--XXXXXX------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $00, $40                                  ; ---------X------ = ------------------XX--------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $00, $50                                  ; ---------X-X---- = --------------XX--XX--------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $48, $F1                                  ; -X--X---XXXX---X = ----XX------XXXXXXXXXX------
.byte $4E, $F3                                  ; -X--XXX-XXXX--XX = ----XX--XXXXXXXXXXXXXXXX----
.byte $EF, $B3                                  ; XXX-XXXXX-XX--XX = --XXXXXXXXXXXXXXXX--XXXX----
.byte $8F, $12                                  ; X---XXXX---X--X- = ------XXXXXXXXXX------XX----

sprite24:
.byte $00, $E1                                  ; --------XXX----X = ----------------XXXXXX------
.byte $00, $72                                  ; ---------XXX--X- = --------------XXXXXX--XX----
.byte $08, $74                                  ; ----X----XXX-X-- = ------------XXXXXXXX----XX--
.byte $08, $74                                  ; ----X----XXX-X-- = ------------XXXXXXXX----XX--
.byte $08, $74                                  ; ----X----XXX-X-- = ------------XXXXXXXX----XX--
.byte $00, $72                                  ; ---------XXX--X- = --------------XXXXXX--XX----
.byte $00, $E1                                  ; --------XXX----X = ----------------XXXXXX------
.byte $00, $81                                  ; --------X------X = --------------------XX------
.byte $00, $E1                                  ; --------XXX----X = ----------------XXXXXX------
.byte $00, $A1                                  ; --------X-X----X = ----------------XX--XX------
.byte $00, $E1                                  ; --------XXX----X = ----------------XXXXXX------
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $28, $F3                                  ; --X-X---XXXX--XX = --XX--------XXXXXXXXXXXX----
.byte $2E, $F7                                  ; --X-XXX-XXXX-XXX = --XX----XXXXXXXXXXXXXXXXXX--
.byte $FF, $76                                  ; XXXXXXXX-XXX-XX- = XXXXXXXXXXXXXXXXXXXX--XXXX--
.byte $8F, $34                                  ; X---XXXX--XX-X-- = ------XXXXXXXXXXXX------XX--

sprite25:
.byte $00, $C3                                  ; --------XX----XX = ------------------XXXXXX----
.byte $00, $66                                  ; ---------XX--XX- = ----------------XXXX--XXXX--
.byte $00, $3C                                  ; ----------XXXX-- = --------------XXXX------XXXX
.byte $00, $3C                                  ; ----------XXXX-- = --------------XXXX------XXXX
.byte $00, $3C                                  ; ----------XXXX-- = --------------XXXX------XXXX
.byte $00, $66                                  ; ---------XX--XX- = ----------------XXXX--XXXX--
.byte $00, $C3                                  ; --------XX----XX = ------------------XXXXXX----
.byte $00, $02                                  ; --------------X- = ----------------------XX----
.byte $00, $C3                                  ; --------XX----XX = ------------------XXXXXX----
.byte $00, $42                                  ; ---------X----X- = ------------------XX--XX----
.byte $00, $C3                                  ; --------XX----XX = ------------------XXXXXX----
.byte $00, $C7                                  ; --------XX---XXX = ------------------XXXXXXXX--
.byte $81, $E7                                  ; X------XXXX--XXX = ------XX--------XXXXXXXXXX--
.byte $89, $FF                                  ; X---X--XXXXXXXXX = ------XX----XXXXXXXXXXXXXXXX
.byte $CF, $FD                                  ; XX--XXXXXXXXXX-X = ----XXXXXXXXXXXXXXXXXX--XXXX
.byte $0E, $78                                  ; ----XXX--XXXX--- = --------XXXXXXXXXXXX------XX

sprite26:
.byte $C3, $00                                  ; XX----XX-------- = ----XXXXXX------------------
.byte $66, $00                                  ; -XX--XX--------- = --XXXX--XXXX----------------
.byte $3C, $00                                  ; --XXXX---------- = XXXX------XXXX--------------
.byte $3C, $00                                  ; --XXXX---------- = XXXX------XXXX--------------
.byte $3C, $00                                  ; --XXXX---------- = XXXX------XXXX--------------
.byte $66, $00                                  ; -XX--XX--------- = --XXXX--XXXX----------------
.byte $C3, $00                                  ; XX----XX-------- = ----XXXXXX------------------
.byte $40, $00                                  ; -X-------------- = ----XX----------------------
.byte $C3, $00                                  ; XX----XX-------- = ----XXXXXX------------------
.byte $42, $00                                  ; -X----X--------- = ----XX--XX------------------
.byte $C3, $00                                  ; XX----XX-------- = ----XXXXXX------------------
.byte $E3, $00                                  ; XXX---XX-------- = --XXXXXXXX------------------
.byte $E7, $81                                  ; XXX--XXXX------X = --XXXXXXXXXX--------XX------
.byte $FF, $91                                  ; XXXXXXXXX--X---X = XXXXXXXXXXXXXXXX----XX------
.byte $BF, $F3                                  ; X-XXXXXXXXXX--XX = XXXX--XXXXXXXXXXXXXXXXXX----
.byte $1E, $70                                  ; ---XXXX--XXX---- = XX------XXXXXXXXXXXX--------

sprite27:
.byte $87, $00                                  ; X----XXX-------- = ------XXXXXX----------------
.byte $4E, $00                                  ; -X--XXX--------- = ----XX--XXXXXX--------------
.byte $2E, $10                                  ; --X-XXX----X---- = --XX----XXXXXXXX------------
.byte $2E, $10                                  ; --X-XXX----X---- = --XX----XXXXXXXX------------
.byte $2E, $10                                  ; --X-XXX----X---- = --XX----XXXXXXXX------------
.byte $4E, $00                                  ; -X--XXX--------- = ----XX--XXXXXX--------------
.byte $87, $00                                  ; X----XXX-------- = ------XXXXXX----------------
.byte $81, $00                                  ; X------X-------- = ------XX--------------------
.byte $87, $00                                  ; X----XXX-------- = ------XXXXXX----------------
.byte $85, $00                                  ; X----X-X-------- = ------XX--XX----------------
.byte $87, $00                                  ; X----XXX-------- = ------XXXXXX----------------
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $CF, $14                                  ; XX--XXXX---X-X-- = ----XXXXXXXXXXXX--------XX--
.byte $EF, $74                                  ; XXX-XXXX-XXX-X-- = --XXXXXXXXXXXXXXXXXX----XX--
.byte $6E, $FF                                  ; -XX-XXX-XXXXXXXX = --XXXX--XXXXXXXXXXXXXXXXXXXX
.byte $2C, $F1                                  ; --X-XX--XXXX---X = --XX------XXXXXXXXXXXX------

sprite28:
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $87, $10                                  ; X----XXX---X---- = ------XXXXXX--XX------------
.byte $4E, $20                                  ; -X--XXX---X----- = ----XX--XXXXXX--XX----------
.byte $4E, $20                                  ; -X--XXX---X----- = ----XX--XXXXXX--XX----------
.byte $4E, $20                                  ; -X--XXX---X----- = ----XX--XXXXXX--XX----------
.byte $87, $10                                  ; X----XXX---X---- = ------XXXXXX--XX------------
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $02, $00                                  ; ------X--------- = --------XX------------------
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $0A, $00                                  ; ----X-X--------- = --------XX--XX--------------
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $8F, $00                                  ; X---XXXX-------- = ------XXXXXXXX--------------
.byte $8F, $12                                  ; X---XXXX---X--X- = ------XXXXXXXXXX------XX----
.byte $CF, $72                                  ; XX--XXXX-XXX--X- = ----XXXXXXXXXXXXXXXX--XX----
.byte $CD, $F7                                  ; XX--XX-XXXXX-XXX = ----XXXX--XXXXXXXXXXXXXXXX--
.byte $48, $F1                                  ; -X--X---XXXX---X = ----XX------XXXXXXXXXX------

sprite29:
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $0C, $50                                  ; ----XX---X-X---- = ----------XXXXXX--XX--------
.byte $0E, $91                                  ; ----XXX-X--X---X = --------XXXXXXXX----XX------
.byte $0E, $91                                  ; ----XXX-X--X---X = --------XXXXXXXX----XX------
.byte $0E, $91                                  ; ----XXX-X--X---X = --------XXXXXXXX----XX------
.byte $0C, $50                                  ; ----XX---X-X---- = ----------XXXXXX--XX--------
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $08, $00                                  ; ----X----------- = ------------XX--------------
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $08, $20                                  ; ----X-----X----- = ------------XX--XX----------
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $0C, $74                                  ; ----XX---XXX-X-- = ----------XXXXXXXXXX----XX--
.byte $0E, $F5                                  ; ----XXX-XXXX-X-X = --------XXXXXXXXXXXXXX--XX--
.byte $06, $FF                                  ; -----XX-XXXXXXXX = --------XXXX--XXXXXXXXXXXXXX
.byte $02, $E3                                  ; ------X-XXX---XX = --------XX------XXXXXXXX----

sprite2A:
.byte $0C, $30                                  ; ---XX---XX---- = ----------XXXXXXXX----------
.byte $0E, $70                                  ; ---XXX-XXX---- = --------XXXXXXXXXXXX--------
.byte $8F, $F1                                  ; ---XXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $8F, $F1                                  ; ---XXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $C9, $93                                  ; X--X--X--X--XX = ----XXXX----XXXX----XXXX----
.byte $06, $60                                  ; ----XX-XX----- = --------XXXX----XXXX--------
.byte $6E, $76                                  ; XX-XXX-XXX-XX- = --XXXX--XXXXXXXXXXXX--XXXX--
.byte $56, $6A                                  ; X-X-XX-XX-X-X- = XX--XX--XXXX----XXXX--XX--XX
.byte $D9, $9B                                  ; X-XX--X--XX-XX = XX--XXXX----XXXX----XXXX--XX
.byte $9F, $F9                                  ; --XXXXXXXXX--X = XX----XXXXXXXXXXXXXXXX----XX
.byte $9D, $B9                                  ; --XXX-X-XXX--X = XX----XX--XXXXXXXX--XX----XX
.byte $12, $48                                  ; --X--X-X--X--- = XX------XX--------XX------XX
.byte $2E, $74                                  ; -X-XXX-XXX-X-- = --XX----XXXXXXXXXXXX----XX--
.byte $04, $20                                  ; ----X---X----- = ----------XX----XX----------
.byte $04, $20                                  ; ----X---X----- = ----------XX----XX----------
.byte $06, $60                                  ; ----XX-XX----- = --------XXXX----XXXX--------

sprite2B:
.byte $30, $00                                  ; --XX------------ = XXXX------------------------
.byte $30, $00                                  ; --XX------------ = XXXX------------------------
.byte $30, $00                                  ; --XX------------ = XXXX------------------------
.byte $30, $00                                  ; --XX------------ = XXXX------------------------
.byte $30, $00                                  ; --XX------------ = XXXX------------------------
.byte $30, $00                                  ; --XX------------ = XXXX------------------------
.byte $30, $00                                  ; --XX------------ = XXXX------------------------
.byte $BF, $70                                  ; X-XXXXXX-XXX---- = XXXX--XXXXXXXXXXXXXX--------
.byte $BF, $70                                  ; X-XXXXXX-XXX---- = XXXX--XXXXXXXXXXXXXX--------
.byte $FF, $70                                  ; XXXXXXXX-XXX---- = XXXXXXXXXXXXXXXXXXXX--------
.byte $8F, $70                                  ; X---XXXX-XXX---- = ------XXXXXXXXXXXXXX--------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $ED, $30                                  ; XXX-XX-X--XX---- = --XXXXXX--XXXXXXXX----------
.byte $FF, $10                                  ; XXXXXXXX---X---- = XXXXXXXXXXXXXXXX------------
.byte $BF, $10                                  ; X-XXXXXX---X---- = XXXX--XXXXXXXXXX------------
.byte $BF, $10                                  ; X-XXXXXX---X---- = XXXX--XXXXXXXXXX------------

sprite2C:
.byte $C1, $00                                  ; XX-----X-------- = ----XXXX--------------------
.byte $C1, $00                                  ; XX-----X-------- = ----XXXX--------------------
.byte $C1, $00                                  ; XX-----X-------- = ----XXXX--------------------
.byte $C1, $00                                  ; XX-----X-------- = ----XXXX--------------------
.byte $C1, $81                                  ; XX-----XX------X = ----XXXX------------XX------
.byte $C1, $60                                  ; XX-----X-XX----- = ----XXXX--------XXXX--------
.byte $C9, $10                                  ; XX--X--X---X---- = ----XXXX----XXXX------------
.byte $C5, $00                                  ; XX---X-X-------- = ----XXXX--XX----------------
.byte $CD, $F3                                  ; XX--XX-XXXXX--XX = ----XXXX--XXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $0C, $F3                                  ; ----XX--XXXX--XX = ----------XXXXXXXXXXXXXX----
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $87, $F1                                  ; X----XXXXXXX---X = ------XXXXXX--XXXXXXXX------
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $CD, $70                                  ; XX--XX-X-XXX---- = ----XXXX--XXXXXXXXXX--------
.byte $CD, $70                                  ; XX--XX-X-XXX---- = ----XXXX--XXXXXXXXXX--------

sprite2D:
.byte $83, $00                                  ; X-----XX-------- = ------XXXX------------------
.byte $83, $00                                  ; X-----XX-------- = ------XXXX------------------
.byte $83, $40                                  ; X-----XX-X------ = ------XXXX--------XX--------
.byte $83, $20                                  ; X-----XX--X----- = ------XXXX------XX----------
.byte $83, $20                                  ; X-----XX--X----- = ------XXXX------XX----------
.byte $83, $10                                  ; X-----XX---X---- = ------XXXX----XX------------
.byte $83, $10                                  ; X-----XX---X---- = ------XXXX----XX------------
.byte $8B, $00                                  ; X---X-XX-------- = ------XXXX--XX--------------
.byte $8B, $F7                                  ; X---X-XXXXXX-XXX = ------XXXX--XXXXXXXXXXXXXX--
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $08, $F7                                  ; ----X---XXXX-XXX = ------------XXXXXXXXXXXXXX--
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $0E, $E3                                  ; ----XXX-XXX---XX = --------XXXXXX--XXXXXXXX----
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $8B, $F1                                  ; X---X-XXXXXX---X = ------XXXX--XXXXXXXXXX------
.byte $8B, $F1                                  ; X---X-XXXXXX---X = ------XXXX--XXXXXXXXXX------

sprite2E:
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $04                                  ; -----XX------X-- = --------XXXX------------XX--
.byte $06, $83                                  ; -----XX-X-----XX = --------XXXX--------XXXX----
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $06, $10                                  ; -----XX----X---- = --------XXXX--XX------------
.byte $06, $FF                                  ; -----XX-XXXXXXXX = --------XXXX--XXXXXXXXXXXXXX
.byte $0E, $FF                                  ; ----XXX-XXXXXXXX = --------XXXXXXXXXXXXXXXXXXXX
.byte $00, $FF                                  ; --------XXXXXXXX = --------------XXXXXXXXXXXXXX
.byte $00, $E7                                  ; --------XXX--XXX = ----------------XXXXXXXXXX--
.byte $0C, $D7                                  ; ----XX--XX-X-XXX = ----------XXXXXX--XXXXXXXX--
.byte $0E, $F3                                  ; ----XXX-XXXX--XX = --------XXXXXXXXXXXXXXXX----
.byte $06, $F3                                  ; -----XX-XXXX--XX = --------XXXX--XXXXXXXXXX----
.byte $06, $F3                                  ; -----XX-XXXX--XX = --------XXXX--XXXXXXXXXX----

sprite2F:
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $20, $60                                  ; --X------XX----- = --XX------------XXXX--------
.byte $C1, $60                                  ; XX-----X-XX----- = ----XXXX--------XXXX--------
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $08, $60                                  ; ----X----XX----- = ------------XX--XXXX--------
.byte $FF, $60                                  ; XXXXXXXX-XX----- = XXXXXXXXXXXXXX--XXXX--------
.byte $FF, $70                                  ; XXXXXXXX-XXX---- = XXXXXXXXXXXXXXXXXXXX--------
.byte $FF, $00                                  ; XXXXXXXX-------- = XXXXXXXXXXXXXX--------------
.byte $E7, $00                                  ; XXX--XXX-------- = --XXXXXXXXXX----------------
.byte $EB, $30                                  ; XXX-X-XX--XX---- = --XXXXXXXX--XXXXXX----------
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $CF, $60                                  ; XX--XXXX-XX----- = ----XXXXXXXXXX--XXXX--------
.byte $CF, $60                                  ; XX--XXXX-XX----- = ----XXXXXXXXXX--XXXX--------

sprite30:
.byte $00, $83                                  ; --------X-----XX = --------------------XXXX----
.byte $00, $83                                  ; --------X-----XX = --------------------XXXX----
.byte $04, $83                                  ; -----X--X-----XX = ----------XX--------XXXX----
.byte $08, $83                                  ; ----X---X-----XX = ------------XX------XXXX----
.byte $08, $83                                  ; ----X---X-----XX = ------------XX------XXXX----
.byte $00, $93                                  ; --------X--X--XX = --------------XX----XXXX----
.byte $00, $93                                  ; --------X--X--XX = --------------XX----XXXX----
.byte $00, $A3                                  ; --------X-X---XX = ----------------XX--XXXX----
.byte $CF, $B3                                  ; XX--XXXXX-XX--XX = ----XXXXXXXXXXXXXX--XXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $30                                  ; XX--XXXX--XX---- = ----XXXXXXXXXXXXXX----------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------
.byte $8F, $E1                                  ; X---XXXXXXX----X = ------XXXXXXXX--XXXXXX------
.byte $0E, $F3                                  ; ----XXX-XXXX--XX = --------XXXXXXXXXXXXXXXX----
.byte $0E, $B3                                  ; ----XXX-X-XX--XX = --------XXXXXXXXXX--XXXX----
.byte $0E, $B3                                  ; ----XXX-X-XX--XX = --------XXXXXXXXXX--XXXX----

sprite31:
.byte $00, $06                                  ; -------------XX- = ----------------------XXXX--
.byte $00, $06                                  ; -------------XX- = ----------------------XXXX--
.byte $00, $06                                  ; -------------XX- = ----------------------XXXX--
.byte $00, $06                                  ; -------------XX- = ----------------------XXXX--
.byte $02, $06                                  ; ------X------XX- = --------XX------------XXXX--
.byte $0C, $06                                  ; ----XX-------XX- = ----------XXXX--------XXXX--
.byte $00, $36                                  ; ----------XX-XX- = --------------XXXX----XXXX--
.byte $00, $46                                  ; ---------X---XX- = ------------------XX--XXXX--
.byte $8F, $76                                  ; X---XXXX-XXX-XX- = ------XXXXXXXXXXXXXX--XXXX--
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $8F, $70                                  ; X---XXXX-XXX---- = ------XXXXXXXXXXXXXX--------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $0E, $D3                                  ; ----XXX-XX-X--XX = --------XXXXXXXX--XXXXXX----
.byte $0C, $F7                                  ; ----XX--XXXX-XXX = ----------XXXXXXXXXXXXXXXX--
.byte $0C, $76                                  ; ----XX---XXX-XX- = ----------XXXXXXXXXX--XXXX--
.byte $0C, $76                                  ; ----XX---XXX-XX- = ----------XXXXXXXXXX--XXXX--

sprite32:
.byte $00, $0C                                  ; ------------XX-- = ------------------------XXXX
.byte $00, $0C                                  ; ------------XX-- = ------------------------XXXX
.byte $00, $0C                                  ; ------------XX-- = ------------------------XXXX
.byte $00, $0C                                  ; ------------XX-- = ------------------------XXXX
.byte $00, $0C                                  ; ------------XX-- = ------------------------XXXX
.byte $00, $0C                                  ; ------------XX-- = ------------------------XXXX
.byte $00, $0C                                  ; ------------XX-- = ------------------------XXXX
.byte $0E, $FD                                  ; ----XXX-XXXXXX-X = --------XXXXXXXXXXXXXX--XXXX
.byte $0E, $FD                                  ; ----XXX-XXXXXX-X = --------XXXXXXXXXXXXXX--XXXX
.byte $0E, $FF                                  ; ----XXX-XXXXXXXX = --------XXXXXXXXXXXXXXXXXXXX
.byte $0E, $F1                                  ; ----XXX-XXXX---X = --------XXXXXXXXXXXXXX------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $0C, $B7                                  ; ----XX--X-XX-XXX = ----------XXXXXXXX--XXXXXX--
.byte $08, $FF                                  ; ----X---XXXXXXXX = ------------XXXXXXXXXXXXXXXX
.byte $08, $FD                                  ; ----X---XXXXXX-X = ------------XXXXXXXXXX--XXXX
.byte $08, $FD                                  ; ----X---XXXXXX-X = ------------XXXXXXXXXX--XXXX

sprite33:
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------
.byte $EF, $70                                  ; XXX-XXXX-XXX---- = --XXXXXXXXXXXXXXXXXX--------
.byte $E9, $F1                                  ; XXX-X--XXXXX---X = --XXXXXX----XXXXXXXXXX------
.byte $F9, $30                                  ; XXXXX--X--XX---- = XXXXXXXX----XXXXXX----------
.byte $FF, $00                                  ; XXXXXXXX-------- = XXXXXXXXXXXXXX--------------
.byte $F3, $00                                  ; XXXX--XX-------- = XXXXXXXXXX------------------
.byte $FF, $00                                  ; XXXXXXXX-------- = XXXXXXXXXXXXXX--------------
.byte $FF, $30                                  ; XXXXXXXX--XX---- = XXXXXXXXXXXXXXXXXX----------
.byte $EF, $F1                                  ; XXX-XXXXXXXX---X = --XXXXXXXXXXXXXXXXXXXX------
.byte $EF, $70                                  ; XXX-XXXX-XXX---- = --XXXXXXXXXXXXXXXXXX--------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------
.byte $0A, $00                                  ; ----X-X--------- = --------XX--XX--------------
.byte $0A, $00                                  ; ----X-X--------- = --------XX--XX--------------
.byte $0A, $00                                  ; ----X-X--------- = --------XX--XX--------------
.byte $0A, $00                                  ; ----X-X--------- = --------XX--XX--------------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------

sprite34:
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $8F, $F3                                  ; X---XXXXXXXX--XX = ------XXXXXXXXXXXXXXXXXX----
.byte $8F, $C3                                  ; X---XXXXXX----XX = ------XXXXXXXX----XXXXXX----
.byte $CF, $C7                                  ; XX--XXXXXX---XXX = ----XXXXXXXXXX----XXXXXXXX--
.byte $CF, $F7                                  ; XX--XXXXXXXX-XXX = ----XXXXXXXXXXXXXXXXXXXXXX--
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $CF, $F7                                  ; XX--XXXXXXXX-XXX = ----XXXXXXXXXXXXXXXXXXXXXX--
.byte $CF, $F7                                  ; XX--XXXXXXXX-XXX = ----XXXXXXXXXXXXXXXXXXXXXX--
.byte $8F, $F3                                  ; X---XXXXXXXX--XX = ------XXXXXXXXXXXXXXXXXX----
.byte $8F, $F3                                  ; X---XXXXXXXX--XX = ------XXXXXXXXXXXXXXXXXX----
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $08, $20                                  ; ----X-----X----- = ------------XX--XX----------
.byte $08, $20                                  ; ----X-----X----- = ------------XX--XX----------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite35:
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $0E, $F7                                  ; ----XXX-XXXX-XXX = --------XXXXXXXXXXXXXXXXXX--
.byte $0E, $CF                                  ; ----XXX-XX--XXXX = --------XXXXXX----XXXXXXXXXX
.byte $8F, $C3                                  ; X---XXXXXX----XX = ------XXXXXXXX----XXXXXX----
.byte $8F, $70                                  ; X---XXXX-XXX---- = ------XXXXXXXXXXXXXX--------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------
.byte $8F, $70                                  ; X---XXXX-XXX---- = ------XXXXXXXXXXXXXX--------
.byte $8F, $F3                                  ; X---XXXXXXXX--XX = ------XXXXXXXXXXXXXXXXXX----
.byte $0E, $FF                                  ; ----XXX-XXXXXXXX = --------XXXXXXXXXXXXXXXXXXXX
.byte $0E, $F7                                  ; ----XXX-XXXX-XXX = --------XXXXXXXXXXXXXXXXXX--
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite36:
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $0C, $9F                                  ; ----XX--X--XXXXX = ----------XXXXXX----XXXXXXXX
.byte $0C, $97                                  ; ----XX--X--X-XXX = ----------XXXXXX----XXXXXX--
.byte $0E, $F3                                  ; ----XXX-XXXX--XX = --------XXXXXXXXXXXXXXXX----
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $0E, $F3                                  ; ----XXX-XXXX--XX = --------XXXXXXXXXXXXXXXX----
.byte $0C, $F7                                  ; ----XX--XXXX-XXX = ----------XXXXXXXXXXXXXXXX--
.byte $0C, $FF                                  ; ----XX--XXXXXXXX = ----------XXXXXXXXXXXXXXXXXX
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $00, $A1                                  ; --------X-X----X = ----------------XX--XX------
.byte $00, $A1                                  ; --------X-X----X = ----------------XX--XX------
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite37:
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $F9, $30                                  ; XXXXX--X--XX---- = XXXXXXXX----XXXXXX----------
.byte $E9, $30                                  ; XXX-X--X--XX---- = --XXXXXX----XXXXXX----------
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $EF, $30                                  ; XXX-XXXX--XX---- = --XXXXXXXXXXXXXXXX----------
.byte $FF, $30                                  ; XXXXXXXX--XX---- = XXXXXXXXXXXXXXXXXX----------
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $85, $00                                  ; X----X-X-------- = ------XX--XX----------------
.byte $85, $00                                  ; X----X-X-------- = ------XX--XX----------------
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite38:
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $CF, $F1                                  ; XX--XXXXXXXX---X = ----XXXXXXXXXXXXXXXXXX------
.byte $E7, $E1                                  ; XXX--XXXXXX----X = --XXXXXXXXXX----XXXXXX------
.byte $87, $E3                                  ; X----XXXXXX---XX = ------XXXXXX----XXXXXXXX----
.byte $0C, $F3                                  ; ----XX--XXXX--XX = ----------XXXXXXXXXXXXXX----
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $0C, $F3                                  ; ----XX--XXXX--XX = ----------XXXXXXXXXXXXXX----
.byte $8F, $F3                                  ; X---XXXXXXXX--XX = ------XXXXXXXXXXXXXXXXXX----
.byte $EF, $F1                                  ; XXX-XXXXXXXX---X = --XXXXXXXXXXXXXXXXXXXX------
.byte $CF, $F1                                  ; XX--XXXXXXXX---X = ----XXXXXXXXXXXXXXXXXX------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite39:
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $8F, $F3                                  ; X---XXXXXXXX--XX = ------XXXXXXXXXXXXXXXXXX----
.byte $87, $E3                                  ; X----XXXXXX---XX = ------XXXXXX----XXXXXXXX----
.byte $C7, $E7                                  ; XX---XXXXXX--XXX = ----XXXXXXXX----XXXXXXXXXX--
.byte $CF, $F7                                  ; XX--XXXXXXXX-XXX = ----XXXXXXXXXXXXXXXXXXXXXX--
.byte $00, $E7                                  ; --------XXX--XXX = ----------------XXXXXXXXXX--
.byte $CF, $F7                                  ; XX--XXXXXXXX-XXX = ----XXXXXXXXXXXXXXXXXXXXXX--
.byte $CF, $F7                                  ; XX--XXXXXXXX-XXX = ----XXXXXXXXXXXXXXXXXXXXXX--
.byte $8F, $F3                                  ; X---XXXXXXXX--XX = ------XXXXXXXXXXXXXXXXXX----
.byte $8F, $F3                                  ; X---XXXXXXXX--XX = ------XXXXXXXXXXXXXXXXXX----
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $08, $20                                  ; ----X-----X----- = ------------XX--XX----------
.byte $08, $20                                  ; ----X-----X----- = ------------XX--XX----------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite3A:
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $0E, $F7                                  ; ----XXX-XXXX-XXX = --------XXXXXXXXXXXXXXXXXX--
.byte $8F, $97                                  ; X---XXXXX--X-XXX = ------XXXXXXXXXX----XXXXXX--
.byte $0C, $9F                                  ; ----XX--X--XXXXX = ----------XXXXXX----XXXXXXXX
.byte $00, $FF                                  ; --------XXXXXXXX = --------------XXXXXXXXXXXXXX
.byte $00, $CF                                  ; --------XX--XXXX = ------------------XXXXXXXXXX
.byte $00, $FF                                  ; --------XXXXXXXX = --------------XXXXXXXXXXXXXX
.byte $0C, $FF                                  ; ----XX--XXXXXXXX = ----------XXXXXXXXXXXXXXXXXX
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $0E, $F7                                  ; ----XXX-XXXX-XXX = --------XXXXXXXXXXXXXXXXXX--
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $00, $50                                  ; ---------X-X---- = --------------XX--XX--------
.byte $00, $50                                  ; ---------X-X---- = --------------XX--XX--------
.byte $00, $50                                  ; ---------X-X---- = --------------XX--XX--------
.byte $00, $50                                  ; ---------X-X---- = --------------XX--XX--------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------

sprite3B:
.byte $83, $00                                  ; X-----XX-------- = ------XXXX------------------
.byte $87, $00                                  ; X----XXX-------- = ------XXXXXX----------------
.byte $0A, $20                                  ; ----X-X---X----- = --------XX--XX--XX----------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $87, $00                                  ; X----XXX-------- = ------XXXXXX----------------
.byte $8F, $00                                  ; X---XXXX-------- = ------XXXXXXXX--------------
.byte $87, $10                                  ; X----XXX---X---- = ------XXXXXX--XX------------
.byte $C7, $00                                  ; XX---XXX-------- = ----XXXXXXXX----------------
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $6E, $00                                  ; -XX-XXX--------- = --XXXX--XXXXXX--------------
.byte $24, $00                                  ; --X--X---------- = --XX------XX----------------
.byte $28, $00                                  ; --X-X----------- = --XX--------XX--------------
.byte $10, $10                                  ; ---X-------X---- = XX------------XX------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite3C:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $0C, $00                                  ; ----XX---------- = ----------XXXX--------------
.byte $0C, $10                                  ; ----XX-----X---- = ----------XXXXXX------------
.byte $08, $A1                                  ; ----X---X-X----X = ------------XX--XX--XX------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $0C, $10                                  ; ----XX-----X---- = ----------XXXXXX------------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $0C, $50                                  ; ----XX---X-X---- = ----------XXXXXX--XX--------
.byte $0E, $10                                  ; ----XXX----X---- = --------XXXXXXXX------------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $8B, $30                                  ; X---X-XX--XX---- = ------XXXX--XXXXXX----------
.byte $C9, $10                                  ; XX--X--X---X---- = ----XXXX----XXXX------------
.byte $20, $60                                  ; --X------XX----- = --XX------------XXXX--------

sprite3D:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $00, $52                                  ; ---------X-X--X- = --------------XX--XX--XX----
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $08, $B1                                  ; ----X---X-XX---X = ------------XXXXXX--XX------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $E7, $F3                                  ; XXX--XXXXXXX--XX = --XXXXXXXXXX--XXXXXXXXXX----

sprite3E:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $00, $A5                                  ; --------X-X--X-X = ----------------XX--XX--XX--
.byte $00, $E7                                  ; --------XXX--XXX = ----------------XXXXXXXXXX--
.byte $00, $E1                                  ; --------XXX----X = ----------------XXXXXX------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $00, $72                                  ; ---------XXX--X- = --------------XXXXXX--XX----
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $0C, $F1                                  ; ----XX--XXXX---X = ----------XXXXXXXXXXXX------
.byte $0C, $60                                  ; ----XX---XX----- = ----------XXXX--XXXX--------
.byte $06, $83                                  ; -----XX-X-----XX = --------XXXX--------XXXX----
.byte $81, $00                                  ; X------X-------- = ------XX--------------------

sprite3F:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $0C, $00                                  ; ----XX---------- = ----------XXXX--------------
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $A5, $00                                  ; X-X--X-X-------- = --XX--XX--XX----------------
.byte $E7, $00                                  ; XXX--XXX-------- = --XXXXXXXXXX----------------
.byte $87, $00                                  ; X----XXX-------- = ------XXXXXX----------------
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $8F, $00                                  ; X---XXXX-------- = ------XXXXXXXX--------------
.byte $4E, $00                                  ; -X--XXX--------- = ----XX--XXXXXX--------------
.byte $0E, $10                                  ; ----XXX----X---- = --------XXXXXXXX------------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------
.byte $8F, $30                                  ; X---XXXX--XX---- = ------XXXXXXXXXXXX----------
.byte $06, $30                                  ; -----XX---XX---- = --------XXXX--XXXX----------
.byte $C1, $60                                  ; XX-----X-XX----- = ----XXXX--------XXXX--------
.byte $00, $81                                  ; --------X------X = --------------------XX------

sprite40:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $85, $10                                  ; X----X-X---X---- = ------XX--XX--XX------------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------
.byte $0C, $10                                  ; ----XX-----X---- = ----------XXXXXX------------
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $0A, $30                                  ; ----X-X---XX---- = --------XX--XXXXXX----------
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $0C, $F1                                  ; ----XX--XXXX---X = ----------XXXXXXXXXXXX------
.byte $8F, $DF                                  ; X---XXXXXX-XXXXX = ------XXXXXXXXXX--XXXXXXXXXX

sprite41:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $0A, $20                                  ; ----X-X---X----- = --------XX--XX--XX----------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $04, $70                                  ; -----X---XXX---- = ----------XX--XXXXXX--------
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $08, $B3                                  ; ----X---X-XX--XX = ------------XXXXXX--XXXX----
.byte $00, $36                                  ; ----------XX-XX- = --------------XXXX----XXXX--
.byte $0C, $08                                  ; ----XX------X--- = ----------XXXX------------XX

sprite42:
.byte $00, $C1                                  ; --------XX-----X = ------------------XXXX------
.byte $00, $E1                                  ; --------XXX----X = ----------------XXXXXX------
.byte $04, $50                                  ; -----X---X-X---- = ----------XX--XX--XX--------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $E1                                  ; --------XXX----X = ----------------XXXXXX------
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $08, $E1                                  ; ----X---XXX----X = ------------XX--XXXXXX------
.byte $00, $E3                                  ; --------XXX---XX = ----------------XXXXXXXX----
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $00, $76                                  ; ---------XXX-XX- = --------------XXXXXX--XXXX--
.byte $00, $24                                  ; ----------X--X-- = ----------------XX------XX--
.byte $00, $14                                  ; -----------X-X-- = --------------XX--------XX--
.byte $08, $08                                  ; ----X-------X--- = ------------XX------------XX
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite43:
.byte $4C, $32                                  ; -X--XX----XX--X- = ----XX----XXXXXXXX----XX----
.byte $CB, $D3                                  ; XX--X-XXXX-X--XX = ----XXXXXX--XXXX--XXXXXX----
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $CD, $B3                                  ; XX--XX-XX-XX--XX = ----XXXX--XXXXXXXX--XXXX----
.byte $6C, $36                                  ; -XX-XX----XX-XX- = --XXXX----XXXXXXXX----XXXX--
.byte $24, $24                                  ; --X--X----X--X-- = --XX------XX----XX------XX--
.byte $42, $42                                  ; -X----X--X----X- = ----XX--XX--------XX--XX----
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------

sprite44:
.byte $8D, $B1                                  ; X---XX-XX-XX---X = ------XX--XXXXXXXX--XX------
.byte $8B, $D1                                  ; X---X-XXXX-X---X = ------XXXX--XXXX--XXXX------
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $EF, $F7                                  ; XXX-XXXXXXXX-XXX = --XXXXXXXXXXXXXXXXXXXXXXXX--
.byte $7C, $3E                                  ; -XXXXX----XXXXX- = XXXXXX----XXXXXXXX----XXXXXX
.byte $1C, $38                                  ; ---XXX----XXX--- = XX--------XXXXXXXX--------XX
.byte $3C, $3C                                  ; --XXXX----XXXX-- = XXXX------XXXXXXXX------XXXX
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $C3, $C3                                  ; XX----XXXX----XX = ----XXXXXX--------XXXXXX----

sprite45:
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $64, $26                                  ; -XX--X----X--XX- = --XXXX----XX----XX----XXXX--
.byte $48, $12                                  ; -X--X------X--X- = ----XX------XXXX------XX----
.byte $6C, $36                                  ; -XX-XX----XX-XX- = --XXXX----XXXXXXXX----XXXX--
.byte $CD, $B3                                  ; XX--XX-XX-XX--XX = ----XXXX--XXXXXXXX--XXXX----
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $8B, $D1                                  ; X---X-XXXX-X---X = ------XXXX--XXXX--XXXX------
.byte $8D, $B1                                  ; X---XX-XX-XX---X = ------XX--XXXXXXXX--XX------

sprite46:
.byte $E1, $87                                  ; XXX----XX----XXX = --XXXXXX------------XXXXXX--
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $68, $16                                  ; -XX-X------X-XX- = --XXXX------XXXX------XXXX--
.byte $4C, $32                                  ; -X--XX----XX--X- = ----XX----XXXXXXXX----XX----
.byte $6C, $36                                  ; -XX-XX----XX-XX- = --XXXX----XXXXXXXX----XXXX--
.byte $CD, $B3                                  ; XX--XX-XX-XX--XX = ----XXXX--XXXXXXXX--XXXX----
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $46, $62                                  ; -X---XX--XX---X- = ----XX--XXXX----XXXX--XX----
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $8B, $D1                                  ; X---X-XXXX-X---X = ------XXXX--XXXX--XXXX------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------

sprite47:
.byte $02, $00                                  ; ------X--------- = --------XX------------------
.byte $04, $10                                  ; -----X-----X---- = ----------XX--XX------------
.byte $02, $20                                  ; ------X---X----- = --------XX------XX----------
.byte $44, $10                                  ; -X---X-----X---- = ----XX----XX--XX------------
.byte $22, $20                                  ; --X---X---X----- = --XX----XX------XX----------
.byte $40, $10                                  ; -X---------X---- = ----XX--------XX------------
.byte $26, $00                                  ; --X--XX--------- = --XX----XXXX----------------
.byte $C9, $10                                  ; XX--X--X---X---- = ----XXXX----XXXX------------
.byte $24, $20                                  ; --X--X----X----- = --XX------XX----XX----------
.byte $24, $20                                  ; --X--X----X----- = --XX------XX----XX----------
.byte $12, $40                                  ; ---X--X--X------ = XX------XX--------XX--------
.byte $14, $40                                  ; ---X-X---X------ = XX--------XX------XX--------
.byte $22, $20                                  ; --X---X---X----- = --XX----XX------XX----------
.byte $22, $20                                  ; --X---X---X----- = --XX----XX------XX----------
.byte $C9, $10                                  ; XX--X--X---X---- = ----XXXX----XXXX------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------

sprite48:
.byte $08, $00                                  ; ----X----------- = ------------XX--------------
.byte $81, $91                                  ; X------XX--X---X = ------XX------XX----XX------
.byte $0A, $40                                  ; ----X-X--X------ = --------XX--XX----XX--------
.byte $81, $91                                  ; X------XX--X---X = ------XX------XX----XX------
.byte $0A, $40                                  ; ----X-X--X------ = --------XX--XX----XX--------
.byte $81, $81                                  ; X------XX------X = ------XX------------XX------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $81, $81                                  ; X------XX------X = ------XX------------XX------
.byte $81, $C1                                  ; X------XXX-----X = ------XX----------XXXX------
.byte $48, $22                                  ; -X--X-----X---X- = ----XX------XX--XX----XX----
.byte $44, $12                                  ; -X---X-----X--X- = ----XX----XX--XX------XX----
.byte $83, $81                                  ; X-----XXX------X = ------XXXX----------XX------
.byte $81, $81                                  ; X------XX------X = ------XX------------XX------
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------

sprite49:
.byte $00, $20                                  ; ----------X----- = ----------------XX----------
.byte $04, $40                                  ; -----X---X------ = ----------XX------XX--------
.byte $02, $22                                  ; ------X---X---X- = --------XX------XX----XX----
.byte $04, $44                                  ; -----X---X---X-- = ----------XX------XX----XX--
.byte $02, $22                                  ; ------X---X---X- = --------XX------XX----XX----
.byte $04, $04                                  ; -----X-------X-- = ----------XX------------XX--
.byte $00, $32                                  ; ----------XX--X- = --------------XXXX----XX----
.byte $0C, $C1                                  ; ----XX--XX-----X = ----------XXXX----XXXX------
.byte $02, $02                                  ; ------X-------X- = --------XX------------XX----
.byte $02, $02                                  ; ------X-------X- = --------XX------------XX----
.byte $8D, $24                                  ; X---XX-X--X--X-- = ------XX--XXXX--XX------XX--
.byte $81, $D5                                  ; X------XXX-X-X-X = ------XX------XX--XXXX--XX--
.byte $02, $02                                  ; ------X-------X- = --------XX------------XX----
.byte $02, $02                                  ; ------X-------X- = --------XX------------XX----
.byte $0C, $C1                                  ; ----XX--XX-----X = ----------XXXX----XXXX------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------

sprite4A:
.byte $00, $12                                  ; -----------X--X- = --------------XX------XX----
.byte $04, $24                                  ; -----X----X--X-- = ----------XX----XX------XX--
.byte $02, $12                                  ; ------X----X--X- = --------XX----XX------XX----
.byte $04, $24                                  ; -----X----X--X-- = ----------XX----XX------XX--
.byte $02, $12                                  ; ------X----X--X- = --------XX----XX------XX----
.byte $04, $04                                  ; -----X-------X-- = ----------XX------------XX--
.byte $02, $60                                  ; ------X--XX----- = --------XX------XXXX--------
.byte $08, $93                                  ; ----X---X--X--XX = ------------XXXX----XXXX----
.byte $04, $14                                  ; -----X-----X-X-- = ----------XX--XX--------XX--
.byte $04, $24                                  ; -----X----X--X-- = ----------XX----XX------XX--
.byte $02, $48                                  ; ------X--X--X--- = --------XX--------XX------XX
.byte $02, $28                                  ; ------X---X-X--- = --------XX------XX--------XX
.byte $04, $44                                  ; -----X---X---X-- = ----------XX------XX----XX--
.byte $04, $85                                  ; -----X--X----X-X = ----------XX--------XX--XX--
.byte $08, $93                                  ; ----X---X--X--XX = ------------XXXX----XXXX----
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------

sprite4B:
.byte $85, $40                                  ; X----X-X-X------ = ------XX--XX------XX--------
.byte $46, $62                                  ; -X---XX--XX---X- = ----XX--XXXX----XXXX--XX----
.byte $08, $A1                                  ; ----X---X-X----X = ------------XX--XX--XX------
.byte $E9, $68                                  ; XXX-X--X-XX-X--- = --XXXXXX----XX--XXXX------XX
.byte $3A, $3E                                  ; --XXX-X---XXXXX- = XXXX----XX--XXXXXX----XXXXXX
.byte $0C, $B1                                  ; ----XX--X-XX---X = ----------XXXXXXXX--XX------
.byte $FF, $7E                                  ; XXXXXXXX-XXXXXX- = XXXXXXXXXXXXXXXXXXXX--XXXXXX
.byte $0E, $F1                                  ; ----XXX-XXXX---X = --------XXXXXXXXXXXXXX------
.byte $7E, $74                                  ; -XXXXXX--XXX-X-- = XXXXXX--XXXXXXXXXXXX----XX--
.byte $1E, $FF                                  ; ---XXXX-XXXXXXXX = XX------XXXXXXXXXXXXXXXXXXXX
.byte $8D, $F1                                  ; X---XX-XXXXX---X = ------XX--XXXXXXXXXXXX------
.byte $64, $56                                  ; -XX--X---X-X-XX- = --XXXX----XX--XX--XX--XXXX--
.byte $32, $5C                                  ; --XX--X--X-XXX-- = XXXX----XX----XX--XX----XXXX
.byte $99, $58                                  ; X--XX--X-X-XX--- = XX----XX----XXXX--XX------XX
.byte $44, $91                                  ; -X---X--X--X---X = ----XX----XX--XX----XX------
.byte $66, $93                                  ; -XX--XX-X--X--XX = --XXXX--XXXX--XX----XXXX----

sprite4C:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $0A, $40                                  ; ----X-X--X------ = --------XX--XX----XX--------
.byte $0C, $20                                  ; ----XX----X----- = ----------XXXX--XX----------
.byte $68, $E5                                  ; -XX-X---XXX--X-X = --XXXX------XX--XXXXXX--XX--
.byte $CB, $36                                  ; XX--X-XX--XX-XX- = ----XXXXXX--XXXXXX----XXXX--
.byte $0C, $B1                                  ; ----XX--X-XX---X = ----------XXXXXXXX--XX------
.byte $EF, $76                                  ; XXX-XXXX-XXX-XX- = --XXXXXXXXXXXXXXXXXX--XXXX--
.byte $0E, $F5                                  ; ----XXX-XXXX-X-X = --------XXXXXXXXXXXXXX--XX--
.byte $EF, $70                                  ; XXX-XXXX-XXX---- = --XXXXXXXXXXXXXXXXXX--------
.byte $3E, $F7                                  ; --XXXXX-XXXX-XXX = XXXX----XXXXXXXXXXXXXXXXXX--
.byte $8D, $F1                                  ; X---XX-XXXXX---X = ------XX--XXXXXXXXXXXX------
.byte $64, $56                                  ; -XX--X---X-X-XX- = --XXXX----XX--XX--XX--XXXX--
.byte $22, $54                                  ; --X---X--X-X-X-- = --XX----XX----XX--XX----XX--
.byte $8D, $91                                  ; X---XX-XX--X---X = ------XX--XXXXXX----XX------
.byte $C5, $B3                                  ; XX---X-XX-XX--XX = ----XXXX--XX--XXXX--XXXX----
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------

sprite4D:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $04, $40                                  ; -----X---X------ = ----------XX------XX--------
.byte $89, $60                                  ; X---X--X-XX----- = ------XX----XX--XXXX--------
.byte $0A, $32                                  ; ----X-X---XX--X- = --------XX--XXXXXX----XX----
.byte $0C, $B1                                  ; ----XX--X-XX---X = ----------XXXXXXXX--XX------
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $0E, $F3                                  ; ----XXX-XXXX--XX = --------XXXXXXXXXXXXXXXX----
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $4E, $F3                                  ; -X--XXX-XXXX--XX = ----XX--XXXXXXXXXXXXXXXX----
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $44, $52                                  ; -X---X---X-X--X- = ----XX----XX--XX--XX--XX----
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $85, $D1                                  ; X----X-XXX-X---X = ------XX--XX--XX--XXXX------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite4E:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $0A, $40                                  ; ----X-X--X------ = --------XX--XX----XX--------
.byte $0C, $20                                  ; ----XX----X----- = ----------XXXX--XX----------
.byte $68, $E5                                  ; -XX-X---XXX--X-X = --XXXX------XX--XXXXXX--XX--
.byte $CB, $36                                  ; XX--X-XX--XX-XX- = ----XXXXXX--XXXXXX----XXXX--
.byte $0C, $B1                                  ; ----XX--X-XX---X = ----------XXXXXXXX--XX------
.byte $EF, $76                                  ; XXX-XXXX-XXX-XX- = --XXXXXXXXXXXXXXXXXX--XXXX--
.byte $0E, $F5                                  ; ----XXX-XXXX-X-X = --------XXXXXXXXXXXXXX--XX--
.byte $EF, $70                                  ; XXX-XXXX-XXX---- = --XXXXXXXXXXXXXXXXXX--------
.byte $3E, $F7                                  ; --XXXXX-XXXX-XXX = XXXX----XXXXXXXXXXXXXXXXXX--
.byte $8D, $F1                                  ; X---XX-XXXXX---X = ------XX--XXXXXXXXXXXX------
.byte $64, $56                                  ; -XX--X---X-X-XX- = --XXXX----XX--XX--XX--XXXX--
.byte $22, $54                                  ; --X---X--X-X-X-- = --XX----XX----XX--XX----XX--
.byte $8D, $91                                  ; X---XX-XX--X---X = ------XX--XXXXXX----XX------
.byte $C5, $B3                                  ; XX---X-XX-XX--XX = ----XXXX--XX--XXXX--XXXX----
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------

sprite4F:
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $FF, $70                                  ; XXXXXXXX-XXX---- = XXXXXXXXXXXXXXXXXXXX--------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $60, $30                                  ; -XX-------XX---- = --XXXX--------XXXX----------
.byte $B9, $60                                  ; X-XXX--X-XX----- = XXXX--XX----XX--XXXX--------
.byte $D9, $50                                  ; XX-XX--X-X-X---- = XX--XXXX----XXXX--XX--------
.byte $60, $30                                  ; -XX-------XX---- = --XXXX--------XXXX----------

sprite50:
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------
.byte $44, $62                                  ; -X---X---XX---X- = ----XX----XX----XXXX--XX----
.byte $C7, $62                                  ; XX---XXX-XX---X- = ----XXXXXXXX----XXXX--XX----
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------

sprite51:
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $06, $83                                  ; -----XX-X-----XX = --------XXXX--------XXXX----
.byte $8D, $C5                                  ; X---XX-XXX---X-X = ------XX--XXXX----XXXX--XX--
.byte $8B, $46                                  ; X---X-XX-X---XX- = ------XXXX--XX----XX--XXXX--
.byte $06, $83                                  ; -----XX-X-----XX = --------XXXX--------XXXX----

sprite52:
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $0E, $FF                                  ; ----XXX-XXXXXXXX = --------XXXXXXXXXXXXXXXXXXXX
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $0C, $06                                  ; ----XX-------XX- = ----------XXXX--------XXXX--
.byte $02, $9B                                  ; ------X-X--XX-XX = --------XX----XX----XXXX--XX
.byte $0E, $9B                                  ; ----XXX-X--XX-XX = --------XXXXXXXX----XXXX--XX
.byte $0C, $06                                  ; ----XX-------XX- = ----------XXXX--------XXXX--

sprite53:
.byte $E1, $00                                  ; XXX----X-------- = --XXXXXX--------------------
.byte $A1, $00                                  ; X-X----X-------- = --XX--XX--------------------
.byte $E7, $00                                  ; XXX--XXX-------- = --XXXXXXXXXX----------------
.byte $C5, $00                                  ; XX---X-X-------- = ----XXXX--XX----------------
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $CF, $00                                  ; XX--XXXX-------- = ----XXXXXXXXXX--------------
.byte $83, $00                                  ; X-----XX-------- = ------XXXX------------------
.byte $C7, $00                                  ; XX---XXX-------- = ----XXXXXXXX----------------
.byte $EF, $00                                  ; XXX-XXXX-------- = --XXXXXXXXXXXX--------------
.byte $EF, $00                                  ; XXX-XXXX-------- = --XXXXXXXXXXXX--------------
.byte $FD, $10                                  ; XXXXXX-X---X---- = XXXXXXXX--XXXXXX------------
.byte $FB, $10                                  ; XXXXX-XX---X---- = XXXXXXXXXX--XXXX------------
.byte $C7, $00                                  ; XX---XXX-------- = ----XXXXXXXX----------------
.byte $ED, $00                                  ; XXX-XX-X-------- = --XXXXXX--XXXX--------------
.byte $6E, $00                                  ; -XX-XXX--------- = --XXXX--XXXXXX--------------
.byte $ED, $10                                  ; XXX-XX-X---X---- = --XXXXXX--XXXXXX------------

sprite54:
.byte $87, $00                                  ; X----XXX-------- = ------XXXXXX----------------
.byte $85, $00                                  ; X----X-X-------- = ------XX--XX----------------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------
.byte $06, $10                                  ; -----XX----X---- = --------XXXX--XX------------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $0C, $00                                  ; ----XX---------- = ----------XXXX--------------
.byte $0E, $10                                  ; ----XXX----X---- = --------XXXXXXXX------------
.byte $8B, $30                                  ; X---X-XX--XX---- = ------XXXX--XXXXXX----------
.byte $8B, $30                                  ; X---X-XX--XX---- = ------XXXX--XXXXXX----------
.byte $8B, $30                                  ; X---X-XX--XX---- = ------XXXX--XXXXXX----------
.byte $87, $30                                  ; X----XXX--XX---- = ------XXXXXX--XXXX----------
.byte $0E, $10                                  ; ----XXX----X---- = --------XXXXXXXX------------
.byte $0C, $00                                  ; ----XX---------- = ----------XXXX--------------
.byte $0C, $00                                  ; ----XX---------- = ----------XXXX--------------
.byte $0C, $10                                  ; ----XX-----X---- = ----------XXXXXX------------

sprite55:
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $0A, $00                                  ; ----X-X--------- = --------XX--XX--------------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $0C, $20                                  ; ----XX----X----- = ----------XXXX--XX----------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $8F, $E1                                  ; X---XXXXXXX----X = ------XXXXXXXX--XXXXXX------
.byte $8F, $D1                                  ; X---XXXXXX-X---X = ------XXXXXXXXXX--XXXX------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $0E, $60                                  ; ----XXX--XX----- = --------XXXXXX--XXXX--------
.byte $06, $70                                  ; -----XX--XXX---- = --------XXXX--XXXXXX--------
.byte $0E, $E1                                  ; ----XXX-XXX----X = --------XXXXXX--XXXXXX------

sprite56:
.byte $0C, $10                                  ; ----XX-----X---- = ----------XXXXXX------------
.byte $04, $10                                  ; -----X-----X---- = ----------XX--XX------------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $08, $50                                  ; ----X----X-X---- = ------------XXXX--XX--------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $0C, $F1                                  ; ----XX--XXXX---X = ----------XXXXXXXXXXXX------
.byte $0E, $F3                                  ; ----XXX-XXXX--XX = --------XXXXXXXXXXXXXXXX----
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $8B, $76                                  ; X---X-XX-XXX-XX- = ------XXXX--XXXXXXXX--XXXX--
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $0C, $D5                                  ; ----XX--XX-X-X-X = ----------XXXXXX--XXXX--XX--
.byte $06, $87                                  ; -----XX-X----XXX = --------XXXX--------XXXXXX--
.byte $0E, $02                                  ; ----XXX-------X- = --------XXXXXX--------XX----

sprite57:
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $0C, $20                                  ; ----XX----X----- = ----------XXXX--XX----------
.byte $0E, $30                                  ; ----XXX---XX---- = --------XXXXXXXXXX----------
.byte $0A, $10                                  ; ----X-X----X---- = --------XX--XXXX------------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------
.byte $0C, $00                                  ; ----XX---------- = ----------XXXX--------------
.byte $0E, $10                                  ; ----XXX----X---- = --------XXXXXXXX------------
.byte $8F, $30                                  ; X---XXXX--XX---- = ------XXXXXXXXXXXX----------
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $EF, $F1                                  ; XXX-XXXXXXXX---X = --XXXXXXXXXXXXXXXXXXXX------
.byte $6E, $D1                                  ; -XX-XXX-XX-X---X = --XXXX--XXXXXXXX--XXXX------
.byte $8F, $10                                  ; X---XXXX---X---- = ------XXXXXXXXXX------------
.byte $AB, $30                                  ; X-X-X-XX--XX---- = --XX--XXXX--XXXXXX----------
.byte $E1, $60                                  ; XXX----X-XX----- = --XXXXXX--------XXXX--------
.byte $40, $70                                  ; -X-------XXX---- = ----XX--------XXXXXX--------

sprite58:
.byte $00, $E1                                  ; --------XXX----X = ----------------XXXXXX------
.byte $00, $B1                                  ; --------X-XX---X = --------------XXXX--XX------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $08, $60                                  ; ----X----XX----- = ------------XX--XXXX--------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $0C, $70                                  ; ----XX---XXX---- = ----------XXXXXXXXXX--------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $0C, $F1                                  ; ----XX--XXXX---X = ----------XXXXXXXXXXXX------
.byte $0C, $F1                                  ; ----XX--XXXX---X = ----------XXXXXXXXXXXX------
.byte $0E, $E3                                  ; ----XXX-XXX---XX = --------XXXXXX--XXXXXXXX----
.byte $06, $F3                                  ; -----XX-XXXX--XX = --------XXXX--XXXXXXXXXX----
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $0C, $E1                                  ; ----XX--XXX----X = ----------XXXX--XXXXXX------
.byte $0C, $D1                                  ; ----XX--XX-X---X = ----------XXXXXX--XXXX------
.byte $0E, $E1                                  ; ----XXX-XXX----X = --------XXXXXX--XXXXXX------

sprite59:
.byte $00, $C3                                  ; --------XX----XX = ------------------XXXXXX----
.byte $00, $62                                  ; ---------XX---X- = ----------------XXXX--XX----
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $00, $D1                                  ; --------XX-X---X = --------------XX--XXXX------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $08, $F1                                  ; ----X---XXXX---X = ------------XXXXXXXXXX------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $08, $F3                                  ; ----X---XXXX--XX = ------------XXXXXXXXXXXX----
.byte $08, $B3                                  ; ----X---X-XX--XX = ------------XXXXXX--XXXX----
.byte $08, $B3                                  ; ----X---X-XX--XX = ------------XXXXXX--XXXX----
.byte $08, $D3                                  ; ----X---XX-X--XX = ------------XXXX--XXXXXX----
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $70                                  ; ---------XXX---- = --------------XXXXXX--------

sprite5A:
.byte $00, $87                                  ; --------X----XXX = --------------------XXXXXX--
.byte $00, $C5                                  ; --------XX---X-X = ------------------XXXX--XX--
.byte $00, $E7                                  ; --------XXX--XXX = ----------------XXXXXXXXXX--
.byte $00, $A3                                  ; --------X-X---XX = ----------------XX--XXXX----
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $00, $F3                                  ; --------XXXX--XX = --------------XXXXXXXXXX----
.byte $00, $C1                                  ; --------XX-----X = ------------------XXXX------
.byte $00, $E3                                  ; --------XXX---XX = ----------------XXXXXXXX----
.byte $00, $F7                                  ; --------XXXX-XXX = --------------XXXXXXXXXXXX--
.byte $00, $F7                                  ; --------XXXX-XXX = --------------XXXXXXXXXXXX--
.byte $08, $BF                                  ; ----X---X-XXXXXX = ------------XXXXXX--XXXXXXXX
.byte $08, $DF                                  ; ----X---XX-XXXXX = ------------XXXX--XXXXXXXXXX
.byte $00, $E3                                  ; --------XXX---XX = ----------------XXXXXXXX----
.byte $00, $B7                                  ; --------X-XX-XXX = --------------XXXX--XXXXXX--
.byte $00, $76                                  ; ---------XXX-XX- = --------------XXXXXX--XXXX--
.byte $08, $B7                                  ; ----X---X-XX-XXX = ------------XXXXXX--XXXXXX--

sprite5B:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $68, $16                                  ; -XX-X------X-XX- = --XXXX------XXXX------XXXX--
.byte $7A, $5E                                  ; -XXXX-X--X-XXXX- = XXXXXX--XX--XXXX--XX--XXXXXX
.byte $72, $4E                                  ; -XXX--X--X--XXX- = XXXXXX--XX--------XX--XXXXXX
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $8B, $D1                                  ; X---X-XXXX-X---X = ------XXXX--XXXX--XXXX------
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----

sprite5C:
.byte $C7, $00                                  ; XX---XXX-------- = ----XXXXXXXX----------------
.byte $EF, $10                                  ; XXX-XXXX---X---- = --XXXXXXXXXXXXXX------------
.byte $EF, $F1                                  ; XXX-XXXXXXXX---X = --XXXXXXXXXXXXXXXXXXXX------
.byte $68, $16                                  ; -XX-X------X-XX- = --XXXX------XXXX------XXXX--
.byte $02, $5E                                  ; ------X--X-XXXX- = --------XX----XX--XX--XXXXXX
.byte $02, $4E                                  ; ------X--X--XXX- = --------XX--------XX--XXXXXX
.byte $0E, $7E                                  ; ----XXX--XXXXXX- = --------XXXXXXXXXXXX--XXXXXX
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $8B, $D1                                  ; X---X-XXXX-X---X = ------XXXX--XXXX--XXXX------
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----

sprite5D:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $68, $16                                  ; -XX-X------X-XX- = --XXXX------XXXX------XXXX--
.byte $7A, $5E                                  ; -XXXX-X--X-XXXX- = XXXXXX--XX--XXXX--XX--XXXXXX
.byte $72, $4E                                  ; -XXX--X--X--XXX- = XXXXXX--XX--------XX--XXXXXX
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $8B, $D1                                  ; X---X-XXXX-X---X = ------XXXX--XXXX--XXXX------
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----

sprite5E:
.byte $00, $E3                                  ; --------XXX---XX = ----------------XXXXXXXX----
.byte $08, $F7                                  ; ----X---XXXX-XXX = ------------XXXXXXXXXXXXXX--
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $68, $16                                  ; -XX-X------X-XX- = --XXXX------XXXX------XXXX--
.byte $7A, $40                                  ; -XXXX-X--X------ = XXXXXX--XX--XX----XX--------
.byte $72, $40                                  ; -XXX--X--X------ = XXXXXX--XX--------XX--------
.byte $7E, $70                                  ; -XXXXXX--XXX---- = XXXXXX--XXXXXXXXXXXX--------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $06, $60                                  ; -----XX--XX----- = --------XXXX----XXXX--------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $8B, $D1                                  ; X---X-XXXX-X---X = ------XXXX--XXXX--XXXX------
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----

sprite5F:
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $8D, $00                                  ; X---XX-X-------- = ------XX--XXXX--------------
.byte $46, $10                                  ; -X---XX----X---- = ----XX--XXXX--XX------------
.byte $26, $20                                  ; --X--XX---X----- = --XX----XXXX----XX----------
.byte $16, $40                                  ; ---X-XX--X------ = XX------XXXX------XX--------
.byte $16, $40                                  ; ---X-XX--X------ = XX------XXXX------XX--------
.byte $26, $20                                  ; --X--XX---X----- = --XX----XXXX----XX----------
.byte $46, $10                                  ; -X---XX----X---- = ----XX--XXXX--XX------------
.byte $8D, $00                                  ; X---XX-X-------- = ------XX--XXXX--------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $CD, $10                                  ; XX--XX-X---X---- = ----XXXX--XXXXXX------------
.byte $26, $00                                  ; --X--XX--------- = --XX----XXXX----------------
.byte $EF, $70                                  ; XXX-XXXX-XXX---- = --XXXXXXXXXXXXXXXXXX--------
.byte $FF, $70                                  ; XXXXXXXX-XXX---- = XXXXXXXXXXXXXXXXXXXX--------
.byte $20, $20                                  ; --X-------X----- = --XX------------XX----------
.byte $4E, $00                                  ; -X--XXX--------- = ----XX--XXXXXX--------------

sprite60:
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $04, $30                                  ; -----X----XX---- = ----------XX--XXXX----------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $04, $30                                  ; -----X----XX---- = ----------XX--XXXX----------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $0E, $60                                  ; ----XXX--XX----- = --------XXXXXX--XXXX--------
.byte $08, $91                                  ; ----X---X--X---X = ------------XXXX----XX------
.byte $CF, $F1                                  ; XX--XXXXXXXX---X = ----XXXXXXXXXXXXXXXXXX------
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $81, $81                                  ; X------XX------X = ------XX------------XX------
.byte $0C, $50                                  ; ----XX---X-X---- = ----------XXXXXX--XX--------

sprite61:
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $10                                  ; -----------X---- = --------------XX------------
.byte $00, $10                                  ; -----------X---- = --------------XX------------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $08, $B1                                  ; ----X---X-XX---X = ------------XXXXXX--XX------
.byte $02, $32                                  ; ------X---XX--X- = --------XX----XXXX----XX----
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $8F, $F3                                  ; X---XXXXXXXX--XX = ------XXXXXXXXXXXXXXXXXX----
.byte $00, $02                                  ; --------------X- = ----------------------XX----
.byte $0C, $D1                                  ; ----XX--XX-X---X = ----------XXXXXX--XXXX------

sprite62:
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $B1                                  ; --------X-XX---X = --------------XXXX--XX------
.byte $08, $62                                  ; ----X----XX---X- = ------------XX--XXXX--XX----
.byte $08, $62                                  ; ----X----XX---X- = ------------XX--XXXX--XX----
.byte $04, $64                                  ; -----X---XX--X-- = ----------XX----XXXX----XX--
.byte $04, $64                                  ; -----X---XX--X-- = ----------XX----XXXX----XX--
.byte $08, $62                                  ; ----X----XX---X- = ------------XX--XXXX--XX----
.byte $08, $62                                  ; ----X----XX---X- = ------------XX--XXXX--XX----
.byte $00, $B1                                  ; --------X-XX---X = --------------XXXX--XX------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $08, $E1                                  ; ----X---XXX----X = ------------XX--XXXXXX------
.byte $04, $64                                  ; -----X---XX--X-- = ----------XX----XXXX----XX--
.byte $0E, $FF                                  ; ----XXX-XXXXXXXX = --------XXXXXXXXXXXXXXXXXXXX
.byte $0C, $FF                                  ; ----XX--XXXXXXXX = ----------XXXXXXXXXXXXXXXXXX
.byte $04, $00                                  ; -----X---------- = ----------XX----------------
.byte $08, $D3                                  ; ----X---XX-X--XX = ------------XXXX--XXXXXX----

sprite63:
.byte $00, $00                                  ; ---------------- = ---------------------------- 
.byte $00, $00                                  ; ---------------- = ---------------------------- 
.byte $00, $00                                  ; ---------------- = ---------------------------- 
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX---------- 
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------ 
.byte $40, $02                                  ; -X------------X- = ----XX----------------XX---- 
.byte $20, $04                                  ; --X----------X-- = --XX--------------------XX-- 
.byte $10, $08                                  ; ---X--------X--- = XX------------------------XX 
.byte $10, $08                                  ; ---X--------X--- = XX------------------------XX 
.byte $10, $08                                  ; ---X--------X--- = XX------------------------XX 
.byte $20, $04                                  ; --X----------X-- = --XX--------------------XX-- 
.byte $50, $0A                                  ; -X-X--------X-X- = XX--XX----------------XX--XX 
.byte $A3, $C5                                  ; X-X---XXXX---X-X = --XX--XXXX--------XXXX--XX-- 
.byte $9D, $B9                                  ; X--XXX-XX-XXX--X = XX----XX--XXXXXXXX--XX----XX 
.byte $44, $22                                  ; -X---X----X---X- = ----XX----XX----XX----XX---- 
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX---------- 

sprite64:
.byte $00, $00                                  ; ---------------- = ---------------------------- 
.byte $00, $00                                  ; ---------------- = ---------------------------- 
.byte $00, $00                                  ; ---------------- = ---------------------------- 
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX---------- 
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------ 
.byte $40, $02                                  ; -X------------X- = ----XX----------------XX---- 
.byte $20, $04                                  ; --X----------X-- = --XX--------------------XX-- 
.byte $10, $08                                  ; ---X--------X--- = XX------------------------XX 
.byte $F1, $8F                                  ; XXXX---XX---XXXX = XXXXXXXX------------XXXXXXXX 
.byte $5E, $7A                                  ; -X-XXXX--XXXX-X- = XX--XX--XXXXXXXXXXXX--XX--XX 
.byte $AD, $B5                                  ; X-X-XX-XX-XX-X-X = --XX--XX--XXXXXXXX--XX--XX-- 
.byte $44, $22                                  ; -X---X----X---X- = ----XX----XX----XX----XX---- 
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------ 
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX---------- 
.byte $00, $00                                  ; ---------------- = ---------------------------- 
.byte $00, $00                                  ; ---------------- = ---------------------------- 

sprite65:
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX-------- 
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX-------- 
.byte $44, $22                                  ; -X---X----X---X- = ----XX----XX----XX----XX---- 
.byte $9D, $B9                                  ; X--XXX-XX-XXX--X = XX----XX--XXXXXXXX--XX----XX 
.byte $A3, $C5                                  ; X-X---XXXX---X-X = --XX--XXXX--------XXXX--XX-- 
.byte $4C, $32                                  ; -X--XX----XX--X- = ----XX----XXXXXXXX----XX---- 
.byte $2E, $74                                  ; --X-XXX--XXX-X-- = --XX----XXXXXXXXXXXX----XX-- 
.byte $16, $68                                  ; ---X-XX--XX-X--- = XX------XXXX----XXXX------XX 
.byte $16, $68                                  ; ---X-XX--XX-X--- = XX------XXXX----XXXX------XX 
.byte $1E, $78                                  ; ---XXXX--XXXX--- = XX------XXXXXXXXXXXX------XX 
.byte $2C, $34                                  ; --X-XX----XX-X-- = --XX------XXXXXXXX------XX-- 
.byte $40, $02                                  ; -X------------X- = ----XX----------------XX---- 
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------ 
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX---------- 
.byte $00, $00                                  ; ---------------- = ---------------------------- 
.byte $00, $00                                  ; ---------------- = ---------------------------- 

sprite66:
.byte $00, $00                                  ; ---------------- = ---------------------------- 
.byte $00, $00                                  ; ---------------- = ---------------------------- 
.byte $00, $00                                  ; ---------------- = ---------------------------- 
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX---------- 
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------ 
.byte $44, $22                                  ; -X---X----X---X- = ----XX----XX----XX----XX---- 
.byte $A5, $A5                                  ; X-X--X-XX-X--X-X = --XX--XX--XX----XX--XX--XX-- 
.byte $DF, $FB                                  ; XX-XXXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX 
.byte $76, $EF                                  ; -XXX-XX-XXX-XXXX = XXXXXX--XXXX----XXXXXXXXXXXX 
.byte $1E, $78                                  ; ---XXXX--XXXX--- = XX------XXXXXXXXXXXX------XX 
.byte $2C, $34                                  ; --X-XX----XX-X-- = --XX------XXXXXXXX------XX-- 
.byte $40, $02                                  ; -X------------X- = ----XX----------------XX---- 
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------ 
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX---------- 
.byte $00, $00                                  ; ---------------- = ---------------------------- 
.byte $00, $00                                  ; ---------------- = ---------------------------- 

sprite67:
.byte $60, $30                                  ; -XX-------XX---- = --XXXX--------XXXX----------
.byte $D9, $40                                  ; XX-XX--X-X------ = XX--XXXX----XX----XX--------
.byte $D9, $70                                  ; XX-XX--X-XXX---- = XX--XXXX----XXXXXXXX--------
.byte $60, $30                                  ; -XX-------XX---- = --XXXX--------XXXX----------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $FF, $70                                  ; XXXXXXXX-XXX---- = XXXXXXXXXXXXXXXXXXXX--------
.byte $A9, $20                                  ; X-X-X--X--X----- = --XX--XX----XX--XX----------
.byte $89, $00                                  ; X---X--X-------- = ------XX----XX--------------
.byte $89, $00                                  ; X---X--X-------- = ------XX----XX--------------
.byte $8F, $00                                  ; X---XXXX-------- = ------XXXXXXXX--------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $8F, $00                                  ; X---XXXX-------- = ------XXXXXXXX--------------
.byte $CF, $10                                  ; XX--XXXX---X---- = ----XXXXXXXXXXXX------------

sprite68:
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------
.byte $44, $62                                  ; -X---X---XX---X- = ----XX----XX----XXXX--XX----
.byte $C7, $62                                  ; XX---XXX-XX---X- = ----XXXXXXXX----XXXX--XX----
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $85, $A1                                  ; X----X-XX-X----X = ------XX--XX----XX--XX------
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite69:
.byte $06, $83                                  ; -----XX-X-----XX = --------XXXX--------XXXX----
.byte $8B, $C7                                  ; X---X-XXXX---XXX = ------XXXX--XX----XXXXXXXX--
.byte $8B, $44                                  ; X---X-XX-X---X-- = ------XXXX--XX----XX----XX--
.byte $06, $83                                  ; -----XX-X-----XX = --------XXXX--------XXXX----
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $0A, $42                                  ; ----X-X--X----X- = --------XX--XX----XX--XX----
.byte $08, $40                                  ; ----X----X------ = ------------XX----XX--------
.byte $08, $40                                  ; ----X----X------ = ------------XX----XX--------
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $0C, $F1                                  ; ----XX--XXXX---X = ----------XXXXXXXXXXXX------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite6A:
.byte $0C, $06                                  ; ----XX-------XX- = ----------XXXX--------XXXX--
.byte $0E, $9D                                  ; ----XXX-X--XXX-X = --------XXXXXXXX----XX--XXXX
.byte $02, $9D                                  ; ------X-X--XXX-X = --------XX----XX----XX--XXXX
.byte $0C, $06                                  ; ----XX-------XX- = ----------XXXX--------XXXX--
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $0E, $FF                                  ; ----XXX-XXXXXXXX = --------XXXXXXXXXXXXXXXXXXXX
.byte $04, $95                                  ; -----X--X--X-X-X = ----------XX--XX----XX--XX--
.byte $00, $91                                  ; --------X--X---X = --------------XX----XX------
.byte $00, $91                                  ; --------X--X---X = --------------XX----XX------
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $08, $F3                                  ; ----X---XXXX--XX = ------------XXXXXXXXXXXX----
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite6B:
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $5A, $5A                                  ; -X-XX-X--X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $89, $91                                  ; X---X--XX--X---X = ------XX----XXXX----XX------
.byte $42, $42                                  ; -X----X--X----X- = ----XX--XX--------XX--XX----
.byte $85, $A1                                  ; X----X-XX-X----X = ------XX--XX----XX--XX------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $85, $A1                                  ; X----X-XX-X----X = ------XX--XX----XX--XX------
.byte $42, $42                                  ; -X----X--X----X- = ----XX--XX--------XX--XX----
.byte $81, $81                                  ; X------XX------X = ------XX------------XX------

sprite6C:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $5A, $5A                                  ; -X-XX-X--X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $89, $91                                  ; X---X--XX--X---X = ------XX----XXXX----XX------
.byte $42, $42                                  ; -X----X--X----X- = ----XX--XX--------XX--XX----
.byte $85, $A1                                  ; X----X-XX-X----X = ------XX--XX----XX--XX------
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $04, $20                                  ; -----X----X----- = ----------XX----XX----------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $44, $20                                  ; -X---X----X----- = ----XX----XX----XX----------
.byte $2A, $52                                  ; --X-X-X--X-X--X- = --XX----XX--XXXX--XX--XX----
.byte $85, $A5                                  ; X----X-XX-X--X-X = ------XX--XX----XX--XX--XX--

sprite6D:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $0E                                  ; ------------XXX- = ----------------------XXXXXX
.byte $08, $FB                                  ; ----X---XXXXX-XX = ------------XXXXXXXXXXXX--XX
.byte $FF, $5E                                  ; XXXXXXXX-X-XXXX- = XXXXXXXXXXXXXXXX--XX--XXXXXX
.byte $5A, $F1                                  ; -X-XX-X-XXXX---X = XX--XX--XX--XXXXXXXXXX------
.byte $FF, $10                                  ; XXXXXXXX---X---- = XXXXXXXXXXXXXXXX------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $85, $22                                  ; X----X-X--X---X- = ------XX--XX----XX----XX----
.byte $2A, $54                                  ; --X-X-X--X-X-X-- = --XX----XX--XXXX--XX----XX--
.byte $04, $22                                  ; -----X----X---X- = ----------XX----XX----XX----
.byte $48, $14                                  ; -X--X------X-X-- = ----XX------XXXX--------XX--
.byte $0A, $50                                  ; ----X-X--X-X---- = --------XX--XXXX--XX--------
.byte $44, $A1                                  ; -X---X--X-X----X = ----XX----XX----XX--XX------

sprite6E:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $20                                  ; ----------X----- = ----------------XX----------
.byte $08, $04                                  ; ----X--------X-- = ------------XX----------XX--
.byte $00, $4A                                  ; ---------X--X-X- = ------------------XX--XX--XX
.byte $08, $97                                  ; ----X---X--X-XXX = ------------XXXX----XXXXXX--
.byte $0E, $52                                  ; ----XXX--X-X--X- = --------XXXXXXXX--XX--XX----
.byte $3A, $91                                  ; --XXX-X-X--X---X = XXXX----XX--XXXX----XX------
.byte $DD, $14                                  ; XX-XXX-X---X-X-- = XX--XXXX--XXXXXX--------XX--
.byte $78, $91                                  ; -XXXX---X--X---X = XXXXXX------XXXX----XX------
.byte $C1, $08                                  ; XX-----X----X--- = ----XXXX------------------XX
.byte $0C, $32                                  ; ----XX----XX--X- = ----------XXXXXXXX----XX----
.byte $38, $91                                  ; --XXX---X--X---X = XXXX--------XXXX----XX------
.byte $8D, $14                                  ; X---XX-X---X-X-- = ------XX--XXXXXX--------XX--
.byte $48, $F3                                  ; -X--X---XXXX--XX = ----XX------XXXXXXXXXXXX----

sprite6F:
.byte $00, $00                                  ; ---------------- = --------------------------
.byte $00, $00                                  ; ---------------- = --------------------------
.byte $00, $00                                  ; ---------------- = --------------------------
.byte $02, $10                                  ; ------X----X---- = --------XX----XX----------
.byte $00, $00                                  ; ---------------- = --------------------------
.byte $00, $00                                  ; ---------------- = --------------------------
.byte $40, $02                                  ; -X------------X- = ----XX----------------XX--
.byte $00, $24                                  ; ----------X--X-- = ----------------XX------XX
.byte $08, $42                                  ; ----X----X----X- = ------------XX----XX--XX--
.byte $0E, $20                                  ; ----XXX---X----- = --------XXXXXX--XX--------
.byte $2A, $00                                  ; --X-X-X--------- = --XX----XX--XX------------
.byte $CD, $02                                  ; XX--XX-X------X- = ----XXXX--XXXX--------XX--
.byte $68, $00                                  ; -XX-X----------- = --XXXX------XX------------
.byte $C1, $04                                  ; XX-----X-----X-- = ----XXXX----------------XX
.byte $04, $12                                  ; -----X-----X--X- = ----------XX--XX------XX--
.byte $38, $81                                  ; --XXX---X------X = XXXX--------XX------XX----

sprite70:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $08, $00                                  ; ----X----------- = ------------XX--------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $20                                  ; ----------X----- = ----------------XX----------
.byte $81, $81                                  ; X------XX------X = ------XX------------XX------
.byte $0A, $02                                  ; ----X-X-------X- = --------XX--XX--------XX----
.byte $00, $20                                  ; ----------X----- = ----------------XX----------
.byte $64, $00                                  ; -XX--X---------- = --XXXX----XX----------------
.byte $48, $B1                                  ; -X--X---X-XX---X = ----XX------XXXXXX--XX------
.byte $02, $20                                  ; ------X---X----- = --------XX------XX----------
.byte $08, $50                                  ; ----X----X-X---- = ------------XXXX--XX--------
.byte $8D, $30                                  ; X---XX-X--XX---- = ------XX--XXXXXXXX----------

sprite71:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $08, $00                                  ; ----X----------- = ------------XX--------------
.byte $00, $20                                  ; ----------X----- = ----------------XX----------
.byte $81, $00                                  ; X------X-------- = ------XX--------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $04, $40                                  ; -----X---X------ = ----------XX------XX--------
.byte $00, $B1                                  ; --------X-XX---X = --------------XXXX--XX------
.byte $48, $20                                  ; -X--X-----X----- = ----XX------XX--XX----------
.byte $06, $50                                  ; -----XX--X-X---- = --------XXXX--XX--XX--------

sprite72:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $20                                  ; ----------X----- = ----------------XX----------
.byte $02, $00                                  ; ------X--------- = --------XX------------------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------

sprite73:
.byte $60, $06                                  ; -XX----------XX- = --XXXX----------------XXXX--
.byte $9F, $F9                                  ; X--XXXXXXXXXX--X = XX----XXXXXXXXXXXXXXXX----XX
.byte $9F, $F9                                  ; X--XXXXXXXXXX--X = XX----XXXXXXXXXXXXXXXX----XX
.byte $60, $06                                  ; -XX----------XX- = --XXXX----------------XXXX--
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $10, $08                                  ; ---X--------X--- = XX------------------------XX
.byte $5A, $A9                                  ; -X-XX-X-X-X-X--X = XX--XX--XX--XX--XX--XX----XX
.byte $9F, $FB                                  ; X--XXXXXXXXXX-XX = XX----XXXXXXXXXXXXXXXXXX--XX
.byte $D5, $D9                                  ; XX-X-X-XXX-XX--X = XX--XXXX--XX--XX--XXXX----XX
.byte $91, $8B                                  ; X--X---XX---X-XX = XX----XX------------XXXX--XX
.byte $D5, $D9                                  ; XX-X-X-XXX-XX--X = XX--XXXX--XX--XX--XXXX----XX
.byte $9F, $FB                                  ; X--XXXXXXXXXX-XX = XX----XXXXXXXXXXXXXXXXXX--XX
.byte $5A, $A9                                  ; -X-XX-X-X-X-X--X = XX--XX--XX--XX--XX--XX----XX
.byte $10, $08                                  ; ---X--------X--- = XX------------------------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

sprite74:
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $48, $72                                  ; -X--X----XXX--X- = ----XX------XXXXXXXX--XX----
.byte $48, $72                                  ; -X--X----XXX--X- = ----XX------XXXXXXXX--XX----
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $B5, $5A                                  ; X-XX-X-X-X-XX-X- = XXXX--XX--XX--XX--XX--XX--XX
.byte $DF, $FF                                  ; XX-XXXXXXXXXXXXX = XX--XXXXXXXXXXXXXXXXXXXXXXXX
.byte $7A, $AB                                  ; -XXXX-X-X-X-X-XX = XXXXXX--XX--XX--XX--XXXX--XX
.byte $D1, $0E                                  ; XX-X---X----XXX- = XX--XXXX--------------XXXXXX
.byte $74, $9B                                  ; -XXX-X--X--XX-XX = XXXXXX----XX--XX----XXXX--XX
.byte $D1, $0E                                  ; XX-X---X----XXX- = XX--XXXX--------------XXXXXX
.byte $7A, $AB                                  ; -XXXX-X-X-X-X-XX = XXXXXX--XX--XX--XX--XXXX--XX
.byte $DF, $FF                                  ; XX-XXXXXXXXXXXXX = XX--XXXXXXXXXXXXXXXXXXXXXXXX
.byte $B5, $5A                                  ; X-XX-X-X-X-XX-X- = XXXX--XX--XX--XX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

sprite75:
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $B5, $5E                                  ; X-XX-X-X-X-XXXX- = XXXX--XX--XX--XX--XX--XXXXXX
.byte $70, $0C                                  ; -XXX--------XX-- = XXXXXX------------------XXXX
.byte $3A, $2E                                  ; --XXX-X---X-XXX- = XXXX----XX--XX--XX----XXXXXX
.byte $7C, $7C                                  ; -XXXXX---XXXXX-- = XXXXXX----XXXXXXXXXX----XXXX
.byte $3A, $2E                                  ; --XXX-X---X-XXX- = XXXX----XX--XX--XX----XXXXXX
.byte $70, $0C                                  ; -XXX--------XX-- = XXXXXX------------------XXXX
.byte $B5, $5E                                  ; X-XX-X-X-X-XXXX- = XXXX--XX--XX--XX--XX--XXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

sprite76:
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $4E, $12                                  ; -X--XXX----X--X- = ----XX--XXXXXXXX------XX----
.byte $4E, $12                                  ; -X--XXX----X--X- = ----XX--XXXXXXXX------XX----
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $5A, $AD                                  ; -X-XX-X-X-X-XX-X = XX--XX--XX--XX--XX--XX--XXXX
.byte $30, $08                                  ; --XX--------X--- = XXXX----------------------XX
.byte $95, $5C                                  ; X--X-X-X-X-XXX-- = XX----XX--XX--XX--XX----XXXX
.byte $3E, $F9                                  ; --XXXXX-XXXXX--X = XXXX----XXXXXXXXXXXXXX----XX
.byte $9B, $6C                                  ; X--XX-XX-XX-XX-- = XX----XXXX--XX--XXXX----XXXX
.byte $3E, $F9                                  ; --XXXXX-XXXXX--X = XXXX----XXXXXXXXXXXXXX----XX
.byte $95, $5C                                  ; X--X-X-X-X-XXX-- = XX----XX--XX--XX--XX----XXXX
.byte $30, $08                                  ; --XX--------X--- = XXXX----------------------XX
.byte $5A, $AD                                  ; -X-XX-X-X-X-XX-X = XX--XX--XX--XX--XX--XX--XXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

sprite77:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $FF, $70                                  ; XXXXXXXX-XXX---- = XXXXXXXXXXXXXXXXXXXX--------
.byte $10, $70                                  ; ---X-----XXX---- = XX------------XXXXXX--------
.byte $FF, $70                                  ; XXXXXXXX-XXX---- = XXXXXXXXXXXXXXXXXXXX--------
.byte $18, $40                                  ; ---XX----X------ = XX----------XX----XX--------
.byte $FF, $40                                  ; XXXXXXXX-X------ = XXXXXXXXXXXXXX----XX--------
.byte $FF, $70                                  ; XXXXXXXX-XXX---- = XXXXXXXXXXXXXXXXXXXX--------

sprite78:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $40, $C3                                  ; -X------XX----XX = ----XX------------XXXXXX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $40, $22                                  ; -X--------X---X- = ----XX----------XX----XX----
.byte $CF, $32                                  ; XX--XXXX--XX--X- = ----XXXXXXXXXXXXXX----XX----
.byte $CF, $F3                                  ; XX--XXXXXXXX--XX = ----XXXXXXXXXXXXXXXXXXXX----
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite79:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $81, $87                                  ; X------XX----XXX = ------XX------------XXXXXX--
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $81, $44                                  ; X------X-X---X-- = ------XX----------XX----XX--
.byte $8F, $74                                  ; X---XXXX-XXX-X-- = ------XXXXXXXXXXXXXX----XX--
.byte $8F, $F7                                  ; X---XXXXXXXX-XXX = ------XXXXXXXXXXXXXXXXXXXX--
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite7A:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $0E, $FF                                  ; ----XXX-XXXXXXXX = --------XXXXXXXXXXXXXXXXXXXX
.byte $02, $0E                                  ; ------X-----XXX- = --------XX------------XXXXXX
.byte $0E, $FF                                  ; ----XXX-XXXXXXXX = --------XXXXXXXXXXXXXXXXXXXX
.byte $02, $89                                  ; ------X-X---X--X = --------XX----------XX----XX
.byte $0E, $F9                                  ; ----XXX-XXXXX--X = --------XXXXXXXXXXXXXX----XX
.byte $0E, $FF                                  ; ----XXX-XXXXXXXX = --------XXXXXXXXXXXXXXXXXXXX
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite7B:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $02, $00                                  ; ------X--------- = --------XX------------------
.byte $85, $00                                  ; X----X-X-------- = ------XX--XX----------------
.byte $4A, $00                                  ; -X--X-X--------- = ----XX--XX--XX--------------
.byte $A5, $10                                  ; X-X--X-X---X---- = --XX--XX--XX--XX------------
.byte $2A, $00                                  ; --X-X-X--------- = --XX----XX--XX--------------
.byte $14, $00                                  ; ---X-X---------- = XX--------XX----------------
.byte $10, $60                                  ; ---X-----XX----- = XX--------------XXXX--------
.byte $10, $60                                  ; ---X-----XX----- = XX--------------XXXX--------
.byte $20, $10                                  ; --X--------X---- = --XX----------XX------------
.byte $EF, $30                                  ; XXX-XXXX--XX---- = --XXXXXXXXXXXXXXXX----------
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $8F, $30                                  ; X---XXXX--XX---- = ------XXXXXXXXXXXX----------
.byte $0E, $10                                  ; ----XXX----X---- = --------XXXXXXXX------------
.byte $0A, $20                                  ; ----X-X---X----- = --------XX--XX--XX----------
.byte $89, $40                                  ; X---X--X-X------ = ------XX----XX----XX--------

sprite7C:
.byte $4A, $00                                  ; -X--X-X--------- = ----XX--XX--XX--------------
.byte $85, $10                                  ; X----X-X---X---- = ------XX--XX--XX------------
.byte $4A, $00                                  ; -X--X-X--------- = ----XX--XX--XX--------------
.byte $85, $10                                  ; X----X-X---X---- = ------XX--XX--XX------------
.byte $40, $00                                  ; -X-------------- = ----XX----------------------
.byte $40, $00                                  ; -X-------------- = ----XX----------------------
.byte $40, $00                                  ; -X-------------- = ----XX----------------------
.byte $40, $83                                  ; -X------X-----XX = ----XX--------------XXXX----
.byte $40, $83                                  ; -X------X-----XX = ----XX--------------XXXX----
.byte $81, $40                                  ; X------X-X------ = ------XX----------XX--------
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $0E, $F3                                  ; ----XXX-XXXX--XX = --------XXXXXXXXXXXXXXXX----
.byte $0C, $F1                                  ; ----XX--XXXX---X = ----------XXXXXXXXXXXX------
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $08, $A1                                  ; ----X---X-X----X = ------------XX--XX--XX------
.byte $04, $22                                  ; -----X----X---X- = ----------XX----XX----XX----

sprite7D:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $40, $00                                  ; -X-------------- = ----XX----------------------
.byte $A1, $00                                  ; X-X----X-------- = --XX--XX--------------------
.byte $52, $00                                  ; -X-X--X--------- = XX--XX--XX------------------
.byte $A5, $00                                  ; X-X--X-X-------- = --XX--XX--XX----------------
.byte $58, $00                                  ; -X-XX----------- = XX--XX------XX--------------
.byte $28, $00                                  ; --X-X----------- = --XX--------XX--------------
.byte $08, $06                                  ; ----X--------XX- = ------------XX--------XXXX--
.byte $04, $06                                  ; -----X-------XX- = ----------XX----------XXXX--
.byte $04, $81                                  ; -----X--X------X = ----------XX--------XX------
.byte $0C, $F3                                  ; ----XX--XXXX--XX = ----------XXXXXXXXXXXXXX----
.byte $0C, $F7                                  ; ----XX--XXXX-XXX = ----------XXXXXXXXXXXXXXXX--
.byte $08, $F3                                  ; ----X---XXXX--XX = ------------XXXXXXXXXXXX----
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $00, $52                                  ; ---------X-X--X- = --------------XX--XX--XX----
.byte $08, $44                                  ; ----X----X---X-- = ------------XX----XX----XX--

sprite7E:
.byte $85, $10                                  ; X----X-X---X---- = ------XX--XX--XX------------
.byte $4A, $00                                  ; -X--X-X--------- = ----XX--XX--XX--------------
.byte $85, $10                                  ; X----X-X---X---- = ------XX--XX--XX------------
.byte $4A, $00                                  ; -X--X-X--------- = ----XX--XX--XX--------------
.byte $00, $10                                  ; -----------X---- = --------------XX------------
.byte $00, $10                                  ; -----------X---- = --------------XX------------
.byte $00, $10                                  ; -----------X---- = --------------XX------------
.byte $00, $1C                                  ; -----------XXX-- = --------------XX--------XXXX
.byte $08, $0C                                  ; ----X-------XX-- = ------------XX----------XXXX
.byte $08, $02                                  ; ----X---------X- = ------------XX--------XX----
.byte $08, $F7                                  ; ----X---XXXX-XXX = ------------XXXXXXXXXXXXXX--
.byte $08, $FF                                  ; ----X---XXXXXXXX = ------------XXXXXXXXXXXXXXXX
.byte $00, $F7                                  ; --------XXXX-XXX = --------------XXXXXXXXXXXX--
.byte $00, $E3                                  ; --------XXX---XX = ----------------XXXXXXXX----
.byte $00, $A5                                  ; --------X-X--X-X = ----------------XX--XX--XX--
.byte $00, $99                                  ; --------X--XX--X = --------------XX----XX----XX

sprite7F:
.byte $08, $A1                                  ; ----X---X-X----X = ------------XX--XX--XX------
.byte $00, $52                                  ; ---------X-X--X- = --------------XX--XX--XX----
.byte $08, $A1                                  ; ----X---X-X----X = ------------XX--XX--XX------
.byte $00, $52                                  ; ---------X-X--X- = --------------XX--XX--XX----
.byte $08, $00                                  ; ----X----------- = ------------XX--------------
.byte $08, $00                                  ; ----X----------- = ------------XX--------------
.byte $08, $00                                  ; ----X----------- = ------------XX--------------
.byte $38, $00                                  ; --XXX----------- = XXXX--------XX--------------
.byte $30, $10                                  ; --XX-------X---- = XXXX----------XX------------
.byte $40, $10                                  ; -X---------X---- = ----XX--------XX------------
.byte $EF, $10                                  ; XXX-XXXX---X---- = --XXXXXXXXXXXXXX------------
.byte $FF, $10                                  ; XXXXXXXX---X---- = XXXXXXXXXXXXXXXX------------
.byte $EF, $00                                  ; XXX-XXXX-------- = --XXXXXXXXXXXX--------------
.byte $C7, $00                                  ; XX---XXX-------- = ----XXXXXXXX----------------
.byte $A5, $00                                  ; X-X--X-X-------- = --XX--XX--XX----------------
.byte $99, $00                                  ; X--XX--X-------- = XX----XX----XX--------------

sprite80:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $02                                  ; --------------X- = ----------------------XX----
.byte $00, $85                                  ; --------X----X-X = --------------------XX--XX--
.byte $00, $4A                                  ; ---------X--X-X- = ------------------XX--XX--XX
.byte $00, $A5                                  ; --------X-X--X-X = ----------------XX--XX--XX--
.byte $00, $1A                                  ; -----------XX-X- = --------------XX------XX--XX
.byte $00, $14                                  ; -----------X-X-- = --------------XX--------XX--
.byte $60, $10                                  ; -XX--------X---- = --XXXX--------XX------------
.byte $60, $20                                  ; -XX-------X----- = --XXXX----------XX----------
.byte $81, $20                                  ; X------X--X----- = ------XX--------XX----------
.byte $CF, $30                                  ; XX--XXXX--XX---- = ----XXXXXXXXXXXXXX----------
.byte $EF, $30                                  ; XXX-XXXX--XX---- = --XXXXXXXXXXXXXXXX----------
.byte $CF, $10                                  ; XX--XXXX---X---- = ----XXXXXXXXXXXX------------
.byte $8F, $00                                  ; X---XXXX-------- = ------XXXXXXXX--------------
.byte $4A, $00                                  ; -X--X-X--------- = ----XX--XX--XX--------------
.byte $22, $10                                  ; --X---X----X---- = --XX----XX----XX------------

sprite81:
.byte $00, $52                                  ; ---------X-X--X- = --------------XX--XX--XX----
.byte $08, $A1                                  ; ----X---X-X----X = ------------XX--XX--XX------
.byte $00, $52                                  ; ---------X-X--X- = --------------XX--XX--XX----
.byte $08, $A1                                  ; ----X---X-X----X = ------------XX--XX--XX------
.byte $00, $02                                  ; --------------X- = ----------------------XX----
.byte $00, $02                                  ; --------------X- = ----------------------XX----
.byte $00, $02                                  ; --------------X- = ----------------------XX----
.byte $C1, $02                                  ; XX-----X------X- = ----XXXX--------------XX----
.byte $C1, $02                                  ; XX-----X------X- = ----XXXX--------------XX----
.byte $02, $81                                  ; ------X-X------X = --------XX----------XX------
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $8F, $30                                  ; X---XXXX--XX---- = ------XXXXXXXXXXXX----------
.byte $0E, $10                                  ; ----XXX----X---- = --------XXXXXXXX------------
.byte $85, $10                                  ; X----X-X---X---- = ------XX--XX--XX------------
.byte $44, $20                                  ; -X---X----X----- = ----XX----XX----XX----------

sprite82:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $40                                  ; ---------X------ = ------------------XX--------
.byte $00, $A1                                  ; --------X-X----X = ----------------XX--XX------
.byte $00, $52                                  ; ---------X-X--X- = --------------XX--XX--XX----
.byte $08, $A5                                  ; ----X---X-X--X-X = ------------XX--XX--XX--XX--
.byte $00, $54                                  ; ---------X-X-X-- = --------------XX--XX----XX--
.byte $00, $28                                  ; ----------X-X--- = ----------------XX--------XX
.byte $06, $08                                  ; -----XX-----X--- = --------XXXX--------------XX
.byte $06, $08                                  ; -----XX-----X--- = --------XXXX--------------XX
.byte $08, $04                                  ; ----X--------X-- = ------------XX----------XX--
.byte $0C, $F7                                  ; ----XX--XXXX-XXX = ----------XXXXXXXXXXXXXXXX--
.byte $0E, $F3                                  ; ----XXX-XXXX--XX = --------XXXXXXXXXXXXXXXX----
.byte $0C, $F1                                  ; ----XX--XXXX---X = ----------XXXXXXXXXXXX------
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $04, $50                                  ; -----X---X-X---- = ----------XX--XX--XX--------
.byte $02, $91                                  ; ------X-X--X---X = --------XX----XX----XX------

sprite83:
.byte $A5, $5A                                  ; X-X--X-X-X-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $F3, $CF                                  ; XXXX--XXXX--XXXX = XXXXXXXXXX--------XXXXXXXXXX
.byte $A5, $5A                                  ; X-X--X-X-X-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $A3, $4A                                  ; X-X---XX-X--X-X- = --XX--XXXX--------XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

sprite84:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $A5, $5A                                  ; X-X--X-X-X-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $F3, $CF                                  ; XXXX--XXXX--XXXX = XXXXXXXXXX--------XXXXXXXXXX
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $CF, $F7                                  ; XX--XXXXXXXX-XXX = ----XXXXXXXXXXXXXXXXXXXXXX--
.byte $C3, $C7                                  ; XX----XXXX---XXX = ----XXXXXX--------XXXXXXXX--
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $AF, $7A                                  ; X-X-XXXX-XXXX-X- = --XX--XXXXXXXXXXXXXX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite85:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $A5, $5A                                  ; X-X--X-X-X-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $C3, $C7                                  ; XX----XXXX---XXX = ----XXXXXX--------XXXXXXXX--
.byte $CF, $F7                                  ; XX--XXXXXXXX-XXX = ----XXXXXXXXXXXXXXXXXXXXXX--
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $F3, $CF                                  ; XXXX--XXXX--XXXX = XXXXXXXXXX--------XXXXXXXXXX
.byte $AF, $7A                                  ; X-X-XXXX-XXXX-X- = --XX--XXXXXXXXXXXXXX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite86:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $A5, $5A                                  ; X-X--X-X-X-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $F3, $CF                                  ; XXXX--XXXX--XXXX = XXXXXXXXXX--------XXXXXXXXXX
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $A5, $5A                                  ; X-X--X-X-X-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $E3, $CB                                  ; XXX---XXXX--X-XX = --XXXXXXXX--------XXXXXX--XX
.byte $F3, $CF                                  ; XXXX--XXXX--XXXX = XXXXXXXXXX--------XXXXXXXXXX
.byte $F3, $CF                                  ; XXXX--XXXX--XXXX = XXXXXXXXXX--------XXXXXXXXXX
.byte $02, $40                                  ; ------X--X------ = --------XX--------XX--------
.byte $A5, $5A                                  ; X-X--X-X-X-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $00, $00                                  ; ---------------- = ----------------------------

sprite87:
.byte $EF, $00                                  ; XXX-XXXX-------- = --XXXXXXXXXXXX--------------
.byte $93, $10                                  ; X--X--XX---X---- = XX----XXXX----XX------------
.byte $FF, $10                                  ; XXXXXXXX---X---- = XXXXXXXXXXXXXXXX------------
.byte $BB, $10                                  ; X-XXX-XX---X---- = XXXX--XXXX--XXXX------------
.byte $7C, $10                                  ; -XXXXX-----X---- = XXXXXX----XXXXXX------------
.byte $EF, $00                                  ; XXX-XXXX-------- = --XXXXXXXXXXXX--------------
.byte $44, $00                                  ; -X---X---------- = ----XX----XX----------------
.byte $44, $00                                  ; -X---X---------- = ----XX----XX----------------
.byte $44, $00                                  ; -X---X---------- = ----XX----XX----------------
.byte $28, $00                                  ; --X-X----------- = --XX--------XX--------------
.byte $28, $00                                  ; --X-X----------- = --XX--------XX--------------
.byte $28, $00                                  ; --X-X----------- = --XX--------XX--------------
.byte $10, $10                                  ; ---X-------X---- = XX------------XX------------
.byte $10, $10                                  ; ---X-------X---- = XX------------XX------------
.byte $38, $10                                  ; --XXX------X---- = XXXX--------XXXX------------
.byte $38, $10                                  ; --XXX------X---- = XXXX--------XXXX------------

sprite88:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $8F, $30                                  ; X---XXXX--XX---- = ------XXXXXXXXXXXX----------
.byte $4C, $40                                  ; -X--XX---X------ = ----XX----XXXX----XX--------
.byte $CF, $70                                  ; XX--XXXX-XXX---- = ----XXXXXXXXXXXXXXXX--------
.byte $CD, $60                                  ; XX--XX-X-XX----- = ----XXXX--XXXX--XXXX--------
.byte $C3, $70                                  ; XX----XX-XXX---- = ----XXXXXX----XXXXXX--------
.byte $8F, $30                                  ; X---XXXX--XX---- = ------XXXXXXXXXXXX----------
.byte $81, $20                                  ; X------X--X----- = ------XX--------XX----------
.byte $40, $40                                  ; -X-------X------ = ----XX------------XX--------
.byte $40, $40                                  ; -X-------X------ = ----XX------------XX--------
.byte $20, $81                                  ; --X-----X------X = --XX----------------XX------
.byte $20, $81                                  ; --X-----X------X = --XX----------------XX------
.byte $10, $02                                  ; ---X----------X- = XX--------------------XX----
.byte $10, $83                                  ; ---X----X-----XX = XX------------------XXXX----
.byte $30, $83                                  ; --XX----X-----XX = XXXX----------------XXXX----
.byte $30, $00                                  ; --XX------------ = XXXX------------------------

sprite89:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $89, $91                                  ; X---X--XX--X---X = ------XX----XXXX----XX------
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $8B, $D1                                  ; X---X-XXXX-X---X = ------XXXX--XXXX--XXXX------
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $0E, $70                                  ; ----XXX--XXX---- = --------XXXXXXXXXXXX--------
.byte $81, $81                                  ; X------XX------X = ------XX------------XX------
.byte $40, $02                                  ; -X------------X- = ----XX----------------XX----
.byte $20, $04                                  ; --X----------X-- = --XX--------------------XX--
.byte $10, $08                                  ; ---X--------X--- = XX------------------------XX
.byte $10, $08                                  ; ---X--------X--- = XX------------------------XX
.byte $30, $0C                                  ; --XX--------XX-- = XXXX--------------------XXXX
.byte $30, $0C                                  ; --XX--------XX-- = XXXX--------------------XXXX

sprite8A:
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $0C, $F1                                  ; ----XX--XXXX---X = ----------XXXXXXXXXXXX------
.byte $02, $32                                  ; ------X---XX--X- = --------XX----XXXX----XX----
.byte $0E, $F3                                  ; ----XXX-XXXX--XX = --------XXXXXXXXXXXXXXXX----
.byte $06, $B3                                  ; -----XX-X-XX--XX = --------XXXX--XXXX--XXXX----
.byte $0E, $C3                                  ; ----XXX-XX----XX = --------XXXXXX----XXXXXX----
.byte $0C, $F1                                  ; ----XX--XXXX---X = ----------XXXXXXXXXXXX------
.byte $04, $81                                  ; -----X--X------X = ----------XX--------XX------
.byte $02, $02                                  ; ------X-------X- = --------XX------------XX----
.byte $02, $02                                  ; ------X-------X- = --------XX------------XX----
.byte $81, $04                                  ; X------X-----X-- = ------XX----------------XX--
.byte $81, $04                                  ; X------X-----X-- = ------XX----------------XX--
.byte $40, $08                                  ; -X----------X--- = ----XX--------------------XX
.byte $C1, $08                                  ; XX-----X----X--- = ----XXXX------------------XX
.byte $C1, $0C                                  ; XX-----X----XX-- = ----XXXX----------------XXXX
.byte $00, $0C                                  ; ------------XX-- = ------------------------XXXX

sprite8B:
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $4C, $32                                  ; -X--XX----XX--X- = ----XX----XXXXXXXX----XX----
.byte $68, $16                                  ; -XX-X------X-XX- = --XXXX------XXXX------XXXX--
.byte $E9, $97                                  ; XXX-X--XX--X-XXX = --XXXXXX----XXXX----XXXXXX--
.byte $DF, $FB                                  ; XX-XXXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX
.byte $9B, $D9                                  ; X--XX-XXXX-XX--X = XX----XXXX--XXXX--XXXX----XX
.byte $22, $54                                  ; --X---X--X-X-X-- = --XX----XX----XX--XX----XX--
.byte $99, $44                                  ; X--XX--X-X---X-- = XX----XX----XX----XX----XX--
.byte $A9, $89                                  ; X-X-X--XX---X--X = --XX--XX----XX------XX----XX
.byte $22, $95                                  ; --X---X-X--X-X-X = --XX----XX----XX----XX--XX
.byte $14, $2A                                  ; ---X-X----X-X-X- = XX--------XX----XX----XX--XX
.byte $24, $A9                                  ; --X--X--X-X-X--X = --XX------XX----XX--XX----XX
.byte $02, $91                                  ; ------X-X--X---X = --------XX----XX----XX------
.byte $81, $12                                  ; X------X---X--X- = ------XX------XX------XX----
.byte $00, $20                                  ; ----------X----- = ----------------XX----------

sprite8C:
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $4C, $32                                  ; -X--XX----XX--X- = ----XX----XXXXXXXX----XX----
.byte $68, $16                                  ; -XX-X------X-XX- = --XXXX------XXXX------XXXX--
.byte $E9, $97                                  ; XXX-X--XX--X-XXX = --XXXXXX----XXXX----XXXXXX--
.byte $DF, $FB                                  ; XX-XXXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX
.byte $9B, $D9                                  ; X--XX-XXXX-XX--X = XX----XXXX--XXXX--XXXX----XX
.byte $2A, $85                                  ; --X-X-X-X----X-X = --XX----XX--XX------XX--XX--
.byte $12, $99                                  ; ---X--X-X--XX--X = XX------XX----XX----XX----XX
.byte $91, $54                                  ; X--X---X-X-X-X-- = XX----XX------XX--XX----XX--
.byte $A9, $44                                  ; X-X-X--X-X---X-- = --XX--XX----XX----XX----XX--
.byte $A9, $89                                  ; X-X-X--XX---X--X = --XX--XX----XX------XX----XX
.byte $12, $99                                  ; ---X--X-X--XX--X = XX------XX----XX----XX----XX
.byte $04, $22                                  ; -----X----X---X- = ----------XX----XX----XX----
.byte $04, $A1                                  ; -----X--X-X----X = ----------XX----XX--XX------
.byte $02, $00                                  ; ------X--------- = --------XX------------------

sprite8D:
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $4C, $32                                  ; -X--XX----XX--X- = ----XX----XXXXXXXX----XX----
.byte $68, $16                                  ; -XX-X------X-XX- = --XXXX------XXXX------XXXX--
.byte $E9, $97                                  ; XXX-X--XX--X-XXX = --XXXXXX----XXXX----XXXXXX--
.byte $DF, $FB                                  ; XX-XXXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX
.byte $9B, $D9                                  ; X--XX-XXXX-XX--X = XX----XXXX--XXXX--XXXX----XX
.byte $22, $95                                  ; --X---X-X--X-X-X = --XX----XX----XX----XX--XX--
.byte $24, $22                                  ; --X--X----X---X- = --XX------XX----XX----XX----
.byte $24, $22                                  ; --X--X----X---X- = --XX------XX----XX----XX----
.byte $12, $95                                  ; ---X--X-X--X-X-X = XX------XX----XX----XX--XX--
.byte $2A, $44                                  ; --X-X-X--X---X-- = --XX----XX--XX----XX----XX--
.byte $A9, $48                                  ; X-X-X--X-X--X--- = --XX--XX----XX----XX------XX
.byte $81, $91                                  ; X------XX--X---X = ------XX------XX----XX------
.byte $02, $22                                  ; ------X---X---X- = --------XX------XX----XX----
.byte $00, $20                                  ; ----------X----- = ----------------XX----------

sprite8E:
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $4C, $32                                  ; -X--XX----XX--X- = ----XX----XXXXXXXX----XX----
.byte $68, $16                                  ; -XX-X------X-XX- = --XXXX------XXXX------XXXX--
.byte $E9, $97                                  ; XXX-X--XX--X-XXX = --XXXXXX----XXXX----XXXXXX--
.byte $DF, $FB                                  ; XX-XXXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX
.byte $9B, $D9                                  ; X--XX-XXXX-XX--X = XX----XXXX--XXXX--XXXX----XX
.byte $A9, $89                                  ; X-X-X--XX---X--X = --XX--XX----XX------XX----XX
.byte $22, $95                                  ; --X---X-X--X-X-X = --XX----XX----XX----XX--XX--
.byte $14, $2A                                  ; ---X-X----X-X-X- = XX--------XX----XX----XX--XX
.byte $24, $2A                                  ; --X--X----X-X-X- = --XX------XX----XX----XX--XX
.byte $12, $2A                                  ; ---X--X---X-X-X- = XX------XX------XX----XX--XX
.byte $91, $95                                  ; X--X---XX--X-X-X = XX----XX------XX----XX--XX--
.byte $89, $40                                  ; X---X--X-X------ = ------XX----XX----XX--------
.byte $89, $00                                  ; X---X--X-------- = ------XX----XX--------------
.byte $00, $10                                  ; -----------X---- = --------------XX------------

sprite8F:
.byte $0C, $20                                  ; ----XX----X----- = ----------XXXX--XX----------
.byte $8F, $E1                                  ; X---XXXXXXX----X = ------XXXXXXXX--XXXXXX------
.byte $CF, $C3                                  ; XX--XXXXXX----XX = ----XXXXXXXXXX----XXXXXX----
.byte $CF, $22                                  ; XX--XXXX--X---X- = ----XXXXXXXXXX--XX----XX----
.byte $EF, $64                                  ; XXX-XXXX-XX--X-- = --XXXXXXXXXXXX--XXXX----XX--
.byte $EF, $E5                                  ; XXX-XXXXXXX--X-X = --XXXXXXXXXXXX--XXXXXX--XX--
.byte $DF, $EF                                  ; XX-XXXXXXXX-XXXX = XX--XXXXXXXXXX--XXXXXXXXXXXX
.byte $00, $EF                                  ; --------XXX-XXXX = ----------------XXXXXXXXXXXX
.byte $97, $00                                  ; X--X-XXX-------- = XX----XXXXXX----------------
.byte $97, $FF                                  ; X--X-XXXXXXXXXXX = XX----XXXXXX--XXXXXXXXXXXXXX
.byte $26, $F7                                  ; --X--XX-XXXX-XXX = --XX----XXXX--XXXXXXXXXXXX--
.byte $20, $F5                                  ; --X-----XXXX-X-X = --XX----------XXXXXXXX--XX--
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $40, $02                                  ; -X------------X- = ----XX----------------XX----
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------
.byte $04, $30                                  ; -----X----XX---- = ----------XX--XXXX----------

sprite90:
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $CF, $52                                  ; XX--XXXX-X-X--X- = ----XXXXXXXXXXXX--XX--XX----
.byte $CF, $32                                  ; XX--XXXX--XX--X- = ----XXXXXXXXXXXXXX----XX----
.byte $EF, $34                                  ; XXX-XXXX--XX-X-- = --XXXXXXXXXXXXXXXX------XX--
.byte $2E, $D5                                  ; --X-XXX-XX-X-X-X = --XX----XXXXXXXX--XXXX--XX--
.byte $D9, $DF                                  ; XX-XX--XXX-XXXXX = XX--XXXX----XXXX--XXXXXXXXXX
.byte $D7, $EF                                  ; XX-X-XXXXXX-XXXX = XX--XXXXXXXX----XXXXXXXXXXXX
.byte $97, $EF                                  ; X--X-XXXXXX-XXXX = XX----XXXXXX----XXXXXXXXXXXX
.byte $9B, $9F                                  ; X--XX-XXX--XXXXX = XX----XXXX--XXXX----XXXXXXXX
.byte $2A, $74                                  ; --X-X-X--XXX-X-- = --XX----XX--XXXXXXXX----XX--
.byte $28, $F5                                  ; --X-X---XXXX-X-X = --XX--------XXXXXXXXXX--XX--
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $40, $02                                  ; -X------------X- = ----XX----------------XX----
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------

sprite91:
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $CF, $D3                                  ; XX--XXXXXX-X--XX = ----XXXXXXXXXXXX--XXXXXX----
.byte $4E, $32                                  ; -X--XXX---XX--X- = ----XX--XXXXXXXXXX----XX----
.byte $AD, $74                                  ; X-X-XX-X-XXX-X-- = --XX--XX--XXXXXXXXXX----XX--
.byte $AB, $74                                  ; X-X-X-XX-XXX-X-- = --XX--XXXX--XXXXXXXX----XX--
.byte $97, $BF                                  ; X--X-XXXX-XXXXXX = XX----XXXXXX--XXXX--XXXXXXXX
.byte $97, $CF                                  ; X--X-XXXXX--XXXX = XX----XXXXXX------XXXXXXXXXX
.byte $93, $EF                                  ; X--X--XXXXX-XXXX = XX----XXXX------XXXXXXXXXXXX
.byte $9D, $EF                                  ; X--XXX-XXXX-XXXX = XX----XX--XXXX--XXXXXXXXXXXX
.byte $2E, $D7                                  ; --X-XXX-XX-X-XXX = --XX----XXXXXXXX--XXXXXXXX--
.byte $28, $34                                  ; --X-X-----XX-X-- = --XX--------XXXXXX------XX--
.byte $00, $02                                  ; --------------X- = ----------------------XX----
.byte $40, $00                                  ; -X-------------- = ----XX----------------------
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------

sprite92:
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $8D, $F1                                  ; X---XX-XXXXX---X = ------XX--XXXXXXXXXXXX------
.byte $CB, $D3                                  ; XX--X-XXXX-X--XX = ----XXXXXX--XXXX--XXXXXX----
.byte $CB, $32                                  ; XX--X-XX--XX--X- = ----XXXXXX--XXXXXX----XX----
.byte $EB, $74                                  ; XXX-X-XX-XXX-X-- = --XXXXXXXX--XXXXXXXX----XX--
.byte $E7, $F5                                  ; XXX--XXXXXXX-X-X = --XXXXXXXXXX--XXXXXXXX--XX--
.byte $D7, $78                                  ; XX-X-XXX-XXXX--- = XX--XXXXXXXX--XXXXXX------XX
.byte $D7, $8F                                  ; XX-X-XXXX---XXXX = XX--XXXXXXXX--------XXXXXXXX
.byte $91, $EF                                  ; X--X---XXXX-XXXX = XX----XX--------XXXXXXXXXXXX
.byte $1E, $EF                                  ; ---XXXX-XXX-XXXX = XX------XXXXXX--XXXXXXXXXXXX
.byte $0E, $E7                                  ; ----XXX-XXX--XXX = --------XXXXXX--XXXXXXXXXX--
.byte $28, $D5                                  ; --X-X---XX-X-X-X = --XX--------XXXX--XXXX--XX--
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $40, $02                                  ; -X------------X- = ----XX----------------XX----
.byte $83, $81                                  ; X-----XXX------X = ------XXXX----------XX------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------

sprite93:
.byte $0C, $00                                  ; ----XX---------- = ----------XXXX--------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $83, $00                                  ; X-----XX-------- = ------XXXX------------------
.byte $C3, $00                                  ; XX----XX-------- = ----XXXXXX------------------
.byte $E5, $00                                  ; XXX--X-X-------- = --XXXXXX--XX----------------
.byte $3A, $20                                  ; --XXX-X---X----- = XXXX----XX--XX--XX----------
.byte $14, $70                                  ; ---X-X---XXX---- = XX--------XX--XXXXXX--------
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $0C, $40                                  ; ----XX---X------ = ----------XXXX----XX--------
.byte $3E, $60                                  ; --XXXXX--XX----- = XXXX----XXXXXX--XXXX--------
.byte $B3, $40                                  ; X-XX--XX-X------ = XXXX--XXXX--------XX--------
.byte $FF, $70                                  ; XXXXXXXX-XXX---- = XXXXXXXXXXXXXXXXXXXX--------
.byte $78, $00                                  ; -XXXX----------- = XXXXXX------XX--------------
.byte $32, $20                                  ; --XX--X---X----- = XXXX----XX------XX----------
.byte $B5, $50                                  ; X-XX-X-X-X-X---- = XXXX--XX--XX--XX--XX--------
.byte $02, $20                                  ; ------X---X----- = --------XX------XX----------

sprite94:
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $0C, $00                                  ; ----XX---------- = ----------XXXX--------------
.byte $0E, $00                                  ; ----XXX--------- = --------XXXXXX--------------
.byte $87, $10                                  ; X----XXX---X---- = ------XXXXXX--XX------------
.byte $C9, $A1                                  ; XX--X--XX-X----X = ----XXXX----XX--XX--XX------
.byte $40, $D3                                  ; -X------XX-X--XX = ----XX--------XX--XXXXXX----
.byte $00, $E3                                  ; --------XXX---XX = ----------------XXXXXXXX----
.byte $00, $32                                  ; ----------XX--X- = --------------XXXX----XX----
.byte $68, $B3                                  ; -XX-X---X-XX--XX = --XXXX------XXXXXX--XXXX----
.byte $6C, $02                                  ; -XX-XX--------X- = --XXXX----XXXX--------XX----
.byte $EF, $F3                                  ; XXX-XXXXXXXX--XX = --XXXXXXXXXXXXXXXXXXXXXX----
.byte $E3, $20                                  ; XXX---XX--X----- = --XXXXXXXX------XX----------
.byte $68, $81                                  ; -XX-X---X------X = --XXXX------XX------XX------
.byte $64, $52                                  ; -XX--X---X-X--X- = --XXXX----XX--XX--XX--XX----
.byte $08, $81                                  ; ----X---X------X = ------------XX------XX------

sprite95:
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $0C, $10                                  ; ----XX-----X---- = ----------XXXXXX------------
.byte $0E, $20                                  ; ----XXX---X----- = --------XXXXXX--XX----------
.byte $83, $52                                  ; X-----XX-X-X--X- = ------XXXX----XX--XX--XX----
.byte $81, $A7                                  ; X------XX-X--XXX = ------XX--------XX--XXXXXX--
.byte $00, $C7                                  ; --------XX---XXX = ------------------XXXXXXXX--
.byte $00, $64                                  ; ---------XX--X-- = ----------------XXXX----XX--
.byte $60, $76                                  ; -XX------XXX-XX- = --XXXX--------XXXXXX--XXXX--
.byte $68, $14                                  ; -XX-X------X-X-- = --XXXX------XXXX--------XX--
.byte $EF, $F7                                  ; XXX-XXXXXXXX-XXX = --XXXXXXXXXXXXXXXXXXXXXXXX--
.byte $E7, $40                                  ; XXX--XXX-X------ = --XXXXXXXXXX------XX--------
.byte $60, $12                                  ; -XX--------X--X- = --XXXX--------XX------XX----
.byte $68, $A5                                  ; -XX-X---X-X--X-X = --XXXX------XX--XX--XX--XX--
.byte $00, $12                                  ; -----------X--X- = --------------XX------XX----

sprite96:
.byte $00, $C1                                  ; --------XX-----X = ------------------XXXX------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $08, $30                                  ; ----X-----XX---- = ------------XXXXXX----------
.byte $0C, $50                                  ; ----XX---X-X---- = ----------XXXXXX--XX--------
.byte $06, $A5                                  ; -----XX-X-X--X-X = --------XXXX----XX--XX--XX--
.byte $02, $4E                                  ; ------X--X--XXX- = --------XX--------XX--XXXXXX
.byte $00, $8F                                  ; --------X---XXXX = --------------------XXXXXXXX
.byte $00, $C9                                  ; --------XX--X--X = ------------------XXXX----XX
.byte $83, $ED                                  ; X-----XXXXX-XX-X = ------XXXX------XXXXXX--XXXX
.byte $83, $38                                  ; X-----XX--XXX--- = ------XXXX----XXXX--------XX
.byte $8F, $FF                                  ; X---XXXXXXXXXXXX = ------XXXXXXXXXXXXXXXXXXXXXX
.byte $8F, $81                                  ; X---XXXXX------X = ------XXXXXXXX------XX------
.byte $83, $24                                  ; X-----XX--X--X-- = ------XXXX------XX------XX--
.byte $83, $5A                                  ; X-----XX-X-XX-X- = ------XXXX----XX--XX--XX--XX
.byte $00, $24                                  ; ----------X--X-- = ----------------XX------XX--

sprite97:
.byte $89, $00                                  ; X---X--X-------- = ------XX----XX--------------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $8F, $00                                  ; X---XXXX-------- = ------XXXXXXXX--------------
.byte $DF, $50                                  ; XX-XXXXX-X-X---- = XX--XXXXXXXXXXXX--XX--------
.byte $E9, $30                                  ; XXX-X--X--XX---- = --XXXXXX----XXXXXX----------
.byte $E9, $30                                  ; XXX-X--X--XX---- = --XXXXXX----XXXXXX----------
.byte $DF, $50                                  ; XX-XXXXX-X-X---- = XX--XXXXXXXXXXXX--XX--------
.byte $AF, $20                                  ; X-X-XXXX--X----- = --XX--XXXXXXXX--XX----------
.byte $26, $20                                  ; --X--XX---X----- = --XX----XXXX----XX----------
.byte $A9, $20                                  ; X-X-X--X--X----- = --XX--XX----XX--XX----------
.byte $EF, $30                                  ; XXX-XXXX--XX---- = --XXXXXXXXXXXXXXXX----------
.byte $06, $00                                  ; -----XX--------- = --------XXXX----------------
.byte $60, $30                                  ; -XX-------XX---- = --XXXX--------XXXX----------
.byte $99, $60                                  ; X--XX--X-XX----- = XX----XX----XX--XXXX--------
.byte $D9, $40                                  ; XX-XX--X-X------ = XX--XXXX----XX----XX--------
.byte $60, $30                                  ; -XX-------XX---- = --XXXX--------XXXX----------

sprite98:
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $0C, $30                                  ; ----XX----XX---- = ----------XXXXXXXX----------
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $CB, $D3                                  ; XX--X-XXXX-X--XX = ----XXXXXX--XXXX--XXXXXX----
.byte $CB, $D3                                  ; XX--X-XXXX-X--XX = ----XXXXXX--XXXX--XXXXXX----
.byte $87, $E1                                  ; X----XXXXXX----X = ------XXXXXX----XXXXXX------
.byte $8D, $B1                                  ; X---XX-XX-XX---X = ------XX--XXXXXXXX--XX------
.byte $8D, $B1                                  ; X---XX-XX-XX---X = ------XX--XXXXXXXX--XX------
.byte $89, $91                                  ; X---X--XX--X---X = ------XX----XXXX----XX------
.byte $8F, $F1                                  ; X---XXXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $08, $10                                  ; ----X------X---- = ------------XXXX------------
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------
.byte $44, $22                                  ; -X---X----X---X- = ----XX----XX----XX----XX----
.byte $C5, $A3                                  ; XX---X-XX-X---XX = ----XXXX--XX----XX--XXXX----
.byte $83, $C1                                  ; X-----XXXX-----X = ------XXXX--------XXXX------

sprite99:
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $08, $70                                  ; ----X----XXX---- = ------------XXXXXXXX--------
.byte $08, $40                                  ; ----X----X------ = ------------XX----XX--------
.byte $87, $B7                                  ; X----XXXX-XX-XXX = ------XXXXXX--XXXX--XXXXXX--
.byte $8B, $76                                  ; X---X-XX-XXX-XX- = ------XXXX--XXXXXXXX--XXXX--
.byte $8B, $76                                  ; X---X-XX-XXX-XX- = ------XXXX--XXXXXXXX--XXXX--
.byte $87, $B7                                  ; X----XXXX-XX-XXX = ------XXXXXX--XXXX--XXXXXX--
.byte $0A, $42                                  ; ----X-X--X----X- = --------XX--XX----XX--XX----
.byte $0A, $72                                  ; ----X-X--XXX--X- = --------XX--XXXXXXXX--XX----
.byte $0A, $72                                  ; ----X-X--XXX--X- = --------XX--XXXXXXXX--XX----
.byte $0E, $F3                                  ; ----XXX-XXXX--XX = --------XXXXXXXXXXXXXXXX----
.byte $00, $30                                  ; ----------XX---- = --------------XXXX----------
.byte $06, $83                                  ; -----XX-X-----XX = --------XXXX--------XXXX----
.byte $8B, $44                                  ; X---X-XX-X---X-- = ------XXXX--XX----XX----XX--
.byte $89, $C5                                  ; X---X--XXX---X-X = ------XX----XX----XXXX--XX--
.byte $06, $83                                  ; -----XX-X-----XX = --------XXXX--------XXXX----

sprite9A:
.byte $00, $F1                                  ; --------XXXX---X = --------------XXXXXXXX------
.byte $00, $91                                  ; --------X--X---X = --------------XX----XX------
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $06, $FD                                  ; -----XX-XXXXXX-X = --------XXXX--XXXXXXXX--XXXX
.byte $0A, $FB                                  ; ----X-X-XXXXX-XX = --------XX--XXXXXXXXXXXX--XX
.byte $0A, $FB                                  ; ----X-X-XXXXX-XX = --------XX--XXXXXXXXXXXX--XX
.byte $06, $FD                                  ; -----XX-XXXXXX-X = --------XXXX--XXXXXXXX--XXXX
.byte $04, $64                                  ; -----X---XX--X-- = ----------XX----XXXX----XX--
.byte $04, $95                                  ; -----X--X--X-X-X = ----------XX--XX----XX--XX--
.byte $04, $F5                                  ; -----X--XXXX-X-X = ----------XX--XXXXXXXX--XX--
.byte $0C, $F7                                  ; ----XX--XXXX-XXX = ----------XXXXXXXXXXXXXXXX--
.byte $00, $60                                  ; ---------XX----- = ----------------XXXX--------
.byte $0C, $06                                  ; ----XX-------XX- = ----------XXXX--------XXXX--
.byte $0A, $9B                                  ; ----X-X-X--XX-XX = --------XX--XXXX----XXXX--XX
.byte $02, $99                                  ; ------X-X--XX--X = --------XX----XX----XX----XX
.byte $0C, $06                                  ; ----XX-------XX- = ----------XXXX--------XXXX--

sprite9B:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $76, $BF                                  ; XXX-XXX-XXXXXX = XXXXXX--XXXX--XXXX--XXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $76, $BF                                  ; XXX-XXX-XXXXXX = XXXXXX--XXXX--XXXX--XXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $76, $BF                                  ; XXX-XXX-XXXXXX = XXXXXX--XXXX--XXXX--XXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $76, $BF                                  ; XXX-XXX-XXXXXX = XXXXXX--XXXX--XXXX--XXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $76, $BF                                  ; XXX-XXX-XXXXXX = XXXXXX--XXXX--XXXX--XXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

sprite9C:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

sprite9D:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $12, $24                                  ; --X--X--X--X-- = XX------XX------XX------XX--
.byte $C9, $93                                  ; X--X--X--X--XX = ----XXXX----XXXX----XXXX----
.byte $24, $48                                  ; -X--X--X--X--- = --XX------XX------XX------XX
.byte $24, $48                                  ; -X--X--X--X--- = --XX------XX------XX------XX
.byte $C9, $93                                  ; X--X--X--X--XX = ----XXXX----XXXX----XXXX----
.byte $12, $24                                  ; --X--X--X--X-- = XX------XX------XX------XX--
.byte $12, $24                                  ; --X--X--X--X-- = XX------XX------XX------XX--
.byte $C9, $93                                  ; X--X--X--X--XX = ----XXXX----XXXX----XXXX----
.byte $24, $48                                  ; -X--X--X--X--- = --XX------XX------XX------XX
.byte $24, $48                                  ; -X--X--X--X--- = --XX------XX------XX------XX
.byte $C9, $93                                  ; X--X--X--X--XX = ----XXXX----XXXX----XXXX----
.byte $12, $24                                  ; --X--X--X--X-- = XX------XX------XX------XX--
.byte $12, $24                                  ; --X--X--X--X-- = XX------XX------XX------XX--
.byte $C9, $93                                  ; X--X--X--X--XX = ----XXXX----XXXX----XXXX----
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

sprite9E:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $58, $89                                  ; X-XX--X---X--X = XX--XX------XX------XX----XX
.byte $91, $1A                                  ; --X---X--XX-X- = XX----XX------XX------XX--XX
.byte $12, $2C                                  ; --X--X--X-XX-- = XX------XX------XX------XXXX
.byte $34, $48                                  ; -XX-X--X--X--- = XXXX------XX------XX------XX
.byte $58, $89                                  ; X-XX--X---X--X = XX--XX------XX------XX----XX
.byte $91, $1A                                  ; --X---X--XX-X- = XX----XX------XX------XX--XX
.byte $12, $2C                                  ; --X--X--X-XX-- = XX------XX------XX------XXXX
.byte $34, $48                                  ; -XX-X--X--X--- = XXXX------XX------XX------XX
.byte $58, $89                                  ; X-XX--X---X--X = XX--XX------XX------XX----XX
.byte $91, $1A                                  ; --X---X--XX-X- = XX----XX------XX------XX--XX
.byte $12, $2C                                  ; --X--X--X-XX-- = XX------XX------XX------XXXX
.byte $34, $48                                  ; -XX-X--X--X--- = XXXX------XX------XX------XX
.byte $58, $89                                  ; X-XX--X---X--X = XX--XX------XX------XX----XX
.byte $91, $1A                                  ; --X---X--XX-X- = XX----XX------XX------XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

sprite9F:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $A5, $5A                                  ; -X--X-XX-XX-X- = --XX--XX--XX--XX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteA0:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $DF, $FB                                  ; X-XXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX
.byte $DF, $FB                                  ; X-XXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX
.byte $D1, $8B                                  ; X-X---X---X-XX = XX--XXXX------------XXXX--XX
.byte $D1, $8B                                  ; X-X---X---X-XX = XX--XXXX------------XXXX--XX
.byte $D1, $8B                                  ; X-X---X---X-XX = XX--XXXX------------XXXX--XX
.byte $F1, $8F                                  ; XXX---X---XXXX = XXXXXXXX------------XXXXXXXX
.byte $F1, $8F                                  ; XXX---X---XXXX = XXXXXXXX------------XXXXXXXX
.byte $D1, $8B                                  ; X-X---X---X-XX = XX--XXXX------------XXXX--XX
.byte $D1, $8B                                  ; X-X---X---X-XX = XX--XXXX------------XXXX--XX
.byte $D1, $8B                                  ; X-X---X---X-XX = XX--XXXX------------XXXX--XX
.byte $DF, $FB                                  ; X-XXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX
.byte $DF, $FB                                  ; X-XXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteA1:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteA2:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $30, $0C                                  ; -XX-------XX-- = XXXX--------------------XXXX
.byte $50, $0A                                  ; X-X-------X-X- = XX--XX----------------XX--XX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $32, $4C                                  ; -XX--X-X--XX-- = XXXX----XX--------XX----XXXX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $99, $99                                  ; --XX--X--XX--X = XX----XX----XXXX----XX----XX
.byte $32, $4C                                  ; -XX--X-X--XX-- = XXXX----XX--------XX----XXXX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $99, $99                                  ; --XX--X--XX--X = XX----XX----XXXX----XX----XX
.byte $32, $4C                                  ; -XX--X-X--XX-- = XXXX----XX--------XX----XXXX
.byte $54, $2A                                  ; X-X-X---X-X-X- = XX--XX----XX----XX----XX--XX
.byte $32, $4C                                  ; -XX--X-X--XX-- = XXXX----XX--------XX----XXXX
.byte $99, $99                                  ; --XX--X--XX--X = XX----XX----XXXX----XX----XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteA3:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $14, $28                                  ; --X-X---X-X--- = XX--------XX----XX--------XX
.byte $12, $48                                  ; --X--X-X--X--- = XX------XX--------XX------XX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $50, $0A                                  ; X-X-------X-X- = XX--XX----------------XX--XX
.byte $38, $1C                                  ; -XXX-----XXX-- = XXXX--------XXXX--------XXXX
.byte $38, $1C                                  ; -XXX-----XXX-- = XXXX--------XXXX--------XXXX
.byte $50, $0A                                  ; X-X-------X-X- = XX--XX----------------XX--XX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $12, $48                                  ; --X--X-X--X--- = XX------XX--------XX------XX
.byte $14, $28                                  ; --X-X---X-X--- = XX--------XX----XX--------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteA4:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $F1, $1E                                  ; XXX---X--XXXX- = XXXXXXXX------XX------XXXXXX
.byte $91, $99                                  ; --X---X--XX--X = XX----XX------XX----XX----XX
.byte $B5, $99                                  ; -XX-X-X--XX--X = XXXX--XX--XX--XX----XX----XX
.byte $B5, $9D                                  ; -XX-X-X--XXX-X = XXXX--XX--XX--XX----XX--XXXX
.byte $95, $1C                                  ; --X-X-X--XXX-- = XX----XX--XX--XX--------XXXX
.byte $50, $99                                  ; X-X---X--XX--X = XX--XX--------XX----XX----XX
.byte $5A, $DB                                  ; X-XX-XXX-XX-XX = XX--XX--XX--XXXX--XXXXXX--XX
.byte $5A, $AD                                  ; X-XX-XX-X-XX-X = XX--XX--XX--XX--XX--XX--XXXX
.byte $58, $2C                                  ; X-XX----X-XX-- = XX--XX------XX--XX------XXXX
.byte $99, $CB                                  ; --XX--XX--X-XX = XX----XX----XX----XXXXXX--XX
.byte $99, $08                                  ; --XX--X---X--- = XX----XX----XX------------XX
.byte $B1, $5A                                  ; -XX---XX-XX-X- = XXXX--XX------XX--XX--XX--XX
.byte $B5, $5A                                  ; -XX-X-XX-XX-X- = XXXX--XX--XX--XX--XX--XX--XX
.byte $95, $1A                                  ; --X-X-X--XX-X- = XX----XX--XX--XX------XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteA5:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $BB, $AD                                  ; -XXX-XX-X-XX-X = XXXX--XXXX--XX--XX--XX--XXXX
.byte $7A, $BD                                  ; XXXX-XX-XXXX-X = XXXXXX--XX--XXXXXX--XX--XXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteA6:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $1E, $78                                  ; --XXXX-XXXX--- = XX------XXXXXXXXXXXX------XX
.byte $1E, $78                                  ; --XXXX-XXXX--- = XX------XXXXXXXXXXXX------XX
.byte $1E, $78                                  ; --XXXX-XXXX--- = XX------XXXXXXXXXXXX------XX
.byte $1E, $78                                  ; --XXXX-XXXX--- = XX------XXXXXXXXXXXX------XX
.byte $1E, $78                                  ; --XXXX-XXXX--- = XX------XXXXXXXXXXXX------XX
.byte $16, $68                                  ; --X-XX-XX-X--- = XX------XXXX----XXXX------XX
.byte $16, $68                                  ; --X-XX-XX-X--- = XX------XXXX----XXXX------XX
.byte $1E, $78                                  ; --XXXX-XXXX--- = XX------XXXXXXXXXXXX------XX
.byte $1E, $78                                  ; --XXXX-XXXX--- = XX------XXXXXXXXXXXX------XX
.byte $1E, $78                                  ; --XXXX-XXXX--- = XX------XXXXXXXXXXXX------XX
.byte $1E, $78                                  ; --XXXX-XXXX--- = XX------XXXXXXXXXXXX------XX
.byte $1E, $78                                  ; --XXXX-XXXX--- = XX------XXXXXXXXXXXX------XX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteA7:
.byte $0C, $30                                  ; ---XX---XX---- = ----------XXXXXXXX----------
.byte $0E, $70                                  ; ---XXX-XXX---- = --------XXXXXXXXXXXX--------
.byte $8F, $F1                                  ; ---XXXXXXX---X = ------XXXXXXXXXXXXXXXX------
.byte $89, $91                                  ; ---X--X--X---X = ------XX----XXXX----XX------
.byte $89, $91                                  ; ---X--X--X---X = ------XX----XXXX----XX------
.byte $0E, $70                                  ; ---XXX-XXX---- = --------XXXXXXXXXXXX--------
.byte $0A, $50                                  ; ---X-X-X-X---- = --------XX--XXXX--XX--------
.byte $04, $20                                  ; ----X---X----- = ----------XX----XX----------
.byte $28, $14                                  ; -X-X-----X-X-- = --XX--------XXXX--------XX--
.byte $F1, $8F                                  ; XXX---X---XXXX = XXXXXXXX------------XXXXXXXX
.byte $F7, $EF                                  ; XXX-XXXXX-XXXX = XXXXXXXXXXXX----XXXXXXXXXXXX
.byte $0A, $70                                  ; ---X-X-XXX---- = --------XX--XXXXXXXX--------
.byte $0E, $50                                  ; ---XXX-X-X---- = --------XXXXXXXX--XX--------
.byte $F7, $EF                                  ; XXX-XXXXX-XXXX = XXXXXXXXXXXX----XXXXXXXXXXXX
.byte $F1, $8F                                  ; XXX---X---XXXX = XXXXXXXX------------XXXXXXXX
.byte $20, $04                                  ; -X---------X-- = --XX--------------------XX--

spriteA8:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $F3, $CF                                  ; XXX--XXX--XXXX = XXXXXXXXXX--------XXXXXXXXXX
.byte $F1, $8F                                  ; XXX---X---XXXX = XXXXXXXX------------XXXXXXXX
.byte $70, $0E                                  ; XXX-------XXX- = XXXXXX----------------XXXXXX
.byte $30, $0C                                  ; -XX-------XX-- = XXXX--------------------XXXX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $14, $28                                  ; --X-X---X-X--- = XX--------XX----XX--------XX
.byte $14, $28                                  ; --X-X---X-X--- = XX--------XX----XX--------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $30, $0C                                  ; -XX-------XX-- = XXXX--------------------XXXX
.byte $70, $0E                                  ; XXX-------XXX- = XXXXXX----------------XXXXXX
.byte $F1, $8F                                  ; XXX---X---XXXX = XXXXXXXX------------XXXXXXXX
.byte $F3, $CF                                  ; XXX--XXX--XXXX = XXXXXXXXXX--------XXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteA9:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $12, $08                                  ; --X--X----X--- = XX------XX----------------XX
.byte $5A, $08                                  ; X-XX-X----X--- = XX--XX--XX--XX------------XX
.byte $97, $8B                                  ; --X-XXX---X-XX = XX----XXXXXX--------XXXX--XX
.byte $FF, $5E                                  ; XXXXXXXX-XXXX- = XXXXXXXXXXXXXXXX--XX--XXXXXX
.byte $97, $08                                  ; --X-XXX---X--- = XX----XXXXXX--------------XX
.byte $5A, $08                                  ; X-XX-X----X--- = XX--XX--XX--XX------------XX
.byte $12, $08                                  ; --X--X----X--- = XX------XX----------------XX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteAA:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $18, $18                                  ; --XX-----XX--- = XX----------XXXX----------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteAB:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $DF, $FB                                  ; X-XXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX
.byte $50, $0A                                  ; X-X-------X-X- = XX--XX----------------XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $DF, $FB                                  ; X-XXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteAC:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $D1, $8B                                  ; X-X---X---X-XX = XX--XXXX------------XXXX--XX
.byte $50, $0A                                  ; X-X-------X-X- = XX--XX----------------XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $50, $0A                                  ; X-X-------X-X- = XX--XX----------------XX--XX
.byte $D1, $8B                                  ; X-X---X---X-XX = XX--XXXX------------XXXX--XX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteAD:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $DF, $FB                                  ; X-XXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX
.byte $50, $0A                                  ; X-X-------X-X- = XX--XX----------------XX--XX
.byte $5E, $7A                                  ; X-XXXX-XXXX-X- = XX--XX--XXXXXXXXXXXX--XX--XX
.byte $52, $4A                                  ; X-X--X-X--X-X- = XX--XX--XX--------XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $5A, $5A                                  ; X-XX-X-X-XX-X- = XX--XX--XX--XXXX--XX--XX--XX
.byte $52, $4A                                  ; X-X--X-X--X-X- = XX--XX--XX--------XX--XX--XX
.byte $5E, $7A                                  ; X-XXXX-XXXX-X- = XX--XX--XXXXXXXXXXXX--XX--XX
.byte $50, $0A                                  ; X-X-------X-X- = XX--XX----------------XX--XX
.byte $DF, $FB                                  ; X-XXXXXXXXX-XX = XX--XXXXXXXXXXXXXXXXXXXX--XX
.byte $10, $08                                  ; --X-------X--- = XX------------------------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX

spriteAE:
.byte $00, $00                                  ; -------------- = ----------------------------
.byte $0E, $70                                  ; ---XXX-XXX---- = --------XXXXXXXXXXXX--------
.byte $C1, $83                                  ; X-----X-----XX = ----XXXX------------XXXX----
.byte $2C, $34                                  ; -X-XX---XX-X-- = --XX------XXXXXXXX------XX--
.byte $12, $48                                  ; --X--X-X--X--- = XX------XX--------XX------XX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $91, $89                                  ; --X---X---X--X = XX----XX------------XX----XX
.byte $12, $48                                  ; --X--X-X--X--- = XX------XX--------XX------XX
.byte $24, $24                                  ; -X--X---X--X-- = --XX------XX----XX------XX--
.byte $C5, $A3                                  ; X---X-X-X---XX = ----XXXX--XX----XX--XXXX----
.byte $95, $A9                                  ; --X-X-X-X-X--X = XX----XX--XX----XX--XX----XX
.byte $F5, $AF                                  ; XXX-X-X-X-XXXX = XXXXXXXX--XX----XX--XXXXXXXX
.byte $14, $28                                  ; --X-X---X-X--- = XX--------XX----XX--------XX
.byte $F7, $EF                                  ; XXX-XXXXX-XXXX = XXXXXXXXXXXX----XXXXXXXXXXXX
.byte $00, $00                                  ; -------------- = ----------------------------

spriteAF:
.byte $04, $50                                  ; -----X---X-X---- = ----------XX--XX--XX--------
.byte $0A, $2C                                  ; ----X-X---X-XX-- = --------XX--XX--XX------XXXX
.byte $CF, $32                                  ; XX--XXXX--XX--X- = ----XXXXXXXXXXXXXX----XX----
.byte $6C, $FF                                  ; -XX-XX--XXXXXXXX = --XXXX----XXXXXXXXXXXXXXXXXX
.byte $74, $F1                                  ; -XXX-X--XXXX---X = XXXXXX----XX--XXXXXXXX------
.byte $CF, $CF                                  ; XX--XXXXXX--XXXX = ----XXXXXXXXXX----XXXXXXXXXX
.byte $FF, $72                                  ; XXXXXXXX-XXX--X- = XXXXXXXXXXXXXXXXXXXX--XX----
.byte $CF, $3C                                  ; XX--XXXX--XXXX-- = ----XXXXXXXXXXXXXX------XXXX
.byte $00, $00                                  ; ---------------- = ----------------------------
.byte $08, $00                                  ; ----X----------- = ------------XX--------------
.byte $E9, $F3                                  ; XXX-X--XXXXX--XX = --XXXXXX----XXXXXXXXXXXX----
.byte $9F, $04                                  ; X--XXXXX-----X-- = XX----XXXXXXXX----------XX--
.byte $18, $08                                  ; ---XX-------X--- = XX----------XX------------XX
.byte $9F, $F7                                  ; X--XXXXXXXXX-XXX = XX----XXXXXXXXXXXXXXXXXXXX--
.byte $E9, $F3                                  ; XXX-X--XXXXX--XX = --XXXXXX----XXXXXXXXXXXX----
.byte $08, $00                                  ; ----X----------- = ------------XX--------------

sprite19dw:                                     ; Double width for direct drawing when cheat-boot is active
.byte $30, $66, $03, $00                        ; -XX----XX--XX------XX------- = ----XX--XX--XXXX------------
.byte $70, $19, $03, $00                        ; XXX------XX--X-----XX------- = ----XXXX--XX--XX------------
.byte $70, $7F, $03, $00                        ; XXX----XXXXXXX-----XX------- = ----XXXXXXXXXXXX------------
.byte $00, $06, $00, $00                        ; -----------XX--------------- = --------XX------------------
.byte $00, $06, $00, $00                        ; -----------XX--------------- = --------XX------------------
.byte $40, $7F, $00, $00                        ; X------XXXXXXX-------------- = ------XXXXXXXX--------------
.byte $40, $61, $00, $00                        ; X------XX----X-------------- = ------XX----XX--------------
.byte $40, $61, $00, $00                        ; X------XX----X-------------- = ------XX----XX--------------
.byte $40, $61, $00, $00                        ; X------XX----X-------------- = ------XX----XX--------------
.byte $30, $18, $03, $00                        ; -XX------XX--------XX------- = ----XX----XX--XX------------
.byte $30, $60, $7C, $01                        ; -XX----XX-----XXXXX--------X = ----XX------XX--XXXXXX------
.byte $4C, $07, $0C, $06                        ; X--XX------XXX---XX------XX- = --XX--XXXX------XX----XX----
.byte $0C, $18, $03, $18                        ; ---XX----XX--------XX--XX--- = --XX------XX--XX--------XX--
.byte $0C, $18, $00, $18                        ; ---XX----XX------------XX--- = --XX------XX------------XX--
.byte $0C, $18, $00, $18                        ; ---XX----XX------------XX--- = --XX------XX------------XX--
.byte $7F, $7F, $7F, $7F                        ; XXXXXXXXXXXXXXXXXXXXXXXXXXXX = XXXXXXXXXXXXXXXXXXXXXXXXXXXX
