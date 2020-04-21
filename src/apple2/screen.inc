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

    tileReadL      = srcPtrL                    ; tile to draw's data
    tileReadH      = srcPtrH
    scrnPtrL       = dstPtrL                    ; location in screen buffer to draw to
    scrnPtrH       = dstPtrH
    rows           = sizeL                      ; rows to draw (15 -> 0)
    cols           = sizeH                      ; cols to draw (20 + leftEdge -> leftEdge)
    willyYRowEnd   = tmpBot + 0                 ; row where willy overlaps ends (+1)
    willyXPosStart = tmpBot + 1                 ; col where willy overlaps start
    willyXPosEnd   = tmpBot + 2                 ; row where willy overlaps ends (+1)
    rowStartL      = tmpBot + 3                 ; current screen draw row start
    rowStartH      = tmpBot + 4
    height         = tmpBot + 5                 ; normally 8 except for collapsing platforms

    lda #0
    sta tilesRendered
    lda willyYPos                               ; see if willy is across 2 or 3 rows
    and #7
    beq :+
    lda #3
    bne :++
:
    lda #2
:
    clc 
    adc willyYRow                               ; and set up the end row (+1)
    sta willyYRowEnd

    lda willyXPos                               ; calculate the cols that willy overlaps
    sec 
    sbc leftEdge
    sta willyXPosStart
    clc
    adc #2
    sta willyXPosEnd
    clc                                         ; in demo-mode, the prev didn't make sense and carry is set

    lda leftEdge                                ; col where to start drawing (right, bottom)
    adc #<(levelLayout + (PLAY_ROWS - 1) * PLAY_COLS)
    sta colLoop + 1
    lda #>(levelLayout + (PLAY_ROWS - 1) * PLAY_COLS)
    sta colLoop + 2                             ; levelLayout aligned so carry always clear

    lda #PLAY_ROWS - 1                          ; zero based rows to process
    sta rows                                    ; draw rows bottom up

rowLoop:
    clc
    ldy rows                                    ; rows are 8 lines high
    lda mult8, y
    tay 

    lda rowL, y                                 ; put the row in screen space
    sta rowStartL                               ; and save in a temp place
    lda rowH, y
    adc currPageH
    sta rowStartH

    ldx #VISIBLE_COLS - 1                       ; draw 20 columns (0 based)

colLoop:
    lda PLACEHOLDER, x                          ; get the tile from the unpacked level
    bne :+                                      ; if non-zero process that tile
    jmp prevCol                                 ; 0 (space) - skip to next tile to process
:
    cmp #DATA_COLLAPSE                          ; see if the tile is a collapsing tile
    bcc notCollapse                             ; the $70 could be $71->$77 for the collapsed state
    cmp #DATA_KEY
    bcc isCollapse                              ; if it's less than $80 it is a collapsing platform
    beq notCollapseClc                          ; is it a key
    cmp #DATA_DOOR                              ; if not a key, is it a door
    bcc setupSwitch                             ; if < door then it's a switch
    jmp prevCol                                 ; door tile isn't a rendered tile, only a collision tile

isCollapse: 
    and #7                                      ; get the level of collapse
    tay 
    lda collapseHeight, y                       ; see how many lines remain to draw
    sta height
    lda mult1024H, y                            ; and move the screen pointer down as well
    sta scrnPtrH
    lda #DATA_COLLAPSE                          ; and set up to draw the tile from the top (for fewer lines)
    bne setupTile                               ; BRA

setupSwitch:
    ldy #0                                      ; this code duplicated from notCollapse since setupTile is skipped
    sty scrnPtrH                                ; not a collapsing tile so set the screen ptr to top
    ldy #8                                      ; and set the height to 8 lines to draw
    sty height

    and #1                                      ; is this an on switch?
    beq :+                                      ; no
    lda #16                                     ; yes - the image is 16 bytes further (tile36)
:
    adc #<tile35                                ; add the offset of the switch image
    sta tileReadL
    lda #>tile35                                ; and set the hi byte too
    adc #0                                      ; turns out tile36 is in a different block (if I remove these 2 bytes ;)
    sta tileReadH                               ; points at the tile data
    bne :+                                      ; skip the portion where the tile pointer is setup

notCollapseClc:
    clc
notCollapse:
    ldy #0                                      ; not a collapsing tile so set the screen ptr to top
    sty scrnPtrH
    ldy #8                                      ; and set the height to 8 lines to draw
    sty height

setupTile:
    adc #<(tilesInstances - TILE_BYTES)         ; Index 1 has it's bytes at + 0, so move start 1 tile back
    sta tileReadL
    lda #>(tilesInstances - TILE_BYTES) + 1     ; carry always set, so + 1
    sta tileReadH                               ; points at the tile data

:
    inc tilesRendered
    txa                                         ; get the col
    asl                                         ; * 2 for 2-byte wide tiles and clears carry
    adc rowStartL                               ; add to screen row start to get tile screen dest
    sta scrnPtrL
    lda rowStartH
    adc scrnPtrH                                ; add the hi offset for collapsed tiles
    sta scrnPtrH

