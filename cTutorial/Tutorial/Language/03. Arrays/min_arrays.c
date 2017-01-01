#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX pow(2, 15);
#define and &&
#define min(a, b) (a < b)? a : b


int comp (const void * a, const void * b);
void printIntArray(int a[], int n);

int main(int argc, char **argv) {

	int n, m, p;
	printf("Size of A: ");
	scanf("%d", &n);
	printf("Size of B: ");
	scanf("%d", &m);
	printf("Size of C: ");
	scanf("%d", &p);
	int A[n], B[m], C[p];
	printf("A: ");
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	printf("B: ");
	for(int i = 0; i < m; i++)
		scanf("%d", &B[i]);
	printf("C: ");
	for(int i = 0; i < p; i++)
		scanf("%d", &C[i]);

	qsort(A, n, sizeof(int), comp);
	qsort(B, m, sizeof(int), comp);
	qsort(C, p, sizeof(int), comp);

	int i = 0, j = 0, k = 0, ans = INT_MAX;

	while(i < n and j < m and k < p) {
		int flag = abs(A[i] - B[j]) +  abs(B[j] - C[k]) + abs(C[k] - A[i]);
		ans = min(ans, flag);
		i++;
		j++;
		k++;
	}

	printf("ANS: %d\n", ans);	
}

int comp (const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}

void printIntArray(int a[], int n) {
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}