$(OBJECT_DIR)lain.type.integer.8.signed.operation.map.signNegate.o:$(SOURCE_DIR)lain.type.integer.8.signed.operation.map.signNegate.c
	$(call compile_object,$^,$@,$(CC_NOSTDINC_FLAG),)
OBJECT_TARGETS+=$(OBJECT_DIR)lain.type.integer.8.signed.operation.map.signNegate.o