/**
 * @brief Simple tool to generate a rest of up to 31 frames.
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define REQUIRED_ARGC 2

typedef struct _note_type_rest
{
  unsigned char duration : 5;
  bool rest : 1;
  unsigned char channel : 2;
} NoteTypeRest;

NoteTypeRest rest;

int main(int argc, char* argv[])
{
  unsigned char *rp=NULL; // pointer to the rest struct as a byte.
  
  if (argc < REQUIRED_ARGC) // display message if not enough params, and exit
    {
      printf("%s <channel-0-to-3> <1-to-31-frames>\n",argv[0]);
      exit(1);
    }

  // Fill out the fields
  rest.rest = true;
  rest.channel = atoi(argv[1]);
  rest.duration = atoi(argv[2]);

  // Set byte sized pointer to the rest struct, so we can get it as a whole byte.
  rp = (unsigned char *)&rest;

  // Print the result
  printf("0x%02x,\n",rp[0]);

  // and exit
  return 0;
}
