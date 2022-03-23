CC=gcc
BUILD_DIR=build
BUILD_SOURCE_DIR=$(BUILD_DIR)/source
BUILD_BIN_DIR=$(BUILD_DIR)/bin

SOURCE_DIR=source
INCLUDE_DIR=include

CC_FLAGS+=-Wall -Wextra -std=c89 -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition -O3 -nostdinc
INCLUDE_PATHS+=-I$(INCLUDE_DIR)

CC_F_PIC=-fPIC
CC_F_SHARED=-shared

all: $(BUILD_BIN_DIR)/lain.build.c.type.size $(INCLUDE_DIR)/lain.c.type.size.h 

$(BUILD_BIN_DIR)/lain.build.c.type.size:$(BUILD_SOURCE_DIR)/lain.build.c.type.size.c
	$(CC) $^ -o $@

$(INCLUDE_DIR)/lain.c.type.size.h:$(BUILD_BIN_DIR)/lain.build.c.type.size
	$(shell ./$^ > $@)