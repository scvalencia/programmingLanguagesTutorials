#include <stdio.h>
#include <stdbool.h>

void print_array(int id[], int N);

int main(int argc, char **argv) {
	int N;
	scanf("%d", &N);
	int i, p, q, t, id[N];
	int count = N, flag = N;
	while(flag--) {
		scanf("%d %d", &p, &q);
		if(id[p] == id[q]) continue;
		for(t = id[p], i = 0; i < N; i++)
			if(id[i] == t)
				id[i] = id[q];
		count--; 
	}
	printf("%d\n", N - count);
}

void print_array(int id[], int N) {
	int i = 0;
	for(; i < N; i++)
		printf("%d ", id[i]);
	printf("\n");
}

