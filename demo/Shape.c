//
// Created by liuxi on 2019/8/8.
//

#include "Shape.h"
#include <stdarg.h>


void method(Shape,ctor)(struct Shape* self,va_list* val) {
    self->super.class->ctor(&self->super,val);
}

void method(Shape,dtor)(struct Shape* self) {
    self->super.class->dtor(&self->super);
}


struct ShapeClass * GetShapeClass() {
    static struct ShapeClass shape_class = {
            sizeof(struct Shape),
            0,
            method_initialize(Shape,ctor),
            method_initialize(Shape,dtor)
    };
    static int i=1;
    if(i) {
        shape_class.super_class = GetObjectClass();
        i=0;
    }
    return & shape_class;
}