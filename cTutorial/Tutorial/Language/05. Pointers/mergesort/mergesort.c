#include "mergesort.h"

void merge(int* a, int* b, int* c, int m, int n) {
	int i = 0, j = 0, k = 0;

	while(i < m && j < n)
		if(a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++];
	while(i < m)
		c[k++] = a[i++];
	while(j < n)
		c[k++] = b[j++];
}

void my_mergesort(int* key, int n) {
	int j, k, m, *w;

	for(m = 1; m < n; m *= 2) ;

	if(n < m) {
		printf("n must be a power of two.\n");
		exit(1);
	}

	w = (int *) calloc(n, sizeof(int));
	assert(w != NULL);

	for (k = 1; k < n; k *= 2) {
		for (j = 0; j < n - k; j += 2 * k)
			merge(key + j, key + j + k, w + j, k, k); 

		for (j = 0; j < n; ++j)
			key[j] = w[j];
	}

	free(w);
}

void write_array(int* a, int n) {
	int i = 0;
	printf("a = [");
	for(; i < n; i++)
		printf("%d%s", a[i], (i < n - 1) ? ", " : "]\n");
}

int main(int argc, char const *argv[]) {
	int *k, n, i;
	printf("Enter the size: ");
	scanf("%d", &n);

	k = (int *) malloc(n * sizeof(int));

	for(i = 0; i < n; i++)
		scanf("%d", k + i);

	write_array(k, n);
	my_mergesort(k, n);
	write_array(k, n);

	free(k);

	return 0;
}