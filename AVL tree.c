#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int tree;
	struct Node *leftside;
	struct Node *rightside;
	int height;
};

int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}


int max(int a, int b)
{
	return (a > b)? a : b;
}


struct Node* newNode(int tree)
{
	struct Node* node = (struct Node*)
	malloc(sizeof(struct Node));
	node->tree = tree;
	node->leftside = NULL;
	node->rightside = NULL;
	node->height = 1;
	return(node);
}

struct Node *rightsideRotate(struct Node *y)
{
	struct Node *x = y->leftside;
	struct Node *T2 = x->rightside;

	
	x->rightside = y;
	y->leftside = T2;

	y->height = max(height(y->leftside),
					height(y->rightside)) + 1;
	x->height = max(height(x->leftside),
					height(x->rightside)) + 1;


	return x;
}

struct Node *leftsideRotate(struct Node *x)
{
	struct Node *y = x->rightside;
	struct Node *T2 = y->leftside;

	
	y->leftside = x;
	x->rightside = T2;

	
	x->height = max(height(x->leftside),
					height(x->rightside)) + 1;
	y->height = max(height(y->leftside),
					height(y->rightside)) + 1;


	return y;
}


int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->leftside) - height(N->rightside);
}


struct Node* insert(struct Node* node, int tree)
{
	if (node == NULL)
		return(newNode(tree));

	if (tree < node->tree)
		node->leftside = insert(node->leftside, tree);
	else if (tree > node->tree)
		node->rightside = insert(node->rightside, tree);
	else 
		return node;

	node->height = 1 + max(height(node->leftside),
						height(node->rightside));

	int balance = getBalance(node);

	if (balance > 1 && tree < node->leftside->tree)
		return rightsideRotate(node);
		
	if (balance < -1 && tree > node->rightside->tree)
		return leftsideRotate(node);

	if (balance > 1 && tree > node->leftside->tree)
	{
		node->leftside = leftsideRotate(node->leftside);
		return rightsideRotate(node);
	}

	if (balance < -1 && tree < node->rightside->tree)
	{
		node->rightside = rightsideRotate(node->rightside);
		return leftsideRotate(node);
	}

	return node;
}

void AVL(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->tree);
		AVL(root->leftside);
		AVL(root->rightside);
	}
}

int main()
{
struct Node *root = NULL;

root = insert(root, 5);root = insert(root, 10);root = insert(root, 25);root = insert(root, 30);root = insert(root, 40);root = insert(root, 20);

printf("The final AVL tree is stuctured like this: ");
AVL(root);

return 0;
}