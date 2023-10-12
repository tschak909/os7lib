TARGET_EXEC ?= rotate_90.rom

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

CC=zcc
AS=zcc

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.asm)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CFLAGS=+coleco -I../../src
LDFLAGS=+coleco -m -s -pragma-define:CRT_ENABLE_STDIO=0 -pragma-define:REGISTER_SP=0x73B8  -pragma-define:CLIB_FOPEN_MAX=0 -pragma-define:fputc_cons=0 -pragma-define:CLIB_DEFAULT_SCREEN_MODE=-1 -L../.. -los7 -o$(TARGET_EXEC) -create-app 
ASFLAGS=+coleco

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

$(TARGET_EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# asm source
$(BUILD_DIR)/%.asm.o: %.asm
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r rotate_90* $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
