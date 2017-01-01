import os
import string

def rename(directory, i = 0):
	lst = os.listdir(directory)
	names = map(lambda a : os.path.splitext(a)[0], lst)
	max_number = max(names)
	print max_number
	for itm in lst:
		if itm[0] == '.':
			continue
		if itm == 'handler.py':
			continue
		if os.path.isfile(itm):
			fileName, fileExtension = os.path.splitext(itm)
			if not fileName.isdigit():
				os.rename(itm, str(i) + fileExtension)
			i += 1
		else:
			os.chdir(itm)
			rename(os.getcwd())
			os.chdir("..")

rename(os.getcwd())