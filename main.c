// CAlgoIntro
// Try to implement some algorithms in the book Introduction to Algorithms
// in C (and maybe C++).
//
// by Hans Wan (@criwits)
// Licensed under Mozilla Public License v2.0

#include <stdio.h>
#include "longest_common_subsequence/longest_common_subsequence.h"
#include "median_of_two_arrays/median_of_two_arrays.h"

int main(void)
{
    printf("I can eat glass!\n");

    int  a[] = {1, 3, 10, 12, 14, 20, 21};
    int  b[] = {2, 7, 8, 11, 70, 76, 82};

    printf("%lf", med2array(a, b, 7, 7));

    return 0;
}