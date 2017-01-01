#include <stdio.h>

int main (void)
{
	int number = 0;
	int sum = 0;
	printf("This program sums a series of numbers.\n");
	printf("Enter integers (0 to terminate): ");
	scanf("%d",&number);
	
	while(number != 0)
	{
		sum += number;
		scanf("%d",&number);		
	}
	printf("The sum is: %d\n", sum);
	return(0);
}