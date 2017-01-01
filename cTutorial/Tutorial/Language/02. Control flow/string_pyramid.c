#include <stdio.h>

int main(void)
{
	char name[40];
	for(int i = 0; i < 40; i++) name[i] = ' ';
	
	printf("Enter a first and last name, (NAME LAST NAME.): ");
	for(int j = 0; j < 40; j++) 
	{
		scanf("%c", &name[j]);
		if(name[j] == '\n') break;
	}
	printf("Your name is: ");
	for(int k = 0; k < 40; k++) 
	{
		if(name[k] != ' ')
		{
			for(int l = k-1; l < 40; l++) printf("%c", name[l]);
			// printf("%c", name[k]);


		}
			
	}
}