#include <stdio.h>
#include <stdbool.h>
#define SIZE 100
#define CLOSED false

int main(void) {
	bool doors[SIZE];
	for(int i = 1; i < SIZE; i++)
		doors[i] = CLOSED;

	for(int j = 1; j < SIZE; j++) 
		for(int i = 1; i < SIZE; i++) 
			if(i % j == 0)
				doors[i] = !doors[i];
	for(int i = 0; i < SIZE; i++)
		(doors[i] == 0? printf("%d >> closed\n", i) : printf("%d >> open\n", i));
}

	
