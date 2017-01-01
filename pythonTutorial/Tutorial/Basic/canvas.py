import math
import string
import os
import os.path
import time
import sys
import random
import urllib
import re
from itertools import permutations

def quadraticRoot(a, b, c):
	discriminant = b * b - 4 * a * c
	denom = 2 * a
	x1 = (- b + math.sqrt(discriminant)) / denom 
	x2 = (- b - math.sqrt(discriminant)) / denom 
	return [x1, x2]

def iterativeFactorialA(n):
	ans = 1
	for i in range(1, n + 1):
		ans *= i
	return ans

def iterativeFactorialB(n):
	i = n
	ans = 1
	while(i > 0):
		ans *= i
		i -= 1
	return ans

def factorial():
	arg = 3.5
	while(type(arg) != int):
		arg = input("Please enter an integer: ")
	print iterativeFactorialA(arg)

def distance(x1,x2,y1,y2):
	sumA = (x2 - x1) ** 2
	sumB = (x2 - x1) ** 2

	return math.sqrt(sumA + sumB)
def absoluteValue(c):
	r = c.real ** 2
	i = c.imag ** 2
	if(type(c) == complex):
		print "The absolute value of %.2f + %.2fi is %.2f" % (c.real, c.imag, math.sqrt(r + i))
	else:
		print "The absolute value of %.2f is %.2f" % (c, math.sqrt(r + i))

def sum():
	n = 8.9
	while(type(n) != int):
		n = input("Enter an integer number: ")
	ans = 0
	for i in range(n + 1):
		ans += i
	print ans

def sumOfNumbers():
	n = input("How many numbers do you want to add? ")
	sum = 0
	for i in range(1, n + 1):
		a = input("Introduce the %d number: " %(i))
		sum += a
	print sum

def piAprox():
	n = 8.9
	pivot = 1
	sum = 0
	while(type(n) != int):
		n = input("Enter the number of elements in the sum: ")
	for i in range(1, n * 2):
		if(i % 2 != 0):
			if(pivot % 2 != 0):
				sum += float(4 / i)
				pivot += 1
			else:
				sum -= float(4 / i)
				pivot += 1
	return float(sum)

def iterativeFib(n):
	a, b, c = 0, 1, 0
	while(c < n):
		a, b, c = b, a + b, c + 1
	return b

def heron(number, guess):
	if(guess * guess == number):
		return guess
	else:
		return heron(number, ((guess  + (number / guess)) / 2))

def type_filter(list, instanceOfType):
	new_list = []
	for i in range(len(list) - 1):
		a = list[i]
		if type(a) == type(instanceOfType):
			new_list.append(str(a))
	return new_list

def stringExplorationsUsingQuotes():
	ShannonQuote = "Information: the negative reciprocal value of probability."
	AbelsonQuote = "Programs must be written for people to read, and only incidentally for machines to execute."
	print ShannonQuote[0]
	print ShannonQuote[0:12]
	print ShannonQuote + " " + AbelsonQuote
	for ch in AbelsonQuote:
		if ch == ShannonQuote[9]:
			print "Upalaluppa"
	print ShannonQuote * 3
	print len(AbelsonQuote)

def sillyCripto():
	pas = "POINCARE"
	n = raw_input("Please introduce the password: ")
	if(n == pas):
		sumOfNumbers()
	else:
		print "Wrong password"
		sillyCripto()

def usernameSuggestion():
	name = raw_input("Introduce your name: ")
	blank = 0
	for i in range(len(name)):
		if(name[i] == ' '):
			blank = i
	print name[0] + name[blank + 1:blank + 8]

def monthAbb():
	months="JanFebMarAprMayJunJulAugSepOctNovDec"
	n = 13
	while(n > 12 or n < 1):
		n = input("Introduce a number 1-12: ")
	pos = (n - 1) * 3
	print months[pos:pos + 3] 

def stringConstants():
	print string.ascii_lowercase
	print string.ascii_uppercase
	print string.ascii_letters
	print string.digits
	print string.punctuation
	print string.printable

def validPassword():
	print("Welcome to your password checker v0.01b")
	pas = raw_input("Introduce a valid password (just letters): ")
	for ch in pas:
		if ch in string.letters:
			continue
		else:
			print "Invalid password"
			break

def ASCIIencoder():
	msg = raw_input("Introduce the message: ")
	for ch in msg:
		print ord(ch),

def ASCIIdecoder():
	msg = raw_input("Introduce the message: ")
	message = ""
	for num in string.split(msg):
		asciiNum = int(num)
		message += chr(asciiNum)
	print message

def caesarEncoder():
	plainText = raw_input("Introduce a message: ")
	distance = input("Introduce the shift value: ")
	code = ""
	for ch in plainText:
		ordValue = ord(ch)
		cipherValue = ordValue + distance
		code += chr(cipherValue)
	print code

def caesarDecoder():
	plainText = raw_input("introduce the plain text: ")
	distance = input("Introduce the shift value: ")
	code = ""
	for ch in plainText:
		ordValue = ord(ch)
		cipherValue = ordValue - distance
		code += chr(cipherValue)
	print code

def fileReading():
	fname = open("file.txt", 'r')
	print fname.readline(), fname.readline()

def fileCreation():
	fname = open("report.txt", 'w')
	fname.write("This is a TalkGround report\n")
	fname.close()

def batchUsernames():
	inFile = raw_input("Introduce the name of the input file: ")
	ouFile = raw_input("Introduce the name of the output file: ")
	iarch = open(inFile, 'r')
	oarch = open(ouFile, 'w')
	for line in iarch:
		first, last = string.split(line)
		uname = string.lower(first[0] + last[:7])
		ouFile.write(uname + '\n')
	iarch.close()
	oarch.close()

def FleschIndex():
	fileName = raw_input("Introduce the name of the file: ")
	nSentences = 0
	nWords = 0
	nSyllables = 0
	FleschI = 0
	GradeLevel = 0
	'''
		Word: Any sequence of non-whitespace characters
		Sentence: Any sequence of words ending in a pediod, colon
				  or semicolon.
	 	Syllable: Any word of 3 characters or less; or any vowel or pair
	 			  of consecutive vowels, except for a final -es, -ed or -e
	 			  that is not -le
	'''
	inputFile = open(fileName, 'r')
	text = inputFile.read()
	nSentences = text.count('.') + text.count(',') + text.count(';') + text.count('?') +text.count('!')
	nWords = len(text.split())
	for word in text.split():
		for vowel in ['a', 'e', 'i', 'o', 'u']:
			nSyllables += word.count(vowel)
		for ending in ['es', 'ed', 'e']:
			if word.endswith(ending):
				nSyllables -= 1
		if word.endswith('le'):
			nSyllables -= 1

	FleschI = 206.835 - 1.015 * (nWords / nSentences) - 84.8 * (nSyllables / nWords)
	GradeLevel = int(round(0.39 * (nWords / float(nSentences)) + 11.8 * (nSyllables / float(nWords)) - 15.59))

	print "The Flesch index is: ", FleschI
	print "Te grade level equivalent is ", GradeLevel
	print nSentences, "sentences"
	print nSyllables, "syllables"
	print nWords, "words"

def acronym():
	p = raw_input("Introduce a string: ")
	words = string.split(p)
	o = ''
	for i in words:
		if (len(i) > 3):
			o+= i[0].upper()
	print o

