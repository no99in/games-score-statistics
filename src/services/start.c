//
// Created by moss on 1/2/19.
//

#include "start.h"

int service_start(){

    //  系统日志
    _log log;
    _new_log(&log);

    // ui界面构建
    _ui ui;
    _new_ui(&ui);

    // 创建 school-list
    list schools;
    _new_list(&schools, sizeof(school));
    // 创建 contact-list
    list contacts;
    _new_list(&contacts, sizeof(contact));
    // 创建 project-list
    list projects;
    _new_list(&projects, sizeof(project));

    // 单元测试
    _input(&schools,&contacts,&projects);

    printf("%s",((school*)schools.head->data)->name);

    return 0;

}