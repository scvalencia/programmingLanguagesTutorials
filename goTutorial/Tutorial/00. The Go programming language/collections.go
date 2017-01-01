package main

import "fmt"

func main() {

	/* ARRAYS
	 * An array is defined by: [n]<type>, where n is the length of the array and 
	 * <type> is the stuff you want to store. Assigning or indexing an element in 
	 * the array is done with square brackets:
	*/

	var arr [10]int						// Fixed size

	for i := 0; i < len(arr); i++ {
		arr[i] = i
	}

	/* Also arrays are values: Assigning one array to another copies all the elements. 
	 * In particular, if you pass an array to a function it will receive a copy of the array, 
	 * not a pointer to it.
	*/

	triple := [3]int{1, 2, 3}				// Type-inference like allocation and initialization
	friple := [...]int{1, 2, 3, 4, 5, 6}	// Automatic size counting

	for i := 0; i < len(triple); i++ {
		fmt.Printf("%d ", triple[i])
	}

	fmt.Printf("\n")

	for i := 0; i < len(friple); i++ {
		fmt.Printf("%d ", friple[i])
	}

	fmt.Printf("\n"); fmt.Printf("\n"); fmt.Printf("\n")

	matrix := [2][2]int {[2]int{1, 2}, [2]int{3, 4}}

	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			fmt.Printf("%d ", matrix[i][j])
		}
		fmt.Printf("\n")
	}

	fmt.Printf("\n"); fmt.Printf("\n")

	// Simplified syntax

	matrix = [2][2]int {{5, 6}, {7, 8}}

	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			fmt.Printf("%d ", matrix[i][j])
		}
		fmt.Printf("\n")
	}

	/* SLICES
	 * A slice is similar to an array, but it can grow when new elements are added. 
	 * A slice always refers to an underlying array. What makes slices different from arrays 
	 * is that a slice is a pointer to an array; slices are reference types, which means that if 
	 * you assign one slice to another, both refer to the same underlying array. For instance, 
	 * if a function takes a slice argument, changes it makes to the elements of the slice 
	 * will be visible to the caller, analogous to passing a pointer to the underlying array.
	*/

	// For slices we define a capacity and a length
	// var array [m]int; slice := array[0:n]

	 // ASSERT: len(slice)== n /\ cap(slice)== m /\ len(array)== cap(array)== m 

	sl := make([]int, 10)
	fmt.Printf("length: %d, capacity: %d\n", len(sl), cap(sl))

	/*
	 * Given an array, or another slice, a new slice is created via a[I:J]. 
	 * This creates a new slice which refers to the variable a, starts at index I, 
	 * and ends before index J. It has length J - I
	*/

	a := [...]int{1, 2, 3, 4, 5}		// a[77] throws invalid array index 77 (out of bounds for 5-element array)
	s1 := a[2:4]

	for i := 0; i < len(s1); i++ {
		fmt.Printf("%d ", s1[i])
	}
	fmt.Printf("\n")

	s1 = a[:4]

	for i := 0; i < len(s1); i++ {
		fmt.Printf("%d ", s1[i])
	}
	fmt.Printf("\n")

	s1 = a[2:]

	for i := 0; i < len(s1); i++ {
		fmt.Printf("%d ", s1[i])
	}
	fmt.Printf("%d \n", )

	// Dynamic array-like collection

	primes := make([]int, 10)						// Allocation
	var dubimes = append(primes, 2, 3, 5, 7, 11)	// Appending several values

	for _, i := range dubimes {
		fmt.Printf("%d ", i)
	}

	fmt.Printf("\n")

	var sieve = append(dubimes, primes...)			// Appending a collection

	for _, i := range sieve {
		fmt.Printf("%d ", i)
	}

	fmt.Printf("\n")

	// Copying an slice to a destination, and returns thenumber of copied elements

	var nums = [...]int{1, 2, 3, 4, 5, 6, 7, 8}
	sss1 := make([]int, 6)
	n1 := copy(sss1, nums[0:])

	for _, i := range sss1 {
		fmt.Printf("%d ", i)
	}

	fmt.Printf("\n%d\n", n1)

	sss2 := make([]int, 6)
	n2 := copy(sss2, nums[2:])

	for _, i := range sss2 {
		fmt.Printf("%d ", i)
	}

	fmt.Printf("\n%d\n", n2)

	/* MAPS
	 * Many other languages have a similar type built-in. For instance, Perl has hashes, 
	 * Python has its dictionaries and C++ also has maps (as part of the libraries). 
	 * In Go we have the map type. A map can be thought of as an array indexed by strings 
	 * (in its most simple form). In the following listing we define a map which converts 
	 * from a string (month abbreviation) to an int – the number of days in that month. 
	 * The generic way to define a map is with: map[<from type>]<to type>
	*/

	monthdays := map[string]int {
		"Jan": 31, "Feb": 28, "Mar": 31,
        "Apr": 30, "May": 31, "Jun": 30,
        "Jul": 31, "Aug": 31, "Sep": 30,
        "Oct": 31, "Nov": 30, "Dec": 31,
    }

    scores := make(map[string]int)
    scores["Xavier"] = 100

    fmt.Printf("%s : %d\n", "Jan", monthdays["Jan"])

    year := 0

    for _, days := range monthdays {
    	year += days
    }

    fmt.Printf("Days per year: %d\n", year)

    // Test for existence

    var value int
    var present bool

    value, present = monthdays["Nov"]

    v, ok := monthdays["Seb"]

    fmt.Printf("%d %b\n", value, present)
    fmt.Printf("%d %b\n", v, ok)

    monthdays["Seb"] = 90
    v, ok = monthdays["Seb"]
    fmt.Printf("%d %b\n", v, ok)

    delete(monthdays, "Seb")
    v, ok = monthdays["Seb"]
    fmt.Printf("%d %b\n", v, ok)
}