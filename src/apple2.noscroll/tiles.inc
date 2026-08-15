;-----------------------------------------------------------------------------
; tiles.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020, 2026
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "CODE"

;-----------------------------------------------------------------------------
.proc tilesPrepForLevel

    jsr tilesMakeInstances                      ; copy tile data to instance area
    jsr tilesPrepConveyorTiles                  ; build raw half-width animation before masks discard shape bits

    lda monochrome                              ; see if the game should render for monochrome
    beq color                                   ; no, apply all masks
mono:
    ldy #(DATA_COLLAPSE / $10) - 1              ; apply color mask only to the conveyor tile
    ldx #((DATA_COLLAPSE / $10) -1) * TILE_BYTES
    lda #1
    bne mask
color:
    ldy #0
    ldx #0
    lda #TILES_PER_LEVEL

mask:
    jsr tilesColorInstances                     ; color instance tiles by applying appropriate color masks
    jsr tilesColorConveyorFrames                ; colour both parity variants of all conveyor frames
    jsr tilesPrepKeysTiles                      ; make animated keys from the key tile
    rts

.endproc

;-----------------------------------------------------------------------------
.proc tilesMakeInstances

    numTiles   = sizeL
    iLevelTile = sizeH
    iWrite     = dstPtrL
    tileMemL   = srcPtrL
    tileMemH   = srcPtrH

    lda #TILES_PER_LEVEL                        ; for all tiles used in a level
    sta numTiles

    lda #TILE_BYTES - 1                         ; start at the end of tile memory
    sta iWrite

    ldx currLevel                               ; find index into tile table
    lda mult8, x                                ; 8 tiles per level
    sta iLevelTile                              ; gives entry for the 1st tile

loop:
    lda #0                                      ; set the hi for reading tile memory to 0
    sta tileMemH

    ldx iLevelTile                              ; get the index into the table
    lda levelTiles, x                           ; and get the id for the tile from the table

    asl                                         ; mult tile offset * 16 (width of a tile)
    asl
    asl
    rol tileMemH
    asl
    rol tileMemH                                ; offset of tile start (from background) now in tileMem ptr
    adc #<tilesHalf                             ; add tiles base address
    sta tileMemL
    lda #>tilesHalf
    adc tileMemH
    sta tileMemH                                ; tileMem pointer now points at memory for the tile

    ldy #TILE_BYTES - 1                         ; 0 based, copy all the bytes of the tile
    ldx iWrite

:
    lda (tileMemL), y                           ; get the tile byte
    sta tilesInstances, x                       ; and save it to instance 0
    dex                                         ; back up the tile write pointer
    dey                                         ; and completed one byte
    bpl :-                                      ; do for all bytes of a tile

    dec numTiles                                ; done a tile
    beq copyDone                                ; see if all tiles done

    lda iWrite                                  ; more tiles to do, adjust the tile write ptr
    clc
    adc #TILE_BYTES                             ; by moving it to the end of the next tile
    sta iWrite
    inc iLevelTile                              ; and advance the index into the table to the next tile
    bne loop                                    ; BRA to do the next tile

copyDone:
    rts

.endproc

;-----------------------------------------------------------------------------
; Color tile instances
; IN:   a - number of tiles to color
; y - index of first tile to color
; x - write address of first tile data (16 * y)
.proc tilesColorInstances

    numTiles   = sizeL
    iLevelTile = sizeH
    colMaskL   = dstPtrL + 0
    colMaskR   = dstPtrL + 1
    tileMemL   = srcPtrL
    tileMemH   = srcPtrH

    sta numTiles                                ; save the register parameters
    sty iLevelTile

    ldy currLevel                               ; get the offset of the tiles in the level tile table
    lda mult8, y
    clc
    adc iLevelTile                              ; and add the parameter offset (0 for color and 3 for mono)
    sta iLevelTile

loop:
    ldy iLevelTile                              ; get the index
    lda levelMasks, y                           ; and extract the masks for this tile
    tay
    lda masksLeft, y
    sta colMaskL
    lda masksRight, y
    sta colMaskR

    ldy #(TILE_BYTES / 2)                       ; 2 masks at one time, so bytes / 2
