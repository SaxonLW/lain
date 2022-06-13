$(TEST_DIR)lain.type.integer.8.signed.operation.comparison.addition.overflowAware.test:$(SOURCE_DIR)lain.type.integer.8.signed.operation.comparison.addition.overflowAware.c $(SOURCE_DIR)lain.type.integer.8.signed.operation..overflowAware.operation.construct.c $(TEST_DIR)lain.type.integer.8.signed.operation.comparison.addition.overflowAware.c
	$(call compile_executable,$^,$@,,)
TEST_TARGETS+=$(TEST_DIR)lain.type.integer.8.signed.operation.comparison.addition.overflowAware.test

