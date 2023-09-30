#ifndef OS7_H
#define OS7_H

#include <stdbool.h>

/**
 * @brief Addresses of ROM routines for AsmCall
 */
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
#define ACTIVATE 0x1FF7
#define PUT_OBJ 0x1FFA

/**
 * @brief VDPTable values for get/put_vram
 */
typedef enum _vdp_table
  {
    SPRITE_ATTRIBUTE_TABLE=0,
    SPRITE_GENERATOR_TABLE,
    PATTERN_NAME_TABLE,
    PATTERN_GENERATOR_TABLE,
    PATTERN_COLOR_TABLE
  } VDPTable;

/**
 * @brief VDP colors
 */
#define TRANSPARENT 0
#define BLACK 1
#define MEDIUM_GREEN 2
#define LIGHT_GREEN 3
#define DARK_BLUE 4
#define LIGHT_BLUE 5
#define DARK_RED 6
#define CYAN 7
#define MEDIUM_RED 8
#define LIGHT_RED 9
#define DARK_YELLOW 10
#define LIGHT_YELLOW 11
#define DARK_GREEN 12
#define MAGENTA 13
#define GRAY 14
#define WHITE 15

/**
 * @brief VDP Register #s to Names
 */
#define REGISTER_BACKGROUND 7

/**
 * @brief The size of each WRITER queue entry
 */
#define WRITER_QUEUE_ENTRY_SIZE 3

/**
 * @brief Required Size of newgen table in RAM in bytes
 */
#define NEWGEN_SIZE 72

/**
 * @brief Timer Table entry
 */
typedef struct _timer_table
{
  unsigned char mode;
  unsigned short value;
} TimerTable;

/**
 * @brief A timer signal # returned by REQUEST_SIGNAL
 */
typedef unsigned char SignalNum;

/**
 * @brief A timer data block entry, for long running timers
 * @verbose we don't ever touch it directly, we just need to reserve 4 bytes for each long running timer we want.
 */
typedef unsigned long TimerData;

/**
 * @brief obj_type for a SEMI_MOBILE graphics object
 */
#define SEMI_MOBILE 0

/**
 * @brief obj_type for a Mobile object
 */
#define MOBILE 1

/**
 * @brief obj_type for a Sprite object
 */
#define SPRITE 3

/**
 * @brief obj_type for a Complex object
 */
#define COM_OB 4

/**
 * @brief obj type | modifier for SEMI mobile objects in mode 2 to use a single color generator entry instead of 8.
 */
#define MODE2_SINGLE_COLOR 0x10

/**
 * @brief obj type | modifier for SEMI mobile objects in mode 2 to specify that this object should be in bottom third
 */
#define MODE2_BOTTOM 0x20

/**
 * @brief obj type | modifier for SEMI mobile objects in mode 2 to specify that this object should be in middle third
 */
#define MODE2_MIDDLE 0x40

/**
 * @brief obj type | modifier for SEMI mobile objects in mode 2 to specify that this object should be in top third
 */
#define MODE2_TOP 0x80

/**
 * @brief A Semi-Mobile Object (SMO) top level definition
 */
typedef struct _smo
{
  void *graphics_addr;        // pointer in ROM to graphics object
  void *status_addr;          // pointer in RAM to status 
  void *old_screen_addr;      // pointer in RAM to old screen data (backing store), bit 15 set = disable
} SMO;

/**
 * @brief a Mobile Object (MOB) top level definition
 */
typedef struct _mob
{
  void *graphics_addr;        // pointer in ROM to graphics object
  void *status_addr;          // pointer in RAM to status 
  void *old_screen_addr;      // pointer in RAM to old screen data (backing store), bit 15 set = disable
  unsigned char first_gen;    // Index to first generator to use in PATTERN and COLOR tables
} MOB;

/**
 * @brief the frame data for a given SMO GRAPHICS object
 */
