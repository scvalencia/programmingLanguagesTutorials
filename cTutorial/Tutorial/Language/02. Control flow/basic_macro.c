#include <stdio.h>
#define FOR_UPTO(start, stop, step) for(int i = start; i < stop; i += step)
#define FOR_DOWNTO(start, stop, step) for(int i = start; i > stop; i -= step)
#define is ==


int main(int argc, char const *argv[])
{
	FOR_UPTO(0, 10, 1) {
		printf("%d\n", i);
		if(i is 5)
			break;
	}

	FOR_DOWNTO(10, -1, 1) {
		printf("%d\n", i);
	}
	return 0;
}