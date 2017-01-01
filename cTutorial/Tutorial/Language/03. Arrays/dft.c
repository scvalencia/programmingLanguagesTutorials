#include <stdio.h>
#include <math.h>
#include <complex.h>
#define N 8
#define PI 3.14159265359f

double complex dft(int inreal[], int inimag[], int position) ;
int main(void) {
	int i,o;
	int sumr;
	int sumi;
	int inreal[N];
	int inimag[N];

	printf("\nIntroduzca los %d coeficientes de la señal:\n", N);
	for(i = 0; i < N; i ++) {
		printf("x[%d]> ",i);
		scanf("%d+%di", &inreal[i], &inimag[i]);
		sumr += inreal[i];
		sumi += inimag[i];

    }
    printf("La DFT de la señal es:\n");
    for(o = 0; o < N; o++) {
    	double complex pos = dft(inreal,inimag,o);
    	printf("X[%d] = %.2f + %.2fi\n", o, creal(pos), cimag(pos));
    }  
}
double complex dft(int inreal[], int inimag[], int position) {
	int k;
	double complex out[N];
	for (k = 0; k < N; k++) {  
		double sumreal = 0;
		double sumimag = 0;
		int n;
		for (n = 0; n < N; n++) {  
			sumreal +=  inreal[n]*cos(2*M_PI * n * k / N) + inimag[n]*sin(2*M_PI * n * k / N);
			sumimag += -inreal[n]*sin(2*M_PI * n * k / N) + inimag[n]*cos(2*M_PI * n * k / N);
		}
		out[k] = (sumreal + I * sumimag)/N; 
	}
	return out[position];
}
