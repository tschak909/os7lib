/**
 * @brief Sprite Object demo (VDP Mode 1)
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see COPYING for details
 */

#include <interrupt.h>
#include <arch/z80.h>
#include <intrinsic.h>
#include <os7.h>

/**
 * NOTE: The REFLECT_ commands are specified by the axis of their reflection,
 * So this command may work opposite to what you may think. This is why this
 * example is here.
 */

/**
 * @brief mode 1 color palette
 * @verbose defined as static const so it stays in ROM, and is only referenced in this file.
 */
static const unsigned char colors[32]=
  {
    0xB4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0x64, // 5 for bonus
    0x64,
    0x64,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4
  };

/**
 * @brief The data structures for the timer table, to support one timer
 */
TimerTable tt[2];
TimerData td[2];

/**
 * @brief reflect_horizontal pattern to use
 */
const unsigned char generator[8] =
  {
    0b00010000,
    0b00111000,
    0b01111100,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000
  };

/**
 * @brief Status object for the sprite
 */
SprStatus status;

/**
 * @brief frame to generator and color mapping for the sprite
 */
const SprFrame frame={LIGHT_GREEN,0x00};

/**
 * @brief graphics object mapping generator in rom to pattern table in VRAM
 */
const SprGraphics graphics = {SPRITE,0x00,generator,1,frame};

/**
  * @brief top level object for sprite
  */
const SprObj obj = {graphics,status,0};

/**
 * @brief the routine to use during VDP interrupt, update writer and timer manager
 */
static void vdp_nmi(void)
{
  M_PRESERVE_ALL; // preserve registers, so we don't crash
  time_mgr();     // decrement all timers
  VDP_STATUS_BYTE=read_register();
  M_RESTORE_ALL;  // restore registers, so we don't crash
}

/**
 * @brief Plot sign-on message to VDP using ASCII PATTERNs
 */
void signon_msg(void)
{
  const char sign_on[32]=" MODE 1 REFLECT_HORIZONTAL TEST";

  put_vram(PATTERN_NAME_TABLE,0x0000,sign_on,32);
}

void main(void)
{  
  init_timer(&tt,&td);                          // Set up timer queue
  add_raster_int(vdp_nmi);                      // attach vdp_nmi() to be called on every VDP interrupt.
  mode_1();                                     // set up VDP mode 1, at this point, display is OFF (blank)
  load_ascii();                                 // put ASCII table in PATTERN GENERATORS
  put_vram(PATTERN_COLOR_TABLE,0,colors,sizeof(colors)); // Place the color palette.
  write_register(0x07,0x04);                    // set border to dark blue.
  signon_msg();                                 // Go ahead and plot sign-on message
  blank(true);
  
  activate(obj,false);

  status.x = 0;
  
  while(1)
    {
      SignalNum wait_frame = request_signal(8,false); // timer that waits for eight frames.

      // yes, source and dest can be the same, because the transform happens in the work buffer.
      reflect_horizontal(SPRITE_GENERATOR_TABLE,0,0,1);
      
      put_obj(obj,0);
      
      while (!test_signal(wait_frame)); // wait until end of frame
    }
}
