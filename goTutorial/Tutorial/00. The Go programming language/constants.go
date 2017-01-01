package main

import "fmt"
import "math"

const language string = "Español"

func main() {
	fmt.Println(language)

	const number = 500
	const datum = 3e20 / number

	fmt.Println(datum)
	fmt.Println(int64(datum))
	fmt.Println(math.Sin(number))

	const (
		a = iota
		b; c; d 
	)

	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)

	const (
		epsilon = 4.06
		name = "Sebastián"
	)

	fmt.Println(epsilon)
	fmt.Println(name)
}