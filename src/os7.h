#ifndef OS7_H
#define OS7_H

#define READ_VRAM 0x1FE2
#define WRITE_VRAM 0x1FDF
#define READ_REGISTER 0x1FDC
#define WRITE_REGISTER 0x1FD9
#define GAME_OPT 0x1F7C
#define LOAD_ASCII 0x1F7F
#define FILL_VRAM 0x1F82
#define MODE_1 0x1F85
#define GET_VRAM 0x1FBB
#define PUT_VRAM 0x1FBE
#define REFLECT_VERTICAL 0x1F6A
#define REFLECT_HORIZONTAL 0x1F6D
#define ROTATE_90 0x1F70
#define ENLARGE 0x1F73
#define INIT_SPR_ORDER 0x1FC1
#define WR_SPR_NM_TBL 0x1FC4
#define POLLER 0x1FEB
#define DECODER 0x1F79

typedef enum _vdp_table
  {
    SPRITE_ATTRIBUTE_TABLE,
    SPRITE_GENERATOR_TABLE,
    PATTERN_NAME_TABLE,
    PATTERN_GENERATOR_TABLE,
    PATTERN_COLOR_TABLE
  } VDPTable;

/**
 * READ_VRAM - Read # of bytes from VRAM to BUFFER in CRAM
 *
 * @param buffer Target buffer in CRAM
 * @param src Source address to read from in VRAM
 * @param count # of bytes
 */
void read_vram(void *buffer, unsigned short src, unsigned short count);

/**
 * WRITE_VRAM - Write # of bytes to VRAM from BUFFER in CRAM
 *
 * @param buffer Source Address
 * @param dest Dest address in VRAM
 * @param count # of bytes
 */
void write_vram(void *buffer, unsigned short dest, unsigned short count);

/**
 * READ_REGISTER - Read VDP Status Register, return in A
 *
 * @return VDP Status Register in A
 */

unsigned char read_register(void);

/**
 * WRITE_REGISTER - Write requested VDP register in B with value in C
 * 
 * @param register The regiter # 0-7
 * @param value the value 0-255
 */

void write_register(unsigned char rg, unsigned char v);

/**
 * FILL_VRAM - Fill VRAM starting at address with count bytes of value
 *
 * @param address starting VRAM address (0x0000-0x3FFF)
 * @param count number of bytes to write (0x0000-0x4000)
 * @param value Byte to write (0-0xFF) 
 */
unsigned char fill_vram(unsigned short address, unsigned short count, unsigned char value);

/**
 * MODE_1 - Set VDP to Graphics I
 * 
 * VDP tables are set to:
 * 
 * Sprite Generator Table  - 0x3800
 * Pattern Color Table     - 0x2000
 * Sprite Attribute Table  - 0x1B00
 * Pattern Name Table      - 0x1800
 * Pattern Generator Table - 0x0000
 */

void mode_1(void);

/**
 * FILL_VRAM - Fill VRAM starting at address with count bytes of value
 *
 * @param address starting VRAM address (0x0000-0x3FFF)
 * @param count number of bytes to write (0x0000-0x4000)
 * @param value Byte to write (0-0xFF) 
 */
unsigned char fill_vram(unsigned short address, unsigned short count, unsigned char value);

/** 
 * GET_VRAM - reads from VDP ram starting at TABLE_CODE, start index count, and count number of bytes 
 *
 * @param table_code - Table code (see VDPTable enum type)
 * @param start_index - The starting entry in the given table
 * @param data - The target buffer in CRAM
 * @param count - The number of items
 */
void get_vram(VDPTable table, unsigned short start_index, void *data, unsigned short count);

/**
 * REFLECT_VERTICAL - Flip a pattern vertically
 *
 * @param table The table to operate on (see VDPTable typedef in os7.h)
 * @param source The index to start transformation
 * @param destination The index to place the transformed generators
 * @param count The number of items to transform
 */
void reflect_vertical(VDPTable table, unsigned short source, unsigned short destination, unsigned short count);

/**
 * REFLECT_HORIZONTAL - Flip a pattern horizontally
 *
 * @param table The table to operate on (see VDPTable typedef in os7.h)
 * @param source The index to start transformation
 * @param destination The index to place the transformed generators
 * @param count The number of items to transform
 */
void reflect_horizontal(VDPTable table, unsigned short source, unsigned short destination, unsigned short count);

/**
 * ROTATE_90 - Rotate a set of patterns by 90 degrees.
 *
 * @param table The table to operate on (see VDPTable typedef in os7.h)
 * @param source The index to start transformation
 * @param destination The index to place the transformed generators
 * @param count The number of items to transform
 */
void rotate_90(VDPTable table, unsigned short source, unsigned short destination, unsigned short count);

/**
 * INIT_SPR_ORDER - Initialize the sprite order table with SPRITE_COUNT entries
 *
 * @param SPRITE_COUNT Number of sprites to initialize table with
 */
void init_spr_order(unsigned char sprite_count);

/**
 * LOAD_ASCII - Load ASCII patterns into pattern table in VDP
 */
void load_ascii(void);

/**
 * GAME_OPT - Show standard game options screen
 */
void game_opt(void);

/**
 * POLLER - Poll/Debounce controller data into controller data area
 */
void poller(void);

#endif /* OS7_H */
