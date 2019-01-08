//
// Created by moss on 1/2/19.
//

#include "start.h"

int service_start() {

    //  create log 创建系统日志
    _log log;
    _new_log(&log);

    // create ui 创建UI
    _ui ui;
    _new_ui(&ui);

    // create school-list 创建 school-list
    list schools;
    _new_list(&schools, sizeof(school));
    // create contacts-list 创建 contact-list
    list contacts;
    _new_list(&contacts, sizeof(contact));
    // create projects-list 创建 project-list
    list projects;
    _new_list(&projects, sizeof(project));

    // 单元测试
//    _input(&schools, &contacts, &projects);
//    output_school_info(&schools);
//    output_project_info(&projects);
//    output_contact_info(&contacts, &schools, &projects);
//    sort_project_by_score(1,&projects,&contacts,&schools);

    service_menu(&schools, &projects, &contacts);

    return 0;

}

extern void service_menu(list *schools, list *projects, list *contacts) {

    char *scan = (char *) malloc(sizeof(char) * 5);

    while (1) {

        show_menu();

        scanf("%s", scan);
        char * END;
        switch (strtol(scan,&END,10)) {
            case 1:
                scanf("%s", scan);
                _input(strtol(scan,&END,10), schools, contacts, projects);
                break;
            case 2:
                calculate_school_socre(projects, contacts, schools);
                output_school_info(schools);
                break;
            case 3:
                output_project_info(projects);
                break;
            case 4:

                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
        }
    }

}


void show_menu() {

    _ui ui = _get_ui_instance();
    int length = DISPLAY_WIDTH;

    system("clear");
    _ui_print_head(ui, length);
    _ui_print_custom(ui, "录 入 成 绩\0", length);
    _ui_print_custom(ui, "学 校 排 名 情 况\0", length);
    _ui_print_custom(ui, "男 子 团 体 排 名\0", length);
    _ui_print_custom(ui, "女 子 团 体 排 名\0", length);
    _ui_print_custom(ui, "按 学 校 查 询 信 息\0", length);
    _ui_print_custom(ui, "按 项 目 查 询 信 息\0", length);
    _ui_print_custom(ui, "保 存 并 退 出\0", length);

}