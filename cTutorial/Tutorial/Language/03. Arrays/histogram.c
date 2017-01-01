#include <stdio.h>

int main(void)
{
	int number;
	printf("Introduce a list of numbers: ");
	int i = 0;
	while (i < 5) 
	{
		scanf("%d",&number);
		for(int j = 0; j < number; j++)
		{
			printf("*");
		}
		printf("\n");
		i++;
		
	}
}