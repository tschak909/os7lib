#include <arch/z80.h>
#include "os7.h"

/** 
 * DECLSN - Decrement least significant nibble at address
 * @param addr - Address with least-significant nibble to decrement
 */
void declsn(unsigned short *addr)
{
  Z80_registers r;

  r.UWords.HL = addr;

  AsmCall(DECLSN,&r,REGS_ALL,REGS_ALL);
}
