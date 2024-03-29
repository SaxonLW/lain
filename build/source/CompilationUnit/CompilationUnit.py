from os.path import isfile
from os import linesep
import os
import json
from glob import glob
import re

import CompilationUnitFile

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
			outDict["newFlag"] = True
			for key, value in outDict.items():
				setattr(self, key, value)

	def createJSON(self):
		with open(self.nameToJSONPath(), "w") as f:
			tmpDict = self.__dict__
			tmpDict.pop("newFlag",None)
			json.dump(tmpDict,f)
		return self
			

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
		return CompilationUnitFile.CompilationUnitFile(self, CompilationUnitFile.CompilationUnitFileType.HEADER)

	def getSourceFile(self):
		return CompilationUnitFile.CompilationUnitFile(self, CompilationUnitFile.CompilationUnitFileType.SOURCE)

	def getSharedFile(self):
		return CompilationUnitFile.CompilationUnitFile(self, CompilationUnitFile.CompilationUnitFileType.SHARED)

	def getStaticFile(self):
		return CompilationUnitFile.CompilationUnitFile(self, CompilationUnitFile.CompilationUnitFileType.STATIC)

	def getObjectFile(self):
		return CompilationUnitFile.CompilationUnitFile(self, CompilationUnitFile.CompilationUnitFileType.OBJECT)

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
				if usedObject in self.__dict__.get("objectDefinitionList",list()):
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
			if getattr(dependency, "hasInclude", False):
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
			CompilationUnitFile.CompilationUnitFileType.HEADER : self.getHeaderFile,
			CompilationUnitFile.CompilationUnitFileType.SOURCE : self.getSourceFile,
			CompilationUnitFile.CompilationUnitFileType.OBJECT : self.getObjectFile,
			CompilationUnitFile.CompilationUnitFileType.STATIC : self.getStaticFile,
			CompilationUnitFile.CompilationUnitFileType.SHARED : self.getSharedFile,
		}[type]()

	def getMakefileDefinition(self, type):
		return self.getFile(type).getMakefileDefinition()

	def getMakefileFileName(self, type):
		return self.getFile(type).getMakefileFileName()