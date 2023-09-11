#ifndef OS7_H
#define OS7_H

#include <stdbool.h>

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
#define INIT_WRITER 0x1FE5
#define WRITER 0x1FE8
#define INIT_TIMER 0x1FC7
#define TIME_MGR 0x1FD3
#define REQUEST_SIGNAL 0x1FCD
#define TEST_SIGNAL 0x1FD0
#define FREE_SIGNAL 0x1FCA
#define SOUND_INIT 0x1FEE
#define PLAY_IT 0x1FF1
#define SOUND_MAN 0x1FF4
#define PLAY_SONGS 0x1F61
#define ADD816 0x01B1
#define DECLSN 0x0190
#define DECMSN 0x019B
#define MSNTOLSN 0x01A6
#define RAND_GEN 0x1FFD

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

/** 
 * @brief INIT_WRITER - Initializes deferred write queue
 * @param size # of entries in queue, should equal desired queue size / 3
 * @param location The location of queue in memory
 */
void init_writer(void *location, unsigned char size);

/** 
 * @brief WRITER - Calls PUTOBJ to do deferred object writes
 */
void writer(void);

/** 
 * @brief INIT_TIMER - Initializes the timer data areas
 * @param timer_table location of timer table in cartridge memory
 * @param timer_data_block location of timer data block in memory
 */
void init_timer(void *timer_table, void *timer_data_block);

/** 
 * @brief TIME_MGR - Called every NMI to decrement the active timers
 */
void time_mgr(void);

/** 
 * @brief REQUEST_SIGNAL - Requests a timer to start.
 * @param len Length of timer (0-65535 frames)
 * @param repeat true = reset and decrement when 0
 * @return signal number.
 */
unsigned char request_signal(unsigned short len, bool repeat);

/**
 * @brief TEST_SIGNAL - Check if timer specified by signal_num has passed.
 * @param signal_num  - The signal # to test (0-255)
 * @return true if timer has passed, false if not.
 */
bool test_signal(unsigned char signal_num);

/**
 * @brief FREE_SIGNAL - Stop timer and remove it from tables
 * @param signal_num  - The signal # to test (0-255)
 */
void free_signal(unsigned char signal_num);

/**
 * @brief DECODER - Scan and return decoded controller output
 * @param controller_no - The controller # (0 or 1)
 * @param segment_no - The segment # to decode (0 = fire/joy/spinner, 1 = keypad)
 * @param buttons - destination pointer for button data
 * @param control - destination pointer for controller/keyboard data
 * @param spinner - destination pointer for spinner data.
 */
void decoder(unsigned char controller_no, unsigned char segment_no, unsigned char *buttons, unsigned char *control, unsigned char *spinner);

/** 
 * @brief SOUND_INIT - Initialize the sound routines
 * @param sound_data_areas - # of sound data areas to initialize
 * @param list_of_sound_addrs - base address of a list of starting addresses for each sund's note list and data area
 */
void sound_init(unsigned char sound_data_areas, void *list_of_sound_addrs);

/** 
 * @brief PLAY_IT - Trigger sound no.
 * @param sound_no - The sound to trigger
 */
void play_it(unsigned char sound_no);

/** 
 * @brief SOUND_MAN - Updates sound state each VDP interrupt
 */
void sound_man(void);

/** 
 * @brief PLAY_SONGS - Updates sound state each VDP interrupt
 */
void play_songs(void);

/** 
 * ADD816 - Add 8-bit value to 16-bit value pointed to by address
 * @param a - The number to add to value at addr
 * @param addr - pointer to 16-bit number at address
 */
void add816(unsigned char a, unsigned short *addr);

/** 
 * DECLSN - Decrement least significant nibble at address
 * @param addr - Address with least-significant nibble to decrement
 */
void declsn(unsigned short *addr);

/** 
 * DECMSN - Decrement most significant nibble at address
 * @param addr - Address with mo st-significant nibble to decrement
 */
void decmsn(unsigned short *addr);

/** 
 * MSNTOLSN - Decrement most significant nibble at address
 * @param addr - Address with mo st-significant nibble to decrement
 */
void msntolsn(unsigned short *addr);

/** 
 * RAND_GEN - Generate new 16-bit pseudo-random number, stuff at RAND_NUM
 */
void rand_gen(void);

#endif /* OS7_H */
