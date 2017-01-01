#include <stdio.h>

int* find_largest(int a[], const int n, int* index) {
	int i = 0, *ans = &a[i];
	for(;i < n; i++)
		if(a[i] > *ans) {
			ans = &a[i];
			*index = i;
		}
	return ans;
}

int main(int argc, char const *argv[]) {
	int array[] = {8, 45, 12, 87, 23, 9, 43, 23, 8, 12, 65, 98, 9};
	int index = 0, i = 0;
	int* largest = find_largest(array, sizeof(array) / sizeof(int), &index);
	for(; i < sizeof(array) / sizeof(int) - index; i++)
		printf("%p has value %d\n", largest + i, *(largest + i));
	return 0;
}