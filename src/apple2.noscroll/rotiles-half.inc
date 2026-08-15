;-----------------------------------------------------------------------------
; rotiles-half.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2026
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "RODATA"

;-----------------------------------------------------------------------------
.align 16                                       ; don't want tiles spanning boundaries

; Rows are 8 x [even-column byte, odd-column byte] and the two differ:
; run tiles are encoded seamlessly across a two-tile period, unique
; tiles get three whole colour pixels inside six dots.  A tile is one
; screen byte - 7 dots, 3.5 colour pixels - and screen.inc picks the
; byte by column parity.

tilesHalf:
tile00Half:  ; unique, 6 dots
.byte $80, $80                                  ; ------- / -------
.byte $80, $80                                  ; ------- / -------
.byte $80, $80                                  ; ------- / -------
.byte $80, $80                                  ; ------- / -------
.byte $80, $80                                  ; ------- / -------
.byte $80, $80                                  ; ------- / -------
.byte $80, $80                                  ; ------- / -------
.byte $80, $80                                  ; ------- / -------

tile01Half:  ; unique, 6 dots
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX

tile02Half:  ; unique, 6 dots
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--

tile03Half:  ; unique, 6 dots
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--

tile04Half:  ; unique, 6 dots
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX

tile05Half:  ; unique, 6 dots
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $8C, $98                                  ; --XX--- / ---XX--

tile06Half:  ; unique, 6 dots
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--

tile07Half:
.byte $FC, $FC                                  ; XXXXX-- = --XXXXX
.byte $B3, $B3                                  ; -XX--XX = XX--XX-
.byte $FC, $FC                                  ; XXXXX-- = --XXXXX
.byte $B3, $B3                                  ; -XX--XX = XX--XX-
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------

tile08Half:  ; unique, 6 dots
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--

tile09Half:  ; unique, 6 dots
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX

tile0AHalf:  ; unique, 6 dots
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--

tile0BHalf:  ; unique, 6 dots
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--

tile0CHalf:  ; unique, 6 dots
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX

tile0DHalf:
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8C, $98                                  ; --XX--- / ---XX--

tile0EHalf:
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX

tile0FHalf:  ; unique, 6 dots
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX

tile10Half:  ; unique, 6 dots
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $B0, $E0                                  ; ----XX- / -----XX
.byte $B0, $E0                                  ; ----XX- / -----XX

tile11Half:  ; unique, 6 dots
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX

tile12Half:
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--

tile13Half:  ; unique, 6 dots
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--

tile14Half:  ; unique, 6 dots
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX

tile15Half:  ; unique, 6 dots
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX

tile16Half:
.byte $F0, $F0                                  ; XXX---- = ----XXX
.byte $B3, $B3                                  ; -XX--XX = XX--XX-
.byte $F0, $F0                                  ; XXX---- = ----XXX
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------

tile17Half:  ; unique, 6 dots
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--

tile18Half:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX

tile19Half:  ; unique, 6 dots
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX

tile1AHalf:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX

tile1BHalf:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $F3, $E7                                  ; XX--XXX / XXX--XX
.byte $F3, $E7                                  ; XX--XXX / XXX--XX

tile1CHalf:
.byte $F3, $F3                                  ; XXX--XX = XX--XXX
.byte $BF, $BF                                  ; -XXXXXX = XXXXXX-
.byte $BC, $BC                                  ; -XXXX-- = --XXXX-
.byte $BF, $BF                                  ; -XXXXXX = XXXXXX-
.byte $80, $80                                  ; ------- = -------
.byte $CF, $CF                                  ; X--XXXX = XXXX--X
.byte $FF, $FF                                  ; XXXXXXX = XXXXXXX
.byte $80, $80                                  ; ------- = -------

tile1DHalf:
.byte $F3, $F3                                  ; XXX--XX = XX--XXX
.byte $BF, $BF                                  ; -XXXXXX = XXXXXX-
.byte $BC, $BC                                  ; -XXXX-- = --XXXX-
.byte $FF, $FF                                  ; XXXXXXX = XXXXXXX
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------

