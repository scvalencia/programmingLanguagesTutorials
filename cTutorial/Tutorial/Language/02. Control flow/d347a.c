#include <stdio.h>
#include <math.h>
int factorial(int n);
int main(void)
{
	int jei;
	printf("Introduce a number: ");
	scanf("%i",&jei);
	int ipso = factorial(jei);
	printf("Its facorial is %d\n",ipso);

}


int factorial(int n)
{
    int r = 1;
    while (n > 1)
    {
        r = r * n;
        n--;
    }
    return(r);
}