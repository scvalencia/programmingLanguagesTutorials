/* 
 * File:   DCh5Ex5.c
 * Author: me
 *
 * Problem 5.9
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN_HOURS 3.00
float calculate_Charges(float parkingHours);
int main(void) {

    float hoursCar1, hoursCar2, hoursCar3;
    float chargesC1, chargesC2, chargesC3;
    printf("Introduce de hours of the three clients: ");
    scanf("%f%f%f", &hoursCar1, &hoursCar2, &hoursCar3);
    chargesC1 = calculate_Charges(hoursCar1);
    chargesC2 = calculate_Charges(hoursCar2);
    chargesC3 = calculate_Charges(hoursCar3);
    float sumHours = hoursCar1 + hoursCar2 + hoursCar3;
    float sumCharges = chargesC1 + chargesC2 + chargesC3;
    printf("CAR     HOUR      CHARGE\n");
    printf("1       %.2f      %.2f\n", hoursCar1, chargesC1);
    printf("2       %.2f      %.2f\n", hoursCar2, chargesC2);
    printf("3       %.2f     %.2f\n", hoursCar3, chargesC3);
    printf("TOTAL   %.2f     %.2f\n", sumHours, sumCharges);    
}
float calculate_Charges(float parkingHours) {
    float base = 02.00;
    float difference = parkingHours - MIN_HOURS;
    float integerPart = ceil(difference);        
    if (difference <= 0)
        return base;
    else if (difference >= 21.0)
        return base * 5.0;
    else {
        if ((integerPart - difference) == 0)
            base += integerPart * 0.5;
        else
            base += (integerPart * 0.5) + 0.5;
    } 
    return base;
}
