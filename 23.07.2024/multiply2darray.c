#include <stdio.h>
int main()
{
    int i,j ,k,r1,r2,c1,c2;
    int mat1[100][100],mat2[100][100],res[100][100];
    printf("For multiplying two matrices the columns of first matrix is equal to the rows of second matrix");
    printf("\nEnter the rows and columns of first matrix:");
    scanf("%d%d",&r1,&c1);
    printf("\nEnter the rows and columns of second matrix:");
    scanf("%d%d",&r2,&c2);
    if(c1!=r2)
    {
    	printf("\nThe columns of first matrix is not equal to columns of second matrix");
    	printf("\nTherefore the matrix are not possible to multiply");
    }
    else if(c1==r2)
	{
		printf("\nEnter the elements of first matrix:");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				scanf("%d",&mat1[i][j]);
			}
		}
		printf("\nEnter the elements of second matrix:");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				scanf("%d",&mat2[i][j]);
			}
		}
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				res[i][j]=0;
				for(k=0;k<c2;k++)
				{
					res[i][j]+=mat1[i][k]*mat2[k][j];
				}
			}
		}
		printf("\nThe result of multiplication of these 2 matrices is");
		for(i=0;i<r1;i++)
		{
		    printf("\n");
			for(j=0;j<c2;j++)
			{
				printf("%d\t ",res[i][j]);
			}
		}
	}
	return 0;
}

