/**
 * @brief Complex Object demo (Mode 2)
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see COPYING for details
 */

#ifndef SOUND_DATA_AREA_H
#define SOUND_DATA_AREA_H

unsigned char output0[10], output1[10], output2[10], output3[10];

const unsigned char sound0[] =
  {
    // measure 1, 16th notes, notes are in octave above middle C, at full volume.
    0x40, 0xbe, 0x00, 0x08, // D
    0x40, 0xa9, 0x00, 0x08, // E
    0x40, 0xa0, 0x00, 0x08, // F
    0x40, 0x8e, 0x00, 0x08, // G
    0x40, 0x7f, 0x00, 0x08, // A
    0x40, 0x78, 0x00, 0x08, // Ab

    // measure 2, also 16th notes, a reflection of the previous measure.
    0x40, 0xc9, 0x00, 0x08, // Db
    0x40, 0x78, 0x00, 0x08, // Ab
    0x40, 0x7f, 0x00, 0x08, // A
    0x40, 0x8e, 0x00, 0x08, // G
    0x40, 0xa0, 0x00, 0x08, // F
    0x40, 0xa9, 0x00, 0x08, // E
    0x00, // end of song (so it doesn't go off into the weeds)
  };

const void *soundTable[] = {&sound0,&output0,&sound0,&output1,&sound0,&output2,&sound0,&output3};

#endif /* SOUND_DATA_AREA_H */
