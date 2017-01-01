# include <stdio.h>
# include <stdbool.h>
# define MAX 6
void print_array(int array[MAX][MAX]);
void ne_generation(int array[MAX][MAX]);
int main(void) {
	int generation[MAX][MAX] = {{1,0,0,0,0,0},
								{0,0,1,0,0,1},
								{0,0,1,0,1,0},
								{0,0,0,1,0,0},
								{0,0,1,0,1,0},
								{0,0,0,0,0,0}};
	print_array(generation);
	printf("\n");
	ne_generation(generation);
		
}
void print_array(int array[MAX][MAX]) {
	for(int row = 0; row < MAX; row++) {
		for(int column = 0; column < MAX; column++)
			printf("%d ", array[row][column]);
		printf("\n");
	}
}
void ne_generation(int array[MAX][MAX]) {
	int next_generation[MAX][MAX];
	for(int row = 0; row < MAX; row++) {
		for(int column = 0; column < MAX; column++)
			next_generation[row][column] = array[row][column];
	}
	for(int n = 1; n < (MAX - 1); n++) {
		for(int m = 1; m < (MAX - 1); m++) {
			int live_count = 0;
			int dead_count = 0;

			if(array[n-1][m-1] == 1) live_count++;			
			if(array[n-1][m] == 1) live_count++;			
			if(array[n-1][m+1] == 1) live_count++;
			if(array[n][m-1] == 1) live_count++;			
			if(array[n][m+1] == 1) live_count++;
			if(array[n-1][m+1] == 1) live_count++;			
			if(array[n][m+1] == 1) live_count++;			
			if(array[n+1][m+1] == 1) live_count++;			

			if(live_count == 3) next_generation[n][m] = 1;
			else if ((live_count >= 4) || live_count < 2) next_generation[n][m] = 0;
		}
	}
	
	print_array(next_generation);
}


					