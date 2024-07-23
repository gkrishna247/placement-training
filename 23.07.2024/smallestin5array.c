#include <stdio.h>
int main()
{
    int arr[5],i,j,c;
    printf("Enter the array of 5 elements:");
    for (i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<5;i++)
    {
        c=0;
        for(j=0;j<5;j++)
        {
            if(arr[j]>=arr[i])
            {
                c++;
            }
        }
        if(c==5){
            printf("\n Smallest number in array is %d",arr[i]);
            break;
        }
    }
    return 0;
}

