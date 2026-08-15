;-----------------------------------------------------------------------------
; rosystem.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020, 2026
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "RODATA"

;-----------------------------------------------------------------------------
; the lo byte for the memory at the start of every screen row
rowL:
    .repeat $C0, Row
        .byte   Row & $08 << 4 | Row & $C0 >> 1 | Row & $C0 >> 3
    .endrep

;-----------------------------------------------------------------------------
; the hi byte for the memory at the start of every screen row
rowH:
    .repeat $C0, Row
        .byte   >$0000 | Row & $07 << 2 | Row & $30 >> 4
    .endrep

;-----------------------------------------------------------------------------
; Jump table for screen tile rendering, per row - unrolled loops
rowDrawL:
    .byte <tileDrawP0R0
    .byte <tileDrawP0R1
    .byte <tileDrawP0R2
    .byte <tileDrawP0R3
    .byte <tileDrawP0R4
    .byte <tileDrawP0R5
    .byte <tileDrawP0R6
    .byte <tileDrawP0R7
    .byte <tileDrawP0R8
    .byte <tileDrawP0R9
    .byte <tileDrawP0RA
    .byte <tileDrawP0RB
    .byte <tileDrawP0RC
    .byte <tileDrawP0RD
    .byte <tileDrawP0RE
    .byte <tileDrawP0RF
    .byte <tileDrawP1R0                         ; Page 1
    .byte <tileDrawP1R1
    .byte <tileDrawP1R2
    .byte <tileDrawP1R3
    .byte <tileDrawP1R4
    .byte <tileDrawP1R5
    .byte <tileDrawP1R6
    .byte <tileDrawP1R7
    .byte <tileDrawP1R8
    .byte <tileDrawP1R9
    .byte <tileDrawP1RA
    .byte <tileDrawP1RB
    .byte <tileDrawP1RC
    .byte <tileDrawP1RD
    .byte <tileDrawP1RE
    .byte <tileDrawP1RF

rowDrawH:
    .byte >tileDrawP0R0
    .byte >tileDrawP0R1
    .byte >tileDrawP0R2
    .byte >tileDrawP0R3
    .byte >tileDrawP0R4
    .byte >tileDrawP0R5
    .byte >tileDrawP0R6
    .byte >tileDrawP0R7
    .byte >tileDrawP0R8
    .byte >tileDrawP0R9
    .byte >tileDrawP0RA
    .byte >tileDrawP0RB
    .byte >tileDrawP0RC
    .byte >tileDrawP0RD
    .byte >tileDrawP0RE
    .byte >tileDrawP0RF
    .byte >tileDrawP1R0                         ; Page 1
    .byte >tileDrawP1R1
    .byte >tileDrawP1R2
    .byte >tileDrawP1R3
    .byte >tileDrawP1R4
    .byte >tileDrawP1R5
    .byte >tileDrawP1R6
    .byte >tileDrawP1R7
    .byte >tileDrawP1R8
    .byte >tileDrawP1R9
    .byte >tileDrawP1RA
    .byte >tileDrawP1RB
    .byte >tileDrawP1RC
    .byte >tileDrawP1RD
    .byte >tileDrawP1RE
    .byte >tileDrawP1RF

;-----------------------------------------------------------------------------
; Half-width Willy frame pointers. Entries 0..7 start on an even HGR byte.
; Entries 8..15 are shifted one dot for an odd HGR byte.
willyHalfFrameL:
    .lobytes sprite00Half, sprite01Half, sprite02Half, sprite03Half
    .lobytes sprite04Half, sprite05Half, sprite06Half, sprite07Half
    .lobytes sprite00HalfOdd, sprite01HalfOdd, sprite02HalfOdd, sprite03HalfOdd
    .lobytes sprite04HalfOdd, sprite05HalfOdd, sprite06HalfOdd, sprite07HalfOdd

willyHalfFrameH:
    .hibytes sprite00Half, sprite01Half, sprite02Half, sprite03Half
    .hibytes sprite04Half, sprite05Half, sprite06Half, sprite07Half
    .hibytes sprite00HalfOdd, sprite01HalfOdd, sprite02HalfOdd, sprite03HalfOdd
    .hibytes sprite04HalfOdd, sprite05HalfOdd, sprite06HalfOdd, sprite07HalfOdd

;-----------------------------------------------------------------------------
mult48H:
.repeat MAX_SPRITE_IFRAMES, Row
    .byte >(Row * SPRITE_BYTES)
.endrep

mult48L:
.repeat MAX_SPRITE_IFRAMES, Row
    .byte <(Row * SPRITE_BYTES)
.endrep

; Full-width Willy sprites are 64 bytes per frame.
; Eight entries: the lives display only walks frames 0..3, but I think the
; title screen steps Willy through all eight poses with screenDrawUIWilly.
uiMult64H:
.repeat 8, Row
    .byte >(Row * 64)
.endrep

uiMult64L:
.repeat 8, Row
    .byte <(Row * 64)
.endrep

; One entry per row - the dirty renderer marks cells on the bottom
; row too, so a 15-entry table was too short and this cause a bug
; where Ore Refinery's conveyor was messed up
mult32H:
.repeat PLAY_ROWS, Row
    .byte >(Row * 32)
.endrep

mult32L:
.repeat PLAY_ROWS, Row
    .byte <(Row * 32)
.endrep

mult16:
.repeat 9, Row
    .byte Row * 16
.endrep

mult8:
.repeat 24, Row
    .byte Row * 8
.endrep

;-----------------------------------------------------------------------------
; color masks
masksLeft:
.byte %11111111                                 ; 00 MSB-BITS-11..1 White
.byte %00101010                                 ; 01   0-BITS-01..0 Green
.byte %10101010                                 ; 04   1-BITS-01..0 Orange
.byte %01010101                                 ; 01   0-BITS-10..1 Purple
.byte %11010101                                 ; 02   1-BITS-10..1 Blue

masksRight:
.byte %11111111                                 ; 00  MSB-BITS-11 White
.byte %01010101                                 ; 01    0-BITS-10..1 Green
.byte %11010101                                 ; 04    1-BITS-10..1 Orange
.byte %00101010                                 ; 01    0-BITS-01..0 Purple
.byte %10101010                                 ; 02    1-BITS-01..0 Blue

maskGreen:
.byte %00101010, %01010101                      ; Green

maskOrange:
.byte %10101010, %11010101                      ; Orange

maskGreenHi:
.byte %00100000, %01000000                      ; Green

maskNewTip:
.byte %01011111, %00111111                      ; White air graph tip (reversed order)

;-----------------------------------------------------------------------------
; Rotate the seven display dots in one HGR byte one place to the right while
; preserving palette bit 7. Six applications rotate one place to the left.
halfRotateRight:
.repeat $100, B
    .byte (B & $80) | (B << 1 & $7E) | (B >> 6 & $01)
.endrep

;-----------------------------------------------------------------------------
; sprite 32 to 64 byte bit-double helper table
binDouble:
.byte %00000000
.byte %00000011
.byte %00001100
.byte %00001111
.byte %00110000
.byte %00110011
.byte %00111100
.byte %00111111
.byte %11000000
.byte %11000011
.byte %11001100
.byte %11001111
.byte %11110000
.byte %11110011
.byte %11111100
.byte %11111111
