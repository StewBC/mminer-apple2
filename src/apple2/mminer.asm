;-----------------------------------------------------------------------------
; mminer.asm
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "CODE"

;-----------------------------------------------------------------------------
.proc main

    jsr mainInit                                ; do some one-time global init
    jsr uiWaitForIntroEnter                     ; color cycle ENTER and wait for key

loop:
    jsr uiTitleScreen                           ; go to the ui
    and #EVENT_EXIT_GAME                        ; see if event to exit game is set
    bne quit
    jsr gameLoop                                ; not quit, so run the gameplay (or demo)
    jmp loop                                    ; go back to the ui

quit:
    jsr MLI                                     ; quit using the prodos mli

    .byte   $65                                 ; ProDOS Quit request
    .addr   * + 2
    .byte   4
    .byte   0
    .word   0000
    .byte   0
    .word   0000

.endproc

;-----------------------------------------------------------------------------
.include "apple2.inc"                           ; cc65 include file for LOWSCR, etc
.include "logo.inc"                             ; loading bitmap, manic miner bouncy text
.include "defs.inc"                             ; globally used defines
.include "variables.inc"                        ; all game variables and buffers
.include "roaudio.inc"                          ; all ro files read only.  This music and sfx
.include "rofont.inc"                           ; ZX Spectrum font
.include "rolevels.inc"                         ; level layout, sprite positions, colors, etc.
.include "rosprites.inc"                        ; sprite definitions
.include "rosystem.inc"                         ; useful tables for mult, color masks, etc.
.include "rotext.inc"                           ; all in-game text (except scores in variables)
.include "rotiles.inc"                          ; all tile (background) definitions
.include "screen.inc"                           ; code to draw, clear, etc. the screen
.include "text.inc"                             ; code to manipulate and show text
.include "input.inc"                            ; keyboard handling
.include "level.inc"                            ; unpack level and put keys in place
.include "sprite.inc"                           ; instance and color sprites, etc.
.include "tiles.inc"                            ; put right tiles in place and color, etc.
.include "ui.inc"                               ; all pre-game screens
.include "audio.inc"                            ; play the music and make tones
.include "willy.inc"                            ; user controlled character logic
.include "game.inc"                             ; game flow, ai, game over, etc.


;-----------------------------------------------------------------------------
.proc mainInit

    lda #0                                      ; init some one-time globals
    sta backPage
    sta leftEdge
    sta cameraMode
    sta uiComponent
    sta cheatActive
    sta cheatIndex
    sta monochrome

    lda #AUDIO_MUSIC | AUDIO_SOUND              ; turn the music and in-game sounds on
    sta audioMask

    lda #>HGRPage1                              ; set the current hidden (back) page to page 1
    sta currPageH                               ; (page 2 was made visible by the loader)

    lda #$80                                    ; make a zero-page bit mask area for checking bits
    ldx #7                                      ; from 1 to 128, set each bit (backwards)
:
    sta bitMasks, x                             ; set the bits in the area called bitMasks
    lsr
    dex
    bpl :-

    rts

.endproc
