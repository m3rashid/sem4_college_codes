/*
 * PROGRAM TO FIND GCD AND LCM OF 4 NUMBERS
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <stdio.h>

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b % a, a);
}

int main() {
    printf("20BCS033 MD Rashid Hussain\n");

    int a, b, c, d;
    printf("Enter 4 numbers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int GCD = gcd(gcd(a, b), gcd(c, d));
    printf("GCD of 4 numbers is %d\n", GCD);

    int LCM = a * b * c * d / gcd(gcd(a * b * c, a * b * d), gcd(a * c * d, b * c * d));
    printf("LCM of 4 numbers is %d\n", LCM);

    int max = a > b ? a > c ? a > d ? a : d : c : b;
    printf("Maximum of 4 numbers is %d\n", max);
    int min = a < b ? a < c ? a < d ? a : d : c : b;
    printf("Minimum of 4 numbers is %d\n", min);

    return 0;
}
