#include <stdio.h>
int main(void)
{
	int num;
	num = 0;
	while (num >= 0)
	{
		while(getchar() != '\n') 
		{
			num++;
		}
		printf("%d\n", num);
		num = 0;		
	}	
}