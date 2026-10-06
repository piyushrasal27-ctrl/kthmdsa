//doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct dlnode
{
 int data;
 struct dlnode *next,*prev;
};

struct dlnode *dlcreate();
void dldisplay(struct dlnode *head);
struct dlnode *dlinsert(struct dlnode *head);
void reverse(struct dlnode *head);
void main()
{
 struct dlnode *head=NULL;
 int choice;

  while(1)
  {
    printf("\n\n1.Create Doubly Linked List");
    printf("\n2.Display");
    printf("\n3.reverse");
    printf("\n0.Exit");
    printf("\nSelect Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1: head=dlcreate();
		break;
     case 2: dldisplay(head);
		break;
     case 3: reverse(head);
	   	break;
		
     case 0: exit(0);
     default: printf("Invalid choice:");
    }
  }
}//main

struct dlnode *dlcreate()
{
  int n,i;

  struct dlnode *head=NULL,*newnode,*curr;
  printf("\nHow many nodes:");
  scanf("%d",&n);
  printf("Enter data:");
  for(i=0;i<n;i++)
  {
    newnode=(struct dlnode*)malloc(sizeof(struct dlnode));
     newnode->next=NULL;
     newnode->prev=NULL;
    scanf("%d",&newnode->data);
    if(head==NULL)
      head=curr=newnode;
    else
    {
      curr->next=newnode;
      newnode->prev=curr;
      curr=newnode;
    }

  }//for
 

  return(head);
}

void dldisplay(struct dlnode *head)
{
   struct dlnode *curr;
  for(curr=head;curr!=NULL;curr=curr->next)
  printf("%d\t",curr->data);
}

void reverse(struct dlnode *head)
{
   struct dlnode *curr,*temp;
   for(curr=head;curr->next!=NULL; curr=curr->next);
           
      temp=curr;
    while(temp!=NULL)
    {
    printf("%d\t",temp->data);
     temp=temp->prev;
    } 
       
}

