import sys

def skip_header(fileData, commentChar = "#"):

	ans = []
	fileData.readline()
	for line in fileData:
		if line.startswith(commentChar):
			continue
		else:
			info = line.split()
			for item in info:
				ans.append(item[:-1])
	return [int(x) for x in ans]

def main():
	data = open(sys.argv[1],'r')
	lst = skip_header(data)
	print "Min: ", min(lst)
	print "Max: ", max(lst)
	print "Len: ", len(lst)
	print "Avg: ", sum(lst) / (len(lst) + 0.0)
	data.close()

main()


