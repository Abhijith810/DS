#include<stdio.h>
#include<stdlib.h>
void push(int);
void pop();
void search(int);
struct node
{
    int data;
    struct node *next;
}*Top=NULL;
void main()
{
    int choice,val,ch;
    do
    {
        printf(" 1.push \n 2.pop \n 3.search \n 4.dispaly \n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to push:\n");
            scanf("%d",&val);
            push(val);
            break;
        case 2:
            //printf("Enter the element to pop:\n");
            //scanf("%d",&val);
            pop();
            break;
        case 3:
            printf("Enter the element to be search:\n");
            scanf("%d",&val);
            search(val);
            break;
        case 4:if(Top==NULL)
            printf("\n Stack is empty \n");
            else
            {
            struct node *temp=Top;
            printf("\n elements are : \n");
            while(temp->next!=NULL)
            {
            printf("%d \n",temp->data);
            temp=temp->next;
            }
            printf("%d \n",temp->data);
            }
            }
    printf("enter 0 to continue \n");
    scanf("%d",&ch);
    }
    while(ch==0);
}
void push(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    if(Top==NULL)
    {
        newnode->next=NULL;
        Top=newnode;
    }
    else
    {
        newnode->next=Top;
        Top=newnode;
    }
printf("one node inserted \n");
}
void pop()
{
struct node *temp;
    if(Top==NULL)
    {
        printf("Stack is empty:\n");
    }
    else
    {
        temp=Top;
        Top=temp->next;
        free(temp);
    }
}
void search(int val)
{
struct node *temp=Top;
int f;
while(temp!=NULL)
{
    if(temp->data==val)
    {
    f=1;
    }
temp=temp->next;
}
if(f==1)
{
printf("Element is found \n");
}
else
{
printf("Element is not found \n");
}
}
