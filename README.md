# CO2
CO2: C language Object Oriented system.

Support:  Encapsulation, Inheritance, Polymorphism.

Super light libary with only ~240 loc ( 170 lines of none blank codes).

Take care of that: compilers must support `__VA_OPT__`. Using the latest `GCC` is a good choice.

Demo:
```C
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
```

print as below:

```
Circle(r=8) - area: 201.1
Rectangle(w=10,h=5) - area: 50.0
Square(a=3) - area: 9.0
 ```
