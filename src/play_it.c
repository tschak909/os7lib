#include <arch/z80.h>
#include "os7.h"

/** 
 * @brief PLAY_IT - Trigger sound no.
 * @param sound_no - The sound to trigger
 */
void play_it(unsigned char sound_no)
{
  Z80_registers r;

  r.Bytes.B = sound_no;

  AsmCall(PLAY_IT,&r,REGS_ALL,REGS_ALL);
}
