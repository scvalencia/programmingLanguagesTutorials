package main

import "fmt"

func main() {

    /* Create a simple loop with the for construct. Make it loop 10 times and printout
	 * the loop counter with the fmt package.
	*/

    for i := 1; i <= 10; i++ {
    	fmt.Printf("%d ", i);
    }

    fmt.Printf("\n")

    /* Rewrite the same loop without using the for construct (goto statement) */

    var loopcounter = 1
    loop:
    	if loopcounter <= 10 {
    		fmt.Printf("%d ", loopcounter);
    		loopcounter = loopcounter + 1
    		goto loop
    	}

    fmt.Printf("\n")

    /* Rewrite the loop again so that it fills an array and then prints that 
     * array to the screen.
    */

    var numarray [11]int

    for i := 1; i < len(numarray); i++ {
    	numarray[i] = i
    	fmt.Printf("%d ", numarray[i]);
    }

    fmt.Printf("\n")

    /* Write a program that prints the numbers from 1 to 100. 
     * But for multiples of three print “Fizz” instead of the number and for the multiples 
     * of five print “Buzz”. For numbers which are multiples of both three and five print “FizzBuzz”.
    */

    var message string
    loopcounter = 1
    fizzbuzz:
    	message = ""
    	if loopcounter <= 15 {

    		if loopcounter % 5 == 0 && loopcounter % 3 == 0 {
    			message = "FizzBuzz"
    		} else if loopcounter % 3 == 0 {
    			message = "Fizz"
    		} else if loopcounter % 5 == 0 {
    			message = "Buzz"
    		}

    		fmt.Printf("%d %s\n", loopcounter, message)
    		loopcounter = loopcounter + 1
    		goto fizzbuzz
    	}

    /* Create a Go program that prints the following (up to 100 characters):
	 * A
	 * AA
	 * AAA
	 * AAAA
	 * AAAAA
	 * ....
    */

    charater := "A"
    for i := 1; i <= 10; i++ {
    	fmt.Printf("%s\n", charater)
        charater += "A"
    }

    /* Create a program that counts the number of characters in a string */

    var thisString string = "This is a perfect String";
    var count int = 0;

    for count < len(thisString) { count += 1 }

    fmt.Printf("CHARACTERS: %d\n", count)

    /* Create a program to replace the three runes at position 4 with ’abc’
     * of the following string: "asSASA ddd dsjkdsjs dk"
    */

    msg := "asSASA ddd dsjkdsjs dk"
    replace := "abc";

    slice1 := []rune(msg)
    slice2 := []rune(replace)

    for i, j := 4, 0; j < len(slice2); i, j = i + 1, j + 1  {
        slice1[i] = slice2[j]
    }

    fmt.Printf("%d\n", string(slice1))

    /* Create a simle progam to reverse a String */

    word := "ABCDEFGHI"
    auxWord := []rune(word)

    for i, j := 0, len(word) - 1; i < j; i, j = i + 1, j - 1 {
        auxWord[i], auxWord[j] = auxWord[j], auxWord[i]
    }

    for i := 0; i < len(auxWord); i = i + 1 {
        fmt.Printf("%c", auxWord[i])
    }

    fmt.Printf("\n");

}