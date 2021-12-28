//(1)Write a C program to search an element in an array using linear search and binary search.

#include <stdio.h>
#include<stdlib.h>
void BinarySearch(int);
void LinearSearch(int);
void display();
int arr[]={45,87,47,43,69,12};
int n = sizeof(arr)/sizeof(arr[0]);
int main()
{
	int s,c;
	printf("The Array Is\n");
	display();
	printf("\nEnter the element to Search: ");
	scanf("%d",&s);
	printf("Enter 1 For Binary Search 2 for Linear Search : ");
	scanf("%d",&c);
	if(c==1) BinarySearch(s);
	else if (c==2) LinearSearch(s);
	else printf("Wrong Choice");
	return 0;
}

void display(){
	int i;
	for ( i = 0; i < n; ++i)
		printf("%d\t",arr[i]);
}

void BinarySearch(int x){
 int first = 0;
  int last = n - 1;
  int middle = (first+last)/2;

  while (first <= last) {
    if (arr[middle] < x)
      first = middle + 1;
    else if (arr[middle] == x) {
      printf("%d found at location %d.\n", x, middle+1);
      break;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", x);
}

void LinearSearch(int x){
	int t=0;
    for (int i = 0; i < n; i++)
        (arr[i] == x)
        	? printf("Element Found At %d",i+1)
        	: (t=-1);
    if(t==-1)
    	printf("Not Found");
}