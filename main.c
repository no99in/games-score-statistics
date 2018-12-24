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

    return 0;
}



void uitest() {

    ui _ui = get_ui_instance();

    ui_print_head(_ui);


}

