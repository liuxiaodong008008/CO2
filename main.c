#include <stdio.h>
#include "co2/include/all.h"
#include "demo/demo.h"
#include "co2/std/Vector.h"

int main() {

    struct Circle* p1 = new(Circle,8);
    struct Rectangle* p2 = new(Rectangle,10,5);
    struct Square* p3 = new(Square,3);

    struct Vector* vec = new(Vector);
    $(vec,push_back,p1);
    $(vec,push_back,p2);
    $(vec,push_back,p3);

    for (int i = 0; i < $(vec,len); ++i)
        $(((struct Circle*) $(vec,at,i)),summary);

    delete($(vec,at,0));
    delete($(vec,at,1));
    delete($(vec,at,2));
    delete(vec);
    return 0;
}