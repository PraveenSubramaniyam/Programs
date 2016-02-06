#include <stdio.h>

int equalNum(int i,int j)
{
  return i ^ j;
}

void main()
{
  int i = 15;
  int j = 15;
  if(equalNum(i,j))
    printf("Not Equal\n");
  else
    printf("Equal\n");
}
