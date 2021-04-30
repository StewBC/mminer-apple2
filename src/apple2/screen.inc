;-----------------------------------------------------------------------------
; screen.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "CODE"

;-----------------------------------------------------------------------------
; Swap visible HGR pages and update currPageH to the back page hi byte
.proc screenSwap

    lda backPage
    beq  :+
    bit HISCR
    jmp valueSwap
:
    bit LOWSCR

valueSwap:

    lda backPage                                ; pretend flip the screen
    eor #1
    sta backPage
    lda #$60                                    ; pretend flip the screen Hi value so all drawing
    eor currPageH                               ; happens on the front screen
    sta currPageH
    rts

.endproc

;-----------------------------------------------------------------------------
; x 0 cleats top (play area minus 8 pixel row), x non-0 clears whole screen
.proc screenClear

    lda #$00

    ldy backPage
    beq page1
    jmp page2

page1:
    cpx #0
    bne :+
    jmp p1p2
:
    ldx #39
p1l1:
    .repeat $48, Row
        sta $100 * (>HGRPage1 + (Row + $78) & $07 << 2 | (Row + $78) & $30 >> 4) | (Row + $78) & $08 << 4 | (Row + $78) & $C0 >> 1 | (Row + $78) & $C0 >> 3, x
    .endrepeat
    dex
    bmi p1p2
    jmp p1l1

p1p2:
    ldx #39
p1l2:
    .repeat $78, Row
        sta $100 * (>HGRPage1 + Row & $07 << 2 | Row & $30 >> 4) | Row & $08 << 4 | Row & $C0 >> 1 | Row & $C0 >> 3, x
    .endrepeat
    dex
    bmi done0
    jmp p1l2

done0:
    rts

page2:
    cpx #0
    bne :+
    jmp p2p2
:
    ldx #39

p2l1:
    .repeat $48, Row
        sta $100 * (>HGRPage2 + (Row + $78) & $07 << 2 | (Row + $78) & $30 >> 4) | (Row + $78) & $08 << 4 | (Row + $78) & $C0 >> 1 | (Row + $78) & $C0 >> 3, x
    .endrepeat
    dex
    bmi p2p2
    jmp p2l1

p2p2:
    ldx #39
p2l2:
    .repeat $78, Row
        sta $100 * (>HGRPage2 + Row & $07 << 2 | Row & $30 >> 4) | Row & $08 << 4 | Row & $C0 >> 1 | Row & $C0 >> 3, x
    .endrepeat
    dex
    bmi done1
    jmp p2l2

done1:
    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDrawLevelName

    clc
    lda #20                                     ; screen is 20 "characters" wide
    adc leftEdge                                ; but maybe is offset from the left
    asl                                         ; mult by 2 for columns
    tay                                         ; put into y
    dey                                         ; but 0 based so 0-39 or whatever (not 1-40)
    ldx #39                                     ; screen index is 0-39

    lda currPageH
    cmp #$20
    bne page2

:
    lda levelNameGfx0 + $0000, y                ; load the cache
    sta $2050, x                                ; store to the screen (the hi byte is updated)

    lda levelNameGfx0 + $0040, y                ; but the lo byte ($50) is correct for row 16 (0 based)
    sta $2450, x

    lda levelNameGfx0 + $0080, y                ; the cache is linear so each line is $40 from previous
    sta $2850, x

    lda levelNameGfx0 + $00C0, y
    sta $2C50, x

    lda levelNameGfx0 + $0100, y
    sta $3050, x

    lda levelNameGfx0 + $0140, y
    sta $3450, x

    lda levelNameGfx0 + $0180, y
    sta $3850, x

    lda levelNameGfx0 + $01C0, y
    sta $3C50, x

    dey                                         ; previous cache byte
    dex                                         ; previous screen byte
    bpl :-                                      ; keep going till all 40 columns copied

    rts

page2:
    lda levelNameGfx0 + $0000, y                ; load the cache
    sta $4050, x                                ; store to the screen (the hi byte is updated)

    lda levelNameGfx0 + $0040, y                ; but the lo byte ($50) is correct for row 16 (0 based)
    sta $4450, x

    lda levelNameGfx0 + $0080, y
    sta $4850, x

    lda levelNameGfx0 + $00C0, y
    sta $4C50, x

    lda levelNameGfx0 + $0100, y
    sta $5050, x

    lda levelNameGfx0 + $0140, y
    sta $5450, x

    lda levelNameGfx0 + $0180, y
    sta $5850, x

    lda levelNameGfx0 + $01C0, y
    sta $5C50, x

    dey                                         ; previous cache byte
    dex                                         ; previous screen byte
    bpl page2                                   ; keep going till all 40 columns copied

    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDrawAirFrame

    lda currPageH                               ; see if this is to page 1 or 2
    cmp #$20
    bne page2

    ldx #28                                     ; draw the long green lines that outline the bar
:
    lda #%00101010                              ; green left
    sta $20DA, x
    sta $24DA, x
    sta $38DA, x
    sta $3CDA, x

    lda #%01010101                              ; green right
    sta $20DB, x
    sta $24DB, x
    sta $38DB, x
    sta $3CDB, x

    dex                                         ; step back in 2's for left/right
    dex
    bpl :-

    ldx #31                                     ; draw the even longer white bar that counts down
    lda #%01111111                              ; white left & right
:
    sta $28D7, x
    sta $2CD7, x
    sta $30D7, x
    sta $34D7, x

    dex                                         ; in 1's since left/right is the same $7f
    bpl :-

    rts

page2:                                          ; the same as page 1, just diff buffer
    ldx #28
:
    lda #%0101010
    sta $40DA, x
    sta $44DA, x
    sta $58DA, x
    sta $5CDA, x

    lda #%01010101
    sta $40DB, x
    sta $44DB, x
    sta $58DB, x
    sta $5CDB, x

    dex
    dex
    bpl :-

    ldx #31
    lda #%01111111                              ; white left & right
:
    sta $48D7, x
    sta $4CD7, x
    sta $50D7, x
    sta $54D7, x

    dex
    bpl :-

    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDrawAirRemaining

    lda airTipGfx                               ; the "graphic" to use
    ldx airCols                                 ; where to draw the tip of the graph
    cpx #3                                      ; last few cols are against orange
    bpl :+
    ora #$80                                    ; in the last few cols so make green orange
:
    ldy currPageH                               ; which page
    cpy #$20
    bne page2

    sta $28D7, x                                ; write the tip into page 1
    sta $2CD7, x
    sta $30D7, x
    sta $34D7, x

    rts

page2:
    sta $48D7, x                                ; write the tip into page 2
    sta $4CD7, x
    sta $50D7, x
    sta $54D7, x

    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDrawLevel
    levelReadL     = srcPtrL                    ; tile to draw in level
    levelReadH     = srcPtrH
    tileReadL      = dstPtrL                    ; data for tile to draw 
    tileReadH      = dstPtrH
    rows           = sizeL                      ; rows to draw (15 -> 0)
    cols           = sizeH                      ; cols to draw (20 + leftEdge -> leftEdge)

    lda #0
    sta tilesRendered
    sta cols
    sta rows
    tay

    lda leftEdge
    adc #<levelLayout
    sta levelReadL
    lda #>levelLayout
    sta levelReadH

nextRow:
    clc
    lda backPage
    beq :+
    lda #PLAY_ROWS
:
    adc rows
    tax
    lda rowDrawL,x
    sta tileDraw+1
    lda rowDrawH,x
    sta tileDraw+2
