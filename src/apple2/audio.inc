;-----------------------------------------------------------------------------
; audio.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "CODE"

;-----------------------------------------------------------------------------
.proc audioPlayTitleNote 

    fixedDuration =  srcPtrL
    noteDuration  =  srcPtrH
    freqTimer1    =  dstPtrL
    freqTimer2    =  dstPtrH


    ldy #0                                      ; load the duration
    lda (musicL), y
    beq reset                                   ; on 0, the song is done
    sta noteDuration

    lda audioMask                               ; see if the note should be played or simply delayed
    and #AUDIO_MUSIC
    bne :+                                      ; audio is on, go play
    jsr uiDelay                                 ; waste time as though a note was played
    jmp leave                                   ; and move the audio pointer along

:
    iny                                         ; load the 1st timer
    lda (musicL), y
    sta freqTimer1
    iny                                         ; load the second timer
    lda (musicL), y
    sta freqTimer2

preplay:
    lda #$8A                                    ; repeat minimum this much
    sta fixedDuration
play:
    lda SPEAKER                                 ; toggle the speaker
    dec freqTimer1                              ; timer1 down
    bne :++                                     ; not zero, go to timer 2
    ldy #1                                      ; reset timer 1
    lda (musicL), y
    sta freqTimer1
    ldx #11                                     ; delay about 20 clock cycles
:
    dex 
    bne :-
:
    dec freqTimer2                              ; dec timer 2
    bne :++                                     ; not zero?
    ldy #2                                      ; at zero, reset timer 2
    lda (musicL), y
    sta freqTimer2
    ldx #11                                     ; and waste 20 clock cycles
:
    dex 
    bne :-
:
    dec fixedDuration                           ; dec the fixed repeat count
    bne play                                    ; not zero, do another loop
    dec noteDuration                            ; dec the note delay
    bne preplay                                 ; do more loops of at least fixedDuration

leave:
    clc
    lda musicL                                  ; add 3 to the music pointer
    adc #3
    sta musicL
    bcc :+
    inc musicH
    clc                                         ; leave with carry clear
:
    rts 

reset:
    lda #<titleMusic                            ; played the whole tune
    sta musicL                                  ; reset to start of tune
    lda #>titleMusic
    sta musicH

    sec                                         ; and leave with carry set
    rts 

.endproc 

;-----------------------------------------------------------------------------
.proc audioPlayNote

    delayTime = tmpBot + 0

    lda audioMask                               ; see if the music is on
    and #AUDIO_MUSIC
    bne :+
    rts                                         ; if not, return

:
    lda #$FF                                    ; calculate a delay
    sec                                         ; based on how many tiles were rendered
    sbc tilesRendered                           ; this lets the music sound
    cmp #80                                     ; better, esp. when a level is
    bcc :+                                      ; very sparse (SkyLab for example)
    lsr 
    lsr
    lsr
    lsr 
    tay 
    jsr uiDelay::ySet
:
    ldx musicL                                  ; get the index into the in-game music
    inc musicL                                  ; and advance that index
    lda inGameMusic, x                          ; get the note at the index
    bne :+                                      ; if non-zero it's a valid note
    sta musicL                                  ; reset the index to the start of the song
    beq :-
:
    ldy #$08                                    ; fixed number of iterations

freq:                                           ; external entry point for custom fixed iterations/delay
    sta delayTime                               ; store it in a delay counter
    lda audioMask                               ; see if
    and #AUDIO_SOUND                            ; audio is enabled
    bne loop                                    ; and play or ignore audio accordingly
    rts

loop:
    lda SPEAKER                                 ; toggle the speaker
    ldx delayTime                               ; and load the delay
:
    dex                                         ; count down
    bne :-                                      ; to zero
    dey                                         ; then repeat
    bne loop                                    ; for the fixed iterations

    rts                                         ; and return

.endproc 
