//15. Write a C program containing a function which will add two Matrices of same size.
#include <stdio.h>
//to add two matrices
void sum(int m, int n , int arr1[][n],int arr2[][n]){
   printf("\nSum of entered matrices:-\n");
   int sum[m][n],i,j;
   for (i = 0; i < m; i++) {
      for (j = 0 ; j < n; j++) {
         sum[i][j] = arr1[i][j] + arr2[i][j]
         ;
         printf("%-4d", sum[i][j]);
      }
      printf("\n");
   }
}
//print
void display(int row, int col, int arr[][col]){
   for(int i=0;i<row;i++)
   {
      for(int j=0;j<col;j++)
         printf("%-4d",arr[i][j]);
      printf("\n");
   }
    printf("\n");
}
int main()
{
   int m, n, i, j;

   printf("Enter the number of rows and columns of matrix\n");
   scanf("%d%d", &m, &n);
   int arr1[m][n], arr2[m][n];
   printf("Enter the elements of first matrix\n");

   for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
         scanf("%d", &arr1[i][j]);

   printf("Enter the elements of second matrix\n");

      for (i = 0; i < m; i++)
         for (j = 0 ; j < n; j++)
            scanf("%d", &arr2[i][j]);

      printf("\nThe element of first matrix is\n");
      display(m,n,arr1);
      printf("\nThe element of second matrix is\n");
      display(m,n,arr2);
      sum(m,n,arr1,arr2);
         return 0;
      }