#include "os7.h"

/**
 * MODE_2 - Set VDP to Graphics II
 * 
 * VDP tables are set to:
 * 
 * Sprite Generator Table  - 0x3800
 * Pattern Color Table     - 0x2000
 * Sprite Attribute Table  - 0x1B00
 * Pattern Name Table      - 0x1800
 * Pattern Generator Table - 0x0000
 */

void mode_2(void)
{
  // First call mode_1 to get 99% of it set up.
  mode_1();

  // Then set the OS7 graphics mode byte.
  // This also silently sets the VDP_MODE_WORD byte in CRAM (see OS7PRIME:pOS PAGE 130)
  // So the OS7 table and object routines can adjust calculations, per mode.
  write_register(0x00,2);
}
