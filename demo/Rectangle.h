//
// Created by DELL on 2019/8/9.
//

#ifndef CO2_RECTANGLE_H
#define CO2_RECTANGLE_H

#include "../co2/include/all.h"
#include "Shape.h"

struct Rectangle {
    struct RectangleClass * class;
    struct Shape super;
    int width;
    int height;
};

struct RectangleClass {
    size_t size;
    size_t class_size;
    struct ShapeClass* super_class;
    method_declare(void,ctor)(struct Rectangle* self, va_list* val);
    method_declare(void,dtor)(struct Rectangle* self);
    method_declare(void,name)(struct Rectangle* self);
};

struct RectangleClass * GetRectangleClass();

#endif //CO2_RECTANGLE_H
