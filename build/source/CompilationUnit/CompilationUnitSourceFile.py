from CompilationUnitFile import CompilationUnitFile

class CompilationSourceUnitFile(CompilationUnitFile):
    def __init__(self, fromSource=None, name=None, source=None, dependencies=None):
        if isintance(fromSource,CompilationUnitSourceFile):
            self = deepcopy(fromSource)
        else:
            super().__init__(fromSource=fromSource, name=name, source=source, dependencies=dependencies)
            self.directory = "source"
            self.fileExtension = ".c"
    
    def getFileName(self):
        return os.path.join(".",self.directory,super().getFileName()+self.fileExtension)

	def getExtension(self):
		return self.extension

	def getDirectory(self):
		return self.directory

	def getSource(self):
		with open(self.getFileName()) as f:
			return f.read()
	
	def writeOut(self):
		with open(self.getFileName(), "w") as f:
			f.write(self.getSource())