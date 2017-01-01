#include <stdio.h>

int main(void)
{
	int number, digit;
	int array[9] = {0,0,0,0,0,0,0,0,0};
	printf("Enter a number: ");
	scanf("%d",&number);
	while(number != 0)
	{
		digit = number % 10;
		array[digit]++;
		number /= 10;
	}
	printf("Repeated digit(s): ");
	for(int i = 0; i <= 9; i++)
		if(array[i] > 1) printf("%d ", i);
	printf("\n");	
	return 0;
}