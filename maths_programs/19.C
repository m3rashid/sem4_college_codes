/*
 * PROGRAM FOR STUDENT MARKS MANAGEMENT
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct student {
    int marks[3];
    int total;
    float average;
};

struct student s[5];

int main() {
    int i, j, sum, max;

    for (i = 0; i < 5; i++) {
        sum = 0;
        printf("\nEnter the marks of Student %d: \n\n", i + 1);
        for (j = 0; j < 3; j++) {
            printf("Subject %d Marks: ", j + 1);
            scanf("%d", &s[i].marks[j]);
            sum += s[i].marks[j];
        }

        s[i].total = sum;
        s[i].average = (float)s[i].total / 300;
    }

    printf("\n\nStudent\t\tSubject1\tSubject2\tSubject3\tTotal\t\tPercentage\n");
    for (i = 0; i < 5; i++) {
        printf("%d\t\t", i + 1);
        for (j = 0; j < 3; j++) {
            printf("%d\t\t", s[i].marks[j]);
        }
        printf("%d\t\t%.2f\n", s[i].total, s[i].average * 100);
    }
    printf("\n");

    return 0;
}
