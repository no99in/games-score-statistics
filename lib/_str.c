/*****************************************************************************
* copyright   : 2019 moss@nodie.ink
* filename    : _str.h
* description : 纯C语言实现的字符串 pure c implementation of string
* author      : 莫斯莫斯 mossnodie
* version     : 1.0.0
* date        : 2019/01/06
* history     :
*****************************************************************************/
#include "_str.h"

extern STATUS _str_copy(str *t, str *s) {

    p_str pt = (p_str) malloc(sizeof(str));
    pt->ch = (char *) malloc(sizeof(char) * s->length);
    int length = s->length;
    while (--length >= 0) {
        pt->ch[length] = s->ch[length];
    }// 将 s 赋值给 pt->ch
    pt->length = s->length;

    *t = *pt;

    free(pt);

    return OK;

}

STATUS _str_assign(str *t, char *s) {
    // NULL处理 to deal with NULL
    if (!s) {
        t->ch = NULL;
        t->length = 0;
        return 0;
    }
    // 计算字符串s的长度 calculate the length of the char* s
    int length = 0;
    char *c = s;
    while (*c != '\0') {
        ++length;
        ++c;
    }
    // 为t开辟空间 malloc space for str t
    p_str ps = (p_str) malloc(sizeof(str));
    if (!ps)
        exit(OVERFLOW);
    ps->ch = (char *) malloc(sizeof(char) * length);
    if (!ps->ch)
        exit(OVERFLOW);
    // 为t赋值 assign for t
    for (c = s; length >= 0; --length) {
        (ps->ch)[length] = c[length];
    }
    ps->length = length;
    // *t = *ps
    memset(t, ps, sizeof(str));
    free(ps);
    return OK;
}

extern int _str_length(str s) {
    return s.length;
}

extern int _str_compare(str s1, str s2) {
    if (s1.length != s2.length)
        return s1.length - s2.length;
    else
        for (int i = 0; i < s1.length; i++)
            if (s1.ch[i] - s2.ch[i])
                return s1.ch[i] - s2.ch[i];
    return 0;
}

extern Status _str_concat(p_str t, str s1, str s2) {
    p_str pt = (p_str) malloc(sizeof(str));
    pt->length = s1.length + s2.length;
    pt->ch = (char *) malloc(sizeof(char) * (pt->length));
    for (int i = 0; i < s1.length; i++) {
        (pt->ch)[i] = (s1.ch)[i];
    }
    for (int i = s1.length; i < s2.length + s1.length; i++) {
        (pt->ch)[i] = (s2.ch)[i - s1.length];
    }
    *t = *pt;
    free(pt);
}

extern str _str_long_to_str(long num) {

    char *t = (char *) malloc(sizeof(char) * 10);

    sprintf(t, "%ld", num);

    str res;

    _str_assign(&res, t);

    return res;

}

str _str_int_to_str(long num) {

    char *t = (char *) malloc(sizeof(char) * 10);

    sprintf(t, "%d", num);

    str res;

    _str_assign(&res, t);

    return res;
}
