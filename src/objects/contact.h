/**
 * @description  业务对象 BO
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         contact.h
 * @date         2019-01-06
 */

#ifndef GAMES_SCORE_STATISTICS_CONTACT_H
#define GAMES_SCORE_STATISTICS_CONTACT_H

#include "../../lib/str.h"

typedef struct contact {
    long sid;
    long pid;
    int score;
} contact, *p_contact;

extern contact new_contact(contact *_self);

extern contact create_contact(contact _self, long sid, long pid, int score);

extern long contact_get_sid(contact _self);

extern long contact_get_pid(contact _self);

extern int contact_get_score(contact _self);

extern void contact_set_sid(contact _self, long sid);

extern void contact_set_pid(contact _self, long pid);

extern void contact_set_score(contact _self, int score);


#endif //GAMES_SCORE_STATISTICS_CONTACT_H
