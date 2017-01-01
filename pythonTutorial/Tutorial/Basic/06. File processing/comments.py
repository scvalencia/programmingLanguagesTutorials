def fileHandler():
	name = raw_input("File name: ")
	fileObject = open(name, 'r')
	return fileObject

def printLines(fileObject):
	for line in fileObject:
		if line[0] == '#':
			print line[:len(line)-1]

printLines(fileHandler())