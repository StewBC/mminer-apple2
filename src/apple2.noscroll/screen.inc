;-----------------------------------------------------------------------------
; screen.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020, 2026
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
; x 0 clears the centred play area (minus its last 8 rows); x non-0 clears all
.proc screenClear

    lda #$00

    ldy backPage
    beq page1
    jmp page2

page1:
    cpx #0
    bne p1full
    lda #MARGIN
    sta sizeL                                   ; regular frame: clear only the centred playfield
    lda #0
    ldx #MARGIN + PLAY_COLS - 1
    jmp p1l2
p1full:
    lda #0
    sta sizeL                                   ; full clear: include margins and the UI band
    ldx #HGR_ROW_BYTES - 1
p1l1:
    .repeat $48, Row
        sta $100 * (>HGRPage1 + (Row + $78) & $07 << 2 | (Row + $78) & $30 >> 4) | (Row + $78) & $08 << 4 | (Row + $78) & $C0 >> 1 | (Row + $78) & $C0 >> 3, x
    .endrepeat
    dex
    bmi p1fullTop
    jmp p1l1

p1fullTop:
    ldx #HGR_ROW_BYTES - 1
p1l2:
    .repeat $78, Row
        sta $100 * (>HGRPage1 + Row & $07 << 2 | Row & $30 >> 4) | Row & $08 << 4 | Row & $C0 >> 1 | Row & $C0 >> 3, x
    .endrepeat
    cpx sizeL
    beq done0
    dex
    jmp p1l2

done0:
    rts

page2:
    cpx #0
    bne p2full
    lda #MARGIN
    sta sizeL                                   ; regular frame: clear only the centred playfield
    lda #0
    ldx #MARGIN + PLAY_COLS - 1
    jmp p2l2
p2full:
    lda #0
    sta sizeL                                   ; full clear: include margins and the UI band
    ldx #HGR_ROW_BYTES - 1

p2l1:
    .repeat $48, Row
        sta $100 * (>HGRPage2 + (Row + $78) & $07 << 2 | (Row + $78) & $30 >> 4) | (Row + $78) & $08 << 4 | (Row + $78) & $C0 >> 1 | (Row + $78) & $C0 >> 3, x
    .endrepeat
    dex
    bmi p2fullTop
    jmp p2l1

p2fullTop:
    ldx #HGR_ROW_BYTES - 1
p2l2:
    .repeat $78, Row
        sta $100 * (>HGRPage2 + Row & $07 << 2 | Row & $30 >> 4) | Row & $08 << 4 | Row & $C0 >> 1 | Row & $C0 >> 3, x
    .endrepeat
    cpx sizeL
    beq done1
    dex
    jmp p2l2

done1:
    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDirtyInitLevel

    rowBase = tmpBot + 0

    lda #0
    sta tilesRendered
    sta tilesRenderedHi
    sta rowBase
    sta dirtyAnimCount
    ldx #MAX_DIRTY_COLLAPSE_TILES - 1
:
    sta dirtyCollapseAge, x
    dex
    bpl :-
    lda #<levelLayout
    sta read + 1
    lda #>levelLayout
    sta read + 2
    ldx #0
    ldy #0

read:
    lda PLACEHOLDER, x
    beq next
    inc tilesRendered
    bne :+
    inc tilesRenderedHi
:
    and #$F0
    cmp #DATA_KEY
    beq animated
    cmp #DATA_CONVEYOR
    bne next
animated:
    cpy #MAX_DIRTY_ANIM_TILES
    bcs next                                    ; current level data peaks below the cap
    txa
    and #PLAY_COLS - 1
    sta dirtyAnimCols, y
    txa
    lsr
    lsr
    lsr
    lsr
    lsr
    clc
    adc rowBase
    sta dirtyAnimRows, y
    iny
next:
    inx
    bne read
    lda rowBase
    bne done                                    ; two 256-byte halves cover the 32x16 layout
    lda #8
    sta rowBase
    inc read + 2
    bne read                                    ; BRA
done:
    sty dirtyAnimCount
    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDirtyQueueCollapse

    col = sizeL
    row = sizeH

    sta col
    sty row
    lda #$ff
    sta dirtyIndex                              ; remember the last free slot while looking for a match
    ldx #MAX_DIRTY_COLLAPSE_TILES - 1
find:
    lda dirtyCollapseAge, x
    bne occupied
    stx dirtyIndex
    jmp next
occupied:
    lda dirtyCollapseCols, x
    cmp col
    bne next
    lda dirtyCollapseRows, x
    cmp row
    beq use
next:
    dex
    bpl find
    ldx dirtyIndex
    bpl use
    ldx #0                                      ; two feet make four slots sufficient
use:
    lda col
    sta dirtyCollapseCols, x
    lda row
    sta dirtyCollapseRows, x
    lda #2                                      ; repair this back page and the other page next frame
    sta dirtyCollapseAge, x
    clc
    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenTileCountDec

    lda tilesRendered
    bne :+
    dec tilesRenderedHi
:
    dec tilesRendered
    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenTileCountInc

    inc tilesRendered
    bne :+
    inc tilesRenderedHi
:
    rts

.endproc

;-----------------------------------------------------------------------------
; Use exact dirty rectangles for ordinary rooms after both HGR pages have been
; initialized.  The solar beam samples the framebuffer, so it keeps the old
; full-playfield path.
.proc screenPrepareFrame

    lda fullScreenClearCount
    bne full
    lda currLevel
    cmp #LEVEL_Solar_Power_Generator
    beq fullPlayfield
    lda #1
    sta dirtyRender
    jmp screenDirtyEraseRects

fullPlayfield:
    ldx #0
    beq clear                                   ; BRA
full:
    tax
clear:
    lda #0
    sta dirtyRender
    jmp screenClear

.endproc

;-----------------------------------------------------------------------------
.proc screenDirtyEraseRects

    lda backPage
    beq page0
    lda #<dirtySpriteXPage1
    sta oldX + 1
    sta compareX + 1
    lda #>dirtySpriteXPage1
    sta oldX + 2
    sta compareX + 2
    lda #<dirtySpriteYPage1
    sta oldY + 1
    sta compareY + 1
    lda #>dirtySpriteYPage1
    sta oldY + 2
    sta compareY + 2
    bne sprites                                 ; BRA
