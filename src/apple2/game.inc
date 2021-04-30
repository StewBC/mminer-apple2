;-----------------------------------------------------------------------------
; game.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "CODE"

;-----------------------------------------------------------------------------
.proc gameLoop

    jsr gameNewGame                             ; init things that need 1-time game init

nextLevel:
    jsr tilesPrepForLevel                       ; move 8 tiles for this level to tilesInstances

restart:
    jsr gameInitStage                           ; init the stage, incl unpacking the level, tile prep etc

playLoop:
    jsr inputGet                                ; read the keyboard

    lda demoMode                                ; check for demo mode
    beq :+                                      ; if not demo, move willy
    jsr gameDemoTick                            ; demo mode so run demo
    jmp ai                                      ; skip moving willy
:
    jsr willyMove                               ; move the main character based on user input (or conveyor or gravity)
ai:
    jsr gameAI                                  ; run all the monster AI

    ldx fullScreenClearCount                    ; get the flag for what level of screen clear is needed
    jsr screenClear                             ; and clear the screen

    jsr tilesAnimateKeys                        ; copy the 16 bytes for the next "key" frame into place
    jsr tilesAnimateConveyor                    ; update the conveyor tile

    jsr screenDrawSprites                       ; draw all the enemies

    lda demoMode                                ; get the event state
    beq :+                                      ; 0 - not demo, full flow
    jsr screenDrawLevel                         ; show all the tiles in demo mode
    jmp ui
:
    lda #$ff                                    ; Enable Collision detection
    jsr screenDrawWilly                         ; not demo - draw willy with collision detection
    bcc level                                   ; carry set is a collision, clear is no problem
    lda eventState                              ; on collision, set the die event
    ora #EVENT_DIED
    sta eventState
level:
    jsr screenDrawLevel                         ; show all the tiles
    lda #0                                      ; No collision detection
    jsr screenDrawWilly                         ; Now draw willy over self and level, no collision
ui:
    lda updateUICount                           ; see if the UI needs an update
    beq :+
    jsr uiUpdate                                ; if needed, update the appropriate UI components

:
    ldx numSprites                              ; The door's index
    jsr screenDrawSprite                        ; render the door over everything else, no collision

    jsr screenSwap                              ; swap to the newly rendered screen
    jsr audioPlayNote                           ; play in-game music if needed
    jsr gameDelay                               ; waste time to get all screens to run at same rate

    lda eventState                              ; see if any events fired
    beq playLoop                                ; keep looping while no events

    jsr gameEvent                               ; process the event, return value in a
    bit bit1Mask                                ; EVENT_LEVEL_RESTART
    bne restart
    bit bit2Mask                                ; EVENT_NEXT_LEVEL
    bne nextLevel


    lda demoMode                                ; no Game Over when the demo ends
    bne :+
    jsr gameOver                                ; wasn't a demo, show Game Over
:
    jsr textCheckHighScore                      ; game over - see if a new high score was set
    rts

.endproc

;-----------------------------------------------------------------------------
.proc gameDelay

    lda #$80                                    ; max tiles ever visible is $CD, but delay only up to $80
    sec 
    sbc tilesRendered                           ; how many were shown
    bcc done                                    
    tax                                         ; delta in x
:
    ldy #49                                     ; delay 246 cycles per non-rendered tile
:
    dey
    bne :-
    dex                                         ; and do it for all tiles not rendered (<$80)
    bne :--
done:
    rts

.endproc 

;-----------------------------------------------------------------------------
.proc gameNewGame

    lda #START_LIVES                            ; init player number of lives
    sta lives

    lda #LEVEL_Central_Cavern                   ; Init these game vars to 0
    sta currLevel

    lda #0                                      ; audioPlayNote uses muiscL as well
    sta musicL                                  ; track progress through in-game song

    ldx #5                                      ; six, zero-based score digits
    lda #'0'                                    ; load a with '0'
:
    sta score, x                                ; set all 6 score digits to '0'
    dex
    bpl :-

    rts

.endproc

