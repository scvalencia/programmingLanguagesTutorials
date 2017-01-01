#include <stdio.h>
#include <math.h>
#include <complex.h>
#define N 8
#define PI 3.14159265359f

double complex idft(float inreal[], float inimag[], int position) ;
int main(void)
{
	int i,o;
	int sumr;
	int sumi;
	float inreal[N];
	float inimag[N];

	printf("\nIntroduzca los %d coeficientes de la señal:\n", N);
	for(i = 0; i < N; i ++)
	{
		printf("X[%d]> ",i);
		scanf("%f+%fi", &inreal[i], &inimag[i]);
		sumr += inreal[i];
		sumi += inimag[i];

    }

    printf("La IDFT de la señal es:\n");
    for(o = 0; o < N; o++)
    {
    	double complex pos = idft(inreal,inimag,o);
    	printf("x[%d] = %.7f %+.7fi\n", o, creal(pos), cimag(pos));
    }  
}
double complex idft(float inreal[], float inimag[], int position) 
{
	int k;
	double complex out[N];
	for (k = 0; k < N; k++) 
	{  
		double sumreal = 0;
		double sumimag = 0;
		int n;
		for (n = 0; n < N; n++)
		 {  
			sumreal += inreal[n]*cos(2*M_PI * n * k / N) - inimag[n]*sin(2*M_PI * n * k / N);
			sumimag += inreal[n]*sin(2*M_PI * n * k / N) + inimag[n]*cos(2*M_PI * n * k / N);
		}
		out[k] = (sumreal + I * sumimag); 
	}
	return out[position];
}
