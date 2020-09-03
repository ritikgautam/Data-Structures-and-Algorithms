#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    int data;
    char c;
    struct Node *next;
}list;

list *search(list *root,char a){
    if(root==NULL)
        return NULL;
    if(root->c == a)
        return root;
    else
        return search(root->next,a);
}

void create(list **root,char s[],int l){
        int i=0;
	while(i<l)
	{
        if(*root==NULL)
	{
            list *temp;
            temp=(list*)malloc(sizeof(list));
            temp->data=0;
            temp->c=s[i];
            temp->next = NULL;
            *root = temp;
        }
        list *temp = search(*root,s[i]);
        if(temp!=NULL)
            temp->data++;
        else{
            list *temp;
            temp=(list*)malloc(sizeof(list));
            temp->data=1;
            temp->c=s[i];
            temp->next=NULL;
            list *temp2 =*root;
            while(temp2->next!=NULL)
                temp2=temp2->next;
            temp2->next = temp;
        }
	i++;
    }
}

void value(list *root,int i)
    {
    int s=(root->data +root->next->data)*(i-1);
    root=root->next->next;
    for(int j=i-2;j>0;j--)
    {
        s += (root->data)*j;
        root=root->next;
    }
    printf("%d\n",s);
}

void split(list *root,list **l,list **r)
	{
        list *temp1,*temp2;
        temp2=root;
        temp1=root->next;
        while(temp1!=NULL){
            temp1=temp1->next;
            if(temp1!=NULL)
	    {
                temp2 = temp2->next;
                temp1 = temp1->next;
            }
        }
        *l=root;
        *r = temp2->next;
        temp2->next=NULL;
}

list *merge(list *l,list *r)
{
   list *temp= NULL;
    if(l==NULL)
        return r;
    else if(r==NULL)
        return l;
    if(l->data <= r->data)
	{
        temp=l;
        temp->next=merge(l->next,r);
    }
    else
	{
        temp=r;
        temp->next=merge(l,r->next);
    }
    return temp;
}

void mrgsrt(list **root)
{
    list *temp=*root,*l,*r;
    if(temp==NULL || temp->next==NULL)
        return;
    split(temp,&l,&r);
    mrgsrt(&l);
    mrgsrt(&r);
    *root=merge(l,r);
}

int main()
{
    int i=0;
    char s[50];
    scanf("%s",s);
    list *root=NULL;
    int l=strlen(s);
    create(&root,s,l);
    mrgsrt(&root);
    list *temp=root;
    while(temp!=NULL)
    {
        i++;
        temp = temp->next;
    }
    value(root,i);
}
