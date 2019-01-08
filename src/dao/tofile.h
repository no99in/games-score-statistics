/**
 * @description  纯C语言实现的字符串 C language file function
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         tofile.h
 * @date         2019-01-06
 */

#ifndef GAMES_SCORE_STATISTICS_TOFILE_H
#define GAMES_SCORE_STATISTICS_TOFILE_H

#include "../datastructs/list.h"
#include "../../lib/stdhead.h"
#include "../objects/school.h"
#include "../objects/project.h"
#include "../objects/contact.h"

/**
 * @description 数据结构到文件 Data structure to file
 * @param       定义的三个类型 school project contact
 * @return      OK ERROR OVERFLOW
 * @others      第一行含有其他干扰故第一行避开 The file of first line contains other interference, so the first line avoids
 */
extern STATUS _schools_to_file(list *schools);

extern STATUS _projects_to_file(list *projects);

extern STATUS _contacts_to_file(list *contacts);

/**
 * @description 文件到数据结构 file to Data structure
 * @param       定义的三个类型的数据结构 schools projects contacts
 * @return      OK ERROR OVERFLOW
 * @others      第一行含有其他干扰故第一行避开 The file of first line contains other interference, so the first line avoids
 */
extern STATUS _file_to_schools(list *schools);

extern STATUS _files_to_project(list *projects);

extern STATUS _file_to_contacts(list *contacts);

#endif //GAMES_SCORE_STATISTICS_TOFILE_H
