//
// Created by moss on 1/1/19.
//

#include "list.h"

void new_list(list *_self,int data_size, int* c){

    plist pl = (plist)malloc(sizeof(list));
    pl->data_size = data_size;
    pl->length = 0;
    pl->head = (pnode)malloc(sizeof(node) - sizeof(void*) + data_size);
    pl->head->data = (int*)malloc(data_size);
    pl->head->data = c;
    *_self = *pl;

}