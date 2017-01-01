#include <stdio.h>
/* Print Celsius-Fahrenheit table for
   fahr = 0, 20, ...,300 with a header */
int main(void)
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("Fahrenheit \t Celsius\n");
	while(fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr-32);
		printf("%6.2f\t\t%6.2f\n",fahr,celsius);
		fahr += step;
	}

}