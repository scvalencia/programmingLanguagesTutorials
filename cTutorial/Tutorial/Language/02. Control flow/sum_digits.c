#include <stdio.h>

int main(void)
{
	int number, sum;
	printf("Introduce a number: ");
	scanf("%d",&number);
	int digit;

	while (number != 0)
	{
		digit = number%10;
		sum+=digit;
		number=number/10;
				
	}
	printf("%d",sum);

	return 0;
}