#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define N 20

long long fact[N];

void factorial() {
	fact[0] = 1;
	fact[1] = 1;
	int i = 2;
	for(; i < N; i++)
		fact[i] = i * fact[i - 1];
} 

void swap(char* x, char* y) {
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char *a, int i, int n) {
   int j; 
   if (i == n)
     printf("%s\n", a);
   else {
        for (j = i; j <= n; j++) {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j));
       }
   }
} 

int main(int argc, char **argv) {
	factorial();
	char word[20];
	scanf("%s", word);
	int length = strlen(word);
	permute(word, 0, length - 1);
	return 0;
}