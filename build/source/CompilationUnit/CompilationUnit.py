from os.path import isfile
from os import linesep
import json
from glob import glob

from CompilationUnitFile import CompilationUnitFile

class CompilationUnit(object):
    def __init__(self, name):
		self.name = name
		if isfile(self.nameToJSONPath(name)):
			for key, value in self.getJSONDict().items():
				setattr(self, key, value)
		else:
			outDict = dict()
			outDict["hasInclude"] = True
			outDict["name"] = self.name
			with open(self.nameToJSONPath(name), "w") as f:
				json.dump(outDict, f, indent="\t")
			for key, value in self.getJSONDict().items():
				setattr(self, key, value)

	def getJSONDict(self):
		with open(self.nameToJSONPath()) as f:
			return json.load(f)

	def nameToJSONPath(self):
		return os.path.join(".","build","source","CompilationUnit","compilationUnitData", f"{self.name}.json")

	def getHeaderFile(self):
		return CompilationUnitFile(name=self.name, dependencies=getattr(self,"dependencyList",None), ).getHeaderFile()

	def getSourceFile(self):
		return CompilationUnitFile(name=self.name, dependencies=getattr(self,"dependencyList",None), ).getSourceFile()

	def getSharedFile(self):
		return CompilationUnitFile(name=self.name, dependencies=getattr(self,"dependencyList",None), ).getSharedFile()

	def getStaticFile(self):
		return CompilationUnitFile(name=self.name, dependencies=getattr(self,"dependencyList",None), ).getStaticFile()