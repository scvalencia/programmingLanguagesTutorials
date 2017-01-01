#include <stdio.h>

#define STACK_SIZE 11
#define STACK_EMPTY '0'

void push(char* stack, char item, int *top, int max_size);
char pop(char* stack, int* top);

int main(int argc, char *argv[]) {
	char s[STACK_SIZE];     // A stack of characters
	int s_top = 1; 			// Stack is empty
}

void push(char* stack, char item, int *top, int max_size) {
	if(*top < max_size - 1) {
		++(*top);
		stack[*top] = item;
	}
}

char pop(char* stack, int* top) {

	char item;
	if(*top >= 0) {
		item = stack[*top];
		--(*top);
	}
	else {
		item = STACK_EMPTY;
	}

	return item;

}