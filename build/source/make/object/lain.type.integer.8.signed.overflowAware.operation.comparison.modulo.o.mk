$(OBJECT_DIR)lain.type.integer.8.signed.overflowAware.operation.comparison.modulo.o:$(SOURCE_DIR)lain.type.integer.8.signed.overflowAware.operation.comparison.modulo.c
	$(call compile_object,$^,$@,$(CC_NOSTDINC_FLAG),)
OBJECT_TARGETS+=$(OBJECT_DIR)lain.type.integer.8.signed.overflowAware.operation.comparison.modulo.o