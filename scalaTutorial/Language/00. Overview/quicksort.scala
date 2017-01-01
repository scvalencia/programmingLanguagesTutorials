def sort(xs : Array[Int]) {

	def swap(i : Int, j : Int) {
		val t = xs(i)
		xs(i) = xs(j)
		xs(j) = t
	}

	def sort1(l : Int, r : Int) {
		val pivot = xs((l + r) / 2)
		var i = l
		var j = r
		while (i <= j) {
			while(xs(i) < pivot) i += 1
			while(xs(j) > pivot) j -= 1
			if(i <= j) {
				swap(i, j)
				i += 1
				j -= 1
			}
		}
		if(l < j) sort1(l, j)
		if(j < r) sort1(i, r)
	}

	sort1(0, xs.length - 1)
}

/*

	def filter(p : T => Boolean) : Array[T],
	we apply xs filter (pivot >), that is 
	xs filter (pivot > x).

	def while(p => Boolean) (s: => Unit) {
		if(p) {s ; while(p)(s)}
	}

	Since Scala is an expression oriented language, every
	function returns a value, if not specified, the value
	is (), which is called unit of type Unit.

	If a function returns ype is Unit, it's called a procedure
	as in Wirth languages (Pascal, Modula, Pl/0, Oberon)

	A more explicit expression oriented swap function would be:

	def swap(i :  Int, j : Int) : Unit {
		val t = xs(i); xs(i) = xs(j); xs(j) = t
		()
	}

	The result value of a function is the last expression,
	a return keyword is not necessary. Note that functions
	returning an explicit value always need an "=" before
	their body or defining expression.

*/

def quicksort(xs : Array[Int]) : Array[Int] = {
	if(xs.length <= 1) xs
	else {
		val pivot = xs(xs.length / 2)
		Array.concat(
			quicksort(xs filter (pivot >)), // Partially application of function
			xs filter (pivot ==),
			quicksort(xs filter (pivot <))
		)
	}
}

def printArray[K](arg : Array[K]) = println(arg.mkString("Array(", ",", ")"))

var list : Array[Int] = Array(2,6,1,0,3,68,12,67,90,1,0,45,86,12,86,23,76,12)
println("*****************************************************")
printArray(list)
sort(list)
printArray(list)
println("*****************************************************")
list = Array(2,6,1,0,3,68,12,67,90,1,0,45,86,12,86,23,76,12)
printArray(list)
printArray(quicksort(list))
println("*****************************************************")