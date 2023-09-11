#include <arch/z80.h>
#include "os7.h"

/**
 * MODE_1 - Set VDP to Graphics I
 * 
 * VDP tables are set to:
 * 
 * Sprite Generator Table  - 0x3800
 * Pattern Color Table     - 0x2000
 * Sprite Attribute Table  - 0x1B00
 * Pattern Name Table      - 0x1800
 * Pattern Generator Table - 0x0000
 */

void mode_1(void)
{
  Z80_registers r;

  AsmCall(MODE_1,&r,REGS_ALL,REGS_ALL);
}