page0:
    lda #<dirtySpriteXPage0
    sta oldX + 1
    sta compareX + 1
    lda #>dirtySpriteXPage0
    sta oldX + 2
    sta compareX + 2
    lda #<dirtySpriteYPage0
    sta oldY + 1
    sta compareY + 1
    lda #>dirtySpriteYPage0
    sta oldY + 2
    sta compareY + 2

sprites:
    ldx numSprites                              ; include the door, which is composited last
loop:
    stx dirtyIndex
oldY:
    ldy PLACEHOLDER, x
oldX:
    lda PLACEHOLDER, x
    jsr screenDirtyRect
    ldx dirtyIndex
compareX:
    lda PLACEHOLDER, x
    cmp spriteXPos, x
    bne current
compareY:
    lda PLACEHOLDER, x
    cmp spriteYPos, x
    beq next
current:
    lda spriteXPos, x
    ldy spriteYPos, x
    jsr screenDirtyRect
next:
    dec dirtyIndex
    ldx dirtyIndex
    bpl loop

    lda demoMode                                ; demo rooms do not draw Willy
    bne animated
    ldx backPage
    ldy dirtyWillyY, x
    lda dirtyWillyX, x
    jsr screenDirtyRect
    ldx backPage
    lda dirtyWillyX, x
    cmp willyXPos
    bne currentWilly
    lda dirtyWillyY, x
    cmp willyYPos
    beq animated
currentWilly:
    lda willyXPos
    ldy willyYPos
    jsr screenDirtyRect

animated:
    ldx dirtyAnimCount
    beq collapses
    dex
animLoop:
    stx dirtyIndex
    lda dirtyAnimCols, x
    ldy dirtyAnimRows, x
    clc                                         ; cached blanks are skipped after a key is collected
    jsr screenDirtyMarkCell
    ldx dirtyIndex
    dex
    bpl animLoop
collapses:
    jsr screenDirtyMarkCollapses
    jmp screenDirtyClearCells                  ; destructive cell clears must precede sprite drawing

.endproc

;-----------------------------------------------------------------------------
; A sprite is three HGR bytes by 16 scanlines. Clear only that rectangle
.proc screenClearSpriteRect

    rectX    = tmpBot + 0
    rectY    = tmpBot + 1
    scanline = tmpBot + 2
    lines    = tmpBot + 3

    sta rectX
    sty rectY
    sty scanline
    lda #16
    sta lines

clearLoop:
    ldy scanline
    clc
    lda rowL, y
    adc rectX
    adc #MARGIN
    sta dstPtrL
    lda rowH, y
    adc currPageH
    sta dstPtrH
    lda #0
    ldy #2
    sta (dstPtrL), y
    dey
    sta (dstPtrL), y
    dey
    sta (dstPtrL), y
    inc scanline
    dec lines
    bne clearLoop
    rts

.endproc

;-----------------------------------------------------------------------------
; Clear a sprite rectangle and mark every underlying tile plus the floor row
; immediately below it for the later (sparse) level repair.
.proc screenDirtyRect

    rectX    = tmpBot + 0
    rectY    = tmpBot + 1
    firstRow = tmpBot + 4
    lastRow  = tmpBot + 5
    lastCol  = sizeH

    jsr screenClearSpriteRect                   ; leaves rectX and rectY in shared scratch

    lda rectX
    clc
    adc #2
    cmp #PLAY_COLS
    bcc :+
    lda #PLAY_COLS - 1
:
    sta lastCol

    lda rectY
    lsr
    lsr
    lsr
    sta firstRow
    lda rectY                                  ; include y+16 so collapsing floor changes are repaired
    clc
    adc #16
    lsr
    lsr
    lsr
    cmp #PLAY_ROWS
    bcc :+
    lda #PLAY_ROWS - 1
:
    sta lastRow

rowLoop:
    ldx firstRow
    lda mult32L, x
    sta srcPtrL
    lda mult32H, x
    clc
    adc #>levelLayout
    sta srcPtrH
    ldy rectX
colLoop:
    lda (srcPtrL), y
    ora #DIRTY_TILE_MASK
    sta (srcPtrL), y
    cpy lastCol
    beq nextRow
    iny
    bne colLoop                                 ; BRA
nextRow:
    lda firstRow
    cmp lastRow
    beq done
    inc firstRow
    bne rowLoop                                 ; BRA
done:
    rts

.endproc

;-----------------------------------------------------------------------------
; A = tile column, Y = tile row. 
; Carry set forces a blank cell to be tagged
; Carry clear skips stale blank entries in the key/conveyor animation cache.
.proc screenDirtyMarkCell

    php
    pha
    tya
    tax
    lda mult32L, x
    sta srcPtrL
    lda mult32H, x
    clc
    adc #>levelLayout
    sta srcPtrH
    pla
    tay
    plp
    lda (srcPtrL), y
    bcs mark
    beq done                                    ; collected keys leave a stale cache entry, but need no future redraws
mark:
    ora #DIRTY_TILE_MASK
    sta (srcPtrL), y
done:
    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDirtyMarkCollapses

    ldx #MAX_DIRTY_COLLAPSE_TILES - 1
loop:
    lda dirtyCollapseAge, x
    beq next
    stx dirtyIndex
    lda dirtyCollapseCols, x
    ldy dirtyCollapseRows, x
    sec                                         ; final collapse-to-blank must also repair the other page
    jsr screenDirtyMarkCell
    ldx dirtyIndex
    dec dirtyCollapseAge, x
next:
    dex
    bpl loop
    rts

.endproc

;-----------------------------------------------------------------------------
; Blank cells and partial collapsing platforms need a complete cell clear.  Do
; that before sprites are drawn as clearing them from screenDrawDirtyLevel would
; erase any enemy that was just drawn over the same map tile.
.proc screenDirtyClearCells

    levelReadL = srcPtrL
    levelReadH = srcPtrH
    rows       = sizeL
    cols       = sizeH

    lda #0
    sta rows
    lda #<levelLayout
    sta levelReadL
    lda #>levelLayout
    sta levelReadH

nextRow:
    ldy #0
nextCol:
    lda (levelReadL), y
    and #DIRTY_TILE_MASK
    beq advance
    lda (levelReadL), y
    and #<~DIRTY_TILE_MASK
    beq clear
    cmp #DATA_COLLAPSE + 1
    bcc advance
    cmp #DATA_KEY
    bcs advance
clear:
    sty cols
    jsr screenClearDirtyCell
    ldy cols
