#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int main(void) {
	for(int i = 1; i <= 1000; i++) 
		if(is_perfect(i)) 
			printf("%d ", i);	
		printf("\n");	
}
bool is_perfect(int a) {
	int var = 0;
	bool ans = false;
	for(int i = 1; i < a; i++) 
		if((a % i) == 0) {
			var+=i;
			printf("%d ", i);
		}
	if(var == a)
		return true;
	return ans;
}

