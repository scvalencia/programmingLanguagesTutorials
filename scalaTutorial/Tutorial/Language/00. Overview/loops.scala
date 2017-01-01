var i, sum = 0

while(i <= 100) {
	sum += i
	i += 1
}
println(s"Iteration variable: $i")
println(s"Final summation: $sum")

var nSum = 0
for(j <- 0 to 10) {
	nSum += j
}
println(nSum)

var floopySum = 0
var range : Range = 1 to 100

for(k <- range) {
	floopySum += k
}
println(s"K if None, and summation id $floopySum")

var newRange : Range = 1 until 10
var summationRange = newRange.sum
println(s"Sum: $summationRange")