tile1EHalf:
.byte $F3, $F3                                  ; XXX--XX = XX--XXX
.byte $FF, $FF                                  ; XXXXXXX = XXXXXXX
.byte $BC, $BC                                  ; -XXXX-- = --XXXX-
.byte $BF, $BF                                  ; -XXXXXX = XXXXXX-
.byte $BF, $BF                                  ; -XXXXXX = XXXXXX-
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------

tile1FHalf:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $80, $80                                  ; ------- / -------
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $80, $80                                  ; ------- / -------
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $80, $80                                  ; ------- / -------
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $80, $80                                  ; ------- / -------

tile20Half:
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $F3, $E7                                  ; XX--XXX / XXX--XX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--

tile21Half:
.byte $CF, $CF                                  ; X--XXXX = XXXX--X
.byte $FF, $FF                                  ; XXXXXXX = XXXXXXX
.byte $FC, $FC                                  ; XXXXX-- = --XXXXX
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------
.byte $80, $80                                  ; ------- = -------

tile22Half:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $FC, $F9                                  ; --XXXXX / X--XXXX
.byte $FC, $F9                                  ; --XXXXX / X--XXXX
.byte $FC, $F9                                  ; --XXXXX / X--XXXX
.byte $FC, $F9                                  ; --XXXXX / X--XXXX
.byte $F3, $E7                                  ; XX--XXX / XXX--XX
.byte $C3, $87                                  ; XX----X / XXX----

tile23Half:  ; unique, 6 dots
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX

tile24Half:  ; unique, 6 dots
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX

tile25Half:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $CF, $9F                                  ; XXXX--X / XXXXX--
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $CF, $9F                                  ; XXXX--X / XXXXX--
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX

tile26Half:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX

tile27Half:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $CF, $9F                                  ; XXXX--X / XXXXX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $B0, $E0                                  ; ----XX- / -----XX
.byte $80, $80                                  ; ------- / -------

tile28Half:  ; unique, 6 dots
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--

tile29Half:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $CC, $99                                  ; --XX--X / X--XX--
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX

tile2AHalf:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--

tile2BHalf:  ; unique, 6 dots
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX

tile2CHalf:  ; unique, 6 dots
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--

tile2DHalf:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $CF, $9F                                  ; XXXX--X / XXXXX--
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $80, $80                                  ; ------- / -------

tile2EHalf:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $CF, $9F                                  ; XXXX--X / XXXXX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $CF, $9F                                  ; XXXX--X / XXXXX--
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $80, $80                                  ; ------- / -------

tile2FHalf:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $CF, $9F                                  ; XXXX--X / XXXXX--
.byte $CF, $9F                                  ; XXXX--X / XXXXX--
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $CF, $9F                                  ; XXXX--X / XXXXX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $80, $80                                  ; ------- / -------

tile30Half:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $F3, $E7                                  ; XX--XXX / XXX--XX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $80, $80                                  ; ------- / -------

tile31Half:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $F3, $E7                                  ; XX--XXX / XXX--XX
.byte $83, $86                                  ; XX----- / -XX----
.byte $80, $80                                  ; ------- / -------
.byte $80, $80                                  ; ------- / -------

tile32Half:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $80, $80                                  ; ------- / -------

tile33Half:
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $FF, $FF                                  ; XXXXXXX / XXXXXXX
.byte $80, $80                                  ; ------- / -------
.byte $80, $80                                  ; ------- / -------
.byte $80, $80                                  ; ------- / -------

tile34Half:  ; unique, 6 dots
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX

tile35Half:  ; unique, 6 dots
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--
.byte $8F, $9E                                  ; XXXX--- / -XXXX--

tile36Half:  ; unique, 6 dots
.byte $BF, $FE                                  ; XXXXXX- / -XXXXXX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $B3, $E6                                  ; XX--XX- / -XX--XX
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $8C, $98                                  ; --XX--- / ---XX--
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
.byte $BC, $F8                                  ; --XXXX- / ---XXXX
