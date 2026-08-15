;-----------------------------------------------------------------------------
; text.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020, 2026
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "CODE"

;-----------------------------------------------------------------------------
.proc textSHowText

    xpos     = srcPtrL
    ypos     = srcPtrH
    rows     = sizeH
    strIndex = sizeL
    color    = dstPtrL                          ; and H
    fontL    = charGfx + 1
    fontH    = charGfx + 2

    stx xpos
    sty ypos

loop:
    lda #0
    sta fontH                                   ; init the pointer hi to 0 for later mult rol's
    ldx strIndex                                ; get the index into the string

read:
    lda PLACEHOLDER, x                          ; get the character in the string
    sec
    sbc #32                                     ; the font only starts at space (char 32 or $20)
    beq :+
    sbc #9                                      ; gap after space
    asl                                         ; mult by 16 as that's how wide a char is in bytes
    asl
    rol fontH
    asl
    rol fontH
    asl
    rol fontH                                   ; srcPtr now points at the char but $0000 based
:
    adc #<font                                  ; add the font start
    sta fontL
    lda fontH
    adc #>font
    sta fontH                                   ; srcPtr now point at the actual character memory

    lda #8                                      ; font is 8 rows high
    sta rows
    ldy ypos                                    ; start each character on the same line

iLoop:
    lda strIndex                                ; strIndex is also col offset from xpos
    asl                                         ; but font is 2 cols wide
    adc xpos                                    ; add the xpos to get screen col
    adc rowL, y                                 ; and add the row
    sta write + 1                               ; lo byte of where to write to screen buffer
    lda currPageH                               ; get the hi page
    adc rowH, y                                 ; add the row
    sta write + 2                               ; and complete the screen buffer write address

    ldx #1                                      ; set up for copying 2 font bytes (1 char)
charGfx:
    lda PLACEHOLDER, x                          ; get the font
eorMask:
    eor #$00                                    ; eor to invert if necessary
    and color, x                                ; and to get the color needed
write:
    sta PLACEHOLDER, x                          ; and write to screen memory
    dex                                         ; go left a byte
    bpl charGfx                                 ; and repeat to do 2 bytes
    dec rows                                    ; done one of the 8 rows needed
    beq nextChar                                ; repeat for all 8 rows, then done
    iny                                         ; more rows - next row in y
    lda fontL                                   ; move along 2 in the font
    adc #2
    sta fontL
    bcc iLoop
    inc fontH
    bcs iLoop                                   ; BRA

nextChar:
    dec strIndex                                ; string done from the back, so move left in string
    bpl loop                                    ; if not all of string done, loop

done:
    rts

.endproc

;-----------------------------------------------------------------------------
; Macro that takes a lo and hi for the text with optional color and invert wanted
; sets up what's needed to call textShow which does the printing
.macro printXYlh xpos, ypos, textL, textH, len, colorMask, inverse

    .local color, strIndex

    color    = dstPtrL                          ; textShow expects color masks in dstPtr(L and H)
    strIndex = sizeL

    .ifblank colorMask
        lda #$ff                                ; no color (white) is a mask of $ff left and right
        sta color
        sta color + 1
    .else
        ldx colorMask                           ; this is an index into mask[Left|Right]
        lda masksLeft, x
        sta color
        lda masksRight, x
        sta color + 1
    .endif

    .ifblank inverse
        lda #0                                  ; eor o is not inverse
    .else
        lda #$7f                                ; eor $7f inverts the color (leave MSB)
    .endif

    sta textSHowText::eorMask + 1               ; set the eor in the code

    lda textL                                   ; set the string pointer in the code
    sta textSHowText::read + 1
    lda textH
    sta textSHowText::read + 2
    ldx len                                     ; 0 based
    stx strIndex
    lda xpos                                    ; and x/y coords in x and y registers
    asl
    tax
    ldy ypos
    jsr textSHowText                            ; print that string

.endmacro

;-----------------------------------------------------------------------------
; macro to take text address and split it into lo and hi (shorthand)
.macro printXY xpos, ypos, text, len, colorMask, inverse
    printXYlh xpos, ypos, #<text, #>text, len, colorMask, inverse
.endmacro

;-----------------------------------------------------------------------------
; One-byte-wide text path used by the no-scroll UI. xpos is a screen byte,
; unlike printXY where xpos is a two-byte character column.
.proc textShowHalf

    xpos     = srcPtrL
    ypos     = srcPtrH
    rows     = sizeH
    strIndex = sizeL
    color    = dstPtrL                          ; and H
    fontL    = charGfx + 1
    fontH    = charGfx + 2

    stx xpos
    sty ypos

loop:
    lda #0
    sta fontH
    ldx strIndex

read:
    lda PLACEHOLDER, x
    sec
    sbc #32
    beq addFont
    sbc #9
    asl                                         ; packed character index * 8
    asl
    rol fontH
    asl
    rol fontH

addFont:
    clc
    adc #<fontHalf
    sta fontL
    lda fontH
    adc #>fontHalf
    sta fontH

    lda #8
    sta rows
    ldy ypos

rowLoop:
    clc
    lda strIndex
    adc xpos
    tax                                         ; absolute screen byte, also selects colour phase
    clc
    txa
    adc rowL, y
    sta write + 1
    lda currPageH
    adc rowH, y
    sta write + 2

    txa
    and #1
    tax
charGfx:
    lda PLACEHOLDER
eorMask:
    eor #$00
    and color, x
write:
    sta PLACEHOLDER

    dec rows
    beq nextChar
    iny
    inc fontL
    bne rowLoop
    inc fontH
    bne rowLoop                                 ; BRA