readLevelCol:
    lda (levelReadL),y
    beq nextCol
    inc tilesRendered
    sty cols                                    ; save the current col index
    pha                                         ; save the tile id
    and #$F0                                    ; strip to bare tile (no extra infor like collapse state)
    adc #<(tilesInstances - TILE_BYTES)         ; Index 1 has it's bytes at + 0, so move start 1 tile back
    sta tileReadL
    lda #>(tilesInstances - TILE_BYTES) + 1     ; carry always set, so + 1
    sta tileReadH                               ; points at the tile data
    tya                                         ; col to a
    asl                                         ; *2 since each tile is 2 cols on screen
    tax                                         ; put the sceen col into x
    pla                                         ; restore the tileID
    cmp #DATA_COLLAPSE+1                        ; see if the tile is an active collapsing tile (>=$71)
    bcc prepTileDraw                            ; could be $71->$77 for the collapsed state
    cmp #DATA_KEY
    bcc isCollapse                              ; if it's less than $80 it is a collapsing platform
    beq prepTileDraw                            ; is it a key
    cmp #DATA_DOOR                              ; if not a key, is it a door
    beq nextCol                                 ; door tile isn't a rendered tile, only a collision tile
setupSwitch:                                    ; if < door then it's a switch
    and #1                                      ; is this an on switch?
    beq :+                                      ; no
    lda #16                                     ; yes - the image is 16 bytes further (tile36)
:
    adc #<tile35                                ; add the offset of the switch image
    sta tileReadL
    lda #>tile35                                ; and set the hi byte too
    adc #0                                      ; turns out tile36 is in a different block (if I remove these 2 bytes          ;)
    sta tileReadH                               ; points at the tile data

prepTileDraw:
    ldy #0                                      ; set index for where to read tile data to the start
tileDraw:
    jsr PLACEHOLDER
    ldy cols
nextCol:
    iny
    cpy #VISIBLE_COLS
    bne readLevelCol
    ldy #0
    inc rows
    lda rows
    cmp #PLAY_ROWS
    beq allDrawn
    lda levelReadL
    adc #PLAY_COLS
    sta levelReadL
    bcc nextRow
    inc levelReadH
    bne nextRow                                 ; bra
isCollapse:
    and #7                                      ; get the level of collapse
    tay
    lda collapseHeight, y                       ; see how many lines remain to draw and skip bytes
    adc tileDraw+1                              ; base address of draw routine
    sta collapseDraw+1
    lda tileDraw+2
    adc #0
    sta collapseDraw+2
    ldy #0
collapseDraw:
    jsr PLACEHOLDER
    ldy cols
    jmp nextCol
allDrawn:
    lda currLevel
    cmp #LEVEL_Solar_Power_Generator            ; Is this the solar room
    bne :+                                      ; if not, move on
    jmp screenSolarBeam                         ; solar room needs a solar beam
:
    rts

