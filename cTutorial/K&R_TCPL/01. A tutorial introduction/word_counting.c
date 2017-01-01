#include <stdio.h>

#define IN 1     
#define OUT 0
int main(void)
{ 
	int c, nw, nc, state;
	
	state = OUT;
	nw = nc = 0;
	while ((c = getchar()) != '\n') 
	{
		++nc;
		if (c == ' ' || c == '\n' || c == '\t') state = OUT;
		else if (state == OUT) 
		{
			state = IN;
			++nw;			
		}		
	}
	printf("Number of words: %d\nNumber of characters: %d\n", nw, nc);
}