advance:
    iny
    cpy #PLAY_COLS
    bne nextCol
    inc rows
    lda rows
    cmp #PLAY_ROWS
    beq done
    lda levelReadL
    clc
    adc #PLAY_COLS
    sta levelReadL
    bcc nextRow
    inc levelReadH
    bne nextRow                                  ; BRA
done:
    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDirtySavePositions

    lda backPage
    beq page0
    lda #<dirtySpriteXPage1
    sta saveX + 1
    lda #>dirtySpriteXPage1
    sta saveX + 2
    lda #<dirtySpriteYPage1
    sta saveY + 1
    lda #>dirtySpriteYPage1
    sta saveY + 2
    bne saveSprites                             ; BRA
page0:
    lda #<dirtySpriteXPage0
    sta saveX + 1
    lda #>dirtySpriteXPage0
    sta saveX + 2
    lda #<dirtySpriteYPage0
    sta saveY + 1
    lda #>dirtySpriteYPage0
    sta saveY + 2
saveSprites:
    ldx numSprites
loop:
    lda spriteXPos, x
saveX:
    sta PLACEHOLDER, x
    lda spriteYPos, x
saveY:
    sta PLACEHOLDER, x
    dex
    bpl loop
    ldx backPage
    lda willyXPos
    sta dirtyWillyX, x
    lda willyYPos
    sta dirtyWillyY, x
    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDrawLevelName

    ldy #PLAY_COLS - 1                          ; cache index 31..0
    ldx #MARGIN + PLAY_COLS - 1                 ; centred screen bytes 35..4

    lda currPageH
    cmp #$20
    bne page2

:
    lda levelNameGfx0 + $0000, y                ; load the cache
    sta $2050, x                                ; store to the screen (the hi byte is updated)

    lda levelNameGfx0 + $0020, y                ; cache rows are 32 bytes apart
    sta $2450, x

    lda levelNameGfx0 + $0040, y
    sta $2850, x

    lda levelNameGfx0 + $0060, y
    sta $2C50, x

    lda levelNameGfx0 + $0080, y
    sta $3050, x

    lda levelNameGfx0 + $00A0, y
    sta $3450, x

    lda levelNameGfx0 + $00C0, y
    sta $3850, x

    lda levelNameGfx0 + $00E0, y
    sta $3C50, x

    dey                                         ; previous cache byte
    dex                                         ; previous screen byte
    cpy #$ff
    bne :-                                      ; keep going till all 32 columns copied

    rts

page2:
    lda levelNameGfx0 + $0000, y                ; load the cache
    sta $4050, x                                ; store to the screen (the hi byte is updated)

    lda levelNameGfx0 + $0020, y
    sta $4450, x

    lda levelNameGfx0 + $0040, y
    sta $4850, x

    lda levelNameGfx0 + $0060, y
    sta $4C50, x

    lda levelNameGfx0 + $0080, y
    sta $5050, x

    lda levelNameGfx0 + $00A0, y
    sta $5450, x

    lda levelNameGfx0 + $00C0, y
    sta $5850, x

    lda levelNameGfx0 + $00E0, y
    sta $5C50, x

    dey                                         ; previous cache byte
    dex                                         ; previous screen byte
    cpy #$ff
    bne page2                                   ; keep going till all 32 columns copied

    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDrawAirFrame

    lda currPageH                               ; see if this is to page 1 or 2
    cmp #$20
    bne page2

    ldx #MARGIN + PLAY_COLS - 1 - AIR_FRAME_LEFT ; frame spans bytes 9..35
    lda #%01010101                              ; byte 35 is odd, so start with green right
:
    sta $20D0 + AIR_FRAME_LEFT, x
    sta $24D0 + AIR_FRAME_LEFT, x
    sta $38D0 + AIR_FRAME_LEFT, x
    sta $3CD0 + AIR_FRAME_LEFT, x
    eor #%01111111                              ; alternate the green phase for each byte
    dex
    bpl :-

    ldx #AIR_BAR_COLS - 1                       ; white fill spans bytes 7..34
    lda #%01111111                              ; white left & right
:
    sta $28D0 + AIR_BAR_LEFT, x
    sta $2CD0 + AIR_BAR_LEFT, x
    sta $30D0 + AIR_BAR_LEFT, x
    sta $34D0 + AIR_BAR_LEFT, x

    dex                                         ; in 1's since left/right is the same $7f
    bpl :-

    rts

page2:                                          ; the same as page 1, just diff buffer
    ldx #MARGIN + PLAY_COLS - 1 - AIR_FRAME_LEFT
    lda #%01010101
:
    sta $40D0 + AIR_FRAME_LEFT, x
    sta $44D0 + AIR_FRAME_LEFT, x
    sta $58D0 + AIR_FRAME_LEFT, x
    sta $5CD0 + AIR_FRAME_LEFT, x
    eor #%01111111
    dex
    bpl :-

    ldx #AIR_BAR_COLS - 1
    lda #%01111111                              ; white left & right
:
    sta $48D0 + AIR_BAR_LEFT, x
    sta $4CD0 + AIR_BAR_LEFT, x
    sta $50D0 + AIR_BAR_LEFT, x
    sta $54D0 + AIR_BAR_LEFT, x

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

    sta $28D0 + AIR_BAR_LEFT, x                 ; x=28 starts at playfield byte 35
    sta $2CD0 + AIR_BAR_LEFT, x
    sta $30D0 + AIR_BAR_LEFT, x
    sta $34D0 + AIR_BAR_LEFT, x

    rts

page2:
    sta $48D0 + AIR_BAR_LEFT, x                 ; same position on page 2
    sta $4CD0 + AIR_BAR_LEFT, x
    sta $50D0 + AIR_BAR_LEFT, x
    sta $54D0 + AIR_BAR_LEFT, x

    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDrawLevel
    levelReadL     = srcPtrL                    ; tile to draw in level
    levelReadH     = srcPtrH
    tileReadL      = dstPtrL                    ; data for tile to draw 
    tileReadH      = dstPtrH
    rows           = sizeL                      ; rows to draw (15 -> 0)
    cols           = sizeH                      ; current level column (0..31)

    lda #0
    sta cols
    sta rows
    tay

    lda #<levelLayout
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
    sty cols                                    ; save the current col index
    pha                                         ; save the tile id
    and #$F0                                    ; strip to bare tile (no extra infor like collapse state)
    clc
    adc #<(tilesInstances - TILE_BYTES)         ; Index 1 has it's bytes at + 0, so move start 1 tile back
    sta tileReadL
    lda #>(tilesInstances - TILE_BYTES)
    adc #0                                      ; include carry from the low-byte address add
    sta tileReadH                               ; points at the tile data
    tya                                         ; level column to A
    clc
    adc #MARGIN                                 ; one screen byte per level column, centred
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
    adc #<tile35Half                            ; add the offset of the switch image
    sta tileReadL
    lda #>tile35Half                            ; and set the hi byte too
    adc #0                                      ; turns out tile36 is in a different block (if I remove these 2 bytes          ;)
    sta tileReadH                               ; points at the tile data

