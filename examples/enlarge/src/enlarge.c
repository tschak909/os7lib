/**
 * @brief Enlarge demo on SMO
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see COPYING for details
 */

#include <interrupt.h>
#include <arch/z80.h>
#include <intrinsic.h>
#include <os7.h>
#include <math/math_fix16.h>

#define OFF_THE_LEFT -32

/**
 * @brief mode 1 color palette
 * @verbose defined as static const so it stays in ROM, and is only referenced in this file.
 */
static const unsigned char colors[32]=
  {
    0xB4,
    0x64, // We have to pre-populate colors for enlarged
    0x64, // because activate isn't transferring them.
    0x64,
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
 * @brief pattern to enlarge
 */
const unsigned char generators[36] = // 32 generator bytes, + 4 color bytes
  {
    // Upper left
    0b00000000,
    0b00000011,
    0b00001111,
    0b00011111,
    0b00111111,
    0b00111111,
    0b00111111,
    0b01111111,

    // upper right
    0b00000000,
    0b11000000,
    0b11110000,
    0b11111000,
    0b11111100,
    0b11111100,
    0b11111100,
    0b11111110,

    // lower left
    0b01111111,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01101110,
    0b01000110,
    0b00000000,

    // lower right
    0b11111110,
    0b11111110,
    0b11111110,
    0b11111110,
    0b11111110,
    0b01110110,
    0b01100010,
    0b00000000,

    // colors (mode 1 = 1 for each generator)
    0x60,
    0x60,
    0x60,
    0x60
  };

/**
 * @brief the FRAME object for the normal SMO, made up of 4 generators in 2x2
 */
SMOFrame(4) NormalFrame;
const NormalFrame normal_frame =
  {
    2,         // This frame is 2 tiles in the X direction 
    2,         // This frame is 2 tiles in the Y direction
    {
      0x60,    // X 0 Y 0 uses name 0x60
      0x61,    // X 1 Y 0 uses name 0x61
      0x62,    // X 0 Y 1 uses name 0x62
      0x63,    // X 1 Y 1 uses name 0x63 
    }
  };

/**
 * @brief the GRAPHICS object for the normal SMO
 */
SMOGraphics(4,NormalFrame) NormalGraphics;
const NormalGraphics normal_graphics =
  {
    SEMI_MOBILE,   // Object type, SEMI MOBILE
    0x60,          // start at pattern generator 0x10
    4,             // This is made up of 4 generators
    generators,    // pointer to the generators
    {normal_frame} // pointer to the 1 normal frame object
  };

/**
 * @brief the STATUS object for the normal SMO
 */
SMOStatus normal_status;

/**
 * @brief the SEMI_MOBILE object for normal size
 */
const SMO normal_object = {normal_graphics, normal_status, 0xFFFF}; // old screen not used

/**
 * @brief the FRAME object for the enlarged SMO, made up of 16 generators in 4x4
 */
SMOFrame(16) EnlargedFrame;

/**
 * @note: Notice that enlarge doubles the # of generators, and interleaves them
 *        this makes it much more conducive to sprite generator ordering, but it works
 *        for background pattern tiles used in SEMI MOBILE objects, too.
 */
const EnlargedFrame enlarged_frame =
  {
    4,         // This frame is 4 tiles in the X direction 
    4,         // This frame is 4 tiles in the Y direction
    {
      0x10,    // X 0 Y 0 uses name 0x10
      0x12,    // X 1 Y 0 uses name 0x12
      0x14,    // X 2 Y 0 uses name 0x14
      0x16,    // X 3 Y 0 uses name 0x16 
      0x11,    // X 0 Y 1 uses name 0x11
      0x13,    // X 1 Y 1 uses name 0x13
      0x15,    // X 2 Y 1 uses name 0x15
      0x17,    // X 3 Y 1 uses name 0x17
      0x18,    // X 0 Y 2 uses name 0x18
      0x1A,    // X 1 Y 2 uses name 0x1A
      0x1C,    // X 2 Y 2 uses name 0x1C
      0x1E,    // X 3 Y 2 uses name 0x1E 
      0x19,    // X 0 Y 3 uses name 0x19
      0x1B,    // X 1 Y 3 uses name 0x1B
      0x1D,    // X 2 Y 3 uses name 0x1D
      0x1F,    // X 3 Y 3 uses name 0x1F
    }
  };

/**
 * @brief the GRAPHICS object for the enlarged SMO
 */
SMOGraphics(1,EnlargedFrame) EnlargedGraphics;
const EnlargedGraphics enlarged_graphics =
  {
    SEMI_MOBILE,   // Object type, SEMI MOBILE
    0x10,          // start at pattern generator 0x10
    16,             // This is made up of 16 generators
    0xFFFF,        // pointer to the generators (not needed)
    {enlarged_frame} // pointer to the 1 enlarged frame object
  };

/**
 * @brief the STATUS for enlarged image
 */
SMOStatus enlarged_status;

/**
 * @brief the SEMI_MOBILE object for normal size
 */
const SMO enlarged_object = {enlarged_graphics, enlarged_status, 0xFFFF}; // old screen not used

/**
 * @brief the routine to use during VDP interrupt, update writer and timer manager
 */
static void vdp_nmi(void)
{
  M_PRESERVE_ALL; // preserve registers, so we don't crash
  time_mgr();     // decrement all timers
  VDP_STATUS_BYTE = read_register();
  M_RESTORE_ALL;  // restore registers, so we don't crash
}

/**
 * @brief Plot sign-on message to VDP using ASCII PATTERNs
 */
void signon_msg(void)
{
  const char sign_on[32]="      MODE 1 ENLARGE TEST      ";

  put_vram(PATTERN_NAME_TABLE,0x0000,sign_on,32);
}

void main(void)
{
  normal_status.x = 64;
  normal_status.y = 64;

  enlarged_status.x = 128;
  enlarged_status.y = 128;
  
  DEFER_WRITES = 0;
  init_timer(&tt,&td);                          // Set up timer queue
  add_raster_int(vdp_nmi);                      // attach vdp_nmi() to be called on every VDP interrupt.
  mode_1();                                     // set up VDP mode 1, at this point, display is OFF (blank)
  load_ascii();                                 // put ASCII table in PATTERN GENERATORS
  put_vram(PATTERN_COLOR_TABLE,0,colors,sizeof(colors)); // Place the color palette.
  write_register(0x07,0x04);                    // set border to dark blue.
  signon_msg();                                 // Go ahead and plot sign-on message
  blank(true);

  // Place the normal sized object
  activate(normal_object, false);               // Move the generators for the normal size into VRAM.
  put_obj(normal_object,0);                     // put it on screen

  // Enlarge the normal sized object
  enlarge(PATTERN_GENERATOR_TABLE,              // Transform data in PATTERN GENERATOR TABLE
	  0x60,                                 // transform the ghost now at 0x60
	  0x10,                                 // place it starting at 0x10
	  4);                                   // 4 generators to transform = 16 total generators.

  // Activate the enlarged object
  activate(enlarged_object, true);             // Do not move generators to VDP, as enlarge has done this.
  put_obj(enlarged_object,0);                   // place it on name table.
  
  while(1);
  
}
