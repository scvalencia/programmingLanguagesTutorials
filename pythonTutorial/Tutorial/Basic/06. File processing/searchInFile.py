import sys

def inputFile():
	name = sys.argv[1]
	word = sys.argv[2]
	fileObject = open(name, 'r')
	return fileObject, word

def fileHandler(fileObject, word):
	for line in fileObject:
			lst = line.split()
			if word in lst:
				print line[:len(line) - 1]

def main():
	fObject, word = inputFile()
	fileHandler(fObject, word)

main()

