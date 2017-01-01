#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int question(int a, int b);
int main(void) {
	srand(time(NULL));
	int n;
	int m;
	bool is_bad = true;
	while(is_bad) {
		n = (rand() % 10);
		m = (rand() % 10);
		int k = n * m;
		if (question(n,m) == k)
			is_bad = false;
	}	
}
int question(int a, int b) {
	int ans;
	printf("How much is %d times %d?: ", a, b);
	scanf("%d", &ans);
	return ans;
}