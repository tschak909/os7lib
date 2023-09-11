#include <arch/z80.h>
#include "os7.h"

/** 
 * @brief INIT_TIMER - Initializes the timer data areas
 * @param timer_table location of timer table in cartridge memory
 * @param timer_data_block location of timer data block in memory
 */
void init_timer(void *timer_table, void *timer_data_block)
{
  Z80_registers r;

  r.UWords.HL = timer_table;
  r.UWords.DE = timer_data_block;

  AsmCall(INIT_TIMER,&r,REGS_ALL,REGS_ALL);
}
