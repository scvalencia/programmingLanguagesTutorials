#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void processInput(double a, char o, double b);

int main(void) {
	double a, b;
	char operator;

	while(true) {
		printf(">> ");
		scanf("%lf %c %lf", &a, &operator, &b);
		if(a == b && operator == '-') {
			processInput(a, operator, b);
			break;
		}
		processInput(a, operator, b);
	}

	return 0;
}

void processInput(double a, char o, double b) {

	switch(o) {
		case '+':
			printf("=  %.2lf\n", a + b);
			break;

		case '-':
			printf("=  %.2lf\n", a - b);
			break;

		case '*':
			printf("=  %.2lf\n", a * b);
			break;

		case '/':
			if(b == 0)
				printf("ERROR: (%c) operator over corrupted operands.\n", o);
			else 
				printf("=  %.2lf\n", a / b);
			break;

		case '%':
			if((int) b == 0)
				printf("ERROR: (%c) operator over corrupted operands.\n", o);
			else 
				printf("=  %d\n", (int)a % (int)b);
			break;

		case '^':		
			printf("=  %.2lf\n", pow(a, b));
			break;

		default:
			printf("Not recognized operator\n.");
			break;
	}
}