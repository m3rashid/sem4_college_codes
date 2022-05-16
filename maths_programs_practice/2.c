/*
 * PROGRAM TO COMPUTE VALUE OF nCr USING RECURSIVE FUNCTION
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <stdio.h>

long int fact(int n) {
    return (n == 0 || n == 1) ? 1 : n * fact(n - 1);
}

int main() {
    printf("20BCS033 MD Rashid Hussain\n");

    int n, r;
    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("Enter value of r: ");
    scanf("%d", &r);

    long ncr = fact(n) / (fact(r) * fact(n - r));
    printf("Value of %dC%d is %ld\n", n, r, ncr);

    return 0;
}
