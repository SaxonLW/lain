from sys import platform

from CompilationUnitFile import CompilationUnitFile

class CompilationUnitHeaderFile(CompilationUnitFile):
    def __init__(self, fromSource=None, name=None, source=None, dependencies=None):
        if isintance(fromSource,CompilationUnitHeaderFile):
            self = deepcopy(fromSource)
        else:
            super().__init__(fromSource=fromSource, name=name, source=source, dependencies=dependencies)
            self.directory = "include"
            self.fileExtension = "h"
    
    def getFileName(self):
        return os.path.join(".",self.includeDirectory,super().getFileName()+self.headerExtension)
    
    def getHeaderGuardDefinition(self):
        return self.getFileName.replace(".","_").upper()

    def getSource(self):
        with open(self.getFileName()) as f:
			return f.read()

	def getExtension(self):
		return self.extension

	def getDirectory(self):
		return self.directory

	def writeOut(self):
		with open(self.getFileName(), "w") as f:
			f.write(self.getSource())