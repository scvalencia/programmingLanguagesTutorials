#include <stdio.h>

int main(int argc, char const *argv[]) {
	char* s = "Abecedariozzz";
	int v[26];
	int i = 0;
	for(;i < 26; i++)
		v[i] = 0;
	for(i = 0; *(s+i) != '\0'; i++) {
		int index = 0;
		char ch = *(s+i);
		if(ch >= 'A' && ch <= 'Z') {
			char min = ch + 32;
			v[min - 97] += 1;
		}
		if(ch >= 'a' && ch <= 'z')
			v[ch - 97] += 1;
	}
	for(i = 0; i < 26; i++)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}