.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R0
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2000,x
    iny
    lda (tileReadL),y
    sta $2001,x
    iny
    lda (tileReadL),y
    sta $2400,x
    iny
    lda (tileReadL),y
    sta $2401,x
    iny
    lda (tileReadL),y
    sta $2800,x
    iny
    lda (tileReadL),y
    sta $2801,x
    iny
    lda (tileReadL),y
    sta $2C00,x
    iny
    lda (tileReadL),y
    sta $2C01,x
    iny
    lda (tileReadL),y
    sta $3000,x
    iny
    lda (tileReadL),y
    sta $3001,x
    iny
    lda (tileReadL),y
    sta $3400,x
    iny
    lda (tileReadL),y
    sta $3401,x
    iny
    lda (tileReadL),y
    sta $3800,x
    iny
    lda (tileReadL),y
    sta $3801,x
    iny
    lda (tileReadL),y
    sta $3C00,x
    iny
    lda (tileReadL),y
    sta $3C01,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R0
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4000,x
    iny
    lda (tileReadL),y
    sta $4001,x
    iny
    lda (tileReadL),y
    sta $4400,x
    iny
    lda (tileReadL),y
    sta $4401,x
    iny
    lda (tileReadL),y
    sta $4800,x
    iny
    lda (tileReadL),y
    sta $4801,x
    iny
    lda (tileReadL),y
    sta $4C00,x
    iny
    lda (tileReadL),y
    sta $4C01,x
    iny
    lda (tileReadL),y
    sta $5000,x
    iny
    lda (tileReadL),y
    sta $5001,x
    iny
    lda (tileReadL),y
    sta $5400,x
    iny
    lda (tileReadL),y
    sta $5401,x
    iny
    lda (tileReadL),y
    sta $5800,x
    iny
    lda (tileReadL),y
    sta $5801,x
    iny
    lda (tileReadL),y
    sta $5C00,x
    iny
    lda (tileReadL),y
    sta $5C01,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R1
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2080,x
    iny
    lda (tileReadL),y
    sta $2081,x
    iny
    lda (tileReadL),y
    sta $2480,x
    iny
    lda (tileReadL),y
    sta $2481,x
    iny
    lda (tileReadL),y
    sta $2880,x
    iny
    lda (tileReadL),y
    sta $2881,x
    iny
    lda (tileReadL),y
    sta $2C80,x
    iny
    lda (tileReadL),y
    sta $2C81,x
    iny
    lda (tileReadL),y
    sta $3080,x
    iny
    lda (tileReadL),y
    sta $3081,x
    iny
    lda (tileReadL),y
    sta $3480,x
    iny
    lda (tileReadL),y
    sta $3481,x
    iny
    lda (tileReadL),y
    sta $3880,x
    iny
    lda (tileReadL),y
    sta $3881,x
    iny
    lda (tileReadL),y
    sta $3C80,x
    iny
    lda (tileReadL),y
    sta $3C81,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R1
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4080,x
    iny
    lda (tileReadL),y
    sta $4081,x
    iny
    lda (tileReadL),y
    sta $4480,x
    iny
    lda (tileReadL),y
    sta $4481,x
    iny
    lda (tileReadL),y
    sta $4880,x
    iny
    lda (tileReadL),y
    sta $4881,x
    iny
    lda (tileReadL),y
    sta $4C80,x
    iny
    lda (tileReadL),y
    sta $4C81,x
    iny
    lda (tileReadL),y
    sta $5080,x
    iny
    lda (tileReadL),y
    sta $5081,x
    iny
    lda (tileReadL),y
    sta $5480,x
    iny
    lda (tileReadL),y
    sta $5481,x
    iny
    lda (tileReadL),y
    sta $5880,x
    iny
    lda (tileReadL),y
    sta $5881,x
    iny
    lda (tileReadL),y
    sta $5C80,x
    iny
    lda (tileReadL),y
    sta $5C81,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R2
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2100,x
    iny
    lda (tileReadL),y
    sta $2101,x
    iny
    lda (tileReadL),y
    sta $2500,x
    iny
    lda (tileReadL),y
    sta $2501,x
    iny
    lda (tileReadL),y
    sta $2900,x
    iny
    lda (tileReadL),y
    sta $2901,x
    iny
    lda (tileReadL),y
    sta $2D00,x
    iny
    lda (tileReadL),y
    sta $2D01,x
    iny
    lda (tileReadL),y
    sta $3100,x
    iny
    lda (tileReadL),y
    sta $3101,x
    iny
    lda (tileReadL),y
    sta $3500,x
    iny
    lda (tileReadL),y
    sta $3501,x
    iny
    lda (tileReadL),y
    sta $3900,x
    iny
    lda (tileReadL),y
    sta $3901,x
    iny
    lda (tileReadL),y
    sta $3D00,x
    iny
    lda (tileReadL),y
    sta $3D01,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R2
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4100,x
    iny
    lda (tileReadL),y
    sta $4101,x
    iny
    lda (tileReadL),y
    sta $4500,x
    iny
    lda (tileReadL),y
    sta $4501,x
    iny
    lda (tileReadL),y
    sta $4900,x
    iny
    lda (tileReadL),y
    sta $4901,x
    iny
    lda (tileReadL),y
    sta $4D00,x
    iny
    lda (tileReadL),y
    sta $4D01,x
    iny
    lda (tileReadL),y
    sta $5100,x
    iny
    lda (tileReadL),y
    sta $5101,x
    iny
    lda (tileReadL),y
    sta $5500,x
    iny
    lda (tileReadL),y
    sta $5501,x
    iny
    lda (tileReadL),y
    sta $5900,x
    iny
    lda (tileReadL),y
    sta $5901,x
    iny
    lda (tileReadL),y
    sta $5D00,x
    iny
    lda (tileReadL),y
    sta $5D01,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R3
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2180,x
    iny
    lda (tileReadL),y
    sta $2181,x
    iny
    lda (tileReadL),y
    sta $2580,x
    iny
    lda (tileReadL),y
    sta $2581,x
    iny
    lda (tileReadL),y
    sta $2980,x
    iny
    lda (tileReadL),y
    sta $2981,x
    iny
    lda (tileReadL),y
    sta $2D80,x
    iny
    lda (tileReadL),y
    sta $2D81,x
    iny
    lda (tileReadL),y
    sta $3180,x
    iny
    lda (tileReadL),y
    sta $3181,x
    iny
    lda (tileReadL),y
    sta $3580,x
    iny
    lda (tileReadL),y
    sta $3581,x
    iny
    lda (tileReadL),y
    sta $3980,x
    iny
    lda (tileReadL),y
    sta $3981,x
    iny
    lda (tileReadL),y
    sta $3D80,x
    iny
    lda (tileReadL),y
    sta $3D81,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R3
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4180,x
    iny
    lda (tileReadL),y
    sta $4181,x
    iny
    lda (tileReadL),y
    sta $4580,x
    iny
    lda (tileReadL),y
    sta $4581,x
    iny
    lda (tileReadL),y
    sta $4980,x
    iny
    lda (tileReadL),y
    sta $4981,x
    iny
    lda (tileReadL),y
    sta $4D80,x
    iny
    lda (tileReadL),y
    sta $4D81,x
    iny
    lda (tileReadL),y
    sta $5180,x
    iny
    lda (tileReadL),y
    sta $5181,x
    iny
    lda (tileReadL),y
    sta $5580,x
    iny
    lda (tileReadL),y
    sta $5581,x
    iny
    lda (tileReadL),y
    sta $5980,x
    iny
    lda (tileReadL),y
    sta $5981,x
    iny
    lda (tileReadL),y
    sta $5D80,x
    iny
    lda (tileReadL),y
    sta $5D81,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R4
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2200,x
    iny
    lda (tileReadL),y
    sta $2201,x
    iny
    lda (tileReadL),y
    sta $2600,x
    iny
    lda (tileReadL),y
    sta $2601,x
    iny
    lda (tileReadL),y
    sta $2A00,x
    iny
    lda (tileReadL),y
    sta $2A01,x
    iny
    lda (tileReadL),y
    sta $2E00,x
    iny
    lda (tileReadL),y
    sta $2E01,x
    iny
    lda (tileReadL),y
    sta $3200,x
    iny
    lda (tileReadL),y
    sta $3201,x
    iny
    lda (tileReadL),y
    sta $3600,x
    iny
    lda (tileReadL),y
    sta $3601,x
    iny
    lda (tileReadL),y
    sta $3A00,x
    iny
    lda (tileReadL),y
    sta $3A01,x
    iny
    lda (tileReadL),y
    sta $3E00,x
    iny
    lda (tileReadL),y
    sta $3E01,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R4
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4200,x
    iny
    lda (tileReadL),y
    sta $4201,x
    iny
    lda (tileReadL),y
    sta $4600,x
    iny
    lda (tileReadL),y
    sta $4601,x
    iny
    lda (tileReadL),y
    sta $4A00,x
    iny
    lda (tileReadL),y
    sta $4A01,x
    iny
    lda (tileReadL),y
    sta $4E00,x
    iny
    lda (tileReadL),y
    sta $4E01,x
    iny
    lda (tileReadL),y
    sta $5200,x
    iny
    lda (tileReadL),y
    sta $5201,x
    iny
    lda (tileReadL),y
    sta $5600,x
    iny
    lda (tileReadL),y
    sta $5601,x
    iny
    lda (tileReadL),y
    sta $5A00,x
    iny
    lda (tileReadL),y
    sta $5A01,x
    iny
    lda (tileReadL),y
    sta $5E00,x
    iny
    lda (tileReadL),y
    sta $5E01,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R5
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2280,x
    iny
    lda (tileReadL),y
    sta $2281,x
    iny
    lda (tileReadL),y
    sta $2680,x
    iny
    lda (tileReadL),y
    sta $2681,x
    iny
    lda (tileReadL),y
    sta $2A80,x
    iny
    lda (tileReadL),y
    sta $2A81,x
    iny
    lda (tileReadL),y
    sta $2E80,x
    iny
    lda (tileReadL),y
    sta $2E81,x
    iny
    lda (tileReadL),y
    sta $3280,x
    iny
    lda (tileReadL),y
    sta $3281,x
    iny
    lda (tileReadL),y
    sta $3680,x
    iny
    lda (tileReadL),y
    sta $3681,x
    iny
    lda (tileReadL),y
    sta $3A80,x
    iny
    lda (tileReadL),y
    sta $3A81,x
    iny
    lda (tileReadL),y
    sta $3E80,x
    iny
    lda (tileReadL),y
    sta $3E81,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R5
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4280,x
    iny
    lda (tileReadL),y
    sta $4281,x
    iny
    lda (tileReadL),y
    sta $4680,x
    iny
    lda (tileReadL),y
    sta $4681,x
    iny
    lda (tileReadL),y
    sta $4A80,x
    iny
    lda (tileReadL),y
    sta $4A81,x
    iny
    lda (tileReadL),y
    sta $4E80,x
    iny
    lda (tileReadL),y
    sta $4E81,x
    iny
    lda (tileReadL),y
    sta $5280,x
    iny
    lda (tileReadL),y
    sta $5281,x
    iny
    lda (tileReadL),y
    sta $5680,x
    iny
    lda (tileReadL),y
    sta $5681,x
    iny
    lda (tileReadL),y
    sta $5A80,x
    iny
    lda (tileReadL),y
    sta $5A81,x
    iny
    lda (tileReadL),y
    sta $5E80,x
    iny
    lda (tileReadL),y
    sta $5E81,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R6
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2300,x
    iny
    lda (tileReadL),y
    sta $2301,x
    iny
    lda (tileReadL),y
    sta $2700,x
    iny
    lda (tileReadL),y
    sta $2701,x
    iny
    lda (tileReadL),y
    sta $2B00,x
    iny
    lda (tileReadL),y
    sta $2B01,x
    iny
    lda (tileReadL),y
    sta $2F00,x
    iny
    lda (tileReadL),y
    sta $2F01,x
    iny
    lda (tileReadL),y
    sta $3300,x
    iny
    lda (tileReadL),y
    sta $3301,x
    iny
    lda (tileReadL),y
    sta $3700,x
    iny
    lda (tileReadL),y
    sta $3701,x
    iny
    lda (tileReadL),y
    sta $3B00,x
    iny
    lda (tileReadL),y
    sta $3B01,x
    iny
    lda (tileReadL),y
    sta $3F00,x
    iny
    lda (tileReadL),y
    sta $3F01,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R6
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4300,x
    iny
    lda (tileReadL),y
    sta $4301,x
    iny
    lda (tileReadL),y
    sta $4700,x
    iny
    lda (tileReadL),y
    sta $4701,x
    iny
    lda (tileReadL),y
    sta $4B00,x
    iny
    lda (tileReadL),y
    sta $4B01,x
    iny
    lda (tileReadL),y
    sta $4F00,x
    iny
    lda (tileReadL),y
    sta $4F01,x
    iny
    lda (tileReadL),y
    sta $5300,x
    iny
    lda (tileReadL),y
    sta $5301,x
    iny
    lda (tileReadL),y
    sta $5700,x
    iny
    lda (tileReadL),y
    sta $5701,x
    iny
    lda (tileReadL),y
    sta $5B00,x
    iny
    lda (tileReadL),y
    sta $5B01,x
    iny
    lda (tileReadL),y
    sta $5F00,x
    iny
    lda (tileReadL),y
    sta $5F01,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R7
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2380,x
    iny
    lda (tileReadL),y
    sta $2381,x
    iny
    lda (tileReadL),y
    sta $2780,x
    iny
    lda (tileReadL),y
    sta $2781,x
    iny
    lda (tileReadL),y
    sta $2B80,x
    iny
    lda (tileReadL),y
    sta $2B81,x
    iny
    lda (tileReadL),y
    sta $2F80,x
    iny
    lda (tileReadL),y
    sta $2F81,x
    iny
    lda (tileReadL),y
    sta $3380,x
    iny
    lda (tileReadL),y
    sta $3381,x
    iny
    lda (tileReadL),y
    sta $3780,x
    iny
    lda (tileReadL),y
    sta $3781,x
    iny
    lda (tileReadL),y
    sta $3B80,x
    iny
    lda (tileReadL),y
    sta $3B81,x
    iny
    lda (tileReadL),y
    sta $3F80,x
    iny
    lda (tileReadL),y
    sta $3F81,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R7
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4380,x
    iny
    lda (tileReadL),y
    sta $4381,x
    iny
    lda (tileReadL),y
    sta $4780,x
    iny
    lda (tileReadL),y
    sta $4781,x
    iny
    lda (tileReadL),y
    sta $4B80,x
    iny
    lda (tileReadL),y
    sta $4B81,x
    iny
    lda (tileReadL),y
    sta $4F80,x
    iny
    lda (tileReadL),y
    sta $4F81,x
    iny
    lda (tileReadL),y
    sta $5380,x
    iny
    lda (tileReadL),y
    sta $5381,x
    iny
    lda (tileReadL),y
    sta $5780,x
    iny
    lda (tileReadL),y
    sta $5781,x
    iny
    lda (tileReadL),y
    sta $5B80,x
    iny
    lda (tileReadL),y
    sta $5B81,x
    iny
    lda (tileReadL),y
    sta $5F80,x
    iny
    lda (tileReadL),y
    sta $5F81,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R8
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2028,X
    iny
    lda (tileReadL),y
    sta $2029,X
    iny
    lda (tileReadL),y
    sta $2428,X
    iny
    lda (tileReadL),y
    sta $2429,X
    iny
    lda (tileReadL),y
    sta $2828,X
    iny
    lda (tileReadL),y
    sta $2829,X
    iny
    lda (tileReadL),y
    sta $2C28,X
    iny
    lda (tileReadL),y
    sta $2C29,X
    iny
    lda (tileReadL),y
    sta $3028,X
    iny
    lda (tileReadL),y
    sta $3029,X
    iny
    lda (tileReadL),y
    sta $3428,X
    iny
    lda (tileReadL),y
    sta $3429,X
    iny
    lda (tileReadL),y
    sta $3828,X
    iny
    lda (tileReadL),y
    sta $3829,X
    iny
    lda (tileReadL),y
    sta $3C28,X
    iny
    lda (tileReadL),y
    sta $3C29,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R8
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4028,X
    iny
    lda (tileReadL),y
    sta $4029,X
    iny
    lda (tileReadL),y
    sta $4428,X
    iny
    lda (tileReadL),y
    sta $4429,X
    iny
    lda (tileReadL),y
    sta $4828,X
    iny
    lda (tileReadL),y
    sta $4829,X
    iny
    lda (tileReadL),y
    sta $4C28,X
    iny
    lda (tileReadL),y
    sta $4C29,X
    iny
    lda (tileReadL),y
    sta $5028,X
    iny
    lda (tileReadL),y
    sta $5029,X
    iny
    lda (tileReadL),y
    sta $5428,X
    iny
    lda (tileReadL),y
    sta $5429,X
    iny
    lda (tileReadL),y
    sta $5828,X
    iny
    lda (tileReadL),y
    sta $5829,X
    iny
    lda (tileReadL),y
    sta $5C28,X
    iny
    lda (tileReadL),y
    sta $5C29,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R9
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $20A8,X
    iny
    lda (tileReadL),y
    sta $20A9,X
    iny
    lda (tileReadL),y
    sta $24A8,X
    iny
    lda (tileReadL),y
    sta $24A9,X
    iny
    lda (tileReadL),y
    sta $28A8,X
    iny
    lda (tileReadL),y
    sta $28A9,X
    iny
    lda (tileReadL),y
    sta $2CA8,X
    iny
    lda (tileReadL),y
    sta $2CA9,X
    iny
    lda (tileReadL),y
    sta $30A8,X
    iny
    lda (tileReadL),y
    sta $30A9,X
    iny
    lda (tileReadL),y
    sta $34A8,X
    iny
    lda (tileReadL),y
    sta $34A9,X
    iny
    lda (tileReadL),y
    sta $38A8,X
    iny
    lda (tileReadL),y
    sta $38A9,X
    iny
    lda (tileReadL),y
    sta $3CA8,X
    iny
    lda (tileReadL),y
    sta $3CA9,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R9
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $40A8,X
    iny
    lda (tileReadL),y
    sta $40A9,X
    iny
    lda (tileReadL),y
    sta $44A8,X
    iny
    lda (tileReadL),y
    sta $44A9,X
    iny
    lda (tileReadL),y
    sta $48A8,X
    iny
    lda (tileReadL),y
    sta $48A9,X
    iny
    lda (tileReadL),y
    sta $4CA8,X
    iny
    lda (tileReadL),y
    sta $4CA9,X
    iny
    lda (tileReadL),y
    sta $50A8,X
    iny
    lda (tileReadL),y
    sta $50A9,X
    iny
    lda (tileReadL),y
    sta $54A8,X
    iny
    lda (tileReadL),y
    sta $54A9,X
    iny
    lda (tileReadL),y
    sta $58A8,X
    iny
    lda (tileReadL),y
    sta $58A9,X
    iny
    lda (tileReadL),y
    sta $5CA8,X
    iny
    lda (tileReadL),y
    sta $5CA9,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0RA
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2128,X
    iny
    lda (tileReadL),y
    sta $2129,X
    iny
    lda (tileReadL),y
    sta $2528,X
    iny
    lda (tileReadL),y
    sta $2529,X
    iny
    lda (tileReadL),y
    sta $2928,X
    iny
    lda (tileReadL),y
    sta $2929,X
    iny
    lda (tileReadL),y
    sta $2D28,X
    iny
    lda (tileReadL),y
    sta $2D29,X
    iny
    lda (tileReadL),y
    sta $3128,X
    iny
    lda (tileReadL),y
    sta $3129,X
    iny
    lda (tileReadL),y
    sta $3528,X
    iny
    lda (tileReadL),y
    sta $3529,X
    iny
    lda (tileReadL),y
    sta $3928,X
    iny
    lda (tileReadL),y
    sta $3929,X
    iny
    lda (tileReadL),y
    sta $3D28,X
    iny
    lda (tileReadL),y
    sta $3D29,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1RA
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4128,X
    iny
    lda (tileReadL),y
    sta $4129,X
    iny
    lda (tileReadL),y
    sta $4528,X
    iny
    lda (tileReadL),y
    sta $4529,X
    iny
    lda (tileReadL),y
    sta $4928,X
    iny
    lda (tileReadL),y
    sta $4929,X
    iny
    lda (tileReadL),y
    sta $4D28,X
    iny
    lda (tileReadL),y
    sta $4D29,X
    iny
    lda (tileReadL),y
    sta $5128,X
    iny
    lda (tileReadL),y
    sta $5129,X
    iny
    lda (tileReadL),y
    sta $5528,X
    iny
    lda (tileReadL),y
    sta $5529,X
    iny
    lda (tileReadL),y
    sta $5928,X
    iny
    lda (tileReadL),y
    sta $5929,X
    iny
    lda (tileReadL),y
    sta $5D28,X
    iny
    lda (tileReadL),y
    sta $5D29,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0RB
    tileReadL      = dstPtrL                     ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $21A8,X
    iny
    lda (tileReadL),y
    sta $21A9,X
    iny
    lda (tileReadL),y
    sta $25A8,X
    iny
    lda (tileReadL),y
    sta $25A9,X
    iny
    lda (tileReadL),y
    sta $29A8,X
    iny
    lda (tileReadL),y
    sta $29A9,X
    iny
    lda (tileReadL),y
    sta $2DA8,X
    iny
    lda (tileReadL),y
    sta $2DA9,X
    iny
    lda (tileReadL),y
    sta $31A8,X
    iny
    lda (tileReadL),y
    sta $31A9,X
    iny
    lda (tileReadL),y
    sta $35A8,X
    iny
    lda (tileReadL),y
    sta $35A9,X
    iny
    lda (tileReadL),y
    sta $39A8,X
    iny
    lda (tileReadL),y
    sta $39A9,X
    iny
    lda (tileReadL),y
    sta $3DA8,X
    iny
    lda (tileReadL),y
    sta $3DA9,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1RB
    tileReadL      = dstPtrL                     ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $41A8,X
    iny
    lda (tileReadL),y
    sta $41A9,X
    iny
    lda (tileReadL),y
    sta $45A8,X
    iny
    lda (tileReadL),y
    sta $45A9,X
    iny
    lda (tileReadL),y
    sta $49A8,X
    iny
    lda (tileReadL),y
    sta $49A9,X
    iny
    lda (tileReadL),y
    sta $4DA8,X
    iny
    lda (tileReadL),y
    sta $4DA9,X
    iny
    lda (tileReadL),y
    sta $51A8,X
    iny
    lda (tileReadL),y
    sta $51A9,X
    iny
    lda (tileReadL),y
    sta $55A8,X
    iny
    lda (tileReadL),y
    sta $55A9,X
    iny
    lda (tileReadL),y
    sta $59A8,X
    iny
    lda (tileReadL),y
    sta $59A9,X
    iny
    lda (tileReadL),y
    sta $5DA8,X
    iny
    lda (tileReadL),y
    sta $5DA9,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0RC
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2228,X
    iny
    lda (tileReadL),y
    sta $2229,X
    iny
    lda (tileReadL),y
    sta $2628,X
    iny
    lda (tileReadL),y
    sta $2629,X
    iny
    lda (tileReadL),y
    sta $2A28,X
    iny
    lda (tileReadL),y
    sta $2A29,X
    iny
    lda (tileReadL),y
    sta $2E28,X
    iny
    lda (tileReadL),y
    sta $2E29,X
    iny
    lda (tileReadL),y
    sta $3228,X
    iny
    lda (tileReadL),y
    sta $3229,X
    iny
    lda (tileReadL),y
    sta $3628,X
    iny
    lda (tileReadL),y
    sta $3629,X
    iny
    lda (tileReadL),y
    sta $3A28,X
    iny
    lda (tileReadL),y
    sta $3A29,X
    iny
    lda (tileReadL),y
    sta $3E28,X
    iny
    lda (tileReadL),y
    sta $3E29,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1RC
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4228,X
    iny
    lda (tileReadL),y
    sta $4229,X
    iny
    lda (tileReadL),y
    sta $4628,X
    iny
    lda (tileReadL),y
    sta $4629,X
    iny
    lda (tileReadL),y
    sta $4A28,X
    iny
    lda (tileReadL),y
    sta $4A29,X
    iny
    lda (tileReadL),y
    sta $4E28,X
    iny
    lda (tileReadL),y
    sta $4E29,X
    iny
    lda (tileReadL),y
    sta $5228,X
    iny
    lda (tileReadL),y
    sta $5229,X
    iny
    lda (tileReadL),y
    sta $5628,X
    iny
    lda (tileReadL),y
    sta $5629,X
    iny
    lda (tileReadL),y
    sta $5A28,X
    iny
    lda (tileReadL),y
    sta $5A29,X
    iny
    lda (tileReadL),y
    sta $5E28,X
    iny
    lda (tileReadL),y
    sta $5E29,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0RD
    tileReadL      = dstPtrL                     ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $22A8,X
    iny
    lda (tileReadL),y
    sta $22A9,X
    iny
    lda (tileReadL),y
    sta $26A8,X
    iny
    lda (tileReadL),y
    sta $26A9,X
    iny
    lda (tileReadL),y
    sta $2AA8,X
    iny
    lda (tileReadL),y
    sta $2AA9,X
    iny
    lda (tileReadL),y
    sta $2EA8,X
    iny
    lda (tileReadL),y
    sta $2EA9,X
    iny
    lda (tileReadL),y
    sta $32A8,X
    iny
    lda (tileReadL),y
    sta $32A9,X
    iny
    lda (tileReadL),y
    sta $36A8,X
    iny
    lda (tileReadL),y
    sta $36A9,X
    iny
    lda (tileReadL),y
    sta $3AA8,X
    iny
    lda (tileReadL),y
    sta $3AA9,X
    iny
    lda (tileReadL),y
    sta $3EA8,X
    iny
    lda (tileReadL),y
    sta $3EA9,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1RD
    tileReadL      = dstPtrL                     ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $42A8,X
    iny
    lda (tileReadL),y
    sta $42A9,X
    iny
    lda (tileReadL),y
    sta $46A8,X
    iny
    lda (tileReadL),y
    sta $46A9,X
    iny
    lda (tileReadL),y
    sta $4AA8,X
    iny
    lda (tileReadL),y
    sta $4AA9,X
    iny
    lda (tileReadL),y
    sta $4EA8,X
    iny
    lda (tileReadL),y
    sta $4EA9,X
    iny
    lda (tileReadL),y
    sta $52A8,X
    iny
    lda (tileReadL),y
    sta $52A9,X
    iny
    lda (tileReadL),y
    sta $56A8,X
    iny
    lda (tileReadL),y
    sta $56A9,X
    iny
    lda (tileReadL),y
    sta $5AA8,X
    iny
    lda (tileReadL),y
    sta $5AA9,X
    iny
    lda (tileReadL),y
    sta $5EA8,X
    iny
    lda (tileReadL),y
    sta $5EA9,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0RE
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2328,X
    iny
    lda (tileReadL),y
    sta $2329,X
    iny
    lda (tileReadL),y
    sta $2728,X
    iny
    lda (tileReadL),y
    sta $2729,X
    iny
    lda (tileReadL),y
    sta $2B28,X
    iny
    lda (tileReadL),y
    sta $2B29,X
    iny
    lda (tileReadL),y
    sta $2F28,X
    iny
    lda (tileReadL),y
    sta $2F29,X
    iny
    lda (tileReadL),y
    sta $3328,X
    iny
    lda (tileReadL),y
    sta $3329,X
    iny
    lda (tileReadL),y
    sta $3728,X
    iny
    lda (tileReadL),y
    sta $3729,X
    iny
    lda (tileReadL),y
    sta $3B28,X
    iny
    lda (tileReadL),y
    sta $3B29,X
    iny
    lda (tileReadL),y
    sta $3F28,X
    iny
    lda (tileReadL),y
    sta $3F29,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1RE
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4328,X
    iny
    lda (tileReadL),y
    sta $4329,X
    iny
    lda (tileReadL),y
    sta $4728,X
    iny
    lda (tileReadL),y
    sta $4729,X
    iny
    lda (tileReadL),y
    sta $4B28,X
    iny
    lda (tileReadL),y
    sta $4B29,X
    iny
    lda (tileReadL),y
    sta $4F28,X
    iny
    lda (tileReadL),y
    sta $4F29,X
    iny
    lda (tileReadL),y
    sta $5328,X
    iny
    lda (tileReadL),y
    sta $5329,X
    iny
    lda (tileReadL),y
    sta $5728,X
    iny
    lda (tileReadL),y
    sta $5729,X
    iny
    lda (tileReadL),y
    sta $5B28,X
    iny
    lda (tileReadL),y
    sta $5B29,X
    iny
    lda (tileReadL),y
    sta $5F28,X
    iny
    lda (tileReadL),y
    sta $5F29,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0RF
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $23A8,X
    iny
    lda (tileReadL),y
    sta $23A9,X
    iny
    lda (tileReadL),y
    sta $27A8,X
    iny
    lda (tileReadL),y
    sta $27A9,X
    iny
    lda (tileReadL),y
    sta $2BA8,X
    iny
    lda (tileReadL),y
    sta $2BA9,X
    iny
    lda (tileReadL),y
    sta $2FA8,X
    iny
    lda (tileReadL),y
    sta $2FA9,X
    iny
    lda (tileReadL),y
    sta $33A8,X
    iny
    lda (tileReadL),y
    sta $33A9,X
    iny
    lda (tileReadL),y
    sta $37A8,X
    iny
    lda (tileReadL),y
    sta $37A9,X
    iny
    lda (tileReadL),y
    sta $3BA8,X
    iny
    lda (tileReadL),y
    sta $3BA9,X
    iny
    lda (tileReadL),y
    sta $3FA8,X
    iny
    lda (tileReadL),y
    sta $3FA9,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1RF
    tileReadL      = dstPtrL                    ; tile to draw's data
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $43A8,X
    iny
    lda (tileReadL),y
    sta $43A9,X
    iny
    lda (tileReadL),y
    sta $47A8,X
    iny
    lda (tileReadL),y
    sta $47A9,X
    iny
    lda (tileReadL),y
    sta $4BA8,X
    iny
    lda (tileReadL),y
    sta $4BA9,X
    iny
    lda (tileReadL),y
    sta $4FA8,X
    iny
    lda (tileReadL),y
    sta $4FA9,X
    iny
    lda (tileReadL),y
    sta $53A8,X
    iny
    lda (tileReadL),y
    sta $53A9,X
    iny
    lda (tileReadL),y
    sta $57A8,X
    iny
    lda (tileReadL),y
    sta $57A9,X
    iny
    lda (tileReadL),y
    sta $5BA8,X
    iny
    lda (tileReadL),y
    sta $5BA9,X
    iny
    lda (tileReadL),y
    sta $5FA8,X
    iny
    lda (tileReadL),y
    sta $5FA9,X
    rts
