;-----------------------------------------------------------------------------
; rotiles.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "RODATA"

;-----------------------------------------------------------------------------
.align 16                                       ; don't want tiles spanning boundaries

tiles:
tile00:
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------

tile01:
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $FC, $9F                                  ; XXXXX----XXXXX = --XXXXXXXXXX--
.byte $F3, $FF                                  ; XXX--XXXXXXXXX = XX--XXXXXXXXXX
.byte $F3, $FF                                  ; XXX--XXXXXXXXX = XX--XXXXXXXXXX
.byte $83, $FE                                  ; -----XXXXXXXX- = XX------XXXXXX
.byte $8F, $E0                                  ; ---XXXXXX----- = XXXX--------XX
.byte $FC, $9F                                  ; XXXXX----XXXXX = --XXXXXXXXXX--

tile02:
.byte $C0, $FF                                  ; X------XXXXXXX = ------XXXXXXXX
.byte $C0, $E1                                  ; X------XX----X = ------XX----XX
.byte $FC, $E7                                  ; XXXXX--XX--XXX = --XXXXXXXX--XX
.byte $8C, $FE                                  ; ---XX--XXXXXX- = --XX----XXXXXX
.byte $BF, $86                                  ; -XXXXXX----XX- = XXXXXX--XX----
.byte $F3, $87                                  ; XXX--XX----XXX = XX--XXXXXX----
.byte $C3, $81                                  ; X----XX------X = XX----XX------
.byte $FF, $81                                  ; XXXXXXX------X = XXXXXXXX------

tile03:
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------

tile04:
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $CF, $F9                                  ; X--XXXXXXXX--X = XXXX--XX--XXXX
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $CF, $F9                                  ; X--XXXXXXXX--X = XXXX--XX--XXXX
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $CC, $99                                  ; X--XX----XX--X = --XX--XX--XX--
.byte $C3, $E1                                  ; X----XXXX----X = XX----XX----XX

tile05:
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $CF, $F9                                  ; X--XXXXXXXX--X = XXXX--XX--XXXX
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $CF, $F9                                  ; X--XXXXXXXX--X = XXXX--XX--XXXX
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $8C, $98                                  ; ---XX----XX--- = --XX------XX--
.byte $8F, $F8                                  ; ---XXXXXXXX--- = XXXX------XXXX
.byte $B0, $86                                  ; -XX--------XX- = ----XX--XX----

tile06:
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $BC, $9E                                  ; -XXXX----XXXX- = --XXXX--XXXX--
.byte $8C, $98                                  ; ---XX----XX--- = --XX------XX--
.byte $CF, $F9                                  ; X--XXXXXXXX--X = XXXX--XX--XXXX
.byte $8F, $E6                                  ; ---XXXXXX--XX- = XXXX----XX--XX
.byte $BC, $98                                  ; -XXXX----XX--- = --XXXX----XX--
.byte $FC, $9F                                  ; XXXXX----XXXXX = --XXXXXXXXXX--
.byte $C0, $81                                  ; X------------X = ------XX------

tile07:
.byte $C0, $FF                                  ; X------XXXXXXX = ------XXXXXXXX
.byte $8F, $9E                                  ; ---XXXX--XXXX- = XXXX----XXXX--
.byte $C0, $FF                                  ; X------XXXXXXX = ------XXXXXXXX
.byte $8F, $9E                                  ; ---XXXX--XXXX- = XXXX----XXXX--
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------

tile08:
.byte $C0, $FF                                  ; X------XXXXXXX = ------XXXXXXXX
.byte $B0, $F8                                  ; -XX----XXXX--- = ----XX----XXXX
.byte $8C, $FE                                  ; ---XX--XXXXXX- = --XX----XXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $C3, $FF                                  ; X----XXXXXXXXX = XX----XXXXXXXX
.byte $C3, $9F                                  ; X----XX--XXXXX = XX----XXXXXX--
.byte $C3, $87                                  ; X----XX----XXX = XX----XXXX----
.byte $FF, $81                                  ; XXXXXXX------X = XXXXXXXX------

tile09:
.byte $F0, $81                                  ; XXX----------X = ----XXXX------
.byte $8C, $86                                  ; ---XX------XX- = --XX----XX----
.byte $83, $86                                  ; -----XX----XX- = XX------XX----
.byte $C3, $81                                  ; X----XX------X = XX----XX------
.byte $BC, $86                                  ; -XXXX------XX- = --XXXX--XX----
.byte $80, $98                                  ; ---------XX--- = ----------XX--
.byte $80, $E6                                  ; -------XX--XX- = --------XX--XX
.byte $80, $98                                  ; ---------XX--- = ----------XX--

