/*
 * PROGRAM FOR FINDING SUM OF SERIES
 * 1 + x + 2x^2/4 + x^3/3 + 4x^4/5! + x^5/5 + 6x^6/12!
 * at x=0.123
 *
 * Program Submitted By ---
 * MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>

long factorial(int n) {
    return n == 0 ? 1 : n * factorial(n - 1);
}

double oddTermsSum(double x) {
    double sum = 0;
    for (int i = 1; i <= 5; i += 2) sum += pow(x, i) / i;
    return sum;
}

double evenTermsSum(double x) {
    double sum = 0;
    for (int i = 2; i <= 6; i += 2) sum += i * pow(x, i) / factorial(2 * i);
    return sum;
}

int main() {
    printf("20BCS033 MD Rashid Hussain\n");

    float x = 0.123;
    double sumEvenTerms = evenTermsSum(x);
    double sumOddTerms = oddTermsSum(x);
    printf("The sum of series is: %.4lf\n", 1 + sumEvenTerms + sumOddTerms);

    return 0;
}
