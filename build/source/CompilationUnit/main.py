import CompilationUnit

cu = CompilationUnit.CompilationUnit("lain.type.integer.8.signed.operation.comparison.addition.overflowAware")
print(cu.getMakefileDefinition(type=CompilationUnit.CompilationUnitFileType.HEADER))
print(cu.getMakefileDefinition(type=CompilationUnit.CompilationUnitFileType.SOURCE))
print(cu.getMakefileDefinition(type=CompilationUnit.CompilationUnitFileType.OBJECT))
print(cu.getMakefileDefinition(type=CompilationUnit.CompilationUnitFileType.SHARED))
print(cu.getMakefileDefinition(type=CompilationUnit.CompilationUnitFileType.STATIC))