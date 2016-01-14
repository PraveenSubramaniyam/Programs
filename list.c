#include <stdio.h>

typedef struct listStruct list;

struct listStruct {
  int value;
  list *next;
};

list *head = NULL;

void insert(int value)
{
  list *tmp;
  tmp = malloc(sizeof(list));
  tmp->value = value;
  tmp->next = NULL;

  if(head == NULL)
    head = tmp;
  else
  {
    tmp->next = head;
    head = tmp;
  }
}

void delete(int value)
{
  list *prev = NULL, *tmp;

  if(head == NULL)
  {
    printf("List empty");
  }
  else
  {
    tmp = head;
    while(tmp != NULL)
    {
      if(tmp->value == value)
        break;
      prev = tmp;
      tmp = tmp->next;
    }

    if(tmp == NULL)
      printf("Element %d Not found in the list",value);
    else
    {
      if(prev == NULL)
        head = head->next;
      else
        prev->next = tmp->next;

      printf("Deleting Node: %d\n",tmp->value);
      free(tmp);
    }
  }
}

void search(int value)
{
  list *tmp;
  tmp = head;
  while(tmp != NULL)
  {
    if(tmp->value == value)
      break;
  }
  if(tmp == NULL)
    printf("Element not found\n");
}

void reverse()
{
  if(head == NULL)
    printf("List is Empty");
}

void recurRev(list *node)
{
  if(node == NULL)
    return ;

  recurRev(node->next);
  node->next->next = node;
}

void main()
{

}
