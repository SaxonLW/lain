from os.path import isfile
from os import linesep
import os
import json
from glob import glob
from copy import deepcopy

class CompilationUnitFile(object):
	def __init__(self, fromSource=None, name=None, dependencies=None):
		if fromSource is not None:
			if isinstance(fromSource, dict):
				for key, value in fromSource.items():
					setattr(self,key,value)
			elif isinstance(fromSource,str):
				if isfile(fromSource):
					with open(fileSource) as f:
						for key, value in json.load(f):
							setattr(self,key,value)
				else:
					for key, value in json.loads(fromSource):
						setattr(self,key,value)
			elif isinstance(fromSource,CompilationUnitFile):
				self = deepcopy(fromSource)
			else:
				raise ValueError("fromSource is unknown type")
		else:
			
			if name is None:
				raise ValueError("name must not be None")
			elif isinstance(name,list):
				self.name = name
			elif isinstance(name,str):
				self.name = str.split(".")
			else:
				raise ValueError(f"Needs [list,str] not {type(name)}, fuckwit")
			
			if dependencies is None:
				self.dependencies = list()
			else:
				try:
					iter(dependencies)
				except TypeError as e:
					raise ValueError(f"Needs [None, List[CompilationUnitFile]] not {type(dependencies)}, fuckwit")
				
				constructedDependencyList = list()
				for dependency in (dependencies if dependencies is not None else list()):
					try:
						tmp = CompilationUnitFile(fromSource=dependency)
					except Exception as e:
						raise ValueError(f"{repr(e)}\t\tNeeds [None, List[CompilationUnitFile]] not {type(dependencies)}[{type(dependency)}], fuckwit")
					constructedDependencyList.append(tmp)
				self.dependencies = constructedDependencyList
		
		self.newLine = str(linesep)
		if getattr(self,"name",None) is None:
			raise ValueError(f"name is required, {self.__dict__}, {fromSource}, {name}, {dependencies}")
	
	def getFileName(self):
		raise NotImplementedError(f"{repr(self.getFileName)} not overloaded")
		
	def getSource(self):
		raise NotImplementedError(f"{repr(self.getSource)} not overloaded")
		
	def getExtension(self):
		raise NotImplementedError(f"{repr(self.getExtension)} not overloaded")

	def getDirectory(self):
		raise NotImplementedError(f"{repr(self.getDirectory)} not overloaded")

	def getHeaderFile(self):
		return CompilationUnitHeaderFile(fromSource=self)

	def getSharedFile(self):
		return CompilationUnitSharedFile(fromSource=self)

	def getSourceFile(self):
		return CompilationUnitSourceFile(fromSource=self)

	def getStaticFile(self):
		return CompilationUnitStaticFile(fromSource=self)

class CompilationUnitHeaderFile(CompilationUnitFile):
	def __init__(self, fromSource=None, name=None, dependencies=None):
		if isinstance(fromSource,CompilationUnitHeaderFile):
			self = deepcopy(fromSource)
		else:
			super().__init__(fromSource=fromSource, name=name, dependencies=dependencies)
			for key, value in super().__dict__.items():
				setattr(self,key,value)
			self.directory = "include"
			self.fileExtension = "h"
		if getattr(self,"name",None) is None:
			raise ValueError(f"name is required, {self.__dict__}, {super().__dict__}, {fromSource}, {name}, {dependencies}")
	
	def getFileName(self):
		return os.path.join(".",self.includeDirectory,(".".join(self.name))+self.headerExtension)
	
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

class CompilationUnitSharedFile(CompilationUnitFile):
	def __init__(self, fromSource=None, name=None, dependencies=None):
		if isintance(fromSource,CompilationUnitSharedFile):
			self = deepcopy(fromSource)
		else:
			super().__init__(fromSource=fromSource, name=name, dependencies=dependencies)
			for key, value in super().__dict__.items():
				setattr(self,key,value)
			self.directory = "shared"
			
			if "linux" in platform:
				self.extension = "so"
			elif platform == "darwin":
				self.extension = "dylib"
			elif platform == "win32":
				self.extension = "dll"
			else:
				raise ValueError("Unsupported platform mate")
		if getattr(self,"name",None) is None:
			raise ValueError(f"name is required, {self.__dict__}, {super().__dict__}, {fromSource}, {name}, {dependencies}")
	
	def getFileName(self):
		return os.path.join(".",self.directory,(".".join(self.name))+self.fileExtension)
		
	def getExtension(self):
		return self.extension

	def getDirectory(self):
		return self.directory	
	
	def writeOut(self):
		with open(self.getFileName(), "w") as f:
			f.write(self.getSource())

class CompilationUnitSourceFile(CompilationUnitFile):
	def __init__(self, fromSource=None, name=None, dependencies=None):
		if isinstance(fromSource,CompilationUnitSourceFile):
			self = deepcopy(fromSource)
		else:
			super().__init__(fromSource=fromSource, name=name, dependencies=dependencies)
			for key, value in super().__dict__.items():
				setattr(self,key,value)
			self.directory = "source"
			self.fileExtension = ".c"
		if getattr(self,"name",None) is None:
			raise ValueError(f"name is required, {self.__dict__}, {super().__dict__}, {fromSource}, {name}, {dependencies}")
	
	def getFileName(self):
		return os.path.join(".",self.directory,(".".join(self.name))+self.fileExtension)

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

class CompilationUnitStaticFile(CompilationUnitFile):
	def __init__(self, fromSource=None, name=None, dependencies=None):
		if isintance(fromSource,CompilationUnitStaticFile):
			self = deepcopy(fromSource)
		else:
			super().__init__(fromSource=fromSource, name=name, dependencies=dependencies)
			for key, value in super().__dict__.items():
				setattr(self,key,value)
			self.directory = "static"
			
			if "linux" in platform:
				self.extension = "a"
			elif platform == "darwin":
				self.extension = "a"
			elif platform == "win32":
				self.extension = "lib"
			else:
				raise ValueError("Unsupported platform mate")
		if getattr(self,"name",None) is None:
			raise ValueError(f"name is required, {self.__dict__}, {super().__dict__}, {fromSource}, {name}, {dependencies}")
	
	def getFileName(self):
		return os.path.join(".",self.directory,(".".join(self.name))+self.fileExtension)

	def getExtension(self):
		return self.extension

	def getDirectory(self):
		return self.directory
	
	def writeOut(self):
		with open(self.getFileName(), "w") as f:
			f.write(self.getSource())