#include <stdio.h>
#include <stdlib.h>

typedef struct ListStr list;

struct ListStr
{
  int value;
  list *next;
};

void insert(list **head, int value)
{
  list *tmp = malloc(sizeof(list));
  tmp -> value = value;
  tmp->next = NULL;
  if((*head) == NULL)
    *head = tmp;
  else
  {
    tmp ->next = *head;
    *head = tmp;
  }
}

void printElements(list *head)
{
  list *tmp;
  if(!head)
    printf("List Empty\n");
  else
  {
    tmp = head;
    printf("Elements: ");
    while(tmp)
    {
      printf("%d ",tmp->value);
      tmp = tmp->next;
    }
    printf("\n");
  }
}

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
  printElements(head);
  insert(&head,1);
  insert(&head,2);
  insert(&head,3);
  insert(&head,4);
  insert(&head,5);
  insert(&head,6);
  printElements(head);
  deleteKNodeFromLast(&head,7);
  printElements(head);
}
