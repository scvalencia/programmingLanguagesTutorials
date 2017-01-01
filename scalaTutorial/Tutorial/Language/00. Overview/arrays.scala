var newArray : Array[Int] = Array(1, 2, 3, 4)
def printArray[K](arg : Array[K]) = println(arg.mkString("Array(", ",", ")"))
printArray(newArray)
println(newArray.mkString(","))

var array2 = Array("a", 1, true)
printArray(array2)
var example : Array[Int] = Array(1,2,3,4)
var zero = example(0)
var one = example(1)
var two = example(2)
var three = example(3) 
println("If a := Array(1,2,3,4) Then a(i) is the ith position")
println(s"If a := Array(1,2,3,4) Then a(0) is $zero")
println(s"If a := Array(1,2,3,4) Then a(1) is $one")
println(s"If a := Array(1,2,3,4) Then a(2) is $two")
println(s"If a := Array(1,2,3,4) Then a(3) is $three")
example(0) = 6
printArray(example)
example(0) = 15
printArray(example)

val appended = 15 +: example
val prepended = example :+ 30
printArray(appended)
printArray(prepended)


val concatenated = Array(1,2,3,4,5) ++ Array(6,7,8,9,10)
printArray(concatenated)

println(concatenated.indexOf(5))

val difference1 = Array(1,2,3,4).diff(Array(1,4,6,7))
val difference2 = Array(1,4,6,7).diff(Array(1,2,3,4))
printArray(difference1)
printArray(difference2)


// JSON like tuples

val person = Array(Array("Alice", 32), Array("Fred", 34), Array("Frances", 65), Array("Bill", 13))
def findByName(name : String) : Array[Any] = {
	val personArray = person
	for(p <- personArray) {
		if (p(0) == name) {
			return p
		}
	}
	return Array()
}

printArray(findByName("Alice"))
printArray(findByName("Gerald"))

val tuple = ("Haskell", "Scala", "Standard-ML", "OCaml", "Lisp", "Erlang", "Clojure", "F#")
println(tuple._1)
println(tuple._2)
println(tuple._3)
println(tuple._4)
println(tuple._5)
println(tuple._6)
println(tuple._7)
println(tuple._8)

val tuplesArray = Array(("Alice", 32), ("Fred", 34), ("Frances", 65), ("Bill", 13))
def findByNameInTuple(name : String) = tuplesArray.find(_._1 == name).getOrElse(("", -1))
println(findByNameInTuple("Alice"))