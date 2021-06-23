//Matrix Multiplication
#include<stdio.h>
#include<stdlib.h>

int **create(int r, int c)
{
	int **A = (int**)malloc(r*sizeof(int));
	for(int i=0;i<r;i++)
	{
		A[i] = (int*)malloc(c*sizeof(int));

		printf("\nEnter the row[%d]: ",i+1);
		for(int j=0;j<c;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	return A;
}

void display(int **A, int r, int c)
{
        for(int i=0;i<r;i++)
        {
		for(int j=0;j<c;j++)
		{
			printf("%d\t",A[i][j]);
                }
		printf("\n");
	}
}

int** multiply(int **A, int **B, int r,int c)
{
	int **result = (int**)calloc(r,sizeof(int));
	for(int i=0;i<c;i++)
	{
		result[i] = (int*)calloc(c,sizeof(int));
		for(int j=0;j<r;j++)
		{
			for(int k=0;k<c;k++)
			{	
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return result;
}

int main()
{
	int r1,r2,c1,c2;
	int **A,**B;
	
	printf("Enter the row and column numbers of the first matrix: ");
	scanf("%d%d",&r1,&c1);
	
	if(r1>0 && c1>0)
	{
		A = create(r1,c1);
	}
	else
	{
		printf("\nInvalid Input!!!");
		exit(0);
	}

	printf("Enter the row and column numbers of the second  matrix: ");
	scanf("%d%d",&r2,&c2);

	if(r2>0 && c2>0)
        {
		if(c1==r2)
		{
			B = create(r2,c2);
		}
		else
		{
			printf("\nNumber of columns of the first matrix must be equal to the number of rows of the second matrix!\n");
			exit(0);
		}
        }
	else
	{
		printf("\nInvalid Input!!!");
		exit(0);
	}

	printf("\nMatrix A:\n");
	display(A,r1,c1);
	
	printf("\nMatrix B:\n");
	display(B,r2,c2);
	
	int **result = multiply(A,B,r1,c2);

	printf("\nResult Matrix:\n");
	display(result,r1,c2);

	free(A);
	free(B);
	free(result);
}
