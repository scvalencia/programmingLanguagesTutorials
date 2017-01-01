#include <stdio.h>
#include <stdbool.h>

int onesInBinary(int n);

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d\n", onesInBinary(n));
}

int onesInBinary(int n) {
	int ans = 0;
	if(n % 2 == 0) {
	int count = 0;
		while(n != 0) {
			int m = n % 2;
			n = n / 2;
			count += m;   
		}
		ans = count;
		return ans;
	}
	else
		return onesInBinary(n / 2) + 1;
	return ans;
}