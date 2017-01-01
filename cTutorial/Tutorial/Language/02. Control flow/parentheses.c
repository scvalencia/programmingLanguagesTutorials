# include <stdio.h>
int main(void) {
	char a[100];
	int c = 0;
	printf("Introduce the sequence of parentheses: ");
	for(int i = 0; i < 100; i++) {
		scanf("%c", &a[i]);		
		if(a[i] == '\n') break;
		else c++;
	}
	char array[c];
	for(int i = 0; i < c; i++) 
		array[i] = a[i];
	int count = 0;
	for(int i = 0; i < c; i++) {
		if(array[i] == '(')
			count++;
		else if(array[i] == ')')
			count--;
		else printf("Invalid string.\n");
	}
	if(count == 0) printf("Valid string.\n");
	else printf("Invalid string.\n");
}