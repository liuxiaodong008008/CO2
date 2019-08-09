//
// Created by liuxi on 2019/8/8.
//

#ifndef CO2_SHAPE_H
#define CO2_SHAPE_H

#include "../co2/include/all.h"

struct Shape {
    union {
        struct ShapeClass* class;
        struct Object super;
    } head;
};

struct ShapeClass {
    size_t size;
    size_t class_size;
    struct ObjectClass* super_class;
    method_declare(void,ctor)(struct Shape* self, va_list* val);
    method_declare(void,dtor)(struct Shape* self);
    method_declare(void,name)(struct Shape* self);
    method_declare(float,area)(struct Shape* self);
};

struct ShapeClass * GetShapeClass();


#endif //CO2_SHAPE_H
