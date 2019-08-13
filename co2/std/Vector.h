//
// Created by DELL on 2019/8/13.
//

#ifndef CO2_VECTOR_H
#define CO2_VECTOR_H

#include "../include/core.h"

struct Vector {
    union {
        struct VectorClass* class;
        struct Object super;
    } head;
    void ** _array;
    size_t _capcity;
    size_t _size;
};

struct VectorClass {
    size_t size;
    size_t class_size;
    struct ObjectClass* super_class;
    method_declare(void, ctor)(struct Vector* self, struct va_list_ex val);
    method_declare(void, dtor)(struct Vector* self);
    method_declare(void, push_back)(struct Vector* self, void* element);
    method_declare(void*, pop_back)(struct Vector* self);
    method_declare(void*, at)(struct Vector* self, unsigned int idx);
    method_declare(size_t , len)(struct Vector* self);
};

struct VectorClass * GetVectorClass();


#endif //CO2_VECTOR_H
