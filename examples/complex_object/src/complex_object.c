/**
 * @brief Complex Object demo (Mode 2)
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see COPYING for details
 */

#include <os7.h>
#include <interrupt.h>
#include <arch/z80.h>
#include <intrinsic.h>
#include <stdbool.h>
#include "donkey_kong_head.h"
#include "donkey_kong_body.h"
#include "donkey_kong_complex_object.h"

/**
 * @brief The data structures for the timer table, to support one timer
 */
TimerTable tt[2];
TimerData td[2];

unsigned char queue[48];

/**
 * @brief the routine to use during VDP interrupt, update writer and timer manager
 */
static void vdp_nmi(void)
{
  M_PRESERVE_ALL; // preserve registers, so we don't crash
  time_mgr();     // decrement all timers
  writer();
  VDP_STATUS_BYTE = read_register();
  M_RESTORE_ALL;  // restore registers, so we don't crash
}

/**
 * @brief set up VDP MODE II, with 16x16 (size1) sprites
 */
void mode2_with_size1_sprites(bool bOnOff)
{
  mode_1();
  write_register(0x00,2); // SET M2
  write_register(0x01,bOnOff ? 0xE2 : 0x82); // BLANK(bOnOff), 16K, INTERRUPTS
}

void main(void)
{
  mode2_with_size1_sprites(false);              // Set up, but keep screen BLANK
  init_timer(&tt,&td);                          // Set up timer queue
  init_writer(queue,16);
  add_raster_int(vdp_nmi);                      // attach vdp_nmi() to be called on every VDP interrupt.

  fill_vram(0x2000,6144,0x60);

  activate(donkey_kong_obj,false);
  
  reflect_vertical(PATTERN_GENERATOR_TABLE,0x1f,0x7b,39);

  donkey_kong_status.x=0xb8;
  donkey_kong_status.y=0x10;

  mode2_with_size1_sprites(true);
  
  while (1)
    {
      SignalNum wait = request_signal(30,false);
      donkey_kong_status.frame++;

      if (donkey_kong_status.frame>2)
	donkey_kong_status.frame=0;
      
      put_obj(donkey_kong_obj,false);

      while (!test_signal(wait));
    }    
}
