/*
 * Print the first 100 prime numbers not divisible by 5, 7
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int isPrime(int n) {
    int prime = 1;
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            prime = 0;
            break;
        }
    }
    return prime;
}
int main() {
    int counter = 0;
    printf("\nFirst 100 prime numbers are:\n");
    for (int i = 2; counter <= 101; i++) {
        if (isPrime(i) == 1) {
            if (i % 5 != 0 && i % 7 != 0) {
                printf("%d ", i);
            }
            counter++;
        }
    }
    printf("\n");

    return 0;
}
