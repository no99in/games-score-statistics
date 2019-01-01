//
// Created by mossnodie on 12/23/18.
//

#include "_ui.h"

/* static */

_ui * ui_instance = NULL;

// singleton pattern model
extern _ui _get_ui_instance(){

    if(!ui_instance)
        _new_ui(ui_instance);

    return *ui_instance;

}

// _ui construct
void _new_ui(_ui *self) {

    // malloc
    _ui * _self = (_pui)malloc(sizeof(_ui));
    _log _log = _get_log_instance();
    if(!_self) {

        strcpy(_log.log_information ,"UI界面初始化失败,错误代码(500)!\0");
        _log.log_type = _LOG_ERROR;

        _ui_notify(_log.log_type, _log.log_information);

        exit(500);
    }

    // init
    _self->long_str = _UI_LONG_STR;
    _self->null_str = _UI_NULL_STR;
    _self->zero_str = _UI_ZERO_STR;
    _self->point    = _UI_POINT;
    _self->line     = _UI_LINE;
    _self->div      = _UI_DIV;
    _self->ln       = _UI_LN;

    *self = *_self;
    ui_instance = _self;

    strcpy( _log.log_information  , "UI界面初始化完成!\0");
    _log.log_type = _LOG_INFO;

    _ui_notify(_log.log_type, _log.log_information);

}



// reload the function strlen() in that chinese character take up three lengths
// in fact the character width only take up two units;
int _ui_str_length(char *s){

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

// print ==> |    |str|    |<-max_length
void _ui_print_str(_ui _self, char *s, int max_length) {

    _log _log = _get_log_instance();

    if(!s) {
        s = _self.null_str;
        strcpy(_log.log_information , "出现空指针,请正确使用系统\0");
        _log.log_type=_LOG_ERROR;
        _ui_notify(_LOG_ERROR, _log.log_information);
    }

    int str_len = _ui_str_length(s);

    if(!str_len) {
        s = _self.zero_str;
        str_len = _ui_str_length(s);
        strcpy( _log.log_information , "位置出现0串,请正确使用系统\0");
        _log.log_type=_LOG_WARN;
        _ui_notify(_LOG_WARN, _log.log_information);
    }else if(str_len > max_length){
        s = _self.long_str;
        str_len = _ui_str_length(s);
        strcpy(_log.log_information , "位置出现长度过长的子串,请正确使用系统\0");
        _log.log_type=_LOG_WARN;
        _ui_notify(_LOG_WARN, _log.log_information);
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

// print +,~,*,^ ...
void _ui_print_point(_ui _self) {

    printf("%c",_self.point);

}

// print - ...
void _ui_print_line(_ui _self, int length) {

    while(length--)
        printf("%c",_self.line);

}

// print | ...
void _ui_print_div(_ui _self) {

    printf("%c",_self.div);

}

static void  _ui_print_ln(_ui _self){

    printf("%s",_self.ln);

}

/* !static */

/* extern */

void _ui_print_head(_ui _self, int length){
    _ui_print_point(_self);
    _ui_print_line(_self, length - 2);
    _ui_print_point(_self);
    _ui_print_ln(_self);
    _ui_print_div(_self);
    _ui_print_str(_self, TITLE, 38);
    _ui_print_div(_self);
    _ui_print_ln(_self);
    _ui_print_point(_self);
    _ui_print_line(_self, length - 2);
    _ui_print_point(_self);
    _ui_print_ln(_self);
}

void _ui_print_fun(_ui _self, int length){

    _ui_print_div(_self);
    _ui_print_str(_self, TITLE, length - 2);
    _ui_print_div(_self);
    _ui_print_ln(_self);
    _ui_print_point(_self);
    _ui_print_line(_self, length - 2);
    _ui_print_point(_self);
    _ui_print_ln(_self);

}

void _ui_print_custom(_ui _self, char *custom_str, int length){

    _ui_print_div(_self);
    _ui_print_str(_self, custom_str, length - 2);
    _ui_print_div(_self);
    _ui_print_ln(_self);
    _ui_print_point(_self);
    _ui_print_line(_self, length - 2);
    _ui_print_point(_self);
    _ui_print_ln(_self);

}

/* !extern */

/* interface */

void _ui_notify(int log_level, char *notice){

    _log_update(log_level, notice);

}

/* !interface */