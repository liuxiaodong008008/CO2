//
// Created by DELL on 2019/8/9.
//

#include "Circle.h"
#include <stdarg.h>
#include <stdio.h>

void method(Circle,ctor)(struct Circle* self,va_list* val) {
    assign_class(Circle, self);
    invoke_super_ctor_if_exists(Circle, self, val);

    self->radius = va_arg(*val,int);
}

void method(Circle,dtor)(struct Circle* self) {
    invoke_super_dtor_if_exists(Circle, self);
}

void method(Circle,name)(struct Circle* self) {
    printf("Circle(r=%d)\n",self->radius);
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