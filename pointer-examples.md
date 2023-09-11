# Example OS7 pointer values

At the beginning of every ColecoVision cartridge, after the cartridge identification bytes (0xAA, 0x55, or reversed if the splash screen is to be skipped), are a number of pointers to areas in cartridge RAM (CRAM) where the OS7 can do its work for various system routines.

(todo, provide explanation of each pointer)

## Berenstain Bears, The

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x703F
| SPRITE_ORDER   | 0x702B
| WORK_BUFFER    | 0x708F
| CONTROLLER_MAP | 0x7000

## Buck Rogers: Planet of Zoom

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7037
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x70B7
| CONTROLLER_MAP | 0x702B

## Bump 'n Jump

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x70DE
| SPRITE_ORDER   | 0x7136
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x704A

## Burgertime

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x710C
| SPRITE_ORDER   | 0x714C
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x7047

## Carnvival

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x71C5
| SPRITE_ORDER   | 0x71ED
| WORK_BUFFER    | 0x71F7
| CONTROLLER_MAP | 0x7162

## Congo Bongo

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x72B3
| SPRITE_ORDER   | 0x7293
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x702B

## Cosmic Avenger

(this is an interesting one, does this mean it only uses the OS7 controller POLLER?)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x0000
| CONTROLLER_MAP | 0x7000

## Choplifter

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7048
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x7038

## Cabbage Patch Kids - Picture Show

(this one skips the splash screen)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7047
| SPRITE_ORDER   | 0x706F
| WORK_BUFFER    | 0x7079
| CONTROLLER_MAP | 0x702C

## Donkey Kong (24K, 1982, Pascal version)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x70D4
| SPRITE_ORDER   | 0x70C4
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x702B

## Donkey Kong (16K, 1983, Assembler version)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7231
| SPRITE_ORDER   | 0x7221
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x7040

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

## Frenzy 

(am guessing this is a pure bitmap game, so no sprite pointers)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x702B

## Front Line

(looks like this one only uses the OS7 controller POLLER too)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x0000
| CONTROLLER_MAP | 0x7000

## Gorf

(am guessing this is also purely a tile only game?)

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x709B
| CONTROLLER_MAP | 0x7000

## Illusions

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x0000
| CONTROLLER_MAP | 0x7000

## Ken Uston's Blackjack and Poker

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7140
| SPRITE_ORDER   | 0x7168
| WORK_BUFFER    | 0x7172
| CONTROLLER_MAP | 0x710A

## Lady Bug

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x0000
| CONTROLLER_MAP | 0x7000

## Looping

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x0000
| CONTROLLER_MAP | 0x7006 (why?)

## Mouse Trap

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x71D7
| SPRITE_ORDER   | 0x71FB
| WORK_BUFFER    | 0x702B
| CONTROLLER_MAP | 0x7054

## Mr. Do!

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x70E9
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x72EF
| CONTROLLER_MAP | 0x7086

## Omega Race

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7032
| SPRITE_ORDER   | 0x7072
| WORK_BUFFER    | 0x700C
| CONTROLLER_MAP | 0x7000

## Pepper II

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x70DF
| SPRITE_ORDER   | 0x4000 (?!?!)
| WORK_BUFFER    | 0x708F
| CONTROLLER_MAP | 0x7013

## Roc'n Rope

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7174
| SPRITE_ORDER   | 0x71E4
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x7030

## Rocky Super Action Boxing

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x704F
| SPRITE_ORDER   | 0x708F
| WORK_BUFFER    | 0x709F
| CONTROLLER_MAP | 0x702C

## Slither

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x7243
| CONTROLLER_MAP | 0x7000

## Smurf Paint 'n' Play Workshop

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7047
| SPRITE_ORDER   | 0x7067
| WORK_BUFFER    | 0x706F
| CONTROLLER_MAP | 0x702C

## Smurf Rescue in Gargamel's Castle

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x702B
| CONTROLLER_MAP | 0x712D

## Space Fury

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7037
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x70B7
| CONTROLLER_MAP | 0x702B

## Space Panic

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7037
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x70B7
| CONTROLLER_MAP | 0x702B

## Star Trek: Strategic Operations Simulator

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7037
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x70B7
| CONTROLLER_MAP | 0x702B

## SubRoc

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x70CB
| SPRITE_ORDER   | 0x4000 (again, wtf?)
| WORK_BUFFER    | 0x4000 (?!?)
| CONTROLLER_MAP | 0x7013

## Super Action Baseball

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7141
| SPRITE_ORDER   | 0x717D
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x7030

## Tarzan

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x708B
| SPRITE_ORDER   | 0x4000 (???)
| WORK_BUFFER    | 0x7082
| CONTROLLER_MAP | 0x7013

## Time Pilot

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x7287
| CONTROLLER_MAP | 0x7000

## Turbo

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x7000
| SPRITE_ORDER   | 0x7000
| WORK_BUFFER    | 0x71CC
| CONTROLLER_MAP | 0x7010

## Venture

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x72C9
| SPRITE_ORDER   | 0x72F1
| WORK_BUFFER    | 0x72FB
| CONTROLLER_MAP | 0x725A

## Victory

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x0000
| SPRITE_ORDER   | 0x0000
| WORK_BUFFER    | 0x0000
| CONTROLLER_MAP | 0x7000

## WarGames

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x704D
| SPRITE_ORDER   | 0x704D
| WORK_BUFFER    | 0x7000
| CONTROLLER_MAP | 0x702C

## Zaxxon

| Pointer        | Address
|---             |---
| LOCAL_SPR_TBL  | 0x702B
| SPRITE_ORDER   | 0x4000 (I guess not used?)
| WORK_BUFFER    | 0x70AB
| CONTROLLER_MAP | 0x70D3






