#include <stdio.h>

void main()
{
  int i = ~0u >> 1;
  //i = i>>>1;
  printf("MaxIntVal:%d\n",i);
}
