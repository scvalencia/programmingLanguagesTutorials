#include <stdio.h>
#include <math.h>
#include <complex.h>
#define PI 3.14159f

float equivalente (float r1, float r2, float r3);
float divisor (float volt, float r1, float r2, float r3, float resistencia);

int main(void)
{
	// Inputs
	float resistenciaA, resistenciaB, resistenciaC;
	float voltaje;

    // Input basic functions
	printf("\nIntroduzca el valor de la resistencia 1 en Ohms: ");
	scanf("%f", &resistenciaA);
	printf("Introduzca el valor de la resistencia 2 en Ohms: ");
	scanf("%f", &resistenciaB);
	printf("Introduzca el valor de la resistencia 3 en Ohms: ");
	scanf("%f", &resistenciaC);
    printf("Introduzca el valor del voltaje en Volts: ");
	scanf("%f", &voltaje);

	// Basic output variables
	float va, vb, vc;
	float equiv;
	va = divisor(voltaje, resistenciaA, resistenciaB, resistenciaC, resistenciaA);
	vb = divisor(voltaje, resistenciaA, resistenciaB, resistenciaC, resistenciaB);
	vc = divisor(voltaje, resistenciaA, resistenciaB, resistenciaC, resistenciaC);
	equiv = equivalente(resistenciaA, resistenciaB, resistenciaC);

	// Output processes
	printf("\nLa resistencia equivalente del circuito es: %f\n \n", equiv);
	printf("El voltaje de la resistencia 1 es: %f\n", va);
	printf("El voltaje de la resistencia 2 es: %f\n", vb);
	printf("El voltaje de la resistencia 3 es: %f\n \n", vc);
}
float equivalente (float r1, float r2, float r3)
{
	float resp;
	resp = r1 + r2 + r3;
	return(resp);
}
float divisor (float volt, float r1, float r2, float r3, float resistencia)
{
	float vn;
	float suma;
	suma = equivalente(r1, r2, r3);
	vn = (resistencia * volt) / suma;
	return(vn);
}


