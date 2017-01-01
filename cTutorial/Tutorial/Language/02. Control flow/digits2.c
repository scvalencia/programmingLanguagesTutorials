#include <stdio.h>
int main(void)
{
	int digits = 0;
	int n;
	
	printf("Introduce a positive number: ");
	scanf("%d",&n);
	
	do
	{
		n /= 10;
		digits++;		
	} 
	while (n != 0);
	if (digits == 1) printf("The number has one digit.");
	else printf("The number has %d digits",digits);
}