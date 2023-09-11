#include <arch/z80.h>
#include "os7.h"

/**
 * WR_SPR_NM_TBL - write COUNT entries from local sprite attribute table
 *
 * @param COUNT - # of sprite entries from local table to write
 */
void wr_spr_nm_tbl(unsigned char count)
{
  Z80_registers r;

  r.Bytes.A = count;

  AsmCall(WR_SPR_NM_TBL,&r,REGS_ALL,REGS_ALL);
}
