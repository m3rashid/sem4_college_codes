/*
 * PROGRAM TO FIND MEAN VARIANCE
 * AND STANDARD DEVIATION OF N VALUES TAKEN RANDOMLY
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>

int main() {
    printf("20BCS033 MD Rashid Hussain\n");

    int i, n, x;
    float sum_x = 0, sum_sqx = 0, sd, var, mean;

    printf("Enter number of values: ");
    scanf("%d", &n);
    printf("\nEnter %d values one by one:-\n ", n);
    for (i = 0; i < n; i++) {
        printf("Enter the value of x%d: ", i + 1);
        scanf("%d", &x);
        sum_x += x;
        sum_sqx += x * x;
    }
    mean = sum_x / n;
    var = sum_sqx / n - mean * mean;
    sd = sqrt(var);

    printf("\nMean is %.2f\n", mean);
    printf("Variance is %.2f\n", var);
    printf("Standard deviation is %.2f\n", sd);

    return 0;
}