;-----------------------------------------------------------------------------
.proc gameInitStage

    count       = tmpBot + 0
    spriteIdx   = tmpBot + 1
    instanceIdx = tmpBot + 2

    ldy currLevel                               ; Skip some stuff for "Game Over" pseudo-level
    cpy #20
    bcs notDemo

    jsr levelUnpack                             ; decompress a level to levelLayout
    jsr levelPlaceKeys                          ; put the keys into the world
    jsr textSetLevelText                        ; create the gfx cache for the name

    ldy currLevel                               ; tables are indexed by level
    lda demoMode                                ; see if this is demo mode
    beq notDemo                                 ; branch if game
    lda willyx                                  ; use willy screen 0 for willyXPos in demo (force leftEdge to 0)
    bne :+

notDemo:
    lda willyx, y                               ; set willy X up
:
    sta willyXPos
    ldx cameraMode
    lda #CAMERA_MODE_SCROLL
    sta cameraMode
    jsr willyMove::positionScreen               ; set the screen position based on willy's X
    stx cameraMode
    lda willyy, y                               ; set willy's Y
    sta willyYPos
    lda willyStartDir, y                        ; and see what facing direction
    sta willyDir
    beq :+                                      ; if right (0) then set that as the animFrame
    lda #4                                      ; if left (1) set the anim frame to 4
:
    sta willyFrame                              ; and save the anim frame

postWilly:
    lda #3                                      ; AI will count down and runs before clearScreen
    sta fullScreenClearCount                    ; so set to 3 to get full clear on both buffers

    lda #AIR_SPEED                              ; set counter for ticking down air
    sta airFlow

    lda #32                                     ; set how many air cols there are
    sta airCols

    lda #$7f                                    ; the air "bar" tip is a character that draws less
    sta airTipGfx                               ; bar over time, till it rolls to the prev column

    lda #$ff                                    ; match all masks
    jsr uiUpdateComponent                       ; so force all UI elements to draw

    lda level_sprites_count, y                  ; get how many enemy sprites the level has
    sta count                                   ; save for init
    sta numSprites                              ; save for the game to use
    dec numSprites                              ; make this count 0 based
    lda level_sprites_offset, y                 ; see where in the sprite tables this sprite starts
    tay                                         ; move the offset into x - sprite tables indexed by this

    ldx #0                                      ; y will be an enemy instance index
    stx eventState                              ; init he event state
    stx livesFrame                              ; but use this 0 to init some variables
    stx movementMask                            ; current movement for willy
    stx conveyorMask                            ; direction conveyor under willy is moving (0=no conveyor under willy)
    stx userKeyMask                             ; keys the user has pressed to move willy
    stx willyJumpCounter                        ; 0 means no jump, 1-18 is in a jump, beyond is a fall height
    stx spriteFramesIdx

    clc                                         ; clear carry - will always enter below with carry clear
next:
    sty spriteIdx                               ; save which sprite is being processed (x clobbered)
    stx instanceIdx                             ; save y, also clobbered

    lda #0
    sta spriteFrame, x                          ; init the sprite specific frame counter to 0

    lda sprites_x, y                            ; load the basic sprite variables and put into zero page
    sta spriteXPos, x                           ; from 0 .. numSprites - 1
    lda sprites_y, y                            ; the addressing is unfortunate - sta ,x is zero-page 2 byte
    sta spriteYPos, x                           ; but it's not worth swapping x and y for this bit of code
    lda sprites_min, y
    sta spriteMin, x
    lda sprites_max, y
    sta spriteMax, x
    lda sprites_speed, y
    sta spriteSpeed, x
    sta spriteTick, x
    lda sprites_dir, y
    sta spriteDir, x
    lda sprites_class, y
    sta spriteClass, x
    lda sprites_colors, y                       ; get the color
    sta spriteColor, x

    lda sprites_bitmaps, y                      ; get the index into the sprite data for this sprite's images
    jsr spriteInstanceSpriteFrames

    ldx instanceIdx                             ; restore y
    cpx numSprites
    beq prep

    lda spriteClass, x
    bit bit1Mask                                ; CLASS_FOUR_FRAME
    beq :+
    lda #4
    bne :++
:
    lda #8
:
    adc spriteFramesIdx, x
    sta spriteFramesIdx + 1, x

    ldy spriteIdx
    iny                                         ; next sprite in sprite table
    inx                                         ; next instance
    dec count
    beq prep
    jmp next

