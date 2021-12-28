//3. program in C to delete an element at a specified position in a given array containing n numbers.
#include <stdio.h>
int main()
{  
    int arr [10], i, n , pos ; 
    printf("\nEnter the size of the array:"); 
    scanf ("%d", &n); 
    printf("\nEnter the elements of the array\n"); 
    for(i=0;i<n;i++) 
    scanf("%d", &arr[i]);  

   printf("Enter the location to delete element\n");
   scanf("%d", &pos);

   if (pos >= n+1)
      printf("Deletion not possible.\n");
   else
   {
      for (i = pos - 1; i < n - 1; i++)
         arr[i] = arr[i+1];

      printf("Resultant array:\n");

      for (i = 0; i < n - 1; i++)
         printf("%d ", arr[i]);
   }
	return 0;
}
