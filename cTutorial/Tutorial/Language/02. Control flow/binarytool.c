#include <stdio.h>
#include <math.h>


int main (void)
{
	int number_lines;
	printf("This program prints a table of powers of two.\n");
	printf("Enter number of entries in table: ");
	scanf("%d",&number_lines);
	int i = 0;
	while(i <= number_lines)
	{
	    printf("%1d %.f\n",i,pow(2,i));
	    i++;
	}
	return(0);
}