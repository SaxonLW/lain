CC=gcc
BUILD_DIR=build
BUILD_SOURCE_DIR=$(BUILD_DIR)/source
BUILD_BIN_DIR=$(BUILD_DIR)/bin

SOURCE_DIR=source
INCLUDE_DIR=include
OBJECT_DIR=object
SHARED_DIR=shared
TEST_DIR=test

CC_FLAGS+=-Wall -Wextra -std=c89 -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition -O3 -nostdinc
CC_SHARED_FLAG=-shared
CC_POSITION_INDEPENDENT_FLAG=-fPIC
CC_OBJECT_FLAG=-c

INCLUDE_PATHS+=-I$(INCLUDE_DIR)

SHARED_EXT=so

$(BUILD_BIN_DIR)/lain.build.c.type.size:$(BUILD_SOURCE_DIR)/lain.build.c.type.size.c
	$(CC) -o $@ $^
ALL_TARGETS+=$(BUILD_BIN_DIR)/lain.build.c.type.size

$(INCLUDE_DIR)/lain.c.type.size.h:$(BUILD_BIN_DIR)/lain.build.c.type.size
	$(shell ./$^ > $@)
ALL_TARGETS+=$(INCLUDE_DIR)/lain.c.type.size.h

$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.typedef.h:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.typedef.h
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.typedef.h

$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.addition.h:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.typedef.h
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.addition.h

$(INCLUDE_DIR)lain.type.integer.8.signed.operation.comparison.typedef.h:$(INCLUDE_DIR)/lain.type.integer.8.signed.typedef.h
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.typedef.h

$(INCLUDE_DIR)lain.type.integer.8.signed.operation.typedef.h:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.typedef.h
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.typedef.h

$(INCLUDE_DIR)/lain.type.integer.8.signed.typedef.h:
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.signed.typedef.h

$(INCLUDE_DIR)/lain.type.integer.8.unsigned.typedef.h:
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.unsigned.typedef.h

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.addition.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.addition.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.addition.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.division.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.division.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.division.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.equality.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.equality.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.equality.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThan.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThan.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThan.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThanOrEquality.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThanOrEquality.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThanOrEquality.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.inequality.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.inequality.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.inequality.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThan.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThan.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThan.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThanOrEquality.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThanOrEquality.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThanOrEquality.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.modulo.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.modulo.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.modulo.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.multiplication.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.multiplication.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.multiplication.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.subtraction.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.subtraction.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.subtraction.c

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.addition.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.addition.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.addition.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.division.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.division.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.division.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.equality.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.equality.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.equality.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThan.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThan.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThan.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThanOrEquality.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThanOrEquality.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThanOrEquality.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.inequality.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.inequality.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.inequality.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.lessThan.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThan.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.lessThan.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.lessThanOrEquality.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThanOrEquality.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.lessThanOrEquality.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.modulo.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.modulo.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.modulo.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.multiplication.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.multiplication.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.multiplication.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.subtraction.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.subtraction.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.subtraction.o

all: $(ALL_TARGETS)