;-----------------------------------------------------------------------------
; rofont-half.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2026
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "RODATA"

;-----------------------------------------------------------------------------
; Half-width font: 8 rows x 1 byte.
fontHalf:
font00Half:
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------

font06Half:
.byte $80                                       ; ------- = -------
.byte $8C                                       ; ---XX-- = --XX---
.byte $8F                                       ; ---XXXX = XXXX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font07Half:
.byte $80                                       ; ------- = -------
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------

font0CHalf:
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---

font0DHalf:
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------

font0EHalf:
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------

font0FHalf:
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $B0                                       ; -XX---- = ----XX-
.byte $B0                                       ; -XX---- = ----XX-
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $83                                       ; -----XX = XX-----
.byte $80                                       ; ------- = -------

font10Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font11Half:
.byte $80                                       ; ------- = -------
.byte $8C                                       ; ---XX-- = --XX---
.byte $8F                                       ; ---XXXX = XXXX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font12Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B0                                       ; -XX---- = ----XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $83                                       ; -----XX = XX-----
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font13Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BC                                       ; -XXXX-- = --XXXX-
.byte $B0                                       ; -XX---- = ----XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font14Half:
.byte $80                                       ; ------- = -------
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $8F                                       ; ---XXXX = XXXX---
.byte $8F                                       ; ---XXXX = XXXX---
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------

font15Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $83                                       ; -----XX = XX-----
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B0                                       ; -XX---- = ----XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font16Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $83                                       ; -----XX = XX-----
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font17Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B0                                       ; -XX---- = ----XX-
.byte $B0                                       ; -XX---- = ----XX-
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------

font18Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font19Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B0                                       ; -XX---- = ----XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font1AHalf:
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------

font1BHalf:
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $83                                       ; -----XX = XX-----

font1CHalf:
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $B0                                       ; -XX---- = ----XX-
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $B0                                       ; -XX---- = ----XX-
.byte $80                                       ; ------- = -------

font1DHalf:
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------

font1EHalf:
.byte $80                                       ; ------- = -------
.byte $80                                       ; ------- = -------
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $B0                                       ; -XX---- = ----XX-
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------

font1FHalf:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B0                                       ; -XX---- = ----XX-
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------

font20Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $83                                       ; -----XX = XX-----
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font21Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $80                                       ; ------- = -------

font22Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $8F                                       ; ---XXXX = XXXX---
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font23Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $83                                       ; -----XX = XX-----
.byte $83                                       ; -----XX = XX-----
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font24Half:
.byte $80                                       ; ------- = -------
.byte $8F                                       ; ---XXXX = XXXX---
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $8F                                       ; ---XXXX = XXXX---
.byte $80                                       ; ------- = -------

font25Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $83                                       ; -----XX = XX-----
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $83                                       ; -----XX = XX-----
.byte $83                                       ; -----XX = XX-----
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font26Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $83                                       ; -----XX = XX-----
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $83                                       ; -----XX = XX-----
.byte $83                                       ; -----XX = XX-----
.byte $83                                       ; -----XX = XX-----
.byte $80                                       ; ------- = -------

font27Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $83                                       ; -----XX = XX-----
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font28Half:
.byte $80                                       ; ------- = -------
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $80                                       ; ------- = -------

font29Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font2AHalf:
.byte $80                                       ; ------- = -------
.byte $B0                                       ; -XX---- = ----XX-
.byte $B0                                       ; -XX---- = ----XX-
.byte $B0                                       ; -XX---- = ----XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font2BHalf:
.byte $80                                       ; ------- = -------
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $8F                                       ; ---XXXX = XXXX---
.byte $8F                                       ; ---XXXX = XXXX---
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $80                                       ; ------- = -------

font2CHalf:
.byte $80                                       ; ------- = -------
.byte $83                                       ; -----XX = XX-----
.byte $83                                       ; -----XX = XX-----
.byte $83                                       ; -----XX = XX-----
.byte $83                                       ; -----XX = XX-----
.byte $83                                       ; -----XX = XX-----
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font2DHalf:
.byte $80                                       ; ------- = -------
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XX--XX = XXXXXX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $80                                       ; ------- = -------

font2EHalf:
.byte $80                                       ; ------- = -------
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $80                                       ; ------- = -------

font2FHalf:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font30Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $83                                       ; -----XX = XX-----
.byte $83                                       ; -----XX = XX-----
.byte $80                                       ; ------- = -------

font31Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font32Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $8F                                       ; ---XXXX = XXXX---
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $80                                       ; ------- = -------

font33Half:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $83                                       ; -----XX = XX-----
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B0                                       ; -XX---- = ----XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font34Half:
.byte $80                                       ; ------- = -------
.byte $7F                                       ; -XXXXXX = XXXXXX-
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------

font35Half:
.byte $80                                       ; ------- = -------
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font36Half:
.byte $80                                       ; ------- = -------
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------

font37Half:
.byte $80                                       ; ------- = -------
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BF                                       ; -XX--XX = XXXXXX-
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $80                                       ; ------- = -------

font38Half:
.byte $80                                       ; ------- = -------
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $80                                       ; ------- = -------

font39Half:
.byte $80                                       ; ------- = -------
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BC                                       ; -XXXX-- = --XXXX-
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $80                                       ; ------- = -------

font3AHalf:
.byte $80                                       ; ------- = -------
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $B0                                       ; -XX---- = ----XX-
.byte $8C                                       ; ---XX-- = --XX---
.byte $8C                                       ; ---XX-- = --XX---
.byte $83                                       ; -----XX = XX-----
.byte $BF                                       ; -XXXXXX = XXXXXX-
.byte $80                                       ; ------- = -------

font5FHalf:
.byte $BC                                       ; -XXXX-- = --XXXX-
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $CF                                       ; X--XXXX = XXXX--X
.byte $CF                                       ; X--XXXX = XXXX--X
.byte $CF                                       ; X--XXXX = XXXX--X
.byte $CF                                       ; X--XXXX = XXXX--X
.byte $B3                                       ; -XX--XX = XX--XX-
.byte $BC                                       ; -XXXX-- = --XXXX-
