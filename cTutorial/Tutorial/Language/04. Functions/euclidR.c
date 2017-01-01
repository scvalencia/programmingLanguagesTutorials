#include <stdio.h>

int GCD(int a, int b);
int LCM(int a, int b);
int main(void)
{
	int a, b, gcd, lcm;

	printf("Intriduce the numbers: ");
	scanf("%i%i", &a, &b);

	gcd = GCD(a,b);
	printf("The grtest common divisor of %i and %i is: %i\n", a, b, gcd);
	lcm = LCM(a,b);
	printf("The least common multiple of %i and %i is: %i\n", a, b, lcm);
	return(0);
}
int GCD(int a, int b)
{
	int resp;
	if (b == 0)
		resp = a;
	else
		resp = GCD(b, a%b);
	return(resp);
}
int LCM(int a, int b)
{
	int resp;
	int gcd;
	gcd = GCD(a,b);
	resp = (a*b)/gcd;
	return(resp);
}