prepTileDraw:
    lda cols                                    ; emitted rows are [even, odd] phases
    and #1                                      ; select the phase for this screen byte
    tay
tileDraw:
    jsr PLACEHOLDER
    ldy cols
nextCol:
    iny
    cpy #PLAY_COLS
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
    lda cols                                    ; preserve column parity when entering partway
    and #1                                      ; through the generated draw routine
    tay
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
.proc screenDrawFrameLevel

    lda dirtyRender
    bne :+
    jmp screenDrawLevel
:
    jmp screenDrawDirtyLevel

.endproc

;-----------------------------------------------------------------------------
; Scan the compact level map, but emit only cells tagged by the dirty rectangle
; pass.  DIRTY_TILE_MASK is removed before interpreting the normal tile value.
.proc screenDrawDirtyLevel

    levelReadL = srcPtrL
    levelReadH = srcPtrH
    tileReadL  = dstPtrL
    tileReadH  = dstPtrH
    rows       = sizeL
    cols       = sizeH

    lda #0
    sta cols
    sta rows
    tay
    lda #<levelLayout
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
    lda rowDrawL, x
    sta tileDraw + 1
    lda rowDrawH, x
    sta tileDraw + 2

readLevelCol:
    lda (levelReadL), y
    and #DIRTY_TILE_MASK
    beq nextCol
    sty cols
    lda (levelReadL), y
    and #<~DIRTY_TILE_MASK
    sta (levelReadL), y                         ; clear transient marker before game logic runs again
    bne nonBlank
    ldy cols
    jmp nextCol
nonBlank:
    pha
    and #$F0
    clc
    adc #<(tilesInstances - TILE_BYTES)
    sta tileReadL
    lda #>(tilesInstances - TILE_BYTES)
    adc #0
    sta tileReadH
    tya
    clc
    adc #MARGIN
    tax
    pla
    cmp #DATA_COLLAPSE + 1
    bcc prepTileDraw
    cmp #DATA_KEY
    bcc isCollapse
    beq prepTileDraw
    cmp #DATA_DOOR
    beq nextCol
    and #1
    beq :+
    lda #16
:
    adc #<tile35Half
    sta tileReadL
    lda #>tile35Half
    adc #0
    sta tileReadH

prepTileDraw:
    lda cols
    and #1
    tay
tileDraw:
    jsr PLACEHOLDER
    ldy cols
nextCol:
    iny
    cpy #PLAY_COLS
    bne readLevelCol
    ldy #0
    inc rows
    lda rows
    cmp #PLAY_ROWS
    beq done
    lda levelReadL
    clc
    adc #PLAY_COLS
    sta levelReadL
    bcc :+
    inc levelReadH
:
    jmp nextRow

isCollapse:
    and #7
    tay
    lda collapseHeight, y
    clc
    adc tileDraw + 1
    sta collapseDraw + 1
    lda tileDraw + 2
    adc #0
    sta collapseDraw + 2
    lda cols
    and #1
    tay
collapseDraw:
    jsr PLACEHOLDER
    ldy cols
    jmp nextCol
done:
    rts

.endproc

;-----------------------------------------------------------------------------
; Clear one 7-dot by 8-scanline level cell.  rows/cols are the tile coordinates.
; Use a different temp for the screen pointer so the selected tile source remains
; intact when a collapsing tile is redrawn immediately afterward.
.proc screenClearDirtyCell

    rows      = sizeL
    cols      = sizeH
    clearPtrL = tmpBot + 4
    clearPtrH = tmpBot + 5

    lda rows
    asl
    asl
    asl
    tay
    clc
    lda rowL, y
    adc cols
    adc #MARGIN
    sta clearPtrL
    lda rowH, y
    adc currPageH
    sta clearPtrH
    ldx #8
    ldy #0
loop:
    lda #0
    sta (clearPtrL), y
    clc
    lda clearPtrH
    adc #4                                      ; the next scanline in an aligned HGR group
    sta clearPtrH
    dex
    bne loop
    rts

.endproc

