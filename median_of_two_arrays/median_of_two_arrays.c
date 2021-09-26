//
// Median of two Arrays
// Topic: Divide-and-Conquer
//
// To find the the median of two given arrays with the same length
//

#include "median_of_two_arrays.h"
#include <stdio.h>

/**
 * Find the median of two given arrays. Their length are the same value `n`
 * @param a Array A
 * @param b Array B
 * @param n Length n
 * @return The median of A and B, or, the median of the array combined by A
 * and B.
 */
double med2array(int *a, int *b, int n)
{
    // The method was forked from https://zhuanlan.zhihu.com/p/39129143.
    int l = 0, r = n;
    int i, j;
    while (l <= r) {
        i = (l + r) / 2;
        j = (2 * n + 1) / 2 - i;
        if (i < n && b[j - 1] > a[i]) {
            l = i + 1;
        } else if (i > 0 && a[i - 1] > b[j]) {
            r = i - 1;
        } else {
            int lmax, rmin;
            if (i == 0) {
                lmax = b[j - 1];
            } else if (j == 0) {
                lmax = a[i - 1];
            } else {
                lmax = a[i - 1] > b[j - 1] ? a[i - 1] : b[j - 1];
            }

            if (i == n) {
                rmin = b[j];
            } else if (j == n) {
                rmin = a[i];
            } else {
                rmin = a[i] < b[j] ? a[i] : b[j];
            }

            printf("%d %d\n", lmax, rmin);
            return (rmin + lmax) / 2.0;
        }
    }
    return 0.0;
}