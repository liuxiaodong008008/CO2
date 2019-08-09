//
// Created by liuxi on 2019/8/8.
//

#ifndef CO2_ALLOCATE_H
#define CO2_ALLOCATE_H

void* _new(void* _class, ...);
#define new(Type,...) ((struct Type*)_new(get_class(Type),__VA_ARGS__))

void _delete(void* self);
#define delete(self) _delete(self)

#endif //CO2_ALLOCATE_H
