#include <stdio.h>


void main()
{
  int num = 9750;
  int rev = 0;
  int count = 0;
  int org = num;
  while(num >0)
  {
    rev = rev * 10  + num%10;
    num = num/10;    
  }
  printf("org: %d, reverse: %d\n",org,rev);
}
