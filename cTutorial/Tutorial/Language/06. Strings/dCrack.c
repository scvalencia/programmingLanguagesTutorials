#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	if(argc != 2)
		return 1;

	char* user = argv[1];
	FILE* ptr_file = fopen("passwords.txt", "r");
	char buf[1000];

	while (fgets(buf, 1000, ptr_file) != NULL) {

		if(strncmp(user, buf, strlen(user)) == 0) {
			int j;
			for(unsigned long i = 0; i < strlen(buf); i++) 
				if(buf[i] == ':')
					j = i;
			for(unsigned long i = j + 1; i < strlen(buf); i++) 
				printf("%c", buf[i]);
			fclose(ptr_file);
			return 0;
		}

		
	}

	return 0;
}