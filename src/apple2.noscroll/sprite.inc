;-----------------------------------------------------------------------------
; sprite.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020, 2026
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
; sizeH = absolute byte parity of the fixed-X sprite
; Clobbers: a, y
.proc spriteApplyMaskToFrames

    numFrames = tmpBot + 0
    colMaskL  = tmpBot + 1
    colMaskR  = tmpBot + 2
    rows       = tmpBot + 3

    sty numFrames                               ; save y
    tay                                         ; put color index in y

    lda masksLeft, y                            ; look up the masks for the color
    sta colMaskL
    lda masksRight, y
    sta colMaskR

    clc
    lda mult48L, x                              ; build a pointer to the frame
    adc #<spriteInstances
    sta srcPtrL
    lda mult48H, x
    adc #>spriteInstances
    sta srcPtrH

nextFrame:
    lda #16
    sta rows
nextRow:
    ldy #0
    lda sizeH                                   ; select masks by absolute screen-byte parity
    and #1
    bne odd
even:
    lda (srcPtrL), y
    and colMaskL
    sta (srcPtrL), y
    iny
    lda (srcPtrL), y
    and colMaskR
    sta (srcPtrL), y
    iny
    lda (srcPtrL), y
    and colMaskL
    sta (srcPtrL), y
    jmp advance

odd:
    lda (srcPtrL), y
    and colMaskR
    sta (srcPtrL), y
    iny
    lda (srcPtrL), y
    and colMaskL
    sta (srcPtrL), y
    iny
    lda (srcPtrL), y
    and colMaskR
    sta (srcPtrL), y

advance:
    clc
    lda srcPtrL
    adc #3
    sta srcPtrL
    bcc :+
    inc srcPtrH
:
    dec rows
    bne nextRow
    dec numFrames
    bne nextFrame

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
    lda mult48L, x
    adc #<spriteInstances
    sta srcPtrL
    lda mult48H, x
    adc #>spriteInstances
    sta srcPtrH

    ldx newFrame                                ; point dstPtr at the target frame
    clc
    lda mult48L, x
    adc #<spriteInstances
    sta dstPtrL
    lda mult48H, x
    adc #>spriteInstances
    sta dstPtrH

    lda #0                                      ; 256 or less bytes (no Hi)
    sta sizeH
    lda #SPRITE_BYTES                           ; copy one 48-byte frame
    sta sizeL
    jsr spriteCopyMemSrcToDst                   ; use copymem to copy one frame

    rts

.endproc

;-----------------------------------------------------------------------------
; Invert the pixels of a frame
; IN:
; x = frame number
.proc spriteInvertFrame

    clc
    lda mult48L, x                              ; make srcPtr point at the frame
    adc #<spriteInstances
    sta srcPtrL
    lda mult48H, x
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

    lda mult48L, y                              ; turn the number of frames into num bytes
    sta count                                   ; save as a count

    clc                                         ; and clear carry
    lda mult48L, x                              ; make srcPtr point at the
    adc #<spriteInstances
    sta srcPtrL
    lda mult48H, x
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
; Make an instance of the bitmap (index in a) into the spriteInstance buffer.
; Source frames are 16-byte 1bpp; destination frames are 16 rows x 3 bytes.
; Horizontal sprites receive adjacent even and odd frame sets. Fixed-X
; vertical sprites and the door receive only the parity they actually occupy.
; IN:
; a - bitmapIdx
; x - instanceIdx
.proc spriteInstanceSpriteFrames

    instanceIdx = tmpBot + 0
    numFrames   = tmpBot + 1
    variants    = tmpBot + 2
    parity      = tmpBot + 3
    colMaskL    = tmpBot + 4
    colMaskR    = tmpBot + 5
    sourceByte  = tmpBot + 6

    stx instanceIdx

    ldy #0
    sty srcPtrH
    ldy #4                                      ; source frame index * 16
