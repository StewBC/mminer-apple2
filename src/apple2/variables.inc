;-----------------------------------------------------------------------------
; variables.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
.segment "ZEROPAGE"

;-----------------------------------------------------------------------------
currPageH:            .res 1                            ; $02 or $04 - Hi for screen buffer to draw t0
backPage:             .res 1                            ; 0 or 1 - just used to toggle HISCR or LOSCR
monochrome:           .res 1                            ; 0 for color, 1 for black and white
leftEdge:             .res 1                            ; distance the screen has scrolled to the right
cameraMode:           .res 1
tilesRendered:        .res 1                            ; count the number of tiles shown in a screen.  Used to time music delay

willyXPos:            .res 1                            ; column for willy
willyYPos:            .res 1                            ; pixel-row for willy
willyYRow:            .res 1                            ; row (YPos / 8) for willy
willyFrame:           .res 1                            ; willy animation frame
willyDir:             .res 1                            ; direction willy is facing
willyJumpCounter:     .res 1                            ; what phase of a jump willy is in
willyFallFromJump:    .res 1                            ; 0 or 1. 1 when willy starts jumping.  Affects falling death

numSprites:           .res 1                            ; how many sprites (excl. willy) to draw in a level (door is last)
spriteXPos:           .res MAX_SPRITES                  ; col position of the sprite
spriteYPos:           .res MAX_SPRITES                  ; pixel row
spriteDir:            .res MAX_SPRITES                  ; facing direction
spriteMin:            .res MAX_SPRITES                  ; min (turn/hold) point for path
spriteMax:            .res MAX_SPRITES                  ; max point for path
spriteSpeed:          .res MAX_SPRITES                  ; speed (frames/pixels) to move the sprite
spriteTick:           .res MAX_SPRITES                  ; counter how often a sprite animates (spritespeed as init)
spriteFramesIdx:      .res MAX_SPRITES                  ; Index into
spriteFrame:          .res MAX_SPRITES                  ; which frame the sprite is on
spriteClass:          .res MAX_SPRITES                  ; see CLASS_* in defs.inc for masks
spriteColor:          .res MAX_SPRITES                  ; index into masks<Left|Right> in rosystem.inc

movementMask:         .res 1                            ; movement that happened in willyMove.  See MASK_* in defs.inc
userKeyMask:          .res 1                            ; user desire to move based on keys pressed.  See MASK_* in defs.inc
conveyorMask:         .res 1                            ; 0, willy not on conveyor, 2 for left, 1 for right

currLevel:            .res 1                            ; level that's active
lives:                .res 1                            ; lives in reserve
airCols:              .res 1                            ; screen columns that have an air bar in them
airTipGfx:            .res 1                            ; the bit pattern for the tip of the air bar
airFlow:              .res 1                            ; the "tick" till a unit of air is decreased
livesFrame:           .res 1                            ; anim frame for the walking willy's at the bottom
keysFrameNum:         .res 1                            ; animation frame for keys in the level (color)
conveyorFrameNum:     .res 1                            ; animation frame for conveyor tile to be active
keysToCollect:        .res 1                            ; number of keys that remain to be collected

eventState:           .res 1                            ; see EVENT_* in defs.inc for bitmask values
updateUICount:        .res 1                            ; updateUI is called when non-zero
uiComponent:          .res 1                            ; See UI_COMPONENT_* in defs.inc for mask values.  What UI to update
fullScreenClearCount: .res 1                            ; 0 - clear only top, non-zero all.  Is counted down by gameAI

musicL:               .res 1                            ; pointer or index for playing music
musicH:               .res 1                            ; hi pointer for playing UI music
audioMask:            .res 1                            ; see AUDIO_* in defs.inc

demoMode:             .res 1                            ; 0 - not a demo, 1 when demo mode active
demoTimer:            .res 1                            ; in demo mode, scroll when counter is 0
demoDirection:        .res 1                            ; direction the demo scroll will move the screen

cheatIndex:           .res 1                            ; count cheat code entry or when active, if 6 is down
cheatActive:          .res 1                            ; non-zero when the cheat was successfully entered

;-----------------------------------------------------------------------------
tempBlock:            .res 13                           ; widely used z-page general memory
srcPtrL               := tempBlock + 0                  ; often a pointer Lo
srcPtrH               := tempBlock + 1                  ; often a pointer Hi
dstPtrL               := tempBlock + 2                  ; often a pointer Lo
dstPtrH               := tempBlock + 3                  ; often a pointer Hi
sizeL                 := tempBlock + 4                  ; sometimes a size used in ptr operations
sizeH                 := tempBlock + 5                  ; sometimes a size used in ptr operations
tmpBot                := tempBlock + 6                  ; start of block of 6 zp values used randomly

;-----------------------------------------------------------------------------
bitMasks:                                               ; constant - used mostly for bit instruction
bit0Mask:             .res 1                            ; 1
bit1Mask:             .res 1                            ; 2
bit2Mask:             .res 1                            ; 4
bit3Mask:             .res 1                            ; 8
bit4Mask:             .res 1                            ; 16
bit5Mask:             .res 1                            ; 32
bit6Mask:             .res 1                            ; 64
bit7Mask:             .res 1                            ; 128

;-----------------------------------------------------------------------------
.segment "LOWMEM"

; These are instance buffers for sprites / tiles.  They are copied into this
; area and then masked for color from where they are rendered
levelLayout:          .res PLAY_COLS * PLAY_ROWS        ; Unpacked level (tile) info - keep 1st for alignment

; Instances for display
spriteInstances:      .res MAX_SPRITE_IFRAMES * SPRITE_BYTES
tilesInstances:       .res TILES_PER_LEVEL * TILE_BYTES ; instances of tiles in use bitmaps
keyAnimTiles:         .res KEYS_FRAMES * TILE_BYTES     ; color instances of key tile
conveyorAnimTiles:    .res CONVEYOR_FRAMES * TILE_BYTES ; instances of conveyor animated tiles

; cache of 8 pixel-rows for 32 double-byte characters. The level name is centered in here, and drawn from here
levelNameGfx0:        .res PLAY_COLS * 2 * 8

;-----------------------------------------------------------------------------
.segment "DATA"

; The scores are updated in these text strings directly
highScore:
.byte "000000"
score:
.byte "000000"

;-----------------------------------------------------------------------------
.segment "HIMEM"