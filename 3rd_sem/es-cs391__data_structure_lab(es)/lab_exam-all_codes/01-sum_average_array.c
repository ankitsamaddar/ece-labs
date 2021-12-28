//1. Write a C Program containing a function which will calculate sum & average of all elements of an array.

#include <stdio.h>
#include <stdlib.h>
int arr[]={10,20,30,65,41};
int n = sizeof(arr)/sizeof(arr[0]);
void SumAvg();
void display();

int main () {
	display();
	SumAvg();
	return 0;
}

void SumAvg(){
	int sum=0;
	float avg=0.0;
	for (int i = 0; i < n; ++i)
	{
		sum+=arr[i];
	}
	avg=sum/n;
	printf("The sum is %d average is %.2f",sum,avg);
}

void display(){
	printf("The List Is\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
}