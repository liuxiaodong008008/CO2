//
// Created by liuxi on 2019/8/8.
//

#include "Shape.h"
#include <stdarg.h>
#include <stdio.h>

void method(Shape,ctor)(struct Shape* self,va_list* val) {
    assgin_class(Shape,self);
    invoke_super_ctor_if_exists(Shape,self,val);
}

void method(Shape,dtor)(struct Shape* self) {
    invoke_super_dtor_if_exists(Shape,self);
}

void method(Shape,name)(struct Shape* self) {
    printf("Shape()\n");
}


struct ShapeClass * GetShapeClass() {
    static struct ShapeClass shape_class = {
            sizeof(struct Shape),
            sizeof(struct ShapeClass),
            0,
            method_init_with_func(Shape, ctor),
            method_init_with_func(Shape, dtor),
            method_init_with_func(Shape, name)
    };
    static int i=1;
    if(i) {
        shape_class.super_class = GetObjectClass();
        add_unimplemented_function(shape_class.super_class, &shape_class);
        i=0;
    }
    return & shape_class;
}