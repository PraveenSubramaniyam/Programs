#include <stdio.h>

int countBits(int i)
{
  int count=0;
  while(i)
  {
    i = i & (i-1);
    count++;
  }
  return count;
}

void main()
{
  int i = 15;
  printf("Bits:%d\n",countBits(i));
}
