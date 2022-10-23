#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	int height;
	struct node *left;
	struct node *right;
}*root;


int max(int a , int b){ return a>b?a:b;}

int height(struct node *root)
{
	if(root == NULL) return 0;
	return root->height;
}

int balance_factor(struct node *root)
{
	return height(root->left) - height(root->right);
}

struct node *new_node(int data)
{
	struct node *root = (struct node *) malloc(sizeof(struct node *));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	root->height = 1;
	return root;
}

struct node *right_rotate(struct node *root)
{
	struct node *x , *y ,*z , *t3;
	z = root;
	y = z->left;
	t3 = y->right;
	
	y->right = z;
	z->left = t3;
	
	z->height = 1 + max(height(z->left) , height(z->right));
	y->height = 1 + max(height(y->left) , height(y->right));
	return y;
}
struct node *left_rotate(struct node *root)
{
	struct node *x , *y ,*z , *t3;
	z = root;
	y = z->right;
	t3 = y->left;
	
	y->left = z;
	z->right = t3;
	
	z->height = 1 + max(height(z->left) , height(z->right));
	y->height = 1 + max(height(y->left) , height(y->right));
	return y;
	
}

struct node *insert(struct node *root, int data)
{
	if(root == NULL) return new_node(data);
	else if(root->data < data) root->right = insert(root->right , data);
	else if(root->data > data) root->left  = insert(root->left  , data);
	
	root->height = 1 + max(height(root->left) , height(root->right));
	
	int bf = balance_factor(root);
	
	if(bf>=-1 && bf<=1)
	{
		printf("Node : %d , balanced , bf = %d\n" , root->data , bf);
	}
	else
	{
		printf("Node : %d , unbalanced , bf = %d\n" , root->data , bf);
	
		if(bf > 1)
		{
			if(root->left->data > data)
			{
				root = right_rotate(root);
			}
			else
			{
				root->left = left_rotate(root->left);
				root = right_rotate(root);
			}
		}
		else
		{
			if(root->right->data < data)
			{
				root = left_rotate(root);
			}
			else
			{
				root->right = right_rotate(root->right);
				root = left_rotate(root);
			}
		}
	}
	return root;

}

struct node *delete(struct node *root, int data)
{
	if(root == NULL) return new_node(data);
	else if(root->data < data) root->right = delete(root->right , data);
	else if(root->data > data) root->left  = delete(root->left  , data);
	else {root = NULL; return root;}
	
	root->height = 1 + max(height(root->left) , height(root->right));
	
	int bf = balance_factor(root);
	
	if(bf>=-1 && bf<=1)
	{
		printf("Node : %d , balanced , bf = %d\n" , root->data , bf);
	}
	while(bf > 1 || bf < -1)
	{
	
		printf("Node : %d , unbalanced , bf = %d\n" , root->data , bf);
	
		if(bf > 1)
		{
			if(root->left->data < data)
			{
				root = right_rotate(root);
			}
			else
			{
				root->left = left_rotate(root->left);
				root = right_rotate(root);
			}
		}
		else
		{
			if(root->right->data < data)
			{
				root = left_rotate(root);
			}
			else
			{
				root->right = right_rotate(root->right);
				root = left_rotate(root);
			}
		}
		bf = balance_factor(root);
	}
	return root;

}

struct node *search(int data)
{
	struct node *curr = root;
	
	while(curr!=NULL)
	{
		int d = curr->data;
		if(d < data){
			if(curr->right!=NULL) curr = curr->right;
			else
			{
				printf("Not found! \n");
				break;
			}
		}
		else if(d > data) {
			if(curr->left!=NULL) curr = curr->left;
			else
			{	
				printf("Not found! \n");
				break;
			}
		}
		else
		{
			printf("found ! \n");
			return curr;
		}
	}
	return NULL;
}

void inorder(struct node *root)
{
	if (root == NULL) return ;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void preorder(struct node *root)
{
	if (root == NULL) return ;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	root = NULL;
	
	printf("1. for insertion\n");
	printf("2. for deletion of subtree\n");
	printf("3. search node\n");
	printf("4. calculate balance factor\n\n");
	
	while(1)
	{
		int ch;
		printf("Enter your choice : ");
		scanf("%d" , &ch);
		if(ch == 1)
		{
			int data;
			printf("Enter data : ");
			scanf("%d" , &data);
			
			root = insert(root , data);
			printf("\n");
			
			printf("inorder : "); inorder(root);
			printf("\npreorder: "); preorder(root);
		}
		else if(ch == 2)
		{
			int data;
			printf("Enter data : ");
			scanf("%d" , &data);
			printf("Enter 1 for left , 2 for right subtree\n");
			int ch;
			scanf("%d" , &ch);
			
			if(ch == 1)
			{
				data = search(data)->left->data;
			}
			
			if(ch == 2)
			{
				data = search(data)->right->data;
			}
			root = delete(root , data);
			
			printf("inorder : "); inorder(root);
			printf("\npreorder: "); preorder(root);
			
		}
		else if(ch == 3)
		{
			int data;
			printf("Enter data : ");
			scanf("%d" , &data);
			search(data);
		}
		else if(ch == 4)
		{
		
			int data;
			printf("Enter data : ");
			scanf("%d" , &data);
			struct node *n = search(data);
			printf("balance factor : %d\n" , balance_factor(n) );
		}
		else
		{
			break;
		}
		printf("\n\n");
	}
	return 0;
}