def numerologistTool():
	name = raw_input("Introduce your name: ")
	sum = 0
	nameL = string.split(name)
	for word in nameL:
		for letter in word:
			sum += (ord(letter) - 96)
	print sum

def nl():
	fileName = raw_input("Introduce the name of the file: ")
	txtO = open(fileName, 'r')
	txt = txtO.read()
	lines = string.split(txt, '\n')
	print len(lines)

def wc():
	fileName = raw_input("Introduce the name of the file: ")
	f = open(fileName, 'r')
	text = f.read()
	wordsList = string.split(text)
	linesList = string.split(text, '\n')
	char = 0
	for item in wordsList:
		for ch in item:
			char += 1
	print ("%10s%10s%10s%10s") %(len(linesList) - 1, len(wordsList), char, fileName)

def copyFile(): #Lambert 4.p8
	inFile = raw_input("Introduce the file to be copied: ")
	ouFile = raw_input("Introduce the destination file: ")
	inp = open(inFile,'r')
	out = open(ouFile,'w')
	out.write(inp.read())
	inp.close()
	out.close()

def sameFile():
	inFile = raw_input("Introduce a file to compare: ")
	ouFile = raw_input("Introduce a file to be compared: ")
	inp = open(inFile,'r')
	out = open(ouFile,'r')
	if(inp.read() == out.read()):
		print 'YES'
	else:
		print 'NOT'

def printName(firstName, lastName, reverse = False):
	if reverse:
		print lastName + ',' + firstName
	else:
		print firstName, lastName
	#printName('Sebastian', 'Valencia', True)
	#printName('Sebastian', 'Valencia')

def findRoot(x, power, epsilon):
	""" x:int, float; epsilon:int, float; power:int,
		epsilon > 0 & power >= 1
	returns float y | y ** power - epsilon = x
		if such y don't exists, it returns None """
	if x < 0 and power%2 == 0:
		return None
	low = min(-1.0, x)
	high = max(1.0, x)
	ans = (low + high) / 2.0
	while abs(ans**power - x) >= epsilon:
		if ans**power < x:
			low = ans
		else:
			high = ans
		ans = (high + low) / 2.0
	return ans

def testFindRoot():
	epsilon = 0.0001
	for x in (0.25, -0.25, 2, -2, 8, -8):
		for power in range(4):
			print 'Testing x = ' + str(x) + ' and power = ' + str(power)
			res = findRoot(x, power, epsilon)
			if res:
				print '   ' + str(res ** power) + '~=' + str(x)
			else:
				print '    No root'

def index_and_value(list):
	flag = 5
	for i in range(len(list)):
		if list[i] == flag:
			return i, flag

# ----------------------------------------
def displayRangeIterative(lower, upper):
	while (lower <= upper):
		print lower
		lower += 1

def displayRangeRecursive(lower, upper):
	if lower <= upper:
		print lower
		displayRangeRecursive(lower + 1, upper)

def recursiveSum(low, upp):
	if low > upp: 
		return 0
	else: 
		return low + recursiveSum(low + 1, upp)

def iterativeSum(low, upp):
	"""
		Arguments: A lower bound and a upper bound
		Returns: The sum of numbers between arguments inclusive
	"""
	ans = 0
	while low <= upp:
		ans += low
		low += 1
	return ans

def recursiveSumWithTrace(low, upp, margin):
	blanks = " " * margin
	print blanks, low, upp
	if low > upp: 
		print blanks, 0
		return 0
	else: 
		res = low + recursiveSumWithTrace(low + 1, upp, margin + 4)
		print blanks, res
		return res

def recursiveFactorial(n):
	if n == 1:
		return n
	else:
		return n * recursiveFactorial(n - 1)

def fibo1(n):
	fibs = [0, 1]
	for i in range(n):
		fibs.append(fibs[-2] + fibs[-1])
	return fibs

def fibo2(n):
	if n in [0,1]:
		return 1
	else:
		return fibo2(n - 1) + fibo2(n - 2)

def isPalindrome(s):

	"""	Asumes s is a string
		Returns True if s is a palindrome, False otherwise
		Punctuation marks, blanks and capitalizations are ignored. """

	def toChar(s):
		s = s.lower()
		ans = ''
		for c in s:
			if c in string.ascii_lowercase:
				ans += c
		return ans

	def isPal(s):
		if len(s) <= 1:
			return True
		else:
			return s[0] == s[-1] and isPal(s[1:-1])
	return isPal(toChar(s))

def print_current_directory():
	s = os.getcwd()
	print "Current working directory: " + s

def time_execution(code):
	# Code must be a string
	start = time.clock()
	result = eval(code)
	run_time = time.clock() - start
	return result, run_time

def centeredText():
	sentence = raw_input("Sentence >> ")
	screen_width = 80
	text_width = len(sentence)
	box_width = text_width + 6
	left_margin = (screen_width - box_width) // 2
	print 
	print ' ' *  left_margin + '+'   + '-' * (box_width - 2) +   '+'
	print ' ' *  left_margin + '|  ' + ' ' * text_width      + '  |'
	print ' ' *  left_margin + '|  ' +       sentence        + '  |'
	print ' ' *  left_margin + '|  ' + ' ' * text_width      + '  |'
	print ' ' *  left_margin + '+'   + '-' * (box_width - 2) +   '+'
	print

def basicPQM():
	database = [
		['albert',  '1234'],
		['dilbert', '4242'],
		['smith',   '7383'],
		['jones',   '9874']
	]
	MENU = """Welcome to PQM (Python Query Manager):
			  1. CONSULT
			  2. ADD
			  3. SEARCH
			  4. QUIT"""

	def main():
		command = 7
		while command != 4:
			print MENU
			command = input("Introduce the command:")
			runCommand(command)

	def runCommand(cmd):
		if cmd == 1:
			consult()
		elif cmd == 2:
			add()
		elif cmd == 3:
			search()

	def consult():
		print database

	def add():
		username = raw_input("Introduce the username: ")
		PIN = raw_input("Introduce the PIN: ")
		if [username, PIN] not in database:
			database.append([username, PIN])
		else:
			print "Not valid username. "

	def search():		
		username = raw_input("Introduce the username: ")
		PIN = raw_input("Introduce the PIN: ")
		if [username, PIN] in database:
			print "You are in the DB."
		else:
			print "Not found."

	main()

def namesLibrary():
	# A simple database

	# A dictionary with persons names as keys. Each person is represented as
	# another dictionary with the keys 'phone' and 'adr' referring to their
	# phone number and adress, respectively

	people = {
		'Alice' : {
			'phone':'2341',
			'addr':'Foo drive 23'
		},

		'Beth' : {
			'phone':'9012',
			'addr':'Bar street 42'
		},

		'Cecil' : {
			'phone':'3158',
			'addr':'Baz avenue 90'
		}
	} 

	# Desciptive labels for the phone number and adress. These will be used
	# when printing the output

	labels = {
		'phone':'phone number',
		'addr':'adress'
	}
	name = raw_input('Name: ')

	# Are we looking for the phone number, or the adress?
	request = raw_input('Phone number (p) or adress (a)? ')

	if request == 'p': 
		key = 'phone'
	if request == 'a': 
		key = 'addr'
	if name in people:
		print "%s's %s is %s." % \
			(name, labels[key], people[name][key])

def stringSubstitution():
	template = ''' 
				<html><head><title>%(title)s</title></head>
				<body>
				<h1>%(title)s</h1>
				<p>%(text)s</p>
				</body>
			'''
	data = {'title':'My home page', 'text': 'Welcome to my home page'}
	return template % data

