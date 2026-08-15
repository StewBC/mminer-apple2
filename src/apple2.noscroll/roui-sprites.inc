;-----------------------------------------------------------------------------
; roui-sprites.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2026
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "RODATA"

; Full-width UI-only sprite art retained for the title, lives display, cheat
; boot and Game Over. Gameplay sprites live in rosprites-half.inc.
uiWillySprites:
uiWillySprite00:
.byte $00, $1E, $00, $00                        ; ---------XXXX---------------
.byte $70, $1F, $00, $00                        ; XXX------XXXXX--------------
.byte $7C, $07, $00, $00                        ; XXXXX------XXX--------------
.byte $30, $06, $00, $00                        ; -XX--------XX---------------
.byte $70, $1F, $00, $00                        ; XXX------XXXXX--------------
.byte $70, $07, $00, $00                        ; XXX--------XXX--------------
.byte $40, $01, $00, $00                        ; X------------X--------------
.byte $70, $07, $00, $00                        ; XXX--------XXX--------------
.byte $7C, $1F, $00, $00                        ; XXXXX----XXXXX--------------
.byte $7C, $1F, $00, $00                        ; XXXXX----XXXXX--------------
.byte $3F, $7E, $00, $00                        ; -XXXXXXXXXXXX---------------
.byte $7F, $79, $00, $00                        ; XXXXXXXXXXX--X--------------
.byte $70, $07, $00, $00                        ; XXX--------XXX--------------
.byte $3C, $1E, $00, $00                        ; -XXXX----XXXX---------------
.byte $7C, $1F, $00, $00                        ; XXXXX----XXXXX--------------
.byte $3C, $7E, $00, $00                        ; -XXXX--XXXXXX---------------

uiWillySprite01:
.byte $00, $60, $03, $00                        ; -------XX----------XX-------
.byte $00, $7E, $03, $00                        ; -------XXXXXX------XX-------
.byte $40, $7F, $00, $00                        ; X------XXXXXXX--------------
.byte $00, $66, $00, $00                        ; -------XX--XX---------------
.byte $00, $7E, $03, $00                        ; -------XXXXXX------XX-------
.byte $00, $7E, $00, $00                        ; -------XXXXXX---------------
.byte $00, $18, $00, $00                        ; ---------XX-----------------
.byte $00, $7E, $00, $00                        ; -------XXXXXX---------------
.byte $40, $67, $03, $00                        ; X------XX--XXX-----XX-------
.byte $40, $67, $03, $00                        ; X------XX--XXX-----XX-------
.byte $40, $67, $03, $00                        ; X------XX--XXX-----XX-------
.byte $40, $7F, $03, $00                        ; X------XXXXXXX-----XX-------
.byte $00, $7E, $00, $00                        ; -------XXXXXX---------------
.byte $00, $18, $00, $00                        ; ---------XX-----------------
.byte $00, $18, $00, $00                        ; ---------XX-----------------
.byte $00, $78, $00, $00                        ; -------XXXX-----------------

uiWillySprite02:
.byte $00, $00, $3C, $00                        ; ---------------XXXX---------
.byte $00, $60, $3F, $00                        ; -------XX------XXXXXX-------
.byte $00, $78, $0F, $00                        ; -------XXXX------XXXX-------
.byte $00, $60, $0C, $00                        ; -------XX--------XX---------
.byte $00, $60, $3F, $00                        ; -------XX------XXXXXX-------
.byte $00, $60, $0F, $00                        ; -------XX--------XXXX-------
.byte $00, $00, $03, $00                        ; -------------------XX-------
.byte $00, $60, $0F, $00                        ; -------XX--------XXXX-------
.byte $00, $78, $3F, $00                        ; -------XXXX----XXXXXX-------
.byte $00, $78, $3F, $00                        ; -------XXXX----XXXXXX-------
.byte $00, $7E, $7C, $01                        ; -------XXXXXX-XXXXX--------X
.byte $00, $7E, $73, $01                        ; -------XXXXXX-XXX--XX------X
.byte $00, $60, $0F, $00                        ; -------XX--------XXXX-------
.byte $00, $78, $3C, $00                        ; -------XXXX----XXXX---------
.byte $00, $18, $3F, $00                        ; ---------XX----XXXXXX-------
.byte $00, $78, $7C, $01                        ; -------XXXX---XXXXX--------X

