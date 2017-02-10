#include <stdlib.h>
#include "listAPIs.h"
#include <stdio.h>

void insert(list **head, int value)
{
  list *tmp;
  tmp = malloc(sizeof(list));
  tmp->value = value;
  tmp->next = NULL;

  if((*head) == NULL)
    (*head) = tmp;
  else
  {
    tmp->next = *head;
    *head = tmp;
  }
}


int delete(list **head, int value)
{
  list *prev = NULL, *tmp;

  if((*head) == NULL)
  {
    printf("List empty");
    return -1;
  }
  else
  {
    tmp = *head;
    while(tmp != NULL)
    {
      if(tmp->value == value)
        break;
      prev = tmp;
      tmp = tmp->next;
    }

    if(tmp == NULL)
    {
      printf("Element %d Not found in the list",value);
      return -1;
    }
    else
    {
      if(prev == NULL)
        (*head) = (*head)->next;
      else
        prev->next = tmp->next;

      printf("Deleting Node: %d\n",tmp->value);
      free(tmp);
    }
  }
  return 0;
}

void search(list *head, int value)
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


void print (list *head)
{
  list *tmp = head;

  if (!tmp)
	  printf("Empty List");


  while(tmp != NULL)
  {
	  printf("%d ",tmp->value);
	  tmp=tmp->next;
  }
  printf("\n");
}
