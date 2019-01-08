//
// Created by moss on 1/1/19.
//

#include "school.h"


long _school_id = 1;

long school_get_id(school _self) {
    return _school_id++;
}

void school_reset_id(school _self) {
    _school_id--;
}
