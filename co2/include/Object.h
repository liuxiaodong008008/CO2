//
// Created by liuxi on 2019/8/8.
//

#ifndef CO2_OBJECT_H
#define CO2_OBJECT_H

#include "utils.h"
#include <vadefs.h>
#include <stddef.h>


struct Object {
    union {
        struct ObjectClass * class;
    } head;
};

struct ObjectClass {
    size_t size;
    size_t class_size;
    struct ObjectClass* super_class;
    method_declare(void,ctor)(struct Object* self, struct va_list_ex val);
    method_declare(void,dtor)(struct Object* self);
};

struct ObjectClass * GetObjectClass();



#endif //CO2_OBJECT_H
