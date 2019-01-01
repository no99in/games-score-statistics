//
// Created by moss on 1/1/19.
//

#ifndef GAMES_SCORE_STATISTICS_CONTACT_H
#define GAMES_SCORE_STATISTICS_CONTACT_H

#include "../../lib/_str.h"

typedef struct contact{
    long long sid;
    long long pid;
    double score;
}contact,* pcontact;

extern contact new_contact(contact *_self);
extern contact create_contact(contact _self,long long sid,long long pid, double score);
extern long long contact_get_sid(contact _self);
extern long long contact_get_pid(contact _self);
extern double contact_get_score(contact _self);
extern void contact_set_sid(contact _self,long long sid);
extern void contact_set_pid(contact _self,long long pid);
extern void contact_set_score(contact _self,double score);


#endif //GAMES_SCORE_STATISTICS_CONTACT_H
