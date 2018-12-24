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
static void  ui_print_str(ui _self,char * s);

/**
 * @desc   获取ui实例,保证全局只有一个ui实例
 * @param  无
 * @return ui实例
 */
extern ui    get_ui_instance();
/**
 * @desc   初始化一个ui实例
 * @param  待初始化的ui声明
 * @return 无
 */
extern void  new_ui(ui * self);
/**
 * @desc   打印 | 中北大学 | 在DISPLAY_MAX_STRING_LENGTH设置宽度
 * @param  {ui,待打印字符串的s}
 * @return 无
 */
extern void  ui_print_unit_str(ui _self,char * s);


#endif //GAMES_SCORE_STATISTICS_UI_H
