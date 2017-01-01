/* This program defines the basic properties
 * of vector manipulations, sucha as addition
 * length, dot and cross product.
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool equality(double a[], double b[], int size);
void addition(double a[], double b[], int size);
void substraction(double a[], double b[], int size);
void scalar(double a[], int size);
void length(double a[], int size);
void dot_product(double a[], double b[], int size);

int main(void)
{
	// Vector construction over memory
	double a[100];
	double b[100];
	int dimension;
	// Input basic operations of needed processing data
	printf("Introduce the dimension of your vector space: ");
	scanf("%d", &dimension);
	printf("Introduce the first vector.\n");
	for(int i = 0; i < dimension; i++) scanf("%lf",&a[i]);
	printf("Introduce the secnd vector.\n");
	for(int i = 0; i < dimension; i++) scanf("%lf",&b[i]);
	// Are they equal?
	if(equality(a, b, dimension)) printf("\nTHEY ARE EQUAL.\n");
	else printf("\nTHEY ARE NOT EQUAL.\n");
	// Addition and substraction (a + b) and (a - b)
	printf("\nTHE SUM IS:\n");
	addition(a, b, dimension);
	printf("\nTHE REST IS:\n");
	substraction(a, b, dimension);
	printf("\nA TIMES THE SCALAR\n");
	scalar(a, dimension);
	printf("\nB TIMES THE SCALAR\n");
	scalar(b, dimension);
	printf("\nA NORM\n");
	length(a, dimension);
	printf("\nB NORM\n");
	length(b, dimension);
	printf("\nDOT PRODUCT\n");
	dot_product(a, b, dimension);
	return 0;
}
bool equality(double a[], double b[], int size)
{
	bool equal;
	for(int i = 0; i < size; i++) 
	{
		equal = (a[i] == b[i]);
		if(equal == false) break;
	}
	return (equal);	
}
void addition(double a[], double b[], int size)
{
	double sum[size];
	for(int i = 0; i < size; i++) 
		sum[i] = a[i] + b[i];
	for(int i = 0; i < size; i++)
		printf("%lf\n", sum[i]);
}
void substraction(double a[], double b[], int size)
{
	double sub[size];
	for(int i = 0; i < size; i++) 
		sub[i] = a[i] - b[i];
	for(int i = 0; i < size; i++)
		printf("%lf\n", sub[i]);
}
void scalar(double a[], int size)
{
	double scalar;
	double prod[size];
	printf("Introduce an scalar: ");
	scanf("%lf",&scalar);
	for(int i = 0; i < size; i++) 
		prod[i] = scalar * a[i];
	for(int i = 0; i < size; i++)
		printf("%lf\n", prod[i]);
}
void length(double a[], int size)
{
	double sum_squares = 0;
	double norm;
	for(int i = 0; i < size; i++)
		sum_squares += (a[i] * a[i]);
	norm = sqrt(sum_squares);
	printf("%lf\n", norm);
}
void dot_product(double a[], double b[], int size)
{
	double dot = 0;
	for(int i = 0; i < size; i++)
		dot += (a[i] * b[i]);
	printf("%lf\n", dot);
}