import string
import random

def fileHandler(fileName):

	fileObject1 = open(fileName, 'r')
	fileObject2 = open('outputText.txt', 'w')

	for line in fileObject1:
		if not line.startswith('#'):
			a = line.strip(' ')
			for ch in string.punctuation:
				a = a.replace(ch, ' ')
			a = a.lower().strip()
			fileObject2.write(a + '\n')		

	fileObject1.close()
	fileObject2.close()

	fileObject2 = open('outputText.txt', 'r')
	
	
	freq = freqWords(fileObject2)

	return freq

	fileObject2.close()

def numWords(fileData):
	ans = 0
	for line in fileData:
		words = line.split()
		for word in words:
			ans += 1
	return ans

def freqWords(fileData):
	freq = {}
	for line in fileData:
		words = line.split()
		for word in words:
			freq[word] = freq.get(word,0) + 1
	return freq

def choose_from_hist(dct):
	a = random.choice(dct.keys())
	return a, dct[a]

def most_common(hist):
	t = []
	for key, value in hist.items():
		t.append((key, value))

	t.sort(reverse = True)
	return t

def main():
	dct = fileHandler('rainbow.txt')
	print choose_from_hist(dct)

	print 'The most common words are:'
	for freq, word in most_common(dct)[0:10]:
		print word, '\t', freq

	fileObject2 = open('outputText.txt', 'r')
	wc = numWords(fileObject2)
	fileObject2.close()

	print wc

main()