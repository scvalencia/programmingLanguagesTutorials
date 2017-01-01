#include <stdio.h>

int my_strlen(char* string);
int summation(int array[], int n);

int main(int argc, char **argv) {
	char word[100] = "My word";
	int array[5] = {1,2,3,4,5};
	int len = my_strlen(word);
	printf("%d %d\n", len, summation(array, 5));
	return 0;
}

int my_strlen(char* string) {
	int ans = 0;
	for(; *string != '\0'; string++)
		ans++;
	return ans;
}

int summation(int array[], int n) {
	int i = 0;
	int ans = 0;
	for(; i < n; i++)
		ans += array[i];
	return ans;
}


