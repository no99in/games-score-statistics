/**
 * @description  业务对象 BO
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         school.h
 * @date         2019-01-06
 */

#include "../../lib/str.h"

#ifndef GAMES_SCORE_STATISTICS_SCHOOL_H
#define GAMES_SCORE_STATISTICS_SCHOOL_H

typedef struct school {
    long id;
    str name;
    int score;
    int man_score;
    int woman_score;
} school, *p_school;

extern school new_school(school *_self);

extern school create_school(school _self, long id, str name);

extern long school_get_id(school _self);

extern void school_reset_id(school _self);

extern str school_get_name(school _self);

extern void school_set_id(school _self, long id);

extern void school_set_name(school _self, str name);


#endif //GAMES_SCORE_STATISTICS_SCHOOL_H
