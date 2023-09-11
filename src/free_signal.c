#include <arch/z80.h>
#include <stdbool.h>
#include "os7.h"

/**
 * @brief FREE_SIGNAL - Stop timer and remove from tables.
 * @param signal_num  - The signal # to test (0-255)
 */
void free_signal(unsigned char signal_num)
{
  Z80_registers r;

  r.Bytes.A   = signal_num;

  AsmCall(FREE_SIGNAL,&r,REGS_ALL,REGS_ALL);
}
