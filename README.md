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

    struct Shape *sps[4] = {
            new(Shape),
            new(Circle,8),
            new(Rectangle,10,5),
            new(Square,3),
    };

    for (int i = 0; i < 4; ++i) {
        invoke(sps[i],name);
    }

    delete(sps[0]);
    delete(sps[1]);
    delete(sps[2]);
    delete(sps[3]);

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
