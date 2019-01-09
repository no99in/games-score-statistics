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
    _file_to_schools(&schools);
    _file_to_projects(&projects);
    _file_to_contacts(&contacts);
    service_menu(&schools, &projects, &contacts);
    return 0;
}

void service_menu(list *schools, list *projects, list *contacts) {
    char *scan = (char *) malloc(sizeof(char) * 5);
    _ui ui  = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;
    while (1) {
        show_menu();
        scanf("%s", scan);
        char *END;
        switch (strtol(scan, &END, 10)) {
            case 1:
                _ui_print_custom_head(ui, "请输入录入数据的个数\0", display_width);
                scanf("%s", scan);
                _input(strtol(scan, &END, 10), schools, contacts, projects);
                break;
            case 2:
                calculate_school_score(projects, contacts, schools);
                output_school_info(schools);
                break;
            case 3:
                calculate_school_score(projects, contacts, schools);
                output_man_project_rank(schools);
                break;
            case 4:
                calculate_school_score(projects, contacts, schools);
                output_woman_project_rank(schools);
                break;
            case 6:
                system("clear");
                _ui_print_custom_head(ui, "请输入查询项目的编号\0", display_width);
                scanf("%s", scan);
                sort_school_by_score(contacts);
                system("clear");
                output_project_rank(strtol(scan, &END, 10), projects, contacts, schools);
                break;
            case 5:
                system("clear");
                _ui_print_custom_head(ui, "请输入查询学校的编号\0", display_width);
                scanf("%s", scan);
                system("clear");
                output_school_info_by_num(strtol(scan, &END, 10), schools, contacts, projects);
                break;
            case 7:
                output_school_rank(schools);
                break;
            case 8:
                output_project_info(projects);
                break;
            case 9:
                _schools_to_file(schools);
                _contacts_to_file(contacts);
                _projects_to_file(projects);
                exit(0);
        }
    }
}


void show_menu() {
    _ui ui = _get_ui_instance();
    int length = DISPLAY_WIDTH;
    system("clear");
    _ui_print_head(ui, length);
    _ui_print_custom(ui, "1 录 入 成 绩\0", length);
    _ui_print_custom(ui, "2 学 校 排 名 情 况\0", length);
    _ui_print_custom(ui, "3 男 子 团 体 排 名\0", length);
    _ui_print_custom(ui, "4 女 子 团 体 排 名\0", length);
    _ui_print_custom(ui, "5 按 学 校 查 询 信 息\0", length);
    _ui_print_custom(ui, "6 按 项 目 查 询 信 息\0", length);
    _ui_print_custom(ui, "7 学 校 信 息 表\0", length);
    _ui_print_custom(ui, "8 项 目 信 息 表\0", length);
    _ui_print_custom(ui, "9 保 存 并 退 出\0", length);
}