#define SMOFrame(n)				\
  typedef struct				\
  {						\
    unsigned char x_extent;			\
    unsigned char y_extent;			\
    unsigned char generator[n];			\
  }						\

/**
 * @brief the frame data for a given SMO GRAPHICS object
 */
#define SMOOldScreen(n)				\
  typedef struct				\
  {						\
    unsigned char x_pat_pos;			\
    unsigned char y_pat_pos;			\
    unsigned char x_extent;			\
    unsigned char y_extent;			\
    unsigned char generator[n];			\
  }						\

/**
 * @brief the frame data for a given MOB GRAPHICS object
 */
typedef struct _mob_frame
{
  unsigned char upper_left;
  unsigned char lower_left;
  unsigned char upper_right;
  unsigned char lower_right;
  unsigned char color0;
} MOBFrame;

typedef struct _mob_old_screen
{
  unsigned char x_pat_pos;
  unsigned char y_pat_pos;
  unsigned char saved_generators[9];
} MOBOldScreen;

/**
 * @brief a SMO GRAPHICS object defining n of frames
 */
#define SMOGraphics(n,FrameObj)			\
  typedef struct				\
  {						\
    unsigned char obj_type;			\
    unsigned char first_gen_name;		\
    unsigned char numgen;			\
    void *generators;				\
    FrameObj *frame[n];				\
  }

/**
 * @brief a MOB GRAPHICS object defining n of frames
 */
#define MOBGraphics(n)				\
  typedef struct				\
  {						\
    unsigned char obj_type;			\
    unsigned char numgen;			\
    void *newgen;				\
    void *generators;				\
    MOBFrame *frame[n];				\
  }						

/**
 * @brief a SEMI-MOBILE STATUS object
 */
typedef struct _smo_status
{
  unsigned char frame;
  int x;
  int y;
  unsigned char next_gen;
} SMOStatus;

/**
 * @brief a MOBILE status object
 */
typedef struct _mob_status
{
  unsigned char frame;
  int x;
  int y;
  void *newgen;
} MOBStatus;

/**
 * @brief a SPROBJ (sprite object)
 */
typedef struct _sprobj
{
  void *graphics;
  void *status;
  unsigned char index;
} SprObj;

/**
 * @brief A Sprite Graphics Object
 */
typedef struct _spr_graphics
{
  unsigned char obj_type;
  unsigned char first_gen_name;
  void *generators;
  unsigned char numgen;
  void *frame_table;
} SprGraphics;

/**
 * @brief a sprite frame (usually in an array)
 */
typedef struct _spr_frame
{
  unsigned char color;
  unsigned char shape;
} SprFrame;

/**
 * @brief a sprite's status object
 */
typedef struct _spr_status
{
  unsigned char frame;
  int x;
  int y;
  unsigned char next_gen;
} SprStatus;

/**
 * @brief a Complex top-level object with n number components
 */
#define COMObj(n)				\
  typedef struct				\
  {						\
    void *graphics;				\
    void *status;                               \
    void *components[n];			\
  }              				\

/**
 * @brief A Complex graphics object with n number components
 */
#define COMGraphics(n)							\
  typedef struct							\
  {									\
    unsigned char obj_type;						\
    struct								\
    {									\
      void *frame_obj;							\
      void *offset_obj;							\
    } ptrs[n];								\
  }									\

/**
 * @brief A complex frame, just a frame # to use
 */
typedef unsigned char COMFrame;

/**
 * @brief A Complex offset. X,Y coordinate pairs
 */
typedef struct
{
  unsigned short x;
  unsigned short y;
} COMOffset;

/**
 * @brief a status object for COMPLEX objects
 */
typedef struct
{
  unsigned char frame;
  unsigned short x;
  unsigned short y;
} COMStatus;

/**
 * @brief A structure for the controller data area
 */
