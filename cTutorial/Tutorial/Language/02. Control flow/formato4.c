#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv) {
	
	char input;
	int charpCount = 0;
	int numGroups = 0;
	scanf("%c", &input);
	while(true){
		if(input == '\n') {
			if(charpCount == 0) 
				numGroups = 0;
			else
				numGroups += 1;
			break;
		}
		if(input == ' ')
			numGroups += 1;
		else if(input == '#')
			charpCount += 1;
		scanf("%c", &input);
	}

	printf("%d %d %.2f\n", numGroups, charpCount, (numGroups == 0)? 0 : (float) charpCount / (float) numGroups);
}