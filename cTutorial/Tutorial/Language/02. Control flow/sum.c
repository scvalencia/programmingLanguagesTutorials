#include <stdio.h>

int GCD(int a, int b);
int LCM(int a, int b);
int main(void)
{
	int n, sum_loop, sum_math;
    int counter; 
	printf("This program add the numbers from zero to a given number\n");
	printf("Introduce an integer number: ");
	scanf("%i", &n);
	counter = 0;
	while(counter <= n)
	{
		sum_loop = sum_loop + counter;
		counter++;
	}
	printf("The sum is %d\n", sum_loop);
	printf("The sum is %d\n", (n*(n+1))/2);

	return(0);
}

