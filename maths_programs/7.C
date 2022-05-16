/*
 * Numerical double integration
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <math.h>
#include <stdio.h>

float givenFunction(float x, float y) {
    return pow(pow(x, 4) + pow(y, 5), 0.5);
}

float doubleIntegral(float h, float k, float lx, float ux, float ly, float uy) {
    int nx, ny;
    float z[50][50], ax[50], answer;
    nx = (ux - lx) / h + 1;
    ny = (uy - ly) / k + 1;

    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            z[i][j] = givenFunction(lx + i * h, ly + j * k);
        }
    }

    for (int i = 0; i < nx; ++i) {
        ax[i] = 0;
        for (int j = 0; j < ny; ++j) {
            if (j == 0 || j == ny - 1)
                ax[i] += z[i][j];
            else if (j % 2 == 0)
                ax[i] += 2 * z[i][j];
            else
                ax[i] += 4 * z[i][j];
        }
        ax[i] *= (k / 3);
    }
    answer = 0;

    for (int i = 0; i < nx; ++i) {
        if (i == 0 || i == nx - 1)
            answer += ax[i];
        else if (i % 2 == 0)
            answer += 2 * ax[i];
        else
            answer += 4 * ax[i];
    }
    answer *= (h / 3);

    return answer;
}

int main() {
    float h, k, lx, ux, ly, uy;

    lx = 2.3, ux = 2.5, ly = 3.7,
    uy = 4.3, h = 0.1, k = 0.15;

    printf("\n%f\n", doubleIntegral(h, k, lx, ux, ly, uy));
    return 0;
}
