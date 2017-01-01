// Anonymous functions 

println(((x : Int) => x * x)(1))
println(((x : Int) => x * x)(2))
println(((x : Int) => x * x)(3))
println(((x : Int) => x * x)(4))
println(((x : Int) => x * x)(5))
println(((x : Int) => x * x)(6))
println(((x : Int) => x * x)(7))

println("=" * 100)

println(((x : Int, y : Int) => x + y)(1, 1))
println(((x : Int, y : Int) => x + y)(1, 2))
println(((x : Int, y : Int) => x + y)(1, 3))
println(((x : Int, y : Int) => x + y)(1, 4))
println(((x : Int, y : Int) => x + y)(1, 5))
println(((x : Int, y : Int) => x + y)(1, 6))
println(((x : Int, y : Int) => x + y)(1, 7))

println("=" * 100)

val squareVal = (a: Int) => a * a

println(squareVal(1))
println(squareVal(2))
println(squareVal(3))
println(squareVal(4))
println(squareVal(5))
println(squareVal(6))
println(squareVal(7))

// First class functions

println("=" * 100)

def addOne(f: Int => Int, arg: Int) = f(arg) + 1
def double(x : Int) = x * 2

println(addOne((x : Int) => x * 2, 6))
println(addOne(double, 6))

def doWithOneAndTwo(f: (Int, Int) => Int) = f(1, 2)

val call1 = doWithOneAndTwo((x : Int, y : Int) => x + y)
val call2 = doWithOneAndTwo((x : Int, y : Int) => x * y)
val call3 = doWithOneAndTwo((x, y) => x * y)
val call4 = doWithOneAndTwo((x, y) => x * y)

println(call1)
println(call2)
println(call3)
println(call4)

val conciseCall = doWithOneAndTwo(_ + _)

println(conciseCall)