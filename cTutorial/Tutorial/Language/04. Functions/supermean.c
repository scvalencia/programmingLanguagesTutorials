#include <stdio.h>
#include <math.h>

int combination(int n, int k) {

	if(k < 0 || k > n)
		return 0;
	if(k == 0 || k == n)
		return 1;
	int num_flag = n - k;
	if(k > num_flag)
		k = num_flag;	
	int ans = 1;
	int i;
	for(i = 0; i < k; i++) 
		ans = ans *  (n - i) / (i + 1);
	return ans;

}

double log_fac(int m, int n) {

	double sum = 0.0;
	int i = m;
	for(; i <= n; i++)
		sum += log((double)i);
	return sum;

}

int log_binomial(int n, int k) {

    if(k > (n - k))
        return (log_fac(n - k + 1, n) - log_fac(2, k));
    else
        return (log_fac(k + 1, n) - log_fac(2, n - k));

}

int main(int argc, char const *argv[]) {
	
	int cases;
	int flag = 1;
	
	scanf("%d", &cases);
	while(cases--) {

		int size;
		scanf("%d", &size);

		float data[size];
		float sum = 0.0;

		int i;
		for(i = 0; i < size; i++) {
			scanf("%f", &data[i]);
			sum += combination(size - 1, i) * data[i];
		}
		sum *= (1 / pow(2.0, size - 1));
		printf("Case #%d: %.3f\n", flag, sum);
		flag++;
	}
	return 0;

}