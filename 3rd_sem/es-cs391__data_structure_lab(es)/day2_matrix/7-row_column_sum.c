//7. Write a C Program containing a function which will find sum of each row and column of a matrix.

#include<stdio.h>

void dArr(int arr[],int n){
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void rowColSum(int row, int col, int matrix[][col]){
	int rowSum[row],colSum[col];int sum;
	for(int i=0; i<row; i++){
		sum = 0;
		for(int j=0; j<col; j++){
			sum = sum + matrix[i][j];
		}
		rowSum[i]=sum;
	}
	for(int i=0;i<col; i++){
		sum = 0;
		for(int j=0; j<row; j++){
			sum = sum + matrix[j][i];
		}
		colSum[i]=sum;
	}
	printf("Row summation : ");dArr(rowSum,row);
	printf("col summation : ");dArr(colSum,col);
}


int main(){
	int row,col;
	printf("Enter the numbers of row : ");
	scanf("%d",&row);
	printf("Enter the numbers of columns : ");
	scanf("%d",&col);
	int matrix[row][col];
	printf("Enter the matrix elements : \n");
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("Matrix is : \n");
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	rowColSum(row,col,matrix);


	return 0;
}