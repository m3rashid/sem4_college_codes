/*
 * PROGRAM TO FIT A STRAIGHT LINE y=mx+c
 * USING LAGENDRE PRINCIPLE OF LEAST SQUARES
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

    int i, n;
    float m, c;
    float x[10], y[10], sum_x, sum_y, sum_xy, sum_sqx;

    sum_x = sum_y = sum_xy = sum_sqx = 0;
    printf("Enter the number of points i.e. value of n: ");
    scanf("%d", &n);
    printf("Enter %d poinys one by one:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_sqx += x[i] * x[i];
    }

    m = (n * sum_xy - sum_x * sum_y) / (n * sum_sqx - sum_x * sum_x);
    c = (sum_y - m * sum_x) / n;
    printf("m=%f \t c=%f\n", m, c);
    printf("Line of best fit is y=%fx+%f\n", m, c);

    return 0;
}
