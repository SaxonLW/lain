$(TEST_DIR)lain.type.integer.8.signed.operation.comparison.modulo.overflowAware.test:$(SOURCE_DIR)lain.type.integer.8.signed.operation.comparison.modulo.overflowAware.c $(SOURCE_DIR)lain.type.integer.8.signed.operation..overflowAware.operation.construct.c $(TEST_DIR)lain.type.integer.8.signed.operation.comparison.modulo.overflowAware.c
	$(call compile_executable,$^,$@,,)
TEST_TARGETS+=$(TEST_DIR)lain.type.integer.8.signed.operation.comparison.modulo.overflowAware.test