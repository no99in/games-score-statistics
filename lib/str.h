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
 * @param length 字符串的长度     Length of str
 * @param ch     指向字符串的指针  Pointer to char*
 * @param str    字符串类         My str class
 * @param p_str  字符串类型指针    Pointer to str
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

/**
 * @description 连接两个字符串 connect two str to t
 * @param       t  赋值字符串 Assigned str
 * @param       s1 字符串 1 str 1
 * @param       s2 字符串 2 str 2
 * @return      OK ERROR OVERFLOW
 */
extern STATUS _str_concat(str *t, str s1, str s2);

/**
 * @description 将s赋值给t Assign s to t
 * @param       t 复制字符串 Copy str t
 * @param       s 被复制字符串 Copied str s
 * @return      OK ERROR OVERFLOW
 */
extern STATUS _str_copy(str *t, str *s);

/**
 * @description 字符串与整形数据的相互转换 Conversion of strings and shaped data 下同 Same as below
 */
extern str _str_long_to_str(long num);

extern str _str_int_to_str(int num);

extern long _str_str_to_long(char *un_num);

extern int _str_str_to_int(char *un_num);

#endif //GAMES_SCORE_STATISTICS_STR_H
