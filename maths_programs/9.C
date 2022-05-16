/*
 * Gauss Jordan
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>

#define SIZE 10

int main() {
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;
    printf("\nEnter number of unknowns: ");
    scanf("%d", &n);
    printf("\nEnter coefficients of Augmented Matrix:\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 1; i <= n; i++) {
        if (a[i][i] == 0.0) {
            printf("\nMathematical Error!");
            exit(0);
        }
        for (j = 1; j <= n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 1; k <= n + 1; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    for (i = 1; i <= n; i++) {
        x[i] = a[i][n + 1] / a[i][i];
    }

    printf("\nSolution:\n");
    for (i = 1; i <= n; i++) {
        printf("\nx[%d] = %0.3f\n", i, x[i]);
    }

    return 0;
}
