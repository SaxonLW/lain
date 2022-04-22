CC=gcc
BUILD_DIR=build/
BUILD_SOURCE_DIR=$(BUILD_DIR)source/
BUILD_BIN_DIR=$(BUILD_DIR)bin/

SOURCE_DIR=source/
INCLUDE_DIR=include/
OBJECT_DIR=object/
SHARED_DIR=shared/
TEST_DIR=test/

CC_FLAGS+=-Wall -Wextra -std=c89 -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition -O3
CC_NOSTDINC_FLAG+=-nostdinc
CC_SHARED_FLAG+=-shared
CC_SHARED_FLAG+=-fPIC
CC_OBJECT_FLAG=-c

INCLUDE_PATHS+=-I$(INCLUDE_DIR)

SHARED_EXT=so

# compile = $(CC) $(INCLUDE_PATHS) $(CC_FLAGS) $(CC_OBJECT_FLAG) -o $@ $^
compile_executable = $(CC) $(INCLUDE_PATHS) $(4) $(CC_FLAGS) $(3) -o $(2) $(1)
compile_object = $(CC) $(INCLUDE_PATHS) $(4) $(CC_FLAGS) $(3) $(CC_OBJECT_FLAG) -o $(2) $(1)
compile_shared = $(CC) $(INCLUDE_PATHS) $(4) $(CC_FLAGS) $(3) $(CC_SHARED_FLAG) -o $(2) $(1)

# BUILD

$(BUILD_BIN_DIR)lain.build.c.type.size:$(BUILD_SOURCE_DIR)lain.build.c.type.size.c
	$(call compile_executable,$^,$@,,)
BUILD_TARGETS+=$(BUILD_BIN_DIR)lain.build.c.type.size

$(INCLUDE_DIR)lain.c.type.size.h:$(BUILD_BIN_DIR)lain.build.c.type.size
	$(shell ./$^ > $@)
BUILD_TARGETS+=$(INCLUDE_DIR)lain.c.type.size.h

# INCLUDE

include $(BUILD_SOURCE_DIR)/make/include/*.mk

# SOURCE

include $(BUILD_SOURCE_DIR)/make/source/*.mk

# OBJECT

include $(BUILD_SOURCE_DIR)/make/object/*.mk

build_targets: $(BUILD_TARGETS)
source_targets: $(SOURCE_TARGETS)
include_targets: $(INCLUDE_TARGETS)
object_targets: $(OBJECT_TARGETS)
share_targets: $(SHARE_TARGETS)

all: build_targets source_targets include_targets object_targets share_targets