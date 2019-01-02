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

    double e = 1.0;
    double f = 2.0;

    list double_list;
    _new_list(&double_list, sizeof(double));

    _list_head_push(&double_list,&e);
    _list_head_push(&double_list,&f);

    double g = *(double *)_list_get(double_list,1);
    double h = *(double *)_list_get(double_list,2);

    printf("%lf\n",g);
    printf("%lf\n",h);

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