def hexToBinary(number):
	""" 
		Builds and returns the base two representation of
		number.
	"""
	table = {
						'0':'0000', '1':'0001', '2':'0010',
						'3':'0011', '4':'0100', '5':'0101',
						'6':'0110', '7':'0111', '8':'1000',
						'9':'1001', 'A':'1010', 'B':'1011',
						'C':'1100', 'D':'1101', 'E':'1110',
						'F':'1111'

			}

	binary = ''
	for digit in number:
		binary += table[digit]
	return binary
def average(*args):

	summation = 0.0
	length = len(args)
	for arg in args:
		summation += arg
	return summation / length

def parse_polynomial(a,b,c):
	return str(a) + "(x*x)+" + str(b) + "x+" + str(c)

def quadraticRootParsing(a,b,c):

	if (type(a) == int and type(b) == int and type(c) == int):
		string = parse_polynomial(a,b,c)
		print "POLYNOMIAL: ", string

	print "SOLUTION: ", quadraticRoot(a,b,c)

def evaluate_pol(a,b,c):
	dic = {'aa' : a, 'bb' : b, 'cc' : c}
	string = '%(aa)s(x*x)+%(bb)sx+%(cc)s'
	return string % dic

def nested_file_list():
	f = open('alkaline_metals.txt', 'r')
	l = []
	for line in f:
		a = line.split()
		l.append(map(float,a))
	f.close()
	return l

def print_patternA(n):
	b = '*'
	c = ' '
	for i in range(1,n+1):
		for j in reversed(range(n+1)):
			print b * i, j * c
			break

def print_patternB(n):
	b = '*'
	c = ' '
	for i in reversed(range(1,n+1)):
		for j in range(n+1):
			print b * i, j * b
			break

def print_patternC(n):
	for i in range(1, n + 1):
		print ' ' * (n - i) + '*' * i

def print_patternD(n):
	for i in range(1, n + 1):
		print '*' * i + ' ' * (n - i)

def print_patternE(n):
	i = 1
	while i < (n + 1):
		print '*' * i + ' ' * (n - i)
		i += 1

def print_patternF():
	ancho = input("Enter width: ")
	alto = input("Enter height: ")
	for i in range(alto):
		if i == 0 or i == (alto - 1):
			print '@' * ancho
		else:
			print '@' + ' ' * (ancho - 2) + '@'

def nCm(n,m):
	if m == 0 or m == n:
		return 1
	else:
		return nCm(n-1,m) + nCm(n-1,m-1)

def expTaylor():
	e = 0.0
	for i in range(10):
		e += i/iterativeFactorialA(i)
	return e

def asterix_triangleR(i, t=0):
    if i == 0:
        return 0
    else:
        print ' ' * ( i + 1 ) + '*' * ( t * 2 + 1)
        return asterix_triangle(i-1, t + 1)

def asterix_triangleI(depth):
        rows = [ (depth-i)*' ' + i*'*' + '*' + i*'*'  for i in range(depth) ]
        for j in rows:
            print j

def upside_down_asterix_triangle(i, t=0):
    if i == 0:
        return 0
    else:
        print ' ' * ( t + 1 ) + '*' * ( i * 2 - 1 )
        return upside_down_asterix_triangle( i - 1, t + 1 )

def squareMatrix(n):
	data = [None] * n
	for i in range(0,n):
		data[i] = [0] * n
	return data

def printSquareMatrix(matrix):
	for i in matrix:
		print i

def triangleArea(a,b,c):
	s = sum([a,b,c])/2
	A = math.sqrt(s*(s-a)*(s-b)*(s-c))
	return A

def piTaylor(n):
	pos = 0
	neg = 0
	for i in range(1,n,4):
		pos += (4./i)
	for i in range(3,n,4):
		neg += (4./i)
	return pos - neg

def collatz(n):
	print n
	while n != 1:
		if n % 2 == 0:
			n = n / 2
		else:
			n = (3*n) + 1
		print n

def isPrime(n):
	if n == 1: return False
	if n < 3:
		return True
	for i in range(2, int(math.sqrt(n)) + 1):
		if n % i == 0:
			return False
	return True

def primeList(n):
	a = list()
	for i in range(n+1):
		if isPrime(i):
			a.append(i)
	return a

def goldbach(n):
	if n % 2 == 1:
		return -1
	else:
		a = primeList(n)
		for it in a:
			b = n - it
			if b in a:
				return b, it

def iterativeGCD(m,n):
	while m:
		m, n = n % m, m
	return n

def innerProd(x,y):
	if len(x) != len(y):
		return -1
	else:
		ans = 0
		for i in range(len(a)):
			ans += x[i] * y[i]
		return ans

def removeDuplicates(l):
	a = l
	for i in a:
		b = a.count(i)
		if b > 1:
			a.remove(i)
	return a

def sieveOfEratosthenes(n):
	lst = range(2,n+1)
	primes = []
	while lst != []:
		first = lst[0]
		lst.remove(first)
		primes.append(first)
		for i in lst:
			if i % first == 0:
				lst.remove(i)
	return primes

def sorting(lst):
	# print sorted(lst)
	# lst.sort(), sorts the list using basic 
	# comparation operations on the type

	# As an alternative, sort() method can accept as an argument
	# a comparision function, that is a function that takes two
	# arguments, and return a negative value if the first is smaller,
	# zero if are equal, and a positive value if the first is larger

	def smallerThan(x, y):
		if x < y: return 1
		if x == y: return 0
		return -1
	
	def compareIndexOne(x, y):
		if x[0] < y[0]: return -1
		if x[0] == y[0]: return 0
		return 1
	lst.sort(compareIndexOne)
	#sorting([[1,7],[3,5],[2,6]]) ==> [[1, 7], [2, 6], [3, 5]]
	return lst

def stringology(string):
	print string.capitalize()
	print string.count('a')
	print string.find('c')
	print string.index('b')
	print string.rfind('a')
	print string.rindex('b')
	print string.lower()
	print string.split()
	print string.join('a')
	print string.strip()
	print string.upper()
	print string.replace('b','v')
	print list(string)

def diceSim():
	lst = [0] * 13
	for i in range(1000):
		a = random.randint(1,6)
		b = random.randint(1,6)
		add = a + b
		lst[add - 1] += 1
	print lst

def printMatrix(mat):
	for i in mat:
		for j in i:
			print str(j) + ' ',
		print ''

def randomWalk(n):
	if n % 2 == 0: print 'n is even'
	else:
		a = []
		for i in range(n):
			a.append([0] * n)
		mid = (n / 2)
		row = mid
		col = mid
		a[row][col] = '*'		

		
		while(True):

			move = random.randint(1,4)

			if (move == 1 and col >= 0 and a[row][col - 1] == 0):
				col -= 1
				a[row][col] = '*'
				continue
				
			if (move == 2 and row >= 0 and a[row - 1][col] == 0):
				row -= 1
				a[row][col] = '*'
				continue
				
			if (move == 3 and col <= n and a[row][col + 1] == 0):
				col -= 1
				a[row][col] = '*'
				continue
				
			if (move == 4 and row <= n and a[row + 1][col] == 0):
				row += 1
				a[row][col] = '*'
				continue
			break
		
		printMatrix(a)

def print_grid():
	head = '+' + '-' * 5 + '+'
	body = '|     |'
	print head, head
	for i in range(3):
		print body, body
	print head, head
	for i in range(3):
		print body, body
	print head, head

