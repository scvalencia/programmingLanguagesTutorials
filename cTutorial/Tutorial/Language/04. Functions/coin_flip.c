#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int flip(void);
int main(void) {
	int heads = 0;
	int tails = 1;
	int flag;
	srand(time(NULL));
	for(int i = 0; i <= 100; i++) {		
		int flag = flip();
		if(flag == 0) {
			heads++;
			printf("Head\n");
		}
		else {
			tails++;
			printf("Tail\n");
		}		
	}
	printf("-----------------------------------\n");
	printf("HEADS = %d\n", heads);
	printf("TAILS = %d\n", tails );		
}
int flip(void) {
	return (rand() % 2);
}
