#include <stdio.h>
#include <stdlib.h>

typedef struct bstTree bst;
struct bstTree
{
  int value;
  bst *left;
  bst *right;
};

void insert(bst **root,int value)
{
  if(*root == NULL)
  {
    bst *tmp = malloc(sizeof(bst));
    tmp->value = value;
    tmp->left = NULL;
    tmp->right = NULL;
    *root = tmp;
  }
  else if((*root)->value >= value)
  {
    insert(&(*root)->left,value);
  }
  else
  {
    insert(&(*root)->right,value);
  }
}

/* don't study this */
void findSumUtil(bst *node,int *arr,int size,int sum)
{
  sum = sum - node->value;
  if(node->left == NULL && node->right == NULL)
  {
    if(sum == 0)
    {
      int i;
      for(i=0;i<size;i++)
      {
        printf("%d ",arr[i]);
      }
      printf("%d",node->value);
    }
    return;
  }
  else
  {
    arr[size] = node->value;
    if(node->left != NULL)
      findSumUtil(node->left,arr,size+1,sum);

    if(node->right != NULL)
      findSumUtil(node->right,arr,size+1,sum);
  }
}

int findSumUtil2(bst *node,int *arr,int size,int sum)
{
  if(node == NULL )
  {
    if(sum == 0)
    {
      int i;
      for(i=0;i<size;i++)
      {
        printf("%d ",arr[i]);
      }
      return 1;
    }
    return 0;
  }
  else
  {
    sum = sum - node->value;
    arr[size] = node->value;
    if(findSumUtil2(node->left,arr,size+1,sum) == 0)
      return findSumUtil2(node->right,arr,size+1,sum);
    else return 1;
  }
}


void mirror(bst *node)
{
  if(node == NULL)
    return;

  mirror(node->left);
  bst *tmp = node->left;
  node->left = node ->right;
  mirror(node->right);
  node->right = tmp;
}

void findSumUtility(bst *node,int *arr,int size,int outSum,int currSum)
{
  currSum = currSum + node->value;
  if(currSum == outSum && node->left == NULL && node->right == NULL)
  {
    int i;
    for(i=0;i<size;i++)
    {
      printf("%d ",arr[i]);
    }
    printf("%d",node->value);
  }
  else if((node->left == NULL && node->right == NULL) || currSum > outSum)
  {

  }
  else
  {
    if(node->left != NULL)
    {
      int *tmpArray;
      tmpArray = malloc(sizeof(int) * size+1);
      printf("Allocated: %p\n",tmpArray);
      if(arr != NULL)
        memcpy(tmpArray,arr,sizeof(int)*size);
      tmpArray[size] = node->value;
      findSumUtility(node->left,tmpArray,size+1,outSum,currSum);
    }
    if(node->right != NULL)
    {
      int *tmpArray1;
      tmpArray1 = malloc(sizeof(int) * size+1);
      printf("Allocated: %p\n",tmpArray1);
      if(arr != NULL)
      memcpy(tmpArray1,arr,sizeof(int)*size);
      tmpArray1[size] = node->value;
      findSumUtility(node->right,tmpArray1,size+1,outSum,currSum);
    }
  }
  if(arr != NULL)
  {
    printf("Free: %p\n",arr);
    free(arr);
  }
}


void findSum(bst *root, int sum)
{
  int *arr = NULL;
  findSumUtility(root,arr,0,sum,0);
}

void inOrder(bst *node)
{
  if(node == NULL)
    return;
  inOrder(node->left);
  printf("%d ",node->value);
  inOrder(node->right);
}

void printPaths(bst *node,int *arr, int size)
{
  if(node == NULL)
    return ;

  arr[size++] = node->value;
  printPaths(node->left,arr,size);
  printPaths(node->right,arr,size);
  if(node->left == NULL && node->right == NULL)
  {
    int i;
    for(i=0;i<size;i++)
    {
      printf("%d ",arr[i]);
    }
    printf("\n");
  }
}

void doubleTree(bst *node) {
  if(node == NULL)
    return;
  doubleTree(node->left);
  doubleTree(node->right);
  insert(&node,node->value);
}

int sameTree(bst* a, bst* b) {
  if(a == NULL && b == NULL)
    return 1;
  else if(a == NULL || b == NULL)
    return 0;
  else
  {
    if(a->value != b->value)
      return 0;
    if((sameTree(a->left,b->left) && sameTree(a->right,b->right)) == 0)
      return 0;
  }
  return 1;
}

void main()
{
  bst *root = NULL,*tmp;
  insert(&root,17);
  insert(&root,5);
  insert(&root,9);
  insert(&root,12);
  insert(&root,21);
  insert(&root,18);
  insert(&root,27);
  insert(&root,30);
  insert(&root,35);
  insert(&tmp,17);
  insert(&tmp,5);
  insert(&tmp,9);
  insert(&tmp,12);
  insert(&tmp,45);
  insert(&tmp,18);
  insert(&tmp,27);
  insert(&tmp,30);
  insert(&tmp,35);
  printf("Inorder: ");
  inOrder(root);
  printf("\n");
  findSum(root,130); /* not the correct one*/
  int arr[1000];
  printf("\nFound Path:%d\n",findSumUtil2(root,arr,0,13));
  printPaths(root,arr,0);
  mirror(root);

  //doubleTree(root);
  //inOrder(root);
  printf("Same Tree:%d\n",sameTree(root,tmp));
}
