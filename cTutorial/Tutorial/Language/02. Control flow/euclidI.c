#include <stdio.h>
int main (void) {
	int a, b;
	printf("Introduce two positive numbers: ");
	scanf("%d%d",&a,&b);
	int m = a, n = b, r = m % n;
	while(r > 0) {
		m = n;
		n = r;
		r = m % n;
	}
	printf("%d\n", n);	
}