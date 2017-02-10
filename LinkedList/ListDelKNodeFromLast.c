#include <stdio.h>
#include <stdlib.h>
#include "listAPIs.h"


void deleteKNodeFromLast(list **head, int k)
{
  list *tmp = *head,*prev= NULL;
  list *temp = *head;
  if(k == 0)
    return;
  while(tmp && k > 0)
  {
    k--;
    tmp = tmp->next;
  }
  if(!tmp && k > 0)
  {
    printf("K is greater than Length of list\n");
  }
  else
  {
    while(tmp)
    {
      tmp = tmp->next;
      prev = temp;
      temp = temp->next;
    }
    if(prev == NULL)
    {
      tmp = *head;
      *head = (*head) ->next;
      free(tmp);
    }
    else
    {
      prev->next = temp->next;
      free(temp);
    }
  }
}


void main()
{
  list *head = NULL;
  insert(&head,1);
  deleteKNodeFromLast(&head,1);
  print(head);
  insert(&head,2);
  insert(&head,3);
  insert(&head,4);
  insert(&head,5);
  insert(&head,6);
  print(head);
  deleteKNodeFromLast(&head,3);
  print(head);
}
