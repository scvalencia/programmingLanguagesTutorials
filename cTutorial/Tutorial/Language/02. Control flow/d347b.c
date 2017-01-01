#include <stdio.h>
#include <math.h>
int factorial(int n);
int main(void)
{

    int i = 0;
    float zuku;
    while (i < 100)
    {
        zuku = 1/factorial(i);
        i++;
    }
    printf("%f\n",zuku);
    return(0);

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