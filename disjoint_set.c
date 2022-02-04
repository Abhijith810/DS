#include<stdio.h>
#include<stdlib.h>
void uni(int,int);
int find(int);
int a1[100];
void main()
{
    int n,i,a,b,ch;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    //printf("\n Enter the elements:");
    for(i=1;i<=n;i++)
    {
        a1[i]=0;
    }
    do
    {
    printf("\n Enter the values to take union:");
    scanf("%d%d",&a,&b);
    uni(a,b);
    for(i=1;i<=n;i++)
    {
        printf("%d ",a1[i]);
    }
    /*for(i=1;i<=n;i++)
    {
        if(a1[i]!=0)
        {
        printf("{");
        printf("%d,%d",i,a1[i]);
        printf("}");
        }
    }*/
    printf("\n Do you want to continue(0/1):");
    scanf("%d",&ch);
    }while(ch==1);
}
void uni(int a,int b)
{
    int x=find(a);
    int y=find(b);
    if(x!=y)
    {
        a1[x]=y;

    }
    else
    {
        printf("\n This belongs to the same set");
    }
    //return();
}
int find(int a)
{
    if(a1[a]==0)
    {
        return a;
    }
    else
    {
        find(a1[a]);
    }
}
