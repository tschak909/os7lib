#include <arch/z80.h>
#include "os7.h"

/** 
 * @brief TIME_MGR - Called every NMI to decrement the active timers
 */
void time_mgr(void)
{
  Z80_registers r;

  AsmCall(TIME_MGR,&r,REGS_ALL,REGS_ALL);
}
