#include <stdio.h>

int i;
void func() {
  static int i = 9;
  printf("%d ",i);
  i++;
}

void main()
{
  i++;
  func();
  i++;
  func();
}
