class CompilationUnitStaticFile(object):
    def __init__(self, fromSource=None, name=None, source=None, dependencies=None):
        if isintance(fromSource,CompilationUnitStaticFile):
            self = deepcopy(fromSource)
        else:
            super().__init__(fromSource=fromSource, name=name, source=source, dependencies=dependencies)
            self.directory = "static"
            
	        if "linux" in platform:
	            self.extension = "a"
	        elif platform == "darwin":
	            self.extension = "a"
	        elif platform == "win32":
	            self.extension = "lib"
	        else:
	            raise ValueError("Unsupported platform mate")
    
    def getFileName(self):
        return os.path.join(".",self.directory,super().getFileName()+self.fileExtension)

	def getExtension(self):
		return self.extension

	def getDirectory(self):
		return self.directory
	
	def writeOut(self):
		with open(self.getFileName(), "w") as f:
			f.write(self.getSource())