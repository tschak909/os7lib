/**
 * @brief Controller Demo
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see COPYING for details
 */

#include <os7.h>
#include <interrupt.h>
#include <arch/z80.h>
#include <intrinsic.h>
#include <stdbool.h>
#include <arch/coleco.h>

// Bits to mask for joystick directions
#define JOYSTICK_UP_BIT 0x01
#define JOYSTICK_RIGHT_BIT 0x02
#define JOYSTICK_DOWN_BIT 0x04
#define JOYSTICK_LEFT_BIT 0x08
#define JOYSTICK_FIRE_BIT 0x40

// VDP positions relative to start of nametable
#define P1_UP_POS 197
#define P1_RIGHT_POS 264
#define P1_DOWN_POS 324
#define P1_LEFT_POS 256
#define P1_LBUT_POS 128
#define P1_RBUT_POS 137
#define P1_KP1_POS 419
#define P1_KP2_POS 422
#define P1_KP3_POS 425
#define P1_KP4_POS 515
#define P1_KP5_POS 518
#define P1_KP6_POS 521
#define P1_KP7_POS 611
#define P1_KP8_POS 614
#define P1_KP9_POS 617
#define P1_KPA_POS 707
#define P1_KP0_POS 710
#define P1_KPP_POS 713
#define P2_UP_POS 216
#define P2_RIGHT_POS 283
#define P2_DOWN_POS 343
#define P2_LEFT_POS 275
#define P2_LBUT_POS 147
#define P2_RBUT_POS 156
#define P2_KP1_POS 429
#define P2_KP2_POS 432
#define P2_KP3_POS 435
#define P2_KP4_POS 534
#define P2_KP5_POS 537
#define P2_KP6_POS 540
#define P2_KP7_POS 630
#define P2_KP8_POS 633
#define P2_KP9_POS 636
#define P2_KPA_POS 726
#define P2_KP0_POS 729
#define P2_KPP_POS 732
#define P1_HEADER_POS 66
#define P2_HEADER_POS 85

const char signon[]="OS7 CONTROLLER TEST";
const char p1_header[]="PLAYER  1";
const char p2_header[]="PLAYER  2";
const char up_1[] = "UP";
const char up_0[] = "  ";
const char down_1 = "DOWN";
const char down_0 = "    ";
const char left_1 = "LEFT";
const char left_0 = "    ";
const char right_1 = "RIGHT";
const char right_0 = "     ";
const char lbut_1 = "LBUT";
const char lbut_0 = "    ";
const char rbut_1 = "RBUT";
const char rbut_0 = "    ";
const char kp_1_1 = "1";
const char kp_1_0 = " ";
const char kp_2_1 = "2";
const char kp_2_0 = " ";
const char kp_3_1 = "3";
const char kp_3_0 = " ";
const char kp_4_1 = "4";
const char kp_4_0 = " ";
const char kp_5_1 = "5";
const char kp_5_0 = " ";
const char kp_6_1 = "6";
const char kp_6_0 = " ";
const char kp_7_1 = "7";
const char kp_7_0 = " ";
const char kp_8_1 = "8";
const char kp_8_0 = " ";
const char kp_9_1 = "9";
const char kp_9_0 = " ";
const char kp_0_1 = "0";
const char kp_0_0 = " ";
const char kp_A_1 = "*";
const char kp_A_0 = " ";
const char kp_P_1 = "#";
const char kp_P_0 = " ";

