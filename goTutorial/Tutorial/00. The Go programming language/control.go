package main

import "fmt"

func main() {
	x := -54;

	// { must be in the same line as if
	if x > 0 {
		fmt.Println("Positive")
	} else if x < 0 {
		fmt.Println("Negative")
	} else {
		fmt.Println("Zero")
	}

	// Combined initialization and selection
	if hot := false; hot {
		fmt.Println("Hot")
	} else {
		fmt.Println("Cold")
	}

	// GOTO example
	bound := 15
	counter := 0

	loop:
		if counter <= bound {
			fmt.Println(counter)
			counter++
			goto loop
		}

	// For statement, has three forms:
	// for init; cond; advance {}	<- Normal form
	// for cond {}					<- While
	// for {}						<- While true

	number := 5
	fact := 1

	for i := 1; i <= number; i++ {
		fact = fact * i
	}

	fmt.Println(fact)

	// Reverse a string

	name := "claudia"
	c := []rune(name)

	for i, j := 0, len(c) - 1; i < j; i, j = i + 1, j - 1 {
		c[i], c[j] = c[j], c[i]
	}

	fmt.Println(string(c))

	// break, breaks the current loop

	for i := 0; i < 500; i++ {
		fmt.Println(i);
		if i > 5 {
			break;
		}
	}

	OUTER: for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			if i == 5 {
				break OUTER
			} else {
				fmt.Printf("%d * %d = %d    ", i, j, i * j);
			}
		}
	}

	fmt.Printf("\n");

	for i := 0; i < 10; i++ {
		if i == 5 {
			continue
		}
		fmt.Println(i)
	}

	// Ranges

	list := []string{"a", "b", "c", "d", "e", "f"}
	for i, itm := range list {
		fmt.Printf("%d %s\n", i, itm)
	}

	for i, itm := range "®æ€†™∫∂ƒå" {
		fmt.Printf("%d %c\n", i, itm)
	}

	/* Switch expressions: the expression need not to be constants, or even integers; the cases
	* are evaluated from top to bottom until a match is found. If the switch has not expression at all,
	* it matches to true. So one could write an idiomatic if-else-if-esle as a switch
	*/

	var bte byte

	bte = 'F'

	switch {
		case '0' <= bte && bte <= '9':
			fmt.Println(bte - '0')
		case 'a' <= bte && bte <= 'f':
			fmt.Println(bte - 'a' + 10)
		case 'A' <= bte && bte <= 'F':
			fmt.Println(bte - 'A' + 10)
	}

	i := 0

	switch i {
		case 0:
		case 1:
			fmt.Println("Hello new programming concept 1")
	}

	switch i {
		case 0:
			fallthrough
		case 1:
			fmt.Println("Hello new programming concept 2")
	}

	switch i {
		case -1: 
			fallthrough
		case 0:
			fmt.Println("Hello new programming concept 3")
		case 1:
			fmt.Println("Hello new programming concept 4")
	}

	switch i {
		case -1: 
			fallthrough
		case 0:
			fmt.Println("Hello new programming concept 5")
			fallthrough
		case 1:
			fmt.Println("Hello new programming concept 6")
	}

	i = 5

	switch i {
		case 0:
			fmt.Println(0)
		case 1:
			fmt.Println(1)
		case 2:
			fmt.Println(2)
		case 3:
			fmt.Println(3)
		case 4:
			fmt.Println(4)
		default:
			fmt.Println("None")
	}

	completeName := "Sebastián Jesús Antonio de las Casas Madrid, " + 
						"y además es extraordinario. Lo sabías?"

	for _, chr := range completeName {
		switch chr {
			case ' ', '?', '&', '=', '#', '+', ',', '.':
				continue
		}
		fmt.Printf("%c", chr)
	}

	fmt.Printf("\n")

	// String comparisson

	str1 := "hola";	str2 := "hola"

	for i := 0; i < len(str1) && i < len(str2); i++ {
		switch {
			case str1[i] > str2[i]:
				fmt.Println(1) 				// First is bigger than second
			case str1[i] < str2[i]:
				fmt.Println(-1) 			// Second is bigger than first
		}
	}

	switch {
		case len(str1) < len(str2):
			fmt.Println(-1)					// Second is bigger than first
		case len(str1) > len(str2):
			fmt.Println(1)					// First is bigger than second
	}

	fmt.Println(0) 							// If them are equal
}