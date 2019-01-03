//
// Created by moss on 1/1/19.
//

#include "../../lib/_str.h"

#ifndef GAMES_SCORE_STATISTICS_SCHOOL_H
#define GAMES_SCORE_STATISTICS_SCHOOL_H

typedef struct school {
    long id;
    str name;
    int score;
} school, *p_school;

extern school new_school(school *_self);

extern school create_school(school _self, long id, str name);

extern long school_get_id(school _self);

extern str school_get_name(school _self);

extern void school_set_id(school _self, long id);

extern void school_set_name(school _self, str name);


#endif //GAMES_SCORE_STATISTICS_SCHOOL_H
