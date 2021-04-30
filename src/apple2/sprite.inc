;-----------------------------------------------------------------------------
; sprite.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "CODE"

;-----------------------------------------------------------------------------
; Copy bytes from srcPtr to dstPtr
; IN:       - srcPtr - start of copy
; dstPtr    - start of non-overlapping destination
; size      - number of bytes to copy
; Clobbers: a, y
.proc spriteCopyMemSrcToDst

    ldy #0
hiCopy:
    dec sizeH
    bmi lowCopy
:
    lda (srcPtrL), y
    sta (dstPtrL), y
    dey
    bne :-
    inc srcPtrH
    inc dstPtrH
    bne hiCopy

lowCopy:
    ldy sizeL
    dey
    bmi done
:
    lda (srcPtrL), y
    sta (dstPtrL), y
    dey
    bpl :-

done:
    rts

.endproc

;-----------------------------------------------------------------------------
; Look up the color, and apply those masks to the frames
; IN:   x = start frame
; y = num frames
; a = color index
; Clobbers: a, y
.proc spriteApplyMaskToFrames

    instanceIdx = tmpBot + 0
    colMaskL    = tmpBot + 1
    colMaskR    = tmpBot + 2
    numFrames   = tmpBot + 3

    sty numFrames                               ; save y
    tay                                         ; put color index in y

    lda masksLeft, y                            ; look up the masks for the color
    sta colMaskL
    lda masksRight, y
    sta colMaskR

    lda mult64L, x                              ; build a pointer to the frame
    sta srcPtrL
    lda mult64H, x
    adc #>spriteInstances
    sta srcPtrH

    ldy numFrames                               ; convert frames to bytes
    lda mult64H, y
    sta sizeH
    lda mult64L, y
    sta sizeL

    ldy #0                                      ; do blocks of 256
hiPass:
    dec sizeH                                   ; see if there's a hi block to do
    bmi lowPass                                 ; if none (remain) to do, move on
:
    lda (srcPtrL), y                            ; do a left hand byte
    and colMaskL
    sta (srcPtrL), y
    dey
    lda (srcPtrL), y                            ; then a right hand byte
    and colMaskR
    sta (srcPtrL), y
    dey
    bne :-                                      ; for 256 bytes
    inc dstPtrH                                 ; advance the dest ptr Hi
    bne hiPass                                  ; BRA

lowPass:
    ldy sizeL                                   ; do bytes remaining lt 256
    dey
    bmi done                                    ; keep going till all done
:
    lda (srcPtrL), y
    and colMaskL
    sta (srcPtrL), y
    dey
    lda (srcPtrL), y
    and colMaskR
    sta (srcPtrL), y
    dey
    bpl :-

done:
    rts

.endproc

;-----------------------------------------------------------------------------
; Copy one frame to another
; IN:
; originalFrame    = tmpBot + 4
; newFrame         = tmpBot + 5
; Clobbers: a, x, y
.proc spriteCopyFrameToFrame

    originalFrame    = tmpBot + 4
    newFrame         = tmpBot + 5

    clc

    ldx originalFrame                           ; point srcPtr at the original frame
    lda mult64L, x
    sta srcPtrL
    lda mult64H, x
    adc #>spriteInstances
    sta srcPtrH

    ldx newFrame                                ; point dstPtr at the target frame
    lda mult64L, x
    sta dstPtrL
    lda mult64H, x
    adc #>spriteInstances
    sta dstPtrH

    lda #0                                      ; 256 or less bytes (no Hi)
    sta sizeH
    lda #64                                     ; just 64 bytes to copy
    sta sizeL
    jsr spriteCopyMemSrcToDst                   ; use copymem to copy a 64 byte frame

    rts

.endproc

;-----------------------------------------------------------------------------
; Invert the pixels of a frame
; IN:
; x = frame number
.proc spriteInvertFrame

    clc
    lda mult64L, x                              ; make srcPtr point at the frame
    sta srcPtrL
    lda mult64H, x
    adc #>spriteInstances
    sta srcPtrH

    ldy #SPRITE_BYTES - 1                       ; do for a whole frame (0 based)
:
    lda (srcPtrL), y                            ; get the frame byte
    eor #%01111111                              ; invert except for the MSB
    sta (srcPtrL), y                            ; and save the byte
    dey                                         ; one less byte to do
    bpl :-                                      ; do for all bytes

    rts

.endproc

;-----------------------------------------------------------------------------
; Clear all the pixels of a frame
; IN:
; x = frame number
; y = number of frames to clear
.proc spriteClearFrames

    count = sizeL

    lda mult64L, y                              ; turn the number of frames into num bytes
    sta count                                   ; save as a count

    clc                                         ; and clear carry
    lda mult64L, x                              ; make srcPtr point at the
    sta srcPtrL
    lda mult64H, x
    adc #>spriteInstances
    sta srcPtrH

    ldy count                                   ; how many bytes to clear
    dey                                         ; make zero based
    lda #0                                      ; value to write
:
    sta (srcPtrL), y                            ; write 0 to frame
    dey                                         ; previous byte in frame
    bpl :-                                      ; do for all, incl. zero'th byte

    rts

.endproc

;-----------------------------------------------------------------------------
; Make an instance of the bitmap (index in a) into the spriteInstance buffer
; while expanding the bitmap from 32 byte 1bpp into 64 byte 2bpp and masking
; the instance for the required color.
; IN:
; a - bitmapIdx
; x - instanceIdx
.proc spriteInstanceSpriteFrames

