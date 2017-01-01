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

	i = j = 0;
	for(count = 0; count < 26; count++) {
		mat[i][j] = 'A' + count;

		for(move = 0; move < MOVES; move++)
			possible[move] = false;

		if (i > 0 && mat[i-1][j] == '.')
      		possible[0] = true; // 0 goes for the UP movement
    	if (i < SIZE - 1 && mat[i+1][j] == '.')
      		possible[1] = true; // 1 goes for the DOWN movement
    	if (j > 0 && mat[i][j-1] == '.')
      		possible[2] = true; // 2 goes for the LEFT movement
    	if (j < SIZE - 1 && mat[i][j+1] == '.')
      		possible[3] = true; // 3 goes for the RIGHT movement

      	for (move = 0; possible[move] == false && move < MOVES; move++);
      	if(move == MOVES) break;

      	move = -1;
      	while(move < 0) {
      		move = rand() % 4;
      		if(possible[move])
      			break;
      		move = -1;
      	}
      	switch(move) {
      		case 0:
      			i--;
      			break;
      		case 1:
      			i++;
      			break;
      		case 2:
      			j--;
      			break;
      		case 3:
      			j++;
      			break;
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