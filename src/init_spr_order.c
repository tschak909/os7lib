#include <arch/z80.h>
#include "os7.h"

/**
 * INIT_SPR_ORDER - Initialize the sprite order table with SPRITE_COUNT entries
 *
 * @param SPRITE_COUNT Number of sprites to initialize table with
 */
void init_spr_order(unsigned char sprite_count)
{
  Z80_registers r;

  r.Bytes.A = sprite_count;

  AsmCall(INIT_SPR_ORDER,&r,REGS_ALL,REGS_ALL);
}
