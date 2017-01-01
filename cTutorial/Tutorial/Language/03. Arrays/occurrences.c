#include <stdio.h>
#define SIZE_ARRAY 10
#define MAX_BOUND 5

int main(void) {
	int input;
	int count_array [SIZE_ARRAY] = { 0 };
	int index;

	for(index = 1; index <= SIZE_ARRAY; index++){
		scanf("%d",&input);
		if(input <= 0 || input > MAX_BOUND) printf("Input out of bound: %d\n", input);
		else count_array[input]++;
	}
	printf("\n\nRating   Number of responses\n");
	printf("------   --------------------\n");
	for(index = 1; index <= MAX_BOUND; index++) printf("%4d%14d\n", index, count_array[index]);
	return(0);
}