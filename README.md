# CO2
CO2: C language Object Oriented system.

Support:  Encapsulation, Inheritance, Polymorphism.

Super light library with only ~240 loc ( 170 lines of none blank codes).

Demo:
```C
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
```

print as below:

```
Circle(r=8) - area: 201.1
Rectangle(w=10,h=5) - area: 50.0
Square(a=3) - area: 9.0
 ```
