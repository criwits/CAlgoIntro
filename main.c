// CAlgoIntro
// Try to implement some algorithms in the book Introduction to Algorithms
// in C (and maybe C++).
//
// by Hans Wan (@criwits)
// Licensed under Mozilla Public License v2.0

#include <stdio.h>
#include "longest_common_subsequence/longest_common_subsequence.h"

int main(void)
{
    printf("I can eat glass!\n");

    char a[] = "abc";
    char b[] = "acd";
    char c[24];

    int answer = lcsubseq(a, b, c);
    printf("%s %d", c, answer);

    return 0;
}