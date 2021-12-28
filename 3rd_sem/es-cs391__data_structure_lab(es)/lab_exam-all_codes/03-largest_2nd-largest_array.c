//3.Write a C Program containing a function which will find the largest element and second largest element in an array.

#include <stdio.h>
#include <stdlib.h>
int arr[]={10,20,30,65,41};
int n = sizeof(arr)/sizeof(arr[0]);
void display();
void LargeAnd2Lr();
int main () {
	display();
	LargeAnd2Lr();
	return 0;
}
void LargeAnd2Lr(){
	int l1,l2,i;
	l1=0,l2=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]>arr[l1])
		{
			l2=l1;
			l1=i;
		}
	}
	printf("First Largest Number is %d\nSecond Largest Number is %d ",arr[l1],arr[l2]);
}
void display(){
	printf("The List Is\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
}