/**
 * @description  业务启动函数 BIZ
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         start.h
 * @date         2019-01-06
 */

#ifndef GAMES_SCORE_STATISTICS_START_H
#define GAMES_SCORE_STATISTICS_START_H

#include "input.h"
#include "output.h"
#include "../datastructs/list.h"
#include "sort.h"
#include "../dao/tofile.h"

extern int service_start();

extern void service_menu(list *schools, list *projects, list *contacts);

static void show_menu();

#endif //GAMES_SCORE_STATISTICS_START_H