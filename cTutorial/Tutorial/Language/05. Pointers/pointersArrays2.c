#include <stdio.h>

int main(int argc, char const *argv[]) {

	long m[] = {5L, 10L, 15L, 20L, 25L, 30L, 35L, 40L, 45L};
	long *p = m;
	int n = sizeof(m) / sizeof(m[0]), i = 0;

	for(; i < n; i++)
		printf("Address p + %d (&m[%d]): %llu\t%p"
			"\t*(p + %d) value: %ld\n", i, i, (unsigned long long)(p + i), p + i, i, *(p + i));

	printf("\nType long occuppies: %d bytes\n", (int) sizeof(long));

	return 0;
}