#include <stdio.h>

int main(void)
{
	int data;
	printf("Enter the sequence, the first value should be the length of the sequence\n");
	scanf("%d",&data);
	
   int i = 0, sum = 0, number;
	while (i < data)
	{
		scanf("%d",&number);
		sum += number;
		i++;				
	}
	printf("%d",sum);

	return 0;
}