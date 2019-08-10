//
// Created by liuxi on 2019/8/8.
//

#ifndef CO2_ALLOCATE_H
#define CO2_ALLOCATE_H

#include "Object.h"

void* _new(void* _class, ...);

#define new(Type, ...) ((struct Type*)_new(class_of(Type) __VA_OPT__(,) __VA_ARGS__))

void _delete(void* self);
#define delete(self) _delete(self)

#endif //CO2_ALLOCATE_H
