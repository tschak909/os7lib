#include <arch/z80.h>
#include "os7.h"

/** 
 * @brief WRITER - Calls PUTOBJ to do deferred object writes
 */
void writer(void)
{
  Z80_registers r;

  AsmCall(WRITER,&r,REGS_ALL,REGS_ALL);
}
