#include <stdio.h>

void fact_print(int number);

int main(void) {
	int number;
	printf("Enter an integer between 0 and 9 or -1 to quit >> ");
	scanf("%d", &number);
	if(number < 0)
		return 0;
	fact_print(number);
	return 0;
}

void fact_print(int number) {

	int fact = number;
	printf("***************************************************************\n");
	if(number == 0 || number == 1)
		printf("* %d! = 1\n", number);
	else{
		printf("* %d! = %d x", number, number);

		while(number > 1) {
			number -= 1;
			fact *= number;
			if(number == 1)
				printf(" %d = ", number);
			else
				printf(" %d x", number);
		}

		printf("%d", fact);
		printf("\n");
	}
	printf("***************************************************************\n");

}