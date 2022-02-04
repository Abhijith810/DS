#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head=NULL;
void enqueue(int v)
{
    struct node *newNode;
    newNode= (struct node*)malloc(sizeof(struct node));
    newNode->data=v;
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
    }
    else
    {
        struct node *t=head;
        while(t->next!=head)
        {
            t=t->next;
        }
        newNode->next=head;
        head=newNode;
        t->next=head;
    }
}
void dequeue()
{
    struct node *t1=head;
    struct node *temp=head;
    if(head==NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        head=t1->next;
        temp->next=head;
        printf("\nDeleted ");
    }
}
void display()
{

    if(head==NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        struct node *temp=head;
        struct node *t=head;
        while(temp->next!=t)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
    printf("%d",temp->data);
    }

   }
int main()
{
    int ch=0,value,c=0,d=0;
    do
    {
    printf("Menu\n1.Enqueue\n2.Dequeue\n3.Display\nEnter your choice ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: printf("\nEnter the value to be inserted ");
            scanf("%d",&value);
            enqueue(value);
            break;

    case 2: dequeue();
            break;

    case 3: printf("\nDisplaying elements\n");
            display();
            break;

    default: printf("\nWrong choice");
    }
    printf("\nDo you want to go to the menu(0/1) ");
    scanf("%d",&c);
    }while(c==1);
    return 0;
}
