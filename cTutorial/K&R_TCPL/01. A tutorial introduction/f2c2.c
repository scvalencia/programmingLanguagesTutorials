#include <stdio.h>
/* Print Celsius-Fahrenheit table for
   fahr = 0, 20, ...,300 with a header */
int main(void)
{
	int fahr;
	float celsius;
	for(fahr = 300; fahr >= 0; fahr -= 20) 
		printf("%3d %6.1f\n\n",fahr, (5.0/9.0)*(fahr-32));

}