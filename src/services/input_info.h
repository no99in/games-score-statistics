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

extern void _input(list *schools, list *contacts, list *projects);

static school input_school_info();

static project input_project_info();

static contact input_contact_info(school s, project p, list *schools, list *projects, list *contacts);

static void input_update(list *schools, school *s, list *projects, project *p, list *contacts, contact *c);

#endif //GAMES_SCORE_STATISTICS_INPUT_INFO_H
