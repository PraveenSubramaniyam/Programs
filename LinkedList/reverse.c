#include "listAPIs.h"
#include <stdio.h>

list* reverse(list *head)
{
  list *new_head = NULL;
  list *temp;
  while (head != NULL)
  {
    temp = head->next;
    head->next = new_head;
    new_head = head;
    head = temp;
  }
  return new_head;
}

list* recursiveReverse(list *head)
{
	if (head->next == NULL)
		return head;
	list *new_head = recursiveReverse(head->next);
	head->next->next = head;
	return new_head;
}


void main()
{
  list *head = NULL;
  insert(&head,1);
  insert(&head,2);
  insert(&head,3);
  insert(&head,4);
  insert(&head,5);
  printf("Original List: ");
  print(head);
  head = reverse(head);
  printf("After Reverse: ");
  print(head);
  list *temp = head ;
  head = recursiveReverse(head);
  temp->next = NULL;
  printf("After Reverse: ");
  print(head);
}
