#include <stdio.h>

int power(int i)
{
  i = i & (i-1);

  return i==0;
}

void main()
{
  int i = 15;
  printf("Powerof2:%d\n",power(i));
}
