//
// Created by moss on 1/1/19.
//

#ifndef GAMES_SCORE_STATISTICS_LIST_H
#define GAMES_SCORE_STATISTICS_LIST_H

#include "../../lib/_stdhead.h"
#include "../../lib/_datastructhead.h"

typedef struct node
{
    void  * data;
    struct node * next;
}node,* pnode;

typedef struct list
{
    node  *head;
    int data_size;
    int length;
}list,* plist;

extern Status _new_list      (list *_self, int data_size);
extern Status _list_head_push(list * _self, void * data);
extern void * _list_get      (list _self,int i);
extern Status _list_remove   (list * _self,int i);
extern Status _list_insert   (list *_self, void * data, int i);


#endif //GAMES_SCORE_STATISTICS_LIST_H
