/**
 * @description  系统日志函数 System log function
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         log.h
 * @date         2019-01-06
 */

#ifndef GAMES_SCORE_STATISTICS_LOG_H
#define GAMES_SCORE_STATISTICS_LOG_H

#include "../../lib/stdhead.h"

#define _LOG_BUFFER_SIZE 100;
typedef struct _log {
    int log_type;
    char *log_information;
} _log, *_p_log;

#define  _LOG_OFF     0
#define  _LOG_INFO    1
#define  _LOG_WARN    2
#define  _LOG_ERROR   3

extern _log _get_log_instance();

extern void _new_log(_log *_self);

extern void _log_update(int level, char *s);

#endif //GAMES_SCORE_STATISTICS_LOG_H
