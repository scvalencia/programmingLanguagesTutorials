#include <stdio.h>
// make basicPointers && ./basicPointers && rm basicPointers
int main(void) {
	int m = 10, n = 5;
	int *mp, *np;
	mp = &m;
	np = &n;
	*mp = *mp + *np;
	*np = *mp - *np;
	printf("%d\t%d\t%p\t%p\t%d\t%d\n", m , n , mp, np, *mp, *np);
}