def ack(m, n):
	ans = 0
	if (m is 0): ans = n + 1
	if (m > 0 and n is 0): return ack(m - 1, 1)
	elif (m > 0 and n > 0): return ack(m - 1, ack(m, n - 1))
	return ans

def abs(x):
	if x < 0: 
		return -x
	else:
		return x

def ramanujanPi():
	const = (2 * math.sqrt(2)) / 9801
	add = 0.0
	k = 0
	while(k < 10):
		num = iterativeFactorialA(4*k) * (1103 + (26390)*k)
		den = iterativeFactorialA(k) ** 4 * 396**(4*k)
		add += (num / den)
		k += 1

	result = const * add

	return 1/result

def rot13(chrChain, shift = 13):
	ans = ''
	for ch in chrChain:
		c = ord(ch)
		if c >= ord('a') and c <= ord('z'):
			if c > ord('m'):
				c -= shift
			else:
				c += shift
		elif c >= ord('A') and c <= ord('Z'):
			if c > ord('M'):
				c -= shift
			else:
				c += shift
		ans += chr(c)
	return ans

def rotate_letter(letter, n):
    if letter.isupper():
        start = ord('A')
    elif letter.islower():
        start = ord('a')
    else:
        return letter

    c = ord(letter) - start
    i = (c + n) % 26 + start
    return chr(i)

def isSorted(l):
	for i in range(len(l) - 1):
		if l[i] <= l[i + 1]:
			pass
		else:
			return False
	return True

def isAnagram(a,b):
	aLst = []
	bLst = []
	for i in a:
		aLst.append(i.lower())
	for i in b:
		bLst.append(i.lower())
	aLst.sort()
	bLst.sort()
	if aLst == bLst:
		return True
	return False

def funnyMap(l1,l2):
	return map(min,l1,l2)

def printDiamond():
	j = 3
	i = 1
	while(j >= 0):
		print ' ' * j + '*' * i
		j -= 1
		i += 2
	p = 1
	o = 3
	while(p <= 3):
		print ' ' * p + '*' * o
		p += 1
		o -= 1

def heinold():

	def automatedLearning():
		for i in range(10):
			a = random.randint(1,10)
			b = random.randint(1,10)
			c = a * b
			mul = input('Question %d : %d x %d = ' %(i+1, a, b))
			if mul == c:
				print 'Right!'
			else:
				print 'Wrong. The answer is %d.' %c
	# In order to swap, one can use x, y = y, x
	
	def funnyP():
		c = [1]
		b = map(lambda x : str(x*x), range(1,100))
		for i in b[3:]: 
			if i[-1] == '1': 
				c.append(int(i))
		return c
	
	def funnyO():
		c = [4]
		n = [9]
		b = map(lambda x : str(x*x), range(1,100))
		for i in b[3:]: 
			if i[-1] == '4': 
				c.append(int(i))
			if i[-1] == '9':
				n.append(int(i))
		return len(c), len(n)

	def funnySum():
		n = input('n>> ')
		add = 1.0
		for i in range(1,n+1):
			add += 1.0/n
		print add - math.log(n)

	def divisorSum():
		# http://en.wikipedia.org/wiki/Divisor_function
		n = input('n>> ')
		su = 0
		for i in range(1,n):
			if n % i == 0:
				su += i
		return su

	def perfectNumber(n):
		add = 0
		for i in range(1,n):
			if n % i == 0:
				add += i
		if add == n:
			return True
		return False

	def funnn():
		n = input()
		i = 0
		while(i < n):
			print ' ' * i, (i + 1)
			i += 1

	def squareWord():
		string = raw_input()
		for ch in string:
			print ch * len(string)

def dictionary():
	def freq(lst):
		count = dict()
		for item in lst:
			count[item] = count.get(item,0) + 1
		return count

	def graphicHistogram(dct):
		for k in dct:
			print k, '*' * dct[k]

	def unique(lst):
		ans = []
		for i in lst:
			a = lst.count(i)
			if (a > 1 and i not in ans):
				ans.append(i)
			elif (a == 1):
				ans.append(i)
			else:
				continue
		return ans

	def find_dups(lst):
		ans = []
		for i in lst:
			a = lst.count(i)
			if (a >= 2 and i not in ans):
				ans.append(i)
			else:
				continue
		return ans

	def count_values(dct):
		ans = []
		for itm in dct.values():
			a = dct.values().count(itm)
			if (itm not in ans):
				ans.append(itm)
		return len(ans)

	def dict_intersect(done, dtwo):
		ans = []
		a = done.items()
		b = dtwo.items()
		for i in range(max(len(a), len(b))):
			if a[i] in b:
				ans.append(a[i])
		return ans

def sparse_vector():
	# [1,0,0,0,0,0,3,0,0,0] ==> {0:1,6:3}
	def sparse_add(sp1, sp2):
		ans = {}
		l1 = sp1.keys()
		l2 = sp2.keys()
		lst = removeDuplicates(l1 + l2)
		for k in lst:
			ans[k] = ans.get(k,0) + sp1.get(k,0) + sp2.get(k,0)
		return ans

	a = {0:1,6:3,9:14}
	b = {0:2,1:3,7:9,9:6}

	print sparse_add(a,b)

def foodDataBase():
	d = {}
	ipt = raw_input()
	line = ipt.split()
	while len(line) > 1:
		d[line[0]] = line[1]
		ipt = raw_input()
		line = ipt.split()
	query = raw_input(">> ")
	while query != 'QUIT':
		print query, d[query]
		query = raw_input(">> ")

def passManager():
	d = {'scvalencia': '.2,a2771993', 'cata11':'camila123'}
	user = raw_input("USERNAME: ")
	if user not in d:
		print "Wrong username"
	else:
		pas = raw_input("PASSWORD: ")
		if d[user] == pas:
			print "WELCOME"
		else:
			print "WRONG PASSWORD"

def teamStatistics():

	def print_dict(d):
		print d

	def percentage_win(d):
		enter = raw_input("Team: ")
		if enter not in d:
			print 'The team is not registred.'
		else:
			add = d[enter][0] + d[enter][1]
			win = d[enter][1]
			return (win * 100) // (add + 0.0)

	def num_wins(d):
		for k in d:
			print k, d[k][0]
	
	def main():
		d = {}
		query = raw_input()
		line = query.split()
		while(line[0] != 'quit'):
			a = list(line[1])
			b = []
			b.append(int(a[1]))
			b.append(int(a[3]))
			d[line[0]] = b
			query = raw_input()
			line = query.split()
		print_dict(d)
		print percentage_win(d)
		num_wins(d)

	main()

def funnyMat():
	print
	lst = [[1,5,3,2,6], [3,6,2,5,2], [4,2,5,1,5], [4,2,5,6,2], [2,5,3,6,2]]
	d = {}
	for col in lst:
		for row in col:
			d[row] = d.get(row, 0) + 1
	printMatrix(lst)	
	print
	print d

def print_url_file():
	url = 'http://www.census.gov/population/estimates/nation/popclockest.txt'

	web_content = urllib.urlopen(url)
	for line in web_content:
		print line
	web_content.close()

#if __name__ == "__main__":
	#funnyMat()


def concatFile():

	for itm in sys.argv[1:-1]:
		fileObject = open(itm, 'r')
		text = fileObject.readlines()
		outFile = open(sys.argv[-1], 'a')
		outFile.writelines(text)
		outFile.close()
		fileObject.close()
	
