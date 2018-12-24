//
// Created by mossnodie on 12/24/18.
//

#include "../lib/log.h"

static char * log_information;

extern void new_log(){

    int buffer_size = LOG_BUFFER_SIZE;
    log_information = (char*)malloc(sizeof(char)*buffer_size);

}

extern  void update(int level,char * s){
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

