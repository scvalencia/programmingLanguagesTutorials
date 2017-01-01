#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int*, int);
void swap(int*, int*);

int main(int argc, char const *argv[]) {
	int n, *a, i;
	printf("Enter size: ");
	scanf("%d", &n);

	a = (int *) calloc(n, sizeof(int));
	for(i = 0; i < n; i++)
		scanf("%d", a + i);

	bubble_sort(a, n);

	for(i = 0; i < n; i++)
		printf("%d ", *(a + i));

	printf("\n");

	free(a);
	return 0;
}

void bubble_sort(int* b, int n) {
	int i, j, temp;
	for (i = (n - 1); i > 0; i--)
    	for (j = 1; j <= i; j++)
      		if (b[j-1] > b[j])
        		swap(&b[j - 1], &b[j]);
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}