;-----------------------------------------------------------------------------
; Each scanline is seven bytes, so collapseHeight uses 7*n.
.proc tileDrawP0R0
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2000,x
    iny
    iny
    lda (tileReadL),y
    sta $2400,x
    iny
    iny
    lda (tileReadL),y
    sta $2800,x
    iny
    iny
    lda (tileReadL),y
    sta $2C00,x
    iny
    iny
    lda (tileReadL),y
    sta $3000,x
    iny
    iny
    lda (tileReadL),y
    sta $3400,x
    iny
    iny
    lda (tileReadL),y
    sta $3800,x
    iny
    iny
    lda (tileReadL),y
    sta $3C00,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R0
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4000,x
    iny
    iny
    lda (tileReadL),y
    sta $4400,x
    iny
    iny
    lda (tileReadL),y
    sta $4800,x
    iny
    iny
    lda (tileReadL),y
    sta $4C00,x
    iny
    iny
    lda (tileReadL),y
    sta $5000,x
    iny
    iny
    lda (tileReadL),y
    sta $5400,x
    iny
    iny
    lda (tileReadL),y
    sta $5800,x
    iny
    iny
    lda (tileReadL),y
    sta $5C00,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R1
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2080,x
    iny
    iny
    lda (tileReadL),y
    sta $2480,x
    iny
    iny
    lda (tileReadL),y
    sta $2880,x
    iny
    iny
    lda (tileReadL),y
    sta $2C80,x
    iny
    iny
    lda (tileReadL),y
    sta $3080,x
    iny
    iny
    lda (tileReadL),y
    sta $3480,x
    iny
    iny
    lda (tileReadL),y
    sta $3880,x
    iny
    iny
    lda (tileReadL),y
    sta $3C80,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R1
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4080,x
    iny
    iny
    lda (tileReadL),y
    sta $4480,x
    iny
    iny
    lda (tileReadL),y
    sta $4880,x
    iny
    iny
    lda (tileReadL),y
    sta $4C80,x
    iny
    iny
    lda (tileReadL),y
    sta $5080,x
    iny
    iny
    lda (tileReadL),y
    sta $5480,x
    iny
    iny
    lda (tileReadL),y
    sta $5880,x
    iny
    iny
    lda (tileReadL),y
    sta $5C80,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R2
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2100,x
    iny
    iny
    lda (tileReadL),y
    sta $2500,x
    iny
    iny
    lda (tileReadL),y
    sta $2900,x
    iny
    iny
    lda (tileReadL),y
    sta $2D00,x
    iny
    iny
    lda (tileReadL),y
    sta $3100,x
    iny
    iny
    lda (tileReadL),y
    sta $3500,x
    iny
    iny
    lda (tileReadL),y
    sta $3900,x
    iny
    iny
    lda (tileReadL),y
    sta $3D00,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R2
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4100,x
    iny
    iny
    lda (tileReadL),y
    sta $4500,x
    iny
    iny
    lda (tileReadL),y
    sta $4900,x
    iny
    iny
    lda (tileReadL),y
    sta $4D00,x
    iny
    iny
    lda (tileReadL),y
    sta $5100,x
    iny
    iny
    lda (tileReadL),y
    sta $5500,x
    iny
    iny
    lda (tileReadL),y
    sta $5900,x
    iny
    iny
    lda (tileReadL),y
    sta $5D00,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R3
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2180,x
    iny
    iny
    lda (tileReadL),y
    sta $2580,x
    iny
    iny
    lda (tileReadL),y
    sta $2980,x
    iny
    iny
    lda (tileReadL),y
    sta $2D80,x
    iny
    iny
    lda (tileReadL),y
    sta $3180,x
    iny
    iny
    lda (tileReadL),y
    sta $3580,x
    iny
    iny
    lda (tileReadL),y
    sta $3980,x
    iny
    iny
    lda (tileReadL),y
    sta $3D80,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R3
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4180,x
    iny
    iny
    lda (tileReadL),y
    sta $4580,x
    iny
    iny
    lda (tileReadL),y
    sta $4980,x
    iny
    iny
    lda (tileReadL),y
    sta $4D80,x
    iny
    iny
    lda (tileReadL),y
    sta $5180,x
    iny
    iny
    lda (tileReadL),y
    sta $5580,x
    iny
    iny
    lda (tileReadL),y
    sta $5980,x
    iny
    iny
    lda (tileReadL),y
    sta $5D80,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R4
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2200,x
    iny
    iny
    lda (tileReadL),y
    sta $2600,x
    iny
    iny
    lda (tileReadL),y
    sta $2A00,x
    iny
    iny
    lda (tileReadL),y
    sta $2E00,x
    iny
    iny
    lda (tileReadL),y
    sta $3200,x
    iny
    iny
    lda (tileReadL),y
    sta $3600,x
    iny
    iny
    lda (tileReadL),y
    sta $3A00,x
    iny
    iny
    lda (tileReadL),y
    sta $3E00,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R4
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4200,x
    iny
    iny
    lda (tileReadL),y
    sta $4600,x
    iny
    iny
    lda (tileReadL),y
    sta $4A00,x
    iny
    iny
    lda (tileReadL),y
    sta $4E00,x
    iny
    iny
    lda (tileReadL),y
    sta $5200,x
    iny
    iny
    lda (tileReadL),y
    sta $5600,x
    iny
    iny
    lda (tileReadL),y
    sta $5A00,x
    iny
    iny
    lda (tileReadL),y
    sta $5E00,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R5
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2280,x
    iny
    iny
    lda (tileReadL),y
    sta $2680,x
    iny
    iny
    lda (tileReadL),y
    sta $2A80,x
    iny
    iny
    lda (tileReadL),y
    sta $2E80,x
    iny
    iny
    lda (tileReadL),y
    sta $3280,x
    iny
    iny
    lda (tileReadL),y
    sta $3680,x
    iny
    iny
    lda (tileReadL),y
    sta $3A80,x
    iny
    iny
    lda (tileReadL),y
    sta $3E80,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R5
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4280,x
    iny
    iny
    lda (tileReadL),y
    sta $4680,x
    iny
    iny
    lda (tileReadL),y
    sta $4A80,x
    iny
    iny
    lda (tileReadL),y
    sta $4E80,x
    iny
    iny
    lda (tileReadL),y
    sta $5280,x
    iny
    iny
    lda (tileReadL),y
    sta $5680,x
    iny
    iny
    lda (tileReadL),y
    sta $5A80,x
    iny
    iny
    lda (tileReadL),y
    sta $5E80,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R6
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2300,x
    iny
    iny
    lda (tileReadL),y
    sta $2700,x
    iny
    iny
    lda (tileReadL),y
    sta $2B00,x
    iny
    iny
    lda (tileReadL),y
    sta $2F00,x
    iny
    iny
    lda (tileReadL),y
    sta $3300,x
    iny
    iny
    lda (tileReadL),y
    sta $3700,x
    iny
    iny
    lda (tileReadL),y
    sta $3B00,x
    iny
    iny
    lda (tileReadL),y
    sta $3F00,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R6
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4300,x
    iny
    iny
    lda (tileReadL),y
    sta $4700,x
    iny
    iny
    lda (tileReadL),y
    sta $4B00,x
    iny
    iny
    lda (tileReadL),y
    sta $4F00,x
    iny
    iny
    lda (tileReadL),y
    sta $5300,x
    iny
    iny
    lda (tileReadL),y
    sta $5700,x
    iny
    iny
    lda (tileReadL),y
    sta $5B00,x
    iny
    iny
    lda (tileReadL),y
    sta $5F00,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R7
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2380,x
    iny
    iny
    lda (tileReadL),y
    sta $2780,x
    iny
    iny
    lda (tileReadL),y
    sta $2B80,x
    iny
    iny
    lda (tileReadL),y
    sta $2F80,x
    iny
    iny
    lda (tileReadL),y
    sta $3380,x
    iny
    iny
    lda (tileReadL),y
    sta $3780,x
    iny
    iny
    lda (tileReadL),y
    sta $3B80,x
    iny
    iny
    lda (tileReadL),y
    sta $3F80,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R7
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4380,x
    iny
    iny
    lda (tileReadL),y
    sta $4780,x
    iny
    iny
    lda (tileReadL),y
    sta $4B80,x
    iny
    iny
    lda (tileReadL),y
    sta $4F80,x
    iny
    iny
    lda (tileReadL),y
    sta $5380,x
    iny
    iny
    lda (tileReadL),y
    sta $5780,x
    iny
    iny
    lda (tileReadL),y
    sta $5B80,x
    iny
    iny
    lda (tileReadL),y
    sta $5F80,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R8
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2028,x
    iny
    iny
    lda (tileReadL),y
    sta $2428,x
    iny
    iny
    lda (tileReadL),y
    sta $2828,x
    iny
    iny
    lda (tileReadL),y
    sta $2C28,x
    iny
    iny
    lda (tileReadL),y
    sta $3028,x
    iny
    iny
    lda (tileReadL),y
    sta $3428,x
    iny
    iny
    lda (tileReadL),y
    sta $3828,x
    iny
    iny
    lda (tileReadL),y
    sta $3C28,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R8
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4028,x
    iny
    iny
    lda (tileReadL),y
    sta $4428,x
    iny
    iny
    lda (tileReadL),y
    sta $4828,x
    iny
    iny
    lda (tileReadL),y
    sta $4C28,x
    iny
    iny
    lda (tileReadL),y
    sta $5028,x
    iny
    iny
    lda (tileReadL),y
    sta $5428,x
    iny
    iny
    lda (tileReadL),y
    sta $5828,x
    iny
    iny
    lda (tileReadL),y
    sta $5C28,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0R9
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $20A8,x
    iny
    iny
    lda (tileReadL),y
    sta $24A8,x
    iny
    iny
    lda (tileReadL),y
    sta $28A8,x
    iny
    iny
    lda (tileReadL),y
    sta $2CA8,x
    iny
    iny
    lda (tileReadL),y
    sta $30A8,x
    iny
    iny
    lda (tileReadL),y
    sta $34A8,x
    iny
    iny
    lda (tileReadL),y
    sta $38A8,x
    iny
    iny
    lda (tileReadL),y
    sta $3CA8,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1R9
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $40A8,x
    iny
    iny
    lda (tileReadL),y
    sta $44A8,x
    iny
    iny
    lda (tileReadL),y
    sta $48A8,x
    iny
    iny
    lda (tileReadL),y
    sta $4CA8,x
    iny
    iny
    lda (tileReadL),y
    sta $50A8,x
    iny
    iny
    lda (tileReadL),y
    sta $54A8,x
    iny
    iny
    lda (tileReadL),y
    sta $58A8,x
    iny
    iny
    lda (tileReadL),y
    sta $5CA8,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0RA
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2128,x
    iny
    iny
    lda (tileReadL),y
    sta $2528,x
    iny
    iny
    lda (tileReadL),y
    sta $2928,x
    iny
    iny
    lda (tileReadL),y
    sta $2D28,x
    iny
    iny
    lda (tileReadL),y
    sta $3128,x
    iny
    iny
    lda (tileReadL),y
    sta $3528,x
    iny
    iny
    lda (tileReadL),y
    sta $3928,x
    iny
    iny
    lda (tileReadL),y
    sta $3D28,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1RA
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4128,x
    iny
    iny
    lda (tileReadL),y
    sta $4528,x
    iny
    iny
    lda (tileReadL),y
    sta $4928,x
    iny
    iny
    lda (tileReadL),y
    sta $4D28,x
    iny
    iny
    lda (tileReadL),y
    sta $5128,x
    iny
    iny
    lda (tileReadL),y
    sta $5528,x
    iny
    iny
    lda (tileReadL),y
    sta $5928,x
    iny
    iny
    lda (tileReadL),y
    sta $5D28,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0RB
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $21A8,x
    iny
    iny
    lda (tileReadL),y
    sta $25A8,x
    iny
    iny
    lda (tileReadL),y
    sta $29A8,x
    iny
    iny
    lda (tileReadL),y
    sta $2DA8,x
    iny
    iny
    lda (tileReadL),y
    sta $31A8,x
    iny
    iny
    lda (tileReadL),y
    sta $35A8,x
    iny
    iny
    lda (tileReadL),y
    sta $39A8,x
    iny
    iny
    lda (tileReadL),y
    sta $3DA8,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1RB
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $41A8,x
    iny
    iny
    lda (tileReadL),y
    sta $45A8,x
    iny
    iny
    lda (tileReadL),y
    sta $49A8,x
    iny
    iny
    lda (tileReadL),y
    sta $4DA8,x
    iny
    iny
    lda (tileReadL),y
    sta $51A8,x
    iny
    iny
    lda (tileReadL),y
    sta $55A8,x
    iny
    iny
    lda (tileReadL),y
    sta $59A8,x
    iny
    iny
    lda (tileReadL),y
    sta $5DA8,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0RC
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2228,x
    iny
    iny
    lda (tileReadL),y
    sta $2628,x
    iny
    iny
    lda (tileReadL),y
    sta $2A28,x
    iny
    iny
    lda (tileReadL),y
    sta $2E28,x
    iny
    iny
    lda (tileReadL),y
    sta $3228,x
    iny
    iny
    lda (tileReadL),y
    sta $3628,x
    iny
    iny
    lda (tileReadL),y
    sta $3A28,x
    iny
    iny
    lda (tileReadL),y
    sta $3E28,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1RC
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4228,x
    iny
    iny
    lda (tileReadL),y
    sta $4628,x
    iny
    iny
    lda (tileReadL),y
    sta $4A28,x
    iny
    iny
    lda (tileReadL),y
    sta $4E28,x
    iny
    iny
    lda (tileReadL),y
    sta $5228,x
    iny
    iny
    lda (tileReadL),y
    sta $5628,x
    iny
    iny
    lda (tileReadL),y
    sta $5A28,x
    iny
    iny
    lda (tileReadL),y
    sta $5E28,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0RD
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $22A8,x
    iny
    iny
    lda (tileReadL),y
    sta $26A8,x
    iny
    iny
    lda (tileReadL),y
    sta $2AA8,x
    iny
    iny
    lda (tileReadL),y
    sta $2EA8,x
    iny
    iny
    lda (tileReadL),y
    sta $32A8,x
    iny
    iny
    lda (tileReadL),y
    sta $36A8,x
    iny
    iny
    lda (tileReadL),y
    sta $3AA8,x
    iny
    iny
    lda (tileReadL),y
    sta $3EA8,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1RD
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $42A8,x
    iny
    iny
    lda (tileReadL),y
    sta $46A8,x
    iny
    iny
    lda (tileReadL),y
    sta $4AA8,x
    iny
    iny
    lda (tileReadL),y
    sta $4EA8,x
    iny
    iny
    lda (tileReadL),y
    sta $52A8,x
    iny
    iny
    lda (tileReadL),y
    sta $56A8,x
    iny
    iny
    lda (tileReadL),y
    sta $5AA8,x
    iny
    iny
    lda (tileReadL),y
    sta $5EA8,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0RE
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $2328,x
    iny
    iny
    lda (tileReadL),y
    sta $2728,x
    iny
    iny
    lda (tileReadL),y
    sta $2B28,x
    iny
    iny
    lda (tileReadL),y
    sta $2F28,x
    iny
    iny
    lda (tileReadL),y
    sta $3328,x
    iny
    iny
    lda (tileReadL),y
    sta $3728,x
    iny
    iny
    lda (tileReadL),y
    sta $3B28,x
    iny
    iny
    lda (tileReadL),y
    sta $3F28,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1RE
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $4328,x
    iny
    iny
    lda (tileReadL),y
    sta $4728,x
    iny
    iny
    lda (tileReadL),y
    sta $4B28,x
    iny
    iny
    lda (tileReadL),y
    sta $4F28,x
    iny
    iny
    lda (tileReadL),y
    sta $5328,x
    iny
    iny
    lda (tileReadL),y
    sta $5728,x
    iny
    iny
    lda (tileReadL),y
    sta $5B28,x
    iny
    iny
    lda (tileReadL),y
    sta $5F28,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP0RF
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $23A8,x
    iny
    iny
    lda (tileReadL),y
    sta $27A8,x
    iny
    iny
    lda (tileReadL),y
    sta $2BA8,x
    iny
    iny
    lda (tileReadL),y
    sta $2FA8,x
    iny
    iny
    lda (tileReadL),y
    sta $33A8,x
    iny
    iny
    lda (tileReadL),y
    sta $37A8,x
    iny
    iny
    lda (tileReadL),y
    sta $3BA8,x
    iny
    iny
    lda (tileReadL),y
    sta $3FA8,x
    rts
