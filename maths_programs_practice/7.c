/*
 * PROGRAM TO FIND REVERSED SQUARE NUMBERS
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <stdio.h>

int isReverseSquare(int n) {
    int sq = n * n;
    int rev = 0;
    int revSq = 0;
    while (n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    while (sq != 0) {
        revSq = revSq * 10 + sq % 10;
        sq /= 10;
    }

    return rev * rev == revSq ? 1 : 0;
}
int main() {
    printf("20BCS033 MD Rashid Hussain\n");

    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    printf("Number which have Reverse square property:-\n");
    for (int i = 1; i <= n; i++) {
        if (isReverseSquare(i)) printf("%d\n", i);
    }

    return 0;
}