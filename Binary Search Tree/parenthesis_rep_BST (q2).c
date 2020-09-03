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
		printf("%d ",root->data);
		paren(root->prev);
		paren(root->next);
	}
	printf(") ");
}

void main()
{
	char s[4];
	int i,k;
	list *root=NULL,*x;
	while(1)
	{
		scanf("%s",s);

		if(strcmp(s,"insr")==0)
		{
			scanf("%d",&i);
			insert(&root,i);
		}

		if(strcmp(s,"srch")==0)
		{
			scanf("%d",&k);
			x=search(root,k);
			if(x==NULL)
				printf("NOT FOUND\n");
			else
				printf("FOUND\n");
		}

		if(strcmp(s,"minm")==0)
		{
			x=findMin(root);
			if(x==NULL)
				printf("NIL\n");
			else
				printf("%d\n",x->data);
		}

		if(strcmp(s,"maxm")==0)
		{
			x=findMax(root);
			if(x==NULL)
				printf("NIL\n");
			else
				printf("%d\n",x->data);
		}

		if(strcmp(s,"pred")==0)
		{
			scanf("%d",&i);
			x=predecessor(root,i);
			if(x)
				printf("%d\n",x->data);
		}

		if(strcmp(s,"succ")==0)
		{
			scanf("%d",&i);
			x=successor(root,i);
			if(x)
				printf("%d\n",x->data);
		}

		if(strcmp(s,"delt")==0)
		{
			scanf("%d",&i);
			delete(root,i);
		}

		if(strcmp(s,"inor")==0)
		{
			inorder(root);
		}

		if(strcmp(s,"prer")==0)
		{
			preorder(root);
		}

		if(strcmp(s,"post")==0)
		{
			postorder(root);
		}

		if(strcmp(s,"prep")==0)
			paren(root);

		if(strcmp(s,"stop")==0)
			return;
	}
}	

