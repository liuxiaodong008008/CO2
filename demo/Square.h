//
// Created by DELL on 2019/8/9.
//

#ifndef CO2_SQUARE_H
#define CO2_SQUARE_H

#include "../co2/include/all.h"
#include "Rectangle.h"

struct Square {
    struct SquareClass * class;
    struct Rectangle super;
};

struct SquareClass {
    size_t size;
    size_t class_size;
    struct RectangleClass* super_class;
    method_declare(void,ctor)(struct Square* self, va_list* val);
    method_declare(void,dtor)(struct Square* self);
    method_declare(void,name)(struct Square* self);
};

struct SquareClass * GetSquareClass();

#endif //CO2_SQUARE_H
