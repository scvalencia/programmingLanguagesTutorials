import sys

def dictHandler():
	fileObject = open('/usr/share/dict/words', 'r')
	lstWords = [line.strip() for line in fileObject.readlines()]
	return lstWords

def inputHandler():
	fileName = sys.argv[1]
	fileObject = open(fileName, 'r')
	return fileObject

def filterWrong(fileObject, seed):
	ans = []
	for line in fileObject:
		lst = line.strip().split()
		for item in lst:
			if item.lower() not in seed:
				ans.append(item)

	return ans


def main():
	seed = dictHandler()
	fileO = inputHandler()
	ans = filterWrong(fileO, seed)

	print ans

main()