import sys
a = ['* * *','    *','* * *','* * *','*   *','* * *','* * *','* * *','* * *','* * *']
b = ['*   *','  * *','    *','    *','*   *','*    ','*    ','    *','*   *','*   *']
c = ['*   *','    *','* * *','  * *','* * *','* * *','* * *','    *','* * *','* * *']
d = ['*   *','    *','*    ','    *','    *','    *','*   *','    *','*   *','    *']
e = ['* * *','    *','* * *','* * *','    *','* * *','* * *','    *','* * *','* * *']
t = [a,b,c,d,e]
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
strNumList = splitNumber(num)
intNumList = intFilter(strNumList)
for i in range(len(intNumList)):
	line = ""
	for j in range(len(t)):
		print t[j][intNumList[i]]
	print " "