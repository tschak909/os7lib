#include <arch/z80.h>
#include <stdbool.h>
#include "os7.h"

/**
 * @brief TEST_SIGNAL - Check if timer specified by signal_num has passed.
 * @param signal_num  - The signal # to test (0-255)
 * @return true if timer has passed, false if not.
 */
bool test_signal(unsigned char signal_num)
{
  Z80_registers r;

  r.Bytes.A   = signal_num;

  AsmCall(TEST_SIGNAL,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
