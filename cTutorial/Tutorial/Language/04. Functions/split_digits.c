#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MIN_VAL 1
#define MAX_VAL 32767
int remainder(int a, int b);
int cocient(int c, int d);
int main(void) {
	int number;
	printf("Introduce a number from %d to %d: ", MIN_VAL, MAX_VAL);
	scanf("%d", &number);
	if(((MIN_VAL > number) || (number > MAX_VAL))) {
		printf("Bad number");
		main();
	}
	while(number > 0) {
		remainder(number, 10);
		number = cocient(number, 10);
	}
	printf("\n");	
}
int remainder(int a, int b) {
	printf("%d ", a % b);
	return a % b;
}
int cocient(int c, int d) {
	printf("%d ", c / d);
	return c / d;
}