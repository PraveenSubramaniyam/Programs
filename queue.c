#include <stdio.h>
#include <stdlib.h>

typedef struct myqueue queue;

struct myqueue{
  int value;
  queue *next;
};

queue *head = NULL;
queue *tail = NULL;

void push (int value)
{
  queue *temp;
  temp = malloc(sizeof(queue));
  temp->value = value;
  temp->next = NULL;

  if(head == NULL)
  {
    head = temp;
    tail = temp;
  }
  else
  {
    temp->next = head;
    head = temp;
  }
}

void pop()
{
  queue *tmp;
  if(head == NULL)
  {
    printf("Queue is Empty\n");
    return;
  }
  else if(head->next == NULL)
  {
    tmp = head;
    head = head->next;
    tail = head->next;
    printf("Popped element:%d",tmp->value);
    free(tmp);
  }
  else
  {
    tmp = head;
    while(tmp->next != tail)
    {
      tmp = tmp->next;
    }
    tail = tmp;
    printf("popped element:%d",tmp->next->value);
    tail->next = NULL;
    free(tmp->next);
  }
}

int isQueueEmpty()
{
  if(head == NULL)
    return 1;
  else
    return 0;
}

void printElements()
{
  queue *tmp;
  tmp = head;
  printf("Elements are.. ");
  while(tmp != NULL)
  {
    printf("%d ",tmp->value);
    tmp = tmp->next;
  }
  printf("\n");
}

void main()
{
  printf("Pushing 1\n");
  push(1);
  printElements();
  printf("Pushing 2\n");
  push(2);
  printElements();
  printf("Pushing 3\n");
  push(3);
  printf("Printing Elements\n");
  printElements();
  printf("Popping 1\n");
  pop();
  printf("Printing Elements\n");
  printElements();
  printf("Pushing 4\n");
  push(4);
  printf("Printing Elements\n");
  printElements();
}
