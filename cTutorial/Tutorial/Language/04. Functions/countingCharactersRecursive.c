/* 
 * Counting Occurrences of a Character in a String 
 * make countingCharactersRecursive && ./countingCharactersRecursive
 * rm countingCharactersRecursive && make countingCharactersRecursive && ./countingCharactersRecursive
 */
 #include <stdio.h>
 int count(char ch, const char *str);
 int main(void) {
 	char str[80]; 
 	char target; 
 	int my_count;
	printf("Enter up to 79 characters.\n");
	scanf("%s", &str);
	printf("Enter the character you want to count: ");
	scanf("%c", &target);	
	printf("The number of occurrences of %c in\n\"%s\"\nis %d\n", target, str, my_count);
	return 0;
 }
 int count(char ch, const char *str) {
 	int ans;
  	if (str[0] == '\0')
 		ans = 0;
 	else if (str[0] == ch) 
 		ans = 1 + count(ch, &str[1]);
 	else
 		ans = count(ch, &str[1]);
 	return ans; 	
 }