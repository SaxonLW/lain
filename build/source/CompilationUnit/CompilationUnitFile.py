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
			with open(self.getFileName()) as f:
				return f.read()
		else:
			return None

	def getUsedObjectList(self):
		source =  self.getSource()
		for match in self.objectRE.finditer(source):
			yield source[match.start():match.end()]

	def checkForObjectInSource(self, object:str):
		return object in self.getUsedObjectList()

	def getMakefileDefinition(self):
		ret = None
		
		# TODO
		if self.type == CompilationUnitFileType.HEADER:
			headerDependency = " ".join([dependency.getHeaderFile().getFileName() for dependency in self.compilationUnit.getDependencyListHeader()])
			ret = f"{self.getFileName()} : {headerDependency if headerDependency else os.path.join('.','makefile')}"
		elif self.type == CompilationUnitFileType.SOURCE:
			ret = f"{self.getFileName()} : {self.compilationUnit.getHeaderFile().getFileName()}"
		elif self.type == CompilationUnitFileType.OBJECT:
			ret = f"{self.getFileName()} : {self.compilationUnit.getSourceFile().getFileName()}{linesep}\t$(call compile_object,$^,$@,,)"
		elif self.type == CompilationUnitFileType.STATIC:
			sourceDependency = " ".join([dependency.getSourceFile().getFileName() for dependency in self.compilationUnit.getDependencyListSource()])
			ret = f"{self.getFileName()} : {sourceDependency}{linesep}\t$(call link_static,$^,$@)"
		elif self.type == CompilationUnitFileType.SHARED:
			sourceDependency = " ".join([dependency.getSourceFile().getFileName() for dependency in self.compilationUnit.getDependencyListSource()])
			ret = f"{self.getFileName()} : {sourceDependency}{linesep}\t$(call compile_shared,$^,$@,,)"
		else:
			raise ValueError(f"Unknown type {self.type=}")

		return ret

	def getMakefileFileName(self):
		return os.path.join(".","make",self.getFileName()+".mk")