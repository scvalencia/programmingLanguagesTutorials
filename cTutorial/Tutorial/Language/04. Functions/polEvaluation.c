// make polEvaluation && ./polEvaluation
# include <stdio.h>
long long int power(int base, int exponent);
long long int evaluation(int array[], int degree, int evaluation_value);
int main(void) {
	int degree, evaluation_value = 0;
	printf("Introduce the degree of the polynomial: ");
	scanf("%d", &degree);
	int coefficients[degree + 1];
	printf("Introduce the coefficients of your polynomial: ");
	for(int i = 0; i <= degree; i++)
		scanf("%d", &coefficients[i]);
	printf("Introduce the evaluation value of the polynomial: ");
	scanf("%d", &evaluation_value);
	long long int value = evaluation(coefficients, degree, evaluation_value);
	printf("The polynomial evaluates to: %lli\n", value);
}
long long int evaluation(int array[], int degree, int evaluation_value) {
	long long int value = 0;
	for(int i = 0; i <= degree; i++)
		value += array[i] * power(evaluation_value, i);
	return value;
}
long long int power(int base, int exponent) {
	if(exponent == 0 || exponent == 1) return(base);
	else return((base) * (power(base, exponent - 1)));
}