.endproc

;-----------------------------------------------------------------------------
.proc screenDrawSprites

    count = sizeL

    ldx numSprites                              ; render the AI
    dex                                         ; ignore the door
    stx count
:
    jsr screenDrawSprite
    dec count
    ldx count
    bpl :-

    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDrawSprite

    col   = sizeH
    lines = tmpBot +  0

    lda #0
    sta read + 1                                ; in case of left clipping, reset read
    lda #3
    sta stripLen + 1                            ; in case of right clipping, reset length

    lda spriteXPos, x                           ; col in 0..31 range
    sec
    sbc leftEdge                                ; move by the left edge
    bpl leftOK                                  ; if ge 0 then no clipping left
    cmp #$ff
    beq lClip

drawOffScreen:
    sta lines
    lda spriteClass, x
    bit CLASS_MOVE_Y
    beq :+                                      ; if yes, ignore
    jmp screenDrawOffscreenSprite               ; an off-screen amoeba gets an indicator
:
    rts

lClip:
    lda #2
    sta read + 1
    lda #1
    sta stripLen + 1
    lda #0
    bne rightOK                                 ; BRA

leftOK:
    cmp #19                                     ; clip on the right
    bcc rightOK
    beq rClip
    bne drawOffScreen                           ; BRA

rClip:
    lda #1
    sta stripLen + 1
    lda #19

