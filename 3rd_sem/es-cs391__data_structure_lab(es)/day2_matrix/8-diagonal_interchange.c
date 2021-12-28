//8. Write a C Program containing a function which will interchange diagonals of a square matrix.

#include<stdio.h>

void changeDiagonal(int row, int col, int matrix[][col]){
    int d = col-1;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i==j){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][d];
                matrix[i][d] = temp;
                d--;
            }
        }
    }
    for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int row,col;
    printf("Enter row==column number : ");
    scanf("%d %d",&row,&col);
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
    printf("After the change of diagonal, Matrix is : \n");
    changeDiagonal(row,col,matrix);
	return 0;
}