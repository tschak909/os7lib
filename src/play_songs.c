#include <arch/z80.h>
#include "os7.h"

/** 
 * @brief PLAY_SONGS - Updates sound state each VDP interrupt
 */
void play_songs(void)
{
  Z80_registers r;

  AsmCall(PLAY_SONGS,&r,REGS_ALL,REGS_ALL);
}
