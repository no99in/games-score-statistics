//
// Created by moss on 1/1/19.
//

#include "list.h"

void _new_list(list *_self, int data_size){

    plist pl = (plist)malloc(sizeof(list));

    pl->data_size = data_size;
    pl->length = 0;
    pl->head = NULL;

    *_self = *pl;

    free(pl);
}

void _list_push(list * _self, void * data){

    node * pn = (node*)malloc(sizeof(node));
    pn->data = malloc(_self->data_size);
    memcpy(pn->data,data,_self->data_size);

    if(_self->head){

        pn->next = _self->head;
        _self->head->next = pn;

    } else{

        _self->head = pn;
        _self->head->next = NULL;

    }

}
