TARGET_EXEC ?= os7

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

CC=zcc
AS=z88dk-z80asm

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CFLAGS=+coleco
LDFLAGS=-xos7

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

$(TARGET_EXEC).lib: $(OBJS)
	$(AS) $(LDFLAGS) $(OBJS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: install check clean

install: src/os7.h os7.lib
	install src/os7.h /usr/local/share/z88dk/include/
	install os7.lib /usr/local/share/z88dk/lib/

check:
	$(MAKE) -C examples/mobile_object

clean:
	$(RM) -r os7.lib $(BUILD_DIR)
	$(MAKE) -C examples/mobile_object $@

-include $(DEPS)

MKDIR_P ?= mkdir -p
