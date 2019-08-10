//
// Created by DELL on 2019/8/9.
//

#include "Circle.h"
#include <stdarg.h>
#include <stdio.h>

void method(Circle,ctor)(struct Circle* self, struct va_list_ex val) {
    assign_class_if_null(Circle, self);
    invoke_super_ctor_if_exists(Circle, self, val);

    va_reset(&val);
    self->radius = va_arg_ex(val,int);
}

void method(Circle,dtor)(struct Circle* self) {
    invoke_super_dtor_if_exists(Circle, self);
}

void method(Circle,name)(struct Circle* self, char *str) {
    sprintf(str,"Circle(r=%d)",self->radius);
}

float method(Circle,area)(struct Circle* self) {
    return 3.1415926f * self->radius * self->radius;
}


struct CircleClass * GetCircleClass() {
    static struct CircleClass circle_class = {
            sizeof(struct Circle),
            sizeof(struct CircleClass),
            0,
            method_init_with_func(Circle, ctor),
            method_init_with_func(Circle, dtor),
            method_init_with_null(Circle, summary),
            method_init_with_func(Circle, name),
            method_init_with_func(Circle, area),
    };
    static int i=1;
    if(i) {
        circle_class.super_class = GetShapeClass();
        add_unimplemented_function(circle_class.super_class, &circle_class);
        i=0;
    }
    return & circle_class;
}