prep:
    ldx currLevel                               ; some levels need special handling
    cpx #LEVEL_Eugenes_Lair                     ; eugene needs colored copies
    bne :+
    jsr spriteEugeneSetup
    jmp fixDoor

:
    cpx #LEVEL_Miner_Willy_meets_the_Kong       ; kong levels need switches
    beq kong
    cpx #LEVEL_Return_of_the_Alien_Kong_Beast
    bne :+
kong:
    lda #DATA_SWITCH1
    sta levelLayout + 6

    lda #DATA_SWITCH2
    sta levelLayout + 18
    jmp fixDoor

:
    cpx #LEVEL_Skylab_Landing_Bay               ; skylab needs satellites to get X values
    bne :+
    ldx #2                                      ; init the falling satellites
skyLabPos:
    lda skylabXPos, x
    sta spriteXPos, x
    txa
    sta spriteTick, x
    dex
    bpl skyLabPos

:
    cpx #LEVEL_The_Final_Barrier
    bne fixDoor
    dec numSprites                              ; hide the victory door sprite

fixDoor:
    jmp spriteDoorSetup                         ; sprites are set up - door is special

.endproc

;-----------------------------------------------------------------------------
.proc gameAI

    lda fullScreenClearCount                    ; get the state
    beq :+                                      ; if it's zero, move on
    dec fullScreenClearCount                    ; count this down
:
    dec airFlow                                 ; deal with the air countdown. airFlow is "time" counter
    bne airDone
    jsr gameAirDecrease

airDone:
    inc livesFrame                              ; move the lives anim frame along
    lda livesFrame                              ; through the first 4 frames only
    cmp #16                                     ; by dividing by 4 (in essence) to get a slower animation
    bcc :+
    lda #0                                      ; start at frame 0 when wrapping
:
    sta livesFrame
    and #3                                      ; only update every 4 frames (not & 3)
    bne :+
    lda #UI_COMPONENT_LIVES                     ; tell ui to update lives
    jsr uiUpdateComponent

:
    ldx numSprites                              ; now set up all the sprites for this level
loop:
    lda spriteClass, x                          ; start with the class
    bit CLASS_DOOR                              ; and if it's a door, treat that separate
    beq :+
    jmp door
:
    bit CLASS_MOVE_Y                            ; see if it moves vertically
    beq horizontal                              ; no - then it moves horizontally
    jmp vertical                                ; yes - them move it vertically

horizontal:
    lda spriteSpeed, x                          ; get speed
    bit bit0Mask                                ; Is the speed 1
    beq rtick                                   ; if not, advance this sprite
    dec spriteTick, x                           ; dec the ticker
    bpl next                                    ; if ge 0 then ignore sprite
    sta spriteTick, x                           ; reset ticker to speed and fall through to run

rtick:
    lda spriteDir, x                            ; get the direction
    bne left                                    ; 1 is left, 0 is right

right:
    inc spriteFrame, x                          ; move the frame
    lda spriteFrame, x                          ; load it
    cmp #4                                      ; see if it's 4
    bcc next                                    ; if 4+, done here
    inc spriteXPos, x                           ; up the x position
    lda spriteXPos, x                           ; load it
    cmp spriteMax, x                            ; see if it's ge max
    bcs rightEnd                                ; if yes, end of going right
    lda #0                                      ; no, reset
    sta spriteFrame, x                          ; frame to 0
    beq next                                    ; BRA. done with this sprite
rightEnd:
    dec spriteXPos, x                           ; set back to last valid x
    lda #1                                      ; load left
    sta spriteDir, x                            ; and set direction left
    lda #7                                      ; 7 is most right position of sprite
    sta spriteFrame, x                          ; and set the frame to that

fix4:
    lda spriteClass, x                          ; get the class
    bit CLASS_FOUR_FRAME                        ; see if it has the (only) 4 frames flag set
    beq next                                    ; if not, done with this sprite (frame 7 is good)
    lda #3                                      ; drop the 7 to 3
    sta spriteFrame, x                          ; set the frame
    jmp next