def stringSearching():

	fileObject = open(sys.argv[1], 'r')
	for line in fileObject:
		words = line.split()
		if sys.argv[2] in words:
			print line
	fileObject.close()

def scoresFile():

	fileObject1 = open('class_scores.txt', 'r')
	fileObject2 = open('scores2.txt', 'w')

	for line in fileObject1:
		nLine = line.strip().split()
		n = int(nLine[1])
		fileObject2.write(nLine[0] + " " + str(n + 5) + '\n')

	fileObject1.close()
	fileObject2.close()

def whoPass():

	fileObject = open('grades.txt', 'r')

	for line in fileObject:
		nLine = line.strip().split()
		g1, g2, g3 = int(nLine[1]), int(nLine[2]), int(nLine[3])
		if g1 >= 60 and g2 >= 60 and g3 >= 60:
			print nLine[0]

	fileObject.close()

def nameInitials():

	n = raw_input("Initials: ")
	n = n.lower()
	fileObject = open('namelist.txt', 'r')
	twoWords = []
	threeWords = []

	for line in fileObject:
		nLine = line.strip().lower().split()
		if len(nLine) == 2:
			twoWords.append(nLine)
		else:
			threeWords.append(nLine)

	if len(n) == 2:
		for itm in twoWords:
			s = ""
			for l in itm:
				s += l[0]
			if s == n:
				print (itm[0] + " " + itm[1]).title()

	else:
		for itm in threeWords:
			s = ""
			for l in itm:
				s += l[0]
			if s == n:
				print (itm[0] + " " + itm[1] + " " + itm[2]).title()

	fileObject.close()

def sortedVowels():
	fileObject = open('namelist.txt', 'r')
	startsWa = []

	for line in fileObject:
		nLine = line.strip().lower()
		dLine = nLine.replace(" ", "")
		if dLine.startswith('a'):	
			if 'e' in dLine and 'i' in dLine and 'o' in dLine and 'u' in dLine:
				if dLine.index('e') < dLine.index('i') and \
				dLine.index('i') < dLine.index('o') and dLine.index('o') < dLine.index('u'):
					print line[:len(line) - 1]		

	fileObject.close()

def wordListExercise(): # 12.5.10 in Heinold

	fileObject = open('wordlist.txt', 'r')

	def a(fileObject):
		ans = []
		for itm in fileObject:
			line = itm.strip()
			if len(line) > 2:
				if line[-3:] == 'ime':
					print itm[:len(itm) - 1]

	def b(fileObject):
		ans = []		
		for itm in fileObject:
			line = itm.strip()
			if len(line) > 2:
				if line[:3] == 'ave':
					print itm[:len(itm) - 1] 

	def c(fileObject):
		count = 0		
		for itm in fileObject:
			line = itm.strip()
			if 'r' in line or 's' in line or 't' in line or \
			'l' in line or 'n' in line or 'e' in line:
				count += 1
				continue 

		print count 
		#return count

	def d(fileObject):
		size = 0		
		for itm in fileObject:
			size += 1
		print (40416 * 100) / (size + 0.0), "%"

	def e(fileObject):
		for itm in fileObject:
			if 'a' not in itm:
				if 'e' not in itm:
					if 'i' not in itm:
						if 'o' not in itm:
							if 'u' not in itm:
								print itm[:len(itm) - 1]

	def f(fileObject):
		for itm in fileObject:
			if 'a' in itm:
				if 'e' in itm:
					if 'i' in itm:
						if 'o' in itm:
							if 'u' in itm:
								print itm[:len(itm) - 1]

	def g(fileObject):
		ten = []
		svn = []

		for itm in fileObject:
			line = itm.strip().replace("-", "")
			if len(line) == 7:
				svn.append(itm)
			elif len(line) == 10:
				ten.append(itm)
			else:
				continue

		if len(ten) > len(svn):
			print "Ten"
		else:
			print "Seven"

	def h(fileObject):

		maxWord = "a"
		for itm in fileObject:
			line = itm.strip()
			if len(line) > len(maxWord):
				maxWord = itm

		print maxWord[:len(maxWord) - 1]

	def i(fileObject):
		for itm in fileObject:
			line = itm.strip()
			if line == line[::-1]: # Test palindrome
				print line

	def j(fileObject):
		lst = []
		for itm in fileObject:
			line = itm.strip()
			lst.append(line)

		for i in lst:
			if i[::-1] in lst:
				print i, i[::-1] 

	def k(fileObject):
		lst = []
		ans = []
		for itm in fileObject:
			line = itm.strip()
			lst.append(line)

		for i in lst:
			if i[::-1] in lst:
				if [i, i[::-1]] not in ans and [i[::-1], i] not in ans:
					ans.append([i, i[::-1]])

		for i in ans:
			print i			

	def l(fileObject):
		for itm in fileObject:
			line = itm.strip()
			if len(line) > 1 and "lly" not in line:
				for i in range(len(line) - 1):
					if line[i] == line[i + 1]:
						print line			

	def m(fileObject):
		for itm in fileObject:
			line = itm.strip()
			if len(line) > 1:
				for i in range(len(line) - 1):
					if line[i] == 'q' and line[i + 1] != 'u':
						print line

	def n(fileObject):
		for itm in fileObject:
			line = itm.strip()
			if 'zu' in line:
				print line

	def o(fileObject):
		for itm in fileObject:
			line = itm.strip()
			if 'ab' in line:
				n = line.index('ab')
				if 'ab' in line[n + 1:]:
					print line
				else:
					continue
			else:
				continue

	def p(fileObject):		
		for itm in fileObject:
			line = itm.strip()
			count = 0
			for ch in line:
				if ch in 'aeiou':
					count += 1
			if count >= 4:
				print line

	def q(fileObject):		
		for itm in fileObject:
			line = itm.strip()
			if 'z' in line and 'w' in line:
				print line

	def r(fileObject):		
		for itm in fileObject:
			line = itm.strip()
			if len(line) >= 5:
				if line[0] == 'a' and line[2] == 'e' and line[4] == 'i':
					print line					

	def s(fileObject):		
		for itm in fileObject:
			line = itm.strip()
			if '-' in line:
				print line

	def t(fileObject):		
		for itm in fileObject:
			line = itm.strip()
			if len(line) == 4:
				if line[0] == line[-1]:
					print line

	def u(fileObject):		
		for itm in fileObject:
			line = itm.strip()
			count = 0
			for ch in line:
				if ch in 'aeiou':
					count += 1
			if count >= 9:
				print line

	def v(fileObject):		
		for itm in fileObject:
			l = itm.strip()
			if len(l) >= 6:
				if 'a' in l and 'b' in l and 'c' in l and \
				'd' in l and 'e' in l and 'f' in l:
					print l

	def w(fileObject):		
		for itm in fileObject:
			line = itm.strip()
			if len(line) >= 8:
				if line[:4] == line[-4:]:
					print line

	def x(fileObject):		
		for itm in fileObject:
			line = itm.strip()
			if len(line) >= 8:
				if 'abcd' in line and 'dcba' in line:
					print line

	def y(fileObject):		
		for itm in fileObject:
			line = itm.strip()
			if len(line) == 3:
				if line[0] == line[-1] and line[1] in 'aeiou':
					print line

	def z(fileObject):
		maxI = "i" 		
		for itm in fileObject:
			line = itm.strip()
			if line.count('i') > maxI.count('i'):
				maxI = line
		print maxI
					
			
			
	#a(fileObject)
	#b(fileObject)
	#c(fileObject)
	#d(fileObject)
	#e(fileObject)
	#f(fileObject)
	#g(fileObject)
	#h(fileObject)
	#i(fileObject)
	#j(fileObject)
	#k(fileObject)
	#l(fileObject)
	#m(fileObject)
	#n(fileObject)
	#o(fileObject)
	#p(fileObject)
	#q(fileObject)
	#r(fileObject)
	#s(fileObject)
	#t(fileObject)
	#u(fileObject)
	#v(fileObject)
	#w(fileObject)
	#x(fileObject)
	#y(fileObject)
	#z(fileObject)


	fileObject.close()

