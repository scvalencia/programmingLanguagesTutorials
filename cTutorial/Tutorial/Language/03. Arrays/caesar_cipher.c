# include <stdio.h>
# define N 100
int main(void) {
	char message[N];
	char sign;
	int var = -1;
	int shift;
	for(int i = 0; i < N; i++) message[i] = ' ';
	printf("Enter message to be encrypted: ");
	for(int j = 0; j < N; j++) {
		scanf("%c", &message[j]);		
		if(message[j] == '.') {
			sign = message[j];
			break;
		}
		else var++;
	}
	printf("Enter shift ammount (1-25): ");
	scanf("%d", &shift);
	if((shift > 25) || (shift < 1)) {		
		printf("The shift amount doesn't makes any sense at all.\n");
		main();
	}
	char final[var];
	for(int i = 0; i <= var; i++) final[i] = ' ';
	for(int y = 0; y <= var; y++) final[y] = message[y];
	for(int i = 0; i <= var; i++) {
		if((final[i] != '.') || (final[i] != ' ')) {
			if('a' <= final[i] && final[i] <= 'z')
				final[i] = (((final[i] - 'a') + shift) % 26 + 'a');      			   
   			else if('A' <= final[i] && final[i] <= 'Z')
   				final[i] = (((final[i] - 'A') + shift) % 26 + 'B');	
  		} 		
	}
	for(int y = 0; y <= var; y++) printf("%c", final[y]);
	printf("\n");
}