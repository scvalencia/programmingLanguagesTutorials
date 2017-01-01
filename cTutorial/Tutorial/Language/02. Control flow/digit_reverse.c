#include <stdio.h>

int main(void)
{
	int number;
	printf("Introduce a number: ");
	scanf("%d",&number);
	int digit;

	while (number != 0)
	{
		digit = number%10;
		printf("%d",digit);
		number=number/10;		
	}
	printf("\n");

	return 0;
}