/**
 * @description  纯C语言实现的字符串 C language file function
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         tofile.c
 * @date         2019-01-06
 */

#include "tofile.h"

STATUS _schools_to_file(list *schools) {
    FILE *_p_f = NULL;
    _p_f = fopen("./sources/schools.dat", "w+");
    fprintf(_p_f, "\n");
    list_node *ln = schools->head;
    while (ln) {
        fprintf(_p_f, "%ld\n", ((school *) ln->data)->id);
        fprintf(_p_f, "%s\n", ((school *) ln->data)->name.ch);
        fprintf(_p_f, "%d\n", ((school *) ln->data)->score);
        fprintf(_p_f, "%d\n", ((school *) ln->data)->man_score);
        fprintf(_p_f, "%d\n", ((school *) ln->data)->woman_score);
        ln = ln->next;

    }
    fclose(_p_f);
}

STATUS _projects_to_file(list *projects) {
    FILE *_p_f = NULL;
    _p_f = fopen("./sources/projects.dat", "w+");
    fprintf(_p_f, "\n");
    list_node *ln = projects->head;
    while (ln) {
        fprintf(_p_f, "%ld\n", ((project *) ln->data)->id);
        fprintf(_p_f, "%s\n", ((project *) ln->data)->name.ch);
        fprintf(_p_f, "%d\n", ((project *) ln->data)->type);
        ln = ln->next;
    }
    fclose(_p_f);
}

STATUS _contacts_to_file(list *contacts) {
    FILE *_p_f = NULL;
    _p_f = fopen("./sources/contacts.dat", "w+");
    fprintf(_p_f, "\n");
    list_node *ln = contacts->head;
    while (ln) {
        fprintf(_p_f, "%ld\n", ((contact *) ln->data)->pid);
        fprintf(_p_f, "%ld\n", ((contact *) ln->data)->sid);
        fprintf(_p_f, "%d\n", ((contact *) ln->data)->score);
        ln = ln->next;
    }
    fclose(_p_f);

}


STATUS _file_to_schools(list *schools) {
    FILE *_p_f = NULL;
    _p_f = fopen("./sources/schools.dat", "r+");
    if (!_p_f) return ERROR;
    char *buff = (malloc(sizeof(char) * 100));
    fseek(_p_f, 0L, SEEK_END);
    long end = ftell(_p_f);
    fseek(_p_f, 0L, SEEK_SET);
    long start = ftell(_p_f);
    fscanf(_p_f, "%s\n", buff);
    while (end != start) {
        school s;
        fscanf(_p_f, "%s\n", buff);
        s.id = _str_str_to_long(buff);
        fscanf(_p_f, "%s\n", buff);
        _str_assign(&s.name, buff);
        fscanf(_p_f, "%s\n", buff);
        s.score = _str_str_to_int(buff);
        fscanf(_p_f, "%s\n", buff);
        s.man_score = _str_str_to_int(buff);
        fscanf(_p_f, "%s\n", buff);
        s.woman_score = _str_str_to_int(buff);
        _list_head_push(schools, &s);
        school_get_id(s);
        start = ftell(_p_f);
    }
    fclose(_p_f);
}

STATUS _files_to_project(list *projects) {
    FILE *_p_f = NULL;
    _p_f = fopen("./sources/projects.dat", "r+");
    if (!_p_f) return ERROR;
    char *buff = (malloc(sizeof(char) * 100));
    fseek(_p_f, 0L, SEEK_END);
    long end = ftell(_p_f);
    fseek(_p_f, 0L, SEEK_SET);
    long start = ftell(_p_f);
    fscanf(_p_f, "%s\n", buff);
    while (end != start) {
        project p;
        fscanf(_p_f, "%s\n", buff);
        p.id = _str_str_to_long(buff);
        fscanf(_p_f, "%s\n", buff);
        _str_assign(&p.name, buff);
        fscanf(_p_f, "%s\n", buff);
        p.type = _str_str_to_int(buff);
        project_get_id(p);
        _list_head_push(projects, &p);
        start = ftell(_p_f);
    }
    free(buff);
    fclose(_p_f);
}

STATUS _file_to_contacts(list *contacts) {
    FILE *_p_f = NULL;
    _p_f = fopen("./sources/contacts.dat", "r+");
    if (!_p_f) return ERROR;
    char *buff = (malloc(sizeof(char) * 100));
    fseek(_p_f, 0L, SEEK_END);
    long end = ftell(_p_f);
    fseek(_p_f, 0L, SEEK_SET);
    long start = ftell(_p_f);
    fscanf(_p_f, "%s\n", buff);
    while (end != start) {
        contact c;
        fscanf(_p_f, "%s\n", buff);
        c.pid = _str_str_to_long(buff);
        fscanf(_p_f, "%s\n", buff);
        c.sid = _str_str_to_long(buff);
        fscanf(_p_f, "%s\n", buff);
        c.score = _str_str_to_int(buff);
        _list_head_push(contacts, &c);
        start = ftell(_p_f);
    }
    free(buff);
    fclose(_p_f);
}