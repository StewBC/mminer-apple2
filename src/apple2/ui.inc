;-----------------------------------------------------------------------------
; ui.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "CODE"

;-----------------------------------------------------------------------------
.proc uiUpdateComponent

    ora uiComponent
    sta uiComponent
    lda #2
    sta updateUICount

    rts 

.endproc 

;-----------------------------------------------------------------------------
.proc uiUpdate

    lda uiComponent

    bit bit0Mask                                ; UI_COMPONENT_NAME
    beq :+
    jsr screenDrawLevelName
    lda uiComponent
:
    bit bit1Mask                                ; UI_COMPONENT_AIR_NAME
    beq :+
    printXY #0, #(17*8), roTextAir, #4, #2, 1
    jsr screenDrawAirFrame
    lda uiComponent
:
    bit bit2Mask                                ; UI_COMPONENT_AIR
    beq :+
    jsr screenDrawAirRemaining
    lda uiComponent
:
    bit bit3Mask                                ; UI_COMPONENT_SCORE_NAME
    beq :+
    printXY #4,  #(19*8), roTextHighScore, #3
    printXY #11, #(19*8), roTextScore, #4
    lda uiComponent
:
    bit bit4Mask                                ; UI_COMPONENT_SCORE
    beq :+
    printXY #11, #(20*8), score, #5
    lda uiComponent
:
    bit bit5Mask                                ; UI_COMPONENT_LIVES
    beq :+
    jsr screenDrawLives
    lda uiComponent
:
    bit bit6Mask                                ; UI_COMPONENT_HIGHSCORE
    beq :+
    printXY #3, #(20*8), highScore, #5
:
    dec updateUICount
    bne :+
    lda #0
    sta uiComponent
:
    rts 
    
.endproc 

;-----------------------------------------------------------------------------
; 28209 cycle delay from start till after rts
.proc uiDelay 

    ldy #$80
ySet:
    ldx #0
:
    dex
    bne :-
    dey 
    bne :-

    rts
     
.endproc 

;-----------------------------------------------------------------------------
; This routine shows the MANIC and MINER text on screen.
; the macro uiShowMMTextXY puts specific values appropriate for each right
; into the routine (such as the address of the character width array)
; The Manic & Miner words are stored in a "compressed" form, this also decodes
; that.  Each letter "pixel" is stored as a bit.
.proc uiShowMMText

    row      = srcPtrL
    col      = srcPtrH
    offset   = dstPtrL
    index    = dstPtrH
    colMaskL = sizeL
    colMaskR = sizeH
    width    = tmpBot + 0
    height   = tmpBot + 1
    dataByte = tmpBot + 2
    dr       = tmpBot + 3
    dc       = tmpBot + 4
    dw       = tmpBot + 5
    pr       = tmpBot + 6
    
    sty row 
    stx col
    lda #0
    sta offset 
    sta index 

strLoop:
    ldx index
colorLoc:
    lda PLACEHOLDER, x                          ; unpack the color masks
    tay 
    lda masksLeft, y 
    sta colMaskL
    lda masksRight, y 
    sta colMaskR
    lda #6                                      ; the text is 6 rows high
    sta height 
    lda row 
    sta dr                                      ; set the working counter to the row

charLoop:
    lda col 
    sta dc                                      ; set the working counter to the column
    ldx index                                   ; get the index to the character in the string
widthLoc:
    lda PLACEHOLDER, x                          ; get the width of the character
    sta width                                   ; save
    sta dw                                      ; and init the working width
    ldx offset                                  ; the offset is into the encoded data
dataLoc:
    lda PLACEHOLDER, x                          ; get the next encoded character
    inc offset                                  ; and move the index
    sta dataByte                                ; save the character
colLoop:
    lda dataByte                                ; load the character
    asl                                         ; shift out the MSB to get the bit
    sta dataByte                                ; save the new shifted encoded character
    bcc skipPlot                                ; if bit was 0, blank, nothing to do
    lda #8                                      ; 1-bit to be drawn.  "pixel" is 8 pixel-rows high
    sta pr                                      ; save row draw counter
    lda dr                                      ; load the screen draw row where drawing should happen
    asl                                         ; * 8
    asl 
    asl
    tay                                         ; store the row in Y
    lda dc                                      ; get the column
    and #1                                      ; and see if the column is odd or even (for color mask)
    tax 
:
    lda dc                                      ; start with the column
    adc rowL, y                                 ; and calculate the hi-res row/col address
    sta write + 1
    lda rowH, y
    adc currPageH                               ; add the page to draw to
    sta write + 2
    lda #$ff                                    ; assume all bits on
    and colMaskL, x                             ; but then mask to get appropriate color
