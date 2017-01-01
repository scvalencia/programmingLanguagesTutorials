#include <stdio.h>
#include <math.h>


int main(void)
{
	float value1, value2;
	char selection;
	float val;

	printf("Introduzca los valores y el operador de la fomra v o v: ");
	scanf("%f%c%f", &value1, &selection, &value2);

	if (selection == '+')
	{
		val = value1 + value2;
	}
	else if (selection == '-')
	{
		val = value1 - value2;
	}
	else if (selection == '*')
	{
		val = value1 * value2;
	}
	else if (selection == '/')
	{
		if (value2 == 0)
		{
			printf("La división por cero no está definida\n");
		}
		else
		{
			val = value1 / value2;
	    }
	}
	else
		printf("Operador desconocido\n");

	printf("%f\n", val);
	return(0);	
}