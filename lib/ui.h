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

typedef struct ui{
    int    u_len;
    char * null_str;
    char * zero_str;
    char * long_str;
}ui,* pui;

static int   str_length(char * s);
static void  notify(int log_level,char * notice);

extern ui    get_ui_instance();
extern void  new_ui(ui * self);
extern void  ui_print_unit_str(ui _self,char * s);
extern void  ui_print_str(ui _self,char * s);

#endif //GAMES_SCORE_STATISTICS_UI_H
