// Filename: sieveEratosthenes.c
// Run as: make sieveEratosthenes && ./sieveEratosthenes
#include <stdio.h>
#include <math.h>
void print_array(int array[], int size);
int first_nonZero(int array[], int from, int size);
int binarySearch(int array[], int target, int from, int to);
int main(void) {
	int n;
	scanf("%d", &n);
	int numbers[n];
	for(int i = 0; i < (n - 1); i++)
		numbers[i] = (i + 2);
	int p = 2;
	while (p < sqrt(n)) {
		for(int i = 0; i < n; i++) {
			if(numbers[i] != p && numbers[i] % p == 0)
				numbers[i] = 0;
		}
		p++;
	}
	print_array(numbers, n);
}
void print_array(int array[], int size) {
	for(int j = 0; j < (size - 1); j++)
		if (array[j] != 0)
			printf("%d ", array[j]);
	printf("\n");
}