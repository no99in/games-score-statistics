//
// Created by moss on 1/1/19.
//

#ifndef GAMES_SCORE_STATISTICS_PROJECT_H
#define GAMES_SCORE_STATISTICS_PROJECT_H

#include "../../lib/_str.h"

typedef struct project {
    long id;
    int type;
    str name;
} project, *pproject;

extern project new_project(project *_self);

extern project create_project(project _self, long id, int type, str name);

extern long project_get_id(project _self);

extern str project_get_name(project _self);

extern int project_get_type(project _self);

extern void project_set_id(project _self, long id);

extern void project_set_name(project _self, str name);

extern void project_set_type(project _self, int type);

#endif //GAMES_SCORE_STATISTICS_PROJECT_H
