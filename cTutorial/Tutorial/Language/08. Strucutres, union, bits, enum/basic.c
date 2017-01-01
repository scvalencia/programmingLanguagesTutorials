#define MAXNOM 40
#define MAXID 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
	char name[MAXNOM + 1];
	char id[MAXID + 1];
	int age;	
};

void displayInformation(struct Employee emp) {
	printf("%s %s %d\n", emp.name, emp.id, emp.age);
}

int main(int argc, char const *argv[]) {
	struct Employee e1;

	strcpy(e1.name, "Ernesto");
	strcpy(e1.id, "1010211109");
	e1.age = 45;

	struct Employee e2 = {"Camilo", "7932323", 45};
	struct Employee e3 = {.name = "Juan", .id = "23848839", .age = 34};

	struct Employee* employees = (struct Employee*) malloc(3 * sizeof(struct Employee));

	*(employees + 0) = e1;
	*(employees + 1) = e2;
	*(employees + 2) = e3;

	int i = 0;
	for(; i < 3; i++)
		displayInformation(*(employees + i));

	return 0;
}

