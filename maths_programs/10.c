/*
 * PROGRAM TO FIND MULTIPLICATION OF TWO GIVEN MATRICES
 * A and B OF ORDER lXm AND mXn RESPECTIVELY
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

    int a[4][5], b[5][6], c[4][6];
    int l, m, n, i, j, k;

    printf("Enter values of l,m and n: ");
    scanf("%d %d %d", &l, &m, &n);

    printf("Enter matrix A of order %dX%d:-\n", l, m);
    for (i = 0; i < l; i++) {
        for (j = 0; j < m; j++) scanf("%d", &a[i][j]);
    }
    printf("Enter matrix B of order %dX%d:-\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) scanf("%d", &b[i][j]);
    }

    printf("\nMatrix A is:\n");
    for (i = 0; i < l; i++) {
        for (j = 0; j < m; j++) printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\nMatrix B is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) printf("%d ", b[i][j]);
        printf("\n");
    }

    printf("\nMatrix C is:\n");
    for (i = 0; i < l; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < m; k++) c[i][j] += a[i][k] * b[k][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
