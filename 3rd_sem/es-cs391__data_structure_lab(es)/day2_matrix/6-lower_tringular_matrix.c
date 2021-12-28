//6. Write a C Program containing a function which will check whether a given matrix is lower triangular or not and if lower triangular then find the sum of elements of the lower triangular matrix.

#include<stdio.h>
void display(int row, int col, int matrix[][col]){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int isLowerTriangle(int row, int col, int matrix[][col]){
	for(int i=0; i<row; i++){
		for(int j=i+1; j<col; j++){
			if(matrix[i][j]!=0)
				return 0;
		}
	}
	return 1;
}

int LowerTriangle(int row, int col, int matrix[][col]){
	int sum = 0;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(j<=i && j<=col-1){
				sum = sum + matrix[i][j];
			}
		}
	}
	return sum;
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
	display(row,col,matrix);
	if(isLowerTriangle(row,col,matrix)==0)
		printf("Matrix is not Lower triangle matrix.\n");
	else{
		printf("Matrix is Lower triangle matrix.\n");
		printf("Summation of elements : %d\n",LowerTriangle(row,col,matrix));
	}


	return 0;
}