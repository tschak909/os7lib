# Example OS7 pointer values

At the beginning of every ColecoVision cartridge, after the cartridge identification bytes (0xAA, 0x55, or reversed if the splash screen is to be skipped), are a number of pointers to areas in cartridge RAM (CRAM) where the OS7 can do its work for various system routines.

LOCAL_SPR_TBL - 
SPRITE_ORDER - Used by WR_SPR_TBL to do software level sprite re-ordering for sprite multiplexing
WORK_BUFFER - Used by the Graphics package for mobile objects

## Berenstain Bears, The

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x703F
| SPRITE_ORDER   | 0x702B
| WORK_BUFFER    | 0x708F
| CONTROLLER_MAP | 0x7000

Uses Mode 1

## Buck Rogers: Planet of Zoom

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7037
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x70B7
| CONTROLLER_MAP | 0x702B

Uses Mode 1
Semi-mobile objects

## Bump 'n Jump

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x70DE
| SPRITE_ORDER   | 0x7136
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x704A

Uses Mode 2, same character set sent to all three sections

## Burgertime

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x710C
| SPRITE_ORDER   | 0x714C
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x7047

Mode 2

## Carnvival

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x71C5
| SPRITE_ORDER   | 0x71ED
| WORK_BUFFER    | 0x71F7
| CONTROLLER_MAP | 0x7162

Mode 1
USES MOBILE OBJECTS FOR TARGETS? VDP Reg 4 being switched between 4 states.
Semi mobile objects for spinning flags
Sprites for birds, gun, a few extra things.

## Congo Bongo

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x72B3
| SPRITE_ORDER   | 0x7293
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x702B

Mode 2, semi-mobile objects for things like waterfall.

## Cosmic Avenger

(this is an interesting one, does this mean it only uses the OS7 controller POLLER?)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x0000
| CONTROLLER_MAP | 0x7000

Mode 1, 16x16 sprites, scrolling done manually, it looks like.

## Choplifter

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7048
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x7038

Mode 2

## Cabbage Patch Kids - Picture Show

(this one skips the splash screen)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7047
| SPRITE_ORDER   | 0x706F
| WORK_BUFFER    | 0x7079
| CONTROLLER_MAP | 0x702C

Uses multi-color mode, sprite multiplexing

## Donkey Kong (24K, 1982, Pascal version)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x70D4
| SPRITE_ORDER   | 0x70C4
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x702B

Mode 2, Pascal functions.

## Donkey Kong (16K, 1983, Assembler version)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7231
| SPRITE_ORDER   | 0x7221
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x7040

Mode 2, Assembler functions. Same data as 24K version ;)

## Donkey Kong Junior

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x72FF
| SPRITE_ORDER   | 0x72EF
| WORK_BUFFER    | 0x702B
| CONTROLLER_MAP | 0x7000

## Dr. Seuss Fix-Up the Mix-Up Puzzler

(Why does this one have a sprite table that falls off the end of RAM?)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7400 (WTF?)
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x7330
| CONTROLLER_MAP | 0x7073

Mode 2
Sprites used for dice and cursor

## Frenzy 

(am guessing this is a pure bitmap game, so no sprite pointers)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x702B

Mode 1, pre-shifted tiles for enemies

## Front Line

(looks like this one only uses the OS7 controller POLLER too)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x0000
| CONTROLLER_MAP | 0x7000

Mode 1, flips pattern name and sprite attr between two pages.

## Gorf

(am guessing this is also purely a tile only game?)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x709B
| CONTROLLER_MAP | 0x7000

mode 1

## Illusions

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x0000
| CONTROLLER_MAP | 0x7000

mode 2, very little use of os7

## Ken Uston's Blackjack and Poker

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7140
| SPRITE_ORDER   | 0x7168
| WORK_BUFFER    | 0x7172
| CONTROLLER_MAP | 0x710A

mode 1

## Lady Bug

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x0000
| CONTROLLER_MAP | 0x7000

mode 2
sprite muxing

## Looping

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x0000
| CONTROLLER_MAP | 0x7006 (why?)

mode 2
background tiles pre-shifted by 4px

## Mouse Trap

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x71D7
| SPRITE_ORDER   | 0x71FB
| WORK_BUFFER    | 0x702B
| CONTROLLER_MAP | 0x7054

mode 1
sprite muxing
changes color tables wholesale via table ptr change in-game

## Mr. Do!

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x70E9
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x72EF
| CONTROLLER_MAP | 0x7086

mode 1
sprite muxing

## Omega Race

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7032
| SPRITE_ORDER   | 0x7072
| WORK_BUFFER    | 0x700C
| CONTROLLER_MAP | 0x7000

mode 1

## Pepper II

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x70DF
| SPRITE_ORDER   | 0x4000 (?!?!)
| WORK_BUFFER    | 0x708F
| CONTROLLER_MAP | 0x7013

mode 2
pattern gen shifts during scrolling

## Roc'n Rope

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7174
| SPRITE_ORDER   | 0x71E4
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x7030

mode 2

## Rocky Super Action Boxing

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x704F
| SPRITE_ORDER   | 0x708F
| WORK_BUFFER    | 0x709F
| CONTROLLER_MAP | 0x702C

mode 2, pre-shifted tiles by 4.

## Slither

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x7243
| CONTROLLER_MAP | 0x7000

mode 2, some interesting nametable use for other things possibly?

## Smurf Paint 'n' Play Workshop

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7047
| SPRITE_ORDER   | 0x7067
| WORK_BUFFER    | 0x706F
| CONTROLLER_MAP | 0x702C

mode 3 multicolor, 16x16 sprites

## Smurf Rescue in Gargamel's Castle

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x702B
| CONTROLLER_MAP | 0x712D

mode 2

## Space Fury

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7037
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x70B7
| CONTROLLER_MAP | 0x702B

mode 1

## Space Panic

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7037
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x70B7
| CONTROLLER_MAP | 0x702B

mode 1

## Star Trek: Strategic Operations Simulator

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7037
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x70B7
| CONTROLLER_MAP | 0x702B

mode 1, semi-mobile objects

## SubRoc

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x70CB
| SPRITE_ORDER   | 0x4000 (again, wtf?)
| WORK_BUFFER    | 0x4000 (?!?)
| CONTROLLER_MAP | 0x7013

mode 1, some vram animation.

## Super Action Baseball

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7141
| SPRITE_ORDER   | 0x717D
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x7030

mode 2

## Tarzan

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x708B
| SPRITE_ORDER   | 0x4000 (???)
| WORK_BUFFER    | 0x7082
| CONTROLLER_MAP | 0x7013

Mode 1

## Time Pilot

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x7287
| CONTROLLER_MAP | 0x7000

Mode 1

## Turbo

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7000
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x71CC
| CONTROLLER_MAP | 0x7010

Mode 1

## Venture

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x72C9
| SPRITE_ORDER   | 0x72F1
| WORK_BUFFER    | 0x72FB
| CONTROLLER_MAP | 0x725A

Mode 1

## Victory

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x0000
| CONTROLLER_MAP | 0x7000

Mode 1

## WarGames

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x704D
| SPRITE_ORDER   | 0x704D
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x702C

Mode 2

## Zaxxon

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x702B
| SPRITE_ORDER   | 0x4000 (I guess not used?)
| WORK_BUFFER    | 0x70AB
| CONTROLLER_MAP | 0x70D3

Mode 2
