#include <arch/z80.h>
#include "os7.h"

/**
 * WRITE_VRAM - Write # of bytes to VRAM from BUFFER in CRAM
 *
 * @param buffer Source Address
 * @param dest Dest address in VRAM
 * @param count # of bytes
 */
void write_vram(void *buffer, unsigned short dest, unsigned short count)
{
  Z80_registers r;

  r.UWords.BC = count;
  r.UWords.DE = dest;
  r.UWords.HL = buffer;

  AsmCall(WRITE_VRAM,&r,REGS_ALL,REGS_ALL);
}
