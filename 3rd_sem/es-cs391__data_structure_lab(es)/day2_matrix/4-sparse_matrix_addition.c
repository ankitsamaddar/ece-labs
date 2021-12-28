//4. Write a C program containing a function which will add two sparse matrices.

#include<stdio.h>

void input(int row, int col, int matrix[][col]) {
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			scanf("%d",&matrix[i][j]);
		}
	}
}

int isParseMatrix(int row, int col, int matrix[][col]) {
	int s = 0;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(matrix[i][j]==0)
				s++;
		}
	}
    if(s>(row*col)/2) // If the number of zeros in a matrix exceeds (row*col)/2
    	return 1;
    else
    	return 0;
}

int main() {
	int row1, row2, col1, col2;
	printf("Enter the number of rows & columns of 1st matrix : ");
	scanf("%d",&row1);
	scanf("%d",&col1);
	printf("Enter the number of rows & of 2nd matrix : ");
	scanf("%d",&row2);
	scanf("%d",&col2);
	int matrix1[row1][col1],matrix2[row2][col2];
	printf("Enter the matrix 1 elements : \n");
	input(row1,col1,matrix1);
	printf("Enter the matrix 2 elements : \n");
	input(row2,col2,matrix2);
	int sum[row1][col1];
	if(isParseMatrix(row1,col1,matrix1)==0 && isParseMatrix(row2,col2,matrix2)==0)
		printf("Not parse matrix");
	else{
		if(row1 != row2 || col1 != col2)
			printf("Addition of two parse matrix is not possible\n");
		else{
			for(int i=0; i<row1; i++){
				for(int j=0; j<col1; j++){
					sum[i][j] = matrix1[i][j]+matrix2[i][j];
				}
			}
		}
	}
	printf("Summation matrix is :\n");
	for(int i=0; i<row1; i++){
		for(int j=0; j<col1; j++){
			printf("%d ",sum[i][j]);
		}
		printf("\n");
	}

	return 0;
}