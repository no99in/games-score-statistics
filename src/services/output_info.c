//
// Created by moss on 1/2/19.
//

#include "output_info.h"


school output_school_info(list* schools){

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