/*
 * PROGRAM TO CHECK FOR MAGIC SQUERE
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <stdio.h>
#include <stdlib.h>

int rowCheck(int magicSquare[][10], int row, int col) {
    int i, j, sum = 0, prevSum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sum += magicSquare[i][j];
        }
        if (i != 0 && sum != prevSum) {
            return -1;
        }
        prevSum = sum;
        sum = 0;
    }
    return prevSum;
}

int colCheck(int magicSquare[][10], int row, int col) {
    int i, j, sum = 0, prevSum = 0;
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            sum += magicSquare[i][j];
        }
        if (j != 0 && sum != prevSum) {
            return -1;
        }
        prevSum = sum;
        sum = 0;
    }
    return prevSum;
}

int diagCheck(int magicSquare[][10], int row, int col) {
    int i, j, diag1 = 0, diag2 = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (i == j) {
                diag1 += magicSquare[i][j];
            }
            if (i + j == row - 1) {
                diag2 += magicSquare[i][j];
            }
        }
    }
    if (diag1 != diag2) {
        return -1;
    }
    return diag1;
}

int main() {
    int n;
    printf("Enter Magic square size: ");
    scanf("%d", &n);

    printf("Enter the Square: \n");
    int magicSquare[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &magicSquare[i][j]);
        }
    }

    int rowValid = rowCheck(magicSquare, n, n);
    int colValid = colCheck(magicSquare, n, n);
    int diagValid = diagCheck(magicSquare, n, n);
    if (rowValid == -1 || colValid == -1 || diagValid == -1) {
        printf("Not a Magic Square\n");
    } else {
        if (rowValid == colValid && rowValid == diagValid) {
            printf("Magic Square with Sum = %d\n", rowValid);
        } else {
            printf("Not a Magic Square\n");
        }
    }
    printf("\n");

    return 0;
}
