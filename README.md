# CO2
CO2: C language Object Oriented system.

Support:  Encapsulation, Inheritance, Polymorphism.

Demo:
```C
#include <stdio.h>
#include <stdarg.h>
#include "co2/include/all.h"
#include "demo/Shape.h"
#include "demo/Rectangle.h"
#include "demo/Square.h"
#include "demo/Circle.h"

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
Shape()
Circle(r=8)
Rectangle(w=10,h=5)
Square(a=1)
 ```