left:
    dec spriteFrame, x                          ; move the frame
    lda spriteFrame ,x                          ; load it
    cmp #$ff                                    ; see if it is now lt 0 (3,2,1 -> 0 overflow)
    beq stepLeft                                ; if it is, move the col left
    cmp #3                                      ; if it's 3, (7,6,5,4 -> 3 overflow)
    bne next                                    ; if not, done with this sprite

stepLeft:
    dec spriteXPos, x                           ; move the column left
    lda spriteXPos, x                           ; load it
    cmp spriteMin, x                            ; compare to minimum
    bcc leftEnd                                 ; if less than minimum, too far, past the left edge
    lda #7                                      ; keep going, load 7
    sta spriteFrame ,x                          ; set frame back to 7
    bne fix4                                    ; BRA, and check for a 4-frame sprite

leftEnd:
    inc spriteXPos, x                           ; put the column back to in range
    lda #0                                      ; load 0
    sta spriteDir, x                            ; set as direction (right)
    sta spriteFrame, x                          ; and frame (most left frame)
    beq next                                    ; BRA, done with this sprite

postVMove:
    lda spriteClass, x                          ; after a vertical update check these special cases
    bit CLASS_EUGENE                            ; Eugene
    bne eugene
    bit CLASS_KONG                              ; Kong
    beq :+
    jmp kong
:
    bit CLASS_SKYLAB                            ; skylab
    beq :+
    jmp skylab
:
    inc spriteFrame, x                          ; otherwise go to next frame
    lda spriteFrame, x
    and #3
    sta spriteFrame, x

next:
    dex                                         ; get previous sprite
    bpl goTop                                   ; if ge 0 then still a sprite to process
    rts                                         ; all sprites done - exit

goTop:
    jmp loop

vertical:
    lda spriteDir, x                            ; get direction 1 = UP, 0 = DOWN
    beq down
    bmi postVMove                               ; if the spriteDir is lt $ff, stationary sprite

up:
    lda spriteYPos, x                           ; get the Y position
    sec
    sbc spriteSpeed, x                          ; move up by the speed
    cmp spriteMin, x                            ; see if at top
    bcc upEnd                                   ; overshot top
    sta spriteYPos, x                           ; update Y position
    bcs postVMove                               ; BRA

upEnd:
    lda spriteClass, x                          ; get the class
    bit CLASS_HOLDATEND                         ; should it stop or bounce
    bne stop                                    ; HOLDATEND means stop
    lda #0                                      ; change direction
    sta spriteDir, x                            ; to DOWN (0)
    beq postVMove                               ; BRA

down:
    lda spriteYPos, x                           ; get the Y
    clc
    adc spriteSpeed, x                          ; add the speed
    cmp spriteMax, x                            ; see of at end
    bcs downEnd                                 ; at or past end
    sta spriteYPos, x                           ; still good, update Y position
    bcc postVMove                               ; BRA

downEnd:
    lda spriteClass, x                          ; same as upEnd
    bit CLASS_HOLDATEND
    bne stop
    lda #1                                      ; but mark for moving UP (1)
    sta spriteDir, x
    bne postVMove                               ; BRA maybe down?
stop:
    lda #$ff                                    ; set the direction to -1 (lt 0)
    sta spriteDir, x
    bne postVMove                               ; BRA

door:
    lda keysToCollect                           ; check if all keys have been collected
    bne next                                    ; no - nothing more to do
frameToggle:
    dec spriteTick, x                           ; count down for animation
    bpl next                                    ; gt 0, nothing more
    lda spriteFrame, x                          ; get the frame
    eor #1                                      ; toggle between 1 and 0
    sta spriteFrame, x                          ; update the frame
    lda spriteSpeed, x                          ; get the anim speed
    sta spriteTick, x                           ; save it to the tick
    jmp next

eugene:
    lda keysToCollect                           ; eugene changes behavior when all keys collected
    bne eugeneNormal                            ; not all keys, carry on
    lda #0                                      ; all keys - force eugene down
    sta spriteDir, x
    inc spriteFrame, x                          ; cycle through the 5 colors
    lda spriteFrame, x
    cmp #4
    bcc :+
    lda #0
:
    sta spriteFrame, x                          ; save the new frame
eugeneNormal:
    jmp next