write:
    sta PLACEHOLDER                             ; write to the screen
    iny                                         ; next hi-res pixel-row
    dec pr                                      ; and one less row to draw
    bne :-                                      ; do all 8 rows

skipPlot:
    inc dc                                      ; go to the next column
    dec dw                                      ; one less to do in the width of the character
    bpl colLoop                                 ; if not done the whole character, keep going
    inc dr                                      ; move down to the next row of the character
    dec height                                  ; one less row to do
    bpl charLoop                                ; keep going till the whole character height done
    lda width                                   ; move the draw col by the width of the character just drawn
    clc 
    adc col 
    sta col
    inc index                                   ; and move the string index to the next character
    lda index
    cmp #6
    bcc strLoop                                 ; if not all 5 characters (MANIC or MINER) done, keep going

    rts
    
.endproc 

;-----------------------------------------------------------------------------
; Prep uiShowMMText internal variables with data relevant for the
; specific text the macro is called with
.macro uiShowMMTextXY column, row, data, widths, colors 

    lda #<data                                  ; MANIC or MINER bit-arrays
    sta uiShowMMText::dataLoc + 1
    lda #>data 
    sta uiShowMMText::dataLoc + 2
    lda #<widths 
    sta uiShowMMText::widthLoc + 1              ; array of letter-widths in MANIC or MINER
    lda #>widths 
    sta uiShowMMText::widthLoc + 2
    lda #<colors                                ; array of letter colors in the words
    sta uiShowMMText::colorLoc + 1
    lda #>colors 
    sta uiShowMMText::colorLoc + 2
    ldx column                                  ; screen location passed in x/y
    ldy row
    jsr uiShowMMText                            ; show the word on-screen

.endmacro

;-----------------------------------------------------------------------------
.proc uiTitleScreen

    scrollPtrL = 0                              ;tmpBot + 0
    scrollPtrH = 1                              ;tmpBot + 1
    scrollLen  = 2                              ;tmpBot + 2
    scrollIdx  = 3                              ;tmpBot + 3
    titleState = 4                              ;currLevel


    lda #0
    sta leftEdge                                ; reset the left edge

    lda #11*8                                   ; position willy for the UI
    sta willyYPos
    lda #0
    sta willyFrame 
    lda #18
    sta willyXPos

    lda #<titleMusic                            ; init the music ptr
    sta musicL
    lda #>titleMusic
    sta musicH

    ldx #1                                      ; do a full screen clear of both buffers
    jsr screenClear
    jsr screenSwap
    ldx #1
    jsr screenClear

    lda #0
    sta titleState                              ; set to bounce manic miner / audio
    sta uiComponent                             ; and init the ui update to nothing
    lda #UI_COMPONENT_SCORE_NAME | UI_COMPONENT_SCORE | UI_COMPONENT_HIGHSCORE
    jsr uiUpdateComponent                       ; add an update for bottom part of screen

    jsr screenDrawWilly                         ; show willy on this screen
    uiShowMMTextXY #6, #6, manicText, manicCharWidth, manicColors
    printXY #0, #22*8, roTextAppleIIVersion, #19
    printXY #0, #23*8, roTextStefan, #19
    jsr uiUpdate                                ; show the UI on the Manic screen
    jsr screenSwap

    jsr screenDrawWilly                         ; show willy on the other screen
    uiShowMMTextXY #6, #6, minerText, minerCharWidth, minerColors
    printXY #0, #22*8, roTextAppleIIVersion, #19
    printXY #0, #23*8, roTextStefan, #19
    jsr uiUpdate                                ; show the UI on the Miner screen

    lda KBDSTRB

mainLoop:
    jsr screenSwap                              ; swap screens (manic/miner) or scroll text
    jsr inputUI                                 ; read keys -1 - quit, 0 - no key, 1 - go to game
    beq stayInUI                                ; no key
    bpl playGame                                ; go to game
    lda #EVENT_EXIT_GAME                        ; quit
    bne exit 
playGame:
    lda #EVENT_OK
exit:
    jmp done

stayInUI:
    lda titleState                              ; get the state (bounce vs scroll)
    beq bounce
    jmp introScroll                             ; 0 - bounce, 1 - scroll

bounce:
    jsr audioPlayTitleNote                      ; play the tune
    bcc mainLoop                                ; tune done when carry is set, else bounce

    lda #2
    sta titleState                              ; use this as a temporary counter
