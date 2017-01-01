#include <stdio.h>
int main(void)
{
	int n;
	printf("Introduce de side of a square: ");
	scanf("%i",&n);
	int l = 1;
	
	while(l <= n)
	{   
		int w = 1;
		while(w <= n)
		{
			printf("*");
			w++;
		}
		printf("\n");
		l++;
	}
	return(0);
}
