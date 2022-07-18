from os.path import isfile
from os import linesep
import os
import json
from glob import glob
import re

from CompilationUnitFileModule import CompilationUnitFile

class CompilationUnit(object):
	def __init__(self, name):

		if isinstance(name,str):
			self.name = name.split(".")
		elif isinstance(name,list):
			self.name = name
		else:
			raise ValueError(f"name must be str or list, not {type(name)}")
		
		if isfile(self.nameToJSONPath()):
			for key, value in self.getJSONDict().items():
				if key == "dependencyList":
					self.dependencyList = [CompilationUnit(dependency) for dependency in value]
				setattr(self, key, value)
		else:
			outDict = dict()
			outDict["hasInclude"] = True
			outDict["name"] = self.name
			with open(self.nameToJSONPath(), "w") as f:
				json.dump(outDict, f, indent="\t")
			for key, value in self.getJSONDict().items():
				setattr(self, key, value)

	def getJSONDict(self):
		with open(self.nameToJSONPath()) as f:
			return json.load(f)

	def getJSONDir(self):
		return os.path.join(".","build","source","CompilationUnit","compilationUnitData")

	def nameToJSONPath(self):
		return os.path.join(self.getJSONDir(), f"{'.'.join(self.name)}.json")

	def getHeaderFile(self):
		return CompilationUnitFile(name=self.name, dependencies=getattr(self,"dependencyList",None) ).getHeaderFile()

	def getSourceFile(self):
		return CompilationUnitFile(name=self.name, dependencies=getattr(self,"dependencyList",None) ).getSourceFile()

	def getSharedFile(self):
		return CompilationUnitFile(name=self.name, dependencies=getattr(self,"dependencyList",None) ).getSharedFile()

	def getStaticFile(self):
		return CompilationUnitFile(name=self.name, dependencies=getattr(self,"dependencyList",None) ).getStaticFile()

	def getAllNameObjects(self):
		for file in glob(os.path.join(self.getJSONDir(), "*.json")):
			with open(file) as f:
				tmp_dict = json.load(f)
				ret_dict = dict()
				ret_dict["name"] = tmp_dict["name"]
				ret_dict["objectDefinitionList"] = tmp_dict["objectDefinitionList"]
				yield ret_dict

	def getDependencyListFromScan(self):
		dependencyList = set()
		for file in [self.getSourceFile(), self.getHeaderFile()]:
			for match in re.finditer(r"([a-zA-Z0-9_])+", file.getSource()):
				for nameObject in self.getAllNameObjects():
					if match in nameObject["objectDefinitionList"]:
						dependencyList.add(nameObject["name"])
		return [CompilationUnit(dependency) for dependency in dependencyList]

	def updateDependencyListFromScan(self, replace=False):
		scanDependencyList = self.getDependencyListFromScan()
		if replace:
			self.dependencyList = scanDependencyList
		else:
			self.dependencyList = set(self.dependencyList + scanDependencyList)