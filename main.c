#include <stdio.h>
#include <stdarg.h>
#include "co2/include/all.h"

int main() {
    printf("Hello, World!\n");

    struct Object *p = new(Object);
    delete(p);

    return 0;
}