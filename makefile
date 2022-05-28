CC=gcc

COMMA=,

BUILD_DIR=build/
BUILD_SOURCE_DIR=$(BUILD_DIR)source/
BUILD_BIN_DIR=$(BUILD_DIR)bin/

SOURCE_DIR=source/
INCLUDE_DIR=include/
OBJECT_DIR=object/
SHARED_DIR=shared/
STATIC_DIR=static/
TEST_DIR=test/

CC_FLAGS+=-Wall -Wextra -std=c89 -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition -O3
CC_NOSTDINC_FLAG+=-nostdinc
CC_SHARED_FLAG+=-shared
CC_SHARED_FLAG+=-fPIC
CC_OBJECT_FLAG=-c

STATIC_EXT=a
SHARED_EXT=so

INCLUDE_PATHS+=-I$(INCLUDE_DIR)

compile_executable = $(CC) $(INCLUDE_PATHS) $(4) $(CC_FLAGS) $(3) -o $(2) $(1)
compile_object = $(CC) $(INCLUDE_PATHS) $(4) $(CC_FLAGS) $(3) $(CC_OBJECT_FLAG) -o $(2) $(1)
compile_shared = $(CC) $(INCLUDE_PATHS) $(4) $(CC_FLAGS) $(3) $(CC_SHARED_FLAG) -o $(2) $(1)

# ARCHIVING
ARCHIVE_EXE=ar
ARCHIVE_FLAG=rcs

link_static = $(ARCHIVE_EXE) $(ARCHIVE_FLAG) $(2) $(1)

# BUILD

$(BUILD_BIN_DIR)lain.build.c.type.size:$(BUILD_SOURCE_DIR)lain.build.c.type.size.c
	$(call compile_executable,$^,$@,,)
BUILD_TARGETS+=$(BUILD_BIN_DIR)lain.build.c.type.size

$(INCLUDE_DIR)lain.c.type.size.h:$(BUILD_BIN_DIR)lain.build.c.type.size
	$(shell ./$^ > $@)
BUILD_TARGETS+=$(INCLUDE_DIR)lain.c.type.size.h

# INCLUDE

include $(BUILD_SOURCE_DIR)make/include/*.mk

# SOURCE

include $(BUILD_SOURCE_DIR)make/source/*.mk

# OBJECT

include $(BUILD_SOURCE_DIR)make/object/*.mk

# STATIC

include $(BUILD_SOURCE_DIR)make/static/*.mk

# SHARED

include $(BUILD_SOURCE_DIR)make/shared/*.mk

.PHONY : build
build:$(BUILD_TARGETS)

.PHONY : object
object:$(OBJECT_TARGETS)

.PHONY : static
static:$(STATIC_TARGETS)

.PHONY : shared
shared:$(SHARED_TARGETS)

.PHONY : all
all:static object build shared

.PHONY : clean
clean:
	-rm $(OBJECT_DIR)*
	-rm $(STATIC_DIR)*
	-rm $(SHARED_DIR)*
