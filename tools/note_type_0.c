/**
 * @brief Simple tool to generate a type 0 note (fixed duration, fixed attenuation)
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 */

#include <stdlib.h>
#include <stdio.h>

#define REQUIRED_ARGC 4

typedef struct _type0_note_channel
{
  unsigned char channel_reserved : 6;
  unsigned char channel : 2;
} Type0NoteChannel;

typedef struct _type0_note_freq_atn
{
  unsigned short frequency : 10;  
  unsigned char frequency_reserved : 2;
  unsigned char atn : 4;
} Type0NoteFreqAtn;

Type0NoteChannel note_channel;
Type0NoteFreqAtn note_freq_atn;
unsigned char len;

int main(int argc, char* argv[])
{
  unsigned char *fp=NULL, *cp=NULL; // pointers to the bit packed fields
  
  if (argc < REQUIRED_ARGC) // display message if not enough params, and exit
    {
      printf("%s <channel-0-to-3> <freq-in-hz> <atn> <duration-in-frames>\n",argv[0]);
      exit(1);
    }

  // Fill out the fields
  note_channel.channel    = atoi(argv[1]);
  note_freq_atn.frequency = atoi(argv[2]);
  note_freq_atn.atn       = atoi(argv[3]);
  len                     = atoi(argv[4]);

  // Set byte sized pointers to note_channel and note_freq_atn
  // so we can easily output them as bytes in little endian order
  cp = (unsigned char *)&note_channel;
  fp = (unsigned char *)&note_freq_atn;

  // Print the result
  printf("0x%02x, 0x%02x, 0x%02x, 0x%02x,\n",cp[0], fp[0], fp[1], len);

  // and exit
  return 0;
}
