#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv) {

	int lenInput;
	int controlCounter = 0;
	float outputStructures[lenInput][4];

	for(int i = 0; i < lenInput; i++)
		for(int j = 0; j < 4; j++)
			outputStructures[i][j] = 0.0;

	int countFlag = 0;

	scanf("%d", &lenInput);
	while(controlCounter < lenInput){

		if(countFlag == 2)
			countFlag = 0;

		char input;
		int charpCount = 0;
		int numGroups = 0;
		scanf("%c", &input);
		while(true) {
			if(input == ' ') 
				numGroups += 1;
			else if(input == '#')
				charpCount += 1;
			else if(input == '\n') {
				if(charpCount == 0) 
					numGroups = 0;
				else
					numGroups += 1;
				break;
			}
		}

		switch(countFlag) {
			case 0:
				outputStructures[controlCounter][countFlag] = numGroups;
				break;

			case 1:
				outputStructures[controlCounter][countFlag] = charpCount;

			case 2:
				outputStructures[controlCounter][countFlag] = (numGroups == 0)? 0 : (float) charpCount / (float) numGroups;

		}

		controlCounter += 1;
		countFlag += 1;		
	}

	printf("%d %d %f\n", (int)outputStructures[0][1] , (int)outputStructures[0][2], outputStructures[0][2]);
}