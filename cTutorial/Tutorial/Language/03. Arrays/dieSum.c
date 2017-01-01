#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rollDice(void);
int main(void) {
	srand(time(NULL));
	int array[13];
	for(int i = 0; i < 36000; i++) {
		int sum = rollDice();
		array[sum]++;
	}
	for(int i = 0; i < 13; i++)
		printf("%d\n", array[i]);
}
int rollDice(void) {
	int die1, die2, sum;
	die1 = (1 + (rand() % 6));
	die2 = (1 + (rand() % 6));
	sum = die1 + die2;
	return sum;
}