def wordPuzzle1():

	fileObject = open('wordlist.txt', 'r')
	ans = []

	for itm in fileObject:
		line = itm.strip()
		lineR = line[::-1]
		ans.append(lineR)

	ans.sort()

	print ans[len(ans) - 1]

	fileObject.close()

def pythonPlusComb():

	fileObject = open('wordlist.txt', 'r')

	for itm in fileObject:
		line = itm.strip()
		if len(line) == 3:
			print "Python" + line.capitalize()

	fileObject.close()

def simpleSpellChecker():

	fileObject = open('wordlist.txt', 'r')
	lst = []
	words = raw_input(">> ")
	wList = [i.lower() for i in words.split()]

	for itm in fileObject:
		line = itm.strip()
		lst.append(line)

	for itm in wList:
		if itm not in lst:
			print itm
		else:
			continue

	fileObject.close()

def crosswordChecker():

	fileObject = open('wordlist.txt', 'r')
	lst = []
	word = raw_input("Introduce the word: ")
	slice1 = ""
	numAst = 0
	slice2 = ""

	for it in xrange(len(word)):
		if word[it] == '*':
			break
		else:
			slice1 += word[it]

	for ch in word:
		if ch == '*':
			numAst += 1

	slice2 = word[len(slice1) + numAst:]

	for itm in fileObject:
		line = itm.strip()
		lst.append(line)

	for itm in lst:
		if len(itm) == len(word):
			if slice1 == itm[:len(slice1)]:
				if slice2 == itm[len(slice1) + numAst:]:
					print itm

	fileObject.close()

def dictionaryOfWords():

	fileObject = open('wordlist.txt', 'r')
	dct = {}

	for ch in string.ascii_lowercase:
		dct[ch] = []

	for itm in fileObject:
		line = itm.strip().lower()
		if line[0] in string.ascii_lowercase:
			dct[line[0]].append(line)

	return dct

def dictionaryOfWordsStats(d):

	fileObject = open('wordlist.txt', 'r')
	lines = 0
	dct = {}

	for itm in fileObject:
		lines += 1

	for k in d:
		dct[k] = (len(d[k]) * 100) / (lines + 0.0) 

	return dct

def meaningOfAcronym():

	acronym = raw_input("Enter acronym: ")
	char = [i.lower() for i in acronym]
	lst = []
	dct = dictionaryOfWords()

	for ch in char:
		r = random.choice(dct[ch])
		lst.append(r)

	print lst

def jotto():

	def noReatedLetters(strng):

		for ch in strng:
			if strng.lower().count(ch) > 1:
				return False

		return True

	def lettersInCommon(s1, s2):

		ans = 0

		for ch in s2:
			if ch in s1:
				ans += 1

		return ans		

	fileObject = open('wordlist.txt', 'r')
	lsg = [line.strip() for line in fileObject]
	fileObject.close()
	lst = filter(lambda s : len(s) == 5 and noReatedLetters(s), lsg)

	turns = 0  
	
	while True:
		attempt = raw_input("Word: ")
		realWord = random.choice(lst)
		if noReatedLetters(attempt) == False:
			print "Your word has repeatted letters"
			continue
		if len(attempt) != 5:
			print "The word has 5 letters"
			continue
		n = lettersInCommon(attempt, realWord)
		print str(n) + " letters in common"
		if n == 5:
			print "Congratulations, you win!"
			break
		turns += 1
		if turns == 10:
			print "The word was ", realWord
			break

def scrabbleHelper():  # a.k.a Anagram generator

	def stringPermutation1(word):
		if len(word) == 1:
			return [word]
		perms = []

		for i in set(word):
			ss = word.replace(i, "", 1)
			z = stringPermutation1(ss)

			for t in z:
				perms.append(i + t)

		return perms

	def stringPermutation2(word):
		perms = [''.join(p) for p in permutations(word)]
		return set(perms)

	def stringPermutation(w): return stringPermutation1(w)

	letters = raw_input("Word: ")
	fileObject = open('wordlist.txt', 'r')
	lsg = [line.strip() for line in fileObject]
	fileObject.close()

	deflist = filter(lambda s : len(s) == len(letters) and '-' not in s, lsg)

	for i in stringPermutation(letters.lower()):
		if i in deflist:
			print i

def rectangle(m, n):
	for i in range(m):
		for j in range(n):
			print "*",
		print

def sum_digits(num):
	string = str(num)
	summation = 0

	for ch in string:
		summation += int(ch)

	return summation

def digital_root(number): # dr(n) = 1 + ((n - 1) % 9)
	ans = str(sum_digits(number))
	while(len(ans) > 1):
		ans = str(sum_digits(int(ans)))
	return ans

def first_diff(s1, s2):
	ans = -1

	for i in xrange(len(s1)):
		if s1[i] == s2[i]:
			continue
		else:
			ans = i
			return ans

	return ans

def funny_random(num):
	r = range(10 ** (num -1), 10 ** num)
	return random.choice(r)

def number_of_factors(num):
	ans = 0
	for i in range(1, num + 1):
		if num % i == 0:
			ans += 1
	return ans

def number_factors(num):
	ans = []
	for i in range(1, num + 1):
		if num % i == 0:
			ans.append(i)
	return ans

def closest(lst, n):
	maxim = 0
	for itm in lst:
		if itm <= n:
			if itm > maxim:
				maxim = itm
	return maxim

def matches(s1, s2):
	match = 0
	minLen = min(len(s1), len(s2))
	for i in range(minLen):
		if s1[i] == s2[i]:
			match += 1
	return match

def findall(s, c):
	ans = []
	for i in range(len(s)):
		if s[i] == c:
			ans.append(i)
	return ans

def is_sorted(lst):
	ans = True
	for i in range(len(lst) - 1):
		if lst[i] > lst[i + 1]:
			ans = False
			break
	return ans

def one_away(s1, s2):
	ans = 0
	for i in range(len(s1)):
		if s1[i] == s2[i]:
			continue
		else:
			ans += 1

	if ans == 1: return True
	return False

def merge(l1, l2, pythonic = False):

	if pythonic:
		ans = l1 + l2
		return sorted(ans)

	else:
		ans = l1 + l2
		for i in range(len(ans) - 1):
			for j in range(ans.index(ans[i]), len(ans) - 1):				
				if ans[i] > ans[j]:
					ans[i], ans[j] = ans[j], ans[i]
		return ans

def binarySearch(L, w):
	mid = len(L) / 2
	if w == mid:
		return True
	if w < L[mid]:
		for i in range(mid):
			if L[i] == w:
				return True
	else:
		for i in range(mid, len(L)):
			if L[i] == w:
				return True
	return False

