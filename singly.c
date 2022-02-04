#include<stdio.h>
#include<stdlib.h>
void insertatbeg(int);
void insertatend(int);
void insertbtw(int);
struct node
{
int data;
struct node *next;
}*head=NULL;
void main()
{
int c,n,value,choice;
do
{
printf("...... your options are ......\n\n");
printf("1.insert at begging \n");
printf("2.insert at end \n");
printf("3.insert b/w 2 nodes \n");
printf("4.traversal \n");
printf("Enter your option : ");
scanf("%d",&c);
switch(c)
{
case 1:printf("Enter the value to be inserted :" );
       scanf("%d",&value);
       insertatbeg(value);
       break;
case 2:printf("\n Enter the value to be inserted:" );
       scanf("%d",&value);
       insertatend(value);
       break;
case 3:printf("\n Enter the value to be inserted:");
       scanf("%d",&value);
       insertbtw(value);
       break;
case 4:if(head==NULL)
       printf("\n list is empty");
       else
       {
       struct node *temp=head;
       printf("\n list elements are : \n");
       while(temp->next!=NULL)
       {
       printf("%d --> ",temp->data);
       temp=temp->next;
       }
       printf("%d -->NULL \n",temp->data);
       }
       }
       printf("enter 0 to continue \n");
       scanf("%d",&choice);
       }while(choice==0);
}
void insertatbeg(int value)
{
struct node *newnode=malloc(sizeof(struct node));
newnode->data=value;
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
}
else
{
newnode->next=head;
head=newnode;
}
printf("\n one node inserted !!! \n");
}
void insertatend(int value)
{
struct node *newnode=malloc(sizeof(struct node));
newnode->data=value;
newnode->next=NULL;
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
}
else
{
struct node *temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
printf("\n one node inserted !!! \n");
}

void insertbtw(int value)
{
struct node *newnode=malloc(sizeof(struct node));
int l1,l2,n;
printf("enter the locotion where it to be inserted : ");
scanf("%d %d",&l1,&l2);
newnode->data=value;
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
}
else
{
struct node *temp = head;
while(temp->data != l1 && temp->data != l2 && temp->next!=NULL)
{
temp = temp->next;
}
if(temp->data!=l1 && temp->data != l2)
{
printf("given node not found in the list !!!");
}
else
{
newnode->next = temp->next;
temp->next = newnode;
}
}
printf("\n one node inserted !!! \n");
}
