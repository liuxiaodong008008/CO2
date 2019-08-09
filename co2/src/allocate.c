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
    void * m = malloc(((struct ObjectClass*)_class)->size);
    assert(m);

    va_list val;

    if(((struct ObjectClass*)_class)->ctor) {
        va_start(val,_class);
        ((struct ObjectClass*)_class)->ctor(m, &val);
        va_end(val);
    }

    return m;
}

void _delete(void* self) {
    if(((struct Object*)self)->class->dtor) {
        ((struct Object*)self)->class->dtor(self);
    }
    free(self);
}


