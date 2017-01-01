// Compile and execute as : make removeDuplicates && ./removeDuplicates && rm removeDuplicates
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool inSearch(int a[20], int val);

int main(void) {

	srand(time(NULL));
	int array[20];

	for(int i = 0; i < 20; i++)
		array[i] = 0;

	array[0] = 1 + (rand() % 20);

	for(int i = 1; i < 20; i++) {
		int flag = 1 + (rand() % 20);
		while(inSearch(array, flag)) 
			flag = 1 + (rand() % 20);		
		array[i] = flag;
	}

	for(int i = 0; i < 20; i++)
		printf("%d ", array[i]);

	printf("\n");
}

bool inSearch(int a[20], int val) {
	for(int i = 0; i < 20; i++)
		if(a[i] == val)
			return true;
	return false;
}