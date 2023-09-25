/**
 * @brief Complex Object demo (Mode 2)
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see COPYING for details
 */

#ifndef DONKEY_KONG_BODY_H
#define DONKEY_KONG_BODY_H

/**
 * @brief Donkey Kong's body is a 6x4 matrix of 8x8 generators, some tiles used more than once
 *        numgen = 20, so 20x3 of these generators ((20x3)*8 = 480 bytes) are grabbed by ACTIVATE 
 */
const unsigned char donkey_kong_body_generators[480]=
  {
    // frame 0 (FACING FRONT)
    // 0x1F
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000011,

    

  };

#endif /* DONKEY_KONG_BODY_H */
