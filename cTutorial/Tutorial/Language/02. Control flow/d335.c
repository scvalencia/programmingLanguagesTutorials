#include <stdio.h>
int main(void)
{
	int n;
	printf("Introduce a five digits number: ");
	scanf("%i",&n);
	int f1,f2,f3,f4,f5;
	int a,b,c,d,e,f;

	f1 = n/10;
	a = n % 10; //
	f2 = f1/10;
	b = f1 % 10; //
	f3 = f2/10; 
	c = f2 % 10; //
	f4 = f3/10;
	d = f3 % 10; //
	f5 = f4/10;
	e = f4 % 10; //

	if(a == e && d == b) printf("They are palindormes\n");
	else printf("Sorry\n");

}