#include <stdio.h>
void collatz(long int n);
int main(void) 
{
	collatz(10);	
}
void collatz(long int n)
{
	int counter = 0;
	while (n > 1) 
	{
		printf("%ld\n", n);
		if ((n % 2) == 1) n = 3 * n + 1;
		else n = n / 2;
		++counter;
	}
    printf("%ld\n", n);
    printf("\n\n%d",counter);
}