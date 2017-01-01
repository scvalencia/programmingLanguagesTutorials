#include <stdio.h>
int main() {
	int c;
	int array[1000] = {0};
	while((c = getchar()) != '\n') {
		int element = (char) c;
		array[element]++;
	}
	printf("\n");
	for(int i = 33; i <= 126; i++) {
		if(array[i] != 0) {
			printf("|%c|: ", i);
			for(int j = 0; j < array[i]; j++) printf("*");
			printf("\n");
		}
		else printf("");
	}  
}