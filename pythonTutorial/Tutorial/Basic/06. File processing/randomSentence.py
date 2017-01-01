import random
import sys

def wordLists():
	fN = open('Nouns.txt', 'r')
	fV = open('Verbs.txt', 'r')
	fP = open('Prepositions.txt', 'r')

	articles = ("A", "THE")
	nouns = []
	verbs = []
	preps = []

	for line in fN:
		nouns.append(line.strip().upper())

	for line in fV:
		verbs.append(line.strip().upper())

	for line in fP:
		preps.append(line.strip().upper())

	fN.close()
	fV.close()
	fP.close()

	return articles, nouns, verbs, preps

def sentence(articles, nouns, verbs, preps):
	return nounPhrase(articles, nouns) + " " + verbPhrase(verbs, articles, nouns, preps)

def nounPhrase(articles, nouns):
	return random.choice(articles) + " " + random.choice(nouns)

def verbPhrase(verbs, articles, nouns, prepo):
	return random.choice(verbs) + " " + nounPhrase(articles, nouns) + " " + prepositionalPhrase(prepo, articles, nouns)

def prepositionalPhrase(prepo, articles, nouns):
	return random.choice(prepo) + " " + nounPhrase(articles, nouns)

def main():
	n = sys.argv[1]
	articles, nouns, verbs, preps = wordLists()

	for i in range(int(n)):
		print sentence(articles, nouns, verbs, preps)
	

main()