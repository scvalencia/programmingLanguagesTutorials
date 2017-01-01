if(true) {
	println("It's true")
}

if(!true) {
	println("Weird CPU")
}

val z : Boolean = false

if(z) {
	println("It's true")
} else {
	println("It's false")
}

val result = {
	if(99 > 100) {
		4
	} else {
		42
	}
}

val a = 1
val b = 0

if(a < b) {

	print("a is less than b since ")
	println(s"$a is less than $b")

} else {

	if(a == b) {

		print("a is equal to b since ")
		println(s"$b is equal to $b")

	} else {

		print("b is less than a since ")
		println(s"$b is less than $a")

	}

}

if(a < 2 && b < 2) {
	println("Both a, b are les than 2")
}

if(true) { 5 } else ()

if(true) { 5 }