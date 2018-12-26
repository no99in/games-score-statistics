#include "view/ui.h"

void ui_test();

int main() {

    //  系统日志
    log log;
    new_log(&log);

    // ui界面构建
    ui ui;
    new_ui(&ui);

    // 单元测试
    ui_test();

    system("clear");
    return 0;
}



void ui_test() {

    ui _ui = get_ui_instance();
    int display_width = 40;

    ui_print_head(_ui,display_width);

    ui_print_custom(_ui,FUN1_DESC,display_width);
    ui_print_custom(_ui,FUN2_DESC,display_width);
    ui_print_custom(_ui,FUN3_DESC,display_width);
    ui_print_custom(_ui,FUN4_DESC,display_width);

}

