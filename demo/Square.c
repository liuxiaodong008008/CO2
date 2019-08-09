//
// Created by DELL on 2019/8/9.
//

#include "Square.h"
#include <stdarg.h>
#include <stdio.h>

void method(Square,ctor)(struct Square* self,va_list* val) {
    assgin_class(Square, self);
    invoke_super_ctor_if_exists(Square, self, val);

    int a = va_arg(*val,int);
    self->super.width = a;
    self->super.height = a;
}

void method(Square,dtor)(struct Square* self) {
    invoke_super_dtor_if_exists(Square, self);
}

void method(Square,name)(struct Square* self) {
    printf("Square(a=%d)\n",self->super.width);
}


struct SquareClass * GetSquareClass() {
    static struct SquareClass square_class = {
            sizeof(struct Square),
            sizeof(struct SquareClass),
            0,
            method_init_with_func(Square, ctor),
            method_init_with_func(Square, dtor),
            method_init_with_func(Square, name),
//            method_init_with_null(Square, name),
    };
    static int i=1;
    if(i) {
        square_class.super_class = GetRectangleClass();
        add_unimplemented_function(square_class.super_class, &square_class);
        i=0;
    }
    return & square_class;
}