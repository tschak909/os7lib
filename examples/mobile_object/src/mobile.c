/**
 * @brief Mobile Object demo (VDP Mode 1)
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see COPYING for details
 */

#include <interrupt.h>
#include <arch/z80.h>
#include <intrinsic.h>
#include <os7.h> 
#include "generators.h"

/**
 * @brief mode 1 color palette
 * @verbose defined as static const so it stays in ROM, and is only referenced in this file.
 */
static const unsigned char colors[32]=
  {
    0xB4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0x64, // 5 for bonus
    0x64,
    0x64,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4
  };

/**
 * @brief The data structures for the timer table, to support one timer
 */
TimerTable tt[2];
TimerData td[2];

unsigned char newgen[72];
unsigned char queue[48];
MOBStatus status;
MOBOldScreen oldScreen;

const MOBFrame frame = {0x00,0x01,0x02,0x03,0xB0};
MOBGraphics(1) Graphics;
const Graphics graphics = {MOBILE,4,newgen,pacman_right_horizontal,{frame}};
const MOB mob = {graphics,status,oldScreen,0x10};

static void vdp_nmi(void)
{
  M_PRESERVE_ALL;
  writer();
  time_mgr();
  M_RESTORE_ALL;
}

void main(void)
{
  init_timer(&tt,&td);
  init_writer(queue,16);
  add_raster_int(vdp_nmi);
  mode_1();
  load_ascii();
  game_opt();
  put_vram(PATTERN_COLOR_TABLE,0,colors,sizeof(colors)); // Place the color palette.
  write_register(0x07,0x04);                    // set border to dark blue.
  blank(true);

  activate(mob,false);
  put_obj(mob,0);
  
  while(1);
}