uiWillySprite03:
.byte $00, $00, $40, $07                        ; --------------X----------XXX
.byte $00, $00, $7C, $07                        ; --------------XXXXX------XXX
.byte $00, $00, $7F, $01                        ; --------------XXXXXXX------X
.byte $00, $00, $4C, $01                        ; --------------X--XX--------X
.byte $00, $00, $7C, $07                        ; --------------XXXXX------XXX
.byte $00, $00, $7C, $01                        ; --------------XXXXX--------X
.byte $00, $00, $30, $00                        ; ---------------XX-----------
.byte $00, $00, $7C, $01                        ; --------------XXXXX--------X
.byte $00, $00, $7F, $07                        ; --------------XXXXXXX----XXX
.byte $00, $60, $7F, $1F                        ; -------XX-----XXXXXXX--XXXXX
.byte $00, $78, $7F, $7F                        ; -------XXXX---XXXXXXXXXXXXXX
.byte $00, $78, $7C, $79                        ; -------XXXX---XXXXX--XXXX--X
.byte $00, $00, $7C, $07                        ; --------------XXXXX------XXX
.byte $00, $00, $4F, $67                        ; --------------X--XXXXXX--XXX
.byte $00, $60, $03, $7E                        ; -------XX----------XXXXXXXX-
.byte $00, $60, $0F, $18                        ; -------XX--------XXXX--XX---

uiWillySprite04:
.byte $70, $01, $00, $00                        ; XXX----------X--------------
.byte $70, $1F, $00, $00                        ; XXX------XXXXX--------------
.byte $40, $7F, $00, $00                        ; X------XXXXXXX--------------
.byte $40, $19, $00, $00                        ; X--------XX--X--------------
.byte $70, $1F, $00, $00                        ; XXX------XXXXX--------------
.byte $40, $1F, $00, $00                        ; X--------XXXXX--------------
.byte $00, $06, $00, $00                        ; -----------XX---------------
.byte $40, $1F, $00, $00                        ; X--------XXXXX--------------
.byte $70, $7F, $00, $00                        ; XXX----XXXXXXX--------------
.byte $7C, $7F, $03, $00                        ; XXXXX--XXXXXXX-----XX-------
.byte $7F, $7F, $0F, $00                        ; XXXXXXXXXXXXXX---XXXX-------
.byte $4F, $1F, $0F, $00                        ; X--XXXX--XXXXX---XXXX-------
.byte $70, $1F, $00, $00                        ; XXX------XXXXX--------------
.byte $73, $79, $00, $00                        ; XXX--XXXXXX--X--------------
.byte $3F, $60, $03, $00                        ; -XXXXXXXX----------XX-------
.byte $0C, $78, $03, $00                        ; ---XX--XXXX--------XX-------

uiWillySprite05:
.byte $00, $1E, $00, $00                        ; ---------XXXX---------------
.byte $00, $7E, $03, $00                        ; -------XXXXXX------XX-------
.byte $00, $78, $0F, $00                        ; -------XXXX------XXXX-------
.byte $00, $18, $03, $00                        ; ---------XX--------XX-------
.byte $00, $7E, $03, $00                        ; -------XXXXXX------XX-------
.byte $00, $78, $03, $00                        ; -------XXXX--------XX-------
.byte $00, $60, $00, $00                        ; -------XX-------------------
.byte $00, $78, $03, $00                        ; -------XXXX--------XX-------
.byte $00, $7E, $0F, $00                        ; -------XXXXXX----XXXX-------
.byte $00, $7E, $0F, $00                        ; -------XXXXXX----XXXX-------
.byte $40, $1F, $3F, $00                        ; X--------XXXXX-XXXXXX-------
.byte $40, $67, $3F, $00                        ; X------XX--XXX-XXXXXX-------
.byte $00, $78, $03, $00                        ; -------XXXX--------XX-------
.byte $00, $1E, $0F, $00                        ; ---------XXXX----XXXX-------
.byte $00, $7E, $0C, $00                        ; -------XXXXXX----XX---------
.byte $40, $1F, $0F, $00                        ; X--------XXXXX---XXXX-------

uiWillySprite06:
.byte $00, $60, $03, $00                        ; -------XX----------XX-------
.byte $00, $60, $3F, $00                        ; -------XX------XXXXXX-------
.byte $00, $00, $7F, $01                        ; --------------XXXXXXX------X
.byte $00, $00, $33, $00                        ; ---------------XX--XX-------
.byte $00, $60, $3F, $00                        ; -------XX------XXXXXX-------
.byte $00, $00, $3F, $00                        ; ---------------XXXXXX-------
.byte $00, $00, $0C, $00                        ; -----------------XX---------
.byte $00, $00, $3F, $00                        ; ---------------XXXXXX-------
.byte $00, $60, $7F, $01                        ; -------XX-----XXXXXXX------X
.byte $00, $60, $73, $01                        ; -------XX-----XXX--XX------X
.byte $00, $60, $73, $01                        ; -------XX-----XXX--XX------X
.byte $00, $60, $73, $01                        ; -------XX-----XXX--XX------X
.byte $00, $00, $3F, $00                        ; ---------------XXXXXX-------
.byte $00, $00, $0C, $00                        ; -----------------XX---------
.byte $00, $00, $0C, $00                        ; -----------------XX---------
.byte $00, $00, $0F, $00                        ; -----------------XXXX-------

