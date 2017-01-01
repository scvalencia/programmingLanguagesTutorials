package main

import "fmt"

func main() {
	var name1 string = "Sebastián"
	fmt.Println(name1)

	var name2, lastname string = "Julián", "Mora"
	fmt.Println(name2 + " " + lastname)

	var and, or bool = true && false, false || true
	fmt.Println(and, or) 

	// Simple type inference
	var flag = true
	fmt.Println(flag)

	var counter int
	counter = 95
	fmt.Println(counter)

	// Automatic declaration and initialization, to be used inside of functions
	country := "Colombia"
	fmt.Println(country)

	age, gender, single := 67, "M", true
	fmt.Println("AGE:", age)
	fmt.Println("GENDER:", gender)
	fmt.Println("SINGLE:", single)

	a, b := 9, 8
	fmt.Println("a: ", a)
	fmt.Println("b: ", b)

	a, b = b, a
	fmt.Println("a: ", a)
	fmt.Println("b: ", b)

	var epsilon float32
	epsilon = 6.564
	fmt.Println("epsilon: ", epsilon)

	// String are immutable in Go
	message := "Hello world"
	cpy := []rune(message)		// rune is an alias for int32

	fmt.Println(cpy)
	cpy[0] = 'c'
	fmt.Println(cpy)

	message2 := string(cpy)
	fmt.Println(message2)

	// complex64 : 32 bits for real part, 32 bit for imaginary part
	var c complex64 = 5 + 5i
	fmt.Printf("Value is: %v\n", c)
}