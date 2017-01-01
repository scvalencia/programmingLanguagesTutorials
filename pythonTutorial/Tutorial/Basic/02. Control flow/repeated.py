def repeated(lst):
	rep = []
	flag = False
	for i in range(len(lst)):
		itm = lst[i]
		for j in range(len(lst)):
			if (itm == lst[j] and i != j):
				if itm not in rep:
					rep.append(itm)

	if rep != []:
		flag = True

	return flag, sorted(rep)