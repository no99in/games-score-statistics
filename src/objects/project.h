/**
 * @description  业务对象 BO
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         project.h
 * @date         2019-01-06
 */

#ifndef GAMES_SCORE_STATISTICS_PROJECT_H
#define GAMES_SCORE_STATISTICS_PROJECT_H

#include "../../lib/str.h"

typedef struct project {
    long id;
    int type;
    str name;
} project, *p_project;

extern project new_project(project *_self);

extern project create_project(project _self, long id, int type, str name);

extern long project_get_id(project _self);

extern void project_reset_id(project _self);

extern long project_force_get_id();

extern str project_get_name(project _self);

extern int project_get_type(project _self);

extern void project_set_id(project _self, long id);

extern void project_set_name(project _self, str name);

extern void project_set_type(project _self, int type);

#endif //GAMES_SCORE_STATISTICS_PROJECT_H
