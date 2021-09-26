/**
 * 一个简单的基于链表的栈实现
 * (C) Hans Wan. MPL 2.0.
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Private:
void stack_node_destory(NODE *node)
{
    if (!node) {
        return;
    }
    if (node->next != NULL) {
        stack_node_destory(node->next);
    }
    free(node);
}

NODE *stack_get_next_node(NODE *node, int remaining)
{
    if (!remaining) {
        return node;
    }
    return stack_get_next_node(node->next, remaining - 1);
}

// Public:
void stackInit(STACK *this)
{
    this->base = NULL;
    this->top = NULL;
    this->height = 0;
}

void stackClear(STACK *this)
{
    stack_node_destory(this->base);
    stackInit(this);
}

void stackPush(STACK *this, TYPE value)
{
    if (this->base == NULL) {
        this->base = (NODE *)malloc(sizeof(NODE));
        this->top = this->base;
        this->base->value = value;
        this->base->next = NULL;
    } else {
        this->top->next = (NODE *)malloc(sizeof(NODE));
        this->top->next->value = value;
        this->top->next->next = NULL;
        this->top = this->top->next;
    }
    this->height++;
}

TYPE stackPop(STACK *this)
{
    if (this->height == 0) {
        return 0xDEADBEEF;
    }
    TYPE answer = this->top->value;
    free(this->top);
    if (this->height == 1) {
        this->top = NULL;
        this->base = NULL;
    } else {
        this->top = stack_get_next_node(this->base, this->height - 2);
        this->top->next = NULL;
    }
    this->height--;
    return answer;
}
