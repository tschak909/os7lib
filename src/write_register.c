#include <arch/z80.h>
#include "os7.h"

/**
 * WRITE_REGISTER - Write requested VDP register in B with value in C
 * 
 * @param register The regiter # 0-7
 * @param value the value 0-255
 */

void write_register(unsigned char rg, unsigned char v)
{
  Z80_registers r;

  r.Bytes.B = rg;
  r.Bytes.C = v;

  AsmCall(WRITE_REGISTER,&r,REGS_ALL,REGS_ALL);
}
