#include <stdio.h>
void hanoi(int pieces, char initial_pile, char final_pile, char temp_pile);
int main(void) {
	int n;
	printf("Introduce the number of disks: ");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
void hanoi(int pieces, char initial_pile, char final_pile, char temp_pile) {
	if(pieces == 1) {
		printf("%c -> %c\n", initial_pile, final_pile);
		return;
	}
	hanoi(pieces - 1, initial_pile, temp_pile, final_pile);
	printf("%c -> %c\n", initial_pile, final_pile);
	hanoi(pieces - 1, temp_pile, final_pile, initial_pile);
}