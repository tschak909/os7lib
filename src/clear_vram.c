#include "os7.h"

void clear_vram(void)
{
  fill_vram(0x0000,0x4000,0x00);
}
