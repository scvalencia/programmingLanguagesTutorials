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