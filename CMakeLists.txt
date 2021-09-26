cmake_minimum_required(VERSION 3.20)
project(CAlgoIntro C)

set(CMAKE_C_STANDARD 99)

add_executable(CAlgoIntro main.c longest_common_subsequence/longest_common_subsequence.c longest_common_subsequence/lib/stack.c longest_common_subsequence/lib/stack.h longest_common_subsequence/longest_common_subsequence.h)
