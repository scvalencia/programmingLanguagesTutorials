package main

import "fmt"
import "math"

func main() {
	var n, m, max, min, mul0, mul1, a0, a1, ans int64
	n, m = 9, 43 

	max, min = m, n
	if n > m {
		max, min = n, m
	}

	var digits, dummy, real = 0, min, min * max

	for dummy > 0 {
		dummy = dummy / 10
		digits++
	}


	mul0, mul1, a0, a1, ans = 1, 2, max, max + max, 0
	fmt.Printf("MUL0: %d MUL1: %d A0: %d A1: %d ANS: %d\n", mul0, mul1, a0, a1, ans)
	fmt.Printf("%s\n\n", "****************************")

	var count1, count2 = 0, 0
	var des = 4.0 * math.Log2(float64(min))

	for mul1 + mul0 <= min {
		fmt.Printf("A0: %d A1: %d MUL0: %d MUL1: %d\n", a0, a1, mul0, mul1)
		fmt.Printf("%s\n", "+++++++++++++++++++++++++++++")
		a0, a1 = a1, a0 + a1
		mul0, mul1 = mul1, mul0 + mul1
		
		count1 += 1
	}

	fmt.Printf("A0: %d A1: %d MUL0: %d MUL1: %d\n", a0, a1, mul0, mul1)
	fmt.Printf("%s\n", "+++++++++++++++++++++++++++++")

	fmt.Printf("\n\n\n\n")

	for min > 0 {
		fmt.Printf("ANS: %d MIN: %d MUL0: %d MUL1: %d A0: %d A1: %d\n", ans, min, mul0, mul1, a0, a1)
		fmt.Printf("%s\n", "``````````````````````````")
		if mul1 <= min {
			ans = ans + a1; 
			min = min - mul1
		} else {
			mul0, mul1 = mul1 - mul0, mul0
			a0, a1 = a1 - a0, a0
		}
		
		count2 += 1
	}

	fmt.Printf("ANS: %d MIN: %d MUL0: %d MUL1: %d A0: %d A1: %d\n", ans, min, mul0, mul1, a0, a1)
	fmt.Printf("%s\n", "``````````````````````````")

	fmt.Printf("%d %g %d\n", count1 + count2, des, real)
}