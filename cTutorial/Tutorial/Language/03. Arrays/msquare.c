# include <stdio.h>
int main(void) {
	int size; 	
	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99\n");
	printf("Enter size of magic square: ");
	scanf("%d", &size);
	if ((size % 2 == 0) || (size < 1) || (size > 99)) {
		printf("Out of bounds. Try again\n");
		main();
	}
	int magic_square[size][size];
	for (int row = 0; row < size; row++) {
    	for(int columns = 0; columns < size; columns++)
         	magic_square[row][columns] = 0;
    }
    int x = 0, y = ((size - 1) / 2);
    int fila, columna;
	magic_square[x][y] = 1;
	for (int k = 2; k < size * size; k++) {
		fila = ((x - 1) < 0)? size - 1: x - 1;
		columna = ((y - 1) < 0)? size - 1: y - 1;
		if (magic_square[fila][columna] != 0) {
			fila = ((x + 1) < size)? x + 1: 0;
			columna = y;
		}
		magic_square[fila][columna] = k;
		x = fila;
		y = columna;		
	}
	for (int row = 0; row < size; row++) {
    	for(int columns = 0; columns < size; columns++)
         	printf("%2d\t", magic_square[row][columns]);
    	printf("\n");
    }
}