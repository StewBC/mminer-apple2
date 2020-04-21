;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                                               ;
; LOADER.SYSTEM - an Apple][ ProDOS 8 loader for cc65 programs (Oliver Schmidt) ;
;                                                                               ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

A1L             := $3C
A1H             := $3D
PATHNAME        := $0280
MLI             := $BF00
TXTCLR          := $C050    ; Display graphics
TXTSET          := $C051    ; Display text
MIXCLR          := $C052    ; Disable 4 lines of text
LOWSCR          := $C054    ; Page 1
HISCR           := $C055    ; Page 2
HIRES           := $C057    ; Hires graphics
VERSION         := $FBB3
RDKEY           := $FD0C
PRBYTE          := $FDDA
COUT            := $FDED

QUIT_CALL       = $65
OPEN_CALL       = $C8
READ_CALL       = $CA
CLOSE_CALL      = $CC

FILE_NOT_FOUND_ERR = $46

; ------------------------------------------------------------------------

        .data

OPEN_PARAM:
                .byte   $03             ;PARAM_COUNT
                .addr   PATHNAME        ;PATHNAME
                .addr   $4000 - $0400   ;IO_BUFFER
OPEN_REF:       .byte   $00             ;REF_NUM

READ_PARAM:
                .byte   $04             ;PARAM_COUNT
READ_REF:       .byte   $00             ;REF_NUM
                .addr   $4000           ;DATA_BUFFER
                .word   $FFFF           ;REQUEST_COUNT
                .word   $0000           ;TRANS_COUNT

CLOSE_PARAM:
                .byte   $01             ;PARAM_COUNT
CLOSE_REF:      .byte   $00             ;REF_NUM

QUIT_PARAM:
                .byte   $04             ;PARAM_COUNT
                .byte   $00             ;QUIT_TYPE
                .word   $0000           ;RESERVED
                .byte   $00             ;RESERVED
                .word   $0000           ;RESERVED

LOADING:
                .byte   $0D
                .asciiz "Loading "

ELLIPSES:
                .byte   " ...", $0D, $0D, $00

FILE_NOT_FOUND:
                .asciiz "... File Not Found"

ERROR_NUMBER:
                .asciiz "... Error $"

PRESS_ANY_KEY:
                .asciiz " - Press Any Key "

; ------------------------------------------------------------------------

        .code

        ; Reset stack
        ldx     #$FF
        txs

        ; Remove ".SYSTEM" from pathname
        lda     PATHNAME
        sec
        sbc     #.strlen(".SYSTEM")
        sta     PATHNAME

        ; Add trailing '\0' to pathname
        tax
        lda     #$00
        sta     PATHNAME+1,x

        ; Provide some user feedback
        lda     #<LOADING
        ldx     #>LOADING
        jsr     PRINT
        lda     #<(PATHNAME+1)
        ldx     #>(PATHNAME+1)
        jsr     PRINT
        lda     #<ELLIPSES
        ldx     #>ELLIPSES
        jsr     PRINT

        jsr     MLI
        .byte   OPEN_CALL
        .word   OPEN_PARAM
        bcc     :+
        jmp     ERROR

        ; Copy file reference number
:       lda     OPEN_REF
        sta     READ_REF
        sta     CLOSE_REF

        ; Turn off 80-column firmware
        lda     VERSION
        cmp     #$06        ; //e ?
        bne     :+
        lda     #$15
        jsr     $C300

        ; Switch to hires page 2
:       bit     TXTCLR
        bit     MIXCLR
        bit     HISCR
        bit     HIRES

        jsr     MLI
        .byte   READ_CALL
        .word   READ_PARAM
        bcs     ERROR

        jsr     MLI
        .byte   CLOSE_CALL
        .word   CLOSE_PARAM
        bcs     ERROR

        ; Go for it ...
        jmp     $6000

PRINT:
        sta     A1L
        stx     A1H
        ldx     VERSION
        ldy     #$00
:       lda     (A1L),y
        beq     :++
        cpx     #$06            ; //e ?
        beq     :+
        cmp     #$60            ; lowercase ?
        bcc     :+
        and     #$5F            ; -> uppercase
:       ora     #$80
        jsr     COUT
        iny
        bne     :--             ; BRA
:       rts

ERROR:
        bit     TXTSET
        bit     LOWSCR
        cmp     #FILE_NOT_FOUND_ERR
        bne     :+
        lda     #<FILE_NOT_FOUND
        ldx     #>FILE_NOT_FOUND
        jsr     PRINT
        beq     :++             ; BRA
:       pha
        lda     #<ERROR_NUMBER
        ldx     #>ERROR_NUMBER
        jsr     PRINT
        pla
        jsr     PRBYTE
:       lda     #<PRESS_ANY_KEY
        ldx     #>PRESS_ANY_KEY
        jsr     PRINT
        jsr     RDKEY
        jsr     MLI
        .byte   QUIT_CALL
        .word   QUIT_PARAM
