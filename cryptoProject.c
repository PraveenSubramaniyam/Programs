#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct keyVal key;

struct keyVal {
  int a;
  int b;
  int x;
  unsigned int preA;
  unsigned int preB;
  unsigned int preX;
  int position;
  int bPosition;
  key *next;
};

unsigned char L[] = { 0xed, 0x3e, 0x0d, 0x20, 0xa9, 0xc3, 0x36, 0x75, 0x4c, 0x2c, 0x57, 0xa3, 0x00, 0xae, 0x31, 0x0f,
                       0x19, 0x4d, 0x44, 0xa0, 0x11, 0x56, 0x18, 0x66, 0x09, 0x69, 0x6e, 0x3d, 0x25, 0x9c, 0xdb, 0x3f,
                       0x65, 0x58, 0x1a, 0x6d, 0xff, 0xd7, 0x46, 0xb3, 0xb1, 0x2b, 0x78, 0xcf, 0xbe, 0x26, 0x42, 0x2f,
                       0xd8, 0xd4, 0x8e, 0x48, 0x05, 0xb9, 0x34, 0x43, 0xde, 0x68, 0x5a, 0xaa, 0x9d, 0xbd, 0x84, 0xa2,
                       0x3c, 0x50, 0xce, 0x8b, 0xc5, 0xd0, 0xa5, 0x77, 0x1f, 0x12, 0x6b, 0xc2, 0xb5, 0xe6, 0xab, 0x54,
                       0x81, 0x22, 0x9f, 0xbb, 0x5c, 0xa8, 0xdc, 0xec, 0x2d, 0x1e, 0xee, 0xd6, 0x6c, 0x5f, 0x9a, 0xfd,
                       0xc8, 0xd5, 0x94, 0xfc, 0x0c, 0x1c, 0x96, 0x4f, 0xf9, 0x51, 0xda, 0x9b, 0xdf, 0xe1, 0x47, 0x37,
                       0xd1, 0xeb, 0xaf, 0xf7, 0xa4, 0x03, 0xf0, 0xc7, 0x60, 0xe4, 0xf4, 0xb4, 0x85, 0xf6, 0x62, 0x04,
                       0x71, 0x87, 0xea, 0x17, 0x99, 0x1d, 0x3a, 0x15, 0x52, 0x0a, 0x07, 0x35, 0xe0, 0x70, 0xb6, 0xfa,
                       0xcb, 0xb0, 0x86, 0xa6, 0x92, 0xfb, 0x98, 0x55, 0x06, 0x4b, 0x5d, 0x4a, 0x45, 0x83, 0xbf, 0x16,
                       0x7c, 0x10, 0x95, 0x28, 0x38, 0x82, 0xf3, 0x6a, 0xf8, 0xfe, 0x79, 0x39, 0x27, 0x2a, 0x5e, 0xe7,
                       0x59, 0xb8, 0x1b, 0xca, 0x8d, 0xd3, 0x7b, 0x30, 0x33, 0x90, 0xd2, 0xd9, 0xac, 0x76, 0x8f, 0x5b,
                       0xa7, 0x0e, 0x63, 0xc4, 0xb2, 0xe9, 0x97, 0x91, 0x53, 0x7a, 0x0b, 0x41, 0x08, 0xc1, 0x8c, 0x7d,
                       0x88, 0x24, 0xf5, 0xf2, 0x01, 0x72, 0xe8, 0x80, 0x49, 0x13, 0x23, 0x9e, 0xc6, 0x14, 0x73, 0xad,
                       0x8a, 0x29, 0xef, 0xe5, 0x67, 0x61, 0xba, 0xe2, 0x7e, 0x89, 0x64, 0x02, 0xc0, 0x21, 0x6f, 0xf1,
                       0xdd, 0xb7, 0xc9, 0xe3, 0xcd, 0x3b, 0x93, 0x2e, 0x40, 0xbc, 0x4e, 0xa1, 0xcc, 0x74, 0x32, 0x7f,
 };

 unsigned char K[] = { 0xb8, 0x08, 0x29, 0x4a, 0xd6, 0x57, 0x37, 0x6b, 0x28, 0xe5, 0x95, 0x34, 0x26, 0x52, 0x6b, 0xe5,
                       0xc5, 0xe7, 0x81, 0x4e, 0x2b, 0xce, 0x11, 0x4d, 0x5e, 0x11, 0x22, 0x57, 0x38, 0x33};


