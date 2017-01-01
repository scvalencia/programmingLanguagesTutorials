#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool is_prime(int n);
int main(void) {
	int number;
	printf("Introduce a number to test: ");
	scanf("%d", &number);
	if(is_prime(number))
		printf("The number %d is prime\n", number);
	else
		printf("%d is not prime\n", number);	
}
bool is_prime(int n) {
	int divisor;
	for(divisor= 2; divisor * divisor <= n; divisor++)
		if(n % divisor == 0)
			return false;
	return true;
}