rightOK:
    asl                                         ; multiply times 2
    sta col                                     ; screen column for where to start draw

    lda spriteFrame, x
    adc spriteFramesIdx, x
    tay
    lda mult64H, y                              ; and add the 64 * frame hi
    adc #>spriteInstances                       ; add the hi offset
    sta read + 2
    lda mult64L, y
    adc #<spriteInstances
    bcc :+
    inc read + 2
    clc
:
    adc read + 1
    sta read + 1

    lda spriteYPos, x                           ; get the y position of the sprite
    tay

    lda #16                                     ; sprites are 16 high
    sta lines

loop:
    lda col                                     ; start with the column
    adc rowL, y                                 ; add the row start
    sta write + 1
    lda rowH, y
    adc currPageH                               ; and the page
    sta write + 2                               ; write points at the line to copy 4 bytes to

stripLen:
    ldx #3                                      ; copy offsets 0..3
read:
    lda PLACEHOLDER, x                          ; get the bytes from src instance
write:
    sta PLACEHOLDER, x                          ; put them on screen
    dex
    bpl read                                    ; do all the bytes
    dec lines                                   ; one more line done
    beq done
    lda read + 1                                ; not all done, advance read by 4 bytes
    adc #4
    sta read + 1
    bcc :+
    inc read + 2
    clc