def tic_tac_toe_game(mat):
	#[[1,2,3],[1,2,3],[1,2,3]]
	def put_two(matrix):
		row = random.randint(0,2)
		col = random.randint(0,2)

		if matrix[row][col] == 0:
			matrix[row][col] = 2

		ans = matrix
		return ans

	def check_winner(matrix):
		for row in range(len(matrix)):
			if matrix[row][0] == matrix[row][1] and \
			matrix[row][1] == matrix[row][2] and \
			matrix[row][0] != ' ':
				return True, matrix[row][0]
	
		for col in range(len(matrix)):
			if matrix[row][col] == matrix[1][col] and \
			matrix[1][col] == matrix[2][col] and \
			matrix[0][col] != ' ':
				return True, matrix[0][col]

		if matrix[0][0] != ' ' and matrix[0][0] == matrix[1][1] and \
		matrix[1][1] == matrix[2][2]:
			return True, matrix[0][0]

		return False, ' '

	return check_winner(mat)

def check_sudoku(m):

	def getSquare(mat, bigRow, bigCol):
		l = []
		for i in range(bigRow, bigRow + 3):
			l.extend(m[i][bigCol:bigCol + 3])
		return set(l)

	if len(m) != 9:
		print "Wrong sudoku"
		return

	vertical = True
	horizontal = True
	blocks = True


	for row in range(len(m)):
		l = []
		for col in range(len(m)):
			if m[row][col] not in l:
				l.append(m[row][col])
			else:
				horizontal = False
				return vertical and horizontal and blocks

	for col in range(len(m)):
		l = []
		for row in range(len(m)):
			if m[row][col] not in l:
				l.append(m[row][col])
			else:
				vertical = False
				return vertical and horizontal and blocks

	for i in range(0, 9, 3):
		for j in range(0, 9, 3):
			if len(getSquare(m, i, j)) != 9:
				blocks = False
				return vertical, horizontal, blocks

	return vertical and horizontal and blocks

m = [[5,3,4,6,7,8,9,1,2],
	 [6,7,2,1,9,5,3,4,8],
	 [1,9,8,3,4,2,5,6,7],
	 [8,5,9,7,6,1,4,2,3],
	 [4,2,6,8,5,3,7,9,1],
	 [7,1,3,9,2,4,8,5,6],
	 [9,6,1,5,3,7,2,8,4],
	 [2,8,7,4,1,9,6,3,5],
	 [3,4,5,2,8,6,1,7,9]] 


class Rational(object):

	def __init__(self, num, den):
		self.num = num
		self.den = den
		self.reduce()

	def getNumerator(self):
		return self.num

	def getDenominator(self):
		return self.den

	def gcd(self, a, b):
		a, b = max(a, b), min(a, b)
		while b > 0:
			a, b = b, a % b
		return a

	def reduce(self):
		divisor = self.gcd(self.num, self.den)
		self.num = self.num / divisor
		self.den = self.den / divisor

	def __str__(self):
		if self.den == 1:
			return str(self.num)
		return str(self.num) + "/" + str(self.den)

	def __add__(self, other):
		newNum = (self.num * other.den + other.num * self.den)
		newDen = (self.den * other.den)
		return Rational(newNum, newDen) 

	def __sub__(self, other):
		newNum = (self.num * other.den - other.num * self.den)
		newDen = (self.den * other.den)
		return Rational(newNum, newDen)

	def __mul__(self, other):
		newNum = self.num * other.num
		newDen = self.den * other.den
		return Rational(newNum, newDen)

	def __div__(self, other):
		newNum = (self.num * other.den)
		newDen = (other.num * self.den)
		return Rational(newNum, newDen)

	def __lt__(self, other):
		a = int(self.num) / (int(self.den) + 0.0)
		b = int(other.num) / (int(other.den) + 0.0)
		return a < b

	def __le__(self, other):
		a = int(self.num) / (int(self.den) + 0.0)
		b = int(other.num) / (int(other.den) + 0.0)
		return a <= b

	def __eq__(self, other):
		first = self.num == other.num
		secnd = self.den == other.den
		return first and secnd

	def __ne__(self, other):
		return not (self == other)

	def __cmp__(self, other):
		extremes = self.num * other.den
		means = other.num * self.den
		return cmp(extremes, means)

class savingAccount(object):

	RATE = 0.02 # Class variable, must be referenced as savingAccount.RATE 

	def __init__(self, name, pin):
		""" Returns a new account with the given name, pin
		    and the given balance.
		"""
		self.name = name
		self.pin = pin
		self.balance = 0

	def deposit(self, amount):
		""" Deposits the given amount from the account balance. """
		self.balance += amount

	def withdraw(self, amount):
		""" Withdraws the given amount from the account balance. """
		if amount < 0:
			return 'Amount must be greater or equal than zero'
		elif amount > self.balance:
			return 'Not enough funds'
		else:
			self.balance -= amount
			return None

	def getBalance(self):
		""" Returns the account's balance. """
		return self.balance

	def getName(self):
		""" Returns the account's name. """
		return self.name

	def getPin(self):
		""" Returns the account's pin. """
		return self.pin 
	
	def computeInterest(self):
		""" Computes the accounts interest and deposits it. """
		interest = self.balance * savingAccount.RATE
		self.deposit(interest)
		return interest

	def transfer(self, amount, toAccount):
		""" Transfer a given amount of money from account to toAccount. """
		self.withdraw(amount)
		toAccount.deposit(amount)

	def __str__(self): # For development and debugging
		""" String representation of the account. """

		result = 'Name:    ' + self.name + '\n'
		result += 'PIN:    ' + self.pin + '\n'
		result += 'Balance:    ' + str(self.balance) + '\n'
		return result

class Bank(object):

	def __init__(self):
		""" Returns a bank. """
		self.accounts = []

	def add(self, account):
		""" Adds the given account to the bank. """
		if account in self.accounts:
			return False
		else:
			self.accounts.append(account)
			return True

	def remove(self, pin):
		""" Removes the account with the given pin if exists, 
			then return it or None.
		"""
		itmToPop = None
		for account in self.accounts:
			if account.getPin() == pin:
				itmToPop = account

		if itmToPop != None:
			self.accounts.remove(itmToPop)

		return itmToPop

	def get(self, pin):
		""" Returns the account associated with the PIN, if the PIN is
			in the bank. Otherwise returns None. 
		"""
		for itm in self.accounts:
			if itm.getPin() == pin:
				return itm.getName()
		return None

		# return self.accounts.get(pin, None) if dict()

	def computeInterest(self):
		""" Computes the interests on each account, deposits it in that account,
			and returns the total interest.
		"""
		total = 0.0
		for account in self.accounts():
			total += account.computeInterest()
		return total

	def __str__(self):
		""" String representation of the bank. """
		accountsAssociated = ""
		for account in self.accounts:
			accountsAssociated += account.getName() + ", "
		return accountsAssociated


class Card(object):

	RANKS = tuple(range(1,14))
	SUITS = ('Spades', 'Diamonds', 'Hearts', 'Clubs')

	def __init__(self, rank, suit):
		self.rank = rank
		self.suit = suit

	def __str__(self):
		if self.rank == 1:
			rank = 'Ace'
		elif self.rank == 11:
			rank = 'Jack'
		elif self.rank == 12:
			rank = 'Queen'
		elif self.rank == 13:
			rank = 'King'
		else:
			rank = self.rank
		return str(rank) + ' of ' + self.suit.lower()

