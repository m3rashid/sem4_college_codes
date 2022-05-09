/*
 * PROGRAM TO FIND COS(X) USING FUNCTION
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <stdio.h>

double COS(double x) {
    x = x * 3.1415 / 180.0;
    double result = 1;
    double sign = 1, fact = 1, pow = 1;
    for (int i = 1; i <= 10; i++) {
        sign = sign * -1;
        fact = fact * (2 * i - 1) * (2 * i);
        pow = pow * x * x;
        result = result + sign * pow / fact;
    }
    return result;
}
int main() {
    printf("20BCS033 MD Rashid Hussain\n");
    for (double i = 0; i <= 180; i += 30) printf("cos(%.0lf) = %.3lf\n", i, COS(i));

    return 0;
}
