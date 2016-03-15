#include <stdio.h>

typedef struct 
{
  int intVal;
  char* charVal;
}str;

void main()
{
  str *nodePtr,node;
  printf("sizeofNode:%d SizeofNodePtr:%d:%d\n",sizeof(node),sizeof(*nodePtr),sizeof(int*));
}
