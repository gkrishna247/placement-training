#include <stdio.h>
void main(){
    int n,arr[100],i,j;
    printf("Input the number of elements to store in the array: ");
    scanf("%d",&n);
    printf("\nInput %d number of elements in the array: ",n);
    for (i=0;i<n;i++){
        printf("\nElement -%d : ",i);
        scanf("%d",&arr[i]);
    }
    for (j=0;j<n;j++){
        printf("\n%d",arr[j]);
    }
    printf("\n\n%d",arr[n]);
}


