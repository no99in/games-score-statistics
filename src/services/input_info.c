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
void input_contact_info(school s ,project p ){

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

}

void input(){

    school s = input_school_info();
    project p = input_project_info();
    input_contact_info(s,p);

}