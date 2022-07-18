from os.path import isfile
from os import linesep
import json
from glob import glob

from CompilationUnit import CompilationUnit
from CompilationUnitHeaderFile import CompilationUnitHeaderFile
from CompilationUnitSharedFile import CompilationUnitSharedFile
from CompilationUnitSourceFile import CompilationUnitSourceFile
from CompilationUnitStaticFile import CompilationUnitStaticFile

class CompilationUnitFile(object):
    def __init__(self, fromSource=None, name=None, dependencies=None):
        if fromSource is not None:
            if isfile(fromSource):
                with open(fileSource) as f:
                    self.__init__(**json.load(f))
            elif isinstance(fromSource, dict):
                self.__init__(**fileSource)
            elif isinstance(fromSource,str):
                self.__init__(**json.loads(fromSource))
            elif isinstance(fromSource,CompilationUnitFile)
                fromSource
            else:
                raise ValueError("fromSource is unknown type")
        
        self.newLine = str(linesep)
        
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
    
    def getFileName(self):
        return ".".join(name)

	def scanForDependencies(self):
        raise NotImplementedError(f"{repr(self.scanForDependencies)} not overloaded")
    
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