;-----------------------------------------------------------------------------
; input.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "CODE"

;-----------------------------------------------------------------------------
.proc inputGet

    lda KBD
    bmi hasKey

    lda cheatActive                             ; is the cheat code active
    beq :+                                      ; no - normal play
    lda cheatIndex                              ; is the 6 down
    beq :+                                      ; no - normal play
    jmp setJmpEvent                             ; cheat active and 6 down - keep resetting to this level
:
    rts

hasKey:
    bit KBDSTRB
    and #$5f                                    ; strip MSB and upper/lower case (to upper)

    tax 
    lda demoMode
    beq :+ 
    jmp premusic
:
    txa 
    bne right                                   ; $5f clears space so a is 0 for jump

jump:
    lda userKeyMask
    eor #MASK_AIR                               ; AIR marks the start of a jump
    sta userKeyMask 
    rts

right:
    cmp #'W'                                    ; go right with w (left handed) or P
    beq :+
    cmp #'P'
    bne left
:
    lda userKeyMask
    and #<~MASK_LEFT                            ; clear left
    eor #MASK_RIGHT                             ; activate right
    sta userKeyMask
    rts

left:
    cmp #'Q'                                    ; go left with q (left handed) or o
    beq :+
    cmp #'O'
    bne camera
:
    lda userKeyMask
    and #<~MASK_RIGHT                           ; clear right
    eor #MASK_LEFT                              ; activate left
    sta userKeyMask
    rts

camera:
    cmp #'C'                                    ; c toggles the scroll mode
    bne cheat                                   ; if not c maybe cheat?
    lda #1                                      ; xor the camera mode with 1
    eor cameraMode
    sta cameraMode
    rts                                         ; done, can't be any other key
    
cheat:
    ora #%00100000                              ; make "normal" characters
    ldx cheatActive                             ; see if the cheat mode is on
    bne checkJump                               ; if yes, see if a jump needs to happen

    ldx cheatIndex                              ; active, not on
    cmp roTextCheatCode, x                      ; is this the next cheat code character
    bne resetCheat                              ; no, reset the cheat
    inx                                         ; yes
    stx cheatIndex                              ; inc the index
    cpx #7                                      ; all 7 typed
    beq :+                                      ; yes
    rts                                         ; not yet, so done here
:
    ldx #1                                      ; make the cheat active
    stx cheatActive

resetCheat:
    ldx #0                                      ; set the cheat index to 0
    stx cheatIndex
jumpNotActive:
    and #%11011111                              ; restore the acc to uppercase
    bne music                                   ; BRA

checkJump:
    cmp #'6'                                    ; is this a 6
    beq jumpToggle                              ; if yes, toggle the jump mode on/off
    bcs jumpNotActive                           ; gt 6, then nothing to do with cheat
    ldx cheatIndex                              ; is 6 down
    beq jumpNotActive                           ; no, process as non-cheat key
    cmp #'1'
    bcc jumpNotActive                           ; less than 1, not cheat code
    sec
    sbc #'1'                                    ; make key 0 based
    tax                                         ; and index in x
    lda bitMasks, x                             ; get the appropriate bit
    eor currLevel                               ; and toggle in the current level
    cmp #20                                     ; if the level ge 20 then set to 0
    bcc :+
    lda #0
:
    sta currLevel 
setJmpEvent:
    lda #EVENT_CHEAT_JUMP                       ; set the jump event active
    ora eventState
    sta eventState
    rts

jumpToggle:
    lda #1                                      ; prep to toggle the jump state
    eor cheatIndex
    sta cheatIndex                              ; save it
    beq :+                                      ; is it off, just leave
    lda #0                                      ; just turned on, reset
    sta currLevel                               ; the level to level 0
:
    rts

premusic:
    txa                                         ; restore the read-key
music:
    cmp #'M'                                    ; m toggles music on/off
    bne :+
    LDA audioMask
    eor #AUDIO_MUSIC
    sta audioMask
    rts 

:
    cmp #'B'
    bne :+
    lda #1
    eor monochrome
    sta monochrome
    jmp tilesPrepForLevel

:
    cmp #'S'                                    ; s toggles in-game sound on/off
    bne :+
    LDA audioMask
    eor #AUDIO_SOUND
    sta audioMask
    rts 

:
    cmp #$1B                                    ; ESC
    beq quit                                    ; quit game or demo

    lda demoMode                                ; see if this is demo
    beq done                                    ; if not, ignore all other keys, demo quit on any key

quit:
    lda #0                                      ; set lives to zero so this die event quits
    sta lives 
    inc demoMode                                ; turn demo mode if not on, so there's no end-of-level stuff
    lda eventState                              ; and make a death event
    ora #EVENT_DIED
    sta eventState

done:
    rts 
    
.endproc

;-----------------------------------------------------------------------------
.proc inputUI

    loop = currLevel

    lda KBD                                     ; Get the keyboard
    bpl okay                                    ; and ignore no keys
    bit KBDSTRB                                 ; reset the keyboard
    and #$5f                                    ; strip MSB and case bit
    cmp #'M'                                    ; see if it's the music toggle
    bne :+
    lda audioMask
    eor #AUDIO_MUSIC
    sta audioMask
okay:
    lda #0                                      ; no key or M or m returns 0
    rts

:
    cmp #'B'                                    ; b in the UI toggles color/mono
    bne :+
    lda #1
    sta currLevel                               ; in UI so abuse currLevel as a counter
    eor monochrome                              ; toggle mono/color
    sta monochrome
    beq showColor
showMono:
    printXY #7, #(17*8), roTextMono, #4         ; show Mono on screen
    jsr screenSwap::valueSwap                   ; fake swap
    dec currLevel                               ; and do twice so both buffers updated
    bpl showMono
    jmp doneB

showColor:
    printXY #7, #(17*8), roTextColor, #4        ; show Color on in both buffers
    jsr screenSwap::valueSwap
    dec currLevel 
    bpl showColor
doneB:
    lda #0                                      ; if all is well, return with 0 in a
    rts 

:                                               ; non-music/color toggle key
    cmp #$1b                                    ; see if it's esc
    beq exit                                    ; exit if it is
stop:
    lda #1                                      ; non-M, B or ESC (non toggle) returns 1 (start game)
    rts 
exit:
    lda #$ff                                    ; -1 on ESC (quit application)
    rts

.endproc 