class Deck(object):

	def __init__(object):
		self.cards = []
		for suit in Cards.SUITS:
			for rank in Card.RANK:
				c = Card(rank, suit)
				self.cards.append(c)

	def shuffle(self):
		random.shuffle(self.cards)

	def deal(self):
		if len(self) == 0:
			return None
		else:
			return self.cards.pop(0)

	def __len__(self):
		return len(self.cards)

	def __str__(self):
		result = ''
		for c in self.cards:
			result += str(c) + '\n'
		return result

class Organism(object):

	def __init__(self, name, x, y):

		 self.name = name
		 self.x = x
		 self.y = y

	def __str__(self):

		return '(%s, [%s, %s])' % (self.name, self.x, self.y)

	def can_eat(self, food):

		return False

	def move(self):

		return

class Arthropod(Organism):

	def __init__(self, name, x, y, legs):

		Organism.__init__(self, name, x, y)
		self.legs = legs

	def __str__(self):

		return '(%s, %s, [%s, %s])' % (self.name, self.legs, self.x, self.y)

	def is_decapod(self):

		return self.legs == 10

	def leg_count(self):

		return self.legs

class Atom(object):

	def __init__(self, num, sym, x, y, z):
		self.num = num
		self.center = (x, y, z)
		self.symbol = sym

	def __str__(self):
		return '(%s, %s, %s, %s)' % \
		(self.symbol, self.center[0], self.center[1], self.center[2])

	def __repr__(self):
		return 'Atom(%s, "%s", %s, %s, %s)' % \
		(self.number, self.symbol, self.center[0], self.center[1], self.center[2])

	def translate(self, x, y, z):
		self.center = (self.center[0] + x, self.center[1] + y, self.center[2] + z)

class Molecule(object):

	def __init__(self, name):
		self.name = name
		self.atoms = []

	def add(self, a):
		aelf.atoms.append(a)

def read_molecule(r):

	line = r.readline()
	if not line:
		return None

	key, name = line.split()

	molecule = Molecule(name)
	reading = True

	while reading:
		line = r.readline()
		if line.startswith('END'):
			reading = False
		else:
			key, num, kind, x, y, z = line.split()
			molecule.add(Atom(num, kind, float(x), float(y), float(z)))

	return molecule

class tic_tac_toe(object):

	def __init__(self):
		self.board = [[0, 0, 0] for i in range(3)]
		self.player = 1

	def get_open_spots(self):
		return [[row, col] for row in range(3) for col in range(3) 
				 if self.board[row][col] == 0]

	def is_valid_move(self, r, c):
		if r in range(3) and c in range(3) and self.board[r][c] == 0:
			return True
		else:
			return False

	def make_move(self, r, c):
		if self.is_valid_move(r, c):
			self.board[r][c] = self.player
			self.player = (self.player + 2) % 2 + 1

	def check_for_winner(self):
		for c in range(3):
			if self.board[0][c] == self.board[1][c] == self.board[2][c] != 0:
				return self.board[0][c]
		for r in range(3):
			if self.board[r][0] == self.board[r][1] == self.board[r][2] != 0:
				return self.board[r][0]
		if self.board[0][0] == self.board[1][1] == self.board[2][2] != 0:
			return self.board[0][0]
		if self.board[2][0] == self.board[1][1] == self.board[0][2] != 0:
			return self.board[2][0]
		if self.get_open_spots() == []:
			return 0
		return -1

	def __str__(self):
		ans = '\n'
		for r in range(3):
			for c in range(3):
				ans += str(self.board[r][c]) + " "
			ans += '\n'
		return ans

def play_tic_tac_toe():

	game = tic_tac_toe()

	while game.check_for_winner() == -1:
		print game
		move = (raw_input("Enter spot, player " + str(game.player) + ': ').split())
		r, c = int(move[0][0]), int(move[1])
		game.make_move(r, c)

	print game

	x = game.check_for_winner()

	if x == 0:
		print 'It\'s a draw'
	else:
		print 'Player ', x, 'wins!'

class Stack(object):

	def __init__(self):
		self.storage = []

	def push(self, newValue):
		self.storage.append(newValue)

	def top(self):
		return self.storage[len(self.storage) - 1]

	def pop(self):
		result = self.top()
		self.storage.pop()
		return result

	def isEmpty(self):
		return len(self.storage) is 0

	def __str__(self):
		if self.isEmpty():
			return '[]'
		ans = '['
		for i in self.storage:
			if i == self.storage[len(self.storage) - 1]:
				ans += str(i) + ']'
			else:
				ans += str(i) + ', '
		return ans

def outputInBinary(n):
	if n is 0:
		return 0

	s = Stack()

	while n > 0:
		bit = n % 2
		s.push(bit)
		n = math.floor(n / 2)

	ans = ''

	while not s.isEmpty():
		ans += str(int(s.pop()))

	return ans

class calculatorEngine(object):

	def __init__(self):
		self.dataStack = Stack()

	def pushOperand(self, value):
		self.dataStack.push(value)

	def currentOperand(self):
		return self.dataStack.top()

	def performBinary(self, fun):
		right = self.dataStack.pop()
		left = self.dataStack.pop()
		self.dataStack.push(fun(left, right))

	def addition(self):
		self.performBinary(lambda x, y : x + y)

	def substraction(self):
		self.performBinary(lambda x, y : x - y)

	def product(self):
		self.performBinary(lambda x, y : x * y)

	def division(self):
		self.performBinary(lambda x, y : x / y)

	def mapOperation(self, op):
		if op == '+':
			self.addition()
		elif op == '-':
			self.substraction()
		elif op == '*':
			self.product()
		elif op == '/':
			self.division()

class RPNCalculator(object):

	def __init__(self):
		self.calcEngine = calculatorEngine()

	def eval(self, line):
		words = line.split(" ")
		for item in words:
			if item in '+-*/':
				self.calcEngine.mapOperation(item)
			else:
				self.calcEngine.pushOperand(int(item))
		return self.calcEngine.currentOperand()

	def run(self):
		while True:
			line = raw_input("tye an expression: ")
			if len(line) == 0:
				break
			print self.eval(line)	

class Node(object):
	
	def __init__(self, value = ""):
		self.left = None
		self.right = None
		self.value = None

	def getLeft(self):
		return self.left

	def getValue(self):
		return self.value

	def getRight(self):
		return self.right

	def setLeft(self, leftNode):
		self.left = leftNode

	def setRight(self, rightNode):
		self.right	= rightNode

	def setValue(self, val):
		self.value = val

valid = [[5,3,4,6,7,8,9,1,2],
         [6,7,2,1,9,5,3,4,8],
         [1,9,8,3,4,2,5,6,7],
         [8,5,9,7,6,1,4,2,3],
         [4,2,6,8,5,3,7,9,1],
         [7,1,3,9,2,4,8,5,6],
         [9,6,1,5,3,7,2,8,4],
         [2,8,7,4,1,9,6,3,5],
         [3,4,5,2,8,6,1,7,9]]

# check_sudoku should return False
invalid = [[5,3,4,6,7,8,9,1,2],
           [6,7,2,1,9,5,3,4,8],
           [1,9,8,3,8,2,5,6,7],
           [8,5,9,7,6,1,4,2,3],
           [4,2,6,8,5,3,7,9,1],
           [7,1,3,9,2,4,8,5,6],
           [9,6,1,5,3,7,2,8,4],
           [2,8,7,4,1,9,6,3,5],
           [3,4,5,2,8,6,1,7,9]]

def basic_re():
	hand = open('mbox-short.txt', 'r')
	for line in hand:
		line = line.strip()
		if re.search('From: ', line):
			print line