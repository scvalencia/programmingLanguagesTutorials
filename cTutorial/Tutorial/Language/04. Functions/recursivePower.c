// make recursivePower && ./recursivePower
# include <stdio.h>
long long int power(int base, int exponent) {
	long long int answer;
	if(exponent == 0 || exponent == 1) 
		return base;
	else {
		if((exponent % 2) == 0) {
			int middle = exponent / 2;
			return(power(base, middle) * power(base, middle));
		}
		else
			return((base) * (power(base, exponent - 1)));
	}
}
int main(void) {
	long long int power(int base, int exponent);
	int base, powe;
	printf("Introduce the base and the power: ");
	scanf("pow(%d,%d)", &base, &powe);
	power(base, powe);
	printf("%d to the power of %d is: %lli\n", base, powe, power(base, powe));
	return 0;
}