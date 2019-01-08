//
// Created by moss on 1/2/19.
//

#include "stack.h"


extern Status _new_stack(stack *_self, int data_size) {

    p_stack ps = (p_stack) malloc(sizeof(stack));

    ps->data_size = data_size;
    ps->length = 0;
    ps->head = NULL;

    *_self = *ps;

    free(ps);

    return OK;

}

extern Status _stack_head_push(stack *_self, void *data) {

    p_stack_node psn = (p_stack_node) malloc(sizeof(p_stack_node));

    psn->data = malloc(_self->data_size);

    memcpy(psn->data, data, _self->data_size);

    psn->next = NULL;

    if (!_self->head) {

        _self->head = psn;

    } else {

        psn->next = _self->head;
        _self->head = psn;

    }

}

extern void *_stack_head_pop(stack *_self) {

    void *p_snd = malloc(_self->data_size);

    memcpy(p_snd, _self->head->data, _self->data_size);

    if (!_self->head->next) {

        free(_self->head); // free
        _self->head = NULL;

    } else {

        p_stack_node free_space = _self->head;

        _self->head = _self->head->next;
        free(free_space); // free

    }

    return p_snd;

}

