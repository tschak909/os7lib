#include <arch/z80.h>
#include "os7.h"

/** 
 * ACTIVATE - writes to VDP ram starting at TABLE_CODE, start index count, and count number of bytes 
 *
 * @param object pointer to object to activate.
 * @oaram move if true, move generators to vram.
 */
void activate(void *object, bool move)
{
  Z80_registers r;

  if (move)
    r.Bytes.A = 0;
  else
    r.Flags.C = 1;
  
  r.UWords.HL = object;

  AsmCall(ACTIVATE,&r,REGS_ALL,REGS_ALL);
}
