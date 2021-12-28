//4.Write a C Program containing a function which will find the maximum and minimum element in an array.
#include <stdio.h>
#include <stdlib.h>
int arr[]={10,20,30,65,41};
int n = sizeof(arr)/sizeof(arr[0]);
void display();
void MaxMin();
int main () {
	display();
	MaxMin();
	return 0;
}
void MaxMin(){
	int i,max,min;
	max=min=arr[0];
	for(i=1;i<n;++i)
	{
		if(arr[i]>max)
			max=arr[i];
		if(arr[i]<min)
			min=arr[i];
	}
	printf("\nThe smallest element is %d\n",min);
	printf("\nThe largest element is %d\n",max);
}

void display(){
	printf("The List Is\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}