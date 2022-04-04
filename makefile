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

$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.byPointer.typedef.h:
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.byPointer.typedef.h

$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.byPointer.h:
	$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.byPointer.typedef.h
ALL_TARGETS+=$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.byPointer.h

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.addition.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.addition.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.addition.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.division.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.division.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.division.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.equalTo.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.equalTo.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.equalTo.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThan.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThan.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThan.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThanOrEqualTo.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThanOrEqualTo.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThanOrEqualTo.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.notEqualTo.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.notEqualTo.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.notEqualTo.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThan.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThan.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThan.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThanOrEqualTo.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThanOrEqualTo.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThanOrEqualTo.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.modulo.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.modulo.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.modulo.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.multiplication.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.multiplication.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.multiplication.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.subtraction.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.subtraction.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.subtraction.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.logicalAnd.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.logicalAnd.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.logicalAnd.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.logicalOr.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.logicalOr.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.logicalOr.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseAnd.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseAnd.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseAnd.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseLeftShift.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseLeftShift.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseLeftShift.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseOr.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseOr.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseOr.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseRightShift.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseRightShift.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseRightShift.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseXOr.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseXOr.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseXOr.c

$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.byPointer.c:$(INCLUDE_DIR)/lain.type.integer.8.signed.operation.comparison.byPointer.h
ALL_TARGETS+=$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.byPointer.c

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.addition.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.addition.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.addition.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.division.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.division.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.division.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.equalTo.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.equalTo.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.equalTo.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThan.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThan.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThan.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThanOrEqualTo.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThanOrEqualTo.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.greaterThanOrEqualTo.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.notEqualTo.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.notEqualTo.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.notEqualTo.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.lessThan.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThan.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.lessThan.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.lessThanOrEqualTo.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.lessThanOrEqualTo.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.lessThanOrEqualTo.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.modulo.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.modulo.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.modulo.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.multiplication.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.multiplication.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.multiplication.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.subtraction.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.subtraction.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.subtraction.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.logicalAnd.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.logicalAnd.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.logicalAnd.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.logicalOr.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.logicalOr.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.logicalOr.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseAnd.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseAnd.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseAnd.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseLeftShift.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseLeftShift.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseLeftShift.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseOr.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseOr.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseOr.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseRightShift.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseRightShift.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseRightShift.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseXOr.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseXOr.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.bitwiseXOr.o

$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.byPointer.o:$(SOURCE_DIR)/lain.type.integer.8.signed.operation.comparison.byPointer.c
	$(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
ALL_TARGETS+=$(OBJECT_DIR)/lain.type.integer.8.signed.operation.comparison.byPointer.o

all: $(ALL_TARGETS)