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

extern void _input();

static school input_school_info();
static project input_project_info();
static contact input_contact_info(school s,project p);


#endif //GAMES_SCORE_STATISTICS_INPUT_INFO_H
