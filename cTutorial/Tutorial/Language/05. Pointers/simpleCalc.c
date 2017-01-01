// make simpleCalc && ./simpleCalc

#include <stdio.h>
#include <math.h>

void scan_data(char* operator, double* value);
void do_next_operation(char operator, double operand, double* stack);

int main(int argc, char *argv[]) {
	char op;
	double in;
	double stack;

	while(op != 'q') {

		scan_data(&op, &in);		
		do_next_operation(op, in, &stack);
		printf("The result so far is %.2f\n", stack);

	}
	/* code */
	return 0;
}

void scan_data(char* operator, double* value) {
	scanf("%c%lf", operator, value);
}

void do_next_operation(char operator, double operand, double* stack) {
	
	if(operator == '+') 
		*stack += operand; 
	else if(operator == '-')
		*stack -= operand;
	else if(operator == '*')
		*stack *= operand;
	else if(operator == '/')
		*stack /= operand;
	else if(operator == '^')
		*stack = pow(*stack, operand);
	else
		*stack = *stack;

}