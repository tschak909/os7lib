#include <stdbool.h>
#include "os7.h"

#define BLANK_ON 0xE0
#define BLANK_OFF 0xC0

/**
 * @brief turn on or off screen rendering
 * @param onOff - true = turn screen on, false = turn screen off (leaving backdrop color)
 */
void blank(bool onOff)
{
  write_register(0x01,(onOff ? BLANK_ON : BLANK_OFF));
}
