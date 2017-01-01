#include <stdio.h>
#include <math.h>

int main(void)
{
	int a,b,c;
	printf("Introduce the triple of integers: ");
	scanf("%i%i%i",&a,&b,&c);
	if((a*a == b*b + c*c) || (b*b == c*c + a*a) || (c*c == b*b + a*a))
	{
		printf("They are a pythagorean triple\n");
	}
	else
		printf("They are not an special triple\n");

}