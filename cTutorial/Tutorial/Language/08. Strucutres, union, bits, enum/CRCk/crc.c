
// Proyecto1.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdlib.h" 
#include "stdio.h"
#include "math.h"

typedef struct text
{
	unsigned char *mensaje;
	int tamanho;
} TEXTO;

FILE *streamArchivo; // Hex file
int k;

//Procedimentos
void cargarArchivo(TEXTO *data, char *nomArchivoEntrada, int n);
void guardarArchivo(TEXTO *arch, char * nomArchivoSalida);
void corregirPrimerBloque(unsigned short * primerBloque, int tamanhoCodigo);
unsigned short recibirGenerador();
void agregarBit(unsigned short * txt, unsigned char bit);
void reemplazarCeros(TEXTO * txt, unsigned short residuo);

//Funciones
unsigned short leerPrimerBloque(TEXTO *datos);
unsigned short division(TEXTO * txt, unsigned short clave);
unsigned short recibirGenerador();
int darTamanho(unsigned short bloq);
unsigned char bajarDigito(unsigned char * msj, int bitpos);


////////////////////////////////////////////////////////////////////////
//MAIN
////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	char caso;
	TEXTO *arch = (TEXTO*)malloc(sizeof (TEXTO));
	unsigned short generador;
	unsigned short residuo;
	if (argc < 2)
	{
		printf("Faltan argumentos\n");
		system("pause");
		return -1;
	}

	printf("Indique la accion\n\t1) Incrustar codigo de deteccion\n\t2) Comprobar integridad\n\n");
	caso = getchar();
	if (caso == '1')
	{
		if (argc < 3)
		{
			printf("Falta la direccion de destino\n");
			system("pause");
			return -1;
		}
		printf("Cargando Mensaje...\n");
		cargarArchivo(arch, argv[1], 2);

		printf("\nIngrese el codigo generador:\n");
		generador = recibirGenerador();

		k = darTamanho(generador);

		residuo = division(arch, generador);

		reemplazarCeros(arch, residuo);

		//Guarda el archivo con el codigo de redundancia incrustado
		guardarArchivo(arch, argv[2]);
	}
	else if (caso == '2')
	{
		if (argc > 2)
		{
			printf("Solo debe ingresar la ruta de la respuesta a verificar\n");
			system("pause");
			return -1;
		}
		cargarArchivo(arch, argv[1], 0);
		printf("\nIngrese el codigo generador:\n");
		generador = recibirGenerador();

		k = darTamanho(generador);

		residuo = division(arch, generador);
		if(!residuo)
		{
			printf("El mensaje no contiene errores\n");
		}
		else
		{
			printf("El mensaje contiene errores\n");
		}
	}
	else
	{
		printf("El caso seleccionado no es valido\n");
	}

	printf("\n----------------------FIN----------------------\n");
	system("pause");
}

////////////////////////////////////////////////////////////////////////
//PROCEDIMIENTOS
////////////////////////////////////////////////////////////////////////


/**
* Corrige el primer bloque, haciendo corrimiento tal que el tamaño del bloque sea igual a k. <br>
* <b>post: </b> primerBloque == Bloque corregido.
* @param primerBloque El primer bloque extaido del mensaje
*/
void corregirPrimerBloque(unsigned short * primerBloque, int tamanhoCodigo) {
	int tamanioMax = darTamanho(*primerBloque); // Tamaño del bloque menos uno, para cumplir la especifiación anotada en el informe
	int tamanioMin = tamanhoCodigo; // cantidad de bits a extraer
	int p = tamanioMax - 1; // desde donde
	int n = tamanioMin; // hasta donde
	*primerBloque = (*primerBloque >> (p + 1 - n) & ~(~0 << n)); // ver getbit, y explicación en informe

	/*
		Otra alternativa mas clara, sería
		int val = darTamanho(* primerBloque) - k;
		* primerBloque = * primerBloque >> val;
		Esta consiste en correr el primer bloque tantas posiciones como la diferencia
		entre el tamaño del bloque y k.
	*/
}

/**
* Agrega el bit al short en la posicion menos significativa, corriendo los demás bits del short una posición a la izquierda. <br>
* <b>post: </b> txt corrido una posición a la izquierda y el bit agregado en la posición menos significativa.
* @param txt Bloque al cual se desea agregar el bit
* @param bit valor del bit que se desea agregar. bit=1 o bit=0.
*/
void agregarBit(unsigned short * txt, unsigned char bit) {
	int realBit = (bit == '0') ? 0 : 1; // El bit de verdad, es decir, parsing al valor real que representa el char
	*txt = (*txt << 1) | realBit; // Corrimietno y OR sobre el bit que llega
}

/**
* Reemplaza los (k-1) ceros al final del mensaje por los (k-1) bits menos significativos del residuo. <br>
* <b>post: </b> Modifica el valor del mensaje.
* @param txt Estructura que contiene el mensaje con los k-1 ceros agregados
* @param residuo Residuo de la divisio.
*/
void reemplazarCeros(TEXTO * txt, unsigned short residuo) {
	unsigned short shift = residuo & ~(~0 << (k - 1)); // El corrimiento que se hace AND residuo
	*txt->mensaje = *txt->mensaje | shift; // OR corrimiento
}

