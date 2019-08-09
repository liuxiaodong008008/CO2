//
// Created by liuxi on 2019/8/8.
//

#include "../include/allocate.h"
#include "../include/utils.h"
#include "../include/Object.h"
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>


void* _new(void* _class, ...) {
    void * m = malloc(*(size_t*)_class);
    assert(m);

    va_list val;
    va_start(val,_class);
    get_class(Object)->ctor(m, &val);
    va_end(val);

    return m;
}

void _delete(void* self) {
    ((struct Object*)self)->class->dtor(self);
    free(self);
}