:
    lda colMaskL                                ; instance 0 mask the left side with a left mask
    and tilesInstances, x
    sta tilesInstances, x

    inx                                         ; next byte

    lda colMaskR                                ; instance 0 mask the right side with a right mask
    and tilesInstances, x
    sta tilesInstances, x

    inx                                         ; next byte

    dey                                         ; one more column done
    bne :-                                      ; keep going till all columns done

    inc iLevelTile                              ; go to the next table entry
    dec numTiles                                ; done one more tile
    bne loop                                    ; keep going till all tiles done

    rts

.endproc


;-----------------------------------------------------------------------------
.proc tilesPrepKeysTiles

    keyByte = tmpBot + 0

    lda #4                                      ; init the key animation to frame 4
    sta keysFrameNum

    ldy #0                                      ; start at the 1st key byte

maskLoop:
    lda tilesInstances + DATA_KEY - TILE_BYTES, y
    sta keyByte                                 ; get a byte and save it

    clc
    ldx #4                                      ; make 4 color variations
colorLoopLeft:
    lda keyByte                                 ; start with the white key byte
    and masksLeft, x                            ; mask it for left
    sta keyAnimTiles, y                         ; and save it to the first key frame instance 0

    tya                                         ; move y along to the next key instance
    adc #TILE_BYTES
    tay
    dex                                         ; and do the next color for that instance
    bne colorLoopLeft                           ; repeat for all 4 color frames
    tya                                         ; move Y back 63 bytes, to the next white key byte
    sec
    sbc #63
    tay

    lda tilesInstances + DATA_KEY - TILE_BYTES, y
    sta keyByte                                 ; get the second (right hand byte)

    clc
    ldx #4                                      ; repeat the above but swap color masks
colorLoopRight:
    lda keyByte
    and masksRight, x
    sta keyAnimTiles, y

    tya
    adc #TILE_BYTES
    tay
    dex
    bne colorLoopRight

    tya
    sec
    sbc #63
    tay                                         ; y is now pointing at the next left byte
    cpy #TILE_BYTES                             ; see if the whole key has been processes
    bne maskLoop

    rts

.endproc

;-----------------------------------------------------------------------------
; Makes animated copies of the conveyor tile.  Instead of making full tile
; copies, this should really just do the two lines affected (so use 1 tile
; of memory, not 7 * TILE_BYTES)
.proc tilesPrepConveyorTiles

    frame  = sizeL
    count  = sizeH
    dir    = tmpBot + 0
    pairCount = tmpBot + 1

    lda #6                                      ; init the conveyor frame counter
    sta conveyorFrameNum

    ldx currLevel
    lda conveyorDirections, x                   ; get a local copy of the conveyor direction
    sta dir

    lda #<(tilesInstances + DATA_CONVEYOR - TILE_BYTES) ; point srcPtr at conveyor instance
    sta srcPtrL
    lda #>(tilesInstances + DATA_CONVEYOR - TILE_BYTES)
    sta srcPtrH

    lda #<conveyorAnimTiles                     ; point dstPtr at the first animated tile
    sta dstPtrL
    lda #>conveyorAnimTiles
    sta dstPtrH

    ldy #TILE_BYTES - 1                         ; copy the tile to the animated tiles
:
    lda (srcPtrL), y
    sta (dstPtrL), y
    dey
    bpl :-

    ldy #CONVEYOR_FRAMES - 1                    ; set a counter for how many frames to process

processTile:
    sty frame

    clc                                         ; move srcPtr to dstPtr (the new src)
    lda dstPtrL                                 ; and move dstPtr to the next frame to animate
    sta srcPtrL
    adc #TILE_BYTES
    sta dstPtrL
    lda dstPtrH
    sta srcPtrH
    bcc :+
    inc dstPtrH
:
    ldy #TILE_BYTES - 1                         ; process a tile's bytes (0 based)
:
    lda (srcPtrL), y                            ; copy the source
    sta (dstPtrL), y                            ; save to the dest
    dey                                         ; copy the whole tile
    bpl :-

    lda dir                                     ; different algorithm for each direction
    cmp #2
    beq left

