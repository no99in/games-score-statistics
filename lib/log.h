//
// Created by mossnodie on 12/24/18.
//

#ifndef GAMES_SCORE_STATISTICS_LOG_H
#define GAMES_SCORE_STATISTICS_LOG_H
#include "stdhead.h"

#define LOG_BUFFER_SIZE 100;
typedef struct log{
    char * log_information;
}log,* plog;

#define  OFF     0
#define  INFO    1
#define  WARN    2
#define  ERROR   3

extern log get_log_instance();
extern void new_log(log * self);
extern void log_update(int level, char *s);

#endif //GAMES_SCORE_STATISTICS_LOG_H
