#include <stdio.h>
#define SIZE 25

void print_array(int size, int array[]);
void initialize_int_array(int size, int array[]);

int main(void) {
	int array[SIZE];
	initialize_int_array(SIZE, array);
	print_array(SIZE, array);	
}

void initialize_int_array(int size, int array[]) {

	for(int i = 0; i < size; i++) 
		array[i] = 10;
}

void print_array(int size, int array[]) {

	for(int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}