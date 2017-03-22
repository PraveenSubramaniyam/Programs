#include <stdio.h>


void main()
{
  int i = 5;
  int j = i++ + ++i;
  printf("%d:j:%d\n",i++ + i++,j);
}
