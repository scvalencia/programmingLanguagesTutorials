#include <stdio.h>
#include <math.h>

void find_two_largest(int a[], int n, int* largest, int* secnd_largest);
void sep(double num, char* sign, int* whole, double* frac);
int *find_largest(int a[], int n);

int main(void) {

	int a[10] = {1,2,3,4,5,6,7,8,11,10};
	int large, scndLarge = 0;
	char sn;
	double num = -35.0817;
	int whole;
	double frac;
	find_two_largest(a, 10, &large, &scndLarge);
	printf("L : %d, S : %d\n", large, scndLarge);
	printf("%d\n", *find_largest(a, 10));
	sep(num, &sn, &whole, &frac);
	printf("%c --> %d --> %f\n", sn, whole, frac);
	return 0;
}

void find_two_largest(int a[], int n, int* largest, int* secnd_largest) {

	*largest = a[0];
	*secnd_largest = a[0];
	for(int i = 0; i < n; i++) {
		if(a[i] > *largest) {
			*secnd_largest = *largest;
			*largest = a[i];
		}
		else if(a[i] > *secnd_largest)
			*secnd_largest = a[i];			
	}
}

int *find_largest(int a[], int n) {

	int* max = &a[0];
	for(int i = 0; i < n; i++)
		if(a[i] > *max)
			max = &a[i];
	return max;
}

void sep(double num, char* sign, int* whole, double* frac) {

	double magnitude;

	if(num < 0)
		*sign = '-';
	else if(num == 0)
		*sign = ' ';
	else
		*sign = '+';

	magnitude = fabs(num);
	*whole = floor(magnitude);
	*frac = magnitude - *whole;

}