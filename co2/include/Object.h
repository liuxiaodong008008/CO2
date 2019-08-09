//
// Created by liuxi on 2019/8/8.
//

#ifndef CO2_OBJECT_H
#define CO2_OBJECT_H

#include "utils.h"
#include <vadefs.h>
#include <stddef.h>


struct Object {
    struct ObjectClass * class;
};

struct ObjectClass {
    size_t size;
    size_t class_size;
    struct ObjectClass* super_class;
    method_declare(void,ctor)(struct Object* self, va_list* val);
    method_declare(void,dtor)(struct Object* self);
};

struct ObjectClass * GetObjectClass();



#endif //CO2_OBJECT_H
