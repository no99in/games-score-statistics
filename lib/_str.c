//
// Created by moss on 1/1/19.
//

#include "_str.h"

extern Status _str_copy(str * t, str * s){

    pstr pt = (pstr)malloc(sizeof(str));
    pt->ch = (char*)malloc(sizeof(char)*s->length);
    int length = s->length;
    while(--length >= 0){
        pt->ch[length] = s->ch[length];
    }// 将 s 赋值给 pt->ch
    pt->length = s->length;

    *t = *pt;

    free(pt);

    return OK;

}

extern Status _str_assign(str * t, char *s){

    if(!s){
        t->ch = NULL;
        t->length = 0;
        return 0;
    }// if NULL 处理

    pstr pt = (pstr)malloc(sizeof(str));
    if(!pt)
        exit(OVERFLOW);

    int length = 0;

    char * p = s;

    while(*p){
        ++length;
        ++p;
    }// while 计算 s 长度

    pt->ch = (char*)malloc(sizeof(char) * length);
    if(!pt->ch)
        exit(OVERFLOW);

    pt->length = length;// 将 length 赋值给 pt->length

    p = s;
    while(--length >= 0){
        (pt->ch)[length] = p[length];
    }// 将 s 赋值给 pt->ch

    *t = *pt;// 将 pt 赋值给 t

    free(pt);// 释放 pt

    return OK;

}
extern int _str_length(str s){
    return s.length;
}

extern int _str_compare(str s1, str s2){
    if(s1.length!=s2.length)
        return s1.length-s2.length;
    else
        for(int i = 0 ; i<s1.length ; i++)
            if(s1.ch[i]-s2.ch[i])
                return s1.ch[i]-s2.ch[i];
    return 0;
}

extern Status _str_concat(pstr t, str s1, str s2){
    pstr pt = (pstr)malloc(sizeof(str));
    pt->length = s1.length+s2.length;
    pt->ch = (char*)malloc(sizeof(char)*(pt->length));
    for(int i = 0;i < s1.length;i++){
        (pt->ch)[i] = (s1.ch)[i];
    }
    for(int i = s1.length;i < s2.length+s1.length;i++){
        (pt->ch)[i] = (s2.ch)[i-s1.length];
    }
    *t = *pt;
    free(pt);
}

extern str _str_long_to_str(long num){

    char * t =  (char*)malloc(sizeof(char)*10);

    sprintf(t, "%ld", num);

    str res;

    _str_assign(&res,t);

    return res;

}

str _str_int_to_str(long num) {

    char * t =  (char*)malloc(sizeof(char)*10);

    sprintf(t, "%d", num);

    str res;

    _str_assign(&res,t);

    return res;
}
