//
// Created by moss on 1/2/19.
//

#include "input.h"

int display_width = DISPLAY_WIDTH;

school input_school_info() {

    char *input = (char *) malloc(sizeof(char) * 100);

    _ui ui = _get_ui_instance();
    system("clear");
    _ui_print_custom_head(ui, "请输入学校名称\0", display_width);

    scanf("%s", input);
    school *s = (p_school) malloc(sizeof(school));

    _str_assign(&s->name, input);

    s->id = school_get_id(*s);

    s->score = 0;

    free(input);

    return *s;

}

project input_project_info() {

    project *p = (p_project) malloc(sizeof(project));

    char *input = (char *) malloc(sizeof(char) * 100);

    _ui ui = _get_ui_instance();

    system("clear");

    _ui_print_custom_head(ui, "请输入项目名称\0", display_width);

    scanf("%s", input);

    _str_assign(&p->name, input);

    system("clear");

    _ui_print_custom_head(ui, "请输入项目类型\0", display_width);

    int project_type = 0;

    scanf("%s", input);

    str input_project_type;
    _str_assign(&input_project_type, input);

    str project_type_man1;
    _str_assign(&project_type_man1, "男\0");
    str project_type_man2;
    _str_assign(&project_type_man2, "1\0");
    str project_type_man3;
    _str_assign(&project_type_man3, "男子\0");

    str project_type_woman1;
    _str_assign(&project_type_woman1, "女\0");
    str project_type_woman2;
    _str_assign(&project_type_woman2, "0\0");
    str project_type_woman3;
    _str_assign(&project_type_woman3, "女子\0");


    if (_str_compare(input_project_type, project_type_man1) == 0 ||
        _str_compare(input_project_type, project_type_man2) == 0 ||
        _str_compare(input_project_type, project_type_man3) == 0) { project_type = 1; }
    if (_str_compare(input_project_type, project_type_woman1) == 0 ||
        _str_compare(input_project_type, project_type_woman2) == 0 ||
        _str_compare(input_project_type, project_type_woman3) == 0) { project_type = 0; }

    p->type = project_type;
    p->id = project_get_id(*p);

    free(input);

    return *p;

}

contact input_contact_info(school s, project p, list *schools, list *projects, list *contacts) {

    contact *c = (p_contact) malloc(sizeof(contact));

    _ui ui = _get_ui_instance();

    system("clear");
    _ui_print_custom_head(ui, "请确认学校与项目\0", display_width);
    _ui_print_custom_row_pre(ui, "学校\0", display_width, 3);
    _ui_print_custom_row_sub(ui, "项目\0", display_width, 3);
    _ui_print_custom_odd_fix(ui, "类型\0", display_width, 3);
    _ui_print_custom_row_end(ui, display_width);


    _ui_print_custom_row_pre(ui, s.name.ch, display_width, 3);
    _ui_print_custom_row_sub(ui, p.name.ch, display_width, 3);
    p.type ? _ui_print_custom_odd_fix(ui, "男子\0", display_width, 3) : _ui_print_custom_odd_fix(ui, "女子\0",
                                                                                               display_width, 3);
    _ui_print_custom_row_end(ui, display_width);

    char *input = (char *) malloc(sizeof(char) * 100);
    scanf("%s", input);
    str input_is;
    _str_assign(&input_is, input);

    str project_type_is_1;
    _str_assign(&project_type_is_1, "是\0");
    str project_type_is_2;
    _str_assign(&project_type_is_2, "1\0");
    str project_type_is_3;
    _str_assign(&project_type_is_3, "正确\0");

    str project_type_isnot_1;
    _str_assign(&project_type_isnot_1, "否\0");
    str project_type_isnot_2;
    _str_assign(&project_type_isnot_2, "0\0");
    str project_type_isnot_3;
    _str_assign(&project_type_isnot_3, "错误\0");

    if (_str_compare(input_is, project_type_is_3) == 0 || _str_compare(input_is, project_type_is_2) == 0 ||
        _str_compare(input_is, project_type_is_1) == 0) {
        system("clear");
        _ui_print_custom_head(ui, "请输入成绩\0", display_width);
        scanf("%s", input);
        int score = strtol(input, NULL, 10);
        c->score = score;
        c->pid = p.id;
        c->sid = s.id;
        return *c;
    }
    if (_str_compare(input_is, project_type_isnot_1) == 0 || _str_compare(input_is, project_type_isnot_2) == 0 ||
        _str_compare(input_is, project_type_isnot_3) == 0) {
        c->pid = -1;
        c->sid = -1;
        return *c;
    }
}


void _input(int times,list *schools, list *contacts, list *projects) {

    int i = times;

    while (i-- > 0) {
        school s = input_school_info();
        project p = input_project_info();
        contact c = input_contact_info(s, p, schools, projects,contacts);
        if(c.pid == -1 && c.sid == -1)
            ++i;
        else
            input_update(schools, &s, projects, &p, contacts, &c);
    }

}


void input_update(list *schools, school *s, list *projects, project *p, list *contacts, contact *c) {

    list_node *sn = schools->head;

    int flag = 0;

    while (sn) {

        if (_str_compare(((school *) sn->data)->name, s->name) == 0) {
            flag = 1;
            break;
        }

        sn = sn->next;

    }

    if (!flag)
        _list_head_push(schools, s);
    else {
        s->id = ((school *) sn->data)->id;
        school_reset_id(*s);
    }

    list_node *pn = projects->head;

    flag = 0;

    while (pn) {

        if ((_str_compare(((project *) pn->data)->name, p->name) == 0) && ((project *)pn->data)->type == p->type) {
            flag = 1;
            break;
        }

        pn = pn->next;

    }

    if (!flag)
        _list_head_push(projects, p);
    else {
        p->id = ((project *) pn->data)->id;
        project_reset_id(*p);
    }


    c->sid = s->id;
    c->pid = p->id;

    list_node *cn = contacts->head;

    flag = 0;

    while (cn) {

        if (((contact *) cn->data)->sid == c->sid && ((contact *) cn->data)->pid == c->pid) {
            flag = 1;
            break;
        }

        cn = cn->next;

    }

    if (!flag)
        _list_head_push(contacts, c);
    else
        ((contact *) cn->data)->score = c->score;

}