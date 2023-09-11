#include <arch/z80.h>
#include "os7.h"

/**
 * POLLER - Poll and decode controller inputs into data area.
 */

void poller(void)
{
  Z80_registers r;

  AsmCall(POLLER,&r,REGS_ALL,REGS_ALL);
}
