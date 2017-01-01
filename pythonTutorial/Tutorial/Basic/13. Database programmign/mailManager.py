# E-mail database application
# Written by scvalencia

import shelve
import string

database = shelve.open("emailinfo")
MENU = """Welcome to mailManager v 1.0 using PQM:
Basic queries: SELECT, ADD, SEARCH, QUIT."""
print MENU

line = raw_input("QUERY: ")
while line != 'QUIT':
	words = line.split()
	if words[0] == 'SELECT':
		print words[1], ":", database[words[1]]
	elif words[0] == 'ADD':
		database[words[1]] = " ".join(words[2:])
	elif words[0] == 'SEARCH':
		for e in database.keys():
			if database[e].find(words[1]) != -1:
				print e, ":", database[e]
	line = raw_input("QUERY: ")

database.close()