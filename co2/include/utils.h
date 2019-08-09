//
// Created by liuxi on 2019/8/8.
//

#ifndef CO2_UTILS_H
#define CO2_UTILS_H

//#ifdef _MSC_VER
//#define __VA_OPT__(x) x
//#endif


#define class_of(Type) (Get##Type##Class())

#define method(Type,method_name) Type##method_name

#define method_declare(ret,method_name) \
    char * method_name##_name; \
    ret (* method_name)

#define method_init_with_func(Type,method_name) \
    #method_name, \
    method(Type,method_name)

#define method_init_with_null(Type,method_name) \
    #method_name, \
    0


#define str(x) (#x)

#define get_ctor(_class) ((struct ObjectClass*)_class)->ctor
#define get_dtor(_class) ((struct ObjectClass*)_class)->dtor

#define object_class(self) self->head.class
#define object_super(self) object_class(self)->super_class

#define assign_class(Type,self) \
    object_class(self) = class_of(Type)

#define invoke_super_ctor_if_exists(Type,self,val) \
    if(object_super(self) && object_super(self)->ctor) { \
        object_super(self)->ctor(self,val); \
    }

#define invoke_super_dtor_if_exists(Type,self) \
    if(object_super(self) && object_super(self)->dtor) { \
        object_super(self)->dtor(self); \
    }


#define invoke(self,func,...) (object_class(self)->func(self ,__VA_ARGS__))

struct NameFuncPair {
    char * name;
    void * func;
};


void add_unimplemented_function(void* src_class, void* dst_class);

#endif //CO2_UTILS_H
