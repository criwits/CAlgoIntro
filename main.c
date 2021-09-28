// CAlgoIntro
// Try to implement some algorithms in the book Introduction to Algorithms
// in C (and maybe C++).
//
// by Hans Wan (@criwits)
// Licensed under Mozilla Public License v2.0

#include <stdio.h>
#include "longest_common_subsequence/longest_common_subsequence.h"
#include "median_of_two_arrays/median_of_two_arrays.h"
#include "0-1_knapsack_problem/0-1_knapsack_problem.h"

int main(void)
{
    printf("I can eat glass!\n");

    int v[] = { 7, 3, 6, 10, 8 };
    int w[] = { 5, 2, 2, 6, 4 };

    printf("%d", knapsack(5, v, w, 10));

    return 0;
}