:
    ldx #0                                      ; clear the upper portion of the screen
    jsr screenClear                             ; show both manic & miner
    uiShowMMTextXY #6, #0, manicText, manicCharWidth, manicColors
    uiShowMMTextXY #6, #8, minerText, minerCharWidth, minerColors
    jsr screenDrawWilly                         ; show willy as well

    jsr screenSwap
    dec titleState                              ; do for both buffers
    lda titleState
    bne :-

    lda #1                                      ; set the state to the scrolling screen
    sta titleState

    lda #<roTextIntro                           ;init the scrolling message text
    sta scrollPtrL
    lda #>roTextIntro
    sta scrollPtrH
    lda #0
    sta scrollLen
    lda #19
    sta scrollIdx

introScroll:                                    ; show the scrolling message
    ldy willyYPos                               ; start by erasing willy so the eor draw works
    lda #16                                     ; 16 rows from his Y
    sta sizeL                                   ; track rows in sizeL
:
    clc 
    lda willyXPos                               ; start with his X
    asl                                         ; * 2 for screen coordinates
    adc rowL, y                                 ; get the hires coordinates
    sta writeZero + 1
    lda rowH, y 
    adc currPageH
    sta writeZero + 2
    lda #0                                      ; write 4 zero-bytes to each row
    ldx #3
writeZero:
    sta PLACEHOLDER, x 
    dex 
    bpl writeZero
    iny                                         ; next hi-res row
    dec sizeL                                   ; one more row done
    bne :-

    lda willyFrame                              ; get the current frame
    clc 
    adc #2                                      ; advance by 2
    and #7                                      ; and keep in the frame range
    sta willyFrame                              ; update the frame
    jsr screenDrawWilly                         ; and draw willy in the new pose

    printXYlh scrollIdx, #16*8, scrollPtrL, scrollPtrH, scrollLen
    lda scrollIdx                               ; see if scrolled all the way into the screen
    beq :+                                      ; if printing at 0, then scrolled all the way in
    dec scrollIdx                               ; not scrolled in all the way, so move the start left
    inc scrollLen                               ; and increase the length to print by 1
    bne :++                                     ; and skip moving the start of the message
:
    inc scrollPtrL                              ; move the scroller so the left disappears off
    bne :+                                      ; the left end of the screen
    inc scrollPtrH
:
    jsr uiDelay                                 ; wait a bit so the message can be read

    ldy scrollLen                               ; see if this is the end of the message
    lda (scrollPtrL), y
    bne :+                                      ; if not a zero, still in message
    dec scrollLen                               ; start printing less of the message so the tail scrolls across
    bmi demoTime                                ; when completely done, go to demo mode
:
    jmp mainLoop                                ; repeat till fully scrolled

demoTime:
    lda #DEMO_TIMER_INITAL                      ; set up the demo variables
    sta demoTimer
    lda #1
    sta demoDirection

done:
    sta demoMode
    rts 

.endproc 

;-----------------------------------------------------------------------------
.proc uiWaitForIntroEnter

    iter  = tmpBot + 0                          ; how many times to loop
    color = tmpBot + 1                          ; the starting color for the string
    xPos  = tmpBot + 2                          ; x for string
    yPos  = tmpBot + 3                          ; y for string
    textL = tmpBot + 4                          ; string pointer
    textH = tmpBot + 5
    len   = tmpBot + 6                          ; how many characters (0 based)

    lda KBDSTRB                                 ; clear the keyboard

    jsr screenSwap::valueSwap
    printXY #0, #22*8, roTextPressEnter, #19
    lda #$28                                    ; intentionally outside the range
    sta color                                   ; it gives an interesting "materialize" effect
    lda #22*8
    sta yPos

cycleLoop:
    lda #6                                      ; print ENTER at x 4
    sta xPos 
    lda #<roTextEnter                           ; point at ENTER text
    sta textL 
    lda #>roTextEnter
    sta textH
    lda #5
    sta len
    jsr textColorCycle                          ; show the text in color
    ldy #$40
    jsr uiDelay::ySet

    lda KBD                                     ; hold the load screen graphic till a key is pressed
    bpl cycleLoop

    lda KBDSTRB                                 ; clear the keyboard
    jsr screenSwap::valueSwap

    ldx #1                                      ; for clear-screen, x = 1 is all clear, x = 0 is partial
    jsr screenClear
    jsr screenSwap                              ; swap to see page 1
    ldx #1
    jmp screenClear                             ; all clear page 2

.endproc 