tile0A:
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $FC, $99                                  ; XXXXX----XX--X = --XXXXXX--XX--
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $BF, $E6                                  ; -XXXXXXXX--XX- = XXXXXX--XX--XX
.byte $BF, $E6                                  ; -XXXXXXXX--XX- = XXXXXX--XX--XX
.byte $BF, $E6                                  ; -XXXXXXXX--XX- = XXXXXX--XX--XX
.byte $FC, $99                                  ; XXXXX----XX--X = --XXXXXX--XX--
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----

tile0B:
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $F3, $E7                                  ; XXX--XXXX--XXX = XX--XXXXXX--XX
.byte $BF, $FE                                  ; -XXXXXXXXXXXX- = XXXXXX--XXXXXX
.byte $BF, $FE                                  ; -XXXXXXXXXXXX- = XXXXXX--XXXXXX
.byte $F3, $E7                                  ; XXX--XXXX--XXX = XX--XXXXXX--XX
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----

tile0C:
.byte $8C, $98                                  ; ---XX----XX--- = --XX------XX--
.byte $8F, $FE                                  ; ---XXXXXXXXXX- = XXXX----XXXXXX
.byte $FF, $9F                                  ; XXXXXXX--XXXXX = XXXXXXXXXXXX--
.byte $BC, $E6                                  ; -XXXX--XX--XX- = --XXXX--XX--XX
.byte $B3, $9E                                  ; -XX--XX--XXXX- = XX--XX--XXXX--
.byte $FC, $E7                                  ; XXXXX--XX--XXX = --XXXXXXXX--XX
.byte $FF, $9F                                  ; XXXXXXX--XXXXX = XXXXXXXXXXXX--
.byte $8F, $FE                                  ; ---XXXXXXXXXX- = XXXX----XXXXXX

tile0D:
.byte $8C, $86                                  ; ---XX------XX- = --XX----XX----
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $B3, $80                                  ; -XX--XX------- = XX--XX--------
.byte $BC, $E0                                  ; -XXXX--XX----- = --XXXX------XX
.byte $B0, $E6                                  ; -XX----XX--XX- = ----XX--XX--XX
.byte $BF, $9E                                  ; -XXXXXX--XXXX- = XXXXXX--XXXX--
.byte $FC, $81                                  ; XXXXX--------X = --XXXXXX------
.byte $B0, $80                                  ; -XX----------- = ----XX--------

tile0E:
.byte $8C, $98                                  ; ---XX----XX--- = --XX------XX--
.byte $8C, $98                                  ; ---XX----XX--- = --XX------XX--
.byte $8C, $98                                  ; ---XX----XX--- = --XX------XX--
.byte $8C, $98                                  ; ---XX----XX--- = --XX------XX--
.byte $BC, $F8                                  ; -XXXX--XXXX--- = --XXXX----XXXX
.byte $BF, $FE                                  ; -XXXXXXXXXXXX- = XXXXXX--XXXXXX
.byte $BF, $FE                                  ; -XXXXXXXXXXXX- = XXXXXX--XXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX

tile0F:
.byte $8C, $86                                  ; ---XX------XX- = --XX----XX----
.byte $F3, $99                                  ; XXX--XX--XX--X = XX--XXXX--XX--
.byte $CC, $E7                                  ; X--XX--XX--XXX = --XX--XXXX--XX
.byte $C0, $99                                  ; X--------XX--X = ------XX--XX--
.byte $FC, $81                                  ; XXXXX--------X = --XXXXXX------
.byte $B3, $9E                                  ; -XX--XX--XXXX- = XX--XX--XXXX--
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $8C, $F8                                  ; ---XX--XXXX--- = --XX------XXXX

tile10:
.byte $BC, $80                                  ; -XXXX--------- = --XXXX--------
.byte $C3, $81                                  ; X----XX------X = XX----XX------
.byte $BC, $86                                  ; -XXXX------XX- = --XXXX--XX----
.byte $C3, $81                                  ; X----XX------X = XX----XX------
.byte $BC, $86                                  ; -XXXX------XX- = --XXXX--XX----
.byte $C0, $87                                  ; X----------XXX = ------XXXX----
.byte $80, $98                                  ; ---------XX--- = ----------XX--
.byte $80, $E0                                  ; -------XX----- = ------------XX

