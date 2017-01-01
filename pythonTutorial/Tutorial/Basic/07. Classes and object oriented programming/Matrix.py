class Matrix(object):

	def __init__(self, row, col):
		self.col = col
		self.row = row
		self.matrix = [[0 for j in range(col)] for i in range(row)]

	def getRow(self):
		return self.row

	def getCol(self):
		return self.col

	def getDim(self):
		return self.row, self.col

	def getMatrix(self):
		return self.matrix

	def isSquare(self):
		return self.row == self.col

	def setSpot(self, i, j, value):
		self.matrix[i][j] = value

	def setColumn(self, lst, index):
		pass


	def returnSpot(self, i, j):
		return self.matrix[i][j]

	def getIdentity(self):

		identity = Matrix(self.row, self.col)

		if self.isSquare():
			
			for i in range(self.row):
				for j in range(self.col):
					if(j == i):
						identity.setSpot(i, j, 1)
					else:
						identity.setSpot(i, j, 0)

			return identity

		else:

			return None

	def scalarProduct(self, scale):
		ans = Matrix(self.row, self.col)

		for i in range(self.row):
			for j in range(self.col):
				val = self.returnSpot(i, j)
				ans.setSpot(i, j, val * scale)

		return ans

	def getDiagonal(self):

		ans = []

		for i in range(self.row):
			for j in range(self.col):
				if j == i:
					ans.append(self.matrix[i][j])

		return ans	

	def __add__(self, other):

		if not(other.getCol() == self.col and other.getRow() == self.row):
			print "Range match ERROR"
			return
		ans = Matrix(self.row, self.col)
		for i in range(self.row):
			for j in range(self.col):
				a = self.returnSpot(i, j)
				b = other.returnSpot(i, j)
				ans.setSpot(i, j, a + b)
		return ans

	def __sub__(self, other):

		if not(other.getCol() == self.col and other.getRow() == self.row):
			print "Range match ERROR"
			return
		ans = Matrix(self.row, self.col)
		for i in range(self.row):
			for j in range(self.col):
				a = self.returnSpot(i, j)
				b = other.returnSpot(i, j)
				ans.setSpot(i, j, a - b)
		return ans

	def __mul__(self, other):
		pass

	def __str__(self):
		ans = ''
		for i in range(self.row):
			for j in range(self.col):
				ans +=  str(self.matrix[i][j]) + ' '
			if i == self.row - 1:
				break
			ans += '\n'
		return ans 