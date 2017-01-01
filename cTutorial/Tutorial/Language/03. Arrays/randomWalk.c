/* Programming project 8.9 King's C book  
 * make randomWalk && ./randomWalk
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 10
#define MOVES 4
int main(void) {
	char mat[SIZE][SIZE];
	int i, j, count, move;
	bool possible[4];
	srand(time(NULL));
	// Initializing the matrices
	for(i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			mat[i][j] = '.';
	for(move = 0; move < MOVES; move++)
		possible[move] = false;
	//
  	i = j = 0;
  	count = 0;
    mat[i][j] = 'A'; 
	while(count < 25) {
		move = rand() % 4;
		switch(move){
			case 0:
				if (i > 0 && mat[i-1][j] == '.') {
					mat[i-1][j] = mat[i][j] + 1;
					i--;
					count++;
				}				
				continue;				
			case 1:
				if (i < SIZE - 1 && mat[i+1][j] == '.') {
					mat[i+1][j] = mat[i][j] + 1;
					i++;
					count++;
				}
				continue;
				
			case 2:
				if (j > 0 && mat[i][j-1] == '.') {
					mat[i][j-1] = mat[i][j] + 1;
					j--;
					count++;
				}
				continue;				
			case 3:
				if (j < SIZE - 1 && mat[i][j+1] == '.') {
					mat[i][j+1] = mat[i][j] + 1;
					j++;
					count++;
				}
				continue;
		}
	}
	
	// Printing the matrix
	for(i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++)
			printf("%c ", mat[i][j]);
		printf("\n");
	}
	return 0;
}