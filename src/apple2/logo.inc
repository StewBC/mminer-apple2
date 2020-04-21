;-----------------------------------------------------------------------------
; logo.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "HGR"

.incbin "logo.hgr"

;-----------------------------------------------------------------------------
.segment "RODATA"

manicText:
.byte $88, $D8, $A8, $88, $88, $00, $00
.byte $00, $70, $88, $88, $F8, $88, $00
.byte $88, $C8, $A8, $98, $88, $00, $00
.byte $00, $00, $E0, $40, $40, $40, $E0
.byte $00, $70, $88, $80, $88, $70, $00

manicCharWidth:
.byte 6, 6, 6, 4, 5

manicColors:
.byte 2, 1, 0, 3, 4

;-----------------------------------------------------------------------------
minerText:
.byte $00, $00, $88, $D8, $A8, $88, $88
.byte $E0, $40, $40, $40, $E0, $00, $00
.byte $00, $88, $C8, $A8, $98, $88, $00
.byte $F8, $80, $F8, $80, $F8, $00, $00
.byte $00, $00, $F0, $88, $F0, $A0, $98

minerCharWidth:
.byte 6, 4, 6, 6, 5

minerColors:
.byte 3, 4, 2, 1, 0
