#ifndef UI_H
#define UI_H
#include "stdhead.h"
#define DISPLAY_MAX_STRING_LENGTH 10
#define ZERO_STR "空串\0"
#define NULL_STR "空值\0"
#define LONG_STR "长串\0"
extern void printunintystr(char * s);
extern void printstr(char * s);
static int strlength(char * s);
#endif // UI_H
