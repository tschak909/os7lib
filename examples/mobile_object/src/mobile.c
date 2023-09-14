/**
 * @brief Mobile Object demo (VDP Mode 1)
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see COPYING for details
 */

#include <interrupt.h>
#include <arch/z80.h>
#include <intrinsic.h>
#include <os7.h> 
#include "generators.h" // pac-man's data is here.

/**
 * @brief The data structures for the timer table, to support one timer
 */
TimerTable tt[2];
TimerData td[2];

/**
 * @brief the size of writer queue is queue size / 3, as there are three bytes per entry
 */
#define WRITER_QUEUE_SIZE 16

/**
 * @brief The queue needed to hold 16 deferred VDP write entries
 */
unsigned char writer_queue[WRITER_QUEUE_SIZE*WRITER_QUEUE_ENTRY_SIZE];

/**
 * @brief PATTERN TABLE generators which will hold each frame, and color
 */
const MOBFrame pacmanFrame0 = {0x60,0x61,0x62,0x63,0x20};
const MOBFrame pacmanFrame1 = {0x64,0x65,0x66,0x67,0x20};
const MOBFrame pacmanFrame2 = {0x68,0x69,0x6A,0x6B,0x20};

/**
 * @brief newGen is 9 generator spaces, each holding 8 bytes for temporary transformation storage.
 */
unsigned char pacmanNewGen[NEWGEN_SIZE];

/**
 * @brief Graphics object which points to bitmaps in ROM, and mappings to frames above
 */
MOBGraphics(3) PacmanGraphics;
const PacmanGraphics pacmanGraphics = {1, 12, pacmanNewGen, pacman_right_horizontal, {pacmanFrame0, pacmanFrame1, pacmanFrame2}};

/**
 * @brief Old Screen object (backing store) for the PAC-MAN object
 */
MOBOldScreen pacmanOldScreen;

/**
 * @brief Pac-man's STATUS object which holds position, frame, etc.
 */
MOBStatus pacmanStatus;

/**
 * @brief PAC-Man's Top-level object
 */
const MOB pacmanMOB = {pacmanGraphics,pacmanStatus,pacmanOldScreen,0x60};

/**
 * @brief the routine to use during VDP interrupt, update writer and timer manager
 */
static void vdp_nmi(void)
{
  M_PRESERVE_ALL; // preserve registers, so we don't crash
  writer();       // fire off pending queue entries
  time_mgr();     // decrement all timers
  M_RESTORE_ALL;  // restore registers, so we don't crash
}

/**
 * @brief Initialize timer, writer, and VDP
 */
void init(void)
{
  init_timer(&tt,&td);                          // Set up timer queue
  init_writer(writer_queue,WRITER_QUEUE_SIZE);  // set up writer queue
  add_raster_int(vdp_nmi);                      // attach vdp_nmi() to be called on every VDP interrupt.

  mode_1();                                     // set up VDP mode 1, at this point, display is OFF (blank)
  load_ascii();                                 // put ASCII table in PATTERN GENERATORS
  fill_vram(MODE1_PATTERN_NAME_TABLE,768,' ');  // spaces in name table
  fill_vram(MODE1_PATTERN_COLOR_TABLE,32,0xF4); // Fill color table with white foreground/black background
  write_register(0x01,0xE0);                    // turn on display, mode 1, VDP interrupt.
}

/**
 * @brief Plot sign-on message to VDP using ASCII PATTERNs
 */
void signon_msg(void)
{
  const char sign_on[32]="  MODE 1 MOBILE PATTERN TEST   ";

  put_vram(PATTERN_NAME_TABLE,0x0000,sign_on,32);
}

/**
 * @brief Program starts here
 */
void main(void)
{
  init();
  signon_msg();

  activate(pacmanMOB,false);
  pacmanStatus.x = 0;
  pacmanStatus.y = 0;
  put_obj(pacmanMOB);
  while(1);
}
