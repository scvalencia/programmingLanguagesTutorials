#include <stdio.h>
int main(void)
{
	int n = 0;
	int l = 1;
	
	while(n <= 100)
	{
		if((n-1) % 10 == 0) printf("new line\n");
		else printf("*\n");
		++n;
	}
	return(0);
}
