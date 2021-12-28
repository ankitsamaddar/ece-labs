// 1. program in C to read and display n numbers using an array.
#include <stdio.h>

int main()
{    
    int arr [10], i, n ; 
    printf("\nEnter the size of the array:"); 
    scanf ("%d", &n); 
    printf("\nEnter the elements of the array\n"); 
    for(i=0;i<n;i++) 
    scanf("%d", &arr[i]); 
    printf("\nThe elements of the Array are\n"); 
    for(i=0;i<n;i++) 
        printf("%d ",arr[i]);
    return 0;
}