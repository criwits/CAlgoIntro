/**
 * 一个简单的基于链表的栈实现
 * (C) Hans Wan. MPL 2.0.
 */
#ifndef STACK_H
#define STACK_H

typedef char TYPE;

typedef struct node_s
{
    TYPE value;
    struct node_s *next;
} NODE;

typedef struct
{
    NODE *base, *top;
    int height;
} STACK;

void stackInit(STACK *this);
void stackClear(STACK *this);
void stackPush(STACK *this, TYPE value);
TYPE stackPop(STACK *this);

#endif
