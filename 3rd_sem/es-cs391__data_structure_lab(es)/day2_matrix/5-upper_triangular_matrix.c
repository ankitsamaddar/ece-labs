//5. Write a C Program containing a function which will check whether a given matrix is upper triangular or not and if upper triangular then find the sum of elements of the upper triangular matrix.
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

int isUpperTriangle(int row, int col, int matrix[][col]){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(j>=i && j<=col-1){
				if(matrix[i][j]==0)
					return 0;
			}
			else{
				if(matrix[i][j]!=0)
					return 0;
			}
		}
	}
	return 1;
}

int upperTriangle(int row, int col, int matrix[][col]){
	int sum = 0;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(j>=i && j<=col-1){
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
	if(isUpperTriangle(row,col,matrix)==0)
		printf("Matrix is not upper triangle matrix.\n");
	else{
		printf("Matrix is upper triangle matrix.\n");
		printf("Summation of elements : %d\n",upperTriangle(row,col,matrix));
	}


	return 0;
}