.endproc

;-----------------------------------------------------------------------------
.proc tileDrawP1RF
    tileReadL      = dstPtrL
    tileReadH      = dstPtrH

    lda (tileReadL),y
    sta $43A8,x
    iny
    iny
    lda (tileReadL),y
    sta $47A8,x
    iny
    iny
    lda (tileReadL),y
    sta $4BA8,x
    iny
    iny
    lda (tileReadL),y
    sta $4FA8,x
    iny
    iny
    lda (tileReadL),y
    sta $53A8,x
    iny
    iny
    lda (tileReadL),y
    sta $57A8,x
    iny
    iny
    lda (tileReadL),y
    sta $5BA8,x
    iny
    iny
    lda (tileReadL),y
    sta $5FA8,x
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

    col       = sizeH
    lines     = tmpBot + 0
    opaque    = tmpBot + 1

    lda #0                                      ; ordinary enemies blend with earlier sprites
    sta opaque                                  ; so transparent dots cannot erase them
    lda spriteClass, x
    bit CLASS_DOOR
    beq :+
    inc opaque                                  ; the door remains an opaque foreground object
:
    lda spriteXPos, x                           ; col in 0..31 range
    clc
    adc #MARGIN                                 ; one screen byte per level column, centred
    sta col                                     ; screen column for where to start draw

    lda spriteFrame, x
    clc
    adc spriteFramesIdx, x
    tay                                         ; fixed-X sprite uses its only instanced parity
    lda spriteClass, x
    bit CLASS_MOVE_Y
    bne frameReady
    bit CLASS_DOOR
    bne frameReady
    lda col                                     ; horizontal sprites have even then odd frame sets
    and #1
    beq frameReady
    lda spriteClass, x
    bit CLASS_FOUR_FRAME
    beq :+
    tya
    clc
    adc #4
    tay
    bne frameReady
