#include <stdio.h>
#define SIZE_ARRAY 10

int main(void) {
	int input;
	int count_array [SIZE_ARRAY] = { 0 };
	int index;

	for(index = 1; index <= SIZE_ARRAY; index++){
		scanf("%d",&input);
		if(input <= 0 || input > MAX_BOUND) printf("Input out of bound: %d\n", input);
		else count_array[input]++;
	}
	printf("\n\nRating   Number of responses           Histogram\n");
	printf("------   --------------------\n");
	for(index = 1; index <= MAX_BOUND; index++) 
	{
		printf("%7d%14d", index, count_array[index]);
		for(int j = 1; j < count_array[index]; j++) 
			{
				if (count_array == 0) printf("+");
				else printf("*");
			}
		printf("*\n");
	}
	return(0);
}