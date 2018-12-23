//
// Created by mossnodie on 12/23/18.
//

#include "../header/ui.h"

static int u_len = DISPLAY_MAX_STRING_LENGTH;
char * null_str = NULL_STR;
char * zero_str = ZERO_STR;
char * long_str = LONG_STR;

static int strlength(char * s){

    int res = 0;
    double flag_cn_op = 0.0;
    char * strp = s;
    while(*strp!='\0'){

        if(*strp >= 'A' && *strp <= 'Z')
            res += 1;
        else if(*strp >= 'a' && *strp <= 'z')
            res += 1;
        else if(*strp >= '0' && *strp <= '9')
            res += 1;
        else if(*strp == ' ')
            res += 1;
        else {

            flag_cn_op += 0.5;

            if(flag_cn_op == 1.5){
                res += 2;
                flag_cn_op = 0;
            }


        }
        ++strp;
    }
    return res;

}



extern void printstr(char * s) {

    if(!s) s = null_str;

    int str_len = strlength(s);
    //printf("%d",str_len);
    if(!str_len) {
        s = zero_str;
        str_len = strlength(s);
    }else if(str_len > u_len){
        s = long_str;
        str_len = strlength(s);
    }

    int flag_u_bnk_len_dcl = (u_len - str_len) % 2?1:0;
    int u_bnk_len = (u_len - str_len) / 2;

    int l_bak_len = u_bnk_len;
    while(l_bak_len > 0) {
        printf(" ");
        --l_bak_len;
    }


    printf(s);

    int r_bak_len = u_bnk_len;
    if(flag_u_bnk_len_dcl) printf(" ");
    while(r_bak_len > 0) {
        printf(" ");
        --r_bak_len;
    }

}
extern void printunintystr(char * s) {
    printf("|");
    printstr(s);
    printf("|");
}

