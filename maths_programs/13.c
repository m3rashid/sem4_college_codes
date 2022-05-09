/*
 * PROGRAM TO FIND SUM OF FIRST 15 TERMS OF SINE SERIES AT x=0.12
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>

int factorial(int n) {
    return n == 0 ? 1 : n * factorial(n - 1);
}

int main() {
    printf("20BCS033 MD Rashid Hussain\n");

    int i, j = 1;
    float x = 0.12, sum = 0;

    for (i = 1; i <= 15; i++) {
        sum += pow(-1, i) * pow(x, j) / factorial(j);
        j += 2;
    }

    printf("sum of sine series is %f\n", sum);

    return 0;
}