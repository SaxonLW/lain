from os.path import isfile
from os import linesep
import json
from glob import glob

from CompilationUnitFile import CompilationUnitFile

def nameToJSONPath(name):
	return os.path.join(".","build","source","CompilationUnit","compilationUnitData", f"{name}.json")

class CompilationUnit(object):
    def __init__(self, name):
		if isfile(nameToJSONPath(name)):
			with open(nameToJSONPath(name)) as f:
				for key, value in json.load(f).items():
					setattr(self, key, value)
			