/*
 * PROGRAM TO ARRANGE NUMBERS 15,9,11,7,12,1 AND 6
 * IN ASCENDING ORDER
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

    int i, j, temp;
    int a[6] = {15, 9, 11, 7, 12, 1};
    printf("Given array is: ");
    for (i = 0; i < 6; i++) printf("%d ", a[i]);
    printf("\n");

    for (i = 0; i < 6; i++) {
        printf("\nIteration %d, i=%d and j=%d to 7\n\n", i + 1, i, i + 1);
        for (j = i + 1; j < 7; j++) {
            for (int k = 0; k < 6; k++) printf("%d ", a[k]);
            printf("\t | j=%d", j);
            printf("\n");
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nSorted array is: ");
    for (i = 0; i < 6; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
