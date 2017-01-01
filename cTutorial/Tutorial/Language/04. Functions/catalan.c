# include <stdio.h>
long int factorial(int number);
unsigned long long catalan(int number);
int main(void) {
	int number;
	printf("Introduce a number: ");
	scanf("%d", &number);
	for(int i = 0; i <= number; i++) 
		printf("%llu ", catalan(i));
	printf("\n");
	return(0);
}
long int factorial(int number) {
	if (number == 0)
		return(1);
	else
		return(number * factorial(number - 1));
}
unsigned long long catalan(int number) {
	return (factorial(2 * number) /((factorial(number + 1)) * factorial(number)));
}