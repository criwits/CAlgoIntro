//
// 0-1 Knapsack Problem
// Topic: Dynamic Programming
//
// Given a set of numbers from 1 up to n, each with a weight w_i and value v_i,
// along with a maximum weight capacity W, find the maximum summary of v_ix_i
// while the summary of w_ix_i is no bigger than W and for each x_i it's either
// 0 or 1.
//

#include <stdio.h>
#include <stdlib.h>

/**
 * 0-1 knapsack problem
 * @param n the number of available elements
 * @param w the array w_i (from 0 to (n-1), w[i] means the (i+1)th element)
 * @param v the array v_i (from 0 to (n-1))
 * @param W the maximum weight capacity W
 * @return the maximum value
 */
int knapsack(int n, int *w, int *v, int W)
{
    // Initialize the map
    // m[i][j] means the maximum value when the 1st~ith elements are put inside
    // a knapsack which has the maximum capacity of j
    int **m = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        m[i] = (int *)malloc(sizeof(int) * (W + 1));
        m[i][0] = 0;
    }
    for (int i = 0; i <= W; i++) {
        m[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i - 1]) {
                // In this case, w_i (w[i-1]) is bigger than j,
                // which means there is no way for the ith element
                // to be put inside our knapsack.
                // Then m[i][j] has no differences with m[i-1][j]
                m[i][j] = m[i - 1][j];
            } else {
                // In this case, w_i is smaller than j, which means the ith
                // thing CAN be put inside.
                m[i][j] = (m[i - 1][j] > (m[i - 1][j - w[i - 1]] + v[i - 1])) ?
                          (m[i - 1][j]) : (m[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }

    // Get the answer
    int ans = m[n][W];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // Free the map
    for (int i = 0; i <= n; i++) {
        free(m[i]);
    }
    free(m);

    return ans;
}
