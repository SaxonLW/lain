from os.path import isfile
from os import linesep
import json

from CompilationUnit import CompilationUnit

class CompilationUnitFile(object):
    def __init__(self, fromSource=None, name=None, source=None, dependencies=None):
        if fromSource is not None:
            if isfile(fromSource):
                with open(fileSource) as f:
                    self = self.__init__(**json.load(f))
            elif isinstance(fromSource, dict):
                self = self.__init__(**fileSource)
            elif isinstance(fromSource,str):
                self = self.__init__(**json.loads(fromSource))
            elif isinstance(fromSource,CompilationUnitFile)
                self = fromSource
            else:
                raise ValueError("fromSource is unknown type")
            return self
        
        self.newLine = str(linesep)
        self.fileExtension = ""
        self.directory = ""
        
        if source is not None:
            if isinstance(source,str):
                if isfile(source):
                    with open(source) as f:
                        self.source = f.read()
                else:
                    self.source = source
        else:
            self.source = ""            
        
        if source is None:
            raise ValueError("source must not be None")
        elif isinstance(source,str):
            if isfile(source):
                with open(source) as f:
                    self.source = f.read()
            else:
                self.source = source
        else:
            raise ValueError(f"Unknown type for source, {type(source)}")
        
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
        
        return self
    
    def getFileName(self):
            return ".".join(name)
    
    def getDependencies(self):
        return self.dependencies
    
    def generateDependencies(self):
        for dependency in dependencies:
            yield dependency
    
    def getSource(self):
        return self.source
    
    def setSource(self, newSource:str):
        self.source = newSource
        return self
    
    def writeOut(self):
        pass