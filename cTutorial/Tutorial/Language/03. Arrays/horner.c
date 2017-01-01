#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

double horner(double *coeffs, int s, double x);
int main(int argc, char **argv) {
	double coeffs[] = { -19.0, 7.0, -4.0, 6.0 };
	printf("%5.1f\n", horner(coeffs, sizeof(coeffs)/sizeof(double), 3.0));
	return 0;
}
double horner(double *coeffs, int s, double x) {
  int i;
  double res = 0.0; 
  for(i= s-1; i >= 0; i--)
    res = res * x + coeffs[i];
  return res;
}