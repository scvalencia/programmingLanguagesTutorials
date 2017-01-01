#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void init_array(int* a, int n) {
	int i = 0;
	for(; i < n; i++) 
		*(a + i) = rand() % 19 - 9;
}

int sum_array(int* a, int n) {
	int i = 0, ans = 0;
	for(; i < n; i++)
		ans += *(a + i);
	return ans;
}

void write_array(int* a, int n) {
	int i = 0;
	printf("a = [");
	for(; i < n; i++)
		printf("%d%s", a[i], (i < n - 1) ? ", " : "]\n");
}

int main(int argc, char const *argv[]) {
	int *a, n;
	srand(time(NULL));

	while(true) {
		printf("Input size: ");
		scanf("%d", &n);

		if(n <= 1)
			break;

		putchar('\n');

		a = (int *) malloc(n * sizeof(int));

		init_array(a, n);
		write_array(a, n);
		printf("sum = %d\n\n", sum_array(a, n));

		free(a);

	}

	return 0;
}