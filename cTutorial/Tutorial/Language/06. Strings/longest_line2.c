# include <stdio.h>
int gl(char array[]);
int copy(char to[]; char from[]);
int main(void) {
	int len, max;
	char line[100], longest[100];
	max = 0;
	while((len = gl(line)) > 0)
		if(len > max) {
			max = len;
			copy(longest, line);
		}
}  
int gl(char array[]) {
	int c, i;
	for(i = 0; (c = getchar()) != '\n'; i++)
		array[i] = c;
	return i;
} 
void copy(char to[], char from[]) {
	int i = 0;
	while((to[i] = from[i]) != '\0')
		i++;
}                                                                      