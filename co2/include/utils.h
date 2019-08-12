//
// Created by liuxi on 2019/8/8.
//

#ifndef CO2_UTILS_H
#define CO2_UTILS_H

#include <stdarg.h>


#define class_of(Type) (Get##Type##Class())

#define method(Type,method_name) Type##_##method_name

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
#define class_super(Type) class_of(Type)->super_class

#define assign_class_if_null(Type,self) \
    if(object_class(self)==0) \
        object_class(self) = class_of(Type)

#define invoke_super_ctor_if_exists(Type,self,val) \
    if(class_super(Type) && class_super(Type)->ctor) { \
        class_super(Type)->ctor(self,val); \
    }

#define invoke_super_dtor_if_exists(Type,self) \
    if(class_super(Type) && class_super(Type)->dtor) { \
        class_super(Type)->dtor(self); \
    }


#define PP_THIRD_ARG(a,b,c,...) c
#define VA_OPT_SUPPORTED_I(...) PP_THIRD_ARG(__VA_OPT__(,),1,0,)
#define VA_OPT_SUPPORTED VA_OPT_SUPPORTED_I(?)


#if VA_OPT_SUPPORTED
#define invoke(self,func,...) (object_class(self)->func(self __VA_OPT__(,) __VA_ARGS__))
#elif defined(_MSC_VER)
#define invoke(self,func,...) (object_class(self)->func(self, __VA_ARGS__))
#else
#define invoke(self,func,...) (object_class(self)->func(self,##__VA_ARGS__))
#endif

struct va_list_ex {
    va_list *valist;
    const void* origin;
};

struct name_func_pair {
    char * name;
    void * func;
};

struct va_list_ex make_va_list_ex(va_list* val);

void va_reset(struct va_list_ex* val);

#define va_arg_ex(va,Type) va_arg(*((va).valist),Type)

void add_unimplemented_function(void* src_class, void* dst_class);

#endif //CO2_UTILS_H