; count       = tmpBot + 0
; spriteIdx   = tmpBot + 1
    instanceIdx  = tmpBot + 2
    srcIdx       = tmpBot + 3
    dstIdx       = tmpBot + 4
    colMaskL     = tmpBot + 5
    colMaskR     = tmpBot + 6

    ldy #0
    sty srcPtrH
    sty dstPtrH

    ldy #5                                      ; mult * 32 (shl 5 times) since each src frame is 32 bytes
:
    asl                                         ; shift the low
    rol srcPtrH                                 ; and the hi, and move carry into hi if needed
    dey                                         ; do for all 6 iterations
    bne :-

    adc #<sprite08                              ; add the memory offset off the non-willy src sprites
    sta srcPtrL
    lda #>sprite08
    adc srcPtrH
    sta srcPtrH                                 ; src ptr now points at the 1st frame

    lda spriteFramesIdx, x                      ; get the sprite dest frame
    ldy #6                                      ; mult * 64 (shl 6 times) since each frame is 64 bytes
:
    asl                                         ; shift the lo
    rol dstPtrH                                 ; and the hi, and move carry into hi if needed
    dey                                         ; do for all 6 iterations
    bne :-
    sta dstPtrL                                 ; save the lo
    lda dstPtrH                                 ; get the hi
    adc #>spriteInstances                       ; and make relative to the buffer
    sta dstPtrH                                 ; and save the hi

    lda #1                                      ; assume 4 frames = 256 bytes
    sta sizeH
    lda spriteClass, x                          ; get the class
    bit bit1Mask                                ; CLASS_FOUR_FRAME is it 4 frames
    bne :+                                      ; yes, all set
    inc sizeH                                   ; 8 frames = 512 bytes = 2 Hi

:
    ldy instanceIdx                             ; get the instance
    lda spriteColor, y                          ; and get the color for the instance
    tay                                         ; put the color index in y
    lda masksLeft, y                            ; get the color mask
    sta colMaskL
    lda masksRight, y                           ; do the same for the right
    sta colMaskR                                ; SQW - look at comments but save for second (inverse) buffer

    ldy #0
    sty dstIdx                                  ; set the src and dst indices to start at 0
    sty srcIdx                                  ; srcIndex moves at 1/2 of dstIndex

copyFrames:
    ldy srcIdx                                  ; get the source index
    lda (srcPtrL), y                            ; get a (left) src byte at the source index
    pha                                         ; save so the right nibble can be expanded later
    lsr                                         ; make the left nibble the low nibble
    lsr
    lsr
    lsr
    tax                                         ; put the value in x
    lda binDouble, x                            ; look up the "pixel doubled" value
    ora #$80                                    ; and set the color msb "on"
    and colMaskL                                ; mask it with appropriate color
    ldy dstIdx                                  ; get the destination offset
    sta (dstPtrL), y                            ; and save to instance destination
    iny                                         ; move the destination along one
    pla                                         ; get the source byte
    and #$0f                                    ; mask so only right nibble
    tax                                         ; put it in x
    lda binDouble, x                            ; and look up the "doubled" pixel values
    sec                                         ; set carry so a rotate will be equiv to or #$80
    ror                                         ; and rotate, making it a "right" byte
    and colMaskR                                ; mask it with appropriate color
    sta (dstPtrL), y                            ; and save to instance destination
    iny                                         ; move the dest index along again
    sty dstIdx                                  ; and save the index
    bne :+                                      ; if the index rolled over
    inc dstPtrH                                 ; move the hi byte along
    dec sizeH                                   ; check if moved all required 4 * 32 src byte blocks
    beq done
:
    inc srcIdx                                  ; move the src index along
    bne copyFrames                              ; do max 256 bytes = 8 * 32 byte src frames

done:
    rts

.endproc

;-----------------------------------------------------------------------------
; Copy the door frame, invert the copy, mask both and combine
.proc spriteDoorSetup

    originalFrame    = tmpBot + 4
    newFrame         = tmpBot + 5

    ldx numSprites                              ; numSprites is the door sprite index
    lda spriteFramesIdx, x
    tax
    stx originalFrame
    inx
    stx newFrame
    jsr spriteCopyFrameToFrame                  ; make a copy y = instanceIdx, a = srcFrame, x = dstFrame

    ldx newFrame
    jsr spriteInvertFrame                       ; invert the instance frame bits (leave msb alone)

    ldx currLevel
    lda door_color1, x
    beq :+
    ldx originalFrame
    ldy #1
    jsr spriteApplyMaskToFrames

    ldx currLevel
    lda door_color2, x
    beq :+
    ldx newFrame
    ldy #1
    jmp spriteApplyMaskToFrames

:
    rts

.endproc

;-----------------------------------------------------------------------------
; Make 4 copies of Eugene frame 0 into frames 1-4 and apply a different
; color mask to the additional frames
.proc spriteEugeneSetup

    originalFrame    = tmpBot + 4
    newFrame         = tmpBot + 5
    count            = tmpBot + 6

    ldx numSprites
    dex                                         ; eugene is sprite before the door

    lda spriteFramesIdx, x                      ; get the frame where eugene is
    tax                                         ; put in x
    stx originalFrame                           ; and call it the original
    inx                                         ; and go to the next frame
    stx newFrame                                ; and call it the new frame
    ldx #3                                      ; and set the loop count to 3
    stx count
:
    jsr spriteCopyFrameToFrame                  ; make a copy of eugene, x = ori, y = new

    lda count                                   ; get the count in a (as a color mask index)
    ldx newFrame                                ; the frame in x
    ldy #1                                      ; and the number of frames to process in Y
    jsr spriteApplyMaskToFrames                 ; mask the new eugene to the "count" color

    inc newFrame                                ; go up a frame
    dec count                                   ; and dec the loop counter
    bne :-                                      ; and do for the number of loops (3)

    rts                                         ; there are now 4 eugenes, White, Green, Orange & Purple

.endproc
