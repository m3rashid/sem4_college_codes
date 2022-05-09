/*
 * PROGRAM TO CONVERT A GIVEN BINARY NUMBER TO DECIMAL
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

    int n, i, bin[100], sum = 0;
    printf("Enter a binary number: ");
    scanf("%d", &n);

    i = 0;
    while (n > 0) {
        bin[i] = n % 10;
        sum += bin[i] * pow(2, i);
        n = n / 10;
        i++;
    }
    printf("Decimal Equivalent of %d is: %d\n", n, sum);

    return 0;
}