//
// Created by moss on 1/2/19.
//

#ifndef GAMES_SCORE_STATISTICS_OUT_PUT_H
#define GAMES_SCORE_STATISTICS_OUT_PUT_H

#include "../../lib/_str.h"
#include "../../lib/_ui.h"
#include "../objects/school.h"
#include "../objects/project.h"
#include "../objects/contact.h"
#include "../datastructs/list.h"


extern void _output(list *schools, list *contacts, list *projects);

extern void output_school_info(list *schools);

extern void output_project_info(list *projects);

extern void output_contact_info(list *contacts, list *schools, list *projects);

static str output_sid_to_school_name(list *schools, long sid);

static char *output_pid_to_project_type(list *projects, long pid);

static str output_pid_to_project_name(list *projects, long pid);


#endif //GAMES_SCORE_STATISTICS_OUT_PUT_H
