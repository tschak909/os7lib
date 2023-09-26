/**
 * @brief Complex Object demo (Mode 2)
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see COPYING for details
 */

#ifndef DONKEY_KONG_COMPLEX_OBJECT_H
#define DONKEY_KONG_COMPLEX_OBJECT_H

// These are the FRAME objects, which specify which child frame to use for each child component.

const COMFrame donkey_kong_frame0[2] =
  {
    0x00, // Component 0 uses frame 0 of child object
    0x00, // Component 1 uses frame 0 of child object
  };

const COMFrame donkey_kong_frame1[2] =
  {
    0x01, // Component 0 uses frame 0 of child object
    0x01, // Component 1 uses frame 0 of child object
  };

const COMFrame donkey_kong_frame2[2] =
  {
    0x02, // Component 0 uses frame 0 of child object
    0x02, // Component 1 uses frame 0 of child object
  };

// These are the OFFSET objects, which specify where to place each child component on the metaplane
// RELATIVE to the position requested by PUTOBJ

const COMOffset donkey_kong_offset0[2] =
  {
    {
      10, // frame 0 component 0 rX position
      0   // frame 0 component 0 rY position
    },
    {
      0,  // frame 0 component 1 rX position
      0   // frame 0 component 1 rY position
    }
  };

const COMOffset donkey_kong_offset1[2] =
  {
    {
      0,  // frame 1 component 0 rX position
      0   // frame 1 component 0 rY position
    },
    {
      0,  // frame 1 component 1 rX position
      0   // frame 1 component 1 rY position
    }
  };

const COMOffset donkey_kong_offset2[2] =
  {
    {
      20, // frame 2 component 0 rX position
      0   // frame 2 component 0 rY position
    },
    {
      0,  // frame 2 component 1 rX position
      0   // frame 2 component 1 rY position
    }
  };

COMGraphics(3) DonkeyKongGraphics;
const DonkeyKongGraphics donkey_kong_graphics =
  {
    0x24,  // This is a complex object (4) with two (2) components.
    {
      {
	donkey_kong_frame0,
	donkey_kong_offset0
      },
      {
	donkey_kong_frame1,
	donkey_kong_offset1
      },
      {
	donkey_kong_frame2,
	donkey_kong_offset2
      }
    }
  };

/**
 * @brief the overall status object for Donkey Kong
 */
COMStatus donkey_kong_status;

COMObj(2) DonkeyKongObj;
const DonkeyKongObj donkey_kong_obj =
  {
    donkey_kong_graphics,
    donkey_kong_status,
    {
      donkey_kong_head_obj,
      donkey_kong_body_obj
    }
  };

#endif /* DONKEY_KONG_COMPLEX_OBJECT_H */
