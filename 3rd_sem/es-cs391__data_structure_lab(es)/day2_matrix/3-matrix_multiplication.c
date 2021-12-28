//3. Write a C program containing a function which will multiply two matrices.
#include <stdio.h>
void display(int row, int col, int arr[][col]){
	for(int i=0;i<row;i++)
	{
		printf("\n");
		for(int j=0;j<col;j++)
			printf("\t%d",arr[i][j]);
	}
}

void MatMul(int m,int n,int a[][n],int b[][n]){
	int c[m][n],i,j,k;
	for( i=0;i<m;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			c[i][j]=0;
			for(k=0;k<m;k++)
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
		}
	}
	for(i=0;i<m;i++) //printing
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%4d",c[i][j]);
	}
}

int main (){
	int  i,j,m,n,r,s;
	printf("Enter the first matrix\n");
	scanf("%d%d",&m,&n);
	printf("Enter the second matrix\n");
	scanf("%d%d",&r,&s);
	if(m!=r)
		printf("\nThe matrix cannot multiplied");
	else
	{  
		int  a[m][n],b[r][s];
		printf("\nEnter the elements of first matrix \n");
		for(i= 0;i<m;i++)
		{
			for(j=0;j<n;j++)
				scanf("\t%d",&a[i][j]);
		}
		printf("\nEnter the elements of second matrix \n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				scanf("\t%d",&b[i][j]);
		}
		printf("\nThe element of first matrix is\n");
		display(m,n,a);
		printf("\nThe element of second matrix is\n");
		display(r,s,b);
		printf("\nMultiplication of two matrix is");
		MatMul(m,n,a,b);
		
	}
}
