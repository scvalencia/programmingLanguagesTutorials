#include <stdio.h>
int main(void)
{
	int c, num_lines;
	while ((c = getchar()) != '0')
	{
		if (c == '\n') num_lines++;
	}
	printf("%d\n",num_lines);
}