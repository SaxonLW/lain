CC=gcc
BUILD_DIR=build
BUILD_SOURCE_DIR=$(BUILD_DIR)/source
BUILD_BIN_DIR=$(BUILD_DIR)/bin

SOURCE_DIR=source
INCLUDE_DIR=include
OBJECT_DIR=object
SHARED_DIR=shared
TEST_DIR=test

CC_FLAGS+=-Wall -Wextra -std=c99 -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition -O3 -nostdinc
CC_SHARED_FLAG=-shared
CC_POSITION_INDEPENDENT_FLAG=-fPIC
CC_OBJECT_FLAG=-c

INCLUDE_PATHS+=-I$(INCLUDE_DIR)

$(BUILD_BIN_DIR)/lain.build.c.type.size:$(BUILD_SOURCE_DIR)/lain.build.c.type.size.c
	$(CC) -o $@ $^
ALL_TARGETS+=$(BUILD_BIN_DIR)/lain.build.c.type.size

$(INCLUDE_DIR)/lain.c.type.size.h:$(BUILD_BIN_DIR)/lain.build.c.type.size
	$(shell ./$^ > $@)
ALL_TARGETS+=$(INCLUDE_DIR)/lain.c.type.size.h

$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.typedef.h:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.typedef.h
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.typedef.h

$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.add.h:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.typedef.h
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.add.h

$(INCLUDE_DIR)lain.type.integer.8.signed.operation.comparison.typedef.h:$(INCLUDE_DIR)/lain.type.integer.8.signed.typedef.h
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.typedef.h

$(INCLUDE_DIR)lain.type.integer.8.signed.operation.typedef.h:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.typedef.h
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.typedef.h

$(INCLUDE_DIR)/lain.type.integer.8.signed.typedef.h:
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.signed.typedef.h

$(INCLUDE_DIR)/lain.type.integer.8.unsigned.typedef.h:
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.unsigned.typedef.h

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.add.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.add.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.add.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.subtract.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.subtract.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.subtract.c

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.add.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.add.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.add.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.subtract.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.subtract.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.subtract.o

all: $(ALL_TARGETS)