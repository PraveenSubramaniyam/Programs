#include "listAPIs.h"
#include <stdio.h>
#include <stdlib.h>

void deleteNode(list *node)
{
   node->value = node->next->value;
   node->next = node->next->next;
   free(node->next);
}

int deleteMiddleNode(list *head)
{
	list *fast = head;
    list *slow = head;

    if (head == NULL)
    {
    	printf("Empty List\n");
    	return -1;
    }

    if(head->next == NULL || head->next->next == NULL)
    {
    	printf("Either Single Node or Two Node list can't delete\n");
    	return -1;
    }

	while (fast && fast->next)
	{
       slow = slow->next;
       fast = fast->next->next;
	}

	deleteNode(slow);
	return 0;
}

void main()
{
   list *head = NULL;
   deleteMiddleNode(head);
   print(head);

   insert(&head,1);
   deleteMiddleNode(head);
   print(head);

   insert(&head,2);
   deleteMiddleNode(head);
   print(head);

   insert(&head,3);
   deleteMiddleNode(head);
   print(head);

   insert(&head,4);
   deleteMiddleNode(head);
   print(head);
}
