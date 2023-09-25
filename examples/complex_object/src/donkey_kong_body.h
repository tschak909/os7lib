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
 *        and frame 2 is generated via REFLECT_VERTICAL, so... this is why the # is off.
 */
const unsigned char donkey_kong_body_generators[312]=
  {

// generator_0x1f                                

  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000011,

// generator_0x20

  0b00000000,
  0b00000000,
  0b00000000,
  0b00000001,
  0b00000011,
  0b00000011,
  0b00000011,
  0b00001111,

// generator_0x21

  0b00001111,
  0b00111111,
  0b01111111,
  0b11111111,
  0b11111001,
  0b11111001,
  0b11111111,
  0b11111111,

// generator_0x22

  0b11110000,
  0b11111100,
  0b11111110,
  0b11111111,
  0b10011111,
  0b10011111,
  0b11111111,
  0b11111111,

// generator_0x23

  0b00000000,
  0b00000000,
  0b00000000,
  0b10000000,
  0b11000000,
  0b11000000,
  0b11000000,
  0b11110000,

// generator_0x24

  0b00000000,
  0b00000000,
  0b00000000,
  0b00000001,
  0b00000001,
  0b00000001,
  0b00000001,
  0b00000001,

// generator_0x25

  0b00011111,
  0b01111111,
  0b11111111,
  0b11111111,
  0b11110111,
  0b11110011,
  0b11111001,
  0b11111100,

// generator_0x26

  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b01001111,

// generator_0x27

  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11110010,

// generator_0x28

  0b11111000,
  0b11111110,
  0b11111111,
  0b11111111,
  0b11101111,
  0b11001111,
  0b10011111,
  0b00111111,

// generator_0x29

  0b00000000,
  0b00000000,
  0b00000000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000,

// generator_0x2a

  0b11111111,
  0b01111111,
  0b00111111,
  0b00011111,
  0b00001111,
  0b00011111,
  0b01111111,
  0b01111111,

// generator_0x2b

  0b10000001,
  0b11010001,
  0b11100011,
  0b10010001,
  0b00000001,
  0b11100001,
  0b11111110,
  0b11000000,

// generator_0x2c

  0b10000001,
  0b10001011,
  0b11000111,
  0b10001001,
  0b10000000,
  0b11000111,
  0b01111111,
  0b00000011,

// generator_0x2d

  0b11111111,
  0b11111110,
  0b11111100,
  0b11111000,
  0b11110000,
  0b11111000,
  0b11111110,
  0b11111110,

// generator_0x2e

  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000001,
  0b00000011,

// generator_0x2f

  0b01111111,
  0b01111111,
  0b00111111,
  0b00111111,
  0b00111111,
  0b01111111,
  0b11111111,
  0b11111111,

// generator_0x30

  0b11110000,
  0b11111111,
  0b11110000,
  0b11000000,
  0b11000000,
  0b11000000,
  0b11000000,
  0b00000000,

// generator_0x31

  0b00000111,
  0b11111111,
  0b00001111,
  0b00000011,
  0b00000011,
  0b00000011,
  0b00000011,
  0b00000000,

// generator_0x32

  0b11111110,
  0b11111110,
  0b11111100,
  0b11111100,
  0b11111100,
  0b11111110,
  0b11111111,
  0b11111111,

// generator_0x33

  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b10000000,
  0b11000000,

// generator_0x34

  0b00000001,
  0b00000011,
  0b00000011,
  0b00000111,
  0b00000111,
  0b00001101,
  0b00111111,
  0b01111111,

// generator_0x35

  0b11110000,
  0b11111110,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,

// generator_0x36

  0b00000000,
  0b00000000,
  0b00000000,
  0b11000000,
  0b11111000,
  0b11111111,
  0b11111111,
  0b11011111,

// generator_0x37

  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b10000000,

// generator_0x38

  0b01111111,
  0b11111111,
  0b01111111,
  0b01111111,
  0b00111111,
  0b00111111,
  0b00000011,
  0b00000001,

// generator_0x39

  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,

// generator_0x3a

  0b11001111,
  0b11101111,
  0b11101111,
  0b11101111,
  0b11101111,
  0b11101111,
  0b11001111,
  0b10011111,

// generator_0x3b

  0b11000000,
  0b11000000,
  0b11100000,
  0b11100000,
  0b11110000,
  0b11110000,
  0b11110000,
  0b11111000,

// generator_0x3c

  0b00000001,
  0b00000001,
  0b00000011,
  0b00000011,
  0b00000111,
  0b00000111,
  0b00001111,
  0b00000111,

// generator_0x3d

  0b11111111,
  0b11111110,
  0b11111110,
  0b11111100,
  0b11111000,
  0b11111000,
  0b11110000,
  0b11100100,

// generator_0x3e

  0b00111111,
  0b01111111,
  0b00111111,
  0b00111111,
  0b00111111,
  0b00001111,
  0b00000011,
  0b00000000,

// generator_0x3f

  0b11111100,
  0b11111110,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,

// generator_0x40

  0b00000000,
  0b00000000,
  0b00000000,
  0b10000000,
  0b11000000,
  0b11000000,
  0b11100000,
  0b11110000,

// generator_0x41

  0b00000111,
  0b00011111,
  0b00011111,
  0b00111111,
  0b11111111,
  0b11111110,
  0b01111100,
  0b00111000,

// generator_0x42

  0b11101110,
  0b11001111,
  0b11001111,
  0b10001111,
  0b00001111,
  0b00011111,
  0b01111111,
  0b11111111,

// generator_0x43

  0b11111111,
  0b11100000,
  0b11111000,
  0b11110000,
  0b11110000,
  0b11110000,
  0b11110000,
  0b11000000,

// generator_0x44

  0b00111111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00001111,
  0b00000000,
  0b00000001,
  0b00000011,

// generator_0x45

  0b11111110,
  0b11111000,
  0b11111000,
  0b11110100,
  0b11110000,
  0b00010000,
  0b11111100,
  0b11111000
  };

