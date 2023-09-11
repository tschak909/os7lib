#include <arch/z80.h>
#include "os7.h"

/**
 * @brief DECODER - Scan and return decoded controller output
 * @param controller_no - The controller # (0 or 1)
 * @param segment_no - The segment # to decode (0 = fire/joy/spinner, 1 = keypad)
 * @param buttons - destination pointer for button data
 * @param control - destination pointer for controller/keyboard data
 * @param spinner - destination pointer for spinner data.
 */
void decoder(unsigned char controller_no, unsigned char segment_no, unsigned char *buttons, unsigned char *control, unsigned char *spinner)
{
  Z80_registers r;

  r.Bytes.H = controller_no;
  r.Bytes.L = segment_no;

  AsmCall(DECODER,&r,REGS_ALL,REGS_ALL);

  *buttons = r.Bytes.H;
  *control = r.Bytes.L;
  *spinner = r.Bytes.E;
}
