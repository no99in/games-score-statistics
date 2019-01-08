/**
 * @description  业务启动函数 BIZ
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         output.h
 * @date         2019-01-06
 */
#ifndef GAMES_SCORE_STATISTICS_OUT_PUT_H
#define GAMES_SCORE_STATISTICS_OUT_PUT_H

#include "../../lib/str.h"
#include "../views/_ui.h"
#include "../objects/school.h"
#include "../objects/project.h"
#include "../objects/contact.h"
#include "../datastructs/list.h"

extern void output_school_info(list *schools);

extern void output_school_info_by_num(long sid, list *schools, list *contacts, list *projects);

extern void output_project_rank(long pid, list *projects, list *contacts, list *school);

extern void output_man_project_rank(list *schools);

extern void output_woman_project_rank(list *schools);

static str output_sid_to_school_name(list *schools, long sid);

static char *output_pid_to_project_type(list *projects, long pid);

static str output_pid_to_project_name(list *projects, long pid);

extern void output_school_rank(list *schools);

extern void output_project_info(list *projects);

extern void output_contact_info(list *contacts, list *schools, list *projects);

#endif //GAMES_SCORE_STATISTICS_OUT_PUT_H
