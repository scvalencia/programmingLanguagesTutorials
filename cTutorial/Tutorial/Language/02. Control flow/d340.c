#include <stdio.h>
int main(void)
{
	int n = 1;
	while (n <= 8)
	{
		int m = 1;
		while (m <= 8)
		{
			if (n % 2 == 0)
			{
				printf(" *");
			}
			else
			{
				printf("* ");
			}
			m++;
		}
		printf("\n");
		n++;
		
	}

}