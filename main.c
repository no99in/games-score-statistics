#include "lib/_ui.h"
#include "lib/_str.h"
#include "src/datastructs/list.h"

void ui_test();

int main() {
//
//    //  系统日志
//    _log log;
//    _new_log(&log);
//
//    // ui界面构建
//    _ui ui;
//    _new_ui(&ui);
//
//    // 单元测试
//    ui_test();











    int a = 1;
    int b = 2;

    list int_list;
    _new_list(&int_list, sizeof(int));

    _list_head_push(&int_list,&a);
    _list_head_push(&int_list,&b);

    int c = *(int*)_list_get(int_list,1);
    int d = *(int*)_list_get(int_list,2);

    printf("%d\n",c);
    printf("%d\n",d);

    _list_remove(&int_list,2);

    c = *(int*)_list_get(int_list,1);

    printf("%d\n",c);

    return 0;
}



void ui_test() {

    _ui _ui = _get_ui_instance();
    int display_width = 40;

    _ui_print_head(_ui, display_width);

    _ui_print_custom(_ui, FUN1_DESC, display_width);
    _ui_print_custom(_ui, FUN2_DESC, display_width);
    _ui_print_custom(_ui, FUN3_DESC, display_width);
    _ui_print_custom(_ui, FUN4_DESC, display_width);

}