:
    iny                                         ; and go to next line
    bne loop                                    ; BRA

done:
    rts

.endproc

;-----------------------------------------------------------------------------
; used where vertical sprites are off-screen.  Sometimes it matters to gameplay
; that you know where a sprite is before you get on a conveyor
.proc screenDrawOffscreenSprite

    distance = tmpBot + 0
    color    = tmpBot + 1
    col      = tmpBot + 2

    lda distance
    bmi leftSide                                ; if negative, off on the left
    sbc #20                                     ; make 0 based distance
    lsr                                         ; half the distance
    sta distance                                ; save that
    lda spriteColor, x                          ; get the color of this amoeba
    tay
    lda masksRight, y                           ; and read the mask
    sta color                                   ; and save that
    lda #39                                     ; want to draw in the far right column
    sta col                                     ; save that
    bne drawBlock                               ; BRA

leftSide:
    eor #$FE                                    ; make distance positive 0+
    lsr                                         ; half the distance
    sta distance                                ; save
    lda spriteColor, x                          ; get the color index
    tay
    lda masksLeft, y                            ; get the actual color mask
    sta color                                   ; save it
    lda #0                                      ; draw in the left most column
    sta col                                     ; and save that

drawBlock:
    clc                                         ; carry undetermined
    lda spriteYPos, x                           ; get the sprite's position (at top)
    adc #5                                      ; put more or less in the center
    tay                                         ; put the draw row in y

    lda #5                                      ; start with a distance of 5
    sec
    sbc distance                                ; subtract the actual distance
    clc                                         ; make carry clear
    tax                                         ; but that distance as a height in X
