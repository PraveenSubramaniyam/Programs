#include <stdio.h>

typedef struct {
  char age;
  int name;
}emp;

/*
short - 2
char - 1
int - 4
float - 4
*/

typedef struct{
  float i;
  char j;
  short k;
  int l;
};


void main()
{
  emp *head = malloc(sizeof(emp)*3);
  head[0].age = 0;
  head[0].name = 0;
  head[1].age = 1;
  head[1].name = 1;
  head[2].age = 2;
  head[2].name = 2;

  printf("Sizeof emp:%d\n",sizeof(emp));
  printf("1 age :%d\n",head[1].age);
  printf("0 age :%d\n",(head+1)->age);
}
