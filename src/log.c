//
// Created by mossnodie on 12/24/18.
//

#include "../lib/log.h"

log * log_instance = NULL;

log get_log_instance(){
    if(!log_instance)
        new_log(log_instance);
    return *log_instance;
}

void new_log(log * _self){

    log * self = (plog)malloc(sizeof(log));

    int buffer_size = LOG_BUFFER_SIZE;
    self->log_information = (char*)malloc(sizeof(char)*buffer_size);

    *_self = *self;
    log_instance = self;

}

void log_update(int level, char *s){
    switch (level){
        case 0:
            break;
        case 1:
            printf("信息:%s\n",s);
            break;
        case 2:
            printf("警告:%s\n",s);
            break;
        case 3:
            printf("错误:%s\n",s);
            break;
    }

}

