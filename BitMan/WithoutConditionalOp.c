#include <stdio.h>

void main()
{
  int a = 0;
  int b = 5,c=6, result;
  a && (result = b, 1) || (result = c, 0);
  printf("Result:%d\n",result);
}