tile11:
.byte $FC, $9F                                  ; XXXXX----XXXXX = --XXXXXXXXXX--
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $BC, $98                                  ; -XXXX----XX--- = --XXXX----XX--
.byte $CF, $FF                                  ; X--XXXXXXXXXXX = XXXX--XXXXXXXX
.byte $83, $FE                                  ; -----XXXXXXXX- = XX------XXXXXX
.byte $CF, $FF                                  ; X--XXXXXXXXXXX = XXXX--XXXXXXXX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $FC, $9F                                  ; XXXXX----XXXXX = --XXXXXXXXXX--

tile12:
.byte $FC, $87                                  ; XXXXX------XXX = --XXXXXXXX----
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $CF, $FF                                  ; X--XXXXXXXXXXX = XXXX--XXXXXXXX
.byte $F0, $9F                                  ; XXX------XXXXX = ----XXXXXXXX--
.byte $C0, $87                                  ; X----------XXX = ------XXXX----
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------

tile13:
.byte $FC, $FF                                  ; XXXXX--XXXXXXX = --XXXXXXXXXXXX
.byte $F0, $9F                                  ; XXX------XXXXX = ----XXXXXXXX--
.byte $C0, $9F                                  ; X--------XXXXX = ------XXXXXX--
.byte $C0, $87                                  ; X----------XXX = ------XXXX----
.byte $C0, $87                                  ; X----------XXX = ------XXXX----
.byte $80, $86                                  ; -----------XX- = --------XX----
.byte $80, $86                                  ; -----------XX- = --------XX----
.byte $80, $86                                  ; -----------XX- = --------XX----

tile14:
.byte $83, $80                                  ; -----XX------- = XX------------
.byte $8F, $80                                  ; ---XXXX------- = XXXX----------
.byte $BF, $9E                                  ; -XXXXXX--XXXX- = XXXXXX--XXXX--
.byte $FC, $E1                                  ; XXXXX--XX----X = --XXXXXX----XX
.byte $B0, $86                                  ; -XX--------XX- = ----XX--XX----
.byte $CC, $99                                  ; X--XX----XX--X = --XX--XX--XX--
.byte $83, $E6                                  ; -----XXXX--XX- = XX------XX--XX
.byte $83, $F8                                  ; -----XXXXXX--- = XX--------XXXX

tile15:
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $8F, $F8                                  ; ---XXXXXXXX--- = XXXX------XXXX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $C3, $E1                                  ; X----XXXX----X = XX----XX----XX
.byte $C3, $E1                                  ; X----XXXX----X = XX----XX----XX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $8F, $F8                                  ; ---XXXXXXXX--- = XXXX------XXXX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX

tile16:
.byte $C3, $FF                                  ; X----XXXXXXXXX = XX----XXXXXXXX
.byte $8F, $9E                                  ; ---XXXX--XXXX- = XXXX----XXXX--
.byte $C3, $FF                                  ; X----XXXXXXXXX = XX----XXXXXXXX
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------

tile17:
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $8C, $98                                  ; ---XX----XX--- = --XX------XX--
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $CF, $F9                                  ; X--XXXXXXXX--X = XXXX--XX--XXXX
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $FC, $9F                                  ; XXXXX----XXXXX = --XXXXXXXXXX--
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $B0, $86                                  ; -XX--------XX- = ----XX--XX----

tile18:
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX

tile19:
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX

tile1A:
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $CC, $99                                  ; X--XX----XX--X = --XX--XX--XX--
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $CC, $99                                  ; X--XX----XX--X = --XX--XX--XX--
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $CC, $99                                  ; X--XX----XX--X = --XX--XX--XX--
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $CC, $99                                  ; X--XX----XX--X = --XX--XX--XX--

tile1B:
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $F3, $E7                                  ; XXX--XXXX--XXX = XX--XXXXXX--XX
.byte $F3, $F9                                  ; XXX--XXXXXX--X = XX--XXXX--XXXX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $8F, $E6                                  ; ---XXXXXX--XX- = XXXX----XX--XX
.byte $8F, $E6                                  ; ---XXXXXX--XX- = XXXX----XX--XX

tile1C:
.byte $8F, $F8                                  ; ---XXXXXXXX--- = XXXX------XXXX
.byte $BC, $9E                                  ; -XXXX----XXXX- = --XXXX--XXXX--
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $BC, $9E                                  ; -XXXX----XXXX- = --XXXX--XXXX--
.byte $80, $80                                  ; -------------- = --------------
.byte $C3, $E1                                  ; X----XXXX----X = XX----XX----XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $80, $80                                  ; -------------- = --------------

tile1D:
.byte $8F, $F8                                  ; ---XXXXXXXX--- = XXXX------XXXX
.byte $BC, $9E                                  ; -XXXX----XXXX- = --XXXX--XXXX--
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------

