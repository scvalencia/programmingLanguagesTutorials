val kg = 80
val heightM = 1.83

val bmi = kg / (heightM * heightM)

if(bmi < 18.5) {
	println("Underweight")
} else if(bmi < 25) {
	println("Normal weight")
} else {
	println("Overweight")
}
