//
// Created by moss on 1/1/19.
//

#include "list.h"

Status _new_list(list *_self, int data_size){

    plist pl = (plist)malloc(sizeof(list));

    pl->data_size = data_size;
    pl->length = 0;
    pl->head = NULL;

    *_self = *pl;

    free(pl);

    return OK;

}

Status _list_head_push(list * _self, void * data){

    node * pn = (node*)malloc(sizeof(node));
    pn->data = malloc(_self->data_size);
    memcpy(pn->data,data,_self->data_size);

    if(_self->head){

        pn->next = _self->head;
        _self->head = pn;
        ++_self->length;

    } else{

        _self->head = pn;
        _self->head->next = NULL;
        ++_self->length;

    }

    return OK;

}

extern void * _list_get(list _self,int i){

    if(i > _self.length || i <= 0){
        return NULL;
    }

    void * res = malloc(sizeof(_self.data_size));

    node * n = _self.head;

    while(i-1 > 0){
        n = n->next;
        i--;
    }

    memcpy(res,n->data,_self.data_size);

    return res;

}

extern Status _list_remove(list* _self,int i){

    if(i > _self->length || i <= 0){
        return ERR;
    }

    node * n = _self->head;

    if(i == 1){

        if(_self->length == 1){

            free(_self->head);
            _self->head = NULL;
            --_self->length;
            return OK;

        }else{

            _self->head = _self->head->next;
            free(n);
            --_self->length;
            return OK;

        }

    }else{

        while(i-2 > 0 ){
            n = n->next;
            i--;
        }

        free(n->next);
        n->next = n->next->next;

        --_self->length;
        return OK;

    }

}