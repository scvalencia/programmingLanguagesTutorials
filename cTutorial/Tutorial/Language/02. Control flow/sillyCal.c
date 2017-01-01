#include <stdio.h>
int main(void) {
	int m, s;
	printf("Enter number of days in month: ");
	scanf("%d", &m);
	printf("Enter starting day of the week (1 = sun, 7 = sat): ");
	scanf("%d", &s);
	int count = 0;
	int c = 1;
	while(count < (m+2)) {
		while(count < (s-1)) {
			printf("   ");
			count++;
		}
		if(count % 7 == 0)
			printf("\n");
		printf("%2d ", (c));
		count++;
		c++;
	}
	printf("\n");

}