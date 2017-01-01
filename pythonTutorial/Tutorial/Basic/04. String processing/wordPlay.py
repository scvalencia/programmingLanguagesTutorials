def more_than_20(fileData):
	for word in fileData:
		if len(word) >= 20:
			print word.strip()[:-1]

def has_no_e(string):
	return not('e' in string)

def list_has_no_e(fileData):
	length = 0
	numWithoutE = 0
	for word in fileData:
		length += 1
		if has_no_e(word):
			numWithoutE += 1

	return (numWithoutE*100) / length

def avoids(word, forbString):

	for ch in forbString:
		if ch in word:
			return False
	return True

def prompAvoids(fileData):
	avoids = raw_input(">>> ")
	ans = 0
	for word in fileData:
		if avoids(word, avoids):
			ans += 1
	return ans

def uses_only(word, requiredString):
	for ch in word.lower():
		if ch not in requiredString and ch != ' ':
			return False
	return True

def uses_all(word, requiredString):
	for ch in requiredString:
		if ch not in word:
			return False
	return True

def is_abecedarian(word):
	return list(word) == sorted(list(word))

def quantity_abecedarian(fileData):
	ans = 0
	for line in fileData:
		word = line.strip()
		if is_abecedarian(word):
			ans += 1
	return ans

def is_triple_double(word):
	i = 0
	quant = 0
	while i < len(word) - 1:
		if word[i] == word[i + 1]:
			quant += 1
			if quant == 3:
				return True
			i += 2
		else:
			quant = 0
			i += 1
	return False

def find_triple_double(fileData):
	for line in fileData:
		word = line.strip()
		if is_triple_double(word):
			print word

def is_palindromic(word):
	ans = ''
	for i in range(len(word)-1,-1,-1):
		ans += word[i]
	return ans == word

def find_palindromes(fileData):
	for line in fileData:
		word =line.strip()
		if is_palindromic(word):
			print word

def int_as_string(num):
	return str(num).zfill(6)

def is_pal_number(numAsStr):
	slip = numAsStr[2:]
	return slip == slip[::-1]

def test_nums():
	i =100000
	while i < 999999:
		intAsStr = int_as_string(i)
		if is_pal_number(intAsStr):
			print i
		i += 1

def str_fill(i, len = 2):
	return str(i).zfill(len)

def are_reversed(i, j):
	return str_fill(i) == str_fill(j,2)[::-1]

def num_instances(diff, flag = False):
	son = 0
	count = 0
	while True:
		mother = son + diff
		if are_reversed(son, mother):
			count += 1
			if flag:
				print son, mother
		if mother > 120: break
		son += 1
	return count

def check_diffs():
	diff = 20
	while diff < 50:
		n = num_instances(diff, True)
		if n > 0:
			print diff, n
			print 
		diff += 1

def main():
	'''fileObject = open('words.txt', 'r')
	find_palindromes(fileObject)
	fileObject.close()'''
	check_diffs()

main()