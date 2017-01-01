#include <stdio.h>
/* Copy input to output */
int main(void)
{	int c, d;
	c = getchar() != EOF;
    printf("%d\n",c);
    c = getchar() == EOF;
    printf("%d\n",d);	
}