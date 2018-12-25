#include "lib/ui.h"

void uitest();

int main() {
    //  系统日志
    log log;
    new_log(&log);

    // ui界面构建
    ui ui;
    new_ui(&ui);

    // 单元测试
    uitest();

    system("clear");
    return 0;
}



void uitest() {

    ui _ui = get_ui_instance();
    int display_width = 40;
    ui_print_head(_ui,display_width);
    ui_print_fun(_ui,display_width);
    ui_print_custom(_ui,"你好呀小朋友",display_width);

}

