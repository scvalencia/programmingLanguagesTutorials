# include <stdio.h>
# define N 100
int main(void) {
	char name[N];
	char sign;
	int var = -1;
	for(int i = 0; i < N; i++) name[i] = ' ';
	printf("Enter a sentence: ");
	for(int j = 0; j < N; j++) {
		scanf("%c", &name[j]);		
		if((name[j] == '?') || (name[j] == '.')) {
			sign = name[j];
			name[j] = ' ';
			break;
		}
		else var++;
	}
	char array[var];
	for(int i = 0; i <= var; i++) array[i] = ' ';
	for(int y = 0; y <= var; y++) array[y] = name[y];
	int stop = var;
	int begin;
	printf("Reversal of sentence:");
	for(int i = var; i >= 0; i--) {
		if(array[i] == ' ' && true) {
			begin = i;
			for(int j = begin; j <= stop; j++) {
				if(array[j] != ' ')
					printf("%c", array[j]);	
			}						
			stop = begin;
		}
	}
	printf(" ");
	for(int j = 0; j < begin; j++) printf("%c", array[j]);
	printf("%c\n", sign);	
}