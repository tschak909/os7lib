#include "os7.h"

/**
 * @brief turn on or off screen rendering
 * @param onoff - true = turn screen on, false = turn screen off (leaving backdrop color)
 */
void blank(bool onoff)
{
  write_register(0x01,(onOff ? BLANK_ON : BLANK_OFF));
}
