/*
 * Boole's Rule
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>

float y(float x) {
    return (1 / (1 + x));
}

float BooleRule(float a, float b) {
    int n = 4;
    int h;
    h = ((b - a) / n);
    float sum = 0;
    float bl = (7 * y(a) + 32 * y(a + h) + 12 * y(a + 2 * h) + 32 * y(a + 3 * h) + 7 * y(a + 4 * h)) * 2 * h / 45;

    sum = sum + bl;
    return sum;
}

int main() {
    float lowlimit = 0;
    float upplimit = 4;
    printf("f(x) = %.4f\n", BooleRule(0, 4));
    return 0;
}
