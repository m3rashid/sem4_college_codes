/*
 * Weddle's Rule
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
    float num = 1;
    float denom = 1.0 + x * x;

    return num / denom;
}

float WeedleRule(float a, float b) {
    double h = (b - a) / 6;
    float sum = 0;
    sum = sum + (((3 * h) / 10) * (y(a) + y(a + 2 * h) + 5 * y(a + h) + 6 * y(a + 3 * h) + y(a + 4 * h) + 5 * y(a + 5 * h) + y(a + 6 * h)));
    return sum;
}

int main() {
    float a = 0, b = 6;
    printf("\nf(x) = %f\n", WeedleRule(a, b));

    return 0;
}
