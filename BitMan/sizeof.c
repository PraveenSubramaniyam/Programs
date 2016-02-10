#include <stdio.h>

#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

#define SIZEOF(type) (type *)0+1

int main()
{
    double x;
    printf("%d\n", my_sizeof(x));
    printf("sizeofInt:%d\n", SIZEOF(int));
    return 0;
}