:
    tya
    clc
    adc #8
    tay

frameReady:
    clc
    lda mult48L, y
    adc #<spriteInstances
    sta blendRead + 1
    sta opaqueRead + 1
    lda mult48H, y                              ; and add the 48 * frame offset
    adc #>spriteInstances                       ; add the hi offset and low-byte carry
    sta blendRead + 2
    sta opaqueRead + 2

    lda spriteYPos, x                           ; get the y position of the sprite
    tay

    lda #16                                     ; sprites are 16 high
    sta lines

loop:
    clc                                         ; low-byte addition starts a fresh address calculation
    lda col                                     ; start with the column
    adc rowL, y                                 ; add the row start
    sta blendScreen + 1
    sta blendWrite + 1
    sta opaqueWrite + 1
    lda rowH, y
    adc currPageH                               ; and the page
    sta blendScreen + 2
    sta blendWrite + 2
    sta opaqueWrite + 2                         ; writes point at this HGR scanline

    lda opaque
    bne drawOpaque

    ldx #2                                      ; ordinary sprites use all three alignment bytes
blendRead:
    lda PLACEHOLDER, x                          ; get the byte from the sprite instance
    beq blendNext                               ; $00 and $80 contain no visible dots
    cmp #$80                                    ; do not let a palette-only byte alter earlier art
    beq blendNext
blendScreen:
    ora PLACEHOLDER, x                          ; preserve pixels from an adjacent sprite
blendWrite:
    sta PLACEHOLDER, x
blendNext:
    dex
    bpl blendRead
    bmi stripDone                               ; BRA

drawOpaque:
    ldx #1                                      ; door has two gameplay columns, opaque and foreground
opaqueRead:
    lda PLACEHOLDER, x
opaqueWrite:
    sta PLACEHOLDER, x
    dex
    bpl opaqueRead

stripDone:
    dec lines                                   ; one more line done
    beq done
    clc
    lda blendRead + 1                           ; not all done, advance both reads by 3 bytes
    adc #3
    sta blendRead + 1
    sta opaqueRead + 1
    bcc :+
    inc blendRead + 2
    inc opaqueRead + 2
    clc
:
    iny                                         ; and go to next line
    bne loop                                    ; BRA

done:
    rts

.endproc

