"""
	This program simulates a simple ATM. The ATM user logs in with a name
	and a personal ID, or PIN. If either string is unrecognized, Python 
	prints an error message. Otherwise, an interactive menu is offered to 
	the user, for operation handling. Those operations include get the 
	balance, make a deposit, and make a withdrawal, and finally quit.

	The ATM runs until quit, or the user enters as name "CloseItDown".

"""

import cPickle

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

	def __init__(self, fileName = None):
		""" Returns a bank. """
		self.accounts = {}
		self.fileName = fileName
		if fileName != None:
			fileObject = open(fileName, 'r')
			while True:
				try:
					account = cPickle.load(fileObject)
					self.add(account)
				except EOFError:
					fileObject.close()
					break

	def add(self, account):
		""" Adds the given account to the bank. """
		self.accounts[account.getPin()] = account

	def save(self, fileName = None):
		""" Saves pickled amounts to a file. The paramenter allows theMethod
			user to change filenames. """

		if fileName != None:
			self.fileName = fileName
		elif self.fileName == None:
			return
		fileObject = open(self.fileName, 'w')
		for account in self.accounts.values():
			cPickle.dump(account, fileObject)
		fileObject.close()

	def remove(self, pin):
		""" Removes the account with the given pin if exists, 
			then return it or None.
		"""
		return self.account.pop(pin, None)

	def get(self, pin):
		""" Returns the account associated with the PIN, if the PIN is
			in the bank. Otherwise returns None. 
		"""
		return self.accounts.get(pin, None)

	def computeInterest(self):
		""" Computes the interests on each account, deposits it in that account,
			and returns the total interest.
		"""
		total = 0.0
		for account in self.accounts.values(:
			total += account.computeInterest()
		return total

	def __str__(self):
		""" String representation of the bank. """
		return '\n'.join(map(str, self.account.values()))

class ATM(object):
	""" pass."""

	CRACK = "CloseItDown"

	def __init__(self, bank):
		self.account = None
		self.bank = bank
		self.methods = {}
		self.methods["1"] = self.getBalance
		self.methods["2"] = self.deposit
		self.methods["3"] = self.withdraw
		self.methods["4"] = self.quit

	def run(self):
		while True:
			name = raw_input("Enter your name: ")
			if name == ATM.CRACK:
				break
			pin = raw_input("Enter your PIN: ")
			self.account = self.bank.get(pin)
			if self.account == None:
				print "Error, bad PIN"
			elif self.account.getName() != name:
				print "Error, bad name"
				self.account = None
			else:
				self.processAccount()

	def processAccount(self):
		while True:
			print "1  View your balance"
			print "2  Make a deposit"
			print "3  Make a withdrawl"
			print "4  Quit\n"

			number = raw_input("Enter a number: ")
			theMethod = self.methods.get(number, None)
			if theMethod == None:
				print "Wrong option"
			else:
				theMethod()
				if self.account == None:
					break

	def getBalance(self):
		print "Your balance is ", str(self.account.getBalance())

	def deposit(self):
		amount = input("Enter the amount to deposit: ")
		self.account.deposit(amount)

	def withdraw(self):
		amount = input("Enter the amount to withdraw ")
		msg = self.account.withdraw(amount)
		if msg:
			print msg

	def quit(self):
		self.bank.safe()
		self.account = None
		print "Have a nice day!"

def main():
	bank = Bank("bank.dat")
	atm = ATM(bank)
	atm.run()

def createBank(number = 0):
	bank = Bank()
	for i in xrange(number):
		bank.add(savingAccount('Name' + str(i + 1), str(1000 + i), 100.00))
	bank.save("bank.dat")