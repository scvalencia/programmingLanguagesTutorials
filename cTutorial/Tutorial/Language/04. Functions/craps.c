#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rollDice(void);
int main (void) {
	int gameStatus, sum, myPoint;
	srand(time(NULL));
	sum = rollDice();
	switch(sum) {
		case 7: case 11:
			gameStatus = 1;
			break;
		case 2: case 3: case 12:
			gameStatus = 2;
			break;
		default:
			gameStatus = 0;
			myPoint = sum;
			printf("Point is %d\n", myPoint);
			break;
	}
	while(gameStatus == 0) {
		sum = rollDice();
		if (sum == myPoint)
			gameStatus = 1;
		else if (sum == 7)
			gameStatus = 2;
	}
	switch(gameStatus) {
		case 1:
			printf("Player wins\n");
			break;
		default:
			printf("Player loses\n");
			break;
	}
}
int rollDice(void) {
	int die1, die2, workSum;
	die1 = (1 + (rand() % 6));
	die2 = (1 + (rand() % 6));
	workSum = die1 + die2;
	printf("Player roller %d + %d = %d\n", die1, die2, workSum);
	return workSum;
}	