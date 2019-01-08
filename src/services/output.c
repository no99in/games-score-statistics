//
// Created by moss on 1/2/19.
//

#include "output.h"


void output_school_info(list *schools) {

    _ui ui = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;
    system("clear");
    _ui_print_custom_head(ui, "全部学校信息\0", display_width);
    _ui_print_custom_row_pre(ui, "名称\0", display_width, 3);
    _ui_print_custom_row_sub(ui, "编号\0", display_width, 3);
    _ui_print_custom_odd_fix(ui, "得分\0", display_width, 3);
    _ui_print_custom_row_end(ui, display_width);

    list_node *ln = schools->head;


    int flag = 0;
    for (int i = 0; i < schools->length - 1; i++) {
        flag = 0;
        while (ln->next) {
            if (((school *) ln->data)->score < ((school *) ln->next->data)->score) {
                flag = 1;
                void *p_data = malloc(schools->data_size);
                memcpy(p_data, ln->data, schools->data_size);
                memcpy(ln->data, ln->next->data, schools->data_size);
                memcpy(ln->next->data, p_data, schools->data_size);
                free(p_data);
            }
            ln = ln->next;
        }
        if (!flag)
            break;
        ln = schools->head;
    }


    ln = schools->head;

    while (ln) {

        _ui_print_custom_row_pre(ui, ((school *) ln->data)->name.ch, display_width, 3);
        _ui_print_custom_row_sub(ui, _str_long_to_str(((school *) ln->data)->id).ch, display_width, 3);
        _ui_print_custom_odd_fix(ui, _str_long_to_str(((school *) ln->data)->score).ch, display_width, 3);
        _ui_print_custom_row_end(ui, display_width);

        ln = ln->next;

    }

    getchar();
    getchar();

}

void output_school_rank(list *schools) {

    _ui ui = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;
    system("clear");
    _ui_print_custom_head(ui, "全部学校信息\0", display_width);
    _ui_print_custom_row_pre(ui, "名称\0", display_width, 3);
    _ui_print_custom_row_sub(ui, "编号\0", display_width, 3);
    _ui_print_custom_odd_fix(ui, "得分\0", display_width, 3);
    _ui_print_custom_row_end(ui, display_width);

    list_node *ln = schools->head;


    int flag = 0;
    for (int i = 0; i < schools->length - 1; i++) {
        flag = 0;
        while (ln->next) {
            if (((school *) ln->data)->score < ((school *) ln->next->data)->score) {
                flag = 1;
                void *p_data = malloc(schools->data_size);
                memcpy(p_data, ln->data, schools->data_size);
                memcpy(ln->data, ln->next->data, schools->data_size);
                memcpy(ln->next->data, p_data, schools->data_size);
                free(p_data);
            }
            ln = ln->next;
        }
        if (!flag)
            break;
        ln = schools->head;
    }


    ln = schools->head;

    while (ln) {

        _ui_print_custom_row_pre(ui, ((school *) ln->data)->name.ch, display_width, 3);
        _ui_print_custom_row_sub(ui, _str_long_to_str(((school *) ln->data)->id).ch, display_width, 3);
        _ui_print_custom_odd_fix(ui, _str_long_to_str(((school *) ln->data)->score).ch, display_width, 3);
        _ui_print_custom_row_end(ui, display_width);

        ln = ln->next;

    }

    getchar();
    getchar();

}


void output_project_info(list *projects) {

    _ui ui = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;


    system("clear");
    _ui_print_custom_head(ui, "全部项目信息\0", display_width);
    _ui_print_custom_row_pre(ui, "名称\0", display_width, 3);
    _ui_print_custom_row_sub(ui, "类型\0", display_width, 3);
    _ui_print_custom_odd_fix(ui, "编号\0", display_width, 3);
    _ui_print_custom_row_end(ui, display_width);

    list_node *n = projects->head;

    while (n) {

        _ui_print_custom_row_pre(ui, ((project *) n->data)->name.ch, display_width, 3);
        _ui_print_custom_row_sub(ui, ((project *) n->data)->type ? "男子\0" : "女子\0", display_width, 3);
        _ui_print_custom_odd_fix(ui, _str_long_to_str(((project *) n->data)->id).ch, display_width, 3);
        _ui_print_custom_row_end(ui, display_width);

        n = n->next;

    }

    getchar();
    getchar();

}

