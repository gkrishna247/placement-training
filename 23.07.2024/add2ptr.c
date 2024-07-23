#include <stdio.h>
void read(int a[],int r)
{
    int i;
    for(i=0;i<r;i++)
        scanf("%d",&a[i]);
}
void add(int *a,int *b,int *c)
{
    *c=*a+*b;
}
void main()
{
    int a1[100],a2[100],i,j,r,c,rc,ad[100];
    printf("Enter number of rows and columns:");
    scanf("%d%d",&r,&c);
    rc=r*c;
    printf("\nEnter the elements of first matrix:");
    read(a1,rc);
    printf("\nEnter the elements of second matrix:");
    read(a2,rc);
    printf("\nThe result is:\n");
    for(i=0;i<rc;i++)
        add(&a1[i],&a2[i],&ad[i]);
    for(i=0;i<rc;i++)
    {
        printf("\t%d",ad[i]);
        if((i+1)%c==0)
            printf("\n");
    }
}
