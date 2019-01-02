//
// Created by moss on 1/1/19.
//

#ifndef GAMES_SCORE_STATISTICS_STR_H
#define GAMES_SCORE_STATISTICS_STR_H
#include "_stdhead.h"
#include "_datastructhead.h"

typedef struct str{
    char * ch;
    int length;
}str,* pstr;

extern Status _str_assign(str * t, char *s);
extern int _str_length(str s);
extern int _str_compare(str s1, str s2);
extern Status _str_concat(pstr t, str s1, str s2);
extern Status _str_copy(str * t, str * s);
extern str _str_long_to_str(long num);

#endif //GAMES_SCORE_STATISTICS_STR_H
