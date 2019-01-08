#include "sort.h"

void sort_school_by_score_no_input(long pid, list *projects, list *contacts, list *schools) {
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
    int sum = 3;
    for (int i = 100; i >= 0; --i) {
        if ((sort_bucket + i)->head) {
            stack_node *sn = (sort_bucket + i)->head;
            while (sn) {
                if (sum > 0 && i != 0) {
                    list_node *p = projects->head;
                    while (p) {
                        if (((project *) p->data)->id == ((contact *) sn->data)->pid) {
                            break;
                        }
                        p = p->next;
                    }
                    list_node *s = schools->head;
                    while (s) {
                        if (((school *) s->data)->id == ((contact *) sn->data)->sid) {
                            if (sum == 3)((school *) s->data)->score += 5;
                            if (sum == 3)
                                ((project *) p->data)->type ? (((school *) s->data)->man_score += 5)
                                                            : (((school *) s->data)->woman_score += 5);
                            if (sum == 2)((school *) s->data)->score += 3;
                            if (sum == 2)
                                ((project *) p->data)->type ? (((school *) s->data)->man_score += 3)
                                                            : (((school *) s->data)->woman_score += 3);
                            if (sum == 1)((school *) s->data)->score += 2;
                            if (sum == 1)
                                ((project *) p->data)->type ? (((school *) s->data)->man_score += 2)
                                                            : (((school *) s->data)->woman_score += 2);
                        }
                        s = s->next;
                    }
                }
                _list_back_push(contacts, sn->data);
                _list_remove(contacts, 1);

                sn = sn->next;
            }
            --sum;
        }
    }
    for (int i = 100; i >= 0; --i) {
        free((sort_bucket + i)->head);
    }
}

void sort_school_by_score(list *contacts) {
    list_node *ln = contacts->head;
    int flag = 0;
    for (int i = 0; i < contacts->length - 1; i++) {
        flag = 0;
        while (ln->next) {
            if (((contact *) ln->data)->score < ((contact *) ln->next->data)->score) {
                flag = 1;
                void *p_data = malloc(contacts->data_size);
                memcpy(p_data, ln->data, contacts->data_size);
                memcpy(ln->data, ln->next->data, contacts->data_size);
                memcpy(ln->next->data, p_data, contacts->data_size);
                free(p_data);
            }
            ln = ln->next;
        }
        if (!flag)
            break;
        ln = contacts->head;
    }
}

void calculate_school_score(list *projects, list *contacts, list *schools) {
    if (!projects->head)
        return;
    long sum_id = project_get_id(*(project *) projects->head);
    project_reset_id(*(project *) projects->head);

    list_node *s = schools->head;
    while (s) {
        ((school *) s->data)->score = 0;
        ((school *) s->data)->man_score = 0;
        ((school *) s->data)->woman_score = 0;
        s = s->next;
    }
    long current_id = 1;
    while (current_id < sum_id) {
        sort_school_by_score_no_input(current_id, projects, contacts, schools);
        ++current_id;
    }
    getchar();
    getchar();
}