:
    lda col                                     ; start with the column
    adc rowL, y                                 ; calculate the byte address for the row
    sta write + 1
    lda rowH, y
    adc currPageH                               ; include the hires buffer
    sta write + 2                               ; and save that as a write destination

    lda color                                   ; do all in the same color
write:
    sta PLACEHOLDER                             ; write the color to the column
    iny                                         ; next row
    dex                                         ; one less row to do
    bpl :-                                      ; and repeat for the height that indicates distance

done:
    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDrawLives

    allDone = tmpBot + 0

    ldx lives                                   ; how many lives to draw
    dex                                         ; make 0 based
    stx sizeL                                   ; store as in sizeL as how many to draw
    bpl :+                                      ; only if there's at least 1 spare, draw
    bmi maybeCheat

:
    lda #0
    sta allDone

    lda livesFrame                              ; get the animation frame
    lsr
    lsr
    tay
    lda mult64L, y                              ; mult 64
    clc
    adc #<sprites                               ; and add the sprite (willy) offset
    sta srcPtrL
    lda mult64H, y
    adc #>sprites
    sta srcPtrH                                 ; save as srcPtr

    txa                                         ; how many lives (0 based) into a for column offset calc

oloop:
    asl                                         ; mult * 4 to set them apart
    asl
    sta sizeH                                   ; store the column in sizeH
    lda #16                                     ; draw 16 lines
    sta dstPtrL                                 ; store the lines in dstPrkL

    ldy #22 * 8                                 ; Draw the lives in row 19 (0 based)

    lda srcPtrL                                 ; copy the srcPtr to where to read from
    sta read + 1
    lda srcPtrH
    sta read + 2

loop:
    lda sizeH                                   ; start with the column
    adc rowL, y                                 ; add the row start
    sta write + 1
    lda rowH, y
    adc currPageH                               ; and the page
    sta write + 2                               ; "write" points at the line to copy 4 bytes to

    ldx #3                                      ; copy offsets 0..3
read:
    lda PLACEHOLDER, x                          ; get the willy bytes
write:
    sta PLACEHOLDER, x                          ; put them on screen
    dex
    bpl read                                    ; do all the bytes
    dec dstPtrL                                 ; one more line done
    beq next                                    ; all lines done, see if more lives to draw
    lda read + 1                                ; not all done, advance read by 4 bytes
    adc #4
    sta read + 1
    bcc :+
    inc read + 2
    clc
:
    iny                                         ; and go to next line
    bne loop                                    ; BRA

next:
    dec sizeL                                   ; dec the count of lives to draw
    lda sizeL                                   ; get it in a to calc the column
    bpl oloop                                   ; and go do that if ge 0

    lda allDone                                 ; sentinel to stop looping when cheat active
    beq maybeCheat                              ; if not set then check if cheat is active

done:
    rts                                         ; exit

maybeCheat:
    lda cheatActive                             ; see if cheat mode is on
    beq done                                    ; if not then done
    sta allDone                                 ; set sentinel

    ldx lives                                   ; get the column to draw the boot
    txa
    asl                                         ; mult * 4 to set them apart
    asl
    sta sizeH                                   ; store the column in sizeH
    lda #16                                     ; draw 16 lines
    sta dstPtrL                                 ; store the lines in dstPrkL

    ldy #22 * 8                                 ; Draw the lives in row 19 (0 based)

    lda #<sprite19dw                            ; copy the srcPtr to where to read from
    sta read + 1
    lda #>sprite19dw
    sta read + 2
    jmp loop

.endproc

;-----------------------------------------------------------------------------
.proc screenDrawWilly

    row       = sizeL
    col       = sizeH
    lines     = tmpBot + 0
    willyByte = tmpBot + 1
    collision = tmpBot + 2
    detection = tmpBot + 3

    sta detection
    lda willyYPos                               ; get the y position of the sprite
    sta row 
    lda willyXPos                               ; col in 0..31 range
    sec
    sbc leftEdge                                ; move by the left edge
    asl                                         ; multiply times 2
    sta col                                     ; screen column for where to start draw
    lda #16                                     ; sprites are 16 high
    sta lines
    ldx #0                                      ; index into willy sprite data
    stx collision                               ; clear collision counter

    ldy willyFrame                              ; get the frame
    lda mult64L, y                              ; get the frame * 64 lo
    adc #<sprite00                              ; add instance base address
    sta willyRead + 1                           ; save as the lo src ptr
    lda #>sprite00                              ; add the hi offset
    adc mult64H, y                              ; and add the 64 * frame hi
    sta willyRead + 2                           ; willyRead now a pointer at the frame to show

rowSetup:
    clc
    ldy row                                     ; current row to draw
    lda col                                     ; start with the column
    adc rowL, y                                 ; add the row start
    sta dstPtrL
    lda rowH, y
    adc currPageH                               ; and the page
    sta dstPtrH                                 ; write points at the line to copy 4 bytes to
preWillyRead: 
    ldy #0                                      ; willy is 4 bytes wide
willyRead:
    lda PLACEHOLDER, x                          ; read a willy sprite byte
    beq nextCol                                 ; ignore the 0 bytes
    bit detection
    bne doDetect
    ora (dstPtrL), y                            ; add the screen byte
    sta (dstPtrL), y                            ; store it back
    bne nextCol                                 ; bra
doDetect:
    sta willyByte                               ; save the byte
    eor (dstPtrL), y                            ; add the screen byte
    sta (dstPtrL), y                            ; store it back
    and willyByte                               ; see if willy overlaps
    cmp willyByte
    beq nextCol                                 ; if not changed, no collision
    inc collision                               ; there was a collision
nextCol:
    inx                                         ; advance to next byte
    iny                                         ; next column
    cpy #4
    bcc willyRead                               ; still in a row doing columns
    dec lines                                   ; one less line to render
    beq done                                    ; if no lines left then done
    inc row                                     ; next row
    lda row                                     ; test to see if the row is at an address that needs lookup
    and #7 
    beq rowSetup
    lda dstPtrH                                 ; move down by $400 to next row
    clc
    adc #$04
    sta dstPtrH
    bne preWillyRead                            ; bra
done:
    lda collision
    cmp #1
    rts

.endproc 

;-----------------------------------------------------------------------------
; Mask the front screen with the color index passed in at tmpBot + 0 (colIdx)
.proc screenInvertVisibleScreen

    colIdx    = tmpBot + 0
    rows      = tmpBot + 1
    hiresRows = tmpBot + 2
    colL      = tmpBot + 3
    colR      = tmpBot + 4

    jsr screenSwap::valueSwap

    ldx colIdx                                  ; load the color mask based on the index
    lda masksLeft, x
    sta colL
    lda masksRight, x
    sta colR

    lda #PLAY_ROWS                              ; init a counter for how many rows to do
    sta rows
    lda #0                                      ; init the index to the starting hires row for the same "text" row
    sta hiresRows
    clc