kong:
    lda spriteMax, x                            ; if kong's max is 0 he's still up
    beq frameToggle
    lda spriteDir, x                            ; if he's not up see what his direction is
    bpl kongFall                                ; gt 0, then he's still falling
    cmp #$FE                                    ; $fe he's been erased so done with him
    beq kongDone                                ; $ff he's just reached the bottom
    dec spriteDir, x                            ; turn $ff into $fe
    txa                                         ; put the sprite index into a
    pha                                         ; and save it
    lda spriteFramesIdx, x                      ; get the index to the 1st kong frame
    tax                                         ; put that in x
    inx                                         ; and skip the 2 frames where
    inx                                         ; kong is standing
    ldy #2                                      ; want to clear 2 frames
    jsr spriteClearFrames                       ; and make the falling frames blank
    pla                                         ; get the sprite index
    tax                                         ; and put it back in x
kongDone:
    jmp next
kongFall:
    ldx #3                                      ; digit 3 (100's)
    lda #1                                      ; add 1
    jsr textAddScore                            ; add to score
    lda #UI_COMPONENT_SCORE                     ; show changes
    jsr uiUpdateComponent
    jmp frameToggle

skylab:
    lda spriteDir, x                            ; get the direction of the falling satellite
    cmp #$ff                                    ; see if it's reached its end
    beq :+                                      ; yes it has
    jmp next
:
    inc spriteFrame, x                          ; advance the collapsing frame
    lda spriteFrame, x                          ; load that frame
    cmp #8                                      ; see if it's the last
    bcs :+                                      ; yes
    jmp next
:
    lda spriteTick, x                           ; get the tick (hich is an index in this case)
    clc
    adc #3                                      ; advance by 3 (3 satellites at a time) so next index for this satellite
    cmp #12                                     ; (3*4 is 12) - there are 4 stating locations per satellite
    bcc :+                                      ; not rolled over
    and #3                                      ; reset this satellite to 1st starting location (index)
:
    sta spriteTick, x                           ; save the tick
    tay                                         ; put into Y
    lda skylabXPos, y                           ; get the actual start position, based on y, for this satellite
    sta spriteXPos, x                           ; put that into the satellite
    lda #0                                      ; reset the frame, position and direction all to 0
    sta spriteFrame, x
    sta spriteYPos, x
    sta spriteDir, x
    jmp next

.endproc


;-----------------------------------------------------------------------------
.proc gameDemoTick

    dec demoTimer                               ; timer counts down
    bne :+                                      ; if not yet zero, nothing to do
    lda #DEMO_TIMER_DURATION                    ; reset the timer
    sta demoTimer
    lda #UI_COMPONENT_NAME                      ; mark the level name as needing an update
    jsr uiUpdateComponent
    lda leftEdge                                ; scroll the screen
    clc
    adc demoDirection                           ; based on the scrolling direction
    sta leftEdge
    beq nextDemoLevel                           ; if the edge is 0 then done with level
    cmp #12                                     ; at 12, the level flips scroll direction
    bne :+
    lda #$ff                                    ; at 12, the scroll direction becomes -1
    sta demoDirection
:
    rts

nextDemoLevel:
    lda #DEMO_TIMER_INITAL                      ; set for a longer initial hold at a new level
    sta demoTimer
    lda #1                                      ; set the scroll direction to be right (1)
    sta demoDirection
    lda #0                                      ; set the edge to be the very left
    sta leftEdge
    lda #EVENT_NEXT_LEVEL                       ; fire a new level event
    ora eventState
    sta eventState
    rts

.endproc

;-----------------------------------------------------------------------------
.proc gameEvent

    bit bit0Mask                                ; EVENT_DIED
    beq :+                                      ; if not, must be end of level
    dec lives                                   ; died, so take a life
    bmi died                                    ; all lives lost ends the game
    lda #0
    sta tmpBot
    jsr screenInvertVisibleScreen
    lda #EVENT_LEVEL_RESTART                    ; still alive so restart the level
    rts

:
    bit bit4Mask                                ; EVENT_CHEAT_JUMP
    bne done                                    ; if jumping, just go
    lda currLevel                               ; check the level
    cmp #19                                     ; is this the last level
    bcc :+                                      ; if not, go to screen invert
    lda cheatActive                             ; last level - got here by cheating?
    bne :+                                      ; yes - go screen invert
    lda demoMode                                ; is this demo mode?
    bne :+                                      ; yes - go to screen invert
    jsr gameVictory                             ; played properly through, get the victory
