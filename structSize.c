#include <stdio.h>

typedef struct 
{
  int intVal;
  char charVal;
}str;

void main()
{
  str *nodePtr,node;
  printf("sizeofNode:%d SizeofNodePtr:%d",sizeof(node),sizeof(*nodePtr));
}
