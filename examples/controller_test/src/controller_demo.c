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

static void nmi()
{
  M_PRESERVE_ALL;
  poller();
  VDP_STATUS_BYTE = read_register();
  M_RESTORE_ALL;
}

const char signon[]="OS7 CONTROLLER TEST";
const char up_1[] = "UP";
const char up_0[] = "  ";
const char down_1 = "DOWN";
const char down_0 = "    ";
const char left_1 = "LEFT";
const char left_0 = "    ";
const char right_1 = "RIGHT";
const char right_0 = "     ";
const char fire_left_1 = "LBUT";
const char fire_left_0 = "    ";
const char fire_right_1 = "RBUT";
const char fire_right_0 = "    ";
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

void main(void)
{
  mode_1();
  load_ascii();
  add_raster_int(nmi);
  fill_vram(0x2000,32,0xF4);
  write_register(0x07,0x04);
  put_vram(PATTERN_NAME_TABLE,0x04,signon,sizeof(signon));
  write_register(0x01,0xE0);

  while(1)
    {
      
    }
}
