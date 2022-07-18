from copy import deepcopy

class CompilationUnitSharedFile(object):
    def __init__(self, name):
        if isintance(fromSource,CompilationUnitSharedFile):
            self = deepcopy(fromSource)
        else:
            super().__init__(fromSource=fromSource, name=name, source=source, dependencies=dependencies)
            self.directory = "shared"
			
	        if "linux" in platform:
	            self.extension = "so"
	        elif platform == "darwin":
	            self.extension = "dylib"
	        elif platform == "win32":
	            self.extension = "dll"
	        else:
	            raise ValueError("Unsupported platform mate")
		
	def getExtension(self):
		return self.extension

	def getDirectory(self):
		return self.directory	
	
	def writeOut(self):
		with open(self.getFileName(), "w") as f:
			f.write(self.getSource())