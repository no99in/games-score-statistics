#include "project.h"

long _project_id = 1;

long project_get_id(project _self) {
    return _project_id++;
}

void project_reset_id(project _self) {
    _project_id--;
}

long project_force_get_id() {
    return _project_id;
}