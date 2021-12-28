// 2. program in C to insert an element at a specified position in a given array containing n numbers without any data loss.

#include <stdio.h>
int main()
{  
    int arr [10], i, n , p ,ins; 
    printf("\nEnter the size of the array:"); 
    scanf ("%d", &n); 
    printf("\nEnter the elements of the array\n"); 
    for(i=0;i<n;i++) 
    scanf("%d", &arr[i]);   

	printf("Enter the location to insert an element\n");
   scanf("%d", &p);
 
   printf("Enter the num to insert\n");
   scanf("%d", &ins);
 
   for (i = n - 1; i >= p - 1; i--)
      arr[i+1] = arr[i];
 
   arr[p-1] = ins;
 
   printf("Array after Insertion\n");
 
   for (i = 0; i <= n; i++)
      printf("%d ", arr[i]);
 
   return 0;
}
