$(OBJECT_DIR)lain.type.integer.8.signed.overflowAware.operation.comparison.greaterThan.o:$(SOURCE_DIR)lain.type.integer.8.signed.overflowAware.operation.comparison.greaterThan.c
	$(call compile_object,$^,$@,$(CC_NOSTDINC_FLAG),)
OBJECT_TARGETS+=$(OBJECT_DIR)lain.type.integer.8.signed.overflowAware.operation.comparison.greaterThan.o