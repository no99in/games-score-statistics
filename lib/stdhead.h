/**
 * @description  标准头文件（必须依赖项） Standard header file (must depend on)
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         stdhead.c
 * @date         2019-01-05
 */

#ifndef GAMES_SCORE_STATISTICS_STDHEAD_H
#define GAMES_SCORE_STATISTICS_STDHEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @description  程序内的状态宏定义 macro definition within the program
 * @param        STATUS   int  状态类型为整形，用于返回函数是否正确结束 The status type is integer and is used to return whether the function ends correctly.
 * @param        SUCCESS  1    成功返回 1   SUCCESS return 1
 * @param        ERROR    0    错误返回 2   ERROR return 0
 * @param        OVERFLOW 500  溢出    500 OVERFLOW return 500(Like an internal error in the server)
 */
#define STATUS    int
#define SUCCESS   1
#define ERROR     0
#define OVERFLOW  500

#endif //GAMES_SCORE_STATISTICS_STDHEAD_H