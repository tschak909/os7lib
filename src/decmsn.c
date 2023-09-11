#include <arch/z80.h>
#include "os7.h"

/** 
 * DECMSN - Decrement most significant nibble at address
 * @param addr - Address with mo st-significant nibble to decrement
 */
void decmsn(unsigned short *addr)
{
  Z80_registers r;

  r.UWords.HL = addr;

  AsmCall(DECMSN,&r,REGS_ALL,REGS_ALL);
}
