import CompilationUnit

if __name__ == "__main__":
	cuName = input("Compilation Unit, fuckwit?")
	cu = CompilationUnit.CompilationUnit(cuName)
	if cu.__dict__.get("newFlag",False):
		result = input("Do you wish to set up a new Compilation Unit, fuckwit?")
		if result.lower() in ["y","yes"]:
			
			print("Creating Header")
			headerFile = cu.getHeaderFile()
			print(f"{headerFile.getFileName()}\n{headerFile.getBoilerPlate()}\n\n")
			with open(headerFile.getFileName(), "w") as f:
				f.write(headerFile.getBoilerPlate())

			cuHasSourceInput = input("Got sauce mate?")
			if cuHasSourceInput.lower() in ["y","yes"]:
				print("Creating Source")
				sourceFile = cu.getSourceFile()
				print(f"{sourceFile.getFileName()}\n{sourceFile.getBoilerPlate()}\n\n")

				with open(sourceFile.getFileName(), "w") as f:
					f.write(sourceFile.getBoilerPlate())

			print("Creating Makefile")
			print(f"{headerFile.getMakefileFileName()}\n{headerFile.getMakefileDefinition()}\n\n")
			with open(headerFile.getMakefileFileName(), "w") as f:
				f.write(headerFile.getMakefileDefinition())
			
			if cuHasSourceInput.lower() in ["y","yes"]:
				print(f"{sourceFile.getFileName()}\n{sourceFile.getBoilerPlate()}\n\n")
				with open(sourceFile.getFileName(), "w") as f:
					f.write(sourceFile.getBoilerPlate())