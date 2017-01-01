import random

hedges = ("Please tell me more.", "Many of my patients tell me that",
		  "Please continue.")

qualifiers = ("Why do you say that ", 
			  "You seem to think that ",
			  "Can you explain why ")

replacements = {"I": "you", "me": "you", "my": "your",
				"we": "you", "us": "you", "mine": "yours"}

def reply(sentence):
	prob = random.randint(1, 4)
	if prob is 1:
		return random.choice(hedges)
	else:
		return random.choice(qualifiers) + changePerson(sentence)

def changePerson(sentence):
	words = sentence.split()
	replyWords = []
	for word in words:
		replyWords.append(replacements.get(word, word))
	return " ".join(replyWords)

def main():
	print "Hi, I hope you arer well today."
	print "What can i do for you?"
	while True:
		sentence = raw_input(">> ")
		if sentence.lower() == 'quit':
			print "Bye!"
			break
		print reply(sentence)

main()
