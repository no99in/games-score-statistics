//
// Created by moss on 1/1/19.
//

#ifndef GAMES_SCORE_STATISTICS_LIST_H
#define GAMES_SCORE_STATISTICS_LIST_H

#include "../../lib/_stdhead.h"


typedef struct list_node {
    void *data;
    struct list_node *next;
} list_node, *p_list_node;

typedef struct list {
    list_node *head;
    int data_size;
    int length;
} list, *p_list;

extern Status _new_list(list *_self, int data_size);

extern Status _list_head_push(list *_self, void *data);

extern Status _list_back_push(list *_self, void *data);

extern void *_list_get(list _self, int i);

extern Status _list_remove(list *_self, int i);

extern Status _list_insert(list *_self, void *data, int i);


#endif //GAMES_SCORE_STATISTICS_LIST_H
