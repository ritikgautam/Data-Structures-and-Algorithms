#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data,data2;
	struct node *next,*prev;
}list;

list *Newnode(int i)
{

	list *newnode;
	newnode=(list *)malloc(sizeof(list));
	newnode->data=i;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}
			
void insert(list **root)
{
	char a;
	int i,j;
	scanf("%c",&a);
	while(a==')' || a==' ')
	{
		scanf("%c",&a);
		if(a=='(')
			break;
	}
	if(a=='(')
	{
		j=scanf("%d",&i);
		if(j==1)
		{
			list *newnode=Newnode(i);
			*root=newnode;
			insert(&(newnode->prev));
			insert(&(newnode->next));
		}
		else if(j==0)
			*root=NULL;
	}
}

int sum(list *root)
{
	if(root==NULL)
		return 0;
	return (root->data+sum(root->prev)+sum(root->next));
}

void *tree(list **root)
{
	if(*root==NULL)
		return 0;
	(*root)->data2 = sum(*root);
	tree(&((*root)->prev));
	tree(&((*root)->next));
}

void mod_tree(list *root)
{
	printf("( ");
	if(root!=NULL)
	{
		printf("%d ",root->data2);
		mod_tree(root->prev);
		mod_tree(root->next);
	}
	printf(") ");
}

int maxSubBST(list *root)
{



void main()
{
	list *root=NULL;
	int i;
	insert(&root);
	i=maxSubBST(root);
	printf("%d\n",i);
	return;
}
