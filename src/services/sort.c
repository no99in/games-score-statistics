//
// Created by moss on 1/2/19.
//

#include "sort.h"


void sort_project_by_score(long pid, list *projects, list *contacts, list *schools) {

    stack sort_bucket[101];

    // init
    for (int i = 0; i < 101; ++i) {
        _new_stack(sort_bucket + i, sizeof(contact));
    }

    p_list_node c = contacts->head;

    while (c) {

        if (((contact *) c->data)->pid == pid) {

            _stack_head_push(sort_bucket + ((contact *) c->data)->score, c->data);

        } else {

            _stack_head_push(sort_bucket + 0, c->data);

        }

        c = c->next;
    }

    _ui ui = _get_ui_instance();
    int display_width = DISPLAY_WIDTH;
    system("clear");
    _ui_print_custom_head(ui, "该项目信息\0", display_width);
    _ui_print_custom_row_pre(ui, "学校编号\0", display_width, 3);
    _ui_print_custom_row_sub(ui, "项目编号\0", display_width, 3);
    _ui_print_custom_odd_fix(ui, "得分\0", display_width, 3);
    _ui_print_custom_row_end(ui, display_width);

    int sum = 3;

    for (int i = 100; i >= 0; --i) {
        if ((sort_bucket + i)->head) {

            stack_node *sn = (sort_bucket + i)->head;


            if(sum>0 && i!=0){
                list_node *s = schools->head;


                while(s){
                    if(((school*)s->data)->id == ((contact *) sn->data)->sid){
                        break;
                    }
                    s = s->next;
                }
                if(sum == 3)((school*)s->data)->score+=5;
                if(sum == 2)((school*)s->data)->score+=3;
                if(sum == 1)((school*)s->data)->score+=2;
            }
            --sum;

            while (sn) {
                _ui_print_custom_row_pre(ui, _str_int_to_str(((contact *) sn->data)->sid).ch,
                                         display_width, 3);
                _ui_print_custom_row_sub(ui, _str_int_to_str(((contact *) sn->data)->pid).ch,
                                         display_width, 3);
                _ui_print_custom_odd_fix(ui, _str_int_to_str(((contact *) sn->data)->score).ch,
                                         display_width, 3);
                _ui_print_custom_row_end(ui, display_width);

                _list_back_push(contacts, sn->data);
                _list_remove(contacts, 1);

                sn = sn->next;
            }

        }
    }

    output_contact_info(contacts, schools, projects);



    for (int i = 100; i >= 0; --i) {

        free((sort_bucket + i)->head);

    }

    getchar();
    getchar();

}



void calculate_school_socre(list *projects, list *contacts, list *schools) {

    _ui ui = _get_ui_instance();

    int display_width = DISPLAY_WIDTH;

    _ui_print_custom_head(ui, "这个学校\0", display_width);
    _ui_print_custom_row_pre(ui, "项目名称\0", display_width, 4);
    _ui_print_custom_row_sub(ui, "项目类型\0", display_width, 4);
    _ui_print_custom_odd_fix(ui, "得分\0", display_width, 4);
    _ui_print_custom_odd_fix(ui, "排名\0", display_width, 4);
    _ui_print_custom_row_end(ui, display_width);


    project p;

    long sum_id = project_get_id(p);
    project_reset_id(p);

    long current_id = 1;
    while (current_id < sum_id) {
        sort_project_by_score(current_id, projects, contacts, schools);
        current_id++;
    }


//    while (c) {
//
//        if (((contact *) c->data)->sid == sid) {
//
//            _ui_print_custom_row_pre(ui, _str_int_to_str(((contact *) c->data)->sid).ch,
//                                     display_width, 4);
//            _ui_print_custom_row_sub(ui, _str_int_to_str(((contact *) c->data)->pid).ch,
//                                     display_width, 4);
//            _ui_print_custom_odd_fix(ui, _str_int_to_str(((contact *) c->data)->score).ch,
//                                     display_width, 4);
//            _ui_print_custom_odd_fix(ui, _str_int_to_str(((contact *) c->data)->score).ch,
//                                     display_width, 4);
//            _ui_print_custom_row_end(ui, display_width);
//
//        }
//
//        c = c->next;
//
//    }

}

extern void sort_woman_project_by_score(list *projects, list *contacts) {}

extern void sort_school_by_score(list *projects, list *contacts) {


}

extern void test(list *projects, list *contacts, list *schools) {

    long sum_id = project_get_id(*(project*)projects->head);
    project_reset_id(*(project*)projects->head);

    long current_id = 1;
    while (current_id < sum_id) {
        sort_project_by_score(current_id, projects, contacts, schools);
        current_id++;
    }



    getchar();
    getchar();


}