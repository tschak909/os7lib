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
#include "sound_data_area.h"

/**
 * @brief The data structures for the timer table, to support one timer
 */
TimerTable tt[2];
TimerData td[2];

const char signon[32]="OS7 SOUND DEMONSTRATION";

static void nmi()
{
  M_PRESERVE_ALL;
  play_songs();
  sound_man();
  time_mgr();
  VDP_STATUS_BYTE = read_register();
  M_RESTORE_ALL;
}

void main(void)
{
  mode_1();
  sound_init(1,&soundTable);
  init_timer(&tt,&td);
  add_raster_int(nmi);
  load_ascii();
  fill_vram(0x2000,32,0xF4);
  write_register(0x07,0x04);
  put_vram(PATTERN_NAME_TABLE,0x04,signon,sizeof(signon));
  write_register(0x01,0xE0);
  play_it(1);
  while(1);
}
