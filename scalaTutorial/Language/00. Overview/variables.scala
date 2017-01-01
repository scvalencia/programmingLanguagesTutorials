var x = 1 + 3
println(x)
var y = 3 * 2
println(x + y)
x = 4 * 29
println(x + y)

var helloworld = "hello" + " world"
println(helloworld)

var again = "again"
println(helloworld + " " + again)

var epsilon : Int = 30
println(epsilon)

var num = -5  
var numAbs = num.abs //absolute value  
var max5or7 = numAbs.max(7)  
var min5or7 = numAbs.min(7)  
println(numAbs)  
println(max5or7)   
println(min5or7)

var string = "Martin Odersky"
var stringReversed = string.reverse
println(string + " | " + stringReversed)
var badName = "niklus Wirth"
println(badName.capitalize)
var number = "423423"
println(number.toInt + 89)

var c, python, java = false

println(c, python, java)

var (a, b, d, e, f, g) = (1, 2, 3, true, false, "no!")
println(a)
println(b)
println(d)
println(e)
println(f)
println(g)
println(a, b, d, e, f, g)
