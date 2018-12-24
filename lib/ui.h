//
// Created by mossnodie on 12/23/18.
//
#ifndef GAMES_SCORE_STATISTICS_UI_H
#define GAMES_SCORE_STATISTICS_UI_H
#include "log.h"
#define DISPLAY_MAX_STRING_LENGTH 10
#define ZERO_STR "空串\0"
#define NULL_STR "空值\0"
#define LONG_STR "长串\0"

static int strlength(char * s);
static void notify(int log_level,char * notice);


extern void       init();
extern void       printunintystr(char * s);
extern void       printstr(char * s);

#endif //GAMES_SCORE_STATISTICS_UI_H
