#include <stdio.h>
#include <math.h>

void scan_fraction(int* n, int* m);
void print_fraction(int num, int den);
void reduce_fraction(int* num, int* den);
void add_fractions(int n1, int d1, int n2, int d2);
void sub_fractions(int n1, int d1, int n2, int d2);
void prd_fractions(int n1, int d1, int n2, int d2);
void div_fractions(int n1, int d1, int n2, int d2);
int gcd(int, int);

int main(void) {

	printf("\nWelcome to FRAC 2.0v -0.1 software system.\n");

	

	while(1) {


		int option;
		printf("1. Reduce fraction.\n");
		printf("2. Add fractions.\n");
		printf("3. Substract fractions.\n");
		printf("4. Multiply fractions.\n");
		printf("5. Divide fractions.\n\n");
		printf("~");

		scanf("%d", &option);
		int n1, d1, n2, d2;

		switch(option) {

			case 1:

				printf(">> ");
				scan_fraction(&n1, &d1);
				reduce_fraction(&n1, &d1);
				print_fraction(n1, d1);
				break;

			case 2:

				printf(">> ");
				scan_fraction(&n1, &d1);
				printf(">> ");
				scan_fraction(&n2, &d2);
				add_fractions(n1, d1, n2, d2);
				break;

			case 3:

				printf(">> ");
				scan_fraction(&n1, &d1);
				printf(">> ");
				scan_fraction(&n2, &d2);
				sub_fractions(n1, d1, n2, d2);
				break;

			case 4:

				printf(">> ");
				scan_fraction(&n1, &d1);
				printf(">> ");
				scan_fraction(&n2, &d2);
				prd_fractions(n1, d1, n2, d2);
				break;

			case 5:

				printf(">> ");
				scan_fraction(&n1, &d1);
				printf(">> ");
				scan_fraction(&n2, &d2);
				div_fractions(n1, d1, n2, d2);
				break;

			default:
				return 0;

		}
	}

	
	return 0;

}

void scan_fraction(int* n, int* d) { 

	scanf("%d/%d", n, d);

}

void print_fraction(int num, int den) {

	if(den == 1)
		printf("~%d\n", num);
	else
		printf("~%d/%d\n", num, den);
	printf("\n");

}

void reduce_fraction(int* num, int* den) {

	int temp = *num;
	*num = *num / gcd(temp, *den);
	*den = *den / gcd(temp, *den);

}

void add_fractions(int n1, int d1, int n2, int d2) {

	int n;
	int d;

	if(d1 == d2) {
		d = d1;
		n = n1 + n2;
	}
	else {
		n = n1*d2 + n2*d1;
		d = d1 * d2;
	}

	reduce_fraction(&n, &d);
	print_fraction(n, d);

}

void sub_fractions(int n1, int d1, int n2, int d2) {

	int n;
	int d;

	if(d1 == d2) {
		d = d1;
		n = n1 - n2;
	}
	else {
		n = n1*d2 - n2*d1;
		d = d1 * d2;
	}

	reduce_fraction(&n, &d);
	print_fraction(n, d);

}

void prd_fractions(int n1, int d1, int n2, int d2) {

	int n = n1 * n2;
	int d = d1 * d2;

	reduce_fraction(&n, &d);
	print_fraction(n, d);

}

void div_fractions(int n1, int d1, int n2, int d2) {

	int n = n1 * d2;
	int d = d1 * n2;

	reduce_fraction(&n, &d);
	print_fraction(n, d);

}

int gcd ( int a, int b ) {
  int c;
  while ( a != 0 ) {
     c = a; 
     a = b % a;  
     b = c;
  }
  return b;
}