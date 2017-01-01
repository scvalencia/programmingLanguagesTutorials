// make printPattern && ./printPattern && rm printPattern
#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
void printPattern(int side, char k);
int main (void) {
	int number;
	char key = '(';
	printf("Introduce an integer to generate the pattern: ");	
	scanf("%d", &number);
	printPattern(number, key);
}
void printPattern(int side, char k) {
	for(int i = 0; i < side; i++) {
		for(int j = 0; j < side; j++) 
			printf("%c", k);		
		printf("\n");
	}
}