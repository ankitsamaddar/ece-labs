//2. Write a C Program containing a function which will copy the elements of one array into another array.
#include <stdio.h>
#include <stdlib.h>
int arr[20];
int n;
int arr2[20];
void display();
void copy();

void copy(){
	for (int i = 0; i < n; i++){
		arr2[i]=arr[i];
	}
}

void display(){
	printf("The List Is\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t",arr2[i]);
	}
	printf("\n\n");
}

int main(int argc, char const *argv[])
{
	printf("Enter The Number List Size <=20 : ");
	scanf("%d",&n);
	if(n>20)
		exit(0);
	printf("Enter The Array\n");
	for (int i = 0; i < n; ++i)
		scanf("%d",&arr[i]);
	copy();
	printf("The Array Copy Is Successful\n");
	display	();
	return 0;
}

