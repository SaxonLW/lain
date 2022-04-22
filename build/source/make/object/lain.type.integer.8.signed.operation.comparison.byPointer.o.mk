$(OBJECT_DIR)lain.type.integer.8.signed.operation.comparison.byPointer.o:$(SOURCE_DIR)lain.type.integer.8.signed.operation.comparison.byPointer.c
	$(call compile_object,$^,$@,$(CC_NOSTDINC_FLAG),)
OBJECT_TARGETS+=$(OBJECT_DIR)lain.type.integer.8.signed.operation.comparison.byPointer.o