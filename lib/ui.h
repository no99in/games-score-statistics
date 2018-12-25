//
// Created by mossnodie on 12/23/18.
//
#ifndef GAMES_SCORE_STATISTICS_UI_H
#define GAMES_SCORE_STATISTICS_UI_H
#include "log.h"

#define ZERO_STR "空串\0"
#define NULL_STR "空值\0"
#define LONG_STR "长串\0"


#define POINT    '+'
#define LINE     '-'

typedef struct ui{
    char * null_str;
    char * zero_str;
    char * long_str;
    char  point;
    char  line;
}ui,* pui;

static int   str_length(char * s);
static void  notify(int log_level,char * notice);
static void  ui_print_str(ui _self,char * s,int max_length);
static void  ui_print_point(ui _self);
static void  ui_print_div(ui _self);
static void  ui_print_line(ui _self,int length);











/**
 * @desc   初始化一个ui实例
 * @param  待初始化的ui声明
 * @return 无
 */
extern void  new_ui(ui * self);


/**
 * @desc   获取ui实例,保证全局只有一个ui实例
 * @param  无
 * @return ui实例
 */
extern ui    get_ui_instance();



/**
 * @desc  print
 *+-------------------------------------+
 *|             T I T L E               |
 *+-------------------------------------+
 * @param  ui  ui_instance,
 * @param  int length
 * @return void
 */
extern void  ui_print_head(ui _self,int length);


/**
 * @desc  print
 *|           F U N S T R               |
 *+-------------------------------------+
 * @param  ui  ui_instance
 * @param  int length
 * @return void
 */
extern void ui_print_fun(ui _self,int length);


/**
 * @desc  print
 *|           C U S T O M               |
 *+-------------------------------------+
 * @param  ui     ui_instance
 * @param  char * custom_str
 * @param  int    length
 * @return void
*/
extern void ui_print_custom(ui _self,char * custom_str,int length);
#endif //GAMES_SCORE_STATISTICS_UI_H


