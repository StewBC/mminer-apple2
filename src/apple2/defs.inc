;-----------------------------------------------------------------------------
; defs.inc
; Part of manic miner, the zx spectrum game, made for Apple II
;
; Stefan Wessels, 2020
; This is free and unencumbered software released into the public domain.

;-----------------------------------------------------------------------------
HGRPage1                              := $2000
HGRPage2                              := $4000
MLI                                   := $BF00
SPEAKER                               := $C030
PLACEHOLDER                           := $FFFF

;-----------------------------------------------------------------------------
; Cheat Key (binary 0-19 reverse)                 12345
LEVEL_Central_Cavern                  := 0      ; 00000
LEVEL_The_Cold_Room                   := 1      ; 10000
LEVEL_The_Menagerie                   := 2      ; 01000
LEVEL_Abandoned_Uranium_Workings      := 3      ; 11000
LEVEL_Eugenes_Lair                    := 4      ; 00100
LEVEL_Processing_Plant                := 5      ; 10100
LEVEL_The_Vat                         := 6      ; 01100
LEVEL_Miner_Willy_meets_the_Kong      := 7      ; 11100
LEVEL_Wacky_Amoebatrons               := 8      ; 00010
LEVEL_The_Endorian_Forest             := 9      ; 10010
LEVEL_Attack_of_the_Mutant_Telephones := 10     ; 01010
LEVEL_Return_of_the_Alien_Kong_Beast  := 11     ; 11010
LEVEL_Ore_Refinery                    := 12     ; 00110
LEVEL_Skylab_Landing_Bay              := 13     ; 10110
LEVEL_The_Bank                        := 14     ; 01110
LEVEL_The_Sixteenth_Cavern            := 15     ; 11110
LEVEL_The_Warehouse                   := 16     ; 00001
LEVEL_Amoebatrons_Revenge             := 17     ; 10001
LEVEL_Solar_Power_Generator           := 18     ; 01001
LEVEL_The_Final_Barrier               := 19     ; 11001
LEVEL_Game_Over                       := 20

;-----------------------------------------------------------------------------
DATA_BLANK                            := $00
DATA_FLOOR1                           := $10
DATA_FLOOR2                           := $20
DATA_CONVEYOR                         := $30
DATA_WALL                             := $40
DATA_BUSH                             := $50
DATA_ROCK                             := $60
DATA_COLLAPSE                         := $70
DATA_KEY                              := $80
DATA_SWITCH1                          := $90
DATA_SWITCH1_OPEN                     := $A0
DATA_SWITCH2                          := $B0
DATA_SWITCH2_OPEN                     := $C0
DATA_DOOR                             := $D0

;-----------------------------------------------------------------------------
START_LIVES                           := 2
MAX_LIVES                             := 5

PLAY_ROWS                             := 16
PLAY_COLS                             := 32
VISIBLE_COLS                          := 20

TILES_PER_LEVEL                       := 8
TILE_BYTES                            := 16
CONVEYOR_FRAMES                       := 7
KEYS_FRAMES                           := 4

MAX_SPRITES                           := 10
SPRITE_BYTES                          := 64
MAX_SPRITE_IFRAMES                    := 36

AIR_STR_LEN                           := 5
AIR_SPEED                             := 14

DEMO_TIMER_DURATION                   := 2
DEMO_TIMER_INITAL                     := 18

;-----------------------------------------------------------------------------
CLASS_MOVE_Y                          := <bit0Mask
CLASS_FOUR_FRAME                      := <bit1Mask
CLASS_UNUSED                          := <bit2Mask
CLASS_HOLDATEND                       := <bit3Mask
CLASS_EUGENE                          := <bit4Mask
CLASS_KONG                            := <bit5Mask
CLASS_SKYLAB                          := <bit6Mask
CLASS_DOOR                            := <bit7Mask

;-----------------------------------------------------------------------------
CAMERA_MODE_3_ZONE                    := 0
CAMERA_MODE_SCROLL                    := 1

;-----------------------------------------------------------------------------
EVENT_OK                              := 0
EVENT_DIED                            := 1 << 0
EVENT_LEVEL_RESTART                   := 1 << 1
EVENT_NEXT_LEVEL                      := 1 << 2
EVENT_EXIT_GAME                       := 1 << 3
EVENT_CHEAT_JUMP                      := 1 << 4

;-----------------------------------------------------------------------------
UI_COMPONENT_NAME                     := 1 << 0
UI_COMPONENT_AIR_NAME                 := 1 << 1
UI_COMPONENT_AIR                      := 1 << 2
UI_COMPONENT_SCORE_NAME               := 1 << 3
UI_COMPONENT_SCORE                    := 1 << 4
UI_COMPONENT_LIVES                    := 1 << 5
UI_COMPONENT_HIGHSCORE                := 1 << 6

;-----------------------------------------------------------------------------
MASK_RIGHT                            := 1 << 0 ; bit0Mask
MASK_LEFT                             := 1 << 1 ; bit1Mask
MASK_AIR                              := 1 << 2 ; bit2Mask

;-----------------------------------------------------------------------------
AUDIO_MUSIC                           := $80
AUDIO_SOUND                           := $40
