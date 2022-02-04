#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;
void insertatbeg(int);
void insertatend(int);
void insertatpos(int,int);
void deleteatbeg();
void deleteatend();
void deleteatpos();
void display();
void main()
{
    int c,value,key,choice;
    do
    {
        printf("\n...... your options are ......\n\n");
        printf("1.insert at begining \n");
        printf("2.insert at end \n");
        printf("3.insert b/w 2 nodes \n");
        printf("4.delete node from begining \n");
        printf("5.delete node from end \n");
        printf("6.delete node from a specific position \n");
        printf("7.Display \n");
        printf("8.Exit \n");
        printf("Enter your option :");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("\n Enter the value to inserted:");
            scanf("%d",&value);
            insertatbeg(value);
            break;

            case 2:printf("\n Enter the value to inserted:");
            scanf("%d",&value);
            insertatend(value);
            break;

            case 3:printf("\n Enter the value to specific position:");
            scanf("%d",&value);
            printf("\n Enter the position:");
            scanf("%d",&key);
            insertatpos(value,key);
            break;

            case 4:printf("\n Delete a node from begining");
            deleteatbeg();
            break;

            case 5:printf("\n Delete a node from end");
            deleteatend();
            break;

            case 6:printf("\n Delete a node from specific position");
            printf("\n Enter the position:");
            scanf("%d",&key);
            deleteatpos(key);
            break;

            case 7:printf("\n Display the elements:");
            display();
            break;

            case 8:exit(0);
            break;

            default:printf("\n Wrong choice");
        }
    }while(choice!=8);
}
void insertatbeg(int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
    }
display();
}
void insertatend(int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    struct node *temp=head;
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next=NULL;
    }
display();
}
void insertatpos(int value,int key)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    struct node *temp=head;
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        while(temp->data!=key)
        {
            if(temp->next==NULL)
            {
                printf("\n Node not Found");
            }
            else
            {
                temp=temp->next;
            }
        }
        if(temp->next!=NULL)
        {
            newnode->prev=temp;
            newnode->next=temp->next;
            temp->next=newnode;
            newnode->next->prev=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=NULL;
        }
    }
display();
}
void deleteatbeg(int value)
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("\n Empty list");
    }
    else
    {
        if(temp->next==NULL)
        {
            head=NULL;
        }
        else
        {
        head=temp->next;
        temp->next->prev=NULL;
        }
    }
 free(temp);
display();
}
void deleteatend()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("\n Empty list");
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        if(temp->prev==NULL)
        {
            head=NULL;
        }
        else
        {
            temp->prev->next=NULL;
            free(temp);
        }
    }
display();
}
void deleteatpos(int key)
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("\n Empty list");
    }
    else
    {
        while(temp->data!=key)
        {
           if(temp->next==NULL)
           {
               printf("\n Element not found");
           }
           else
           {
               temp=temp->next;
           }
        }
        if(temp->prev==NULL && temp->next==NULL)
        {
            head==NULL;
        }
        else if(temp->prev==NULL && temp->next!=NULL)
        {
            head=temp->next;
            head->prev=NULL;
        }
        else if(temp->prev!=NULL && temp->next==NULL)
        {
            temp->prev->next=NULL;
        }
        else
        {
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
        }

    }
    free(temp);
display();
}
void display()
{
    if(head==NULL)
    {
        printf("\n Empty list");
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            printf("%d <=>",temp->data);
            temp=temp->next;
        }
    printf("%d",temp->data);
    }
}



