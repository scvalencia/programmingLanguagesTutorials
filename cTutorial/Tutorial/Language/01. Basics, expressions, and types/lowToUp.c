#include <stdio.h>

int main(void) {
	char input;
	scanf("%c", &input);
	printf("%c\n",(((int) input) - 32));
	return 0;
}