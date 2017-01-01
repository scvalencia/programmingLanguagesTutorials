#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#define LIMIT 1000

bool primes[LIMIT];

void populate() {
	int i = 2;
	for(; i < LIMIT; i++)
		primes[i] = true;
}

void sieve() {
	int n = 2, m = ceil(sqrt(LIMIT)), i = 0;
	for(; n < m; n++)
		if(primes[n]) {
			i = n * n;
			for(; i < LIMIT; i += n)
				primes[i] = false;
		}
}

void print_primes() {
	int i = 2;
	for(; i < LIMIT; i++)
		if(primes[i])
			printf("%d ", i);
	printf("\n");
}

int main(void) {
	populate();
	sieve();
	print_primes();

}