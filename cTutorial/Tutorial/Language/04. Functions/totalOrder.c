#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#define MAX(a, b) (a > b)? a : b
#define MIN(a, b) (a < b)? a : b

int main(int argc, char **argv) {
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	int max = MAX(MAX(x, y), z);
	int min = MIN(MIN(x, y), z);
	int sum = x + y + z;
	printf("%d %d\n", min, max);

	return 0;
}