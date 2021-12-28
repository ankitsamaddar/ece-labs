//2. Write a C program containing a function which will find transpose of a given matrix.

#include <stdio.h>
void input(int row, int col, int matrix[row][col]){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			scanf("%d",&matrix[i][j]);
		}
	}
}
void display(int row, int col, int matrix[row][col]){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void transpose(int row,int col,int matrix[][col],int Trans[][row]){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			Trans[j][i]=matrix[i][j];
		}
	}
}

int main(){
	int row,col;
	printf("Enter the numbers of row : ");
	scanf("%d",&row);
	printf("Enter the numbers of columns : ");
	scanf("%d",&col);
	int matrix[row][col],Trans[col][row];
	printf("Enter the matrix elements : \n");
	input(row,col,matrix);
	printf("Matrix is : \n");
	display(row,col,matrix);
	printf("Transpose matrix : \n");
	transpose(row,col,matrix,Trans);
	display(col,row,Trans);

	return 0;
}
