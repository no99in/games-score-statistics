//
// Created by moss on 1/2/19.
//

#include "input_info.h"

int display_width = DISPLAY_WIDTH;

void input_school_info(){

    char * input = (char*)malloc(sizeof(char)*100);

    _ui ui = _get_ui_instance();
    _ui_print_custom_head(ui,"请输入学校名称\0",display_width);

    scanf("%s",input);

    str school_name;
    _str_assign(&school_name,input);

    free(input);

}
void input_project_info(){

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

    str project_type_wman1;
    _str_assign(&project_type_wman1,"女\0");
    str project_type_wman2;
    _str_assign(&project_type_wman2,"0\0");
    str project_type_wman3;
    _str_assign(&project_type_wman3,"女子\0");


    if(_str_compare(input_project_type,project_type_man1)||_str_compare(input_project_type,project_type_man2)||_str_compare(input_project_type,project_type_man3)){project_type = 1;}
    if(_str_compare(input_project_type,project_type_wman1)||_str_compare(input_project_type,project_type_wman2)||_str_compare(input_project_type,project_type_wman3)){project_type = 0;}

    free(input);

}
void input_contact_info(){



}