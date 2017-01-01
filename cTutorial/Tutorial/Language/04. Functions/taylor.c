#include <stdio.h>
long long int factorial(int n);
int main(void) {
	int n;
	printf("n:: ");
	scanf("%d", &n);
	float sum = 0.0;
	for(int i = 0; i <= n; i++) {
		sum += (1/(float)factorial(i));
	}
	printf("%f\n", sum);	
}
long long int factorial(int n) {
	long long int ans = 1;
	int j = n;
	while(j > 0) {
		ans *= j;
		j--;
	}
	return ans;
}