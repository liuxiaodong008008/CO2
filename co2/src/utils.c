//
// Created by DELL on 2019/8/9.
//

#include "../include/utils.h"
#include "../include/Object.h"
#include <string.h>

void add_unimplemented_function(
        void* src_class,
        void* dst_class) {

    struct ObjectClass* src = src_class;
    struct ObjectClass* dst = dst_class;

    struct NameFuncPair* src_list = (struct NameFuncPair*)(((char *)src) + sizeof(struct ObjectClass));
    int src_len = (src->class_size - sizeof(struct ObjectClass))/ sizeof(struct NameFuncPair);

    struct NameFuncPair* dst_list = (struct NameFuncPair*)(((char *)dst) + sizeof(struct ObjectClass));
    int dst_len = (dst->class_size - sizeof(struct ObjectClass))/ sizeof(struct NameFuncPair);

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

