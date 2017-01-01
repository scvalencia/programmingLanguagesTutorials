#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char *argv[] ) {

	char* word = argv[1];
	FILE *ptr_file = fopen("wordlist.txt", "r");
	char buf[128];

	//printf("%lu\n", strlen(word));

	while (fgets(buf, 1000, ptr_file) != NULL) {
		/*if(strncmp(word, buf, strlen(word)) == 0)
			printf("%s", buf); */ // Starts with

		if(strncmp(word, buf, strlen(word)) == 0) {
			printf("YES\n");
			fclose(ptr_file);
			return 0;
		}

		
	}

	printf("NO\n");
	fclose(ptr_file);

	return 0;

}