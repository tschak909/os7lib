#include <arch/z80.h>
#include <stdbool.h>
#include "os7.h"

/** 
 * @brief REQUEST_SIGNAL - Requests a timer to start.
 * @param len Length of timer (0-65535 frames)
 * @param repeat true = reset and decrement when 0
 * @return signal number.
 */
unsigned char request_signal(unsigned short len, bool repeat)
{
  Z80_registers r;

  r.UWords.HL=len;
  r.Bytes.A=repeat;

  AsmCall(REQUEST_SIGNAL,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
