#include <stdio.h>



void strcmp(int i)
{
  if(i == 0)
    return;

  i--;
  strcmp(i);
}

void main()
{
  int i = 100;
  strcmp(i);
}
