//
// Longest Common Subsequence
// Topic: Dynamic Programming
//
// The longest common subsequence, unlike the longest common substring,
// subsequences are not required to occupy consecutive positions within the
// original sequences.
//

#include "lib/stack.h"
#include <string.h>
#include <stdlib.h>

typedef enum {
    UPPER,
    LEFT,
    UPPER_LEFT,
    NIL
} PREVPTR;

/**
 * Find the longest common subsequence of two strings
 * @param str_a String A
 * @param str_b String B
 * @param lcs The longest common subsequence of string A and B; will be empty if
 * there's none
 * @return The length of `lcs`; 0 if there's none
 */
int lcsubseq(const char *str_a, const char *str_b, char *lcs)
{
    // The length of A and B
    int m = strlen(str_a), n = strlen(str_b);

    // Allocate the square array of `c` (used to hold the dynamic programming
    // answers) and `b` (used to hold the pointers of answer)
    int **c = (int **)malloc(sizeof(int *) * (m + 1));
    PREVPTR **b = (PREVPTR **)malloc(sizeof(PREVPTR *) * (m + 1));
    for (int i = 0; i <= m; i++) {
        c[i] = (int *)malloc(sizeof(int) * (n + 1));
        b[i] = (PREVPTR *)malloc(sizeof(PREVPTR) * (n + 1));
        c[i][0] = 0;
        b[i][0] = NIL;
    }
    for (int i = 0; i <= n; i++) {
        c[0][i] = 0;
        b[0][i] = NIL;
    }

    // Run the dynamic programing process...
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str_a[i - 1] == str_b[j - 1]) {
                // Case 1: c[i, j] = c[i-1, j-1] + 1, when A_i = B_j
                // Note that A_i means the i th character of A,
                // while it is str_a[i-1] in our code
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = UPPER_LEFT;
            } else {
                // Case 2: A_i != B_j
                // then c[i, j] need to be transferred from
                // either c[i-1, j] or c[i, j-1]
                if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = UPPER;
                } else {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = LEFT;
                }
            }
        }
    }


    // Catch the returned answer
    int ans = c[m][n];

    // Get the subsequence itself
    STACK subseq;
    stackInit(&subseq);
    int i_pos = m, j_pos = n;
    while (b[i_pos][j_pos] != NIL) {
        if (b[i_pos][j_pos] == UPPER_LEFT) {
            stackPush(&subseq, str_a[i_pos - 1]);
            i_pos--;
            j_pos--;
        }
        if (b[i_pos][j_pos] == UPPER) {
            i_pos--;
        }
        if (b[i_pos][j_pos] == LEFT) {
            j_pos--;
        }
    }
    int ansptr = 0;
    while (subseq.height != 0) {
        lcs[ansptr++] = stackPop(&subseq);
    }
    lcs[ansptr] = '\0';
    stackClear(&subseq);

    // Free `c` and `b`
    for (int i = 0; i <= m; i++) {
        free(c[i]);
        free(b[i]);
    }
    free(c);
    free(b);

    // Return the answer
    return ans;
}
