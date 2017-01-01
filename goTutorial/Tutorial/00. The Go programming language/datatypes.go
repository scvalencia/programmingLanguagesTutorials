// Declarations and definitions

/*
* func 		to declare functions and procedures
* var		to define variables (local and gloabal)
* cosnt		to declare local or global constants
* type 		to defina a type
*/

// Native data types (no implicit type conversion)

/*
* char
* int
* float
* boolean
* complex
*/

package main

import "fmt"

func main() {
	fmt.Println("go" + "lang\n")

	fmt.Println("4 + 5 = ", 4 + 5)
	fmt.Println("9 - 5 = ", 9 - 5)

	fmt.Println("4 * 5 = ", 4 * 5)
	fmt.Println("9 / 5 = ", 9 / 5)	
	fmt.Println("4 mod 2 = ", 4 % 2)

	fmt.Println("7.5 / 3.2 = ", 7.5 / 3.2)

	fmt.Println("flag = ", )
	fmt.Println("\t true && false = ", true && false)
	fmt.Println("\t true || false = ", true || false)
	fmt.Println("\t !false = ", !false)

	fmt.Println(3i + 5 + 8i + 9)
	fmt.Println(3i + 5 * 8i + 9)
}