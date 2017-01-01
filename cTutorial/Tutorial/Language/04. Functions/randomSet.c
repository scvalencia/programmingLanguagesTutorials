/* 
 * File:   DCh5Ex14.c
 * Author: me
 *
 * Problem 5.14
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main(void) {
    int a[5] = {2, 4, 6, 8, 10};
    int b[5] = {3, 5, 7, 9, 11};
    int c[5] = {6, 10, 14, 18, 22};
    srand(time(NULL));
    int index = (rand() % 5);
    printf("%d\n", a[index]);
    printf("%d\n", b[index]);
    printf("%d\n", c[index]);
    return 0;
}

