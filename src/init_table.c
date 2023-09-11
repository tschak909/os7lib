#include <arch/z80.h>
#include "os7.h"

/**
 * INIT_TABLE - Set VRAM table to given address
 *
 * @param table - Table to initialize, see VDPTable in os7.h
 * @param address - Intended address
 */
void init_table(VDPTable table, unsigned short address)
{
  Z80_registers r;

  r.Bytes.A = table;
  r.UWords.HL = address;

  AsmCall(INIT_TABLE,&r,REGS_ALL,REGS_ALL);
}
