//
// Created by DELL on 2019/8/9.
//

#ifndef CO2_SQUARE_H
#define CO2_SQUARE_H

#include "../co2/include/all.h"
#include "Rectangle.h"

struct Square {
    union {
        struct SquareClass * class;
        struct Rectangle super;
    } head;
};

struct SquareClass {
    size_t size;
    size_t class_size;
    struct RectangleClass* super_class;
    method_declare(void,ctor)(struct Square* self, struct va_list_ex val);
    method_declare(void,dtor)(struct Square* self);
    method_declare(void,summary)(struct Square* self);
    method_declare(void,name)(struct Square* self, char *str);
    method_declare(float,area)(struct Square* self);
};

struct SquareClass * GetSquareClass();

#endif //CO2_SQUARE_H
