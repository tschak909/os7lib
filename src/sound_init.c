#include <arch/z80.h>
#include "os7.h"

/** 
 * @brief SOUND_INIT - Initialize the sound routines
 * @param sound_data_areas - # of sound data areas to initialize
 * @param list_of_sound_addrs - base address of a list of starting addresses for each sund's note list and data area
 */
void sound_init(unsigned char sound_data_areas, void *list_of_sound_addrs)
{
  Z80_registers r;

  r.Bytes.B = sound_data_areas;
  r.UWords.HL = list_of_sound_addrs;

  AsmCall(SOUND_INIT,&r,REGS_ALL,REGS_ALL);
}
