#include <stdio.h>
#include <ctype.h>

void scan_line(char line[80], int *pv, int *pc, int *pd, int *pw, int *po) {
	char c;
	int count = 0;

	while((c = toupper(line[count])) != '\0') {
		if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
			(*pv)++;
		else if(c >= 'A' && c <= 'Z')
			(*pc)++;
		else if(c >= '0' && c <= '9')
			(*pd)++;
		else if(c == ' ' || c == '\t')
			(*pw)++;
		else 
			(*po)++;
		++count;
	}	
}

int main(int argc, char const *argv[]) {

	char line[80];
	int vowels = 0;
	int constants = 0;
	int digits = 0;
	int whitespaces = 0;
	int others = 0;

	printf("Enter a line of text below: \n");
	scanf("%s", line);

	scan_line(line, &vowels, &constants, &digits, &whitespaces, &others);

	printf("\nNo. of vowels: %d", vowels);
	printf("\nNo. of constants: %d", constants);
	printf("\nNo. of digits: %d", digits);
	printf("\nNo. of whitespaces: %d", whitespaces);
	printf("\nNo. of others: %d\n\n", others);

	return 0;
}