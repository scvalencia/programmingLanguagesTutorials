#include <stdio.h>

#define N 10

int main(int argc, char const *argv[]) {

	int a[N], *p;
	printf("Enter %d numbers: ", N);

	for(p = &a[0]; p < &a[N]; p++) // for(p = a; p < a + N; p++)
		scanf("%d", p);

	printf("In reverse order: \n");
	for(p = &a[N - 1]; p >= &a[0]; p--) // for(p = a + N - 1; p >= a; p--)
		printf(" %d", *p);

	printf("\n");
	return 0;
}