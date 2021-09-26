//
// Median of two Arrays
// Topic: Divide-and-Conquer
//
// To find the the median of two given arrays.
//

#include "median_of_two_arrays.h"

/**
 * Find the median of two given arrays. Their length are the same value `n`
 * @param a Array A
 * @param b Array B
 * @param m Length of A. !!! NOTE: m >= n !!!
 * @param n Length of B
 * @return The median of A and B, or, the median of the array combined by A
 * and B.
 */
double med2array(const int *a, const int *b, int m, int n)
{
    // The method was forked from https://zhuanlan.zhihu.com/p/39129143
    int l = 0, r = m;
    int i, j;
    while (l <= r) {
        i = (l + r) / 2;
        j = (m + n + 1) / 2 - i;
        if (i < m && b[j - 1] > a[i]) {
            // Case 1: b[j-1] is larger than a[i]
            // which means the division line is on the right side of a[i]
            l = i + 1;
        } else if (i > 0 && a[i - 1] > b[j]) {
            // Case 2: a[i-1] is larger than b[j]
            // which means the division line is on the left side of a[i]
            r = i - 1;
        } else {
            // Case 3: a[i] (and b[j]) are perfect
            int lmax, rmin;
            // Check the boundaries, then get the minimum of the left part
            if (i == 0) {
                lmax = b[j - 1];
            } else if (j == 0) {
                lmax = a[i - 1];
            } else {
                lmax = a[i - 1] > b[j - 1] ? a[i - 1] : b[j - 1];
            }

            // When (m+n) is an odd number, then lmax is the median
            if ((m + n) % 2 == 1) {
                return lmax;
            }

            // Calculate the right side
            if (i == m) {
                rmin = b[j];
            } else if (j == n) {
                rmin = a[i];
            } else {
                rmin = a[i] < b[j] ? a[i] : b[j];
            }

            // When (m+n) is an even number, then the average of lmax and rmin
            // is the answer
            return (rmin + lmax) / 2.0;
        }
    }
    // Just to dismiss the warning...
    return 0.0;
}