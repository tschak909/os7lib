#include <arch/z80.h>
#include "os7.h"

/** 
 * ADD816 - Add 8-bit value to 16-bit value pointed to by address
 * @param a - The number to add to value at addr
 * @param addr - pointer to 16-bit number at address
 */
void add816(unsigned char a, unsigned short *addr)
{
  Z80_registers r;

  r.Bytes.A   = a;
  r.UWords.HL = addr;

  AsmCall(ADD816,&r,REGS_ALL,REGS_ALL);
}