rowLoop:
    ldy hiresRows                               ; init the pointer to the top line of the hires row
    lda rowL, y
    sta dstPtrL
    lda currPageH
    adc rowH, y
    sta dstPtrH

    ldy #2 * (VISIBLE_COLS - 1)                 ; start at column 38
colLoop:
    ldx #8                                      ; 8 hires rows per text row
:
    lda (dstPtrL), y                            ; get the left col/byte on screen
    and #%01111111                              ; ignore the msb
    eor colL                                    ; eor with the color
    sta (dstPtrL), y                            ; write it back
    iny                                         ; go to the right col
    lda (dstPtrL), y
    and #%01111111
    eor colR
    sta (dstPtrL), y
    dey                                         ; back to left
    dex                                         ; one more hires row done
    beq :+                                      ; all done?
    lda dstPtrH                                 ; not yet
    adc #4                                      ; move hires row down by 1
    sta dstPtrH
    bne :-                                      ; BRA to do all 8 hires rows
:
    lda dstPtrH                                 ; move the hires ptr back to the top row
    sec                                         ; for the text row being processed
    sbc #7*4
    sta dstPtrH
    clc                                         ; clear carry from last set

next:
    dey                                         ; move to the prev col right
    dey                                         ; and move to the prev col left
    bpl colLoop                                 ; and repeat for all columns ge 0

    dec rows                                    ; done a row
    beq done                                    ; stop when all rows done

    lda hiresRows                               ; more to do so move the hires
    clc                                         ; starting row down by 8 to be at the
    adc #8                                      ; start of the next "text" row
    sta hiresRows
    jmp rowLoop                                 ; go back and do this row now

done:
    jsr screenSwap::valueSwap                   ; put the screen buffer info back
    rts                                         ; all done

.endproc

;-----------------------------------------------------------------------------
.proc screenSolarBeam

    worldPtrL    = srcPtrL
    worldPtrH    = srcPtrH
    screenPtrL   = dstPtrL
    screenPtrH   = dstPtrH
    column       = sizeL
    row          = sizeH
    screenCol    = tmpBot + 0
    direction    = tmpBot + 1
    collision    = tmpBot + 2
    isWilly      = tmpBot + 3

    lda #0                                      ; init some local variables to 0
    sta row
    sta direction
    sta collision
    sta isWilly

    lda #23                                     ; column where solar beam starts
    sta column
    sta worldPtrL                               ; also the column in levelLayout (aligned in mem)
    lda #>levelLayout                           ; make worldPtr point at the start of the beam
    sta worldPtrH

while:
    lda column                                  ; start with the column
    sec
    sbc leftEdge                                ; and see if it's on screen
    bmi beamLeft                                ; if c - le <= 0 then c is left of screen and done
    sta screenCol                               ; save this
    cmp #20                                     ; if c - le >= 20 then c is to right of screen
    bcc onScreen                                ; c - l1 >= 0 and < 20 so visible

offScreen:
    ldy #0                                      ; beam is to the right so may become visible
    lda (worldPtrL), y                          ; see if beam hits a world tile
    beq :+                                      ; if not, process beam
beamLeft:
    jmp done
:
    ldx numSprites                              ; need to see if beam hits a sprite (not door) to bend
checkLoop:
    dex
    bmi checkCollision                          ; checked all sprites
    lda spriteXPos, x                           ; get the sprite x
    cmp column                                  ; compare to the beam x
    beq matchX                                  ; if it matches it's a hit
    bcs checkLoop                               ; sprite is to the right of the beam
    adc #1                                      ; right col of the sprite
    cmp column                                  ; is it in the beam?
    bne checkLoop                               ; if not this sprite is out
matchX:
    lda spriteYPos, x                           ; see if y also matches
    cmp row                                     ; test against beam height
    beq matchy
    bcs checkLoop                               ; sprite top is lower than beam
    adc #16                                     ; prep to test bottom of sprite
    cmp row                                     ; against the beam
    bcc checkLoop                               ; sprite bottom is above beam
matchy:
    inc collision                               ; set the collision
    bne checkCollision                          ; and exit the check since sprites don't overlap

onScreen:
    lda willyYPos                               ; see if the beam intersects willy
    adc #16                                     ; if willyY + 16 >= row and willyY <= row + 8
    cmp row                                     ; then willy intersects in Y
    bcc drawBlock
    clc
    lda row
    adc #8
    cmp willyYPos
    bcc drawBlock
    lda column                                  ; if col >= willyX and col < willyX + 3
    cmp willyXPos                               ; then willy intersects in X also, so hitting willy
    bcc drawBlock
    lda willyXPos
    clc
    adc #2
    cmp column
    bcc drawBlock
    sta isWilly                                 ; set isWIlly to true when hitting willy
    clc

drawBlock:
    ldy row                                     ; set up to draw
    lda screenCol                               ; on screen
    asl                                         ; which is 2 bytes per column
    adc rowL, y
    sta screenPtrL
    lda rowH, y
    adc currPageH
    sta screenPtrH

    ldx #8                                      ; beam block is 8 rows high
    ldy #0                                      ; y 0 and 1 for left and right
blockLoop:
    lda (screenPtrL), y                         ; get what's on screen (sprite)
    beq nocol                                   ; if nothing just overwrite
    inc collision                               ; hit a sprite
nocol:
    ora #%10101010                              ; orange left
    sta (screenPtrL), y                         ; write to screen

    iny                                         ; go to right column

    lda (screenPtrL), y                         ; repeat for right col
    beq :+
    inc collision
:
    ora #%11010101
    sta (screenPtrL), y

    dey                                         ; set y back to 0
    dex                                         ; done one more row
    beq checkCollision                          ; if all rows done, then done with plot

    lda screenPtrH                              ; move down a row by adding $0400
    adc #$04
    sta screenPtrH
    bne blockLoop                               ; BRA

checkCollision:
    lda isWilly                                 ; was willy hit
    beq chkDirChng                              ; if not, normal collision checks
    lda #2                                      ; don't set airflow to less than 2 so both
    cmp airFlow                                 ; buffers get to draw
    bcs :+
    sta airFlow
:
    lda #0                                      ; willy was hit so reset locals
    sta isWilly
    beq setCollision                            ; go move the beam
chkDirChng:
    lda collision                               ; see if there was a collision
    beq moveBeam                                ; if there wasn't move the beam
    lda direction                               ; there was a sprite collision
    eor #1                                      ; so change the direction of the beam
    sta direction
    lda #0
setCollision:
    sta collision                               ; reset the collision counter
moveBeam:
    lda direction                               ; get the beam direction
    beq down                                    ; 0 is down and 1 is left
left:
    dec column                                  ; move a world column left
    lda worldPtrL                               ; and move the pointer as well
    bne :+
    dec worldPtrH
:
    dec worldPtrL
    jmp checkWorld                              ; see that the new location isn't a world tile

down:
    clc
    lda row                                     ; move the row
    adc #8                                      ; down by 8 (1 block height)
    sta row
    lda worldPtrL                               ; and move the world pointer as well
    adc #32
    sta worldPtrL
    bcc checkWorld
    inc worldPtrH

checkWorld:
    lda (worldPtrL), y                          ; load a world location
    bne done                                    ; if occupied, beam dies
    jmp while                                   ; keep going till beam dies
done:
    rts

.endproc
