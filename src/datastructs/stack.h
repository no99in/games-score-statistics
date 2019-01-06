//
// Created by moss on 1/2/19.
//

#ifndef GAMES_SCORE_STATISTICS_STACK_H
#define GAMES_SCORE_STATISTICS_STACK_H

#include "../../lib/_stdhead.h"

typedef struct stack_node {
    void *data;
    struct stack_node *next;
} stack_node, *p_stack_node;

typedef struct stack {
    stack_node *head;
    int data_size;
    int length;
} stack, *p_stack;

extern Status _new_stack(stack *_self, int data_size);

extern Status _stack_head_push(stack *_self, void *data);

extern void * _stack_head_pop(stack *_self);

#endif //GAMES_SCORE_STATISTICS_STACK_H
