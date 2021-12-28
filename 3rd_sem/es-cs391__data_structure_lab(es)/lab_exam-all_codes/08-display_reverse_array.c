//8.Write a C Program containing a function which will read an array and store the array elements in the same array in reverse order.
#include <stdio.h>
#include <stdlib.h>
int arr[]={10,20,30,65,41};
int n = sizeof(arr)/sizeof(arr[0]);
int arr1[10];

void display(int[]);
void reverse();
int main () {
	display(arr);
	reverse();
	display(arr1);
	return 0;
}
void reverse()
{
    for(int i=0;i<n;++i)
    {
        arr1[i]=arr[n-i-1];
    }
}
void display(int arr[]){
	printf("The List Is\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
}