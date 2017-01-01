#include <stdio.h>
/* Copy input to output */

int main(void)
{
	int c;
	int count = 0;
	while ((c = getchar()) != EOF) 
	{
		if (c == ' ')
		{
			if(count == 0)
			{
				count = 1;
				putchar(c);
			}

			
		}
		else
		{
			count = 0;
			putchar(c);
		}
	    
	}
	
	
}