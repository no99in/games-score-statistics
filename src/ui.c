//
// Created by mossnodie on 12/23/18.
//

#include "../lib/ui.h"

ui * ui_instance = NULL;

extern ui get_ui_instance(){
    if(!ui_instance)
        new_ui(ui_instance);
    return *ui_instance;
}

extern void new_ui(ui * self) {

    // 开辟ui
    ui * _self = (pui)malloc(sizeof(ui));
    log _log = get_log_instance();
    if(!_self) {

        _log.log_information = "UI界面初始化失败,错误代码(500)!\0";
        notify(ERROR,_log.log_information);
        exit(500);
    }
    // 初始化
    _self->long_str = LONG_STR;
    _self->null_str = NULL_STR;
    _self->zero_str = ZERO_STR;

    *self = *_self;
    ui_instance = _self;

    _log.log_information  = "UI界面初始化完成!\0";

    notify(INFO,_log.log_information);

}

static int str_length(char * s){

    int res = 0;
    double flag_cn_op = 0.0;
    char * str_p = s;
    while(*str_p!='\0'){

        if(*str_p >= 'A' && *str_p <= 'Z')
            res += 1;
        else if(*str_p >= 'a' && *str_p <= 'z')
            res += 1;
        else if(*str_p >= '0' && *str_p <= '9')
            res += 1;
        else if(*str_p == ' ')
            res += 1;
        else {

            flag_cn_op += 0.5;

            if(flag_cn_op == 1.5){
                res += 2;
                flag_cn_op = 0;
            }


        }
        ++str_p;
    }
    return res;

}






static void ui_print_str(ui _self,char * s,int max_length) {

    log _log = get_log_instance();

    if(!s) {
        s = _self.null_str;
        strcpy(_log.log_information , "出现空指针,请正确使用系统\0");
        notify(ERROR,_log.log_information);
    }

    int str_len = str_length(s);

    if(!str_len) {
        s = _self.zero_str;
        str_len = str_length(s);
        strcpy( _log.log_information , "位置出现0串,请正确使用系统\0");
        notify(WARN,_log.log_information);
    }else if(str_len > max_length){
        s = _self.long_str;
        str_len = str_length(s);
        strcpy(_log.log_information , "位置出现长度过长的子串,请正确使用系统\0");
        notify(WARN,_log.log_information);
    }

    int flag_u_bnk_len_dcl = (max_length - str_len) % 2?1:0;
    int u_bnk_len = (max_length - str_len) / 2;

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


extern void ui_print_head(ui _self){
    int i = 40;
    while(i--){
        printf("-");
    }
    printf("\n");
    printf("|");
    ui_print_str(_self,"运 动 会 分 数 统 计 系 统\0",38);
    printf("|");
    printf("\n");
    i = 40;
    while(i--){
        printf("-");
    }
    printf("\n");
}





static void notify(int log_level,char * notice){

    log_update(log_level, notice);
}