typedef struct
{
  unsigned char player1_enable;
  unsigned char player2_enable;
  struct
  {
    unsigned char left_button;
    unsigned char joystick;
    unsigned char spinner_count;
    unsigned char right_button;
    unsigned char keyboard;
  } player1;
  struct
  {
    unsigned char left_button;
    unsigned char joystick;
    unsigned char spinner_count;
    unsigned char right_button;
    unsigned char keyboard;
  } player2;
} ControllerData;

// FUNCTIONS ////////////////////////////////////////////////////////////

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
 *w
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

#define MODE1_SPRITE_GENERATOR_TABLE 0x3800
#define MODE1_PATTERN_COLOR_TABLE 0x2000
#define MODE1_SPRITE_ATTRIBUTE_TABLE 0x1B00
#define MODE1_PATTERN_NAME_TABLE 0x1800
#define MODE1_PATTERN_GENERATOR_TABLE 0x0000

/**
 * MODE_1 - Set VDP to Graphics I
 * 
 * VDP tables are set to:
 * 
 * Sprite Generator Table  - 0x3800
 * Pattern Color Table     - 0x2000
 * Sprite Attribute Table  - 0x1B00
 * Pattern Name Table      - 0x1800
o * Pattern Generator Table - 0x0000
 */

void mode_1(void);

/**
 * MODE_1 - Set VDP to Graphics II
 * 
 * VDP tables are set to:
 * 
 * Sprite Generator Table  - 0x3800
 * Pattern Color Table     - 0x2000
 * Sprite Attribute Table  - 0x1B00
 * Pattern Name Table      - 0x1800
o * Pattern Generator Table - 0x0000
 */

void mode_2(void);


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
 * PUT_VRAM - writes to VDP ram starting at TABLE_CODE, start index count, and count number of bytes 
 *
 * @param table_code - Table code (see VDPTable enum type)
 * @param start_index - The starting entry in the given table
 * @param data - The tarput buffer in CRAM
 * @param count - The number of items
 */
void put_vram(VDPTable table, unsigned short start_index, void *data, unsigned short count);

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
 * ENLARGE - Double the size of each pattern into destination.
 *
 * @param table The table to operate on (see VDPTable typedef in os7.h)
 * @param source The index to start transformation
 * @param destination The index to place the transformed generators
 * @param count The number of items to transform
 */
void enlarge(VDPTable table, unsigned short source, unsigned short destination, unsigned short count);

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
SignalNum request_signal(unsigned short len, bool repeat);

/**
 * @brief TEST_SIGNAL - Check if timer specified by signal_num has passed.
 * @param signal_num  - The signal # to test (0-255)
 * @return true if timer has passed, false if not.
 */
bool test_signal(SignalNum signal_num);

/**
 * @brief FREE_SIGNAL - Stop timer and remove it from tables
 * @param signal_num  - The signal # to test (0-255)
 */
void free_signal(SignalNum signal_num);

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
unsigned short rand_gen(void);

// Functions I've added, because why not?

/**
 * @brief turn on or off screen rendering
 * @param onoff - true = turn screen on, false = turn screen off (leaving backdrop color)
 */
void blank(bool onoff);

/**
 * @brief Clear the entire vram
 */
void clear_vram(void);

/** 
 * ACTIVATE - writes to VDP ram starting at TABLE_CODE, start index count, and count number of bytes 
 *
 * @param object pointer to object to activate.
 * @oaram move if true, move generators to vram.
 */
void activate(void *object, bool move);

/** 
 * PUT_OBJ - writes to VDP ram starting at TABLE_CODE, start index count, and count number of bytes 
 *
 * @param object pointer to object to put_obj.
 * @param background mode to use when combining in mobile object mode.
 */
void put_obj(void *object, unsigned char bkg_mode);

/**
 * VDP_STATUS_BYTE - RAM location for VDP Status register
 */
#define VDP_STATUS_BYTE (*(unsigned char *)0x73c5)

/**
 * DEFER_WRITES - RAM location to turn on/off deferred writes
 */
#define DEFER_WRITES (*(unsigned char *)0x73c6)

#endif /* OS7_H */
