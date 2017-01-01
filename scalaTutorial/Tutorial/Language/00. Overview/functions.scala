def add(x : Int, y : Int) : Int = {
	return x + y
}

def substract(x : Int, y : Int) : Int = {
	return x - y
}

def multiply(x : Int, y : Int) : Int = {
	return x * y
}

def divide(x : Int, y : Int) : Int = {
	return x / y
}

var x = 45
var y = 9

println(add(x, y))
println(substract(x, y))
println(multiply(x, y))
println(divide(x, y))

def square(a : Int) : Int = a * a

def squareWithBlock(a: Int) = {
    a * a
}

println(square(4))
println(squareWithBlock(4))

def swap(x : Int, y : Int) = (y, x)

println(swap(1, 3))
