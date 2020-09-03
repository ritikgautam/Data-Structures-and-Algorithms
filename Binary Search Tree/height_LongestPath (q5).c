#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next,*prev;
}list;

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
			list *newnode;
			newnode=(list *)malloc(sizeof(list));
			newnode->data=i;
			newnode->next=NULL;
			newnode->prev=NULL;
			*root=newnode;
			insert(&(newnode->prev));
			insert(&(newnode->next));
		}
		else if(j==0)
			*root=NULL;
	}
}

int height(list *root)
{
	if(root==NULL)
	return 0;
	else{
	int l=height(root->prev);
	int r=height(root->next);
	
	if(l<r)
	l=r;
	return(l+1);}
}
int max(int a, int b)
{
	if(a<b)
		a=b;
	return a;
}

int longest_path(list *root,int *h)
{
	int l=0,r=0,x=0,y=0;
	if(root==NULL)
	{
		*h=0;
		return 0;
	}
	x=longest_path(root->prev,&l);
	y=longest_path(root->next,&r);
	*h=max(l,r)+1;
	return max(l+r+1,max(x,y));
}

void main()
{
	list *root=NULL;
	insert(&root);
	int h,l;
	h=height(root);
	l=longest_path(root,&h);
	printf("%d ",h-1);
	printf("%d\n",l-1);
}
