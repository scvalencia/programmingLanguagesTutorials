#include <stdio.h>
int main(void)
{
	int n;
	printf("Enter the side of the pyramid: ");
	scanf("%i",&n);
	for(int i = 0; i < n; i++)
   {		
		for(int spaces = 0; spaces < i; spaces++)
		{
			
			printf(" ");
									
		}
		for(int stars = n; stars > i; stars--)
		{
			printf("*");
		} 
		printf("\n");
	}
	return(0);
}