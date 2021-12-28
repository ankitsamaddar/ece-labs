//5.Write a C Program containing a function which will insert an element at a Specified Position in a given Array.

#include <stdio.h>
#include <stdlib.h>
int arr[10];
int n ;

void display();
void Insert();

int main () {
    int i;
    printf("\nEnter the size of the array:");
    scanf ("%d", &n);
    printf("\nEnter the elements of the array\n");
    for(i=0;i<n;i++)
    scanf("%d", &arr[i]);

	display();
	Insert();
	return 0;
}

void Insert(){
	int i,p,ins;
	printf("Enter the location to insert an element\n");
   	scanf("%d", &p);

   	printf("Enter the num to insert\n");
   	scanf("%d", &ins);

   	for (i = n - 1; i >= p - 1; i--)
    	arr[i+1] = arr[i];

   arr[p-1] = ins;

   printf("Array after Insertion\n");

   for (i = 0; i <= n; i++)
      printf("%d ", arr[i]);

}

void display(){
	printf("The List Is\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
}