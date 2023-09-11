#include <arch/z80.h>
#include "os7.h"

/**
 * REFLECT_HORIZONTAL - Flip a pattern horizontally
 *
 * @param table The table to operate on (see VDPTable typedef in os7.h)
 * @param source The index to start transformation
 * @param destination The index to place the transformed generators
 * @param count The number of items to transform
 */
void reflect_horizontal(VDPTable table, unsigned short source, unsigned short destination, unsigned short count)
{
  Z80_registers r;

  r.Bytes.A = table;
  r.UWords.DE = source;
  r.UWords.HL = destination;
  r.UWords.BC = count;

  AsmCall(REFLECT_HORIZONTAL,&r,REGS_ALL,REGS_ALL);
}
