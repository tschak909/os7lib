#include <arch/z80.h>
#include "os7.h"

/** 
 * @brief INIT_WRITER - Initializes deferred write queue
 * @param size # of entries in queue, should equal desired queue size / 3
 * @param location The location of queue in memory
 */
void init_writer(void *location, unsigned char size)
{
  Z80_registers r;

  r.Bytes.A   = size;
  r.UWords.HL = location;

  AsmCall(INIT_WRITER,&r,REGS_ALL,REGS_ALL);
}
