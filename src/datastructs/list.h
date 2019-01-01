//
// Created by moss on 1/1/19.
//

#ifndef GAMES_SCORE_STATISTICS_LIST_H
#define GAMES_SCORE_STATISTICS_LIST_H

#include "../../lib/_stdhead.h"

typedef struct node
{
    void  * data;
    struct node *next;
}node,* pnode;

typedef struct list
{
    node  *head;
    int data_size;
    int length;
}list,* plist;

extern void new_list(list *_self,int data_size,int* c);


#endif //GAMES_SCORE_STATISTICS_LIST_H
