#include "lib/ui.h"

void uitest();

int main() {
    uitest();
    system("");
    return 0;
}



void uitest() {


    printunintystr("中北大学\0");
    printf("\n");
    printunintystr("123asd3\0");
    printf("\n");
    printunintystr("\0");
    printf("\n");
    printunintystr("");
    printf("\n");
    printunintystr(NULL);
    printf("\n");
    printunintystr("太原理工大学\0");
    printf("\n");

}

