import sys
zer = ['* * *','*   *','*   *','*   *','* * *']
one = ['    *','  * *','    *','    *','    *']
two = ['* * *','    *','* * *','*    ','* * *']
thr = ['* * *','    *','  * *','    *','* * *']
fou = ['*   *','*   *','* * *','    *','    *']
fiv = ['* * *','*    ','* * *','    *','* * *']
six = ['* * *','*    ','* * *','*   *','* * *']
sev = ['* * *','    *','    *','    *','    *']
eig = ['* * *','*   *','* * *','*   *','* * *']
nin = ['* * *','*   *','* * *','    *','* * *']
Digits = [zer, one, two, thr, fou, fiv, six, sev, eig, nin]
num = sys.argv[1]
def splitNumber(number):
	num_string = str(number)
	digits = []
	for ch in num_string:
		digits.append(ch)
	return digits
def intFilter(numberStr):
	digitsList = [int(i) for i in numberStr]
	return digitsList
def banner(numList):
	pass

a = splitNumber(num)
b = intFilter(a)
#print a
#print b
for row in range(len(zer)):
	line = ""
	for col in range(len(Digits)):
		number = b[col]
		digit = Digits[number]
		line += digit[row] + "  "
	print line, 
