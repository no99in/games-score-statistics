//
// Created by moss on 1/1/19.
//

#include "list.h"

void _new_list(list *_self, int data_size){

    plist pl = (plist)malloc(sizeof(list));

    pl->data_size = data_size;
    pl->length = 0;
    pl->head = (pnode)malloc(sizeof(node) );

    *_self = *pl;

}

