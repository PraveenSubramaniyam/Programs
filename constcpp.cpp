#include <stdio.h>


struct Silly {
    int x;
    mutable int y;
    void do_stuff() const { x = 0; } // illegal - labelled const
    void do_other_stuff() const { y = 0; } // fine - y is mutable
};

int main()
{
    int var = 3;
    int intVar = 4;
    int * const ptr = &var;
    *ptr = intVar;
    return 0;
}
 
