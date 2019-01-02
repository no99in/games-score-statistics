//
// Created by moss on 1/2/19.
//

#ifndef GAMES_SCORE_STATISTICS_INPUT_INFO_H
#define GAMES_SCORE_STATISTICS_INPUT_INFO_H

#include "../../lib/_str.h"
#include "../../lib/_ui.h"
#include "../objects/school.h"
#include "../objects/project.h"
#include "../objects/contact.h"
#include "../datastructs/list.h"

extern void _input(list* schools,list *contacts,list *projects);

static school input_school_info();
static project input_project_info();
static contact input_contact_info(school s ,project p ,list *schools,list *projects,list *contacts);

static void input_update_school_info(list* schools,school s);
static void input_update_project_info(list *projects,project p);
static void input_update_contact_info(list *contacts,contact c);


#endif //GAMES_SCORE_STATISTICS_INPUT_INFO_H
