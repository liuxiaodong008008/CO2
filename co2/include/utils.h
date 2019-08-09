//
// Created by liuxi on 2019/8/8.
//

#ifndef CO2_UTILS_H
#define CO2_UTILS_H

#define get_class(Type) (Get##Type##Class())

#define method(Type,method_name) Type##method_name

#define method_declare(ret,method_name) \
    char * method_name##_name; \
    ret (* method_name)

#define method_initialize(Type,method_name) \
    #method_name, \
    method(Type,method_name)




#define str(x) (#x)



#endif //CO2_UTILS_H
