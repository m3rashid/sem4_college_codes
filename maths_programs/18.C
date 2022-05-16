/*
 * Milne's Method
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>

float f(float a, float b) {
    float r = (a * a + 3.0 * b * b) / 10.0;
    return r;
}

int main() {
    float x0, y0, h, xh, x[10], y[10];
    float f1, f2, f3, f4;
    int i, n;

    x0 = 1;
    y0 = 2;
    h = 0.2;
    xh = 2.0;
    n = (xh - x0) / h;
    x[0] = x0;
    y[0] = y0;

    for (i = 0; i <= n; i++) {
        x[i] = x[0] + i * h;
    }

    for (i = 1; i <= n; i++) {
        float k1 = h * f(x0, y0);
        float k2 = h * f(x0 + h / 2.0, y0 + k1 / 2.0);
        float k3 = h * f(x0 + h / 2.0, y0 + k2 / 2.0);
        float k4 = h * f(x0 * h, y0 + k3);
        y[i] = y[i - 1] + (1.0 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        x0 = x0 + h;
        y[0] = y[i];
    }

    f1 = f(x[1], y[1]);
    f2 = f(x[2], y[2]);
    f3 = f(x[3], y[3]);
    y[4] = y[0] + (4.0 * h) / 3.0 * (2.0 * f1 - f2 + 2.0 * f3);  // Milne's Predictor Formula
    f4 = f(x[4], y[4]);
    float yc = y[2] + h / 3.0 * (f2 + 4.0 * f3 + f4);

    while (fabs((yc - y[4])) / yc <= 0.0001) {
        y[4] = yc;
        f4 = f(x[4], yc);
        yc = y[2] + h / 3.0 * (f2 + 4.0 * f3 + f4);
    }
    printf("x \t\t y");
    for (i = 1; i < 4; i++) {
        printf("%f \t %f \n", x[i], y[i]);
    }
    printf("\n");

    return 0;
}