:
    asl
    rol srcPtrH
    dey
    bne :-
    clc
    adc #<sprite08Half
    sta srcPtrL
    lda srcPtrH
    adc #>sprite08Half
    sta srcPtrH

    ldy spriteFramesIdx, x
    clc
    lda mult48L, y                              ; destination frame * 48
    adc #<spriteInstances
    sta dstPtrL
    lda mult48H, y
    adc #>spriteInstances
    sta dstPtrH

    lda #8
    sta numFrames
    lda spriteClass, x
    bit CLASS_FOUR_FRAME
    beq :+
    lsr numFrames                               ; four logical frames
:
    lda #2
    sta variants
    lda #0
    sta parity                                  ; horizontal layout is even set, then odd set
    lda spriteClass, x
    bit CLASS_MOVE_Y
    bne fixedX
    bit CLASS_DOOR
    beq color
fixedX:
    lda #1
    sta variants
    lda spriteXPos, x
    and #1
    sta parity

color:
    ldy spriteColor, x
    lda masksLeft, y
    sta colMaskL
    lda masksRight, y
    sta colMaskR

nextVariant:
    lda numFrames
    sta sizeL                                   ; frames remaining in this parity set

nextFrame:
    lda #16
    sta sizeH                                   ; rows remaining in this frame

nextRow:
    ldy #0
    lda (srcPtrL), y
    sta sourceByte
    lsr
    lsr
    lsr
    lsr
    tax
    lda parity
    bne oddRow

evenRow:
    lda binDouble, x
    ora #$80
    and colMaskL
    sta (dstPtrL), y
    iny
    lda sourceByte
    and #$0F
    tax
    lda binDouble, x
    sec
    ror
    and colMaskR
    sta (dstPtrL), y
    iny
    lda #0                                      ; even art occupies only two bytes
    sta (dstPtrL), y
    jmp advanceRow

oddRow:
    lda binDouble, x                            ; expanded left byte
    tax
    lda halfShiftDots, x
    ora #$80
    and colMaskR                                ; odd absolute byte starts with right mask
    sta (dstPtrL), y
    lda halfShiftCarry, x
    pha

    lda sourceByte
    and #$0F
    tax
    lda binDouble, x
    sec
    ror                                         ; expanded right byte
    tax
    lda halfShiftDots, x
    sta sourceByte
    pla
    ora sourceByte
    ora #$80
    and colMaskL
    iny
    sta (dstPtrL), y
    lda halfShiftCarry, x
    ora #$80
    and colMaskR
    iny
    sta (dstPtrL), y

advanceRow:
    inc srcPtrL
    bne :+
    inc srcPtrH
:
    clc
    lda dstPtrL
    adc #3
    sta dstPtrL
    bcc :+
    inc dstPtrH
:
    dec sizeH
    bne nextRow
    dec sizeL
    beq :+
    jmp nextFrame
:

    dec variants
    beq done

    lda numFrames                               ; rewind source for the odd set
    asl
    asl
    asl
    asl
    sta sourceByte
    sec
    lda srcPtrL
    sbc sourceByte
    sta srcPtrL
    bcs :+
    dec srcPtrH
:
    inc parity
    jmp nextVariant

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
    ldx numSprites
    lda spriteXPos, x
    and #1
    sta sizeH
    ldx currLevel
    lda door_color1, x
    ldx originalFrame
    ldy #1
    jsr spriteApplyMaskToFrames

    ldx currLevel
    lda door_color2, x
    beq :+
    ldx numSprites
    lda spriteXPos, x
    and #1
    sta sizeH
    ldx currLevel
    lda door_color2, x
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
    pha
    ldx numSprites
    dex
    lda spriteXPos, x
    and #1
    sta sizeH
    pla
    ldx newFrame                                ; the frame in x
    ldy #1                                      ; and the number of frames to process in Y
    jsr spriteApplyMaskToFrames                 ; mask the new eugene to the "count" color

    inc newFrame                                ; go up a frame
    dec count                                   ; and dec the loop counter
    bne :-                                      ; and do for the number of loops (3)

    rts                                         ; there are now 4 eugenes, White, Green, Orange & Purple

.endproc
