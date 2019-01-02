//
// Created by moss on 1/2/19.
//

#include "output_info.h"


void output_school_info(list* schools){

    _ui ui = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;

    _ui_print_custom_head(ui,"全部学校信息\0",display_width);
    _ui_print_custom_row_pre(ui,"名称\0",display_width,3);
    _ui_print_custom_row_sub(ui,"编号\0",display_width,3);
    _ui_print_custom_odd_fix(ui,"得分\0",display_width,3);
    _ui_print_custom_row_end(ui,display_width);

    node * n = schools->head;

    while(n){

        _ui_print_custom_row_pre(ui,((school*)n->data)->name.ch,display_width,3);
        _ui_print_custom_row_sub(ui,_str_long_to_str(((school*)n->data)->id).ch,display_width,3);
        _ui_print_custom_odd_fix(ui,_str_long_to_str(((school*)n->data)->score).ch,display_width,3);
        _ui_print_custom_row_end(ui,display_width);

        n = n->next;

    }

}

void output_project_info(list* projects){

    _ui ui = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;

    _ui_print_custom_head(ui,"全部项目信息\0",display_width);
    _ui_print_custom_row_pre(ui,"名称\0",display_width,3);
    _ui_print_custom_row_sub(ui,"类型\0",display_width,3);
    _ui_print_custom_odd_fix(ui,"编号\0",display_width,3);
    _ui_print_custom_row_end(ui,display_width);

    node * n = projects->head;

    while(n){

        _ui_print_custom_row_pre(ui,((project*)n->data)->name.ch,display_width,3);
        _ui_print_custom_row_sub(ui,((project*)n)->type?"男子\0":"女子\0",display_width,3);
        _ui_print_custom_odd_fix(ui,_str_long_to_str(((project*)n->data)->id).ch,display_width,3);
        _ui_print_custom_row_end(ui,display_width);

        n = n->next;

    }


}

void output_contact_info(list* contacts,list *schools,list* projects){

    _ui ui = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;

    _ui_print_custom_head(ui,"全部项目成绩\0",display_width);
    _ui_print_custom_row_pre(ui,"学校名称\0",display_width,4);
    _ui_print_custom_row_sub(ui,"项目名称\0",display_width,4);
    _ui_print_custom_row_sub(ui,"项目类型\0",display_width,4);
    _ui_print_custom_odd_fix(ui,"项目成绩\0",display_width,4);
    _ui_print_custom_row_end(ui,display_width);

    node * n = contacts->head;

    while(n){



        _ui_print_custom_row_pre(ui,output_sid_to_school_name(schools,((contact*)n->data)->sid).ch,display_width,4);
        _ui_print_custom_row_sub(ui,output_pid_to_project_name(projects,((contact*)n->data)->pid).ch,display_width,4);
        _ui_print_custom_row_sub(ui,output_pid_to_project_type(projects,((contact*)n->data)->pid),display_width,4);
        _ui_print_custom_odd_fix(ui,_str_long_to_str(((contact*)n->data)->score).ch,display_width,4);
        _ui_print_custom_row_end(ui,display_width);

        n = n->next;

    }

}

str output_sid_to_school_name(list * schools,int sid){

    node * sn = schools->head;

    int flag = 0;

    while(sn){

        if(((school*)sn->data)->id == sid){
            flag = 1;
            break;
        }

        sn = sn->next;

    }

    return ((school*)sn->data)->name;

}

str output_pid_to_project_name(list *projects, int pid){

    node * pn = projects->head;

    int flag = 0;

    while(pn){

        if(((project*)pn->data)->id == pid){
            flag = 1;
            break;
        }

        pn = pn->next;

    }

    return ((project*)pn->data)->name;

}

char * output_pid_to_project_type(list *projects, int pid){

    node * pn = projects->head;

    int flag = 0;

    while(pn){

        if(((project*)pn->data)->id == pid){
            flag = 1;
            break;
        }

        pn = pn->next;

    }

    return ((project*)pn)->type?"男子\0":"女子\0";

}