void show_controllers(void)
{
  ControllerData *c = (ControllerData *)os7_bios_controller; // defined in $Z88DK/include/arch/coleco.h
    
  put_vram(PATTERN_NAME_TABLE,P1_UP_POS,c->player1.joystick & JOYSTICK_UP_BIT ? up_1 : up_0,sizeof(up_1));
  put_vram(PATTERN_NAME_TABLE,P1_RIGHT_POS,c->player1.joystick & JOYSTICK_RIGHT_BIT ? right_1 : right_0,sizeof(right_1));
  put_vram(PATTERN_NAME_TABLE,P1_DOWN_POS,c->player1.joystick & JOYSTICK_DOWN_BIT ? down_1 : down_0,sizeof(down_1));
  put_vram(PATTERN_NAME_TABLE,P1_LEFT_POS,c->player1.joystick & JOYSTICK_LEFT_BIT ? left_1 : left_0,sizeof(left_1));
  put_vram(PATTERN_NAME_TABLE,P1_LBUT_POS,c->player1.left_button & JOYSTICK_FIRE_BIT ? lbut_1 : lbut_0,sizeof(lbut_1));
  put_vram(PATTERN_NAME_TABLE,P1_RBUT_POS,c->player1.right_button & JOYSTICK_FIRE_BIT ? rbut_1 : rbut_0,sizeof(rbut_1));
  put_vram(PATTERN_NAME_TABLE,P1_KP1_POS,c->player1.keyboard == 0x01 ? kp_1_1 : kp_1_0,sizeof(kp_1_1));
  put_vram(PATTERN_NAME_TABLE,P1_KP2_POS,c->player1.keyboard == 0x02 ? kp_2_1 : kp_2_0,sizeof(kp_2_1));
  put_vram(PATTERN_NAME_TABLE,P1_KP3_POS,c->player1.keyboard == 0x03 ? kp_3_1 : kp_3_0,sizeof(kp_3_1));
  put_vram(PATTERN_NAME_TABLE,P1_KP4_POS,c->player1.keyboard == 0x04 ? kp_4_1 : kp_4_0,sizeof(kp_4_1));
  put_vram(PATTERN_NAME_TABLE,P1_KP5_POS,c->player1.keyboard == 0x05 ? kp_5_1 : kp_5_0,sizeof(kp_5_1));
  put_vram(PATTERN_NAME_TABLE,P1_KP6_POS,c->player1.keyboard == 0x06 ? kp_6_1 : kp_6_0,sizeof(kp_6_1));
  put_vram(PATTERN_NAME_TABLE,P1_KP7_POS,c->player1.keyboard == 0x07 ? kp_7_1 : kp_7_0,sizeof(kp_7_1));
  put_vram(PATTERN_NAME_TABLE,P1_KP8_POS,c->player1.keyboard == 0x08 ? kp_8_1 : kp_8_0,sizeof(kp_8_1));
  put_vram(PATTERN_NAME_TABLE,P1_KP9_POS,c->player1.keyboard == 0x09 ? kp_9_1 : kp_9_0,sizeof(kp_9_1));
  put_vram(PATTERN_NAME_TABLE,P1_KP0_POS,c->player1.keyboard == 0x00 ? kp_0_1 : kp_0_0,sizeof(kp_0_1));
  put_vram(PATTERN_NAME_TABLE,P1_KPA_POS,c->player1.keyboard == 0x0a ? kp_A_1 : kp_A_0,sizeof(kp_A_1));
  put_vram(PATTERN_NAME_TABLE,P1_KPP_POS,c->player1.keyboard == 0x0b ? kp_P_1 : kp_P_0,sizeof(kp_P_1));

  put_vram(PATTERN_NAME_TABLE,P2_UP_POS,c->player2.joystick & JOYSTICK_UP_BIT ? up_1 : up_0,sizeof(up_1));
  put_vram(PATTERN_NAME_TABLE,P2_RIGHT_POS,c->player2.joystick & JOYSTICK_RIGHT_BIT ? right_1 : right_0,sizeof(right_1));
  put_vram(PATTERN_NAME_TABLE,P2_DOWN_POS,c->player2.joystick & JOYSTICK_DOWN_BIT ? down_1 : down_0,sizeof(down_1));
  put_vram(PATTERN_NAME_TABLE,P2_LEFT_POS,c->player2.joystick & JOYSTICK_LEFT_BIT ? left_1 : left_0,sizeof(left_1));
  put_vram(PATTERN_NAME_TABLE,P2_LBUT_POS,c->player2.left_button & JOYSTICK_FIRE_BIT ? lbut_1 : lbut_0,sizeof(lbut_1));
  put_vram(PATTERN_NAME_TABLE,P2_RBUT_POS,c->player2.right_button & JOYSTICK_FIRE_BIT ? rbut_1 : rbut_0,sizeof(rbut_1));
  put_vram(PATTERN_NAME_TABLE,P2_KP1_POS,c->player2.keyboard == 0x01 ? kp_1_1 : kp_1_0,sizeof(kp_1_1));
  put_vram(PATTERN_NAME_TABLE,P2_KP2_POS,c->player2.keyboard == 0x02 ? kp_2_1 : kp_2_0,sizeof(kp_2_1));
  put_vram(PATTERN_NAME_TABLE,P2_KP3_POS,c->player2.keyboard == 0x03 ? kp_3_1 : kp_3_0,sizeof(kp_3_1));
  put_vram(PATTERN_NAME_TABLE,P2_KP4_POS,c->player2.keyboard == 0x04 ? kp_4_1 : kp_4_0,sizeof(kp_4_1));
  put_vram(PATTERN_NAME_TABLE,P2_KP5_POS,c->player2.keyboard == 0x05 ? kp_5_1 : kp_5_0,sizeof(kp_5_1));
  put_vram(PATTERN_NAME_TABLE,P2_KP6_POS,c->player2.keyboard == 0x06 ? kp_6_1 : kp_6_0,sizeof(kp_6_1));
  put_vram(PATTERN_NAME_TABLE,P2_KP7_POS,c->player2.keyboard == 0x07 ? kp_7_1 : kp_7_0,sizeof(kp_7_1));
  put_vram(PATTERN_NAME_TABLE,P2_KP8_POS,c->player2.keyboard == 0x08 ? kp_8_1 : kp_8_0,sizeof(kp_8_1));
  put_vram(PATTERN_NAME_TABLE,P2_KP9_POS,c->player2.keyboard == 0x09 ? kp_9_1 : kp_9_0,sizeof(kp_9_1));
  put_vram(PATTERN_NAME_TABLE,P2_KP0_POS,c->player2.keyboard == 0x00 ? kp_0_1 : kp_0_0,sizeof(kp_0_1));
  put_vram(PATTERN_NAME_TABLE,P2_KPA_POS,c->player2.keyboard == 0x0a ? kp_A_1 : kp_A_0,sizeof(kp_A_1));
  put_vram(PATTERN_NAME_TABLE,P2_KPP_POS,c->player2.keyboard == 0x0b ? kp_P_1 : kp_P_0,sizeof(kp_P_1));
}

static void nmi()
{
  M_PRESERVE_ALL;
  poller();
  VDP_STATUS_BYTE = read_register();
  M_RESTORE_ALL;
}

void main(void)
{
  mode_1();
  load_ascii();
  add_raster_int(nmi);
  fill_vram(0x2000,32,0xF4);
  write_register(0x07,0x04);
  put_vram(PATTERN_NAME_TABLE,0x04,signon,sizeof(signon));
  put_vram(PATTERN_NAME_TABLE,P1_HEADER_POS,p1_header,sizeof(p1_header));
  put_vram(PATTERN_NAME_TABLE,P2_HEADER_POS,p2_header,sizeof(p2_header));
  write_register(0x01,0xE0);

  while(1)
    {
      SignalNum frame_wait = request_signal(1,false); // request signal that triggers on next frame.

      show_controllers();
      
      while (test_signal(frame_wait)); // Wait for signal to end
    }
}
