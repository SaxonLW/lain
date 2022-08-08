import CompilationUnit
import CompilationUnitInteger

def printBoilerPlateFile(file):
	if file.type in [CompilationUnit.CompilationUnitFileType.HEADER, CompilationUnit.CompilationUnitFileType.SOURCE]:
		print(f"{file.getFileName()}\n{file.getBoilerPlate()}\n\n")
		with open(file.getFileName(), "w") as f:
			f.write(file.getBoilerPlate())

def printMakefileFile(file):
	print(f"{file.getMakefileFileName()}\n{file.getMakefileDefinition()}\n\n")
	with open(file.getMakefileFileName(), "w") as f:
		f.write(file.getMakefileDefinition())
	
def scriptNewCompilationUnit():
	cuName = input("Compilation Unit, fuckwit?\n")
	cu = CompilationUnit.CompilationUnit(cuName)
	if cu.__dict__.get("newFlag",False):
		result = input("Do you wish to set up a new Compilation Unit, fuckwit?")
		if result.lower() in ["y","yes"]:
			
			print("Creating Header")
			headerFile = cu.getHeaderFile()
			printBoilerPlateFile(headerFile)

			cuHasSourceInput = input("Got sauce mate?")
			if cuHasSourceInput.lower() in ["y","yes"]:
				print("Creating Source")
				sourceFile = cu.getSourceFile()
				printBoilerPlateFile(sourceFile)

			printMakefileFile(headerFile)
			
			if cuHasSourceInput.lower() in ["y","yes"]:
				printMakefileFile(sourceFile)
				printMakefileFile(cu.getObjectFile())
				printMakefileFile(cu.getStaticFile())
				printMakefileFile(cu.getSharedFile())

def makeRefreshAll():
	for cu in CompilationUnit.CompilationUnit.getAllNameObjects():
		printMakefileFile(cu.getHeaderFile())
		if cu.__dict__.get("hasSource",False):
			printMakefileFile(cu.getSourceFile())
			printMakefileFile(cu.getObjectFile())
			printMakefileFile(cu.getSharedFile())
			printMakefileFile(cu.getStaticFile())

def makeRefreshOne():
	response = input("Which one mate\n")
	cu = CompilationUnit.CompilationUnit(response)
	printMakefileFile(cu.getHeaderFile())
	if cu.__dict__.get("hasSource",False):
		printMakefileFile(cu.getSourceFile())
		printMakefileFile(cu.getObjectFile())
		printMakefileFile(cu.getSharedFile())
		printMakefileFile(cu.getStaticFile())
	
	

if __name__ == "__main__":
	response = input("Whaddaya want?\n")
	if response.lower() == "new":
		scriptNewCompilationUnit()
	elif response.lower() == "make":
		response = input("\nOR\n".join(["refresh all","refresh one"]) + "\n")
		if response.lower() == "refresh all":
			makeRefreshAll()
		elif response.lower() == "refresh one":
			makeRefreshOne()
		else:
			print("dunno about that")
	elif response.lower() == "integer":
		response = input("What name\n")
		newInt = CompilationUnitInteger.CompilationUnitInteger(response)
		newInt.createFiles()
	else:
		print("dunno about that")