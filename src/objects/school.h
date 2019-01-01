//
// Created by moss on 1/1/19.
//

#include "../../lib/_str.h"

#ifndef GAMES_SCORE_STATISTICS_SCHOOL_H
#define GAMES_SCORE_STATISTICS_SCHOOL_H

typedef struct school{
    long long adress;
    long long id;
    str name;
}school,* pschool;

extern long long school_get_id();
extern str school_get_name();
extern void school_set_id(long long id);
extern void school_set_name(str name);


#endif //GAMES_SCORE_STATISTICS_SCHOOL_H
