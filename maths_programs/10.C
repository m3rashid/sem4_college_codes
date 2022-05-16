/*
 * Gauss-Seidel for 4 unknowns ( make 4 different functions to calculate the 4 unknowns)
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <stdio.h>

int main() {
    int i, j, coeff[10][10], n, fx[10], nmax, k;
    float x[10];
    printf("\nEnter the number of equations: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("\nEnter the coefficients of equation %d : ", i);
        for (j = 1; j <= n; j++) {
            scanf("%d", &coeff[i][j]);
        }
    }

    for (i = 1; i <= n; i++) {
        printf("\nEnter the value of f(x) for equation %d :", i);
        scanf("%d", &fx[i]);
    }

    printf("\nEnter the maximum number of iterations :");
    scanf("%d", &nmax);
    printf("\n");
    printf("Iter\t");

    for (i = 1; i <= n; i++) {
        printf("  x%d\t\t", i);
    }
    printf("\n");
    for (i = 1; i <= n; i++) {
        x[i] = 0;
    }

    for (k = 1; k <= nmax; k++) {
        printf("%d\t", k);
        for (i = 1; i <= n; i++) {
            x[i] = fx[i];
            for (j = 1; j <= n; j++) {
                if (j != i) {
                    x[i] = x[i] - coeff[i][j] * x[j];
                }
            }
            x[i] = x[i] / coeff[i][i];
            printf("%f\t", x[i]);
        }
        printf("\n");
    }

    printf("\nThe Solution of linear equations using Gauss Seidal Method\n ");
    for (i = 1; i <= n; i++) {
        printf("\t X%d = %f\n", i, x[i]);
    }

    return 0;
}