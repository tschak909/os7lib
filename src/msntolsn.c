#include <arch/z80.h>
#include "os7.h"

/** 
 * MSNTOLSN - Decrement most significant nibble at address
 * @param addr - Address with mo st-significant nibble to decrement
 */
void msntolsn(unsigned short *addr)
{
  Z80_registers r;

  r.UWords.HL = addr;

  AsmCall(MSNTOLSN,&r,REGS_ALL,REGS_ALL);
}
