#include <stdio.h>

int main (void)
{
	int number;
	printf("This program prints the fancy multiplication tables of a number.\n");
	printf("Enter the number you want to be the test: ");
	scanf("%d",&number);

	int i = 1;
	while(i <= number)
	{
		int j = 1;
		while(j <= number)
		{
			printf("%d * %d = %d\n",i,j,i*j);
		    j++;
		}
		i++;		
	}
	return(0);
}