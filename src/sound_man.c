#include <arch/z80.h>
#include "os7.h"

/** 
 * @brief SOUND_MAN - Updates sound state each VDP interrupt
 */
void sound_man(void)
{
  Z80_registers r;

  AsmCall(SOUND_MAN,&r,REGS_ALL,REGS_ALL);
}
