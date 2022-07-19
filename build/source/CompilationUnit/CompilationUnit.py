from os.path import isfile
from os import linesep
import os
import json
from glob import glob
import re

from CompilationUnitFile import CompilationUnitFile, CompilationUnitFileType

class CompilationUnit(object):
	def __init__(self, name):

		if isinstance(name,str):
			self.name = name
		elif isinstance(name,list):
			self.name = ".".join(name)
		else:
			raise ValueError(f"name must be str or list, not {type(name)}")
		
		if isfile(self.nameToJSONPath()):
			for key, value in self.getJSONDict().items():
				if key == "dependencyList":
					self.dependencyList = [CompilationUnit(dependency) for dependency in value]
				else:
					setattr(self, key, value)
		else:
			outDict = dict()
			outDict["hasInclude"] = True
			outDict["name"] = self.name
			for key, value in outDict.items():
				setattr(self, key, value)

	def getJSONDict(self):
		with open(self.nameToJSONPath()) as f:
			return json.load(f)

	def __repr__(self):
		middle = ",".join([f"{key}={value}" for key, value in self.__dict__.items()])
		return f"CompilationUnit({middle})"

	def __string__(self):
		middle = ",".join([f"{key}={value}" for key, value in self.__dict__.items()])
		return f"CompilationUnit({middle})"
	
	@classmethod
	def getJSONDir(cls):
		return os.path.join(".","build","source","CompilationUnit","compilationUnitData")

	def nameToJSONPath(self):
		return os.path.join(self.getJSONDir(), f"{self.name}.json")

	def getHeaderFile(self):
		return CompilationUnitFile(self, CompilationUnitFileType.HEADER)

	def getSourceFile(self):
		return CompilationUnitFile(self, CompilationUnitFileType.SOURCE)

	def getSharedFile(self):
		return CompilationUnitFile(self, CompilationUnitFileType.SHARED)

	def getStaticFile(self):
		return CompilationUnitFile(self, CompilationUnitFileType.STATIC)

	def getObjectFile(self):
		return CompilationUnitFile(self, CompilationUnitFileType.OBJECT)

	@classmethod
	def getAllNameObjects(cls):
		for file in glob(os.path.join(cls.getJSONDir(), "*.json")):
			yield CompilationUnit(os.path.basename(file)[:-5])

	def getUsedObjectsFromScan(self):
		for usedObject in self.getSourceFile().getUsedObjectList():
			yield usedObject
		for usedObject in self.getHeaderFile().getUsedObjectList():
			yield usedObject

	def getDependencyListFromScan(self):
		for nameObject in self.getAllNameObjects():
			for usedObject in self.getUsedObjectsFromScan():
				if usedObject in self.objectDefinitionList:
					continue
				else:
					if usedObject in nameObject.objectDefinitionList:
						yield nameObject

	def updateDependencyListFromScan(self, replace=False):
		scanDependencyList = self.getDependencyListFromScan()
		if replace:
			self.dependencyList = scanDependencyList
		else:
			self.dependencyList = set(self.dependencyList + scanDependencyList)

	def getDependencyListHeader(self):
		for dependency in self.getDependencyList():
			if getattr(dependency, "hasHeader", False):
				yield dependency

	def getDependencyListSource(self):
		for dependency in self.getDependencyList():
			if getattr(dependency, "hasSource", False):
				yield dependency

	def getDependencyList(self):
		for scanDependency in self.getDependencyListFromScan():
			if scanDependency.name in [dependency.name for dependency in self.__dict__.get("dependencyList",list())]:
				continue
			else:
				yield scanDependency
		for dependency in self.__dict__.get("dependencyList",list()):
			yield dependency
	
	def getFile(self, type):
		return {
			CompilationUnitFileType.HEADER : self.getHeaderFile(),
			CompilationUnitFileType.SOURCE : self.getSourceFile(),
			CompilationUnitFileType.OBJECT : self.getObjectFile(),
			CompilationUnitFileType.STATIC : self.getStaticFile(),
			CompilationUnitFileType.SHARED : self.getSharedFile(),
		}[type]

	def getMakefileDefinition(self, type):
		return self.getFile(type).getMakefileDefinition()

	def getMakefileFileName(self, type):
		return self.getFile(type).getMakefileFileName()