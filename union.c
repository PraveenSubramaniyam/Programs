#include <stdio.h>

union student
{
  int name;
  char age[10];
  
};


typedef struct 
{
  char name;
  char addr;
  int age;
}employee;

void main()
{
  union student praveen;
  employee hrt;
  printf("sizeof:%d\nsizeof emp:%d\n",sizeof(praveen),sizeof(hrt));
  
}
