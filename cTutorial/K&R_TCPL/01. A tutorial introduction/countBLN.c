#include <stdio.h>
int main(void)
{
	int nb, nt, nl;
   int c;
	nb = 0;
	nt = 0;
	nl = 0;

	while ((c = getchar()) != '0')
	{
		if (c == ' ') nb++;
		if (c == '\t') nt++;
		if (c == '\n') nl++;
	}
	printf("The number of blanks is: %d\n",nb);
	printf("The number of tabs is: %d\n",nt);
	printf("The number of lines is: %d\n",nl);
}