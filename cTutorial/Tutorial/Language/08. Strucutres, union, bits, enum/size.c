#include <stdio.h>
	
int main(int argc, char **argv) {

	struct IDENTIFICACION {
		char genero;
		int nombre[20];
		int cedula;
	};
	
	struct EMPLEADO {
		int salario;
		struct IDENTIFICACION id;
		char horasMes[12];
		short retencion;
	};

	struct EMPLEADO nomina[150];

	printf("%lu\n", sizeof(nomina));

	struct EMPLEADO* p = &nomina[0];
	int* a = &(nomina[30].id.nombre[10]);
	printf("%p\n", p);
	printf("%p\n", a);

	printf("\n");
	printf("%lu\n", sizeof(nomina[30].id.nombre[10]));



// Tamaño nómina en bytes y kbits --> suma normal && (15450 * 8 bits) / 1024 ( 1 kbit son 10254 bits)
// si direccion Inicial es 0x10B4, en que dirección está nomina[30].id.nombre[10]
	// 30 * 103 + 4 + 1 + 10 * 4 = 3135
	//10B4 = 4276
	//4276 + 3135 =ALGO
	// RTA = hexa(ALGO)
}