:
    ldx #8                                      ; do an inverse screen effect
:
    stx sizeL
    txa
    and #3
    clc
    adc #1
    sta tmpBot
    jsr screenInvertVisibleScreen
    ldx sizeL
    dex
    bne :-

    lda demoMode                                ; is this demo mode
    bne incLevel                                ; skip the air/score, just go to next level

nextLevel:
    jsr screenSwap::valueSwap                   ; do the air countdown/add score routine now, on front screen

airLoop:
    ldx #5                                      ; digit 5 (1's)
    lda #7                                      ; add 7
    jsr textAddScore                            ; add to score
    ldx #4                                      ; digit 4 (10's)
    lda #1                                      ; add 1 (so add 17 per tick)
    jsr textAddScore                            ; add to score
    jsr gameAirDecrease                         ; run the decrease air
    lda airCols                                 ; get the remaining bar length
    asl                                         ; mult * 4
    asl
    eor #$7f                                    ; and reverse (ignore MSB which is 0) - this is the freq
    ldy #6                                      ; duration for the freq
    jsr audioPlayNote::freq                     ; make a sound of this freq and duration
    jsr uiUpdate                                ; and show the updates
    lda eventState                              ; get the event state
    bit bit0Mask                                ; check for EVENT_DIED
    beq airLoop                                 ; not dead means more air left

    jsr screenSwap::valueSwap                   ; go back to the back screen

incLevel:
    inc currLevel                               ; set the current level to the next
    ldx currLevel
    cpx #20                                     ; see if this is the last level + 1
    bcc done                                    ; if not, all is well
    lda demoMode                                ; check again for demo
    beq :+                                      ; if not, roll over to level 1 and keep playing
died:
    lda #EVENT_DIED                             ; demo also ends with a death event
    rts
:
    ldx #0                                      ; not demo, past last level, start at 1st level again
    stx currLevel

done:
    lda #EVENT_NEXT_LEVEL                       ; return in a the action (next level)
    rts

.endproc

;-----------------------------------------------------------------------------
.proc gameAirDecrease

    lda #AIR_SPEED
    sta airFlow
    lda #UI_COMPONENT_AIR                       ; tick the air down, so update the UI
    jsr uiUpdateComponent
    ldx airCols                                 ; see if it's an odd or even column
    inx                                         ; but the air draws from an odd column so the 1 bit is backwards
    txa
    and #1
    tax                                         ; x 0 is even, x 1 is odd
    lda airTipGfx                               ; see what the tip looks like
    cmp maskGreen, x                            ; if it's all green, time to drop another column
    beq colDec
    lsr                                         ; not all green, so adjust the tip by dropping 2 bits (1 white pixel)
    lsr
    ora maskGreenHi, x                          ; and replace that with a green pixel (appropriate for odd/even column)
    bne airOk

colDec:
    dec airCols                                 ; one less bar
    bpl :+
    lda eventState                              ; out of air causes death
    ora #EVENT_DIED
    sta eventState
    lda #0
    sta airCols                                 ; lock airCols at 0
    lda maskGreen, x                            ; lock to all green for the tip
    bne airOk
:
    lda maskNewTip, x                           ; start a new (mostly white) tip, appropriate for odd/even

airOk:
    sta airTipGfx

    rts

.endproc

;-----------------------------------------------------------------------------
.proc gameOver

    iter  = currLevel                           ; how many times to loop

bootPart:
    ldx #20                                     ; game over level is 20 (0 based)
    stx currLevel
    jsr gameInitStage

    ldx #0                                      ; clear the top part of the screen
    jsr screenClear

    ldx #0                                      ; draw the boot
    jsr screenDrawSprite

    ldx #$60                                    ; start of boot-drop freq
    stx iter

    lda #1                                      ; pretend there's a key so Boot (EUGENE) doesn't animate
    sta keysToCollect                           ; and the "door" doesn't switch to the second frame

    tax                                         ; also draw the pedestal (door)
    jsr screenDrawSprite                        ; draw the boot

    lda #2                                      ; set willy to frame 2
    sta willyFrame

    jsr screenDrawWilly                         ; show willy on the pedestal
    jsr screenSwap                              ; make it all visible
    jsr screenSwap::valueSwap                   ; fake the front as the back
