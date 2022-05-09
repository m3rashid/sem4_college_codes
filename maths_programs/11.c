/*
 * PROGRAM TO CONVERT GIVEN DECIMAL NUMBER TO BINARY
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <stdio.h>

int main() {
    printf("20BCS033 MD Rashid Hussain\n");

    int i, j, num, p;
    int M[100];
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    p = num;
    i = 0;
    while (num > 0) {
        M[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("Binary Equivalent of %d is: ", p);
    for (j = i - 1; j >= 0; j--) printf("%d", M[j]);
    printf("\n");

    return 0;
}