SMOFrame(24) DonkeyKongBodyFrame;     // Define FRAME object type with space for 24 generators

const DonkeyKongBodyFrame donkeyKongBodyFrame_0 =
  {
    6,                                // frame is 6 generators in X direction
    4,                                // frame is 4 generators in Y direction
    {
      0x1f,0x20,0x21,0x22,0x23,0x1f,  // The generators to use from above.
      0x24,0x25,0x26,0x27,0x28,0x29,
      0x1f,0x2a,0x2b,0x2c,0x2d,0x1f,
      0x2e,0x2f,0x30,0x31,0x32,0x33
    },
  };

const DonkeyKongBodyFrame donkeyKongBodyFrame_1 =
  {
    6,                                // frame is 6 generators in X direction
    4,                                // frame is 4 generators in Y direction
    {
      0x34,0x35,0x36,0x37,0x1f,0x1f,  // The generators to use from above.
      0x38,0x39,0x3A,0x3B,0x1f,0x1f,
      0x3C,0x3D,0x3E,0x3F,0x40,0x1f,
      0x41,0x42,0x43,0x44,0x45,0x1f
    },
  };

const DonkeyKongBodyFrame donkeyKongBodyFrame_2 =
  {
    6,                                // frame is 6 generators in X direction
    4,                                // frame is 4 generators in Y direction
    {
      0x7B,0x7B,0x93,0x92,0x91,0x90,  // These generators don't come from above
      0x7B,0x7B,0x97,0x96,0x95,0x94,  // but are generated by a call to REFLECT_VERTICAL
      0x7B,0x9C,0x9B,0x9A,0x99,0x98,  // see in the main complex_object.c file.
      0x7B,0xA1,0xA0,0x9F,0x9E,0x9D
    },
  };

SMOGraphics(3,DonkeyKongBodyFrame) DonkeyKongBodyGraphics; // Define GRAPHICS object type with space for 3 DonkeyKongBodyFrames
const DonkeyKongBodyGraphics donkeyKongBodyGraphics =
  {
    0xF0,                             // SEMI mobile object, bit 4 = 1 color for each whole tile, bits 5-7 = put in all three M2 pattern generators
    0x1F,                             // This graphics object starts at generator 0x1F
    0x18,                             // NUMGEN = 0x18, 24 generators need to be transferred for this graphics object
    donkey_kong_body_generators,      // Pointer to the generators above
    {
      donkeyKongBodyFrame_0,          // Pointers to the three FRAME objects
      donkeyKongBodyFrame_1,
      donkeyKongBodyFrame_2
    }
  };

SMOStatus donkey_kong_body_status;    // DK body status object

SMO donkey_kong_body_obj =
  {
    donkeyKongBodyGraphics,          // Pointer to the GRAPHICS object
    donkey_kong_body_status,         // Pointer to the STATUS object
    0xFFFF                           // Old Screen not used
  };

#endif /* DONKEY_KONG_BODY_H */
