#include <stdio.h>

int* copy_array(int a[], int* size);
void copy_array1(int*, const int*);
void copy_array2(int*, const int*);

int main(int argc, char const *argv[]) {

	int i, offset, b[] = {34, 56, 12, 76, 98, 34, 12, 90, 45};
	int *bPtr = b, n = sizeof(b) / sizeof(b[0]); 

	printf("Array traversed with:\n\n"
		"Array subscript notation\n");

	for(i = 0; i < n; i++)
		printf("b[%d] = %d\n", i, b[i]);

	printf("\nPointer offset notation where \n"
		"the pointer is the array name\n");

	for(offset = 0; offset < n; offset++)
		printf("*(b + %d) = %d\n", offset, *(b + offset));

	printf("\nPointer subscript notation\n");

	for(i = 0; i < n; i++)
		printf("bPtr[%d] = %d\n", i, bPtr[i]);

	printf("\nPointer offset notation\n");

	for(offset = 0; offset < n; offset++)
		printf("*(bPtr + %d) = %d\n", offset, *(bPtr + offset));

	printf("\n\n");

	int safe_space = 11;
	int array1[n + safe_space], array2[n + safe_space];
	copy_array1(array1, b);
	copy_array2(array2, b);

	for(i = 0; i < n; i++)
		printf("*(array1 + %d) = %d\n", i, *(array1 + i));

	printf("\n\n");
	
	for(i = 0; i < n; i++)
		printf("*(array2 + %d) = %d\n", i, *(array2 + i));

	return 0;
}

// Buggy code, you need to study computer organization!!!
int* copy_array(int a[], int* size) {
	int n = sizeof((int*) a) / sizeof(int);
	*size = n;

	int cpy[*size], i = 0;

	for(; i < *size; i++)
		cpy[i] = a[i];

	return (int*) cpy;
}

void copy_array1(int* a1, const int* a2) {
	int i = 0;
	for(; (a1[i] = a2[i]); i++);
}

void copy_array2(int* a1, const int* a2) {
	for(; (*a1 = *a2); a1++, a2++);
}