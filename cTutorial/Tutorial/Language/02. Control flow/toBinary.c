#include <stdio.h>

void int_to_bin1(int n);

int main(int argc, char **argv) {

	int_to_bin1(155);
	return 0;
}

void int_to_bin1(int n) { // Is not reversed
	int i = n;
	for(; i > 0; i /= 2)
		printf("%d", (i % 2));
	printf("\n"); 
}