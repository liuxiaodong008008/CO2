#include <stdio.h>
#include "co2/include/all.h"
#include "demo/demo.h"

int main() {

    struct Circle* p1 = new(Circle,8);
    struct Rectangle* p2 = new(Rectangle,10,5);
    struct Square* p3 = new(Square,3);

    struct Shape *sps[3] = {p1,p2,p3};

    for (int i = 0; i < 3; ++i) {
        invoke(sps[i],summary);
    }

    delete(sps[0]);
    delete(sps[1]);
    delete(sps[2]);

    return 0;
}