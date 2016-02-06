#include <stdio.h>

void endian()
{
  int i = 1;
  char *c = (char *)&i;
  if((*c) == 1)
    printf("Little Endian\n");
  else
    printf("Big Endian\n");
}

void main()
{
  endian();
}
