#include <arch/z80.h>
#include "os7.h"

/**
 * FILL_VRAM - Fill VRAM starting at address with count bytes of value
 *
 * @param address starting VRAM address (0x0000-0x3FFF)
 * @param count number of bytes to write (0x0000-0x4000)
 * @param value Byte to write (0-0xFF) 
 */
unsigned char fill_vram(unsigned short address, unsigned short count, unsigned char value)
{
  Z80_registers r;

  r.UWords.HL = address;
  r.UWords.DE = count;
  r.Bytes.A   = value;
  
  AsmCall(FILL_VRAM,&r,REGS_ALL,REGS_ALL);
}
