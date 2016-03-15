#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct bst tree;
struct bst{
  char value;
  tree *left;
  tree *right;
};

typedef struct myqueue queue;

struct myqueue{
  tree *value;
  queue *next;
};

queue *head = NULL;
queue *tail = NULL;

void push (tree *value)
{
  queue *temp;
  temp = malloc(sizeof(queue));
  temp->value = value;
  temp->next = NULL;

  if(head == NULL)
  {
    head = temp;
    tail = temp;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
}

tree* pop()
{
  queue *tmp;
  tree *ttmp;
  if(head == NULL)
  {
    printf("Queue is Empty\n");
    return NULL;
  }
  else if(head->next == NULL)
  {
    tmp = head;
    head = NULL;
    tail = NULL;
    //printf("Popped element:%p",tmp->value);
    ttmp = tmp->value;
    free(tmp);
    return ttmp;
  }
  else
  {
    tmp = head;
    head = head->next;
    ttmp = tmp->value;
    free(tmp);
    return ttmp;
  }
}

int isQueueEmpty()
{
  if(head == NULL)
    return 1;
  else
    return 0;
}


tree *root = NULL;

tree* createNode(char value)
{
  tree *tmp = malloc(sizeof(tree));
  tmp->left = NULL;
  tmp->right = NULL;
  tmp->value = value;
  return tmp;
}

char findMin(tree *node)
{
  if(node->left != NULL)
    return findMin(node->left);
  else
    return node->value;
}

tree* findMinNode(tree *node)
{
  if(node->left != NULL)
    return findMinNode(node->left);
  else
    return node;
}

char findMax(tree *root)
{
  if(root->right != NULL)
    return findMax(root->right);
  else
    return root->value;
}


void insertNode(tree **node, char value)
{
  if (NULL == *node)
  {
    *node = createNode(value);
  }
  else if((*node)->value >= value)
  {
    insertNode(&(*node)->left,value);
  }
  else
  {
    insertNode(&(*node)->right,value);
  }
}

int search(tree *root, char value)
{
  if(root == NULL)
  {
    return -1;
  }
  else if(root->value == value)
  {
    return 1;
  }
  else if(root->value >= value)
    return search(root->left,value);
  else
    return search(root->right,value);
}

int max(char a, char b)
{
  if(a>b)
    return a;
  else
    return b;
}

int min(char a, char b)
{
  if(a<b)
    return a;
  else
    return b;
}

int findHeight(tree *root)
{
  if(root == NULL )
    return -1;
  else
    return 1+ max(findHeight(root->left),findHeight(root->right));
}

int findDepth(tree *root,char value)
{
  if(root == NULL )
    return 1000;
  else if(root->value == value)
    return 0;
  else
    return 1 + min(findDepth(root->left,value),findDepth(root->right,value));
}


int findMaxDepth(tree *root)
{
  if(root == NULL )
    return -1;
  else
    return 1 + max(findMaxDepth(root->left),findMaxDepth(root->right));
}

void preOrder(tree *node)
{
  if (node == NULL)
    return ;
  else
  {
    printf("%c ",node->value);
    preOrder(node->left);
    preOrder(node->right);
  }
}

void inOrder(tree *node)
{
  if (node == NULL)
    return ;
  else
  {
    inOrder(node->left);
    printf("%c ",node->value);
    inOrder(node->right);
  }
}

int inOrderBST(tree *node,int lastVal)
{
  if (node == NULL)
    return 1;
  else
  {
    return inOrderBST(node->left,node->value);
    if(lastVal > node->value)
    {
      return 0;
    }
    return inOrderBST(node->right,node->value);
  }
}

void postOrder(tree *node)
{
  if (node == NULL)
    return ;
  else
  {
    postOrder(node->left);
    postOrder(node->right);
    printf("%c ",node->value);
  }
}


int isBST(tree *root, int minVal, int maxval)
{
  if(root == NULL)
    return 1;
  else if(root->value >= minVal && root->value < maxval
		  && isBST(root->left,minVal,root->value) && isBST(root->right,root->value,maxval))
    return 1;
  else return 0;
}

int isBinarySearchTree(tree *root)
{
  return isBST(root,INT_MIN,INT_MAX);
}

void levelOrderTraversal(tree *root)
{
  tree *tmp;
  printf("Level Order: ");
  push(root);
  while(!isQueueEmpty())
  {
    tmp = pop();
    printf("%c ",tmp->value);
    if(tmp->left != NULL)
      push(tmp->left);
    if(tmp->right != NULL)
      push(tmp->right);
  }
  printf("\n");
}

tree* deleteNode(tree *root, int value)
{
  tree *tmp;
  if(root == NULL)
    return NULL;
  else if(value < root->value)
    root->left = deleteNode(root->left,value);
  else if(value > root->value)
    root->right = deleteNode(root->right,value);
  else
  {
    if(root->left == NULL)
    {
      tmp = root;
      root = root->right;
      free(tmp);
    }
    else if(root->right == NULL)
    {
      tmp = root;
      root = root->left;
      free(tmp);
    }
    else
    {
      tmp = findMinNode(root->right);
      root->value = tmp->value;
      root->right = deleteNode(root->right,tmp->value);
    }
  }
  return root;
}


void main()
{
  char input;
  while(0)
  {
    printf("1. InsertNode\n2.FindMin\n3.FindMax\n4.findHeight\n5.findMaxDepth\n");
    printf("1. InsertNode\n2.FindMin\n3.FindMax\n4.findHeight\n5.findMaxDepth\n");
  }
  insertNode(&root,'F');
  //printf("Searched Node 5: %d\n",search(root,5));
  insertNode(&root,'D');
  insertNode(&root,'E');
  insertNode(&root,'B');
  insertNode(&root,'C');
  insertNode(&root,'A');
  insertNode(&root,'J');
  insertNode(&root,'G');
  insertNode(&root,'I');
  insertNode(&root,'H');
  insertNode(&root,'K');
  //printf("Searched Node 5: %d\n",search(root,5));
  //printf("Searched Node 6: %d\n",search(root,6));
  //printf("Min Element:%d\n",findMin(root));
  printf("Min Element:%c\n",findMin(root));
  printf("Max Element:%c\n",findMax(root));
  printf("Height of Tree:%d\n",findHeight(root));
  printf("Depth of Root:%d\n",findDepth(root,4));
  printf("Depth of Root:%d\n",findDepth(root,12));
  printf("Max Depth of Tree:%d\n",findMaxDepth(root));
  printf("Preorder: ");
  preOrder(root);
  printf("\nInorder: ");
  inOrder(root);
  printf("\nPostorder: ");
  postOrder(root);
  printf("\n");
  levelOrderTraversal(root);
  printf("IsBinarySearchTree:%d\n",isBinarySearchTree(root));
  printf("IsBinarySearchTree:%d\n",inOrderBST(root,INT_MIN));
  deleteNode(root,'B');
  printf("\nInorder: ");
  inOrder(root);
  printf("\n");
}
