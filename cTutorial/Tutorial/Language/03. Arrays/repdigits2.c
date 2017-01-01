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
	printf("Digit:\t\t ");
	for(int i = 0; i <= 9; i++) printf("%d ", i);
	printf("\n");
	printf("Occurrences:  \t");
	for(int i = 0; i <= 9; i++) printf("%d ", array[i]);
	printf("\n");	
	return 0;
}