bootLoop:
    jsr gameAI                                  ; run the AI to move the boot down

    dec iter                                    ; raise freq
    dec iter

    lda audioMask                               ; see if the audio will play or skip
    and #AUDIO_SOUND
    beq otherDelay                              ; audio won't delay so "fake" an audio delay

    lda iter                                    ; get the freq
    ldy #$80                                    ; duration for the freq (also slows the boot down)
    jsr audioPlayNote::freq                     ; make a sound of this freq and duration
    jmp :+

otherDelay:
    lda iter
    lsr
    lsr
    tay
    jsr uiDelay::ySet
:

    ldx #0                                      ; go draw the boot
    jsr screenDrawSprite

    lda spriteDir                               ; see if the boot has reached the pedestal
    bpl bootLoop                                ; net yet, keep going

gameOverPart:
    color = tmpBot + 1                          ; index into color masks arrays
    xPos  = tmpBot + 2                          ; x for string
    yPos  = tmpBot + 3                          ; y for string
    textL = tmpBot + 4                          ; string pointer
    textH = tmpBot + 5
    len   = tmpBot + 6                          ; how many characters (0 based)

    lda #$20
    sta iter                                    ; how many times to loop
    lda #(7*8)                                  ; Y for string
    sta yPos
    lda #4                                      ; starting color
    sta color
cycleLoop:
    lda #4                                      ; print GAME at x 4
    sta xPos
    lda #<roTextGame                            ; point at GAME text
    sta textL
    lda #>roTextGame
    sta textH
    lda #4                                      ; 0-3 characters
    sta len
    jsr textColorCycle                          ; show the text in color

    lda #13                                     ; print OVER at x 13
    sta xPos
    lda #<roTextOver                            ; point at OVER text
    sta textL
    lda #>roTextOver
    sta textH
    lda #4                                      ; also 0-3 characters in length
    sta len
    jsr textColorCycle                          ; and show over with color

    ldy #$30                                    ; delay the iteration of color
    jsr uiDelay::ySet
    dec iter                                    ; one less iteration to do
    bpl cycleLoop                               ; do all iterations

    rts

.endproc

;-----------------------------------------------------------------------------
.proc gameVictory

    lda #19                                     ; put willy above the door
    sta willyXPos                               ; outside the caverns
    lda #0
    sta willyFrame
    lda #2*8
    sta willyYPos

    ldx fullScreenClearCount                    ; get the flag for what level of screen clear is needed
    jsr screenClear                             ; and clear the screen

    jsr screenDrawSprites                       ; draw all the enemies
    jsr screenDrawWilly                         ; not demo - draw willy with collision detection
    jsr screenDrawLevel                         ; show all the tiles
    ldx numSprites                              ; The door's index
    inx
    jsr screenDrawSprite                        ; render the door over everything else, no collision
    jsr screenSwap                              ; swap to the newly rendered screen

audioPart:
    freq      = tmpBot + 0                      ; freq
    duration  = tmpBot + 1                      ; duration
    iteration = tmpBot + 2                      ; iteration

    lda #50                                     ; 50 iterations
    sta iteration
    lda #0                                      ; init freq and duration
    sta freq
    sta duration

loop:
    lda duration                                ; start with the duration
    adc iteration                               ; add the iteration counter * 3
    adc iteration
    adc iteration
    sta freq                                    ; save as the freq
    ldy duration                                ; put duration in Y

    lda audioMask                               ; see if the audio will play or skip
    and #AUDIO_SOUND
    bne audioOn                                 ; if on, use the freq "API"
:
    ldx freq                                    ; a bit ridiculous to redo playNote stuff here
:
    dex                                         ; but I want the audio code to all go through the
    bne :-                                      ; same "API" for consistency
    dey
    bne :--
    beq postFreq

audioOn:
    lda freq
    jsr audioPlayNote::freq                     ; make the sound if sound enabled

postFreq:
    dec iteration                               ; dec the iterations
    bne loop                                    ; loop till all iterations done
    rts

.endproc
