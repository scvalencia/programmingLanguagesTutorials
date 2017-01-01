#include <stdio.h>
#include <math.h>


double input(char* msg) {
	double toReturn;
	printf("%s", msg);
	scanf("%lf", &toReturn);
	return toReturn;
}

char* raw_input(char* msg) {
	char* toReturn;
	printf("%s", msg);
	scanf("%s", toReturn);
	return toReturn;
}

int main(void) {
	double number = input("Introduce a number: ");
	printf("%.2lf\n", number);
	char* name = raw_input("Your name is: ");
	
}