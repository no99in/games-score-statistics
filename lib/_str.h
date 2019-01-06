/**
 * @description  纯C语言实现的字符串 pure c implementation of string
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         _str.h
 * @date         2019-01-06
 */
#ifndef GAMES_SCORE_STATISTICS_STR_H
#define GAMES_SCORE_STATISTICS_STR_H

#include "_stdhead.h"

typedef struct str {
    char *ch;
    int length;
} str, *p_str;
/**
 * @description 字符串赋值函数char* s赋值给str t String value assignment function char * s assigned to STR t
 * @param       t t的指针 pointer t
 * @param       s s的指针 pointer s
 * @return
 */
extern STATUS _str_assign(str *t, char *s);

extern STATUS _str_length(str s);

extern STATUS _str_compare(str s1, str s2);

extern STATUS _str_concat(p_str t, str s1, str s2);

extern STATUS _str_copy(str *t, str *s);

extern str _str_long_to_str(long num);

extern str _str_int_to_str(long num);

#endif //GAMES_SCORE_STATISTICS_STR_H
