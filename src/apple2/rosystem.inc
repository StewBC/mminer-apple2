;-----------------------------------------------------------------------------
; rosystem.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
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
; multiplication lookup tables
mult1024H: 
.byte $00, $04, $08, $0C, $10, $14, $18, $1C, $20

mult64H:
.repeat MAX_SPRITE_IFRAMES, Row
    .byte >(Row * 64)
.endrep 

mult64L:
.repeat MAX_SPRITE_IFRAMES, Row
    .byte <(Row * 64)
.endrep 

mult32H:
.repeat 15, Row
    .byte >(Row * 32)
.endrep 

mult32L:
.repeat 15, Row
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
