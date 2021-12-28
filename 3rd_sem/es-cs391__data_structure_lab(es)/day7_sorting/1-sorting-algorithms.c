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
void SelectionSort();
void InsertionSort();
void QuickSort(int,int);
void MergeSort(int,int);
void HeapSort(int[],int);
void RadixSort();
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
		SelectionSort();
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
		QuickSort(l,r);
		printf("After QuickSort ");
		display();
		op();
		break;
		case 5:
		MergeSort( l, r);
		printf("After MergeSort ");
		display();
		op();
		break;
		case 6:
		HeapSort(arr,num);
		printf("After HeapSort ");
		display();
		op();
		break;
		case 7:
		RadixSort();
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

void SelectionSort () {
	int i, j, min,temp=0;
	for (i = 0; i < num-1; i++)
	{
		min = i;
		for (j = i+1; j < num; j++)
			if (arr[j] < arr[min]){
				min = j;
			temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
		}
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

void QuickSort(int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(arr[i]<=arr[pivot]&&i<last)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      QuickSort(first,j-1);
      QuickSort(j+1,last);

   }
}
void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(arr[l1] <= arr[l2])
         b[i] = arr[l1++];
      else
         b[i] = arr[l2++];
   }

   while(l1 <= mid)
      b[i++] = arr[l1++];

   while(l2 <= high)
      b[i++] = arr[l2++];

   for(i = low; i <= high; i++)
      arr[i] = b[i];
}
void MergeSort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      MergeSort(low, mid);
      MergeSort(mid+1, high);
      merging(low, mid, high);
   } else {
      return;
   }
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}
void HeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

void RadixSort (){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
   lar = arr[0];
   for (int i = 1; i < num; i++)
      if (arr[i] > lar)
         lar = arr[i];
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < num; i++){
         r = (arr[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = arr[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            arr[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
   }
}