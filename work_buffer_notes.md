# work-buffer-notes

The WORK_BUFFER, which is defined in the Coleco cartridge area, is a temporary buffer used by the graphics and sound software in OS7 for numerous purposes. Nothing is expected to be permanent here, and the number of bytes used depends on the types of operations being done.

## sprites

PUT_OBJ will use the first four bytes of the WORK BUFFER to stage writes to the SPRITE ATTRIBUTE table, in the same order:

| offset | description
|---     |---
| 0      | Y position
| 1      | X position
| 2      | sprite generator name
| 3      | sprite generator color

