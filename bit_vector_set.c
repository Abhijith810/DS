#include<stdio.h>
#include<stdlib.h>
void uni(int [],int [],int,int);
void intersection(int [],int [],int,int);
void difference(int [],int [],int,int);
void equality(int [],int [],int,int);
void main()
{
    int m,n,a[100],b[100],i,ch;
    printf("Enter the size of 2 arrays:");
    scanf("%d%d",&m,&n);
    printf("\n Enter the elements of 1st array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n Enter the elements of 2st array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    do
    {
        printf("\n 1.Union \n 2.Intersection \n 3.Difference \n 4.Equality \n 5.Exit \n");
        printf("\n Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            uni(a,b,m,n);
            break;
        case 2:
            intersection(a,b,m,n);
            break;
        case 3:
            difference(a,b,m,n);
            break;
        case 4:
            equality(a,b,m,n);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid Choice");
        }
    }while(ch!=5);
}
void uni(int a[],int b[],int m,int n)
{
    int c[m];
    if(m!=n)
    {
        printf("\n Two sets are not compatible for union");
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            c[i]=a[i] || b[i];
        }
        for(int i=0;i<m;i++)
        {
            printf("%d \t",c[i]);
        }
    }
}
void intersection(int a[],int b[],int m,int n)
{
    int c[m];
    if(m!=n)
    {
        printf("\n Two sets are not compatible for union");
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            c[i]=a[i] && b[i];
        }
        for(int i=0;i<m;i++)
        {
            printf("%d \t",c[i]);
        }
    }
}
void difference(int a[],int b[],int m,int n)
{
    int c[m],k[m];
    if(m!=n)
    {
        printf("\n Two sets are not compatible for union");
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            k[i]=!b[i];
        }
        for(int i=0;i<m;i++)
        {
            c[i]=a[i] && k[i];
        }
        for(int i=0;i<m;i++)
        {
            printf("%d \t",c[i]);
        }
    }
}
void equality(int a[],int b[],int m,int n)
{
    int f=0;
    if(m!=n)
    {
        printf("\n Two sets are not compatible for union");
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            if(a[i]!=b[i])
            {
                f=1;;
            }
        }
    }
    if(f==1)
    {
        printf("Not Equal");
    }
    else
    {
        printf("Equal");
    }
}
