#include <stdio.h>
#include <stdbool.h>

void printMatrix(char board[3][3]);
char winner(char b[3][3]);
char map(int player);

int main(void) {

	char board[3][3] = {
							{'1', '2', '3'},
							{'4', '5', '6'},
							{'7', '8', '9'}
						};

	int player = 1;

	// [0][0] ==> 1, [0][1] ==> 2, [0][2] ==> 3
	// [1][0] ==> 4, [1][1] ==> 5, [1][2] ==> 6
	// [2][0] ==> 7, [2][1] ==> 8, [2][2] ==> 9 

	printMatrix(board);

	while(winner(board) == ' ') {

		int input;
		printf("Player %d, introduce your box: ", player );
		scanf("%d", &input);

		switch(input) {

			case 1:
				if(board[0][0] == '1')
					board[0][0] = map(player);
				break;
			case 2:
				if(board[0][1] == '2')
					board[0][1] = map(player);
				break;
			case 3:
				if(board[0][2] == '3')
					board[0][2] = map(player);
				break;
			case 4:
				if(board[1][0] == '4')
					board[1][0] = map(player);
				break;
			case 5:
				if(board[1][1] == '5')
					board[1][1] = map(player);
				break;
			case 6:
				if(board[1][2] == '6')
					board[1][2] = map(player);
				break;
			case 7:
				if(board[2][0] == '7')
					board[2][0] = map(player);
				break;
			case 8:
				if(board[2][1] == '8')
					board[2][1] = map(player);
				break;
			case 9:
				if(board[2][2] == '9')
					board[2][2] = map(player);
				break;
			default:
				printf("Not allowed move\n");
				continue;

		}

		printMatrix(board);
		player = (player + 2) % 2 + 1;
	}

	printf("The winner is player %d!!!!!\n", (player + 2) % 2 + 1);
	return 0;	
}

void printMatrix(char board[3][3]) {

	printf("\n");
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n", board[0][0],board[0][1],board[0][2]);
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n", board[1][0],board[1][1],board[1][2]);
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n", board[2][0],board[2][1],board[2][2]);
	printf("+---+---+---+\n");
	
}

char map(int player) {
	return (player == 1) ? 'X' : 'O';
}

char winner(char b[3][3]) {

	if(b[0][0] == b[0][1] && b[0][1] == b[0][2])
		return b[0][0];
	else if(b[1][0] == b[1][1] && b[1][1] == b[1][2])
		return b[1][0];
	else if(b[2][0] == b[2][1] && b[2][1] == b[2][2])
		return b[2][0];
	else if(b[0][0] == b[1][0] && b[1][0] == b[2][0])
		return b[0][0];
	else if(b[0][1] == b[1][1] && b[1][1] == b[2][1])
		return b[0][1];
	else if(b[0][2] == b[1][2] && b[1][2] == b[2][2])
		return b[0][2];
	else if(b[0][0] == b[1][1] && b[1][1] == b[2][2])
		return b[0][0];
	else if(b[2][0] == b[1][1] && b[1][1] == b[0][2])
		return b[2][0];
	return ' ';

}