// make eratos && ./eratos && rm eratos

#include <stdio.h>
#include <stdbool.h>

int main(void) {

	int n;
	printf(">> ");
	scanf("%d", &n);
	bool array[n];

	for(int i = 2; i < n; i++)
		array[i] = true;

	for(int i = 2; i < n; i++) {
		if(array[i])
			for(int j = i + 1; j < n; j++)
				if(j % i == 0 && array[j])
					array[j] = false;
	}

	for(int i = 2; i < n; i++)
		if(array[i])
			printf("%d ", i);

	printf("\n");
}