/**
 * @description  纯C语言实现的字符串 pure c implementation of string
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         str.h
 * @date         2019-01-06
 */
#ifndef GAMES_SCORE_STATISTICS_STR_H
#define GAMES_SCORE_STATISTICS_STR_H

#include "stdhead.h"

/**
 * @param length 字符串的长度
 * @param ch     指向字符串的指针
 * @param str    字符串类
 * @param p_str  字符串类型指针
 */
typedef struct str {
    char *ch;
    int length;
} str, *p_str;

/**
 * @description 字符串赋值函数char* s赋值给str t String value assignment function char * s assigned to STR t
 * @param       t t的指针 pointer t
 * @param       s s的指针 pointer s
 * @return      OK ERROR OVERFLOW
 */
extern STATUS _str_assign(str *t, char *s);

/**
 * @description 字符串的长度 length of str
 * @param       s str s
 * @return      int 字符串的长度 length of str
 */
extern int _str_length(str s);

/**
 * @description 比较两个字符串的大小 compare the size of two str
 * @param       s1 字符串 1 str 1
 * @param       s2 字符串 2 str 2
 * @return      +(s1大),0(s1与s2相等),-(s2大) +(s1),0(equal),-(s2)
 */
extern STATUS _str_compare(str s1, str s2);

extern STATUS _str_concat(str *t, str s1, str s2);

extern STATUS _str_copy(str *t, str *s);

extern str _str_long_to_str(long num);

extern str _str_int_to_str(long num);

#endif //GAMES_SCORE_STATISTICS_STR_H
