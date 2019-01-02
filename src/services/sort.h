//
// Created by moss on 1/2/19.
//

#ifndef GAMES_SCORE_STATISTICS_SORT_H
#define GAMES_SCORE_STATISTICS_SORT_H


#include "../objects/project.h"
#include "../datastructs/list.h"

extern void sort_project_by_score(list *projects, list *contacts);

extern void sort_man_project_by_score(list *projects, list *contacts);

extern void sort_woman_project_by_score(list *projects, list *contacts);

extern void sort_school_by_score(list *projects, list *contacts);

#endif //GAMES_SCORE_STATISTICS_SORT_H
