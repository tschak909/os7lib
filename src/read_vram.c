#include <arch/z80.h>
#include "os7.h"

/**
 * READ_VRAM - Read # of bytes from VRAM to BUFFER in CRAM
 *
 * @param buffer Target buffer in CRAM
 * @param src Source address to read from in VRAM
 * @param count # of bytes
 */
void read_vram(void *buffer, unsigned short src, unsigned short count)
{
  Z80_registers r;

  r.UWords.BC = count;
  r.UWords.DE = src;
  r.UWords.HL = buffer;

  AsmCall(READ_VRAM,&r,REGS_ALL,REGS_ALL);
}
