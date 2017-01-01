#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double combination(int n, int k);
long long fact(long long n);
int main(int argc, char const *argv[]) {

	int cases;
	int flag = 1;
	
	scanf("%d", &cases);
	while(cases > 0) {
		int size;
		scanf("%d", &size);

		float data[size];
		float sum = 0.0;
		int i;
		for(i = 0; i < size; i++) {
			scanf("%f", &data[i]);
			sum += combination(size - 1, i) * data[i];
		}
		printf("Case #%d: %.3f\n", flag, sum);
		cases--;
		flag++;
	}
	return 0;
}

long long fact(long long n) {

	int i = 1;
	while(n > 0) {
		i *= n;
		n--;
	}
	return i;

}

double combination(int n, int k) {

	long long num = fact(n);
	long long den = fact(k) * fact(n - k);
	double nCk = num / den;
	return nCk / pow(2.0, n);
}