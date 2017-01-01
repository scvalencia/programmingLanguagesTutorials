#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void swap(char* x, char* y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}

char* permute(char* word, int i, int n) {
	int j;
   	if (i == n)
   		return word;
   	else {
   		for (j = i; j <= n; j++) {
        	swap((word + i), (word + j));
          	permute(word, i + 1, n);
          	swap((word + i), (word + j));
       }
   }
}

int main(int argc, char **argv) {
	char word[] = "abc";
	int length = strlen(word);
	int parameter = length - 1;
	permute(word, 0, parameter);
	printf("%s\n", word);
	return 0;
}