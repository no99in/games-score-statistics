//
// Created by mossnodie on 12/24/18.
//

#ifndef GAMES_SCORE_STATISTICS_LOG_H
#define GAMES_SCORE_STATISTICS_LOG_H
#include "stdhead.h"

#define LOG_BUFFER_SIZE 100;

static char * log_information;

#define  OFF     0
#define  INFO    1
#define  WARN    2
#define  ERROR   3

extern void new_log();
extern void update(int level,char * s);



#endif //GAMES_SCORE_STATISTICS_LOG_H