void output_contact_info(list *contacts, list *schools, list *projects) {

    _ui ui = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;

    _ui_print_custom_head(ui, "全部项目成绩\0", display_width);
    _ui_print_custom_row_pre(ui, "学校名称\0", display_width, 4);
    _ui_print_custom_row_sub(ui, "项目名称\0", display_width, 4);
    _ui_print_custom_row_sub(ui, "项目类型\0", display_width, 4);
    _ui_print_custom_odd_fix(ui, "项目成绩\0", display_width, 4);
    _ui_print_custom_row_end(ui, display_width);

    list_node *n = contacts->head;

    while (n) {


        _ui_print_custom_row_pre(ui, output_sid_to_school_name(schools, ((contact *) n->data)->sid).ch, display_width,
                                 4);
        _ui_print_custom_row_sub(ui, output_pid_to_project_name(projects, ((contact *) n->data)->pid).ch, display_width,
                                 4);
        _ui_print_custom_row_sub(ui, output_pid_to_project_type(projects, ((contact *) n->data)->pid), display_width,
                                 4);
        _ui_print_custom_odd_fix(ui, _str_long_to_str(((contact *) n->data)->score).ch, display_width, 4);
        _ui_print_custom_row_end(ui, display_width);

        n = n->next;

    }


    getchar();
    getchar();

}

str output_sid_to_school_name(list *schools, long sid) {

    list_node *sn = schools->head;

    int flag = 0;

    while (sn) {

        if (((school *) sn->data)->id == sid) {
            flag = 1;
            break;
        }

        sn = sn->next;

    }

    if (sn)
        return ((school *) sn->data)->name;


}

str output_pid_to_project_name(list *projects, long pid) {

    list_node *pn = projects->head;

    int flag = 0;

    while (pn) {

        if (((project *) pn->data)->id == pid) {
            flag = 1;
            break;
        }

        pn = pn->next;

    }

    if (pn)
        return ((project *) pn->data)->name;

}

char *output_pid_to_project_type(list *projects, long pid) {

    list_node *pn = projects->head;

    int flag = 0;

    while (pn) {

        if (((project *) pn->data)->id == pid) {
            flag = 1;
            break;
        }

        pn = pn->next;

    }

    if (pn)
        return ((project *) pn->data)->type ? "男子\0" : "女子\0";

}

void output_project_rank(long pid, list *projects, list *contacts, list *schools) {


    _ui ui = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;

    _ui_print_custom_head(ui, "项目成绩\0", display_width);
    _ui_print_custom_row_pre(ui, "学校编号\0", display_width, 3);
    _ui_print_custom_row_sub(ui, "学校名称\0", display_width, 3);
    _ui_print_custom_odd_fix(ui, "项目成绩\0", display_width, 3);
    _ui_print_custom_row_end(ui, display_width);

    list_node *ln = projects->head;

    while (ln) {

        if (((project *) ln->data)->id == pid)
            break;

        ln = ln->next;
    }
    list_node *p = ln;

    ln = contacts->head;

    while (ln) {

        if (((contact *) ln->data)->pid == pid) {

            list_node *s = schools->head;

            while (s) {

                if (((school *) s->data)->id == ((contact *) ln->data)->sid)
                    break;

                s = s->next;

            }
            if (s)
                _ui_print_custom_row_pre(ui, (_str_long_to_str(((school *) s->data)->id)).ch, display_width, 3);
            if (s)
                _ui_print_custom_row_sub(ui, ((school *) s->data)->name.ch, display_width, 3);
            _ui_print_custom_odd_fix(ui, _str_int_to_str(((contact *) ln->data)->score).ch, display_width, 3);
            _ui_print_custom_row_end(ui, display_width);
        }

        ln = ln->next;

    }


    getchar();
    getchar();

}

