/*
 * PROGRAM TO FIND GCD USING EUCLID'S ALGORITHM
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <stdio.h>

int GCD(int M, int N) {
    return M == 0 ? N : N == 0 ? M
                    : M == N   ? M
                    : N > M    ? GCD(N, M)
                               : GCD(N, M % N);
}

int main() {
    printf("20BCS033 MD Rashid Hussain\n");

    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int gcd = GCD(a, b);
    printf("GCD of %d and %d is %d\n", a, b, gcd);

    return 0;
}
