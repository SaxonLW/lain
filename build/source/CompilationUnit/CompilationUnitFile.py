from os.path import isfile
from os import linesep
from sys import platform
import os
import json
from glob import glob
from copy import deepcopy
import re
from enum import Enum

class CompilationUnitFileType(Enum):
	HEADER=1
	SOURCE=2
	SHARED=3
	STATIC=4
	OBJECT=5
	

class CompilationUnitFile(object):

	extensionDict = {
		CompilationUnitFileType.HEADER : "h",
		CompilationUnitFileType.SOURCE : "c",
		CompilationUnitFileType.SHARED : {
			"linux" : "so",
			"darwin" : "dylib",
			"win32" : "dll"
		}[platform],
		CompilationUnitFileType.STATIC : {
			"linux" : "a",
			"darwin" : "a",
			"win32" : "lib"
		}[platform],
		CompilationUnitFileType.OBJECT : "o",
	}

	directoryDict = {
		CompilationUnitFileType.HEADER : "include",
		CompilationUnitFileType.SOURCE : "source",
		CompilationUnitFileType.SHARED : "shared",
		CompilationUnitFileType.STATIC : "static",
		CompilationUnitFileType.OBJECT : "object",
	}

	objectRE = re.compile(r"([a-zA-Z0-9_])+")
	
	def __init__(self, compilationUnit, type:CompilationUnitFileType):
		self.compilationUnit = compilationUnit
		self.type = type

	def getExtension(self):
		return self.extensionDict[self.type]

	def getDirectory(self):
		return self.directoryDict[self.type]
	
	def getFileName(self):
		return os.path.join(".",self.getDirectory(),f"{self.compilationUnit.name}.{self.getExtension()}")
		
	def getSource(self):
		if self.type in (CompilationUnitFileType.HEADER, CompilationUnitFileType.SOURCE):
			if isfile(self.getFileName()):
				with open(self.getFileName()) as f:
					return f.read()
			else:
				return None
		else:
			return None

	def getUsedObjectList(self):
		source =  self.getSource()
		if source is None:
			return
			yield
		else:
			for match in self.objectRE.finditer(source):
				yield source[match.start():match.end()]

	def checkForObjectInSource(self, object:str):
		return object in self.getUsedObjectList()

	def getMakefileDefinition(self):
		ret = None
		
		if self.type == CompilationUnitFileType.HEADER:
			headerDependency = " ".join([dependency.getHeaderFile().getFileName() for dependency in self.compilationUnit.getDependencyListHeader()])
			ret = f"{self.getFileName()} : {headerDependency if headerDependency else ''}\n\nINCLUDE_TARGETS+={self.getFileName()}"
		elif self.type == CompilationUnitFileType.SOURCE:
			ret = f"{self.getFileName()} : {self.compilationUnit.getHeaderFile().getFileName()}\n\nSOURCE_TARGETS+={self.getFileName()}"
		elif self.type == CompilationUnitFileType.OBJECT:
			ret = f"{self.getFileName()} : {self.compilationUnit.getSourceFile().getFileName()}{linesep}\t$(call compile_object,$^,$@,,)\n\nOBJECT_TARGETS+={self.getFileName()}"
		elif self.type == CompilationUnitFileType.STATIC:
			sourceDependency = " ".join([dependency.getSourceFile().getFileName() for dependency in self.compilationUnit.getDependencyListSource()])
			ret = f"{self.getFileName()} : {sourceDependency}{linesep}\t$(call link_static,$^,$@)\n\nSTATIC_TARGETS+={self.getFileName()}"
		elif self.type == CompilationUnitFileType.SHARED:
			sourceDependency = " ".join([dependency.getSourceFile().getFileName() for dependency in self.compilationUnit.getDependencyListSource()])
			ret = f"{self.getFileName()} : {sourceDependency}{linesep}\t$(call compile_shared,$^,$@,,)\n\nSHARED_TARGETS+={self.getFileName()}"
		else:
			raise ValueError(f"Unknown type {self.type}")

		return ret

	def getMakefileFileName(self):
		ret = None
		if self.type == CompilationUnitFileType.STATIC:
			makefileName = ".".join(self.getFileName().split(".")[:-1]) + ".static_ext"
			ret = os.path.join(".","make",makefileName+".mk")
		elif self.type == CompilationUnitFileType.SHARED:
			makefileName = ".".join(self.getFileName().split(".")[:-1]) + ".shared_ext"
			ret = os.path.join(".","make",makefileName+".mk")
		else:
			ret = os.path.join(".","make",self.getFileName()+".mk")
		return ret

	def getBoilerPlate(self):
		ret = None
		if self.type == CompilationUnitFileType.HEADER:
			headerGuard = os.path.basename(self.getFileName()).replace(".","_").upper()
			ret = f"""#ifndef {headerGuard}{linesep}#define {headerGuard}{linesep}TODO - DEFINE {self.compilationUnit.name.replace('.','_')}{linesep}#endif /*{headerGuard}*/"""
		elif self.type == CompilationUnitFileType.SOURCE:
			ret = f'''#include "{os.path.basename(self.compilationUnit.getHeaderFile().getFileName())}"{linesep}{linesep}TODO - IMPLEMENT {self.compilationUnit.name.replace(".","_")}'''
		else:
			raise ValueError(f"Boiler Plate not available for {self.type}")
		return ret