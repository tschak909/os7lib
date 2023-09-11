#include <arch/z80.h>
#include "os7.h"

/**
 * LOAD_ASCII - Load ASCII patterns into pattern generator in VDP
 */
void load_ascii(void)
{
  Z80_registers r;

  AsmCall(LOAD_ASCII,&r,REGS_ALL,REGS_ALL);
}
