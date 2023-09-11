#include <arch/z80.h>
#include "os7.h"

/** 
 * RAND_GEN - Generate new 16-bit pseudo-random number, stuff at RAND_NUM
 */
void rand_gen(void)
{
  Z80_registers r;

  AsmCall(RAND_GEN,&r,REGS_ALL,REGS_ALL);
}
