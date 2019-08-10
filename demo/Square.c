//
// Created by DELL on 2019/8/9.
//

#include "Square.h"
#include <stdarg.h>
#include <stdio.h>

void method(Square,ctor)(struct Square* self,struct va_list_ex val) {
    assign_class_if_null(Square, self);
    invoke_super_ctor_if_exists(Square, self, val);

    va_reset(&val);
    int a = va_arg_ex(val,int);
    self->head.super.width = a;
    self->head.super.height = a;
}

void method(Square,dtor)(struct Square* self) {
    invoke_super_dtor_if_exists(Square, self);
}

void method(Square,name)(struct Square* self, char *str) {
    sprintf(str,"Square(a=%d)",self->head.super.width);
}


struct SquareClass * GetSquareClass() {
    static struct SquareClass square_class = {
            sizeof(struct Square),
            sizeof(struct SquareClass),
            0,
            method_init_with_func(Square, ctor),
            method_init_with_func(Square, dtor),
            method_init_with_null(Square, summary),
            method_init_with_func(Square, name),
            method_init_with_null(Square, area),
    };
    static int i=1;
    if(i) {
        square_class.super_class = GetRectangleClass();
        add_unimplemented_function(square_class.super_class, &square_class);
        i=0;
    }
    return & square_class;
}