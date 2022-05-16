/*
 * Fitting a polynomial: y = a + bx + c(x^2) + d(x^3)
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>

void gaussEliminationLS(int m, int n, double *a, double x[]) {
    int i, j, k;
    for (i = 0; i < m - 1; i++) {
        for (k = i + 1; k < m; k++) {
            if (fabs(*((a + i * m) + i)) < fabs(*((a + k * m) + i))) {
                for (j = 0; j < n; j++) {
                    double temp;
                    temp = *((a + i * m) + j);
                    *((a + i * m) + j) = *((a + k * m) + j);
                    *((a + k * m) + j) = temp;
                }
            }
        }

        for (k = i + 1; k < m; k++) {
            double term = *((a + k * m) + i) / *((a + i * m) + i);
            for (j = 0; j < n; j++) {
                *((a + k * m) + j) = *((a + k * m) + j) - term * (*((a + i * m) + j));
            }
        }
    }

    for (i = m - 1; i >= 0; i--) {
        x[i] = *((a + i * m) + (n - 1));
        for (j = i + 1; j < n - 1; j++) {
            x[i] = x[i] - *((a + i * m) + j) * x[j];
        }
        x[i] = x[i] / *((a + i * m) + i);
    }
}

void printMatrix(int m, int n, double *matrix) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf\t", *((matrix + i * m) + j));
        }
        printf("\n");
    }
}
int main() {
    int N;
    int n;
    printf("Enter the no. of data-points:\n");
    scanf("%d", &N);

    double x[N], y[N];
    printf("Enter the x-axis values:\n");
    int i, j;

    for (i = 0; i < N; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter the y-axis values:\n");
    for (i = 0; i < N; i++) {
        scanf("%lf", &y[i]);
    }

    printf("Enter the degree of polynomial to be used:\n");
    scanf("%d", &n);

    double X[2 * n + 1];
    for (i = 0; i <= 2 * n; i++) {
        X[i] = 0;
        for (j = 0; j < N; j++) {
            X[i] = X[i] + pow(x[j], i);
        }
    }

    double B[n + 1][n + 2];
    double Y[n + 1];
    for (i = 0; i <= n; i++) {
        Y[i] = 0;
        for (j = 0; j < N; j++) {
            Y[i] = Y[i] + pow(x[j], i) * y[j];
        }
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            B[i][j] = X[i + j];
        }
    }

    for (i = 0; i <= n; i++) {
        B[i][n + 1] = Y[i];
    }

    double A[n + 1];
    printf("\nThe polynomial fit is given by the equation:\n\n");
    printMatrix(n + 1, n + 2, &B[0][0]);
    gaussEliminationLS(n + 1, n + 2, &B[0][0], A);
    printf("\n\n");

    for (i = 0; i <= n; i++) {
        if (i == n)
            printf("%lfx^%d", A[i], i);
        else
            printf("%lfx^%d + ", A[i], i);
    }
    printf("\n");

    return 0;
}
