#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

int binarySearch(int* array, int size, int target);
int recBinarySearch(int* array, int size, int target, int low, int upper);

int main(int argc, char **argv) {
	int array[] = {2, 6, 7, 34, 76, 123, 234, 567, 677, 986};
	int size = sizeof(array) / sizeof(int);
	int target = 234;
	printf("%d\n", binarySearch(array, size, target));
	printf("%d\n", recBinarySearch(array, size, target, 0, size - 1));

}

int binarySearch(int* array, int size, int target) {
	int lower = 0;
	int upper = size - 1;
	while(lower <= upper) {
		int mid = floor((upper + lower) / 2);
		if(target > array[mid])
			lower = mid + 1;
		else if(target < array[mid])
			upper = mid - 1;
		else
			return mid;
	}
	return -1;
}

int recBinarySearch(int* array, int size, int target, int low, int upper) {
	if(low > upper)
		return -1;
	int mid = floor((upper + low) / 2);
	if(target > array[mid])
		return recBinarySearch(array, size, target, mid + 1, upper);
	else if(target < array[mid])
		return recBinarySearch(array, size, target, low, upper - 1);
	else
		return mid;
	return -1;
}