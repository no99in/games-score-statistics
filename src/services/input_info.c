//
// Created by moss on 1/2/19.
//

#include "input_info.h"

int display_width = DISPLAY_WIDTH;

school input_school_info(){

    char * input = (char*)malloc(sizeof(char)*100);

    _ui ui = _get_ui_instance();
    _ui_print_custom_head(ui,"请输入学校名称\0",display_width);

    scanf("%s",input);

    str school_name;
    _str_assign(&school_name,input);

    school * s = (pschool)malloc(sizeof(school));
    _str_copy(&s->name,&school_name);
    s->id = 1;

    free(input);

    return *s;

}
project input_project_info(){

    project * p = (pproject)malloc(sizeof(project));

    char * input = (char*)malloc(sizeof(char)*100);

    _ui ui = _get_ui_instance();
    _ui_print_custom_head(ui,"请输入项目名称\0",display_width);

    scanf("%s",input);

    str project_name;
    _str_assign(&project_name,input);

    _ui_print_custom_head(ui,"请输入项目类型\0",display_width);

    int project_type = 0;

    scanf("%s",input);

    str input_project_type;
    _str_assign(&input_project_type,input);

    str project_type_man1;
    _str_assign(&project_type_man1,"男\0");
    str project_type_man2;
    _str_assign(&project_type_man2,"1\0");
    str project_type_man3;
    _str_assign(&project_type_man3,"男子\0");

    str project_type_woman1;
    _str_assign(&project_type_woman1,"女\0");
    str project_type_woman2;
    _str_assign(&project_type_woman2,"0\0");
    str project_type_woman3;
    _str_assign(&project_type_woman3,"女子\0");


    if(_str_compare(input_project_type,project_type_man1)==0||_str_compare(input_project_type,project_type_man2)==0||_str_compare(input_project_type,project_type_man3)==0){project_type = 1;}
    if(_str_compare(input_project_type,project_type_woman1)==0||_str_compare(input_project_type,project_type_woman2)==0||_str_compare(input_project_type,project_type_woman3)==0){project_type = 0;}

    _str_copy(&p->name,&project_name);
    p->type = project_type;
    p->id = 1;

    free(input);

    return *p;

}
contact input_contact_info(school s ,project p ,list *schools,list *projects,list *contacts){

    contact * c = (pcontact)malloc(sizeof(contact));

    _ui ui = _get_ui_instance();
    _ui_print_custom_head(ui,"请确认学校与项目\0",display_width);
    _ui_print_custom_row_pre(ui,"学校\0",display_width,3);
    _ui_print_custom_row_sub(ui,"项目\0",display_width,3);
    _ui_print_custom_odd_fix(ui,"类型\0",display_width,3);
    _ui_print_custom_row_end(ui,display_width);


    _ui_print_custom_row_pre(ui,s.name.ch,display_width,3);
    _ui_print_custom_row_sub(ui,p.name.ch,display_width,3);
    p.type?_ui_print_custom_odd_fix(ui,"男子\0",display_width,3):_ui_print_custom_odd_fix(ui,"女子\0",display_width,3);
    _ui_print_custom_row_end(ui,display_width);

    char * input = (char*)malloc(sizeof(char)*100);
    scanf("%s",input);
    str input_is;
    _str_assign(&input_is,input);

    str project_type_is_1;
    _str_assign(&project_type_is_1,"是\0");
    str project_type_is_2;
    _str_assign(&project_type_is_2,"1\0");
    str project_type_is_3;
    _str_assign(&project_type_is_3,"正确\0");

    str project_type_isnot_1;
    _str_assign(&project_type_isnot_1,"否\0");
    str project_type_isnot_2;
    _str_assign(&project_type_isnot_2,"0\0");
    str project_type_isnot_3;
    _str_assign(&project_type_isnot_3,"错误\0");

    if(_str_compare(input_is,project_type_is_3)==0||_str_compare(input_is,project_type_is_2)==0||_str_compare(input_is,project_type_is_1)==0){
        _ui_print_custom_head(ui,"请输入成绩\0",display_width);
        scanf("%s",input);
        int score = strtol(input,NULL,10);
        c->score = score;
        c->pid = p.id;
        c->sid = s.id;
        return *c;
    }
    if(_str_compare(input_is,project_type_isnot_1)==0||_str_compare(input_is,project_type_isnot_2)==0||_str_compare(input_is,project_type_isnot_3)==0){
        _input( schools, contacts, projects);
    }
}

void input_update_school_info(list *schools,school s){
    _list_head_push(schools,&s);
}
void input_update_project_info(list *projects,project p){
    _list_head_push(projects,&p);
}
void input_update_contact_info(list *contacts,contact c){
    _list_head_push(contacts,&c);
}

void _input(list *schools,list *contacts,list *projects){

    school s = input_school_info();
    project p = input_project_info();
    contact c = input_contact_info(s,p,schools,contacts,projects);

    input_update_school_info(schools,s);
    input_update_project_info(projects,p);
    input_update_contact_info(contacts,c);

}