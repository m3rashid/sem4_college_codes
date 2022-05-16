/*
 * PROGRAM TO FIND CUBES OF FIRST 10 NATURAL NUMBERS
 * AND THEIR SUM USING FUNCTION
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>

int main() {
    printf("20BCS033 MD Rashid Hussain\n");

    int i;
    long int sum = 0, c;

    for (i = 1; i <= 10; i++) {
        c = pow(i, 3);
        sum += c;
        printf("cube of natural number %d is %ld\n", i, c);
    }
    printf("sum of cubes of first 10 natural numbers is %ld\n", sum);

    return 0;
}
