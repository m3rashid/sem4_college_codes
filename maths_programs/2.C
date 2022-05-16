/*
 * Lagrange Interpolation
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <stdio.h>

int main() {
    float x[100], y[100], a, s = 1, t = 1, k = 0;
    int n, i, j, d = 1;

    printf("\nEnter the number of the terms of the table: ");
    scanf("%d", &n);
    printf("\nEnter the respective values of the variables x and y: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
        scanf("%f", &y[i]);
    }

    printf("\nThe table you entered is as follows: ");
    for (i = 0; i < n; i++) {
        printf("%0.3f\t%0.3f", x[i], y[i]);
        printf("\n");
    }

    while (d == 1) {
        printf("\nEnter the value of the x to find the respective value of y: ");
        scanf("%f", &a);
        for (i = 0; i < n; i++) {
            s = 1;
            t = 1;
            for (j = 0; j < n; j++) {
                if (j != i) {
                    s = s * (a - x[j]);
                    t = t * (x[i] - x[j]);
                }
            }
            k = k + ((s / t) * y[i]);
        }

        printf("\nThe respective value of the variable y is: %f", k);
        printf("\nDo you want to continue?\nPress 1 to continue and any other key to exit ");
        scanf("%d", &d);
    }

    return 0;
}
