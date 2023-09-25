/**
 * @brief Complex Object demo (Mode 2)
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see COPYING for details
 */

#ifndef DONKEY_KONG_HEAD_H
#define DONKEY_KONG_HEAD_H

/**
 * @brief Donkey Kong's face is a 16x16 sprite, 32 bytes per sprite x 3 frames = 96
 */
const unsigned char donkey_kong_head_generators[96]=
  {
    // Frame 0 (facing forward)
    
    // Upper left
    0b00000000,
    0b00000000,
    0b00001100,
    0b10011110,
    0b10011111,
    0b10001101,
    0b10001111,
    0b11111110,
    
    // Lower Left
    0b11111111,
    0b11100000,
    0b11011111,
    0b00111111,
    0b01111111,
    0b00011111,
    0b00000000,
    0b00000000,
    
    // Upper Right
    0b00000000,
    0b00000000,
    0b00110000,
    0b01111001,
    0b11111001,
    0b10110001,
    0b11110001,
    0b01111111,

    // Lower Right
    0b11111111,
    0b00000111,
    0b11111011,
    0b11111100,
    0b11111110,
    0b11111000,
    0b00000000,
    0b00000000,

    // Frame 1, facing left

    // upper left
    0b00000000,
    0b00000000,
    0b00000001,
    0b00000111,
    0b00000111,
    0b00001101,
    0b00111111,
    0b01111111,

    // lower left
    0b01111111,    
    0b11111111,
    0b00000011,
    0b01111101,
    0b00111111,
    0b00111111,
    0b00000011,
    0b00000000,

    // upper right
    0b00000000,
    0b10000000,
    0b11000000,
    0b11100000,
    0b11101110,
    0b11101110,
    0b11101110,
    0b10001110,

    // lower right
    0b10001100,
    0b11111100,
    0b11111100,
    0b11111000,
    0b11100000,
    0b11100000,
    0b10000000,
    0b00000000,

    // Frame 2, facing right
    // upper left
    0b00000000,
    0b00000001,
    0b00000011,
    0b00000111,
    0b01100111,
    0b11100111,
    0b11100111,
    0b11110001,

    // lower left
    0b00110000,
    0b00110001,
    0b00111011,
    0b00011111,
    0b00000011,
    0b00000011,
    0b00000001,
    0b00000000,

    // upper right
    0b00000000,
    0b00000000,
    0b10000000,
    0b11100000,
    0b11100000,
    0b10110000,
    0b11111100,
    0b11111110,

    // lower right
    0b11111111,
    0b11000000,
    0b10111110,
    0b01111100,
    0b11111100,
    0b10000000,
    0b00000000,
    0b00000000    
  };

/**
 * @brief FRAME object for Donkey Kong's head sprite.
 */
const SprFrame donkey_kong_head_frame_table[3] =
  {
    {
      WHITE,      // sprite frame 0 has white foreground
      0,          // sprite starts at 0xB4+0 (0xB4)
    }, 
    {
      WHITE,      // sprite frame 0 has white foreground
      4,          // sprite starts at 0xB4+4 (0xB8)
    },
    {
      WHITE,      // sprite frame 0 has white foreground
      8,          // sprite starts at 0xB4+8 (0xBC)
    }
  };

/**
 * @brief GRAPHICS object for Donkey Kong's head sprite
 */
const SprGraphics donkey_kong_head_graphics =
  {
    SPRITE,                       // Object type is SPRITE
    0xB4,                         // First sprite generator used is 0xB4
    donkey_kong_head_generators,  // ptr to generators in ROM
    20,                           // Number of generators to copy (20?)
    donkey_kong_head_frame_table  // ptr to frame table
  };

/**
 * @brief the status object (note the lack of const, this lives in RAM)
 */
SprStatus donkey_kong_head_status;

/**
 * @brief the Sprite top-level object (to be used by ACTIVATE/PUT_OBJ)
 */
const SprObj donkey_kong_head_obj =
  {
    donkey_kong_head_graphics,    // ptr to GRAPHICS object
    donkey_kong_head_status,      // ptr to STATUS object
    12                            // sprite index (0-31) to use.
  };

#endif /* DONKEY_KONG_HEAD_H */
