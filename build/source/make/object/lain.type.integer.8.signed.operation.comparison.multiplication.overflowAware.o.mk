$(OBJECT_DIR)lain.type.integer.8.signed.operation.comparison.multiplication.overflowAware.o:$(SOURCE_DIR)lain.type.integer.8.signed.operation.comparison.multiplication.overflowAware.c
	$(call compile_object,$^,$@,$(CC_NOSTDINC_FLAG),)
OBJECT_TARGETS+=$(OBJECT_DIR)lain.type.integer.8.signed.operation.comparison.multiplication.overflowAware.o