nextChar:
    dec strIndex
    bpl loop
    rts

.endproc

;-----------------------------------------------------------------------------
.macro printHalfXYlh xpos, ypos, textL, textH, len, colorMask, inverse

    .local color, strIndex

    color    = dstPtrL
    strIndex = sizeL

    .ifblank colorMask
        lda #$ff
        sta color
        sta color + 1
    .else
        ldx colorMask
        lda masksLeft, x
        sta color
        lda masksRight, x
        sta color + 1
    .endif

    .ifblank inverse
        lda #0
    .else
        lda #$7f
    .endif
    sta textShowHalf::eorMask + 1

    lda textL
    sta textShowHalf::read + 1
    lda textH
    sta textShowHalf::read + 2
    ldx len
    stx strIndex
    ldx xpos
    ldy ypos
    jsr textShowHalf

.endmacro

;-----------------------------------------------------------------------------
.macro printHalfXY xpos, ypos, text, len, colorMask, inverse
    printHalfXYlh xpos, ypos, #<text, #>text, len, colorMask, inverse
.endmacro

;-----------------------------------------------------------------------------
; Build the level-name cache in the one-byte font.
.proc textSetLevelText

    lda #0
    sta sizeL                                   ; index into string
    sta read + 2                                ; hi byte of string address

    lda currLevel                               ; start with the level
    asl                                         ; multiply by 32
    asl
    asl
    asl
    rol read + 2
    asl
    rol read + 2
    adc #<roTextLevel                           ; add the base address of the string
    sta read + 1
    lda #>roTextLevel
    adc read + 2
    sta read + 2                                ; read + 1 as a ptr now points at the string for this level

loop:
    lda #0
    sta srcPtrH                                 ; init the pointer hi to 0 for later mult rol's
    ldx sizeL                                   ; get the index into the string
read:
    lda PLACEHOLDER, x                          ; get the character in the string
    sec
    sbc #32                                     ; the font only starts at space (char 32 or $20)
    beq :+                                      ; gap after space
    sbc #9
    asl                                         ; packed character index * 8
    asl
    rol srcPtrH
    asl
    rol srcPtrH
:
    clc
    adc #<fontHalf                              ; add the half-width font start
    sta srcPtrL
    lda srcPtrH
    adc #>fontHalf
    sta srcPtrH

    ldx sizeL                                   ; cache column; MARGIN is even, so phase matches
    txa
    and #1
    tay
    lda maskGreen, y
    sta dstPtrL

    ldy #0
    .repeat 8, Row
        lda (srcPtrL), y
        eor #$7f
        and dstPtrL
        sta levelNameGfx0 + Row * PLAY_COLS, x
        iny
    .endrepeat

    inc sizeL                                   ; move to the next character in the string
    lda sizeL
    cmp #PLAY_COLS
    bcs done
    jmp loop

done:
    rts

.endproc

;-----------------------------------------------------------------------------
; x has digit (5 means 1's, 4 means 10's, etc)
; a is the number to add 0..9
.proc textAddScore

    clc
    adc score, x                                ; get the current digit
    cmp #'9'+1                                  ; has it rolled over
    bcc okay                                    ; then simply increment
    sec
    sbc #10
    sta score, x                                ; and save over the 9
    lda #1
    dex                                         ; previous digit
    bmi over                                    ; if it rolls over 999999
    cpx #1                                      ; if the digit is now the 010000 (1)
    bne textAddScore                            ; no, then work with this digit
    ldy lives
    cpy #9                                      ; max out at 9 lives (keeps cheat boot on-screen)
    bcs textAddScore
    inc lives                                   ; yes, then add a life
    bne textAddScore                            ; and then work with this digit
okay:
    sta score, x                                ; and store it
over:
    lda #UI_COMPONENT_SCORE                     ; mark the score texts as needing an update
    jmp uiUpdateComponent

done:
    rts

.endproc

;-----------------------------------------------------------------------------
.proc textCheckHighScore

    ldx #0                                      ; start at the most significant digit
:
    lda score, x                                ; get the score
    cmp highScore, x                            ; compare to the high score
    bcc done                                    ; if smaller then highscore gt score
    bne newHigh                                 ; if ne then highscore gt score
    inx                                         ; digits equal so check next digit
    cpx #6                                      ; compare x to max digits (+ 1)
    bcc :-                                      ; x is 5 or less, keep checking digits

done:
    rts

newHigh:
    ldx #5                                      ; copy the 6 score digits over the highscore digits
:
    lda score, x
    sta highScore, x
    dex
    bpl :-
    lda #UI_COMPONENT_HIGHSCORE
    jmp uiUpdateComponent

.endproc

;-----------------------------------------------------------------------------
.proc textColorCycle

    color = tmpBot + 1
    xPos  = tmpBot + 2
    yPos  = tmpBot + 3
    textL = tmpBot + 4
    textH = tmpBot + 5
    len   = tmpBot + 6

prntLoop:
    printXYlh xPos, yPos, textL, textH, #0, color

    dec len                                     ; one less character to color
    beq done                                    ; all characters done?
    inc xPos                                    ; move to the next character on screen
    inc textL                                   ; and move to the next character in the sting
    bne :+                                      ; did the string wrap a buffer
    inc textH                                   ; yes, up the Hi
:
    dec color                                   ; prev color
    bpl :+                                      ; still ge 0
    lda #4                                      ; no, wrap to index 4
    sta color                                   ; and save that as the color
:
    jmp prntLoop                                ;and print this character

done:
    rts

.endproc
