/**
 * @description  业务启动函数 BIZ
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         sort.h
 * @date         2019-01-06
 */

#ifndef GAMES_SCORE_STATISTICS_SORT_H
#define GAMES_SCORE_STATISTICS_SORT_H

#include "../objects/project.h"
#include "../objects/contact.h"
#include "../datastructs/list.h"
#include "../datastructs/stack.h"
#include "../views/_ui.h"
#include "../../lib/str.h"
#include "output.h"

extern void calculate_school_score(list *projects, list *contacts, list *schools);

extern void sort_school_by_score_no_input(long pid, list *projects, list *contacts, list *schools);

extern void sort_school_by_score(list *contacts);

#endif //GAMES_SCORE_STATISTICS_SORT_H
