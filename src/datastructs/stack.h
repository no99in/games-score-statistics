/**
 * @description  C语言泛型栈 C language generic stack
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         stack.h
 * @date         2019-01-06
 */

#ifndef GAMES_SCORE_STATISTICS_STACK_H
#define GAMES_SCORE_STATISTICS_STACK_H

#include "../../lib/stdhead.h"

typedef struct stack_node {
    void *data;
    struct stack_node *next;
} stack_node, *p_stack_node;

typedef struct stack {
    stack_node *head;
    int data_size;
    int length;
} stack, *p_stack;

extern STATUS _new_stack(stack *_self, int data_size);

extern STATUS _stack_head_push(stack *_self, void *data);

extern void * _stack_head_pop(stack *_self);

#endif //GAMES_SCORE_STATISTICS_STACK_H
