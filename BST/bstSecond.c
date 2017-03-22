#include <stdio.h>
#include <stdlib.h>

typedef struct Bsttree bst;
struct Bsttree {
	int value;
	bst *left;
	bst *right;
};

void insert(bst **root, int value)
{
	bst *node = malloc(sizeof(bst));
	node -> value = value;
	node ->left = NULL;
	node ->right = NULL;

	if ((*root)== NULL)
	{
		*root = node;
	}
	else if ((*root)->value>=value)
	{
		insert(&(*root)->left, value);
	}
	else
	{
		insert(&(*root)->right,value);
	}
}

void findMin(bst *root)
{
	if(root == NULL)
	{
		printf("Root NULL\n");
		return;
	}

	if(root->left == NULL)
		printf("Min element: %d",root->value);
	else
		findMin(root->left);
}

void findMax(bst *root)
{
	if(root == NULL)
	{
		printf("Root NULL\n");
		return;
	}

	if(root->right == NULL)
		printf("Max element: %d",root->value);
	else
		findMax(root->right);
}

void preOrder(bst *root)
{
	if (root==NULL)
		return;

	printf("%d ",root->value);
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(bst *root)
{
	if (root==NULL)
		return;

	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->value);
}

void InOrder(bst *root)
{
	if (root==NULL)
		return;
	InOrder(root->left);
	printf("%d ",root->value);
	InOrder(root->right);
}





int main()
{
  bst *root = NULL;
  insert(&root,20);
  insert(&root,10);
  insert(&root,30);
  insert(&root,15);
  insert(&root,24);
  printf("Preorder: ");
  preOrder(root);
  printf("\nInorder: ");
  InOrder(root);
  printf("\nPostorder: ");
  postOrder(root);
  printf("\n");
  findMin(root);
  printf("\n");
  findMax(root);
}
