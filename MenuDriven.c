#include<stdio.h>
void main()
{
int i,l,n,pos,e,j,temp,f,num=0,choice;
printf("enter the limit of the array :\n");
scanf("%d",&l);
int a[l];
printf("enter the elements of the array :\n");
for(i=0;i<l;i++)
{
scanf("%d",&a[i]);
}
do{
printf("\n\n    .......OPTIONS FOR YOU........     \n\n");
printf("1.insert an element in array \n");
printf("2.delete an element using its position \n");
printf("3.sort array \n");
printf("4.search an element in array \n");
printf("5.traversal \n\n");
printf("enter your option : ");
scanf("%d",&n);
switch(n)
{
case 1: printf("\n enter the position to be inserted :");
        scanf("%d",&pos);
        printf("enter element to be inserted : ");
        scanf("%d",&e);
        for(i=l;i>=pos;i--)
        {
        a[i]=a[i-1];
        }
        a[pos-1]=e;
        printf("\n the elements are : \n");
        for(i=0;i<=l;i++)
        {
        printf("%d  ",a[i]);
        }
        break;
case 2: printf("\n enter the position to be deleted :");
        scanf("%d",&pos);
        for(i=pos-1;i<l;i++)
        {
        a[i]=a[i+1];
        }
        printf("\n the elements are : \n");
        for(i=0;i<l-1;i++)
        {
        printf("%d  ",a[i]);
        }
        break;
case 3: for(i=0;i<l;i++)
        {
            for(j=0;j<l;j++)
            {
            if(a[i]<a[j])
            {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            }
            }
        }
        printf("\n the elements are : \n");
        for(i=0;i<l;i++)
        {
        printf("%d  ",a[i]);
        }
        break;
case 4: printf("\n enter element to be search : ");
        scanf("%d",&e);
        for(i=0;i<l;i++)
        {
        if(a[i]==e)
        {
        printf("\n element found at position %d",i+1);
        f=1;
        }
        }
        if(f!=1)
        printf(" \n element not found \n");
        break;
case 5: printf("\n the elements are : \n");
        for(i=0;i<l;i++)
        {
        printf("%d  ",a[i]);
        }
        break;
}
printf(" \n press 0 to continue \n");
scanf("%d",&choice);
}while(choice==0);
}
