/**
 * @brief mode_2 test
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 */

#include <os7.h>

const char section_1[32]="SCREEN SECTION 1";
const char section_2[32]="SCREEN SECTION 2";
const char section_3[32]="SCREEN SECTION 3";

void main(void)
{
  mode_2();
  load_ascii();
  fill_vram(0x2000,6144,0xF4);
  put_vram(PATTERN_NAME_TABLE,0,section_1,sizeof(section_1));
  put_vram(PATTERN_NAME_TABLE,256,section_2,sizeof(section_2));
  put_vram(PATTERN_NAME_TABLE,512,section_3,sizeof(section_3));
  blank(true);
  
  while(1);
}
