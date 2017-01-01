#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	int *a;
	a = (int *) calloc(10, 8);
	free(a);
	return 0;
}