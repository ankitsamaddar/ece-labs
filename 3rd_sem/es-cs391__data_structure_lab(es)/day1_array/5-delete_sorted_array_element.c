// 5.program in C to delete an element from a sorted array
#include <stdio.h>

int main()
{
    int arr [10], i, n,num ;
    printf("\nEnter the size of the array:");
    scanf ("%d", &n);
    printf("\nEnter the elements of the array\n");
    for(i=0;i<n;i++)
    scanf("%d", &arr[i]);
	printf("\n Enter the number to be deleted: ");
     scanf("%d", &num);

for (  i = 0 ; i < n-1 ; i++)
{
if (  arr[i] < num )
arr[i] = arr[i] ;
else
arr[i] = arr[i+1] ;
}
printf("\n Array after deleting a number are :\n") ;
for (  i = 0 ; i < n-1 ; i++)
printf("%d \t",arr[i]) ;
       return 0;
    }
