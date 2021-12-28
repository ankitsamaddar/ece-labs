/* Write C programs to sort n numbers in ascending order using the following sorting methods:
(1)Bubble sort
(2)Selection sort
(3)Insertion sort
(4)Quick sort
(5)Merge sort
(6)Heap sort
(7)Radix sort  */

#include <stdio.h>
#include<stdlib.h>
int num=0 ;
int arr[20];
int b[20];
void BubbleSort();
void InsertionSort();
void display();
void op();
int main()
{
	op();

	return 0;
}
void op (){
	printf("Enter The Number List Size <=20 : ");
	scanf("%d",&num);
	if(num>20)
		exit(0);
	printf("Enter The Numbers\n");
	for (int i = 0; i < num; ++i)
	{
		scanf("%d",&arr[i]);
	}

		int l=0,r=num-1;
	printf("\n(1)Bubble sort\n(2)Selection sort\n(3)Insertion sort\n(4)Quick sort\n(5)Merge sort\n(6)Heap sort\n(7)Radix sort \n");
	printf("\nEnter Your Choice: ");
	int ch;
	scanf("%d",&ch);
	switch(ch){
		case 1:
		BubbleSort();
		printf("After BubbleSort ");
		display();
		op();
		break;
		case 2:
		printf("After SelectionSort ");
		display();
		op();
		break;
		case 3:
		InsertionSort();
		printf("After InsertionSort ");
		display();
		op();
		break;
		case 4:
		printf("After QuickSort ");
		display();
		op();
		break;
		case 5:
		printf("After MergeSort ");
		display();
		op();
		break;
		case 6:
		printf("After HeapSort ");
		display();
		op();
		break;
		case 7:
		printf("After RadixSort ");
		display();
		op();
		break;
		default: printf("Invalid Choice");

	}

}


void display(){
	printf("The List Is\n");
	for (int i = 0; i < num; ++i)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
}

void BubbleSort (){
	int i, j,temp;
	for (i = 0; i < num-1; i++)
		for (j = 0; j < num-i-1; j++)
			if (arr[j] > arr[j+1]) {
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}


void InsertionSort () {
	int i, key, j;
	for (i = 1; i < num; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

