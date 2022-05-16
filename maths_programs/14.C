/*
 * Newton Raphson method
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>
float f(float x) {
    return cos(x) - x * exp(x);
}

float df(float x) {
    return -sin(x) - exp(x) - x * exp(x);
}

int main() {
    float a, b;
    system("clear");
    printf("Enter initial approximation of the root: \n");
    scanf("%f", &a);

    for (int itr = 1; itr <= 15; itr++) {
        b = a - f(a) / df(a);
        if (f(b) == 0) {
            printf("\n Actual root is :   %f", b);
            break;
        } else {
            a = b;
            printf("\n Approximation to the root is:   %f", b);
        }
    }
    printf("\n");

    return 0;
}
