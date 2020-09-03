#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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

typedef struct bst
{
	int s,m,n,a,b;
}b;

int max(int a,int b)
{
	if(a<b)
		a=b;
	return a;
}

int min(int a,int b)
{
	if(a>b)
		a=b;
	return a;
}

b maxSubBST(list *root)
{
	b y;
	if(root==NULL)
	{
		y.s=0; y.m=INT_MIN; y.n=INT_MAX; y.a=0; y.b=0;
		return y;
	}
       if(root->prev==NULL && root->next==NULL)
       {
		y.s=1; y.m=root->data; y.n=root->data ; y.a=1; y.b=1;
		return y;
       }
       b l=maxSubBST(root->prev);
       b r=maxSubBST(root->next);
       y.s=(1+l.s+r.s);
       if(l.b && r.b && l.m < root->data && r.n > root->data)
       {
	       y.n=min(l.n,min(r.n,root->data));
	       y.m=max(r.m,max(l.m,root->data));
	       y.a=y.s;
	       y.b=1;
	       return y;
       }
       y.a=max(l.a,r.a);
       y.b=0;
       return y;
}

void main()
{
	list *root=NULL;
	b i;
	insert(&root);
	i=maxSubBST(root);
	printf("%d\n",i.a);
	return;
}
