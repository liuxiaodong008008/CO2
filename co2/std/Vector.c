//
// Created by DELL on 2019/8/13.
//

#include "Vector.h"
#include <stdlib.h>
#include <assert.h>

void method(Vector,ctor)(struct Vector* self, struct va_list_ex val) {
    assign_class_if_null(Vector, self);
    invoke_super_ctor_if_exists(Vector,self,val);

    va_reset(&val);
    self->_capcity = 10;
    self->_array = calloc(self->_capcity, sizeof(void*));
    self->_size = 0;

}

void method(Vector,dtor)(struct Vector* self) {
    invoke_super_dtor_if_exists(Vector,self);
    free(self->_array);
    self->_capcity = 0;
    self->_size = 0;
}

void method(Vector, push_back)(struct Vector* self, void* element) {

    unsigned old_size = self->_size;
    unsigned new_size = self->_size+1;
    assert(new_size>old_size);

    if (new_size >= self->_capcity) {
        void * old = self->_array;
        unsigned new_cap = old_size*2+1;
        assert(new_cap>old_size);
        self->_array = calloc(new_cap, sizeof(void*));
        free(old);
        self->_capcity = new_cap;
    }

    self->_array[old_size] = element;
    self->_size = new_size;
}

void* method(Vector, pop_back)(struct Vector* self) {
    if(self->_size>0) {
        void * p = invoke(self,at,self->_size-1);
        self->_size -= 1;
        return p;
    }
}

void* method(Vector, at)(struct Vector* self, unsigned int idx) {
    assert(idx<self->_size);
    return self->_array[idx];
}

size_t method(Vector, len)(struct Vector* self) {
    return self->_size;
}

struct VectorClass * GetVectorClass() {
    static struct VectorClass class_obj = {
            sizeof(struct Vector),
            sizeof(struct VectorClass),
            0,
            method_init_with_func(Vector, ctor),
            method_init_with_func(Vector, dtor),
            method_init_with_func(Vector, push_back),
            method_init_with_func(Vector, pop_back),
            method_init_with_func(Vector, at),
            method_init_with_func(Vector, len)
    };
    static int i=1;
    if(i) {
        class_obj.super_class = GetObjectClass();
        add_unimplemented_function(class_obj.super_class, &class_obj);
        i=0;
    }
    return & class_obj;
}