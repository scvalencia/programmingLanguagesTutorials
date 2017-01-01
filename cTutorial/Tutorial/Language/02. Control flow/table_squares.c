#include <stdio.h>

int main (void)
{
	int number_lines;
	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d",&number_lines);
	printf("\n\n\tNumber\t\tSquare\n\n");

	int i = 1;
	while(i <= number_lines)
	{
		printf("%10d\t%10d\n\n",i,i*i);
		i++;
	}
	return(0);
}