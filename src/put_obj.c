#include <arch/z80.h>
#include "os7.h"

/** 
 * PUT_OBJ - writes to VDP ram starting at TABLE_CODE, start index count, and count number of bytes 
 *
 * @param object pointer to object to put_obj.
 */
void put_obj(void *object)
{
  Z80_registers r;
  
  r.UWords.IX = object;

  AsmCall(PUT_OBJ,&r,REGS_ALL,REGS_ALL);
}
