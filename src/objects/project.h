//
// Created by moss on 1/1/19.
//

#ifndef GAMES_SCORE_STATISTICS_PROJECT_H
#define GAMES_SCORE_STATISTICS_PROJECT_H

#include "../../lib/_str.h"

typedef struct project{
    long long id;
    int type;
    str name;
}project,* pproject;

extern project new_project();
extern project create_project(long long id,int type,str name);
extern long long project_get_id();
extern str project_get_name();
extern int project_get_type();
extern void project_set_id(long long id);
extern void project_set_name(str name);
extern void project_set_type(int type);

#endif //GAMES_SCORE_STATISTICS_PROJECT_H
