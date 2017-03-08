#include <stdio.h>
#include <stdlib.h>

typedef struct RandomListNode deepList;

  struct RandomListNode {
      int label;
      struct RandomListNode *next;
      struct RandomListNode *random;
  };

struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    if(head == NULL)
        return NULL;

    struct RandomListNode *list1 = head, *list2, *temp;
    while(list1 != NULL)
    {
        list2 = malloc(sizeof(struct RandomListNode));
        list2->label = list1->label;
        temp = list1->next;
        list1->next = list2;
        list2->next = temp;
        list1 = temp;
    }

    list1 = head;
    while(list1 != NULL)
    {
        if(list1->random)
            list1->next->random = list1->random->next;
        else
        	list1->next->random = NULL;

        list1 = list1->next->next;
    }

    temp = head;
      list2 = head->next;
      while(temp)
      {
      	list1 = temp->next->next;

          if(temp->next->next != NULL)
              temp->next->next = temp->next->next->next;
          else
              temp->next->next = NULL;

          temp->next = list1;
          temp = list1;
      }
      return list2;

}

deepList *  insert(deepList **head, int value, deepList *random)
{
	deepList *temp = malloc(sizeof(deepList));
	temp ->label = value;
	temp ->random = random;
	temp->next = NULL;
	if((*head) == NULL)
	{
		(*head) = temp;
	}
	else
	{
		temp ->next = (*head);
		*head = temp;
	}
	return temp;
}

void printList(deepList *head)
{
	while(head)
	{
		if(head->random)
			printf("Val: %d Random: %d\n",head->label, head->random->label);
		else
			printf("Val: %d Random: NONE\n",head->label);
		head = head->next;
	}
}

void main()
{
   deepList *head = NULL;
   deepList *one = insert(&head, 1, NULL);
   deepList *two = insert(&head, 2, NULL);
   deepList *three = insert(&head, 3, NULL);
   one = insert(&head, 4, one);
   two = insert(&head, 5, two);
   three = insert(&head, 6, three);
   printList(head);
   printf("\n\n");
   deepList *sHead = copyRandomList(head);
   printList(sHead);
   printf("\n\n");
   printList(head);
}
