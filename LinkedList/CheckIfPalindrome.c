#include "listAPIs.h"
#include <stdio.h>


int isPalindromehelper(list **head, list *last)
{
  if(last == NULL)
	  return 0;

  int ret = isPalindromehelper(head,last->next);
  if(ret == -1 )
	  return -1;

  if ((*head) ->value != last->value)
	  return -1;
  else
	  (*head) = (*head)->next;
  return ret;
}

int isPalindrome(list **head)
{
	list *temp = *head;
	int ret = isPalindromehelper(head,*head);
	*head = temp;
	return ret;
}

void main()
{
	list *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,35);
	insert(&head,4);
	insert(&head,3);
	insert(&head,2);
	insert(&head,1);
	print(head);
	int ret = isPalindrome(&head);
	if(ret == 0)
		printf("IsPalindrome\n");
	else
		printf("NotPalindrome\n");
	print(head);

}
