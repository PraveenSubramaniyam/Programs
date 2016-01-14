#include <stdio.h>

void main()
{
  int var = 3;
  int intVar = 4;
  const int *ptr = &var;
  *ptr = intVar;
}
 
