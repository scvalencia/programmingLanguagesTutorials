#include <stdio.h>
int main(void)
{
	int c;
	while ((c = getchar()) != EOF)
	{
	
		if (c == ' ' || c == '\t' || c == '\\') 
		{
			putchar('\\');
			putchar('\\');
			
		}		
		else putchar(c);
	 }
	   
}