tile1E:
.byte $8F, $F8                                  ; ---XXXXXXXX--- = XXXX------XXXX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $BC, $9E                                  ; -XXXX----XXXX- = --XXXX--XXXX--
.byte $BC, $9E                                  ; -XXXX----XXXX- = --XXXX--XXXX--
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------

tile1F:
.byte $CF, $E7                                  ; X--XXXXXX--XXX = XXXX--XXXX--XX
.byte $80, $80                                  ; -------------- = --------------
.byte $BC, $FE                                  ; -XXXX--XXXXXX- = --XXXX--XXXXXX
.byte $80, $80                                  ; -------------- = --------------
.byte $CF, $E7                                  ; X--XXXXXX--XXX = XXXX--XXXX--XX
.byte $80, $80                                  ; -------------- = --------------
.byte $BC, $FE                                  ; -XXXX--XXXXXX- = --XXXX--XXXXXX
.byte $80, $80                                  ; -------------- = --------------

tile20:
.byte $FF, $87                                  ; XXXXXXX----XXX = XXXXXXXXXX----
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $83, $FE                                  ; -----XXXXXXXX- = XX------XXXXXX
.byte $C0, $87                                  ; X----------XXX = ------XXXX----
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------

tile21:
.byte $FF, $E7                                  ; XXXXXXXXX--XXX = XXXXXXXXXX--XX
.byte $BC, $F8                                  ; -XXXX--XXXX--- = --XXXX----XXXX
.byte $F3, $FF                                  ; XXX--XXXXXXXXX = XX--XXXXXXXXXX
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------

tile22:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FC, $9F                                  ; XXXXX----XXXXX = --XXXXXXXXXX--
.byte $F0, $E7                                  ; XXX----XX--XXX = ----XXXXXX--XX
.byte $C0, $F9                                  ; X------XXXX--X = ------XX--XXXX
.byte $C0, $FF                                  ; X------XXXXXXX = ------XXXXXXXX
.byte $B0, $FE                                  ; -XX----XXXXXX- = ----XX--XXXXXX
.byte $8C, $F8                                  ; ---XX--XXXX--- = --XX------XXXX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX

tile23:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX

tile24:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX

tile25:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $C3, $E1                                  ; X----XXXX----X = XX----XX----XX
.byte $F3, $F9                                  ; XXX--XXXXXX--X = XX--XXXX--XXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $C3, $E1                                  ; X----XXXX----X = XX----XX----XX
.byte $F3, $F9                                  ; XXX--XXXXXX--X = XX--XXXX--XXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX

tile26:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $CC, $99                                  ; X--XX----XX--X = --XX--XX--XX--
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $CC, $99                                  ; X--XX----XX--X = --XX--XX--XX--
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $CC, $99                                  ; X--XX----XX--X = --XX--XX--XX--
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX

tile27:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $CF, $E7                                  ; X--XXXXXX--XXX = XXXX--XXXX--XX
.byte $B3, $F8                                  ; -XX--XXXXXX--- = XX--XX----XXXX
.byte $B0, $98                                  ; -XX------XX--- = ----XX----XX--
.byte $CC, $E1                                  ; X--XX--XX----X = --XX--XX----XX
.byte $B0, $80                                  ; -XX----------- = ----XX--------
.byte $80, $86                                  ; -----------XX- = --------XX----
.byte $80, $80                                  ; -------------- = --------------

tile28:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $9F                                  ; XXXXXXX--XXXXX = XXXXXXXXXXXX--
.byte $FC, $9F                                  ; XXXXX----XXXXX = --XXXXXXXXXX--
.byte $FC, $87                                  ; XXXXX------XXX = --XXXXXXXX----
.byte $CC, $87                                  ; X--XX------XXX = --XX--XXXX----
.byte $CC, $87                                  ; X--XX------XXX = --XX--XXXX----
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------

tile29:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $C0, $E1                                  ; X------XX----X = ------XX----XX
.byte $B0, $98                                  ; -XX------XX--- = ----XX----XX--
.byte $8C, $86                                  ; ---XX------XX- = --XX----XX----
.byte $C3, $81                                  ; X----XX------X = XX----XX------
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX

tile2A:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------

tile2B:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $8C, $9E                                  ; ---XX----XXXX- = --XX----XXXX--
.byte $B0, $9E                                  ; -XX------XXXX- = ----XX--XXXX--
.byte $C0, $9F                                  ; X--------XXXXX = ------XXXXXX--
.byte $80, $9E                                  ; ---------XXXX- = --------XXXX--
.byte $80, $9E                                  ; ---------XXXX- = --------XXXX--
.byte $80, $9E                                  ; ---------XXXX- = --------XXXX--

