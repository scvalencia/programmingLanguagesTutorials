#include <stdio.h>

void indirection1();
void indirection2();
void indirection3(int *pa, int i);

int main(int argc, char const *argv[]) {
	int a = 5, i = 0;
	indirection1();
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	indirection2();
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	for(; i < 99; i++)
		indirection3(&a, i);
	for(i = 0; i < 16*4; i++)
		printf("%4p\n", ((void *) (long) i));
	return 0;
}

void indirection1() {
	int i = 99, *p = &i;
	printf("*p := %d\n", *p);
	printf("*&p := %p\n", *&p);
	printf("*&i := %d\n", *&i);
	printf("&p := %p\n", &p);
	printf("&*p := %p\n", &p);
	printf("&i := %p\n", &i);
}

void indirection2() {
	int i = 10, j = 20, *p = &i, *q = &j;
	p = *&q;
	p = q;
	*p = *q;
}

void indirection3(int *pa, int i) {
	printf("%4d := %p -> %d\n", i, pa + i, *(pa + i));
}