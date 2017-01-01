import string
import random
import sys

def fileHandler(fileName):
	"""Reads a file, and handles the data.

	Reads the lines of a file, process them, in order to strip,
	remove the punctuation signs, and split it, creating a list
	of words from the file. It avoids try-catch expressions for
	readability.

	Args:
		fileName: The name of the file to handle

	Returns:
		A list of well formated words from the file. There's
		a one to one correspondence between the words in the file
		and the length of the list
	"""

	fileObject = open(fileName, 'r')
	words = []

	skipHeader(fileObject)

	for line in fileObject:
		nLine = line.strip().split()
		for word in nLine:
			words.append(removePunctuation(word.lower()))

	return words

def skipHeader(fileObject):
	"""Reads a project Gutenberg txt file, skips the header, and 
	   process it as expected.

	Reads a file named as the argument, skips over the Gutenberg header
	and process it.

	Args:
		fileName: The name of the file 

	"""

	for line in fileObject:
		line = line.strip().lower()
		if line.startswith('chapter'):
			break

def removePunctuation(word):
	"""Takes a string, and returns the string without
	   punctuation symbols

	Args:
		string: a string 

	Returns:
		A string without punctuation symbols
	"""

	ans = ""

	for ch in word:
		if ch in string.punctuation:
			continue
		ans += ch

	return ans

def histogram(lst):
	"""Makes a dictionary of frequencies of the values on a list.

	Args:
		lst: a list to be analyzed

	Returns:
		a dictionary of frequencies
	"""

	ans = {}

	for itm in lst:
		ans[itm] = ans.get(itm, 0) + 1

	return ans

def frequencies(histogram):
	"""Takes a dictionary and creates an items list from the
	   dictionarys items

	Args:
		h: a dictionary containing values of the frequency
		count of the text

	Returns:
		A sorted list of word, count tuples
	""" 
	t = []
	for key, value in histogram.items():
		t.append((value, key))

	t.sort()
	t.reverse()

	return t

def returnMostUsed(lst, fromTo = 20):
	"""Returns the fromTo'th most used words

	Args:
		lst: A sorted, reversed list of item tuples
		fromTo: size of output list

	Returns:
		A list of size fromTo + 1 with the most used words
		in the text
	"""
	ans = []

	for i in range(fromTo + 1):
		ans.append(lst[i])

	return ans

def wordDifferences(wordList, bookWords):
	"""Takes a word list, returns the difference between
	   both histogras

	Args:
		wordList: The list of words
		bookWords: The list of words in the book

	Returns: 
		A list containing words from the wordList that
		are not on bookWords
	"""
	h1 = histogram(wordList)
	h2 = histogram(bookWords)

	ans = []

	for item in h2:
		if item not in h1:
			ans.append(item)

	return ans

def randomWord(wordsList):
	#Selects a random word from the input list

	d = histogram(wordsList)
	k = d.keys()
	return random.choice(k)

def main():

	fileName = sys.argv[1]
	wordsList = fileHandler(fileName)
	hist = histogram(wordsList)
	wc = len(hist)
	del hist['']
	f = frequencies(hist)

	 


main()


