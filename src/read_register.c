#include <arch/z80.h>
#include "os7.h"

/**
 * READ_REGISTER - Read VDP Status Register, return in A
 *
 * @return VDP Status Register in A
 */

unsigned char read_register(void)
{
  Z80_registers r;

  AsmCall(READ_REGISTER,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
