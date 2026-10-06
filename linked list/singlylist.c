#include <stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
};
struct node *create()
{
 struct node *head,*curr,*newnode;
 int n,i;
 head=NULL;
 printf("How many nodes:");
 scanf("%d",&n);
 printf("enter the data");
 for(i=0;i<n;i++)
 {
      newnode=(struct node *)malloc(sizeof(struct node));
      newnode->next=NULL;
   scanf("%d",&newnode->data);
   if(head==NULL)//linked list empty
      head=curr=newnode;
   else
   {
     curr->next=newnode;
     curr=newnode;
   }
 }
   return(head);
}
void display(struct node *head)
{ struct node *curr;
  for(curr=head;curr!=NULL;curr=curr->next)
    printf("%d\t",curr->data);
}  
void search(struct node *head)
{ int x,pos;
  struct node *curr;
  printf("Enter data to search:");
  scanf("%d",&x);
  curr=head; pos=1;
  while(curr!=NULL)
  { if(curr->data==x)
     { printf("\nFound at %d..",pos);
       return;
      }
    else
     { curr=curr->next;
       pos++;
     }
  }
  printf("\nNot found..");
}
struct node *insert(struct node *head)
{ struct node *newnode,*curr;
  int pos,i;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter data to insert:");
  scanf("%d",&newnode->data);
  printf("Enter position to insert:");
  scanf("%d",&pos);
  if(pos==1) //insert at first
  { newnode->next=head;
    head=newnode;
  }
  else //insert at other position
  {
   curr=head;
   for(i=1;i<pos-1;i++)
   {
     curr=curr->next;
     if(curr==NULL)
     { printf("Position not found..");
       return(head);
     }
   }//for
   newnode->next=curr->next;
   curr->next=newnode;
  }//else
  return(head);
}//insert

struct node *reverse(struct node *head)
{
  struct node *temp,*curr;
  curr=head;
  temp=head->next;
  head=head->next;
  curr->next=NULL;
  while(head!=NULL)
  {
    head=head->next;
    temp->next=curr;
    curr=temp;
    temp=head;
  }
    head=curr;
    return(head);
}
struct node *concatenate(struct node *head)
{
    int value;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {   temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
        return head;
}
  void main()
{
  struct node *head=NULL;
  int choice;
  do
    {
   printf("\n\n1.Create Singly List");
   printf("\n2.Display");
   printf("\n3.Search");
   printf("\n4.Insert node");
   printf("\n6.Reverse");
   printf("\n7.concatenate");
   printf("\n9.Exit");
   printf("\nEnter choice:");
   scanf("%d",&choice);
   switch(choice)
    { 
     case 1: head=create();
		break;
     case 2: display(head);
	     break;
     case 3: search(head);
	     break;
     case 4: head=insert(head);
	     display(head);
	     break;
     case 6:head=reverse(head);
	     display(head);
		break;
     case 7: concatenate(head);
     break;
     case 9:  exit(0);
     default: printf("Wrong choice");
   }
  }while(choice!=9);
}


