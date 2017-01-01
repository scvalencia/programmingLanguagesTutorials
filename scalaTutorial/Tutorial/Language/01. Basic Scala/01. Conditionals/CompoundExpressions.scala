val c = {
	val a = 11
	a + 42
}

val distance = {
	val x = 5.0; val x0 = 8.0
	val y = 6.0; val y0 = 19.0
	val dx = x - x0
	val dy = y - y0
	math.sqrt(dx * dx + dy * dy)
}

val activity = "swimming"
val hour = 6

val isOpen = {
	if(activity == "swimming" || 
	   activity == "ice skating") {
		val opens = 9
		val closes = 20
		println("Operating hours: " + opens + " - " + closes)

		hour >= opens && hour <= closes
	}
	else {
		true
	}
}

val e = { val x = 0 }

val a = 1
val b = 2
val c = 3

val cIsLeast = {
	val aAndC = c < a
	val bAndC = c < b
	aAndC && bAndC
}

val abs = {
	val number : Double = 3.0
	if (number >= 0) number else -number
}

{
	println(9)
	4 + 5
}

val comparissons = {
	println(2 == 3)
	println('a' == 'a')
	println('b' == 'a')
	println("mam".length == "dad".length)

	val a = "hola"
	val b = a

	println(a eq b)
	println(a == b)
}

println("≠ " * 90)

// NOT

println("NOT")
println("≠ " * 90)
println("NOT FALSE: " + !false)
println("NOT TRUE: " + !true)
println("≠ " * 90)

// AND

println("AND")
println("≠ " * 90)
println("F /\\ F: " + (false && false))
println("F /\\ T: " + (false && true))
println("T /\\ F: " + (true && false))
println("T /\\ T: " + (true && true))
println("≠ " * 90)

// OR

println("OR")
println("≠ " * 90)
println("F \\/ F: " + (false || false))
println("F \\/ T: " + (false || true))
println("T \\/ F: " + (true || false))
println("T \\/ T: " + (true || true))
println("≠ " * 90)

// XOR

println("XOR")
println("≠ " * 90)
println("F ^ F: " + (false ^ false))
println("F ^ T: " + (false ^ true))
println("T ^ F: " + (true ^ false))
println("T ^ T: " + (true ^ true))
println("≠ " * 90)

val x = {
	val a = 2
	val b = 4
	val c = -4
	val desc = b * b - 4 * a * c
	if(desc < 0) {
		println("Complex roots")
		()
	} else {
		val num1 = -b + math.sqrt(desc)
		val num2 = -b - math.sqrt(desc)
		val den = 2 * a
		num1 / den -> num2 / den
	}
}