right:
    ldy #0                                      ; top row
    jsr rotateHalfLeft                          ; generation is reversed: animation plays frames 6..0
    ldy #4                                      ; 3rd row down, 0 based (2) * 2 byes/row is 4
    jsr rotateHalfRight
    jmp nextFrame                               ; so this is all reversed

left:
    ldy #0
    jsr rotateHalfRight
    ldy #4
    jsr rotateHalfLeft

nextFrame:
    ldy frame
    dey                                         ; another frame processed
    bne processTile                             ; have all tiles been animated (0 is original the rest shifted)

    rts

; Rotate the two independent [even, odd] phase bytes one dot. The table keeps
; bit 7 and wraps only the seven display dots; no bitmap shifting occurs in the
; frame loop. Applying the table six times is the inverse rotation.
rotateHalfRight:
    lda #2
    sta pairCount
:
    lda (dstPtrL), y
    tax
    lda halfRotateRight, x
    sta (dstPtrL), y
    iny
    dec pairCount
    bne :-
    rts

rotateHalfLeft:
    lda #2
    sta pairCount
:
    lda (dstPtrL), y
    .repeat 6
        tax
        lda halfRotateRight, x
    .endrepeat
    sta (dstPtrL), y
    iny
    dec pairCount
    bne :-
    rts

.endproc

;-----------------------------------------------------------------------------
; Apply the level's conveyor colour after the raw 7-dot animation frames have
; been generated. In monochrome mode the raw white frames are already final.
.proc tilesColorConveyorFrames

    colMaskL = tmpBot + 0
    colMaskR = tmpBot + 1

    lda monochrome
    bne done

    ldy currLevel
    lda mult8, y
    clc
    adc #(DATA_CONVEYOR / $10) - 1
    tay
    lda levelMasks, y
    tay
    lda masksLeft, y
    sta colMaskL
    lda masksRight, y
    sta colMaskR

    ldy #0
loop:
    lda conveyorAnimTiles, y
    and colMaskL
    sta conveyorAnimTiles, y
    iny
    lda conveyorAnimTiles, y
    and colMaskR
    sta conveyorAnimTiles, y
    iny
    cpy #CONVEYOR_FRAMES * TILE_BYTES
    bne loop

done:
    rts

.endproc

;-----------------------------------------------------------------------------
; Copy a pre-animated key tile into the tilesInstances so it looks as
; though the key is animating
.proc tilesAnimateKeys

    ldx keysFrameNum                            ; get the frame
    dex                                         ; step
    bpl :+                                      ; underflow
    ldx #3                                      ; reset - frames are 0 to 6, but go to render + 1
:
    stx keysFrameNum                            ; save the new frame
    inx                                         ; go one frame past
    lda mult16, x                               ; get the byte offset to the frame
    tax                                         ; put it in x
    dex                                         ; and go to the last byte of the frame needed

    ldy #TILE_BYTES - 1                         ; set y to copy a whole tile

:
    lda keyAnimTiles, x                         ; read the frame and write to key tile
    sta tilesInstances + DATA_KEY - TILE_BYTES, y
    dex
    dey
    bpl :-

    rts

.endproc

;-----------------------------------------------------------------------------
; Copy a pre-animated conveyor lines over the lines in the conveyor frame tile,
; in the tilesInstances area
.proc tilesAnimateConveyor

    ldx conveyorFrameNum                        ; get the frame
    dex                                         ; step
    bpl :+                                      ; underflow
    ldx #6                                      ; reset - frames are 0 to 6, but go to render + 1
:
    stx conveyorFrameNum                        ; save the new frame
    lda mult16, x                               ; get the byte offset to the frame
    tax                                         ; put it in x

    lda conveyorAnimTiles, x                    ; copy the 4 animated bytes for
    sta tilesInstances + DATA_CONVEYOR - TILE_BYTES

    inx
    lda conveyorAnimTiles, x                    ; instance 0 over
    sta tilesInstances + DATA_CONVEYOR - TILE_BYTES + 1

    inx                                         ; to the tile area 0
    inx
    inx
    lda conveyorAnimTiles, x
    sta tilesInstances + DATA_CONVEYOR - TILE_BYTES + 4

    inx
    lda conveyorAnimTiles, x
    sta tilesInstances + DATA_CONVEYOR - TILE_BYTES + 5

    rts

.endproc
