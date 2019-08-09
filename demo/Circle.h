//
// Created by DELL on 2019/8/9.
//

#ifndef CO2_CIRCLE_H
#define CO2_CIRCLE_H

#include "../co2/include/all.h"
#include "Shape.h"

struct Circle {
    struct CircleClass * class;
    struct Shape super;
    int radius;
};

struct CircleClass {
    size_t size;
    size_t class_size;
    struct ShapeClass* super_class;
    method_declare(void,ctor)(struct Circle* self, va_list* val);
    method_declare(void,dtor)(struct Circle* self);
    method_declare(void,name)(struct Circle* self);
};

struct CircleClass * GetCircleClass();
#endif //CO2_CIRCLE_H
