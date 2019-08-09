//
// Created by liuxi on 2019/8/8.
//

#include "../include/Object.h"

void method(Object,ctor) (struct Object* self, va_list* val) {
    self->class = get_class(Object);
}

void method(Object,dtor) (struct Object* self) {}

struct ObjectClass * GetObjectClass() {
    static struct ObjectClass object_class = {
            sizeof(struct Object),
            0,
            method_initialize(Object,ctor),
            method_initialize(Object,dtor)
    };
    return & object_class;
}
