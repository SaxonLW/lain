$(OBJECT_DIR)lain.type.integer.8.signed.operation.comparison.logicalAnd.o:$(SOURCE_DIR)lain.type.integer.8.signed.operation.comparison.logicalAnd.c
	$(call compile_object,$^,$@,$(CC_NOSTDINC_FLAG),)
OBJECT_TARGETS+=$(OBJECT_DIR)lain.type.integer.8.signed.operation.comparison.logicalAnd.o