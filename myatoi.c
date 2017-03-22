#include <stdio.h>


void main()
{
  char *str = "1998";
  int i = 0;
  while(*str)
  {
     i = (i << 3) + (i << 1) + ((*str) - '0');
     str++;
  }
  printf("num: %d\n",i);
}
