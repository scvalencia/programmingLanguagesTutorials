#include <stdio.h>
int main(void) {
	char name[40];
	int space = 0;
	int space2 = 0;
	int definitive;
	for(int i = 0; i < 40; i++) name[i] = ' ';
	printf("Enter a first and last name, (NAME LAST NAME.): ");
	for(int j = 0; j < 40; j++) {
		scanf("%c", &name[j]);
		if(name[j] == '\n') break;
	}
	printf("Your name is: ");
	for(int k = 0; k < 40; k++) {
		if(name[k] == ' ') space = k;
		if(space > 0) break;			
	}
	for(int p = space+1; p < 40; p++) {
		if(name[p] == ' ') space2 = p;
		if(space2 > 0) break;
	}
	definitive = space2 - 1;
	for(int y = space; y < definitive; y++) printf("%c", name[y]);
	printf(", ");
	printf("%c.", name[0]);
	printf("\n");
}