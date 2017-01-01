#include <stdio.h>
int main(void)
{
	int n, i;
	printf("Introduce a number: ");
	scanf("%i",&n);
	int counter = 0;
	int bux;
	while (n != 0)
	{
		bux = n % 10;
	    n = n / 10;
	    if (bux == 7)
	    {
	    	counter++;
	    } 
	}
	printf("%d\n",counter);
}