void output_school_info_by_num(long sid, list *schools, list *contacts, list *projects) {


    _ui ui = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;

    _ui_print_custom_head(ui, "项目成绩\0", display_width);
    _ui_print_custom_row_pre(ui, "项目名称\0", display_width, 3);
    _ui_print_custom_row_sub(ui, "项目类型\0", display_width, 3);
    _ui_print_custom_odd_fix(ui, "项目成绩\0", display_width, 3);
    _ui_print_custom_row_end(ui, display_width);

    list_node *ln = schools->head;

    while (ln) {

        if (((school *) ln->data)->id == sid)
            break;

        ln = ln->next;
    }
    list_node *s = ln;

    ln = contacts->head;

    while (ln) {

        if (((contact *) ln->data)->sid == sid) {

            list_node *p = projects->head;

            while (p) {

                if (((project *) p->data)->id == ((contact *) ln->data)->pid)
                    break;

                p = p->next;

            }
            if (p)
                _ui_print_custom_row_pre(ui, ((project *) p->data)->name.ch, display_width, 3);
            if (p)
                _ui_print_custom_row_sub(ui, _str_int_to_str(((project *) p->data)->type).ch, display_width, 3);
            if (p)
                _ui_print_custom_odd_fix(ui, _str_int_to_str(((contact *) ln->data)->score).ch, display_width, 3);
            if (p)
                _ui_print_custom_row_end(ui, display_width);
        }

        ln = ln->next;

    }


    getchar();
    getchar();

}

void output_man_project_rank(list *schools) {

    _ui ui = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;
    system("clear");
    _ui_print_custom_head(ui, "全部学校信息\0", display_width);
    _ui_print_custom_row_pre(ui, "名称\0", display_width, 3);
    _ui_print_custom_row_sub(ui, "编号\0", display_width, 3);
    _ui_print_custom_odd_fix(ui, "得分\0", display_width, 3);
    _ui_print_custom_row_end(ui, display_width);

    list_node *ln = schools->head;


    int flag = 0;
    for (int i = 0; i < schools->length - 1; i++) {
        flag = 0;
        while (ln->next) {
            if (((school *) ln->data)->man_score < ((school *) ln->next->data)->man_score) {
                flag = 1;
                void *p_data = malloc(schools->data_size);
                memcpy(p_data, ln->data, schools->data_size);
                memcpy(ln->data, ln->next->data, schools->data_size);
                memcpy(ln->next->data, p_data, schools->data_size);
                free(p_data);
            }
            ln = ln->next;
        }
        if (!flag)
            break;
        ln = schools->head;
    }


    ln = schools->head;

    while (ln) {

        _ui_print_custom_row_pre(ui, ((school *) ln->data)->name.ch, display_width, 3);
        _ui_print_custom_row_sub(ui, _str_long_to_str(((school *) ln->data)->id).ch, display_width, 3);
        _ui_print_custom_odd_fix(ui, _str_long_to_str(((school *) ln->data)->man_score).ch, display_width, 3);
        _ui_print_custom_row_end(ui, display_width);

        ln = ln->next;

    }

    getchar();
    getchar();


}

void output_woman_project_rank(list *schools) {

    _ui ui = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;
    system("clear");
    _ui_print_custom_head(ui, "全部学校信息\0", display_width);
    _ui_print_custom_row_pre(ui, "名称\0", display_width, 3);
    _ui_print_custom_row_sub(ui, "编号\0", display_width, 3);
    _ui_print_custom_odd_fix(ui, "得分\0", display_width, 3);
    _ui_print_custom_row_end(ui, display_width);

    list_node *ln = schools->head;


    int flag = 0;
    for (int i = 0; i < schools->length - 1; i++) {
        flag = 0;
        while (ln->next) {
            if (((school *) ln->data)->woman_score < ((school *) ln->next->data)->woman_score) {
                flag = 1;
                void *p_data = malloc(schools->data_size);
                memcpy(p_data, ln->data, schools->data_size);
                memcpy(ln->data, ln->next->data, schools->data_size);
                memcpy(ln->next->data, p_data, schools->data_size);
                free(p_data);
            }
            ln = ln->next;
        }
        if (!flag)
            break;
        ln = schools->head;
    }


    ln = schools->head;

    while (ln) {

        _ui_print_custom_row_pre(ui, ((school *) ln->data)->name.ch, display_width, 3);
        _ui_print_custom_row_sub(ui, _str_long_to_str(((school *) ln->data)->id).ch, display_width, 3);
        _ui_print_custom_odd_fix(ui, _str_long_to_str(((school *) ln->data)->woman_score).ch, display_width, 3);
        _ui_print_custom_row_end(ui, display_width);

        ln = ln->next;

    }

    getchar();
    getchar();


}