//NO MODIFICAR
void cargarArchivo(TEXTO *data, char *nomArchivoEntrada, int n)
{
	int tam;
	unsigned char * aux;
	int i;
	errno_t err;
	err = fopen_s(&streamArchivo, nomArchivoEntrada, "r");
	if (err == 0)
	{
		//Se abrio de forma correcta
	}
	else
	{
		printf("No se puede abrir el archivo: %s\n", nomArchivoEntrada);
		system("pause");
		exit(EXIT_FAILURE);
	}

	fseek(streamArchivo, 0, SEEK_END);
	tam = ftell(streamArchivo);
	fseek(streamArchivo, 0, SEEK_SET);

	aux = (unsigned char*)calloc(tam+n, 1);

	fread(aux, 1, tam, streamArchivo);

	data->tamanho = tam+n;
	data->mensaje = aux;

	if (fclose(streamArchivo) != 0)
	{
		printf("Error cerrando el archivo");
	}
}

//NO MODIFICAR
void guardarArchivo(TEXTO *arch, char * nomArchivoSalida)
{
	FILE *streamArchivo;     

	if ( !( streamArchivo = fopen( nomArchivoSalida, "wb" ) ) ){
		printf( "No se puede abrir el archivo: %s\n", nomArchivoSalida );
		system("pause");
		exit( EXIT_FAILURE );
	}

	fwrite( (arch->mensaje), 1, (arch->tamanho), streamArchivo );

	if(fclose (streamArchivo)!=0)
	{
		printf("Error cerrando el archivo");
	}
}



////////////////////////////////////////////////////////////////////////
//FUNCIONES
////////////////////////////////////////////////////////////////////////

//NO MODIFICAR
unsigned short recibirGenerador()
{
    unsigned short codigo;
	scanf("%hd", &codigo);
    return codigo;  
}

unsigned short division(TEXTO * txt, unsigned short generador)
{	
	unsigned short primerBloque=leerPrimerBloque(txt); //Se obtiene el primer bloque del mensaje
	int tamanhoResiduo = darTamanho(primerBloque); //Guarda el tamaño del residuo, se incia con el tamaño del primer bloque
	int posActual = 16; //Es la posicion a partir de la cual se comienzan a bajar bits para el desarrollo de la division
	unsigned short residuo;  //Guarda el residuo en cada paso de la division, se inicia con el primer bloque
	unsigned char bitBajar;  //Bit a bajar para que el divisor 'quepa' en el residuo
	

	//fin = Numero de bits totales del mensaje con k-1 ceros incrustados al final
	//(txt->tamanho - 2):			numero de bytes del mensaje sin contar los dos bytes del final
	//(txt->tamanho - 2) * 8):		numero de bits del mensaje
	//(tamanhoCodigo - 1):			k-1 ceros al final del mensaje
	int fin = ((txt->tamanho - 2) * 8) + (k - 1); 


	//En caso de que el tamaño del primer bloque sea mayor al tamaño del codigo, el primer bloque debe someterse a desplazar sus bits
	//lo necesario, y la posicion actual de igual forma es modificada.
	if (k<tamanhoResiduo) 
	{
		corregirPrimerBloque(&primerBloque, k);
		posActual = 16-(tamanhoResiduo - k);
	}

	residuo = primerBloque;
	//Se realizan las iteraciones de la division
	while (posActual < fin)
	{
		if (tamanhoResiduo < k)
		{
			// Obtniene el valor del bit en la posicion actual
			unsigned char bitPosActual = bajarDigito((txt->mensaje), posActual);
			// Agrega el bit recién obtenido al residuo
			agregarBit(&residuo, bitPosActual);
			posActual++;
		}
		tamanhoResiduo = darTamanho(residuo);
		// finalmente, si el tamaño del residuo es igual a k, retorne la división con
		// el residuo corregido.
		if(tamanhoResiduo == k) {
			reemplazarCeros(txt, residuo);
		}
		//En caso de que el tamaño del residuo sea igual al tamaño del generador (k), se realiza la division
		
	}

	return residuo;
}


/**
* Calcula el tamaño del short (el número de dígitos binarios contando a partir del 1 más significativo). <br>
* @param txt Bloque al cual se desea calcular el tamaño
* @return Tamaño del bloque
*/
int darTamanho(unsigned short bloq) {
	return floor(log2(bloq)) + 1; // La deducción formal de la fórmula se encuentra en el informe
	/*
		Otra alternativa, m'as computacional y menos matem'atica, sería realizar el suigiente proceso
		int i = 16;
		unsigned short test;
		while(i > 0 && ((test = bloq) >> i) & 1)
		i--;
		return i;
		Pero este no es portable, como se desearía
	*/
}

/**
* Lee el primer bloque del mensaje, es decir, los 2 primeros bytes, para conformar un short. <br>
* @param txt Estructura que contiene el mensaje con los ceros agregados
* @return Bloque leido.
*/
unsigned short leerPrimerBloque(TEXTO *datos) {
	int sizeOfMensaje = darTamanho(*datos->mensaje); // Tamaño de mensaje
	unsigned short val = *datos->mensaje & (~0 << (sizeOfMensaje - 16)); // Corrimiento y AND
	return val;
}


/**
* Lee el digito(bit) en la posición deseada del mensaje (indicada por bitpos). <br>
* @param msj Estructura que contiene el mensaje con los k-1 ceros agregados
* @bitpos Posicion de msj de la cual se desea leer el dígito
* @return Dígito leido del mensaje. Dígito=1 | Dígito=0.
*/
unsigned char bajarDigito(unsigned char * msj, int bitpos) {
	// (*msj >> bitpos) & 1; es quizá la forma más clara para realizar este proceso,
	// sin embargo, para usar el desarrollo del procedimiento getbits, se desarrolla de esta forma,
	// pues sería coger hasta un dígito a partidr de la posición (ver informe)
	//	int flag = (n >> k) & ~(~0 << 1);
	//return (flag == 0) ? '0' : '1';

	int flag = (*msj >> bitpos) & ~(~0 << 1);
	return (flag == 0) ? '0' : '1';
}

