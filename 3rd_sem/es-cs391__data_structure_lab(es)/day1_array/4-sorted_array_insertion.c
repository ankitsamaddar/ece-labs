// 4. Write a program in C to insert an element in a sorted array so that after insertion array should be sorted.
#include <stdio.h>
int main()
{
    int arr [10], i, n , ins ,p=0 ;
    printf("\nEnter the size of the array:");
    scanf ("%d", &n);
    printf("\nEnter the elements of the array\n");
    for(i=0;i<n;i++)
    scanf("%d", &arr[i]);

	printf("Enter the element to insert\n");
    scanf("%d", &ins);
      for(i=0;i<n;i++)
     if(ins<arr[i])
     {
       p = i;
       break;
     }

   for(i=n;i>=p;i--)
      arr[i]= arr[i-1];
    arr[p]=ins;
    printf("\n\nAfter Insertion the list is :\n ");
   for(i=0;i<=n;i++){
      printf("%-4d",arr[i]);
  }
      printf("\n");
    return 0;
}
