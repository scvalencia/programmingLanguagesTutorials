var range1 = 1 to 10
val range2 = 1 until 10
val range3 = 2 until 10 by 3
println(range1)
println(range2)
println(range3)
println("=" * 100)
println(range1.toList)
println(range2.toList)
println(range3.toList)
var filtered_range = range1.filter(_ > 4)
var mapped_range = range1.map(_ * 2)

println(filtered_range)
println(mapped_range)