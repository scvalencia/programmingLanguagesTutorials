#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

void binaryRepresentation(int number, int bits);
void truthTable(int number, int bits);
void showBits(unsigned int x);

int main(int argc, char **argv) {
	int n;
	while(scanf("%d", &n) != EOF) {
		int need = ceil(log2(n));
		int count = pow(2, n);
		int i = 0;
		for(; i < count; i++) {
			truthTable(i, n);
		}
	}
	return 0;
}

void truthTable(int number, int bits) {
	int need = ceil(log2(number));
	assert(need <= bits);
	int counter;
	char array[bits];
	for(counter = 0; counter < bits; counter++)
		array[counter] = 'F';
	counter = bits - 1;
	while(number != 0) {
		int flag = number % 2;
		array[counter] = (flag == 1)? 'T' : 'F';
		counter--;
		number = number / 2;
	}
	for(counter = 0; counter < bits; counter++)
		printf("%c ", array[counter]);
	printf("\n");
}

void binaryRepresentation(int number, int bits) {
	int need = ceil(log2(number));
	assert(need <= bits);
	int counter;
	char array[bits];
	for(counter = 0; counter < bits; counter++)
		array[counter] = '0';
	counter = bits - 1;
	while(number != 0) {
		int flag = number % 2;
		array[counter] = (flag == 1)? '1' : '0';
		counter--;
		number = number / 2;
	}
	for(counter = 0; counter < bits; counter++)
		printf("%c", array[counter]);
	printf("\n");
}

void showBits(unsigned int x) {
	int i = (sizeof(int) * 8) - 1;
	for(; i >= 0; i--)
		(x & (1 << i)) ? puts("1") : puts("2");
	printf("\n");
}

void reemplazar(TEXTO* txt, unsigned short residuo) {
	short kResiduo = (residuo >> ((k-2) + (1) - (k - 1)) && ~(~0 << (k - 1));
	* txt.mensaje |= kResiduo;
}