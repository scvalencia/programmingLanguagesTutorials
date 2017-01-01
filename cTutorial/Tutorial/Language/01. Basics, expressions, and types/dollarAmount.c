#include <stdio.h>

void pay_amount(int, int*, int*, int*, int*);

int main(void) {
	int amount;
	printf("Enter a dollar amount: ");
	scanf("%d", &amount);

	int twenty, ten, five, one;

	pay_amount(amount, &twenty, &ten, &five, &one);

	printf("$20 bills: %d\n", twenty);
	printf("$10 bills: %d\n", ten);
	printf("$5 bills: %d\n", five);
	printf("$1 bills: %d\n", one);
}

void pay_amount(int dollars, int* twenties, int* tens, int* fives, int* ones) {

	*twenties = dollars / 20;
	dollars = dollars - (*twenties * 20);
	*tens = dollars / 10;
	dollars = dollars - (*tens * 10);
	*fives = dollars / 5;
	dollars = dollars - (*fives * 5);
	*ones = dollars;

}