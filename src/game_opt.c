#include <arch/z80.h>
#include "os7.h"

/**
 * GAME_OPT - Display ROM game options/skill screen.
 */
void game_opt(void)
{
  Z80_registers r;

  AsmCall(GAME_OPT,&r,REGS_ALL,REGS_ALL);
}
