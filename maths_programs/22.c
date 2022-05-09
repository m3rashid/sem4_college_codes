/*
 * PROGRAM FOR COINS COUNT IN BOX
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

    int box[] = {
        2, 5, 10, 20, 5, 20, 5, 2, 5, 10,
        2, 2, 20, 50, 5, 5, 5, 2, 5, 5,
        50, 5, 10, 10, 2, 10, 2, 2, 20, 50,
        2, 10, 10, 20, 50, 20, 10, 2, 5, 10,
        2, 2, 10, 5, 10, 5, 5, 2, 50, 20};

    int twoRupeeCoins = 0;
    int fiveRupeeCoins = 0;
    int tenRupeeCoins = 0;
    int twentyRupeeCoins = 0;
    int fiftyRupeeCoins = 0;

    for (int i = 0; i < 50; i++) {
        box[i] == 2 && twoRupeeCoins++;
        box[i] == 5 && fiveRupeeCoins++;
        box[i] == 10 && tenRupeeCoins++;
        box[i] == 20 && twentyRupeeCoins++;
        box[i] == 50 && fiftyRupeeCoins++;
    }

    printf("Box has:-\n");
    printf("%d Two Rupee coins\n", twoRupeeCoins);
    printf("%d Five Rupee coins\n", fiveRupeeCoins);
    printf("%d Ten Rupee coins\n", tenRupeeCoins);
    printf("%d Twenty Rupee coins\n", twentyRupeeCoins);
    printf("%d Fifty Rupee coins\n", fiftyRupeeCoins);

    printf("Total amount of coins in box is: ");
    printf("%d\n", twoRupeeCoins * 2 + fiveRupeeCoins * 5 + tenRupeeCoins * 10 + twentyRupeeCoins * 20 + fiftyRupeeCoins * 50);

    return 0;
}
