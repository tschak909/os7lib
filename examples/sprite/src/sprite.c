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

#define OFF_THE_LEFT -32

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
 * @brief sprite pattern to use
 */
const unsigned char generator[8] =
  {
    0b11101110,
    0b01000100,
    0b11111111,
    0b11111101,
    0b11111101,
    0b11111111,
    0b01000100,
    0b11101110
  };

/**
 * @brief Status object for the sprite
 */
SprStatus status;

/**
 * @brief frame to generator and color mapping for sprite
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
  M_RESTORE_ALL;  // restore registers, so we don't crash
}

/**
 * @brief Plot sign-on message to VDP using ASCII PATTERNs
 */
void signon_msg(void)
{
  const char sign_on[32]="  MODE 1 SPRITE PATTERN TEST   ";

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

  status.x = OFF_THE_LEFT;
  
  while(1)
    {
      SignalNum wait_frame = request_signal(1,false); // timer that waits for one frame.
      
      status.x+=2;

      if (status.x>288)
	status.x=OFF_THE_LEFT;
      
      put_obj(obj,0);
      
      while (!test_signal(wait_frame)); // wait until end of frame
    }
}
