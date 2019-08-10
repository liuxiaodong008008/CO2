//
// Created by DELL on 2019/8/9.
//

#include "../include/utils.h"
#include "../include/Object.h"
#include <string.h>



struct va_list_ex make_va_list_ex(va_list* val) {
    struct va_list_ex v = {
            val,
            *val
    };
    return v;
}

void va_reset(struct va_list_ex* val) {
    *(val->valist) = val->origin;
}



void add_unimplemented_function(
        void* src_class,
        void* dst_class) {

    struct ObjectClass* src = src_class;
    struct ObjectClass* dst = dst_class;

    struct name_func_pair* src_list = (struct name_func_pair*)(((char *)src) + sizeof(struct ObjectClass));
    int src_len = (src->class_size - sizeof(struct ObjectClass))/ sizeof(struct name_func_pair);

    struct name_func_pair* dst_list = (struct name_func_pair*)(((char *)dst) + sizeof(struct ObjectClass));
    int dst_len = (dst->class_size - sizeof(struct ObjectClass))/ sizeof(struct name_func_pair);

    int i=0, j=0;
    for(i = 0; i < dst_len; ++i) {
        if (dst_list[i].func) continue;
        for (j = 0; j < src_len; ++j) {
            if(strcmp(dst_list[i].name, src_list[j].name)==0) {
                dst_list[i].func = src_list[j].func;
            }
        }
    }
}

