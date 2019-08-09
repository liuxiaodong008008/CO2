//
// Created by liuxi on 2019/8/8.
//

#include "../include/Object.h"

void method(Object,ctor) (struct Object* self, va_list* val) {
    assgin_class(Object,self);
}

void method(Object,dtor) (struct Object* self) {}

struct ObjectClass * GetObjectClass() {
    static struct ObjectClass object_class = {
            sizeof(struct Object),
            sizeof(struct ObjectClass),
            0,
            method_init_with_func(Object, ctor),
            method_init_with_func(Object, dtor)
    };
    return & object_class;
}