intersect:
    lda rows                                    ; see if willy intersects this row
    cmp willyYRow
    bcc noOverlap                               ; is willy below this row?
    cmp willyYRowEnd
    bcs noOverlapClc                            ; is willy's end above this row
    txa                                         ; rows intersect, now check the cols
    cmp willyXPosStart
    bcc noOverlap                               ; is col < willyStartCol
    cmp willyXPosEnd
    bcs noOverlapClc                            ; is col > willyEndCol (>= willyEnd + 1)

overlap:                                        ; willy will be "under" these tiles, so "or" in the
    ldy #0                                      ; tile to the screen.  Since willy's bits are 11, willy
    lda (tileReadL), y                          ; will "appear" as though he's in front of the tile
    ora (scrnPtrL), y                           ; see noOverlap for code explanation
    sta (scrnPtrL), y
    ldy #1
    lda (tileReadL), y
    ora (scrnPtrL), y
    sta (scrnPtrL), y

    lda tileReadL
    adc #2 
    sta tileReadL
    lda scrnPtrH
    adc #$04
    sta scrnPtrH
    dec height 
    bne overlap
    beq prevCol

noOverlapClc:
    clc
noOverlap:                                      ; tile's don't intercept with willy so just write to screen
    ldy #0                                      ; start with a byte at 0 offset (left)
    lda (tileReadL), y                          ; read tile byte
    sta (scrnPtrL), y                           ; write to screen
    ldy #1                                      ; do the same for the right byte at offset 1
    lda (tileReadL), y
    sta (scrnPtrL), y

    lda tileReadL                               ; advance the tile ptr by 2 for the 2 just written
    adc #2 
    sta tileReadL
    lda scrnPtrH                                ; advance the screen ptr to next row ($400)
    adc #$04
    sta scrnPtrH

    dec height                                  ; done one more row
    bne noOverlap                               ; keep going till all rows done

prevCol:
    dex                                         ; go to col to the left
    bmi :+                                      ; reached the end of the row?
    jmp colLoop                                 ; not yet end of row so go do this col
:
    dec rows                                    ; done another row
    bmi done                                    ; done all rows?

    lda colLoop + 1                             ; not yet - setp up a row in the unpacked tile area
    sec 
    sbc #32
    sta colLoop + 1
    bcs :+
    dec colLoop + 2
:
    jmp rowLoop                                 ; go do the next row's worth of tiles

done:
    lda currLevel
    cmp #LEVEL_Solar_Power_Generator            ; Is this the solar room
    bne :+                                      ; if not, move on
    jmp screenSolarBeam                         ; solar room needs a solar beam
:
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

    count     = sizeL
    col       = sizeH
    lines     = tmpBot + 0
    willyByte = tmpBot + 1
    collision = tmpBot + 2

    lda #0
    sta collision

    lda willyXPos                               ; col in 0..31 range
    sec 
    sbc leftEdge                                ; move by the left edge
    asl                                         ; multiply times 2
    sta col                                     ; screen column for where to start draw

    lda willyFrame                              ; get the frame
    tay                                         ; index through y
    lda mult64L, y                              ; get the frame * 64 lo

    adc #<sprite00                              ; add instance base address
    sta willyRead + 1                           ; save as the lo src ptr

    lda #>sprite00                              ; add the hi offset
    adc mult64H, y                              ; and add the 64 * frame hi
    sta willyRead + 2                           ; willyRead now a pointer at the frame to show

    lda willyYPos                               ; get the y position of the sprite
    tay 

    lda #16                                     ; sprites are 16 high
    sta lines

loop:
    lda col                                     ; start with the column
    adc rowL, y                                 ; add the row start
    sta screenRead + 1
    sta write + 1
    lda rowH, y 
    adc currPageH                               ; and the page
    sta screenRead + 2                          ; write points at the line to copy 4 bytes to
    sta write + 2                               ; write points at the line to copy 4 bytes to

stripLen:
    ldx #3                                      ; copy offsets 0..3
willyRead:
    lda PLACEHOLDER, x                          ; get the bytes from src instance
    sta willyByte
screenRead:
    lda PLACEHOLDER, x 
    eor willyByte
write:
    sta PLACEHOLDER, x                          ; put them on screen
    and willyByte
    cmp willyByte 
    beq :+
    inc collision
:
    dex 
    bpl willyRead                               ; do all the bytes
    dec lines                                   ; one more line done
    beq done
    clc
    lda willyRead + 1                           ; not all done, advance read by 4 bytes
    adc #4
    sta willyRead + 1
    bcc :+
    inc willyRead + 2
    clc 
:
    iny                                         ; and go to next line
    bne loop                                    ; BRA

done:
    lda collision
    beq :+
    sec 
    rts 
: 
    clc 
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
