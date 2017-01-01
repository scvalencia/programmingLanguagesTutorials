println("Hello Wolrd!");
6 -> 4 // Is a tuple (6, 4)
6 -> 4 -> 5 // Is a tuple ((6, 4), 5)

/*
 * Steps for evaluation of expressions:
 *	Pick the left-most operation
 *	Evaluate its operands
 *	Apply the operator to the operand values
*/

def pi = math.Pi
def radius = 10
(2 * pi) * radius

/*
	(2 * pi) * radius
	(2 * 3.1415...) * radius
	6.28... * radius
	6.28 * 10
	62.8....
*/

val incomes = 1000000
val money = (incomes * 0.27) + incomes

val str = "Niklaus Wirth"
println(str.toUpperCase)
println(str.trim)
println(str.substring(0, 4))
println(str.replace('k', 'K'))
