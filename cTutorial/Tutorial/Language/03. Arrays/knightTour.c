// Filename: chessHorse.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 8
void print_matrix(int b[SIZE][SIZE]);
int main(void) {

	srand(time(NULL));

	int board[SIZE][SIZE];
	int currentRow = 3, currentCol = 4, moveNumber = (rand() % 7);
	int horizontal[] = {2,1,-1,-2,-2,-1,1,2}; // Izquierda, abajo, son negativos.
	int vertical[] = {-1,-2,-2,-1,1,2,2,1};
	for(int row = 0; row < SIZE; row++) 
		for(int col = 0; col < SIZE; col++) 
			board[row][col] = 0;
	board[currentRow][currentCol] = 1;
	int count = 1;
	bool isPossible = true;
	while(isPossible) {
		moveNumber = (rand() % 7);
		currentRow += vertical[moveNumber];
		currentCol += horizontal[moveNumber];
		
	}
	print_matrix(board);
	printf("%d\n", count);
	return 0;
}
void print_matrix(int b[SIZE][SIZE]) {
	printf("\n");
	for(int row = 0; row < SIZE; row++) {
		for(int col = 0; col < SIZE; col++)
			printf("%d ", b[row][col]);
		printf("\n");
	}
	printf("\n");
}