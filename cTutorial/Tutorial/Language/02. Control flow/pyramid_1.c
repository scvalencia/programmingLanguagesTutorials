#include <stdio.h>
int main(void)
{
	int n;
	printf("Enter the side of the pyramid: ");
	scanf("%i",&n);
	for(int i = 1; i < n;i++){		
		for(int j = 0; j < i;j++)
			printf("*");	
		printf("\n");
	}
	return(0);
}
