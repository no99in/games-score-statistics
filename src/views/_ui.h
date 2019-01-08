/**
 * @description  视图层 Views
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         _ui.h
 * @date         2019-01-06
 */

#ifndef GAMES_SCORE_STATISTICS_UI_H
#define GAMES_SCORE_STATISTICS_UI_H

#include "../../ui_setting.h"
#include "../logs/log.h"
#include "../../lib/stdhead.h"

#define _UI_ZERO_STR "空串\0"
#define _UI_NULL_STR "空值\0"
#define _UI_LONG_STR "长串\0"
#define _UI_LN       "\n\0"

#define _UI_DIV      '|'
#define _UI_POINT    '+'
#define _UI_LINE     '-'

typedef struct _ui {
    char *null_str;
    char *zero_str;
    char *long_str;
    char *ln;
    char point;
    char line;
    char div;
} _ui, *_pui;

static int _ui_str_length(char *s);

static void _ui_notify(int log_level, char *notice);

static void _ui_print_str(_ui _self, char *s, int max_length);

static void _ui_print_point(_ui _self);

static void _ui_print_div(_ui _self);

static void _ui_print_ln(_ui _self);

static void _ui_print_line(_ui _self, int length);

/**
 * @desc   初始化一个ui实例
 * @param  待初始化的ui声明
 * @return 无
 */
extern void _new_ui(_ui *self);


/**
 * @desc   获取ui实例,保证全局只有一个ui实例
 * @param  无
 * @return ui实例
 */
extern _ui _get_ui_instance();

/**
 * @desc  print
 *+-------------------------------------+
 *|             T I T L E               |
 *+-------------------------------------+
 * @param  ui  ui_instance,
 * @param  int length
 * @return void
 */
extern void _ui_print_head(_ui _self, int length);

/**
 * @desc  print
 *|           F U N S T R               |
 *+-------------------------------------+
 * @param  ui  ui_instance
 * @param  int length
 * @return void
 */
extern void _ui_print_fun(_ui _self, int length);

/**
 * @desc  print
 *|           C U S T O M               |
 *+-------------------------------------+
 * @param  ui     ui_instance
 * @param  char * custom_str
 * @param  int    length
 * @return void
*/

extern void _ui_print_custom(_ui _self, char *custom_str, int length);

extern void _ui_print_custom_head(_ui _self, char *custom_str, int length);

extern void _ui_print_custom_row_pre(_ui _self, char *custom_str, int length, int block);

extern void _ui_print_custom_row_sub(_ui _self, char *custom_str, int length, int block);

extern void _ui_print_custom_odd_fix(_ui _self, char *custom_str, int length, int block);

extern void _ui_print_custom_row_end(_ui _self, int length);

#endif //GAMES_SCORE_STATISTICS_UI_H


