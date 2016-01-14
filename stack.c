#include <stdio.h>
#include <stdlib.h>


typedef struct stackStr stack;

struct stackStr{
  /*value will contain value*/
  int value;
  /* next will contain the address of the next element in the stack
   * last elemnt will contain NULL .
   * NULL is very important here since only with NULL we will find the end of the stack*/
  stack *next;
};


/* intially stack will be empty
 * Im using a global variable here since i need to use this variable in all functions like
 * push, pop, printElements*/
stack *head = NULL;




void push(int value)
{
  /*Intially stack will be empty
   * so head == NULL. so just allocate mem for struct copy values
   * make it as head
   * head-> next will be NULL stating this as last element*/
  stack *tmp;
  tmp = malloc(sizeof(stack));
  if(tmp == NULL)
  {
    printf("cannot allocate memory");
    return;
  }
  else
  {
    tmp->value = value;
    tmp->next = head;
    head = tmp;
  }
}

void pop()
{
  stack *tmp;
  /* head is NULL */
  if(head == NULL)
  {
    printf("Empty Stack");

  }
  else
  {
    /* head is not NULL;
     * copy the head to tmp variable
     * move the head to head->next.
     * free the tmp variable.(tmp will contain the address to be freed)
     */
    tmp = head;
    head = head->next;
    printf("Popped Element:%d\n",tmp->value);
    free(tmp);
  }
}

void printElements()
{
  stack *tmp = head;
  printf("Elements in Stack: ");
  /*Loop until NULL and print the values*/
  while(tmp != NULL)
  {
    printf("%d ",tmp->value);
    tmp = tmp->next;
  }
  printf("\n");
}

void main()
{
  printf("Pushing Element 1\n");
  /* 1->NULL */
  push(1);
  printf("Pushing Element 2\n");
  /* 2->1->NULL */
  push(2);
  printf("Printing Elements\n");
  /* 2->1->NULL */
  printElements();
  printf("Pushing Element 3\n");
  /* 3->2->1->NULL */
  push(3);
  printf("Printing Elements\n");
  /* 3->2->1->NULL */
  printElements();
  printf("Popping Element\n");
  /* 2->1->NULL */
  pop();
  printf("Printing Elements\n");
  /* 2->1->NULL */
  printElements();
}
