$(OBJECT_DIR)lain.type.integer.8.signed.operation.comparison.bitwiseOr.o:$(SOURCE_DIR)lain.type.integer.8.signed.operation.comparison.bitwiseOr.c
	$(call compile_object,$^,$@,$(CC_NOSTDINC_FLAG),)
OBJECT_TARGETS+=$(OBJECT_DIR)lain.type.integer.8.signed.operation.comparison.bitwiseOr.o