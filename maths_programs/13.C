/*
 * Bisection method
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>

float func(float x) {
    return x * x * x - x + 11;
}

int main() {
    float a, b, c;
    system("clear");
    printf("Enter initial approximations of the root: \n");
    scanf("%f %f", &a, &b);

    if (func(a) * func(b) >= 0) {
        printf("Root is not lying between a and b\n");
    } else {
        for (int itr = 1; itr <= 15; itr++) {
            c = (a + b) / 2.0;
            if (func(c) == 0)
                break;
            else {
                if (func(a) * func(c) < 0)
                    b = c;
                else
                    a = c;
            }
            printf("\n Approximation to the root is:   %f", c);
        }
    }
    printf("\n");

    return 0;
}
