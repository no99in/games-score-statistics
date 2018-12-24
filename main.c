#include "lib/ui.h"

void uitest();

int main() {
    uitest();
    system("");
    return 0;
}



void uitest() {

    ui _ui;

    new_ui(&_ui);

    ui_print_unit_str(_ui,"中北大学\0");
    printf("\n");
    ui_print_unit_str(_ui,"123asd3\0");
    printf("\n");
    ui_print_unit_str(_ui,"\0");
    printf("\n");
    ui_print_unit_str(_ui,"");
    printf("\n");
    ui_print_unit_str(_ui,NULL);
    printf("\n");
    ui_print_unit_str(_ui,"太原理工大学\0");
    printf("\n");

}

