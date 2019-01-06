/*****************************************************************************
* copyright   : 2019 moss@nodie.ink
* filename    : _str.h
* description : 纯C语言实现的字符串 pure c implementation of string
* author      : 莫斯莫斯 mossnodie
* version     : 1.0.0
* date        : 2019/01/06
* history     :
*****************************************************************************/

#ifndef GAMES_SCORE_STATISTICS_STR_H
#define GAMES_SCORE_STATISTICS_STR_H

#include "_stdhead.h"
#include "_datastructhead.h"

typedef struct str {
    char *ch;
    int length;
} str, *pstr;

extern int _str_assign(str *t, char *s);

extern int _str_length(str s);

extern int _str_compare(str s1, str s2);

extern Status _str_concat(pstr t, str s1, str s2);

extern Status _str_copy(str *t, str *s);

extern str _str_long_to_str(long num);

extern str _str_int_to_str(long num);

#endif //GAMES_SCORE_STATISTICS_STR_H
