from CompilationUnitFile import CompilationUnitFile

class CompilationSourceUnitFile(CompilationUnitFile):
    def __init__(self, fromSource=None, name=None, source=None, dependencies=None):
        if isintance(fromSource,CompilationUnitSourceFile):
            self = fromSource
        else:
            super().__init__(fromSource=fromSource, name=name, source=source, dependencies=dependencies)
            self.directory = "source"
            self.fileExtension = ".c"
        return self
    
    def getFileName(self):
        return os.path.join(".","source",super().getFileName()+self.fileExtension)