key *head = NULL, *tmpHead = NULL;

unsigned char high(unsigned int X)
{
  return(X & 0xff);
}


int mod (int a, int b)
{
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

int initcalcX(int a , int b, int key)
{
  return mod((key - L[high(a)] - L[high(b)]),256);
}

int checkValid(int a, int b, int x, int key)
{
  int newX;
  newX = mod((key - L[high(a)] - L[high(b)]), 256);
  if(newX == high(x))
    return 1;
  return 0;
}

void inserttmpHead(key *node)
{
  if(tmpHead == NULL)
  {
    tmpHead = node;
  }
  else
  {
    key *temp = tmpHead;
    while(temp->next != NULL)
      temp = temp->next;

    temp->next = node;
  }
}

void makeCopy(key *node, unsigned int a, unsigned int b, unsigned int x, int bShift)
{
  key *tmp;
  tmp = (key *)malloc(sizeof(key));
  memset((char*)tmp,0,sizeof(key));
  tmp ->preA = node->preA;
  tmp->preB = node->preB;
  tmp->preX = node->preX;
  tmp->position = node->position;
  tmp->bPosition = node->bPosition;
  tmp -> preA = tmp->preA | ((node->a & 0x01) << node->position);
  if(bShift == 1)
    tmp -> preB = tmp->preB | ((node->b & 0x01) << node->bPosition);
  else if (bShift == 2)
    tmp -> preB = tmp->preB | ((node->b & 0x03) << node->bPosition);

  tmp -> preX = tmp->preX | (node->x & 0x01) << node->position;
  tmp -> a = a;
  tmp-> b = b;
  tmp-> x = x;

  tmp->next = NULL;
  inserttmpHead(tmp);
}

void positionInc(key *node, int bPos)
{
  node->position +=1;
  node->bPosition += bPos;
}

void extendVal(key* node, int key)
{
  /* a b x
   * 0 0 0
   * 0 1 0
   * 1 0 0
   * 1 1 0
   */
  if(checkValid((node->a)>>1,(node->b)>>1,(node->x)>>1,key))
  {
    positionInc(node,1);
    makeCopy(node,(node->a)>>1,(node->b)>>1,(node->x)>>1,1);
  }
  if(checkValid((node->a)>>1,(node->b)>>1|0x80,(node->x)>>1,key))
  {
    positionInc(node,1);
    makeCopy(node,(node->a)>>1,(node->b)>>1,(node->x)>>1,1);
  }

  if(checkValid((node->a)>>1|0x80,(node->b)>>1,(node->x)>>1,key))
  {
    positionInc(node,1);
    makeCopy(node,(node->a)>>1,(node->b)>>1,(node->x)>>1,1);
  }

  if(checkValid((node->a)>>1|0x80,(node->b)>>1|0x80,(node->x)>>1,key))
  {
    positionInc(node,1);
    makeCopy(node,(node->a)>>1|0x80,(node->b)>>1|0x80,(node->x)>>1,1);
  }

  /* a b x
   * 0 0 1
   * 0 1 1
   * 1 0 1
   * 1 1 1
   */

  if(checkValid((node->a)>>1,(node->b)>>1,(node->x)>>1|0x80,key))
  {
    positionInc(node,1);
    makeCopy(node,(node->a)>>1,(node->b)>>1,(node->x)>>1|0x80,1);
  }
  if(checkValid((node->a)>>1,(node->b)>>1|0x80,(node->x)>>1|0x80,key))
  {
    positionInc(node,1);
    makeCopy(node,(node->a)>>1,(node->b)>>1|0x80,(node->x)>>1|0x80,1);
  }
  if(checkValid((node->a)>>1|0x80,(node->b)>>1,(node->x)>>1|0x80,key))
  {
    positionInc(node,1);
    makeCopy(node,(node->a)>>1|0x80,(node->b)>>1,(node->x)>>1|0x80,1);
  }
  if(checkValid((node->a)>>1|0x80,(node->b)>>1|0x80,(node->x)>>1|0x80,key))
  {
    positionInc(node,1);
    makeCopy(node,(node->a)>>1|0x80,(node->b)>>1|0x80,(node->x)>>1|0x80,1);
  }

  /* a b  x
   * 0 00 0
   * 0 01 0
   * 0 10 0
   * 0 11 0
   */
  if(checkValid((node->a)>>1,(node->b)>>2,(node->x)>>1,key))
  {
    positionInc(node,2);
    makeCopy(node,(node->a)>>1,(node->b)>>2,(node->x)>>1,2);
  }

  if(checkValid((node->a)>>1,(node->b)>>2|0x40,(node->x)>>1,key))
  {
    positionInc(node,2);
    makeCopy(node,(node->a)>>1,(node->b)>>2|0x40,(node->x)>>1,2);
  }

  if(checkValid((node->a)>>1,(node->b)>>2|0x80,(node->x)>>1,key))
  {
    positionInc(node,2);
    makeCopy(node,(node->a)>>1,(node->b)>>2|0x80,(node->x)>>1,2);
  }

  if(checkValid((node->a)>>1,(node->b)>>2|0xc0,(node->x)>>1,key))
  {
    positionInc(node,2);
    makeCopy(node,(node->a)>>1,(node->b)>>2|0xc0,(node->x)>>1,2);
  }

  /* a b  x
     0 00 1
     0 01 1
     0 10 1
     0 11 1
  */
  if(checkValid((node->a)>>1,(node->b)>>2,(node->x)>>1|0x80,key))
  {
	  positionInc(node,2);
	  makeCopy(node,(node->a)>>1,(node->b)>>2,(node->x)>>1|0x80,2);
  }
  if(checkValid((node->a)>>1,(node->b)>>2|0x40,(node->x)>>1|0x80,key))
  {
	  positionInc(node,2);
	  makeCopy(node,(node->a)>>1,(node->b)>>2|0x40,(node->x)>>1|0x80,2);
  }
  if(checkValid((node->a)>>1,(node->b)>>2|0x80,(node->x)>>1|0x80,key))
  {
	  positionInc(node,2);
	  makeCopy(node,(node->a)>>1,(node->b)>>2|0x80,(node->x)>>1|0x80,2);
  }
  if(checkValid((node->a)>>1,(node->b)>>2|0xc0,(node->x)>>1|0x80,key))
  {
	  positionInc(node,2);
	  makeCopy(node,(node->a)>>1,(node->b)>>2|0xc0,(node->x)>>1|0x80,2);
  }


  /* a b  x
   * 1 00 0
   * 1 01 0
   * 1 10 0
   * 1 11 0
   */
  if(checkValid((node->a)>>1|0x80,(node->b)>>2,(node->x)>>1,key))
  {
	  positionInc(node,2);
	  makeCopy(node,(node->a)>>1|0x80,(node->b)>>2,(node->x)>>1,2);
  }
  if(checkValid((node->a)>>1|0x80,(node->b)>>2|0x40,(node->x)>>1,key))
  {
	  positionInc(node,2);
	  makeCopy(node,(node->a)>>1|0x80,(node->b)>>2|0x40,(node->x)>>1,2);
  }
  if(checkValid((node->a)>>1|0x80,(node->b)>>2|0x80,(node->x)>>1,key))
  {
	  positionInc(node,2);
	  makeCopy(node,(node->a)>>1|0x80,(node->b)>>2|0x80,(node->x)>>1,2);
  }
  if(checkValid((node->a)>>1|0x80,(node->b)>>2|0xc0,(node->x)>>1,key))
  {
	  positionInc(node,2);
	  makeCopy(node,(node->a)>>1|0x80,(node->b)>>2|0xc0,(node->x)>>1,2);
  }

  /* a b  x
     1 00 1
     1 01 1
     1 10 1
     1 11 1
  */
  if(checkValid((node->a)>>1|0x80,(node->b)>>2,(node->x)>>1|0x80,key))
  {
	  positionInc(node,2);
	  makeCopy(node,(node->a)>>1|0x80,(node->b)>>2,(node->x)>>1|0x80,2);
  }
  if(checkValid((node->a)>>1|0x80,(node->b)>>2|0x40,(node->x)>>1|0x80,key))
  {
	  positionInc(node,2);
	  makeCopy(node,(node->a)>>1|0x80,(node->b)>>2|0x40,(node->x)>>1|0x80,2);
  }
  if(checkValid((node->a)>>1|0x80,(node->b)>>2|0x80,(node->x)>>1|0x80,key))
  {
	  positionInc(node,2);
	  makeCopy(node,(node->a)>>1|0x80,(node->b)>>2|0x80,(node->x)>>1|0x80,2);
  }
  if(checkValid((node->a)>>1|0x80,(node->b)>>2|0xc0,(node->x)>>1|0x80,key))
  {
	  positionInc(node,2);
	  makeCopy(node,(node->a)>>1|0x80,(node->b)>>2|0xc0,(node->x)>>1|0x80,2);
  }
}

int deleteNode(key *n)
{
  if(head == NULL)
  {
    printf("Empty List\n");
    return 0;
  }

  if(head == n)
  {
    if(head->next == NULL)
    {
      printf("Only One Node.. Returning one\n");
      free(head);
      head = NULL;
      return 1;
    }
    head = head->next;
    free(n);
    return 2;
  }

  key *prev = head;
  while(prev->next != NULL && prev->next != n)
    prev = prev->next;

  if(prev->next == NULL)
  {
    printf("Given node is not present in Linked List\n");
    return 3;
  }

  prev->next = prev->next->next;
  free(n);
  return 4;
}



void insert(int a, int b, int k)
{
  if(head == NULL)
  {
    head = (key *)malloc(sizeof(key));
    memset((char*)head,0,sizeof(key));
    head -> a = a;
    head-> b = b;
    head -> x = initcalcX(a,b,k);
    head->position = -1;
    head->bPosition = -1;
    head ->next= NULL;
  }
  else
  {
    key *temp = head, *temp2;

    while(temp->next != NULL)
      temp = temp->next;

    temp2 = (key *)malloc(sizeof(key));
    memset(temp2,0,sizeof(key));
    temp2-> a = a;
    temp2-> b = b;
    temp2-> x = initcalcX(a,b,k);
    temp2->position = -1;
    temp2->bPosition = -1;
    temp2->next= NULL;


    temp->next = temp2;
  }
}

void printCount(key *tmp)
{
  int count = 0;
  while(tmp)
  {
    //printf("%u\n",tmp->a);
	  count++;
    tmp = tmp->next;
  }
  printf("Val:%d\n",count);
}

void printValues(key *tmp)
{
  while(tmp)
  {
    printf("a:%d\n",tmp->a);
    printf("b:%d\n",tmp->b);
    printf("x:%d\n",tmp->x);
    printf("preA:%u\n",tmp->preA);
    printf("preB:%u\n",tmp->preB);
    printf("preX:%u\n",tmp->preX);
    printf("position:%d\n",tmp->position);
    printf("bposition:%d\n",tmp->bPosition);

    tmp = tmp->next;
  }
}

void main()
{
  int i, j,count = 0;
  key *tmp,*prev;
  int c = 0;

  for(i = 0 ;i<256;i++)
  {
    for(j = 0;j<256;j++)
    {
      insert(i,j,K[count]);
    }
  }

  tmp = head;
  while(tmp)
  {
    c++;
    tmp = tmp->next;
  }
  printf("TotalElements:%d\n",c);

  while(1)
  {
    /*variable for looping Key*/
    count++;

    tmp = head;
    /* If count has reached 30., then all the keyStream have been iterated. So break*/
    if(30 == count)
    {
      printValues(tmp);
      break;
    }
    tmp = head;
    while(tmp)
    {
      extendVal(tmp,K[count]);
      if(deleteNode(tmp) == 1)
        tmp = NULL;
      else
        tmp = tmp->next;
    }
    /* Copy the tmpHead to head., since the extension nodes will be only in tmpHead */
    head = tmpHead;
    printf("Iteration: %d\n",count);
    printCount(head);
    tmpHead = NULL;
  }
}