uiWillySprite07:
.byte $00, $00, $3C, $00                        ; ---------------XXXX---------
.byte $00, $00, $7C, $07                        ; --------------XXXXX------XXX
.byte $00, $00, $70, $1F                        ; --------------XXX------XXXXX
.byte $00, $00, $30, $06                        ; ---------------XX--------XX-
.byte $00, $00, $7C, $07                        ; --------------XXXXX------XXX
.byte $00, $00, $70, $07                        ; --------------XXX--------XXX
.byte $00, $00, $40, $01                        ; --------------X------------X
.byte $00, $00, $70, $07                        ; --------------XXX--------XXX
.byte $00, $00, $7C, $1F                        ; --------------XXXXX----XXXXX
.byte $00, $00, $7C, $1F                        ; --------------XXXXX----XXXXX
.byte $00, $00, $3F, $7E                        ; ---------------XXXXXXXXXXXX-
.byte $00, $00, $4F, $7F                        ; --------------X--XXXXXXXXXXX
.byte $00, $00, $70, $07                        ; --------------XXX--------XXX
.byte $00, $00, $3C, $1E                        ; ---------------XXXX----XXXX-
.byte $00, $00, $7C, $19                        ; --------------XXXXX----XX--X
.byte $00, $00, $3F, $1E                        ; ---------------XXXXXX--XXXX-

;-----------------------------------------------------------------------------
; Double width for direct drawing when cheat mode is active.
uiBootSprite:
.byte $30, $66, $03, $00                        ; -XX----XX--XX------XX-------
.byte $70, $19, $03, $00                        ; XXX------XX--X-----XX-------
.byte $70, $7F, $03, $00                        ; XXX----XXXXXXX-----XX-------
.byte $00, $06, $00, $00                        ; -----------XX---------------
.byte $00, $06, $00, $00                        ; -----------XX---------------
.byte $40, $7F, $00, $00                        ; X------XXXXXXX--------------
.byte $40, $61, $00, $00                        ; X------XX----X--------------
.byte $40, $61, $00, $00                        ; X------XX----X--------------
.byte $40, $61, $00, $00                        ; X------XX----X--------------
.byte $30, $18, $03, $00                        ; -XX------XX--------XX-------
.byte $30, $60, $7C, $01                        ; -XX----XX-----XXXXX--------X
.byte $4C, $07, $0C, $06                        ; X--XX------XXX---XX------XX-
.byte $0C, $18, $03, $18                        ; ---XX----XX--------XX--XX---
.byte $0C, $18, $00, $18                        ; ---XX----XX------------XX---
.byte $0C, $18, $00, $18                        ; ---XX----XX------------XX---
.byte $7F, $7F, $7F, $7F                        ; XXXXXXXXXXXXXXXXXXXXXXXXXXXX

;-----------------------------------------------------------------------------
; The Game Over pedestal, so the end screen can be drawn entirely from
; full-width art.  sprite10Half stays in rosprites-half.inc otherwise
; all sprite indicies shift and I don't want to fix that too, now.
uiPedestalSprite:
.byte $FF, $FF, $FF, $FF                        ; XXXXXXXXXXXXXXXXXXXXXXXXXXXX
.byte $FC, $E1, $C3, $9F                        ; XXXXX--XX----XX----XX--XXXXX
.byte $83, $E6, $B3, $E0                        ; -----XXXX--XX--XX--XXXX-----
.byte $B3, $E6, $B3, $E6                        ; -XX--XXXX--XX--XX--XXXX--XX-
.byte $8C, $E6, $B3, $98                        ; ---XX--XX--XX--XX--XX--XX---
.byte $C0, $E1, $C3, $81                        ; X------XX----XX----XX------X
.byte $B0, $E0, $83, $86                        ; -XX----XX----------XX----XX-
.byte $B0, $E6, $B3, $86                        ; -XX----XX--XX--XX--XX----XX-
.byte $B0, $E6, $B3, $86                        ; -XX----XX--XX--XX--XX----XX-
.byte $B0, $E6, $B3, $86                        ; -XX----XX--XX--XX--XX----XX-
.byte $B0, $E6, $B3, $86                        ; -XX----XX--XX--XX--XX----XX-
.byte $B0, $E6, $B3, $86                        ; -XX----XX--XX--XX--XX----XX-
.byte $B0, $E6, $B3, $86                        ; -XX----XX--XX--XX--XX----XX-
.byte $B0, $E6, $B3, $86                        ; -XX----XX--XX--XX--XX----XX-
.byte $B0, $E6, $B3, $86                        ; -XX----XX--XX--XX--XX----XX-
.byte $B0, $E6, $B3, $86                        ; -XX----XX--XX--XX--XX----XX-
