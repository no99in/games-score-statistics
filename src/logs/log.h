//
// Created by mossnodie on 12/24/18.
//

#ifndef GAMES_SCORE_STATISTICS_LOG_H
#define GAMES_SCORE_STATISTICS_LOG_H

#include "../../lib/stdhead.h"

#define _LOG_BUFFER_SIZE 100;
typedef struct _log {
    int log_type;
    char *log_information;
} _log, *_plog;

#define  _LOG_OFF     0
#define  _LOG_INFO    1
#define  _LOG_WARN    2
#define  _LOG_ERROR   3

extern _log _get_log_instance();

extern void _new_log(_log *_self);

extern void _log_update(int level, char *s);

#endif //GAMES_SCORE_STATISTICS_LOG_H
