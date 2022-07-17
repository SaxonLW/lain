from CompilationUnitFile import CompilationUnitFile

class CompilationUnitHeaderFile(CompilationUnitFile):
    def __init__(self, fromSource=None, name=None, source=None, dependencies=None):
        if isintance(fromSource,CompilationUnitHeaderFile):
            self = fromSource
        else:
            super().__init__(fromSource=fromSource, name=name, source=source, dependencies=dependencies)
            self.directory = "include"
            self.fileExtension = "h"
        return self
    
    def getFileName(self):
        return os.path.join(".",self.includeDirectory,super().getFileName()+self.headerExtension)
    
    def getHeaderGuardDefinition(self):
        return self.getFileName.replace(".","_").upper()

    def getSource(self):
        return f"""#ifndef {self.getHeaderGuardDefinition()}{self.newLine}#define {self.getHeaderGuardDefinition()}{self.newLine}{super().getSource()}{self.newLine}#endif /*{self.getHeaderGuardDefinition()}*/"""
