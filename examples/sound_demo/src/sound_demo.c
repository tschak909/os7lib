/**
 * @brief Sound Demo 
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

const char signon[32]="OS7 SOUND DEMONSTRATION";
const char title1[]="INVENTION #4";
const char title2[]="IN D MINOR";
const char title3[]="BY J.S. BACH";
const char title4[]="BWV 775";
const char title5[]="TRANSCRIBED IN 2023 BY";
const char title6[]="THOMAS CHERRYHOMES";

static void nmi()
{
  M_PRESERVE_ALL;
  play_songs();
  sound_man();
  VDP_STATUS_BYTE = read_register();
  M_RESTORE_ALL;
}

void main(void)
{
  mode_1();
  sound_init(4,&soundTable);
  add_raster_int(nmi);
  load_ascii();
  fill_vram(0x2000,32,0xF4);
  write_register(0x07,0x04);
  put_vram(PATTERN_NAME_TABLE,0x04,signon,sizeof(signon));
  put_vram(PATTERN_NAME_TABLE,137,title1,sizeof(title1));
  put_vram(PATTERN_NAME_TABLE,170,title2,sizeof(title2));
  put_vram(PATTERN_NAME_TABLE,297,title3,sizeof(title3));
  put_vram(PATTERN_NAME_TABLE,363,title4,sizeof(title4));
  put_vram(PATTERN_NAME_TABLE,644,title5,sizeof(title5));
  put_vram(PATTERN_NAME_TABLE,678,title6,sizeof(title6));
  write_register(0x01,0xE0);
  play_it(1);
  play_it(2);
  while(1);
}
