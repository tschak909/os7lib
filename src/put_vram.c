#include <arch/z80.h>
#include "os7.h"

/** 
 * PUT_VRAM - writes to VDP ram starting at TABLE_CODE, start index count, and count number of bytes 
 *
 * @param table_code - Table code (see VDPTable enum type)
 * @param start_index - The starting entry in the given table
 * @param data - The tarput buffer in CRAM
 * @param count - The number of items
 */
void put_vram(VDPTable table, unsigned short start_index, void *data, unsigned short count)
{
  Z80_registers r;

  r.Bytes.A   = table;
  r.UWords.DE = start_index;
  r.UWords.HL = data;
  r.UWords.IY  = count;

  AsmCall(PUT_VRAM,&r,REGS_ALL,REGS_ALL);
}
