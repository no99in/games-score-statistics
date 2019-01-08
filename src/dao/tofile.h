//
// Created by moss on 2019/1/8.
//

#ifndef GAMES_SCORE_STATISTICS_TOFILE_H
#define GAMES_SCORE_STATISTICS_TOFILE_H
#include "../datastructs/list.h"
#include "../../lib/stdhead.h"
#include "../objects/school.h"
#include "../objects/project.h"
#include "../objects/contact.h"
extern STATUS _schools_to_file(list* schools);
extern STATUS _projects_to_file(list* projects);
extern STATUS _contacts_to_file(list * contacts);

extern STATUS _file_to_schools(list* schools);
extern STATUS _files_to_project(list* projects);
extern STATUS _file_to_contacts(list * contacts);
#endif //GAMES_SCORE_STATISTICS_TOFILE_H
