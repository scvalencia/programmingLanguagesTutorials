#include <stdio.h>
/* Print Fahrenheit-Celsius table for
   fahr = 0, 20, ...,300 with a header */
int main(void)
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	printf("Celsius \t Fahrenheit\n");
	while(celsius <= upper)
	{
		fahr = (9.0/5.0)*celsius + 32;
		printf("%6.2f\t\t%6.2f\n",celsius,fahr);
		celsius += step;
	}

}