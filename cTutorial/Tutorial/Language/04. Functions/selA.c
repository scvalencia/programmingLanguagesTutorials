#include <stdio.h>
#include <math.h>
#define PI 3.14159f

float cuadrado(float side);
float triangulo(float base, float altura);
float circulo(float radio);
float circuloO(float radioS, float radioI);

int main(void)
{
	int selection;
	float area;

	printf("Introduzca el número de selección: ");
	scanf("%d", &selection);

	if (selection == 1)
	{
		float area, lado;
		printf("Introduzca el lado del cuadrado: ");
		scanf("%f", &lado);
		area = cuadrado(lado);
		printf("El área del cuadrado de lado %f unidades es %f unidades cuadradas\n", lado, area);

	}
	else if (selection == 2)
	{
		float area, base, altura;
		printf("Introduzca la base del triángulo: ");
		scanf("%f", &base);
		printf("Introduzca la altura del triángulo: ");
		scanf("%f", &altura);
		area = triangulo(base, altura);
		printf("El área del triángulo de base %f unidades y %f unidades de altura es %f unidades cuadradas\n", base, altura, area);
	}
	else if (selection == 3)
	{
		float area, radio;
		printf("Introduzca el radio del circulo: ");
		scanf("%f", &radio);
		area = circulo(radio);
		printf("El área del circulo de radio %f unidades es %f unidades cuadradas\n", radio, area);
	}
	else if (selection == 4)
	{
		float area, radioS, radioI;
		printf("Introduzca el radio exterior del circulo: ");
		scanf("%f", &radioS);
		printf("Introduzca el radio interior del circulo: ");
		scanf("%f", &radioI);
		area = circuloO(radioS, radioI);
		printf("El área del circulo de radio exterior %f e interior %f es %f \n", radioS, radioI, area);
	}
	else
		printf("La seleccion está fuera del rango.\n");
	return(0);

}
float cuadrado(float side)
{
	float resp;
	resp = side * side;
	return(resp);
}
float triangulo(float base, float altura)
{
	float resp;
	resp = (base * altura) / 2;
	return(resp);
}
float circulo(float radio)
{
	float resp;
	resp = PI * (radio * radio);
	return(resp);
}
float circuloO(float radioS, float radioI)
{
	float resp;
	float areaA, areaB;
	areaA = (radioS * radioS) * PI;
	areaB = (radioI * radioI) * PI;
	if (areaA < areaB)
	{
		printf("Esto no tiene sentido\n");
	    return(0);
	}
	else
	{
		resp = areaA - areaB;
		return(resp);
	}
}