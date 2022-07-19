import CompilationUnit

cu = CompilationUnit.CompilationUnit("lain.type.integer.8.signed.operation.comparison.addition.overflowAware")
for type in CompilationUnit.CompilationUnitFileType:
	print(cu.getMakefileFileName(type))
	print(cu.getMakefileDefinition(type))