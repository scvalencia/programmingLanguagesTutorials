#include <stdio.h>

int main(void) {

	int n;

	scanf("%d", &n);

	while(n != 0) {

		printf("%d", n % 2);
		n = n / 2;
	}

	printf("\n");

	return 0;
}