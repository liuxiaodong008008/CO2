//
// Created by DELL on 2019/8/9.
//

#include "Rectangle.h"
#include <stdarg.h>
#include <stdio.h>

void method(Rectangle,ctor)(struct Rectangle* self,va_list* val) {
    assign_class(Rectangle, self);
    invoke_super_ctor_if_exists(Rectangle, self, val);

    self->width = va_arg(*val,int);
    self->height = va_arg(*val,int);
}

void method(Rectangle,dtor)(struct Rectangle* self) {
    invoke_super_dtor_if_exists(Rectangle, self);
}

void method(Rectangle,name)(struct Rectangle* self) {
    printf("Rectangle(w=%d,h=%d)\n",self->width,self->height);
}

float method(Rectangle,area)(struct Rectangle* self) {
    return self->width * self->height;
}

struct RectangleClass * GetRectangleClass() {
    static struct RectangleClass rectangle_class = {
            sizeof(struct Rectangle),
            sizeof(struct RectangleClass),
            0,
            method_init_with_func(Rectangle, ctor),
            method_init_with_func(Rectangle, dtor),
            method_init_with_func(Rectangle, name),
            method_init_with_func(Rectangle, area)
    };
    static int i=1;
    if(i) {
        rectangle_class.super_class = GetShapeClass();
        add_unimplemented_function(rectangle_class.super_class, &rectangle_class);
        i=0;
    }
    return & rectangle_class;
}