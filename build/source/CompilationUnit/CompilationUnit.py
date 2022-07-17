from sys import platform

class CompilationUnit(object):
    def __init__(self, name, dependencies):
        if isinstance(name,list):
            self.name = name
        elif isinstance(name,str):
            self.name = str.split(".")
        else:
            raise ValueError(f"Needs [list,str] not {type(name)}, fuckwit")
        
        for dependency in dependencies:
            if not(isinstance(dependency, CompilationUnit)):
                raise ValueError(f"Needs List[CompilationUnit] not {type(name)}, fuckwit")
        self.dependencies = dependencies

        if "linux" in platform:
            self.shared_ext = "so"
            self.static_ext = "a"
        elif platform == "darwin":
            self.shared_ext = "so"
            self.static_ext = "a"
        elif platform == "win32":
            self.shared_ext = "so"
            self.static_ext = "a"
        else:
            raise ValueError("Unsupported platform mate")
        return self
    
    def getHeaderFileName():
        if "headerFileName" in self:
            return self.headerFileName
        self.headerFileName = os.path.join(".","include", (".".join(self.name))+".h")
        return self.headerFileName
    
    def getSourceFileName():
        if "sourceFileName" in self:
            return self.sourceFileName
        self.sourceFileName = os.path.join(".","source", (".".join(self.name))+".c")
        return self.sourceFileName
    
    def getSharedFileName():
        if "sharedFileName" in self:
            return self.sharedFileName
        self.sharedFileName = os.path.join(".","shared", (".".join(self.name))+self.shared_ext)
        return self.sharedFileName
    
    def getStaticFileName():
        if "staticFileName" in self:
            return self.staticFileName
        self.staticFileName = os.path.join(".","static", (".".join(self.name))+self.static_ext)
        return self.staticFileName
