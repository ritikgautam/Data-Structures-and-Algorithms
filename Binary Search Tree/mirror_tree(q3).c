#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *prev,*next;
}list;

list *Newnode(int i)
{
	list *newnode;
	newnode=(list*)malloc(sizeof(list));
	newnode->data=i;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}

void insert(list **root ,int i)
{
	list *temp=*root,*y;
	if(*root==NULL)
		*root=temp=Newnode(i);
	else{
	while(temp)
	{
		y=temp;
		if(i>temp->data)
			temp=temp->next;
		else
			temp=temp->prev;
	}
	if(i>(y->data))
		y->next=Newnode(i);
	else 
		y->prev=Newnode(i);}
}

list *search(list *root,int k)
{
	if(root==NULL)
		return root;
	if(root->data==k)
		return root;
	else if(root->data>k)
		search(root->prev,k);
	else if(root->data<k)
		search(root->next,k);
}

list *findMin(list *root)
{
	list *temp=root,*p=root;
	if(temp==NULL)
	{
		return temp;
	}
	while(temp)
	{
		p=temp;
		temp=temp->prev;
	}
	return p;
}

list *findMax(list *root)
{
	list*temp=root,*p=root;
	if(temp==NULL)
	{
		return temp;
	}
	while(temp)
	{
		p=temp;
		temp=temp->next;
	}
	return p;
}

list *predecessor(list *root,int i)
{
	list*temp;
	temp=search(root,i);
	if(temp==NULL)
	{
		printf("NULL\n");
		return NULL;
	}
	else{
	if(temp->prev)
	{
		return findMax(temp->prev);
	}
	else
	{
		list *x=root,*y=NULL;
		while(x->data!=temp->data)
		{
			if(temp->data > x->data)
			{
				y=x;
				x=x->next;
			}
			else
				x=x->prev;
		}
		if(y==NULL)
		{
			printf("-1\n");
			return NULL;
		}
		else 
			return y;
	}
	}
}

list *successor(list *root,int i)
{
	list *temp;
	temp=search(root,i);
	if(temp==NULL)
	{
		printf("NULL\n");
		return NULL;
	}
	else
	{
		if(temp->next)
			return findMin(temp->next);
		else
		{
			list *x=root,*y=NULL;
			while(x->data!=temp->data)
			{
				if(i>x->data)
					x=x->next;
				else
				{
					y=x;
					x=x->prev;
				}
			}
			if(y)
				return y;
			else
			{
				printf("-1\n");
				return NULL;
			}
		}
	}
}
list *delete(list *root,int i)
{
	list *temp;
	if(root==NULL)
		return root;
	else if(i<root->data)
		root->prev=delete(root->prev,i);
	else if(i>root->data)
		root->next=delete(root->next,i);
	else
	{
		if(root->prev==NULL)
		{
			list *temp=root->next;
			free(root);
			return temp;
		}
		else if(root->next==NULL)
		{
			list *temp=root->prev;
			free(root);
			return temp;
		}
		list *temp=findMin(root->next);
		root->data=temp->data;
		root->next=delete(root->next,temp->data);
	}
	return root;
}
void inorder(list *root)
{
	if(root==NULL)
		return;
	inorder(root->prev);
	printf("%d ",root->data);
	inorder(root->next);
}

void preorder(list *root)
{
	if(root==NULL)
		return;
	printf("%d",root->data);
	preorder(root->prev);
	preorder(root->next);
}

void postorder(list *root)
{
	postorder(root->prev);
	postorder(root->next);
	printf("%d",root->data);
}

void paren(list *root)
{
	printf("( ");
	if(root!=NULL)
	{
		printf("%d",root->data);
		paren(root->prev);
		paren(root->next);
	}
	printf(") ");
}

void mirror(list *root)
{
	printf("( ");
	if(root!=NULL)
	{
		printf("%d ",root->data);
		mirror(root->next);
		mirror(root->prev);
	}
	printf(") ");
}

void main()
{
	list *root=NULL;
	char a[5];
	int count=0;
	scanf("%s",a);
	if(strcmp(a,"(")==0)
			count++;
	while(count)
	{
		scanf("%s",a);
		if(strcmp(a,"(")==0)
			count++;
		else if(strcmp(a,")")==0)
			count--;
		else
			insert(&root,atoi(a));
	}
	mirror(root);
}