;-----------------------------------------------------------------------------
.proc screenDrawLives

    allDone      = tmpBot + 0
    displayLives = tmpBot + 1

    ldx lives                                   ; how many lives to draw
    lda cheatActive                             ; reserve the last 4-byte slot for the boot
    beq noBootCap
    cpx #MAX_UI_LIVES_WITH_BOOT + 1
    bcc capped
    ldx #MAX_UI_LIVES_WITH_BOOT
    bne capped
noBootCap:
    cpx #MAX_UI_LIVES + 1                       ; no UI art may enter the right margin
    bcc capped
    ldx #MAX_UI_LIVES
capped:
    stx displayLives                            ; visible count can be lower than logical lives
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
    lda uiMult64L, y                            ; full-width UI frame stride
    clc
    adc #<uiWillySprites                        ; and add the life-icon offset
    sta srcPtrL
    lda uiMult64H, y
    adc #>uiWillySprites
    sta srcPtrH                                 ; save as srcPtr

    txa                                         ; how many lives (0 based) into a for column offset calc

oloop:
    asl                                         ; mult * 4 to set them apart
    asl
    clc
    adc #MARGIN                                 ; leave the left four screen bytes untouched
    sta sizeH                                   ; store the column in sizeH
    lda #16                                     ; draw 16 lines
    sta dstPtrL                                 ; store the lines in dstPrkL

    ldy #22 * 8                                 ; Draw the lives in row 19 (0 based)

    lda srcPtrL                                 ; copy the srcPtr to where to read from
    sta read + 1
    lda srcPtrH
    sta read + 2

loop:
    clc
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

    ldx displayLives                            ; put the boot after the visible life icons
    txa
    asl                                         ; mult * 4 to set them apart
    asl
    clc
    adc #MARGIN                                 ; final slot ends at byte 35, before right margin
    sta sizeH                                   ; store the column in sizeH
    lda #16                                     ; draw 16 lines
    sta dstPtrL                                 ; store the lines in dstPrkL

    ldy #22 * 8                                 ; Draw the lives in row 19 (0 based)

    lda #<uiBootSprite                          ; copy the srcPtr to where to read from
    sta read + 1
    lda #>uiBootSprite
    sta read + 2
    jmp loop

.endproc

;-----------------------------------------------------------------------------
; Blit 16 rows of four bytes of full-width UI art onto the current page.
; Storing rather than OR-ing means a frame wipes the one before it.
; IN:  srcPtrL/H = art, sizeH = screen byte column, y = first hires row
; Uses: sizeL as the row counter
.proc screenDrawUISprite

    lines = sizeL
    col   = sizeH

    lda srcPtrL
    sta read + 1
    lda srcPtrH
    sta read + 2                                ; read now points at the art

    lda #16                                     ; UI art is 16 rows high
    sta lines

loop:
    clc
    lda col                                     ; start with the column
    adc rowL, y                                 ; add the row start
    sta write + 1
    lda rowH, y
    adc currPageH                               ; and the page
    sta write + 2                               ; write points at the line to copy 4 bytes to

    ldx #3                                      ; copy offsets 0..3
read:
    lda PLACEHOLDER, x                          ; get the art bytes
write:
    sta PLACEHOLDER, x                          ; put them on screen
    dex
    bpl read                                    ; do all the bytes

    clc
    lda read + 1                                ; advance the read pointer one row
    adc #4
    sta read + 1
    bcc :+
    inc read + 2
:
    iny                                         ; next hires row
    dec lines                                   ; one more line done
    bne loop

    rts

.endproc

;-----------------------------------------------------------------------------
; Draw the full-width UI Willy at willyXPos/willyYPos.  The title screen and
; the Game Over pedestal use this instead of screenDrawWilly so they show the
; nicer art.
.proc screenDrawUIWilly

    clc
    lda willyXPos                               ; one screen byte per level column, centred
    adc #MARGIN
    sta sizeH

    ldy willyFrame                              ; full-width frames are 64 bytes apart
    lda uiMult64L, y
    clc
    adc #<uiWillySprites
    sta srcPtrL
    lda uiMult64H, y
    adc #>uiWillySprites
    sta srcPtrH

    ldy willyYPos                               ; first hires row
    jmp screenDrawUISprite

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
    clc
    adc #MARGIN                                 ; one screen byte per level column, centred
    sta col                                     ; screen column for where to start draw
    lda #16                                     ; sprites are 16 high
    sta lines
    ldx #0                                      ; index into willy sprite data
    stx collision                               ; clear collision counter

    ldy willyFrame                              ; get the facing/shift frame (0..7)
    lda col                                     ; odd screen bytes need the one-dot-aligned art
    and #1
    beq :+
    tya
    ora #8                                      ; pointer entries 8..15 are odd-aligned
    tay
:
    lda willyHalfFrameL, y
    sta willyRead + 1                           ; save as the lo src ptr
    lda willyHalfFrameH, y
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
    ldy #0                                      ; Willy's half-width strip is 3 bytes wide
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
    cpy #3
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

    ldy #HGR_ROW_BYTES - 2                      ; retain the proven full-raster pair walk
colLoop:
    cpy #MARGIN + PLAY_COLS                     ; skip right-margin pairs 36/37 and 38/39
    bcs next
    cpy #MARGIN                                 ; skip left-margin pairs 0/1 and 2/3
    bcc next
    clc                                         ; cpy above sets carry; HGR row stepping needs it clear
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
    bpl colLoop                                 ; original termination; margin pairs are skipped above

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
    beamGfx      = tmpBot + 4

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
    lda column                                  ; all 32 world columns are visible now
    cmp #PLAY_COLS
    bcc :+
    jmp done
:
    adc #MARGIN                                 ; one screen byte per world column
    sta screenCol

    clc
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
    clc
    lda screenCol                               ; on screen
    adc rowL, y
    sta screenPtrL
    lda rowH, y
    adc currPageH
    sta screenPtrH

    lda screenCol                               ; select orange for this absolute byte phase
    and #1
    tax
    lda maskOrange, x
    sta beamGfx

    ldx #8                                      ; beam block is 8 rows high
    ldy #0                                      ; one byte per half-width world column
blockLoop:
    lda (screenPtrL), y                         ; get what's on screen (sprite)
    beq nocol                                   ; if nothing just overwrite
    inc collision                               ; hit a sprite
nocol:
    ora beamGfx                                 ; add the correctly phased orange beam
    sta (screenPtrL), y                         ; write to screen
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
