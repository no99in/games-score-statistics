/**
 * @description  C语言泛型链表 C language generic list
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         list.h
 * @date         2019-01-06
 */

#ifndef GAMES_SCORE_STATISTICS_LIST_H
#define GAMES_SCORE_STATISTICS_LIST_H

#include "../../lib/stdhead.h"

typedef struct list_node {
    void *data;
    struct list_node *next;
} list_node, *p_list_node;

typedef struct list {
    list_node *head;
    int data_size;
    int length;
} list, *p_list;

extern STATUS _new_list(list *_self, int data_size);

extern STATUS _list_head_push(list *_self, void *data);

extern STATUS _list_back_push(list *_self, void *data);

extern void *_list_get(list _self, int i);

extern STATUS _list_remove(list *_self, int i);

extern STATUS _list_insert(list *_self, void *data, int i);

#endif //GAMES_SCORE_STATISTICS_LIST_H