tile2C:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $BC, $98                                  ; -XXXX----XX--- = --XXXX----XX--
.byte $BC, $86                                  ; -XXXX------XX- = --XXXX--XX----
.byte $FC, $81                                  ; XXXXX--------X = --XXXXXX------
.byte $BC, $80                                  ; -XXXX--------- = --XXXX--------
.byte $BC, $80                                  ; -XXXX--------- = --XXXX--------
.byte $BC, $80                                  ; -XXXX--------- = --XXXX--------

tile2D:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $BC, $9E                                  ; -XXXX----XXXX- = --XXXX--XXXX--
.byte $C3, $E1                                  ; X----XXXX----X = XX----XX----XX
.byte $8C, $98                                  ; ---XX----XX--- = --XX------XX--
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $FF, $99                                  ; XXXXXXX--XX--X = XXXXXXXX--XX--
.byte $80, $80                                  ; -------------- = --------------

tile2E:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $BC, $9E                                  ; -XXXX----XXXX- = --XXXX--XXXX--
.byte $C3, $E1                                  ; X----XXXX----X = XX----XX----XX
.byte $BC, $9E                                  ; -XXXX----XXXX- = --XXXX--XXXX--
.byte $C3, $E1                                  ; X----XXXX----X = XX----XX----XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $80, $80                                  ; -------------- = --------------

tile2F:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $C3, $E1                                  ; X----XXXX----X = XX----XX----XX
.byte $C3, $E1                                  ; X----XXXX----X = XX----XX----XX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $C3, $E1                                  ; X----XXXX----X = XX----XX----XX
.byte $BC, $9E                                  ; -XXXX----XXXX- = --XXXX--XXXX--
.byte $80, $80                                  ; -------------- = --------------

tile30:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $CF, $99                                  ; X--XXXX--XX--X = XXXX--XX--XX--
.byte $8C, $E6                                  ; ---XX--XX--XX- = --XX----XX--XX
.byte $B3, $98                                  ; -XX--XX--XX--- = XX--XX----XX--
.byte $CC, $81                                  ; X--XX--------X = --XX--XX------
.byte $83, $98                                  ; -----XX--XX--- = XX--------XX--
.byte $80, $80                                  ; -------------- = --------------

tile31:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $CF, $F9                                  ; X--XXXXXXXX--X = XXXX--XX--XXXX
.byte $FC, $9F                                  ; XXXXX----XXXXX = --XXXXXXXXXX--
.byte $8F, $E6                                  ; ---XXXXXX--XX- = XXXX----XX--XX
.byte $8C, $80                                  ; ---XX--------- = --XX----------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------

tile32:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $CF, $E7                                  ; X--XXXXXX--XXX = XXXX--XXXX--XX
.byte $FC, $FF                                  ; XXXXX--XXXXXXX = --XXXXXXXXXXXX
.byte $B3, $9B                                  ; -XX--XX--XX-XX = XX--XX-XX-XX--
.byte $CC, $E4                                  ; X--XX--XX--X-- = --XX--X--X--XX
.byte $B0, $98                                  ; -XX------XX--- = ----XX----XX--
.byte $80, $80                                  ; -------------- = --------------

tile33:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $B3, $E6                                  ; -XX--XXXX--XX- = XX--XX--XX--XX
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------
.byte $80, $80                                  ; -------------- = --------------

tile34:
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $CC, $99                                  ; X--XX----XX--X = --XX--XX--XX--
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $CF, $F9                                  ; X--XXXXXXXX--X = XXXX--XX--XXXX
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $CC, $99                                  ; X--XX----XX--X = --XX--XX--XX--

tile35:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $8C, $98                                  ; ---XX----XX--- = --XX------XX--
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $BC, $80                                  ; -XXXX--------- = --XXXX--------
.byte $BC, $80                                  ; -XXXX--------- = --XXXX--------

tile36:
.byte $FF, $FF                                  ; XXXXXXXXXXXXXX = XXXXXXXXXXXXXX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $83, $E0                                  ; -----XXXX----- = XX----------XX
.byte $8C, $98                                  ; ---XX----XX--- = --XX------XX--
.byte $F0, $87                                  ; XXX--------XXX = ----XXXXXX----
.byte $C0, $81                                  ; X------------X = ------XX------
.byte $80, $9E                                  ; ---------XXXX- = --------XXXX--
.byte $80, $9E                                  ; ---------XXXX- = --------XXXX--
