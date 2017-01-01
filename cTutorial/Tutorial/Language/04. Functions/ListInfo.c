#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isMultiple(int value, int seed);
int sumOfDigits(int value);
bool isPrimeNumber(int value);
int processMultiplicity(int element);
int parityOfDigits(int element);

int main(void) {

	int input[] = {104, 3773, 13, 121, 77, 30751};

	for(int i = 0; i < 6; i++) {
		int a = input[i];
		printf("%d\t\t%d %d %d\n", a, processMultiplicity(a), parityOfDigits(a), isPrimeNumber(a));
	}	
	
}

bool isMultiple(int value, int seed) {
	return value % seed == 0;
}

int sumOfDigits(int value) {

	int sum = 0;

	while(value > 0) {

		sum += value % 10;
		value /= 10;

	}

	return sum;
}

bool isPrimeNumber(int value) {

	if(value <= 1 || value % 2 == 0)
		return false;

	int flag = (int) sqrt(value);

	for(int i = 3; i < flag; i+= 2)
		if(value % i == 0)
			return false;

	return true;
}

int processMultiplicity(int element) {

	if(isMultiple(element, 7) || isMultiple(element, 11) || isMultiple(element, 13))
		return 1;
	return 0;

}

int parityOfDigits(int element) {

	if(sumOfDigits(element) % 2 == 0)
		return 1;
	return 0;
}