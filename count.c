#include <stdio.h>

int cnt = 0;
int count(int total,int x, int y)
{
  if (x == total || y == total)
    return 1;
  
  cnt++;
  return count(total,x+1,y) + count(total,x,y+1);
}
void main()
{
  
  cnt = count(20,0,0);
  printf("Count:%d",cnt);
}
